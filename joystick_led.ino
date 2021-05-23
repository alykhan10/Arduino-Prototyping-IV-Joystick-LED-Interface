/***********************************************************************************************************
 * 
 * Author:    Aly Khan Nuruddin
 * Date:      May 11, 2021
 * Purpose:   This program permits the user to toggle the start and end states of an LED matrix by actuating
 *            motion of an analog joystick on the horizontal and vertical axes, and by triggering the switch.
 *            
 ***********************************************************************************************************/

int joystickX = A0;                              // Define the Analog Pin connection for the x-axis of the analog joystick.
int joystickY = A1;                              // Define the Analog Pin connection for the y-axis of the analog joystick.

int ledWhite = 7;                                // Define the Digital Pin connection for the White LED.

int ledRed = 8;                                  // Define the Digital Pin connection for the Red LED.
int ledBlue = 9;                                 // Define the Digital Pin connection for the Blue LED.
int ledGreen = 10;                               // Define the Digital Pin connection for the Green LED.
int ledYellow = 11;                              // Define the Digital Pin connection for the Yellow LED.

int switchPin = 2;                               // Define the Digital Pin connection for the switch of the analog joystick.

int currentState = 0;                            // Initialize the current state of the switch on the analog joystick. 
int previousState = 0;                           // Initialize the previous state of the switch on the analog joystick.

void setup() {
  pinMode(ledWhite, OUTPUT);                     // Configure the Digital Pin for the White LED to be recognized as an Output.
  pinMode(switchPin,INPUT);                      // Configure the Digital Pin for the switch to be recognized as an Input.
  digitalWrite(switchPin, HIGH);                 // Set the ouput voltage value at the Digital Pin for the switch to 5 V.
  
  Serial.begin(9600);                            // Initialize communication with the Serial Monitor at a baud rate of 9600.

  pinMode(8,OUTPUT);                             // Configure the Digital Pin for the Red LED to be recognized as an Output.
  pinMode(9,OUTPUT);                             // Configure the Digital Pin for the Blue LED to be recognized as an Output.
  pinMode(10,OUTPUT);                            // Configure the Digital Pin for the Green LED to be recognized as an Output.
  pinMode(11,OUTPUT);                            // Configure the Digital Pin for the Yellow LED to be recognized as an Output.
}
 
void loop()
{
  int xPosition = analogRead(joystickX);         // Read the position of the x-coordinate on the analog joystick.
  int yPosition = analogRead(joystickY);         // Read the position of the y-coordinate on the analog joystick.
  
  Serial.print(xPosition);                       // Print the position of the x-coordinate on the Serial Monitor.                                  
  Serial.print("\t");                            // Print a "space" on the Serial Monitor. 
  Serial.println(yPosition);                     // Print the position of the y-coordinate on the Serial Monitor. 
  
  currentState = digitalRead(switchPin);         // Read the current state of the switch on the analog joystick.
  Serial.println(currentState);                  // Print the current state of the switch on the Serial Monitor.
  
  if (xPosition >= 550)                          // Define the condition when the analog joystick is moved upwards.
  {
    digitalWrite(ledRed, HIGH);                  // Set the output voltage at the Red LED to 5 V.
  }
  
  else                                           // Define the condition when the analog joystick is not moved upwards.
  {
    {digitalWrite(ledRed, LOW);}                 // Set the output voltage at the Red LED to 0 V.
  }

  if (xPosition <= 450)                          // Define the condition when the analog joystick is moved downwards.
  {
    digitalWrite(ledBlue, HIGH);                 // Set the output voltage at the Blue LED to 5 V.
  }
  
  else                                           // Define the condition when the analog joystick is not moved downwards.
  {
    digitalWrite(ledBlue, LOW);                  // Set the output voltage at the Blue LED to 0 V.
  }

  if (yPosition >= 550)                          // Define the condition when the analog joystick is moved towards the right.
  {
    digitalWrite(ledGreen, HIGH);                // Set the output voltage at the Green LED to 5 V.
  }
  
  else                                           // Define the condition when the analog joystick is not moved towards the right.
  {
    digitalWrite(ledGreen, LOW);                 // Set the output voltage at the Green LED to 0 V.
  }

  if (yPosition <= 450)                          // Define the condition when the analog joystick is moved towards the left.
  {
    digitalWrite(ledYellow, HIGH);               // Set the output voltage at the Yellow LED to 5 V.
  }
  
  else                                           // Define the condition when the analog joystick is not moved towards the left.
  {
    digitalWrite(ledYellow, LOW);                // Set the output voltage at the Yellow LED to 0 V.
  }

  if (previousState == LOW)                      // Define the condition when the switch on the analog joystick is pressed.
  {             
    digitalWrite(ledWhite, HIGH);                // Set the output voltage at the White LED to 5 V.
    Serial.println("Switch = High");             // Print the previous switch state on the Serial Monitor.
  }
  
  else                                           // Define the condition when the switch on the analog joystick is not pressed.
  {
    digitalWrite(ledWhite, LOW);                 // Set the output voltage at the White LED to 0 V.
  }
  
  currentState = digitalRead(ledWhite);          // Read the current switch state from the Digital Pin for the White LED.
  Serial.println(currentState);                  // Print the current switch state on the Serial Monitor.
  
  delay(100);                                    // Delay the execution of the program by 100 milliseconds (ms).
}
