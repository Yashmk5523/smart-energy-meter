#define BLYNK_TEMPLATE_ID           "TMPL3wddxu3C4"
#define BLYNK_TEMPLATE_NAME         "Smart Meter"
#define BLYNK_AUTH_TOKEN            "k4gOJaaXOlnDHrcEmE-VAYeK6nHtNMGN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Preferences.h> // Added for Permanent Memory
#include "EmonLib.h"

// --- Network Credentials ---
char ssid[] = "realme8";
char pass[] = "11111111"; 

// --- Object Initialization ---
EnergyMonitor poleSensor, houseSensor, voltSensor;
BlynkTimer timer;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Preferences prefs; // Memory object

// --- Custom Rupee Symbol ---
byte rupeeSymbol[8] = {
  0b11111, 0b00100, 0b11111, 0b01000, 
  0b10000, 0b01000, 0b00100, 0b00000
};

// --- Pin Mapping ---
const int poleCurrentPin = 34;   
const int houseCurrentPin = 35;  
const int voltagePin = 32;
const int relayPin = 26;         
const int buzzerPin = 18;        
const int ledPin = 19;

// --- Tiered Billing & Settings ---
const float BASE_RATE = 7.0;     
const float HIGH_RATE = 12.0;    
const float THEFT_THRESHOLD = 0.8; 
const float POLE_OFFSET = 1.16;  

double totalKWh = 0; 
double lastSavedKWh = 0; // Tracks when to save to memory
double liveBill = 0;

unsigned long lastMillis = 0;    
bool isAlarmRunning = false;     

// --- Non-Blocking Delay Function ---
// Keeps the cloud connection alive while waiting
void smartDelay(unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    if (WiFi.status() == WL_CONNECTED) {
      Blynk.run();
    }
    delay(10);
  }
}

void sendSensorData() {
  if (isAlarmRunning) return; 

  // 1. Calculate RMS Voltage
  voltSensor.calcVI(20, 2000); 
  double vRMS = voltSensor.Vrms;
  if (vRMS < 140.0) vRMS = 0.0; 

  // 2. Average Current Sensing
  double sumP = 0, sumH = 0;
  for(int i=0; i<10; i++) {
    sumP += (poleSensor.calcIrms(1480) - POLE_OFFSET);
    sumH += houseSensor.calcIrms(1480);
    delay(5);
  }
  
  double iPole = sumP / 10.0;
  double iHouse = sumH / 10.0;

  // 3. Clamping & Noise Floor
  if (iPole < 0.20 || iPole > 15.0) iPole = 0.0;
  if (iHouse < 0.20 || iHouse > 15.0) iHouse = 0.0;

  float currentDiff = abs(iPole - iHouse);
  double housePower = vRMS * iHouse; 

  // 4. Energy Accumulation
  unsigned long currentMillis = millis();
  double timeInHours = (currentMillis - lastMillis) / 3600000.0; 
  totalKWh += (housePower / 1000.0) * timeInHours;
  lastMillis = currentMillis;

  // 5. Smart Memory Save (Prevents Flash Wear)
  // Only saves to permanent memory if usage increases by 0.01 units
  if (totalKWh - lastSavedKWh >= 0.01) {
    prefs.putDouble("totalKWh", totalKWh);
    lastSavedKWh = totalKWh;
    Serial.println(">>> Backup Saved to Flash Memory <<<");
  }

  // 6. Tiered Slab Billing Logic
  if (totalKWh <= 100.0) {
    liveBill = totalKWh * BASE_RATE;
  } else {
    liveBill = (100.0 * BASE_RATE) + ((totalKWh - 100.0) * HIGH_RATE);
  }

  // 7. Update LCD Displays
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("P:"); lcd.print(iPole, 1); lcd.print("A");
  lcd.print(" H:"); lcd.print(iHouse, 1); lcd.print("A");

  lcd.setCursor(0, 1);
  lcd.print("Df:"); lcd.print(currentDiff, 1); lcd.print("A ");
  lcd.write(0); // Rupee symbol
  lcd.print(liveBill, 1);

  // 8. Update Blynk (Only if connected to avoid crashes)
  if (WiFi.status() == WL_CONNECTED) {
    Blynk.virtualWrite(V0, iPole);       
    Blynk.virtualWrite(V1, iHouse);      
    Blynk.virtualWrite(V2, "Running");   
    Blynk.virtualWrite(V3, (int)housePower);  
    Blynk.virtualWrite(V4, vRMS);        
    Blynk.virtualWrite(V5, totalKWh);    
    Blynk.virtualWrite(V6, liveBill);
  }

  // 9. THEFT TRIPLE-CHECK
  if (vRMS > 170.0 && currentDiff > THEFT_THRESHOLD) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERT WARNING");
    lcd.setCursor(0,1);
    lcd.print("Checking Noise..");
    
    smartDelay(500); 
    
    double checkP = (poleSensor.calcIrms(1480) - POLE_OFFSET);
    double checkH = houseSensor.calcIrms(1480);
    
    if (abs(checkP - checkH) > THEFT_THRESHOLD) {
       triggerAlert();
    }
  }
}

void triggerAlert() {
  isAlarmRunning = true;
  
  digitalWrite(relayPin, LOW);    // Cut Power
  digitalWrite(buzzerPin, HIGH);  // Alarm ON
  digitalWrite(ledPin, HIGH);     
  
  if (WiFi.status() == WL_CONNECTED) {
    Blynk.virtualWrite(V2, "THEFT!");
    Blynk.logEvent("power_theft", "Power bypass detected!");
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("!! THEFT !!");
  lcd.setCursor(0,1);
  lcd.print("POWER CUT - 5S");

  smartDelay(5000); // Uses smart delay!

  // Reset Hardware
  digitalWrite(buzzerPin, LOW);   
  digitalWrite(ledPin, LOW);      
  digitalWrite(relayPin, HIGH);   
  
  if (WiFi.status() == WL_CONNECTED) Blynk.virtualWrite(V2, "Running");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RESTORING POWER");
  lcd.setCursor(0,1);
  lcd.print("STABILIZING...");
  
  smartDelay(8000); // Uses smart delay!
  
  lastMillis = millis(); 
  isAlarmRunning = false;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // 1. Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, rupeeSymbol);
  
  // 2. Initialize Memory (Read last saved bill)
  prefs.begin("billing", false);
  totalKWh = prefs.getDouble("totalKWh", 17.71); // Defaults to 17.71 if new
  lastSavedKWh = totalKWh;

  lcd.setCursor(0,0);
  lcd.print("Smart Meter 3.0");
  lcd.setCursor(0,1);
  lcd.print("Mem Loaded...");
  delay(1500);

  // 3. Initialize Pins
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Power ON
  pinMode(relayPin, OUTPUT);

  // 4. Calibrate Sensors
  voltSensor.voltage(voltagePin, 100.0, 1.7); 
  poleSensor.current(poleCurrentPin, 30.0); 
  houseSensor.current(houseCurrentPin, 30.0);

  // 5. Offline Wi-Fi Setup (Non-Blocking)
  lcd.clear();
  lcd.print("Connecting WiFi.");
  WiFi.begin(ssid, pass);
  Blynk.config(BLYNK_AUTH_TOKEN); // Configures Blynk but doesn't freeze
  
  int wifi_attempts = 0;
  while (WiFi.status() != WL_CONNECTED && wifi_attempts < 10) {
    delay(500);
    Serial.print(".");
    wifi_attempts++;
  }

  lcd.clear();
  if (WiFi.status() == WL_CONNECTED) {
    lcd.print("WiFi Connected!");
  } else {
    lcd.print("Offline Mode!");
  }
  delay(2000);

  timer.setInterval(3000L, sendSensorData); 
  lastMillis = millis();
}

void loop() {
  // Only run Blynk if we actually have Wi-Fi
  if (WiFi.status() == WL_CONNECTED) {
    Blynk.run();
  }
  timer.run();
}
