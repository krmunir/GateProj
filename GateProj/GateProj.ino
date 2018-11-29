// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       GateProj.ino
	Created:	Tue 6 Nov 2018
	Author:     COHDA\kmunir
*/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


/********** #includes **********/
//software serial
#include <SoftwareSerial.h>

//WiFi and Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Other system
#include <string>

//User files
#include "gateControl.h"
#include "distanceSensor.h"
#include "led.h"
#include "openSensor.h"
#include "appWidgets.h"


/********** Blynk setup **********/
char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
BlynkTimer timer; //used to periodically push data to Blynk app

/********** appWidgets **********/
Led isOpenLED;
Led isHalfOpenLED;
Led isClosedLED;
Button FullOpenBtn;
Button HalfOpenBtn;
Button FullCloseBtn;
StyledButton StatusBtn;

/********** Pin Assignments **********/
//Outputs
constexpr auto SLIDING_GATE_CONTROL_PIN = 99;
constexpr auto RGB_LED_East_R_PIN = 99;
constexpr auto RGB_LED_East_G_PIN = 99;
constexpr auto RGB_LED_East_B_PIN = 99;
constexpr auto RGB_LED_South_R_PIN = 99;
constexpr auto RGB_LED_South_G_PIN = 99;
constexpr auto RGB_LED_South_B_PIN = 99;
constexpr auto BUZZER_PIN = 99;

//Inputs
constexpr auto SWING_GATE_East_PIN = 99;
constexpr auto SWING_GATE_South_PIN = 99;
extern const uint8_t SLIDING_GATE_CLOSED_LS_PIN = 99;
extern const uint8_t SLIDING_GATE_FULL_OPEN_LS_PIN = 99;
extern const uint8_t slidingGateDistanceSensor_RX = D2;
extern const uint8_t slidingGateDistanceSensor_TX = D4;


/********** Sliding Gate setup **********/
//gate control 
gateControl slidingGate(SLIDING_GATE_CONTROL_PIN);

//ultrasonic sensor
extern distanceSensor slidingGateDistanceSensor;
extern SoftwareSerial slidingGateDistanceSensorSerial;//forward declaration, definition in distanceSensor.cpp

//sensor settings
extern const unsigned short gateClosedReading = 7000;
extern const unsigned short gateHalfOpenReading = 4500;
extern const unsigned short gateFullyOpenReading = 1500;
extern const unsigned short readingTolerance = 50;//for half open only


/********** Swing Gate setup **********/
//setup swing gate east
openSensor swingGateEastStatus(SWING_GATE_East_PIN);
led swingGateEastLED(RGB_LED_East_R_PIN, RGB_LED_East_G_PIN, RGB_LED_East_B_PIN);

//setup swing gate south
openSensor swingGateSouthStatus(SWING_GATE_South_PIN);
led swingGateSouthLED(RGB_LED_South_R_PIN, RGB_LED_South_G_PIN, RGB_LED_South_B_PIN);



/********** Main Program Forward Declarations **********/
void pushBlynkDataToApp();


/********** Main Program Code **********/
// The setup() function runs once each time the micro-controller starts
void setup()
{
	//start serial to ultrasonic sensor
	slidingGateDistanceSensorSerial.begin(9600);

	//setup limit switches for sliding gate
	pinMode(SLIDING_GATE_CLOSED_LS_PIN, INPUT);
	pinMode(SLIDING_GATE_FULL_OPEN_LS_PIN, INPUT);

	//start serial for debugging
	Serial.begin(9600);

	//start Blynk
	Blynk.begin(auth, ssid, pass);
	timer.setInterval(250L, pushBlynkDataToApp);

	//for blinking led
	pinMode(D1, OUTPUT);
}


// Add the main program code into the continuous loop() function
void loop()
{
	//run Blynk
	Blynk.run();
	timer.run(); //periodically pushes Blynk data to app
	
	//blink LED to indicate program running
	digitalWrite(D1, HIGH);
	delay(500);
	digitalWrite(D1, LOW);
	delay(500);

	slidingGateDistanceSensor.checkIfGateMoving(); //updates isOpening and isClosing status
}

/********** Write Data to app **********/
void pushBlynkDataToApp() //this fn is called periodically based on interval set for 'Blynktimer timer' 
{
	//virtual pin 0 - Pushbutton 'Fully Open'

	//virtual pin 1 - Pushbutton 'Half Open'

	//virtual pin 2 - Pushbutton 'Fully Close'

	//virtual pin 3 - LED 'isOpen'

	//virtual pin 4 - LED 'isClosed'

	//virtual pin 5 - LED 'isHalfOpen'

	//virtual pin 6 - Styled button 'Status'

	//virtual pin 7 - Bar chart 'Gate Position'

	//virtual pin 8 - Terminal Input and Output

	


}



/********** Read Data from app **********/
BLYNK_WRITE(V0) {
	//virtual pin 0 - Pushbutton 'Fully Open'
	slidingGate.currCommand = gateControl::FULL_OPEN;

}

BLYNK_WRITE(V1) {
	//virtual pin 1 - Pushbutton 'Half Open'
	slidingGate.currCommand = gateControl::HALF_OPEN;

}

BLYNK_WRITE(V2) {
	//virtual pin 2 - Pushbutton 'Fully Close'
	slidingGate.currCommand = gateControl::FULL_CLOSE;

}

BLYNK_WRITE(V6) {
	//virtual pin 6 - Styled button 'Status'


}


//
//BLYNK_WRITE(V3) {
//	//virtual pin 3 - LED 'isOpen'
//
//
//}
//
//BLYNK_WRITE(V4) {
//	//virtual pin 4 - LED 'isClosed'
//
//
//}
//
//BLYNK_WRITE(V5) {
//	//virtual pin 5 - LED 'isHalfOpen'
//
//
//}
//
//BLYNK_WRITE(V7) {
//	//virtual pin 7 - Bar chart 'Gate Position'
//
//
//}
//
//BLYNK_WRITE(V8) {
//	//virtual pin 8 - Terminal Input and Output
//
//
//}
//


