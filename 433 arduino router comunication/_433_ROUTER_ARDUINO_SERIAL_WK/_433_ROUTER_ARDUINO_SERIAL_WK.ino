#include <RCSwitch.h>
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
     else if(dato == 'DWL'){
            digitalWrite(relay1, HIGH);//PARA DESCONECTAR LOS PUERTOS SERIALES DEL ARDUINO Y EL ROUTER
  }
}
}
}

