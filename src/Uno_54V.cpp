#include <Arduino.h>

int read_value;
int repetition = 1;
float u;
float u_in = 4.982;
float r_faktor = 11;
String incomingString;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0){
    incomingString = Serial.readString();

    if (incomingString.equals("m")){
      read_value = 0;
      for(int j = 0; j < repetition; j++){
        read_value+=analogRead(A0);}

      read_value=read_value/repetition;
      Serial.print("A0: ");
      Serial.print(read_value);
      u=(u_in/1023.000)*read_value;
      u=u*r_faktor;
      Serial.print(" - U: ");
      Serial.println(u);
}}}