/*
Módulo para ESP32 que utiliza el dispositivo DFplayer nMini
y la libería DFPLayer mini : https://github.com/DFRobot/DFRobotDFPlayerMini


*/

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <HardwareSerial.h>

// Define los pines para la UART virtual
const int RxPin = 14;
const int TxPin = 15;
int modo = 1;       // 1 - TX , 2 - RX , 0 HALT
// Crea el objeto para la UART virtual
HardwareSerial FPSerial(2);     // Define the serial port for communication with the DFPlayer Mini


// Create an instance of the DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;

// Function to print detailed messages from the DFPlayer Mini
void printDetail(uint8_t type, int value) {
  // Handle messages based on type
}

// Function to play a specific sound file with a given duration
void playSound(int soundNumber, int duration) {
  myDFPlayer.play(soundNumber);
  delay(duration * 1000); // Convert duration from seconds to milliseconds
}

void setup() {

  FPSerial.begin(9600, SERIAL_8N1, RxPin, TxPin);   
  FPSerial.setTimeout(20);                       // Fijar time-out para operaciones readString 
  Serial.begin(115200);

  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(FPSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(20); // Set volume value. From 0 to 30
}

void loop() {
  // Example usage: Play sound file 1 for 5 seconds
  Serial.println(F("Play mp3."));
  playSound(2, 10);
  Serial.println(F("Stop mp3."));
  while (true){}
  // Add more code here to play other sound files or implement other functionality
}
