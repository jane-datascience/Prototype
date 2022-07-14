#include <SoftwareSerial.h>

SoftwareSerial bluetooth(19, 18);  

#define RED_LED  2
#define BUTTON   7

bool pre_state = false;

void setup(){
  pinMode(RED_LED , OUTPUT);
  pinMode(BUTTON, INPUT);
  bluetooth.begin(9600);
}

void loop(){
  bool cur_state =!digitalRead(BUTTON);
  if(pre_state !=cur_state){
    if(cur_state == HIGH){
      digitalWrite(RED_LED,HIGH);
      bluetooth.write('a');
    }
    else{
      digitalWrite(RED_LED, LOW);
      bluetooth.write('b');
    }
    pre_state = cur_state;
  }
  delay(100);
}
