#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4
int pos1=0,pos=0;
RF24 radio(8,9); // CE, CSN
uint8_t addresses[][6] = {"1Node", "2Node"};

Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  m1.attach(2);
  m2.attach(3);
  m3.attach(4);
  m4.attach(5);
  m5.attach(6);
  m1.write(1);
  m2.write(1);
  m3.write(1);
  m4.write(1);
  m5.write(1);
   if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {} 
  }
  Serial.println("responding!!");
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if ( radio.available()) {
      radio.read(&pos, sizeof(pos));
      int ch=abs(pos%10);
      pos1=pos/10;
      Serial.print(ch);Serial.print("\t");Serial.println(pos1);
      switch (ch)
      {
        case 1:
          m1.write(pos1);
        break;
        case 2:
          m2.write(pos1);
        break;
        case 3:
          m3.write(pos1);
        break;
        case 4:
          m4.write(pos1);
        break;
        case 5:
          m5.write(pos1);
        break;
        
      }
    }
  }
