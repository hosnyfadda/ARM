//#define L1 22.0
//#define L2 39.0
#define distance X 

#include<Servo.h>
Servo Servo1;
Servo Servo2;
// defines pins numbers
#define trigPin 5
#define echoPin 6
#define waterPin A0
#define IN1 2
#define IN2 4
#define ENA 3
// defines variables
long duration;
float distance ,Y,R,Theta1,Theta2,pos;
int i =0;
float L1=30.4;
float L2=20.3;
float L3=10.0;
float H=9.1;
float r=3.5;

float P1=0.0;
float P2=0.0;

float P=18.0;

float h=4.0+2.5;

float d=0.0;//nan




void setup() {
  // put your setup code here, to run once:

  delay(2000);
  
 
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(waterPin,INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  
  Serial.begin(9600); // Starts the serial communication
  Servo1.attach(9);
    Servo2.attach(10);


 for (pos =0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
    

    delay (500);



    for (pos =95 ; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
     
}

void loop() {
  // put your main code here, to run repeatedly:
// Clears the trigPin
 

delay(2000);
 

 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
if (distance>=13 && distance <=29){ 
  d=distance;}
  else {
   goto A;
  }
  
  Theta1=atan((L3-H+h)/(d+P+r))+acos((pow(d+P+r,2.0)+pow(L3-H+h,2.0)+pow(L1,2.0)-pow(L2,2.0))/(2*L1*sqrt(pow(d+P+r,2.0)+pow(L3-H+h,2.0))));
  Theta2=acos((pow(d+P+r,2.0)+pow(L3-H+h,2.0)-pow(L1,2.0)-pow(L2,2.0))/(2*L1*L2));
 
  Theta1=Theta1*180.0/PI;
  Theta2=Theta2*180.0/PI;

   Serial.print("Theta1: ");
  Serial.println(Theta1);

    Serial.print("Theta2: ");
  Serial.println(Theta2);

  

  
    float Theta1_R = Theta1+9;
    float Theta1_L =180- Theta1+9;

    
    float Theta2_R = 90+Theta2-9;
    float Theta2_L = 90-Theta2-9;

    


//if( digitalRead(2)==HIGH){
  
   // Fot Right Servo1  #####################################

 if (Theta1_R<=90){
     for (pos =90 ; pos >= Theta1_R; pos -= 1) { 
    Servo1.write(pos);            
    delay(50);                       
  }
    if (Theta2_R>=90){
 for (pos =90; pos <= Theta2_R; pos += 1) { 
    Servo2.write(pos);             
    delay(30);  }


delay(3000);


     for (pos =Theta1_R ; pos <= 90; pos += 1) { 
    Servo1.write(pos);            
    delay(50);                       
  }

   for (pos =Theta2_R; pos >= 90; pos -= 1) { 
    Servo2.write(pos);             
    delay(30);  }
    
}
else if (Theta2_R<90){
 for (pos =90; pos >= Theta2_R; pos -= 1) { 
    Servo2.write(pos);             
    delay(30);  }

    delay(3000);


     for (pos =Theta1_R ; pos <= 90; pos += 1) { 
    Servo1.write(pos);            
    delay(50);                       
  }

   for (pos =Theta2_R; pos <= 90; pos += 1) { 
    Servo2.write(pos);             
    delay(30);  }



    
}
  }

//  }
A:
d=0.0;
}
