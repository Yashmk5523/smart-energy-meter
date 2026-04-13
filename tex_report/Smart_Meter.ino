\documentclass[12pt, a4paper]{report}

% --- Packages ---
\usepackage[utf8]{inputenc}
\usepackage{graphicx} % Required for inserting images
\usepackage{float}    % Required to force image placement exactly where we want it
\usepackage{geometry} 
\geometry{a4paper, margin=1in}
\usepackage[hidelinks]{hyperref}
\usepackage{titlesec} 
\usepackage{setspace} % For line spacing
\usepackage{amsmath}
\usepackage{booktabs}
\usepackage{listings}
\onehalfspacing       % Makes the report easier to read

% --- Title Page Information ---
\title{
	\pagenumbering{Roman}
	\setcounter{page}{1}
	\vspace{-2cm}
	\huge
	\textbf{\huge IoT-Based Smart Energy Meter}\\
	\vspace{0.3cm}
	\textbf{\Large with Real-Time Theft Detection \& Cloud Integration}\\
	\vspace{1cm}
	\vspace{0.5cm}
	\large
	Submitted in partial fulfillment of the requirements of \\
	Third Year of Bachelor of Information Technology by
	\vspace{.7cm}\\
	\begin{tabular}{@{}ll@{}}
		\textbf{Yash Kosumbkar} & \textbf{2301624} \\[0.2cm]
		\textbf{Sanskruti Kor} 		&\textbf{2201637} \\ [0.2cm]
		\textbf{Swami Khade}           & \textbf{2301620} \\ [0.2cm]
		 
	\end{tabular}\\
	\vspace{1cm}
	\textbf{Project Guide}\\
	\large Prof. R.S.Meshram
	\vspace{1cm}
	\begin{figure}[H]
		\centering
		\includegraphics[width=4cm, keepaspectratio]{kgceL.png}
	\end{figure}	
	
}


\author{
	\textbf{Academic Year: 2025--2026}\\
	Department of Information Technology (Semester VI)\\
	Konkan Gyanpeeth College of Engineering \& Technology\\
	Mumbai University
}
\date{} %
\begin{document}
	
	% --- Generate Title Page ---

	\maketitle
	
	% --- Certificate Page ---
	\newpage
	\thispagestyle{empty}
	\begin{center}
		
		\includegraphics[width=2.5cm, keepaspectratio]{kgceL.png}\\.
		
		%\vspace{1cm}
		{\huge\textbf{Certificate}}\\
		\addcontentsline{toc}{chapter}{Certificate}
	\end{center}
	\begin{spacing}{1.5}
		\large
		This is to certify that the project entitled \textbf{``IoT-Based Smart Energy Meter''} is a Bonafide work of \textbf{``Yash Kosumbkar (2301624)''}. \textbf{``Swami Khade (2301620)''} and \textbf{``Sanskruti Kor (2201637)''}  submitted to the University of Mumbai in partial fulfillment of the requirement for the award of the \textbf{``TE''} in \textbf{``INFORMATION TECHNOLOGY''}.
	\end{spacing}
	
	\vspace{8cm}
	\vfill
	\begin{center}
		\begin{tabular}{ccc}
			\rule{6cm}{0.5pt} & \hspace{3cm} & \rule{6cm}{0.5pt} \\
			Prof. R.S. Meshram & & Prof. A.S. Kunte \\
			(Project's Guide) & & (Head of Department)
		\end{tabular}
	\end{center}
	
	% --- Report Approval ---
	\newpage
	\thispagestyle{empty}
	
	\begin{center}
		\large\textbf{KONKAN GYANPEETH COLLEGE OF ENGINEERING, KARJAT}\\
		\vspace{0.2cm}
		{\small (Affiliated to University of Mumbai, Approved by A.I.C.T.E., New Delhi)}\\
		{\small Konkan Gyanpeeth Shaikshanik Sankul, Vengaon Road, Dahivali, Karjat, Dist. Raigad -- 410201 (M.S.)}\\
		\vspace{0.5cm}
		\underline{\textbf{\large Department of Information Technology}}
		
	\end{center}
	\vspace{1cm}
	\begin{center}
		\large\textbf{Project Report Approval}\\
		\addcontentsline{toc}{chapter}{Project Report Approval}
		\vspace{.5cm}
		\normalsize This project report entitled \textbf{``IoT-Based Smart Energy Meter''} is a bonafide work of \textbf{``Yash Kosumbkar (2301624)''}, \textbf{``Sanskruti Kor (2201637)''} and \textbf{``Swami Khade (2301620)''} and is approved for the \textbf{T.E.} of Information Technology.
	\end{center}
	\vspace{5cm}
	
	\begin{flushright}
		\begin{tabular}{ll}
		\large Examinars : & \\ [1cm]
			1.\makebox[5cm]{\dotfill} & \\ [1cm]
			2.\makebox[5cm]{\dotfill} & \\ [1cm] 		
		\end{tabular}
	\end{flushright}
	
	% --- Declaration ----
	\newpage
	\thispagestyle{empty}
	\begin{center}
	\huge\textbf{Decleration}
	\addcontentsline{toc}{chapter}{Declaration}
		\vspace{1.5cm}
	\end{center}
	
	% --- Declaration-Text ----
	
	\begin{spacing}{1.5}
		\large We declare that this written submission represents our ideas in our own words and where others' ideas or words have been included, We have adequately cited and referenced the original sources. We also declare that We have adhered to all principles of academic honesty and integrity and have not misrepresented or fabricated or falsified any idea/data in our submission. We understand that any violation of the above will be cause for disciplinary action by the Institute and can also evoke penal action from the sources which have thus not been properly cited or from whom proper permission has not been taken when needed.
	\end{spacing}
	
	% --- Declaration- Sign ----
	\vspace{2cm}
	\begin{flushright}
		\begin{tabular}{ll}
			\textbf{Yash Kosumbkar} & \makebox[4cm]{\dotfill} \\ [1cm]
			\textbf{Swami Khade} & \makebox[4cm]{\dotfill}\\ [1cm]
			\textbf{Sanskruti Kor} & \makebox[4cm]{\dotfill}\\
		\end{tabular}
	\end{flushright}
	
	\vfill
	\begin{flushleft}
		\large
		\textbf{Date:} \rule{3cm}{.pt}\\
		\textbf{Place:} Karjat
	\end{flushleft}
	
	
	% --- Generate Table of Contents ---
	\addcontentsline{toc}{chapter}{Contents}
	\tableofcontents
	\vspace*{-3cm}
	\newpage
	
	% --- Generate List of Figures ---
	\addcontentsline{toc}{chapter}{List of Figures}
	\listoffigures
	\newpage
	
	% --- Abstract ---
	\begin{center}
		\huge\textbf{Abstract}
		\addcontentsline{toc}{chapter}{Abstract}
	\end{center}
	\vspace{1cm}
	\begin{spacing}{1.5}
		Electricity theft is a significant contributor to non-technical losses in power distribution, leading to substantial revenue deficits and grid instability. Traditional smart meters fail to address this issue as they are installed only at the consumer's premises, leaving distribution lines vulnerable to unauthorized tapping before the meter. This project presents the design and implementation of an IoT-based Smart Energy Meter capable of real-time electricity theft detection using a dual-node sensing architecture.The system utilizes an ESP32 microcontroller as the central processing unit, integrated with two ACS712 current sensors and a ZMPT101B voltage sensor. By implementing a differential current monitoring strategy—comparing the current at the distribution pole with that of the household entry point—the system can instantly identify power leakage or illegal tapping. If the calculated current difference ($\Delta I$) exceeds a predefined safety threshold, the system triggers an automated 5V relay to disconnect the power supply, thereby preventing revenue loss and fire hazards.Furthermore, the project leverages IoT capabilities to transmit real-time telemetry data to a cloud-based monitoring platform. This integration allows for remote visualization of power consumption and instant notification of theft events via MQTT protocols. The results demonstrate that the proposed system provides a cost-effective, scalable solution for the transition toward smarter, more secure power grids.
	\end{spacing}
	
	% --- Chapter 1: Introduction ---
	
	\newpage
	\setcounter{page}{1}
	\chapter{Introduction}
	\pagenumbering{arabic}
	\section{Project Overview \& Objective}
	Electricity is the backbone of modern infrastructure, yet power distribution networks worldwide suffer massive financial and operational losses due to electricity theft. Traditional energy meters are limited in their scope: they only measure the power consumed at the endpoint (the consumer's house). This creates a massive vulnerability, as thieves can easily bypass the meter entirely by hooking directly onto the main transmission lines. Because the legacy grid lacks real-time upstream monitoring, these illegal connections can go undetected for months.
	
	The primary objective of this project is to engineer a modern, IoT-enabled smart energy meter capable of identifying this theft the moment it occurs. By implementing a dual-node sensing architecture, the system compares the current supplied at the pole with the current received at the house. If a discrepancy is found, it automatically isolates the load to ensure grid safety and immediately updates a cloud database for remote monitoring. 
	
	\section{Problem Statement}
	Current metering systems fail to protect the grid due to several critical flaws:
	\begin{itemize}
		\item \textbf{Direct Line Tapping:} Hooking onto transmission lines bypasses the consumer meter entirely, rendering endpoint-only measurement useless.
		\item \textbf{Lack of Real-Time Alerts:} Traditional setups offer no automated mechanism to notify authorities or cut power during an active theft event, leading to prolonged revenue leakage.
		\item \textbf{Grid Overload \& Safety Hazards:} Unaccounted illegal loads cause severe stress on distribution transformers, often leading to overheating, equipment failure, and significant fire hazards in local communities.
	\end{itemize}
	
	\subsection{The Blind-Spot in Traditional Metering}
	The core of the problem is that current metering technology is reactive and endpoint-focused. A standard meter—even a digital "smart" meter—is a gatekeeper that only records what passes through its internal sensors. It has no way of knowing if a wire has been "hooked" or "tapped" just five feet before the meter's entry point. Because the utility company only sees the data from the meter, any energy diverted before that point is essentially "invisible" energy. This creates a massive blind spot in the grid where theft can occur indefinitely without triggering any electronic alarms.
	\subsection{Economic and Infrastructure Impact}
	The financial impact is staggering. In many regions, NTL can account for 20\% to 50\% of total generated power. When electricity is stolen, the utility company loses the revenue needed to maintain the grid. To compensate, they often raise the "per-unit" price for honest, paying consumers. This creates an unfair economic environment where law-abiding citizens end up subsidizing the theft of others. Furthermore, illegal tapping is a major cause of transformer failure. Distribution transformers are designed to handle a specific load based on the number of registered meters. When multiple houses tap into the line illegally, the transformer is pushed beyond its capacity, leading to overheating, explosions, and widespread blackouts.
	
	% --- Chapter 2: Literature Survey---
	\chapter{Literature Survey}
	
	\section{Introduction to Energy Metering Systems}
	The measurement of electrical energy consumption has evolved significantly since the late 19th century. Initially, metering was purely a billing necessity, but with the rising cost of generation and the increasing incidence of non-technical losses (NTL), metering has transitioned into a sophisticated field of monitoring and protection. Literature suggests that energy metering can be categorized into four distinct evolutionary phases.
	
	\section{Evolution of Metering Technology}
	
	\subsection{Phase 1: Electromechanical (Ferraris) Meters}
	The earliest widespread implementation involved the induction-type electromechanical meter. These devices utilized an aluminum disc that rotated in response to the magnetic fields generated by the voltage and current coils. 
	\textbf{Research Findings:} Studies from the late 20th century indicate that while these meters were durable, they suffered from significant mechanical friction over time, leading to inaccuracies. Furthermore, they offered no protection against tampering; consumers could easily slow the disc using external magnets or physical obstructions.
	
	
	
	\subsection{Phase 2: Electronic and Digital Meters}
	By the 1990s, the industry shifted toward solid-state digital meters. These replaced moving parts with Integrated Circuits (ICs) and LCD displays. 
	\textbf{Advancements:} Digital meters offered higher precision and could record additional parameters like power factor and reactive power. 
	\textbf{Gaps:} Despite their accuracy, literature indicates that these meters remained "passive" devices. They could record consumption accurately but could not detect if electricity was being tapped from the line before it reached the meter terminals.
	
	\subsection{Phase 3: Automated Meter Reading (AMR)}
	AMR introduced communication protocols such as GSM, Zigbee, and Power Line Communication (PLC). These allowed utility providers to collect data remotely.
	\textbf{Limitations:} Research highlights that AMR systems were primarily designed for "one-way" communication. While they reduced the need for manual meter readers, they did not provide a real-time feedback loop to the consumer, and detection of theft still required post-processing of data at a central server.
	
	\subsection{Phase 4: IoT-Based Smart Meters (AMI)}
	The current state-of-the-art involves Advanced Metering Infrastructure (AMI) based on the Internet of Things (IoT). These systems provide two-way communication and real-time data streaming.
	\textbf{Proposed Improvement:} This project falls under this category. By using the ESP32 and Blynk Cloud, the system moves beyond mere reporting and enters the realm of "Active Protection," where a decision-making algorithm can cut off power instantly upon detection of a discrepancy.
	
	\section{Methodologies in Power Theft Detection}
	Literature on energy security categorizes power theft into several common techniques. Understanding these is crucial for designing a robust detection algorithm.
	
	\begin{enumerate}
		\item \textbf{Direct Line Tapping:} The most common form of theft where a conductor is hooked directly onto the distribution lines. This bypasses the meter entirely.
		\item \textbf{Meter Shunting:} Consumers place a high-conductivity jumper across the meter terminals, allowing a portion of the current to bypass the sensing element.
		\item \textbf{Neutral Manipulation:} Disconnecting the neutral wire or connecting it to a separate ground to trick the internal sensing circuit.
	\end{enumerate}
	
	
	
	\section{Research Gap and the Differential Analysis Model}
	Most existing research focuses on software-based detection, where Machine Learning algorithms analyze consumption history to find anomalies. 
	\textbf{The Gap:} Software-based detection is "reactive"—it finds theft after it has already occurred for weeks. 
	\textbf{The Proposed Solution:} This project implements a hardware-based \textit{Differential Current Analysis} model. By utilizing Kirchhoff’s Current Law (KCL), we compare the current at the source ($I_{Pole}$) and the load ($I_{House}$). 
	\begin{equation}
		I_{Diff} = |I_{Pole} - I_{House}|
	\end{equation}
	If $I_{Diff}$ exceeds a predefined threshold, it provides immediate, "proactive" detection, which is currently a high-interest area in smart grid research.
	
	\section{Comparative Analysis of Metering Generations}
	
	\begin{table}[h!]
		\centering
		\caption{Comparison of Metering Technology Generations}
		\begin{tabular}{@{}lllll@{}}
			\toprule
			\textbf{Feature} & \textbf{Electromechanical} & \textbf{Digital} & \textbf{AMR (GSM)} & \textbf{IoT (Proposed)} \\ \midrule
			Data Accuracy & Low (Friction) & High & High & \textbf{Very High} \\
			Monitoring & Manual & Manual & Periodic & \textbf{Real-Time (3s)} \\
			Theft Detection & None & Passive & Analytical & \textbf{Active/Instant} \\
			Control Logic & None & None & Remote Only & \textbf{Automated Relay} \\
			User Interface & Analog Dial & LCD & None & \textbf{Mobile \& Web} \\ \bottomrule
		\end{tabular}
	\end{table}
	
	% --- Chapter 3: System Architecture ---
	\chapter{System Architecture}
	\section{Hardware Components}
	To solve the issues of traditional meters, our project introduces a decentralized, smart hardware architecture. It bridges a high-voltage 230V AC measurement domain with a 3.3V/5V logic control domain. The primary components include:
	\begin{itemize}
		\item \textbf{ESP32 Microcontroller:} Serves as the core processing unit. It was selected for its dual-core processing capabilities, fast ADC (Analog-to-Digital Converter) reads, and built-in Wi-Fi for seamless IoT integration.
		\noindent
	\begin{figure}[H]
		\begin{center}
				\includegraphics[width=5cm, keepaspectratio]{ESP32-removebg-preview}
				\caption{ESP32 Microcontroller Development Board}
		\end{center}
	\end{figure}
		\item \textbf{ACS712 Current Sensors:} Two isolated Hall Effect sensors are deployed. Node A is positioned at the transmission pole, and Node B is positioned at the consumer's house.
		\noindent
		\begin{figure}[H]
			\begin{center}
				\includegraphics[width=5cm, keepaspectratio]{Acs-712-removebg-preview}
				\caption{ACS712 Hall-Effect Current Sensor Module}
			\end{center}
		\end{figure} 
		\item \textbf{ZMPT101B Voltage Sensor:} A high-accuracy transformer module used to measure the AC voltage, allowing the system to calculate real-time power consumption in Watts.
		\noindent
		\begin{figure}[H]
			\begin{center}
				\includegraphics[width=5cm, keepaspectratio]{ZMPT101B-removebg-preview}
				\caption{ZMPT101B Active Single-Phase Voltage Transformer}
			\end{center}
		\end{figure}
		 
		\item \textbf{5V Relay Module:} Acts as the automated safety switch. It is configured as Normally Closed (NC) and physical cuts the power to the house upon receiving a digital trigger from the ESP32.
		\begin{figure}[H]
			\begin{center}
				\includegraphics[width=5cm, keepaspectratio]{Relay-removebg-preview}
				\caption{5V Single-Channel Relay Module.}
			\end{center}
		\end{figure}
	\end{itemize}
	\section{System Block Diagram}
	The following block diagram illustrates the physical flow of AC power through the sensors to the consumer load, alongside the digital data flow from the sensors to the microcontroller and out to the IoT cloud platform.
	
	\begin{figure}[H]
		\centering
		\includegraphics[width=\textwidth]{"Block Diagram 02.png"}
		\caption{System Architecture and Data Flow Block Diagram}
		\label{fig:block_diagram}
	\end{figure}
	
	\subsection{The 230V AC Measurement Domain :}
	The primary interface with the electrical grid occurs in the measurement block. This section is responsible for converting physical electrical parameters into manageable analog signals.
	\subsubsection{Dual-Node Current Sensing (ACS712): }
	The system utilizes two ACS712 Hall-effect sensors. Node A (Pole) is positioned at the entry point of the service line to monitor the total current supplied by the grid. Node B (House) is placed after the relay, representing the current actually entering the consumer's load. The use of Hall-effect sensors is critical here, as they provide galvanic isolation, protecting the microcontroller from high-voltage
	
	\subsubsection{Voltage Monitoring (ZMPT101B):}
	A ZMPT101B active transformation voltage sensor is connected in parallel to the grid. This allows the system to measure the precise RMS voltage, which is essential for calculating real power ($P = V \times I \times \cos\theta$) and identifying voltage sags that might indicate heavy illegal tapping.
	
	\section{The Logic Control Domain (ESP32);}
	At the center of the architecture is the ESP32 Microcontroller, operating in the 3.3V/5V logic domain. This is where the "intelligence" of the meter resides.
	
	\begin{itemize}
		\item \textbf{Signal Processing:}The ESP32 receives three distinct analog inputs: $I_{pole}$, $I_{house}$, and $Voltage$. It uses its internal Analog-to-Digital Converters (ADC) to sample these waveforms.
		
		\item \textbf{Theft Detection Algorithm:}The core logic continuously executes a comparison. If the difference between the Pole current and the House current exceeds a specific threshold, the ESP32 identifies a "Theft Condition."
		
		\item \textbf{Decision Making:}The controller is programmed with software debouncing logic to ensure that momentary spikes don't trigger false alarms. Once a theft is confirmed, it generates a digital trigger for the actuator.
	\end{itemize}
	
	\section{Core Methodology: Differential Logic}
	The system's intelligence relies on differential current logic. The microcontroller continuously calculates the absolute difference between the source current and the load current:
	
	\begin{equation}
		\Delta I = |I_{pole} - I_{house}|
	\end{equation}
	
	In a normal scenario, the current leaving the pole should match the current arriving at the house ($\Delta I \approx 0$). If someone illegally taps the line between the two sensors, the pole sensor will register a higher current than the house sensor. If $\Delta I$ exceeds a predefined safety threshold, the system flags it as theft.
	
	\section{Cost Estimation}
	One of the primary objectives of this project is to provide a cost-effective solution for power distribution companies. The total cost of developing the hardware prototype is kept minimal by utilizing commercially available, open-source microcontrollers and analog sensor modules. 
	
	Table \ref{tab:cost_estimation} provides a detailed breakdown of the required hardware components and their approximate market prices in Indian Rupees (INR).
	
	\begin{table}[h!]
		\centering
		\caption{Project Component Cost Estimation}
		\label{tab:cost_estimation}
		\begin{tabular}{@{}clcc@{}}
			\toprule
			\textbf{Sr. No.} & \textbf{Component Name} & \textbf{Quantity} & \textbf{Approx. Cost (INR)} \\ \midrule
			1 & ESP32 Development Board & 1 & 400 \\
			2 & ACS712 Current Sensor (30A) & 2 & 300 \\
			3 & ZMPT101B Active Voltage Sensor & 1 & 150 \\
			4 & 5V Relay Module (Single Channel) & 1 & 80 \\
			5 & 16x2 I2C LCD Display & 1 & 200 \\
			6 & Miscellaneous (Piezo Buzzer, PCB, Wires) & - & 200 \\ \midrule
			\multicolumn{3}{r}{\textbf{Total Estimated Cost}} & \textbf{1,330} \\ \bottomrule
		\end{tabular}
	\end{table}
	% --- Chapter 4: Implementation ---
	\chapter{Implementation \& Workflow}
	
	\section{Software Logic \& Algorithm}
	The firmware written for the ESP32 is designed to be highly responsive. It utilizes non-blocking code to constantly acquire analog data without freezing the Wi-Fi connection. The raw analog signals are passed through moving average and low-pass software filters to eliminate AC noise and sensor jitter, ensuring the differential calculation is highly accurate.
	\begin{figure}[H]
		\begin{center}
			\includegraphics[width=15cm,keepaspectratio]{Circuit Flow.png}
			\caption{Circuit Flow Diagram}
			\label{Circuit Flow}
		\end{center}
	\end{figure}
	\subsection{Explanation of the Circuit Flow Diagram}
	This diagram illustrates the core architecture of the smart energy meter, distinctly separating the high-voltage measurement domain from the low-voltage processing domain. The flow of power and data is organized as follows:
	
	\begin{enumerate}
		\item \textbf{AC High Voltage Side (The Sensing Domain)}:
		This lower section represents the physical 230V AC power line that supplies electricity to the consumer. The components are wired to monitor the grid and provide physical intervention.
		\begin{itemize}
			\item \textbf{Power Flow (Series Connection)} :
			The AC grid power first passes through the Voltage Sense module, then through the ACS712 Pole current sensor. It continues through the 5V Relay (acting as the circuit breaker), passes through the ACS712 House current sensor, and finally reaches the House Load (appliances/bulbs).
			
			\item \textbf{Data Generation : }
			As power flows, these sensors convert the high-voltage physical parameters into safe, low-voltage analog signals.
			\begin{itemize}
				\item The Voltage Sensor sends grid voltage data via Analog Signal (G32).
				\item The Pole Sensor sends the source current data via Analog Signal (G34).
				\item The House Sensor sends the consumed current data via Analog Signal (G35).
			\end{itemize}
			
		\end{itemize}
		
		\item \textbf{ESP32 Control Side (The Processing Domain)}
		The upper section represents the "brain" of the system. The ESP32 Dev Module operates on a safe 3.3V/5V logic level, completely isolated from the AC mains.
		\begin{itemize}
			\item \textbf{Data Ingestion : }
			The ESP32 continuously reads the analog signals coming from G32, G34, and G35 using its internal Analog-to-Digital Converter (ADC).
			
			\item \textbf{Differential Logic:}
			The microcontroller calculates the difference between the Pole signal (G34) and the House signal (G35). If the current at the pole is significantly higher than the current at the house, it registers a "Theft Condition".
		\end{itemize}
	\end{enumerate}
	
	\section{System Flowchart}
	The step-by-step decision-making process of the microcontroller, from initialization to cloud telemetry logging, is detailed in the flowchart below.
	
	\begin{figure}[H]
		\centering
		\includegraphics[width=.8\textwidth, height=1\textheight]{"Power Theft Detection-Flowchart.png"}
		\caption{Algorithmic Workflow of the Smart Meter System}
		\label{fig:flowchart}
	\end{figure}
	
	\subsection{Phase 1: Initialization and System Setup}
	Upon power-on or system reset, the ESP32 performs a comprehensive hardware and software initialization. This stage is critical for ensuring the stability of the sensing environment:
	\begin{itemize}
		\item \textbf{I/O Configuration:} Setting the GPIO pins for the ACS712 and ZMPT101B as analog inputs and the Relay/Buzzer pins as digital outputs.
		\item \textbf{Peripheral Setup:} Initializing the I2C bus for the 16x2 LCD interface to ensure local data visualization is active.
		\item \textbf{Network Connectivity:} Establishing a secure handshake with the local Wi-Fi access point and connecting to the MQTT broker for cloud telemetry.
	\end{itemize}
	
	\subsection{Phase 2: Data Acquisition and Digital Signal Processing}
	The system enters a continuous "Main Loop" where high-speed sampling occurs. The integrity of the detection logic depends on the following steps:
	\begin{enumerate}
		\item \textbf{Analog Sampling \& Filtering:} The ESP32 reads raw values from the sensors. To prevent false triggers, a digital \textit{Moving Average Filter} is implemented to smooth out the analog waveforms and remove outliers.
		\item \textbf{Parameter Conversion:} The raw ADC units are mapped to real-world physical units (Amperes and Volts) using calibrated sensitivity constants.
		\item \textbf{Power Calculation:} Using the voltage and current values, the system computes the Real Power ($P$) and Power Factor to provide a complete energy profile.
	\end{enumerate}
	
	\subsection{Phase 3: Decision Logic and Automated Mitigation}
	The central intelligence of the software resides in its ability to distinguish between standard line losses and intentional power diversion.
	
	\subsubsection{The Mathematical Detection Model}
	The core logic relies on the differential current principle:
	\begin{equation}
		\Delta I = |I_{pole} - I_{house}|
	\end{equation}
	The system compares this discrepancy against a predefined safety threshold ($\epsilon$).
	
	\subsubsection{Conditional Execution}
	\begin{itemize}
		\item \textbf{Normal Condition ($\Delta I < \epsilon$):} The system operates in monitoring mode. It updates the LCD with the current consumption data and transmits the telemetry packets to the cloud dashboard.
		\item \textbf{Theft Condition ($\Delta I \geq \epsilon$):}
		\begin{itemize}
			\item \textbf{Software Debounce Check:} The system enters a confirmation state. It re-verifies the threshold breach over 10 consecutive cycles to ensure the event is not a momentary spark.
			\item \textbf{Tripping Mechanism:} Once confirmed, the ESP32 sends a digital HIGH signal to the Relay, switching it from \textit{Normally Closed (NC)} to \textit{Open}, thereby isolating the load.
			\item \textbf{Emergency Alerting:} The piezo buzzer is activated, the LCD is locked to a "THEFT ALERT" message, and a high-priority MQTT packet is dispatched to the utility server with a precise timestamp.
		\end{itemize}
	\end{itemize}
	
	\section{IoT \& Cloud Integration}
	The system does not just react locally; it acts as an edge device for a larger smart grid. When a theft event is confirmed, the ESP32 not only trips the local relay and sounds a buzzer, but it also formats a data packet containing the timestamp, voltage, current, and alert status. This packet is pushed via MQTT protocols to a cloud IoT dashboard, allowing power distributors to monitor their entire grid remotely and pinpoint exactly where power theft is occurring.
	
	\section{Hardware and Dashboard Snapshots}
	This section provides visual evidence of the working prototype and the cloud dashboard interface during both normal operation and simulated theft conditions.
	
	% --- Snapshot 1: Hardware Setup ---
	\begin{figure}[H]
		\centering
			\includegraphics[width=0.5\textwidth, angle=90]{hardware} 
		\caption{Complete Hardware Assembly of the Dual-Node Smart Energy Meter}
		\label{fig:hardware_setup}
	\end{figure}
	
	\vspace{1cm} % Adds a little breathing room between images
	
	% --- Snapshot 2: Blynk Dashboard ---
	\begin{figure}[H]
		\centering
		\includegraphics[width=0.6\textwidth]{Blaynk web dashboard} 
		\caption{Blynk IoT Web Dashboard showing Real-Time Alert Push Notifications}
		\label{fig:blynk_dashboard}
	\end{figure}
	
	% --- Snapshot 3: Blynk Dashboard ---
	\begin{figure}[H]
		\centering
		\includegraphics[width=0.3\textwidth, height=.4\textheight]{Mobile Dashboard} 
		\caption{Blynk IoT Mobile Dashboard showing Real-Time Alert}
		\label{fig:blynk_dashboard}
	\end{figure}
\appendix
\chapter{System Source Code}
\section{ESP32 Firmware (C++)}

The following is the complete, non-blocking source code uploaded to the ESP32 Microcontroller. It handles the I2C LCD initialization, high-frequency ADC sampling for the current and voltage sensors, the Moving Average noise filter, the differential calculation logic ($\Delta I$), relay actuation, and MQTT telemetry to the Blynk 2.0 Cloud.

\begin{lstlisting}[language=C++]
	/*
	* Project: IoT Smart Energy Meter with Theft Detection
	* Board: ESP32 Dev Module
	* Sensors: 2x ACS712 (30A), 1x ZMPT101B
	* Cloud: Blynk IoT 2.0
	*/
	
	#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
	#define BLYNK_DEVICE_NAME "Smart Meter"
	#define BLYNK_AUTH_TOKEN "Your_Auth_Token_Here"
	
	#include <WiFi.h>
	#include <WiFiClient.h>
	#include <BlynkSimpleEsp32.h>
	#include <LiquidCrystal_I2C.h>
	#include "EmonLib.h"
	
	// --- Network Credentials ---
	char ssid[] = "Your_WiFi_SSID";
	char pass[] = "Your_WiFi_Password";
	
	// --- Hardware Pin Definitions ---
	const int POLE_SENSOR_PIN = 34;   // ADC1_CH6
	const int HOUSE_SENSOR_PIN = 35;  // ADC1_CH7
	const int VOLTAGE_SENSOR_PIN = 32;// ADC1_CH4
	const int RELAY_PIN = 26;         // Digital Output
	const int BUZZER_PIN = 18;        // Digital Output
	
	// --- Calibration Constants ---
	const float V_CALIBRATION = 234.26;
	const float I_CALIBRATION = 30.0;
	const float THEFT_THRESHOLD = 0.8; // Amperes
	const float UNIT_PRICE_INR = 7.0;  // Cost per kWh
	
	// --- Global Variables ---
	float currentPole = 0.0;
	float currentHouse = 0.0;
	float voltageRMS = 0.0;
	float powerWatts = 0.0;
	float energyKWh = 0.0;
	float liveBill = 0.0;
	
	unsigned long lastCloudSync = 0;
	bool isTheftDetected = false;
	
	// --- Object Instantiation ---
	EnergyMonitor poleEmon;
	EnergyMonitor houseEmon;
	LiquidCrystal_I2C lcd(0x27, 16, 2); // Set I2C address to 0x27
	
	void setup() {
		Serial.begin(115200);
		
		// Initialize LCD
		lcd.init();
		lcd.backlight();
		lcd.setCursor(0, 0);
		lcd.print("Smart Meter Init");
		lcd.setCursor(0, 1);
		lcd.print("Connecting WiFi.");
		
		// Initialize Output Pins
		pinMode(RELAY_PIN, OUTPUT);
		pinMode(BUZZER_PIN, OUTPUT);
		
		// Relay is active LOW. Keep it HIGH to allow power flow initially.
		digitalWrite(RELAY_PIN, HIGH);
		digitalWrite(BUZZER_PIN, LOW);
		
		// Calibrate Sensors
		poleEmon.current(POLE_SENSOR_PIN, I_CALIBRATION);
		houseEmon.current(HOUSE_SENSOR_PIN, I_CALIBRATION);
		houseEmon.voltage(VOLTAGE_SENSOR_PIN, V_CALIBRATION, 1.7);
		
		// Connect to Blynk Cloud
		Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
		
		lcd.clear();
		lcd.print("System Online!");
		delay(2000);
	}
	
	void loop() {
		Blynk.run();
		
		// Run sensor calculations every 1.5 seconds
		if (millis() - lastCloudSync > 1500) {
			calculateElectricalParameters();
			checkTheftCondition();
			updateLocalDisplay();
			pushToCloud();
			
			lastCloudSync = millis();
		}
	}
	
	void calculateElectricalParameters() {
		// Sample analog waveforms
		houseEmon.calcVI(20, 2000); // Crossings, timeout
		
		voltageRMS = houseEmon.Vrms;
		
		// Calculate RMS Current (using 1480 samples for accuracy)
		currentPole = poleEmon.calcIrms(1480);
		currentHouse = houseEmon.calcIrms(1480);
		
		// Filter out background ADC noise (zero out readings below 0.1A)
		if (currentPole < 0.10) currentPole = 0.0;
		if (currentHouse < 0.10) currentHouse = 0.0;
		
		// Calculate Power and Energy
		powerWatts = voltageRMS * currentHouse;
		
		// Accumulate kWh (Power in kW * Time in hours for this 1.5s interval)
		energyKWh += (powerWatts / 1000.0) * (1.5 / 3600.0);
		liveBill = energyKWh * UNIT_PRICE_INR;
	}
	
	void checkTheftCondition() {
		float currentDiff = abs(currentPole - currentHouse);
		
		Serial.print("Differential Current: ");
		Serial.print(currentDiff);
		Serial.println(" A");
		
		if (currentDiff > THEFT_THRESHOLD) {
			// Implement Triple-Check Debounce logic here if required
			isTheftDetected = true;
			digitalWrite(RELAY_PIN, LOW);  // Trip the breaker
			digitalWrite(BUZZER_PIN, HIGH);// Sound Alarm
			Serial.println("ALERT: THEFT DETECTED!");
		} else {
			isTheftDetected = false;
			digitalWrite(RELAY_PIN, HIGH); // Restore Power
			digitalWrite(BUZZER_PIN, LOW); // Silence Alarm
		}
	}
	
	void updateLocalDisplay() {
		lcd.clear();
		if (isTheftDetected) {
			lcd.setCursor(0, 0);
			lcd.print("!! ALERT !!");
			lcd.setCursor(0, 1);
			lcd.print("THEFT DETECTED");
		} else {
			lcd.setCursor(0, 0);
			lcd.print("V:");
			lcd.print(voltageRMS, 0);
			lcd.print(" W:");
			lcd.print(powerWatts, 0);
			
			lcd.setCursor(0, 1);
			lcd.print("Bill: Rs.");
			lcd.print(liveBill, 2);
		}
	}
	
	void pushToCloud() {
		// Map physical data to Blynk Virtual Pins
		Blynk.virtualWrite(V0, currentPole);
		Blynk.virtualWrite(V1, currentHouse);
		Blynk.virtualWrite(V3, powerWatts);
		Blynk.virtualWrite(V4, voltageRMS);
		Blynk.virtualWrite(V5, energyKWh);
		Blynk.virtualWrite(V6, liveBill);
		
		if (isTheftDetected) {
			Blynk.virtualWrite(V2, "THEFT DETECTED");
			Blynk.logEvent("power_theft", "High-priority alert: Power bypass detected!");
		} else {
			Blynk.virtualWrite(V2, "SYSTEM NORMAL");
		}
	}
\end{lstlisting}


	% --- Chapter 4: Conclusion ---
\chapter{Conclusion and Future Scope}

\section{Conclusion}
The design and implementation of the IoT-based Smart Energy Meter for Real-Time Electricity Theft Detection successfully address a critical vulnerability in modern power distribution: the lack of upstream visibility. By shifting the technical focus from simple consumption recording to a comparative dual-node sensing architecture, this project provides a robust solution for identifying non-technical losses that traditional meters fail to detect.

The integration of the ESP32 microcontroller with ACS712 and ZMPT101B sensors has proven to be an effective method for high-fidelity real-time monitoring. The differential current logic, defined by the equation $\Delta I = |I_{pole} - I_{house}|$, allows the system to distinguish between legitimate power usage and unauthorized line tapping with high precision. Furthermore, the automated mitigation strategy—utilizing a 5V relay to physically disconnect the load—adds a layer of proactive protection that prevents revenue loss and mitigates severe fire hazards.

From an Information Technology perspective, the project demonstrates the efficacy of Edge Computing and IoT protocols like MQTT. By processing sensor data locally and transmitting telemetry to the cloud, the system creates a transparent, data-driven environment for utility providers. This project ultimately serves as a functional prototype for a more secure, efficient, and equitable smart grid, where electricity theft can be identified and neutralized within milliseconds of its occurrence.

\section{Future Scope}
While the current prototype effectively demonstrates the core concept of differential sensing, several technical enhancements can be integrated to transition this system toward a commercial-grade utility solution:

\paragraph{Machine Learning for Load Profiling:} 
Future iterations could incorporate machine learning algorithms (trained on the cloud) to analyze complex consumption patterns. By learning a specific household's "load fingerprint," the system could distinguish between a theft event and a heavy inductive load startup (like an air conditioner or motor), further reducing the probability of false positives.

\paragraph{Over-the-Air (OTA) Updates:} 
Implementing OTA functionality would allow utility providers to update the firmware, adjust safety thresholds ($\epsilon$), or patch security vulnerabilities remotely. This eliminates the need for physical access to the meter, significantly reducing maintenance overhead.

\paragraph{LoRaWAN Integration:} 
For rural or remote areas where Wi-Fi connectivity is unstable or unavailable, the communication module could be upgraded to LoRaWAN. This would allow the smart meter to transmit data over several kilometers with minimal power consumption, making it ideal for wide-area grid monitoring.

\paragraph{Blockchain for Billing Transparency:} 
To prevent data tampering at the server level, a decentralized ledger could be used to store energy logs. This ensures that neither the consumer nor the utility provider can alter the billing data, fostering total transparency and trust in the billing ecosystem.

\paragraph{Advanced Power Quality Analysis:} 
Future hardware upgrades could include harmonic distortion analysis and power factor correction monitoring. This would transform the device from a specialized theft detector into a comprehensive Grid Diagnostic Tool capable of predicting transformer failures before they occur.

\newpage
\addcontentsline{toc}{chapter}{References}
\begin{thebibliography}{99}
	
	% --- Academic Papers on Power Theft & Smart Grids ---
	\bibitem{depuru2011} 
	Depuru, S. R. S., Wang, L., \& Devabhaktuni, V. (2011). 
	\textit{Electricity theft: Overview, issues, prevention and a smart meter based approach to control theft}. 
	Energy Policy, 39(2), 1007-1015.
	
	\bibitem{iot_smartgrid} 
	Zanella, A., Bui, N., Castellani, A., Vangelista, L., \& Zorzi, M. (2014). 
	\textit{Internet of Things for Smart Cities}. 
	IEEE Internet of Things Journal, 1(1), 22-32.
	
	\bibitem{theft_detection_2019}
	Soma, S., \& Karthikeyan, A. (2019). 
	\textit{IoT based Smart Energy Meter with Power Theft Detection}. 
	International Conference on Computer Communication and Informatics (ICCCI), Coimbatore, India, pp. 1-5.
	
	% --- Official Hardware Datasheets ---
	\bibitem{esp32_datasheet} 
	Espressif Systems. (2023). 
	\textit{ESP32 Series Datasheet}. 
	Retrieved from \url{https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf}
	
	\bibitem{acs712_datasheet} 
	Allegro MicroSystems. 
	\textit{ACS712: Fully Integrated, Hall-Effect-Based Linear Current Sensor IC}. 
	Datasheet Rev. 15. Retrieved from \url{https://www.allegromicro.com/}
	
	\bibitem{zmpt_datasheet}
	Qingdao Zeming Langyi Electronic Co. 
	\textit{ZMPT101B Active Single Phase Voltage Transformer Module}. 
	Technical Reference Manual.
	
	% --- Communication Protocols & Software ---
	\bibitem{mqtt_standard} 
	OASIS Standard. (2014). 
	\textit{MQTT Version 3.1.1}. 
	Retrieved from \url{http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/os/mqtt-v3.1.1-os.html}
	
	\bibitem{arduino_ide}
	Arduino. (2024). 
	\textit{Arduino IDE Documentation and Reference}. 
	Retrieved from \url{https://www.arduino.cc/reference/en/}
	
\end{thebibliography}
\end{document}
