// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 7, 4, 3, 2, 1); 

const int trigPin = 10;
const int echoPin = 9;
long duration;
float distance;

int contrast=100; /*It is the contrast of display, 
                    always keep it 100 for best
                    contrast ratio*/
                    
/*out of all pwm pins only pin 5&6 gives 980 Hz frequency hence
   used pin 5 for contrast and pin 6 for backlight brightness*/
   
int backlight=10; /*It is the brightness of backlight 
                    of display,always keep it in 
                    range of 0 to 60, 
                    if increased more than 60,
                    then display will burn out.*/


void setup() 
{
  pinMode(6,OUTPUT);
  analogWrite(6, backlight); // analogWrite(pin,value)
  
  pinMode(5,OUTPUT);
  analogWrite(5, contrast); // analogWrite(pin,value)*/

  lcd.begin(16,2); // Initializes the interface to the LCD screen
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.clear();
  lcd.setCursor(4,0);
  delay(500);
  lcd.print("WELCOME");
  delay(2000);
  lcd.clear();
  delay(500);
}

void loop() 
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  distance= duration*0.03433/2;
  
  // Set cursor to 0th column and 0th row
  lcd.setCursor(0,0);  //lcd.setCursor(column,row)
   
  if(distance>=2 && distance<=9){
    lcd.print("Dist: "); 
  lcd.print(distance);
    lcd.print(" cm  ");
  }
  else if(distance>=10 && distance<=99){
    lcd.print("Dist: "); 
  lcd.print(distance);
    lcd.print(" cm ");
  }
  else if(distance>=100 && distance<=400){
    lcd.print("Dist: "); 
  lcd.print(distance);
    lcd.print(" cm");
  }
  else{
    lcd.print("Out of range");  
  }
  delay(1000);  
  lcd.clear();
}
