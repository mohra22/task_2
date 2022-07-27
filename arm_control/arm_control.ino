#include <Servo.h>

Servo myservo;//BASE ROTATION
Servo myservo2;//ARM_1 UP/DOWN
Servo myservo3;//ARM_2 FOWARD/BACK
Servo myservo4;//CLAW ROTATION
Servo myservo5;//CLAW
int pos = 90;
String voice; 

void allon(){
    
}
void alloff(){     
}

void setup() {
   Serial.begin(9600);
  myservo.attach(11);
  myservo2.attach(10);
  myservo3.attach(9);
  myservo4.attach(6);
  myservo5.attach(5);
  
}

void loop() {

 while (Serial.available()){  
  delay(10);  
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} 
  voice += c; 
  }  
  
  if (voice.length() > 0) {
    Serial.println(voice); 
    
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)

         else if(voice == "*left") {myservo.write(pos -= 10);}
  else if(voice == "*left left") {myservo.write(pos -= 30);}               
 
  
  else if(voice == "*right right") {myservo.write(pos += 30);}    
  else if(voice == "*right") {myservo.write(pos += 10);}
  
  else if(voice == "*up") {myservo2.write(pos -= 10);}
  else if(voice == "*up up") {myservo2.write(pos -= 30);}
  
  else if(voice == "*Down") {myservo2.write(pos += 10);}
  else if(voice == "*down Down") {myservo2.write(pos += 30);}

  else if(voice == "*rotate right") {myservo4.write(pos -= 10);}
  else if(voice == "*rotate right right") {myservo4.write(pos -= 30);}
  
  else if(voice == "*rotate left") {myservo4.write(pos += 10);}
  else if(voice == "*rotate left left") {myservo4.write(pos += 30);}
 
  else if(voice == "*squeeze") {myservo5.write(pos -= 10);}
  else if(voice == "*squeeze squeeze") {myservo5.write(pos -= 30);}
  
  else if(voice == "*release") {myservo5.write(pos += 10);}//CLAW
  else if(voice == "*release release") {myservo5.write(pos += 30);}
  
voice="";}}
