
#include "BootUp.h"
// #include "SerialBufferClear.h"
#include "Hour.h"
#include "Minute.h"
#include "Second.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX

void boot_up();
void hour_funct(unsigned char tens, unsigned char unit);
void minute_funct(unsigned char tens, unsigned char unit);
void second_funct(unsigned char tens, unsigned char unit);

unsigned char Packet[20];
bool ValidPacket = false;
int index = 0;

void setup() {
    mySerial.begin(9600);
  Serial.begin(9600);
  DDRB |= B00011100;  //Digital pin 10, 11, 12 as output
  DDRD |= B11111100;  //Digital pin 2, 3, 4, 5, 6, 7 as output
  DDRC |= B00000100; // Analog pin A0 as output
  PORTB = B00000000; 
  PORTC = B00000000;
  PORTD = B00000000;
  pinMode(A2, OUTPUT);
  boot_up();  // Show Initializer, All Led will turn on in a specific squence
}

void loop() {
  index = 0;
  // If the incoming data is greater than 10, Actually game time packet length is 10
  if (Serial.available() >= 10)
  {
    // Load value in Packet Array. Until Serial Buffer is clear.
    while (Serial.available() > 0) {
      Packet[index] = Serial.read(); // Read from serial buffer and put in Packet array.
      mySerial.print(""); // Unecessary! Code is not working without it.
      index += 1; //Index increasing for Packet Array.
    }
    // If condition will check the Header and Footer. If true then will display data on 7 segment.
    if (Packet[0] == 125 && Packet[1] == 215 && Packet[8] == 255 && Packet[9] == 250) {
      ValidPacket = true;
    }
    else {
      ValidPacket = false;
    }
  }
  
  if (ValidPacket)
  {
    hour_funct(Packet[7], Packet[6]); // Hour Function, takes two digits, tens and units.
    minute_funct(Packet[5], Packet[4]); //Minute Function, takes two digits, tens and units.
    second_funct(Packet[3], Packet[2]); //Second Function, takes two digits, tens and units.
  }
  delay(2);
}
