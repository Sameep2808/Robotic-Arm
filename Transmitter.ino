const int F5= A5;
const int F4= A4;
const int F3= A3;
const int F2= A2;
const int F1= A1; 
#include <Servo.h>
Servo myservo;
int pos1,pos2,pos3;
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(3,4); // CE, CSN
uint8_t addresses[][6] = {"1Node", "2Node"};
boolean buttonState = 0;
int pos=0;
void setup() 
{
  pos3=0;
  pos2=0;
  pos1=0;
  Serial.begin(9600);
   if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {} 
  }
  myservo.attach(3);
  pinMode(F1, INPUT);
  pinMode(F2, INPUT);
  pinMode(F3, INPUT);
  pinMode(F4, INPUT);
  pinMode(F5, INPUT);
  pinMode(12, OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{ 
  
  flex(1);
  delay(10);
  flex(2);
  delay(10);
  flex(3);
  delay(10);
  flex(4);
  delay(10);
  flex(5);
  delay(10);
  
  }

void flex(int o)
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC =0;
  switch(o){
      case 1:
        flexADC = analogRead(F1);
        Serial.println("1 Selected");
        if(flexADC>1020)
        {pos=110;}
        else
        {pos=1;}
        if(pos>0){
        pos=(10*pos)+1;
        radio.write(&pos, sizeof(pos));
        Serial.println(pos);}
      break;
      case 2:
        flexADC = analogRead(F2);
        Serial.println("2 Selected");
        if(flexADC>1020)
        {pos=110;}
        else
        {pos=1;}
        if(pos>0){
        pos=(10*pos)+2;
        radio.write(&pos, sizeof(pos));
        Serial.println(pos);}
      break;
      case 3:
        flexADC = analogRead(F3);
        Serial.println("3 Selected");
        if(flexADC>1020)
        {pos=110;}
        else
        {pos=1;}
        if(pos>0){
        pos=(10*pos)+3;
        radio.write(&pos, sizeof(pos));
        Serial.println(pos);}
      break;
      case 4:
        flexADC = analogRead(F4);
        Serial.println("4 Selected");
        if(flexADC>1020)
        {pos=110;}
        else
        {pos=1;}
        if(pos>0){
        pos=(10*pos)+4;
        radio.write(&pos, sizeof(pos));
        Serial.println(pos);}
      break;
      case 5:
        flexADC = analogRead(F5);
        Serial.println("5 Selected");
        if(flexADC>1020)
        {pos=110;}
        else
        {pos=1;}
        if(pos>0){
        pos=(10*pos)+5;
        radio.write(&pos, sizeof(pos));
        Serial.println(pos);}
      break;
    }
    
  }
