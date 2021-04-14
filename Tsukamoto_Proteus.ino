#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

float kecil,besar,dingin,panas,low,high;  //membership degrees
float alfa_predikat1,alfa_predikat2,alfa_predikat3,alfa_predikat4;
float out_rule1,out_rule2,out_rule3,out_rule4; //nilai z
float set_temperature;
int output_value;
float aktual;

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

pinMode(A0,INPUT);
pinMode(A1,INPUT);

digitalWrite(2,HIGH);
digitalWrite(4,HIGH);

lcd.begin(16,2);
lcd.display();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
set_temperature=analogRead(A1);
set_temperature=map(set_temperature,0,1024,0,100);

aktual=analogRead(A0);
aktual=map(aktual,0,1024,0,100);

//Fuzzy Tsukamoto Loop

Kecil();
Besar();
Dingin();
Panas();
alfa_predikat1=min(kecil,dingin);
alfa_predikat2=min(besar,dingin);
alfa_predikat3=min(kecil,panas);
alfa_predikat4=min(besar,panas);

Low();
High();
output_value = ((alfa_predikat1*out_rule1) + (alfa_predikat2*out_rule2) + (alfa_predikat3*out_rule3) + (alfa_predikat4*out_rule4) )/(alfa_predikat1 + alfa_predikat2 + alfa_predikat3 + alfa_predikat4);


if(output_value<0)
{output_value=0;}
if(output_value>255)
{output_value=255;}


//Display message on LCD 
lcd.setCursor(0,0);
lcd.print("Temp.    Set_T");

lcd.setCursor(0,1);
lcd.print(aktual);
lcd.setCursor(10,1);
lcd.print(set_temperature);

analogWrite(3,output_value);
}
