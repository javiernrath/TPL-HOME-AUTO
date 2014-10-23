#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
byte inByte = 0;
int incomingByte;
int estado;

void setup() {
   Serial.begin(115200); se cambio para la prueba desde el serial del router
   mySwitch.enableTransmit(3);
   mySwitch.setProtocol(1);
   mySwitch.setPulseLength(190);
   mySwitch.setRepeatTransmit(6);
}
void loop(){
  /* Switch using decimal code */
 if(Serial.available() > 0) { // A byte is ready to receive and read the oldest byte in the serial buffer:
 inByte = Serial.read();
 if(inByte == '1') { // byte is '1'
 mySwitch.send(1135923, 24);
 Serial.println("1 ON");
 }
 else if(inByte == '2') { // byte is '2'
 mySwitch.send(1135932, 24);
 Serial.println("1 OFF");
 }
 else if(inByte == '3') { // byte is '3'
 mySwitch.send(1136067, 24);
 Serial.println("2 ON");
 }
 else if(inByte == '4') { // byte is '4'
 mySwitch.send(1136076, 24);
 Serial.println("2 OFF");
 }
 else if(inByte == '5') { // byte is '5'
 mySwitch.send(1136387, 24);
 Serial.println("3 ON");
 }
 else if(inByte == '6') { // byte is '6'
 mySwitch.send(1136396, 24);
 Serial.println("3 OFF");
 }
 else if(inByte == '7') { // byte is '7'
 mySwitch.send(1137923, 24);
 Serial.println("4 ON");
 }
 else if(inByte == '8') { // byte is '8'
 mySwitch.send(1137932, 24);
 Serial.println("4 OFF");
 }
 // aqui se tiene que seactivar todas enviando los comandos al puerto por ejemplo enviando 2,4,6,8,0 que serian los que aparian las cadena
 else if(inByte == '9') { // byte is '9'
 mySwitch.send(1135923, 24);
 mySwitch.send(1136067, 24);
 mySwitch.send(1136387, 24);
  Serial.println("All ON");
 }
  else if(inByte == '0') { // byte is '9'
 mySwitch.send(1135932, 24);
 mySwitch.send(1136076, 24);
 mySwitch.send(1136396, 24);
 Serial.println("All Off");
 }
 else { // byte isn't known
 Serial.println("Unknown");
 }
 //esta parte devolvera el estado del puerto serial para verificar que dispositivos estan activos
char c = Serial.read(); //Guardamos la lectura en una variable char
if (c == 'H') { //Si es una 'H', enciendo el LED
Serial.println("'H' pulsada");
} else if (c == 'L') { //Si es una 'L', apago el LED
Serial.println("'L' pressed");
} else {
Serial.println("Caracter no reconocido");
 }
 }
 }
