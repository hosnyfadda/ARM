#include<Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo gripper;

#define trig 11
#define echo 12

int pos0 ,pos1, pos2 , pos3 ,pos4 ,pos ;
const float L1=12;
const float L2=12.3;
const float base_rad=4.5;
const float y=6.5;
float distance,x,m,n,r;
float beta,phi,alpha,omega;
float theta1,theta2,theta3,theta4,theta5;
long duration;



void setup() {
  Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);

  base.attach(5);
  shoulder.attach(6);
  elbow.attach(7);
  wrist.attach(9);
  gripper.attach(10);
  
}

void intial_position() {
  pos0 = 0; 
  pos1 = 90;
  pos2 = 90;
  pos3 = 90;
  base.write(pos0);
  delay(15);
  shoulder.write(pos1);
  delay(15);
  elbow.write(pos2); 
  delay(15);
  wrist.write(pos3);
  delay(15);
}

void final_position() {
  pos0 = 90; 
  pos1 = 90;
  pos2 = 90;
  pos3 = 90;
  base.write(pos0);
  delay(15);
  shoulder.write(pos1);
  delay(15);
  elbow.write(pos2); 
  delay(15);
  wrist.write(pos3);
  delay(15);
}


void loop() {

  intial_position();
  
  delay(200);

  
  //open the gripper
  
  /*theta5=90;
  gripper.write(theta5);*/
  
  //find distance between the base and the cube
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration= pulseIn(echo, HIGH);
  distance=(duration/2) * 0.0343;;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);


  //the kinematics and the calculation of angles
  
  x=distance+base_rad;
  m=sqrt(pow(x,2.0)+pow(y,2.0));
  r=(-pow(L2,2.0)+pow(L1,2.0)+pow(m,2.0))/(2*m);
  n=sqrt(pow(L1,2.0)-pow(r,2.0));

  phi=(atan(y/x))*180.0/PI;
  omega=(atan(x/y))*180.0/PI;
  beta=(atan(n/r))*180.0/PI;
  alpha=(atan(n/(m-r)))*180.0/PI;

  theta2=(phi+beta);
  theta3=-(alpha+beta);
  theta4=180-(alpha+omega);
  Serial.print("theta2: ");
  Serial.println(theta2);
  delay(500);

  Serial.print("theta3: ");
  Serial.println(theta3);
  delay(500);

  Serial.print("theta4: ");
  Serial.println(theta4);
  delay(500);

  theta2=180-(phi+beta);
  theta3=90-(alpha+beta);
  theta4=90+(180-(alpha+omega));

 //the movement of the motors to the cube

    for( pos = 90; pos <= theta2; pos += 1)
  {
    shoulder.write(pos);
    delay (15);
  }
 for( pos = 90; pos >= theta3; pos -= 1)
 {  
    elbow.write(pos);
    delay (15);
 }
 for( pos = 90; pos <= theta4; pos += 1)
 { 
    wrist.write(pos);
    delay (15);
 }

  //gripper hold the cube
  
    /*theta5=0; 
    gripper.write(theta5);
    delay (15);*/

  final_position();

  delay(200);

 
  x=15; // distance between the base and the cup

  //repeat the kinematics for the new distance to the cup
  


  //the movement of the motors to the cup
  for( pos = 90; pos <= 108; pos += 1)  {
    shoulder.write(pos);
    delay (15);
  }
 for( pos = 90; pos >=-5; pos -= 1){  
    elbow.write(pos);
    delay (15);
 }
 for( pos = 90; pos <= 157; pos += 1) { 
    wrist.write(pos);
    delay (15);
 }
  //gripper put the cube in the cup
  /*theta5=90;
    gripper.write(theta5);
    delay (15);*/

  intial_position();
}
