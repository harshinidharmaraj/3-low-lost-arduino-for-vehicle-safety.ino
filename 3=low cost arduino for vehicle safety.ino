#include <LiquidCrystal.h> 
LiquidCrystal lcd(8,9,10,11,12,13); // RS,E,D4,D5,D6,D7 
#define REPORTING_PERIOD_MS 1000 
const int trigPin = 2; const 
int echoPin = 3; 
int moto=5; 
int temp,send=0,sound; int 
speed=0; 
long 
duration; 
int distance1=0; 
int distance2=0; 
int distance=0; 
void setup() 
{ 
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output pinMode(echoPin, 
INPUT); // Sets the echoPin as an Input 
pinMode(moto,OUTPUT); 
analogWrite(moto,0); 
//Serial.begin(9600); // Starts the serial communication 
lcd.begin(16, 2); lcd.setCursor(0, 0); 
lcd.print(" COMMUNICATION "); 
lcd.setCursor(0, 1); 
lcd.print(" 
"); 
delay(1000);delay(1000); 
lcd.clear(); 
32 
} 
void loop() 
{ distance1 = ultrasonicRead(); 
speed=analogRead(A0)/4; 
speed=map(speed,0,255,0,100) 
; analogWrite(moto,speed); 
lcd.setCursor(0,0); 
lcd.print("Distance:"); 
lcd.print(distance1); 
lcd.print(" 
"); 
lcd.setCursor(0,1); 
lcd.print("Speed:"); 
lcd.print(speed); 
lcd.print(" 
"); 
} 
float ultrasonicRead () 
{ 
digitalWrite(trigPin,    
delayMicroseconds(2); 
digitalWrite(trigPin,  
delayMicroseconds(10); 
digitalWrite(trigPin,   
LOW); 
HIGH); 
LOW); 
duration = pulseIn(echoPin, HIGH); 
distance= duration*0.034/2; 
Serial.print("Distance in cm : "); 
Serial.println(distance); 
return 
distance; 
} 
