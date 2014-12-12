#include <RCSwitch.h>//Version 12-12-14
RCSwitch mySwitch = RCSwitch();
byte inByte = 0;
int incomingByte;
int estado;
int led = 13;
int relay1 = 12; //relay desconecta el arduino de la señal serial del router para hacer modificaciones al firmware


void setup(){
  Serial.begin(115200);
   mySwitch.enableTransmit(3);
   mySwitch.setProtocol(1);
   mySwitch.setPulseLength(190);
   mySwitch.setRepeatTransmit(6);
pinMode(led,OUTPUT);
pinMode(relay1,OUTPUT);



}

void loop(){
if(Serial.available()>0){
char dato=Serial.read();
switch(dato);

{
    if(dato == '1'){
    mySwitch.send(1135923, 24);
      digitalWrite(led, HIGH);
      Serial.println((char)dato);
       Serial.println("1 ON");
    }
 
    else if(dato == '2'){
       mySwitch.send(1135932, 24);
      digitalWrite(led, LOW);
      Serial.println((char)dato);
       Serial.println("1 OFF");
    }  
	   
    else if(dato == '3'){
	mySwitch.send(1136067, 24);
            digitalWrite(led, HIGH);
      Serial.println((char)dato);
       Serial.println("2 On");
    }
    
else if(dato == '4'){
mySwitch.send(1136076, 24);
digitalWrite(led, LOW);
Serial.println((char)dato);
Serial.println("2 OFF");
   }
   
 else if(dato == '5') { // byte is '5'
 mySwitch.send(1136387, 24);
  digitalWrite(led, HIGH);
  Serial.println((char)dato);
 Serial.println("3 ON");
 }
 else if(dato == '6') { // byte is '6'
 mySwitch.send(1136396, 24);
  digitalWrite(led, LOW);
  Serial.println((char)dato);
 Serial.println("3 OFF");
 }
  else if(dato == 'DWL'){
            digitalWrite(relay1, HIGH);//PARA DESCONECTAR LOS PUERTOS SERIALES DEL ARDUINO Y EL ROUTER
            Serial.println((char)dato);
Serial.println("data download");
}
 // aqui se tiene que seactivar todas enviando los comandos al puerto por ejemplo enviando 2,4,6,8,0 que serian los que aparian las cadena
 else if(dato == '9') { // byte is '9'
 mySwitch.send(1135923, 24);
 mySwitch.send(1136067, 24);
 mySwitch.send(1136387, 24);
 Serial.println((char)dato);
  Serial.println("All ON");
 }
  else if(dato == '0') { // byte is '9'
 mySwitch.send(1135932, 24);
 mySwitch.send(1136076, 24);
 mySwitch.send(1136396, 24);
 Serial.println((char)dato);
 Serial.println("All Off");

}
}
}
}

