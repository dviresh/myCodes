# Baton_rpi3

For the project descripton - please refer Baton Vehicle Project section at https://www.linkedin.com/in/viresh-duvvuri-64684859/

All the codes for this project are written in C++ using the OOPS and multi-threading techniques. Libraries and code samples for this code are borrowed from https://github.com/emlid/Navio.git

These codes run on a raspberry-pi based auto-pilot -> https://emlid.com/introducing-navio2/

1.) control.cpp:

	-> This is the main code that runs in the Main-Autopilot  used for controlling the BatonDrone. 
	-> Main-Autopilot sits on the body of the drone which commands the actuators to control the head of the BatonDrone.
	-> For the best flight of BatonDrone, head (housing the main rotor of BatonDrone) of the drone must be perfectly parallel to the Main-Autopilot and to the earth.  
	
	
	Code Summary: 

	i)  Code Input : real-time data from sensors (housed on auto-pilot)- accelerometer, gyroscope, magnetometer

	ii) Actions Performed: control.cpp runs 3 threads:
 
		Control Thread - runs the contol equations - sleeps for 25 ms
		Input	Thread - recives the control inputs from the human pilot - sleeps for 100 ms 
		Output  Thread - outputs the drone's status data to monitor and log file.
	
	iii) Code Output: pulse signals(integers) that command motor and actuators housed on BatonDrone

2.) Calibration.cpp:
	
	-> Calibration is done to make the head of BatoDrone perfectly parallel to Main-Autopilot and body of the BatonDrone
	-> Main-Autopilot runs the Calibration.cpp when the calibration mode is turned on (by the pilot) and Calibration-Autopilot is placed on head of BatonDrone.  
	
	Code Summary:
	
	i)  Code Input: Roll, Pitch and Yew readrings from sensors of Calibration-Autopilot

	ii) Actions Performed: 
 	
		-> Calibration.cpp compares recieved inputs with the roll, pitch and yaw readings from Main-Autopilot
		-> If both the readings match then BatonDrone - head is parallel to BatonDrone - Body, else compute offset to tilt head to its desired position
		-> Computes offsets are traformed to pulse signals for commanding actuators and rotors to perform action 

	iii) Code Output: Computed pulse signals are sent to actuators to perform necessary actions     
 
3.) AHRS.cpp:

	One of the header files taken from https://github.com/emlid/Navio.git, used in control.cpp
	
	Code Summary: Filters the raw data from sensors and transforms them to roll, pitch, yaw readings
		
	i)  Code Input : raw data from sensors (housed on auto-pilot)) - accelerometer, gyroscope, magnetometer
	ii) Code Output: roll, pitch, yaw


4.) Eigen: 
	
	Contains libraries for performing operations on matrix objects in C++. 
