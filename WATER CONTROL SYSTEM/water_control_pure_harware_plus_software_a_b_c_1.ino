// C++ code
//
#include<LiquidCrystal.h>
LiquidCrystal led(3,4,5,6,7,8);
void setup()
{
  pinMode(2,OUTPUT);
 led.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
 if(Serial.available()>0)
 {
 int A =Serial.parseInt();
 led.setCursor(0,0);
 led.print("A=");
 led.setCursor(2,0);
 led.print(A);
   
 int B =Serial.parseInt();
 led.setCursor(4,0);
 led.print("B=");
 led.setCursor(6,0);
 led.print(B);
   
 int C =Serial.parseInt();
 led.setCursor(8,0);
 led.print("C=");
 led.setCursor(10,0);
 led.print(C);
   
 digitalWrite(2,!(!(!A&B)&!C));
 int F=!(!(!A&B)&!C);
   if(F==1)
   {
   led.setCursor(1,0);
   led.print("Water Pumping");
   }
   else
   {
   led.setCursor(0,1);
   led.print("Pumping Water");
   }
 }
}