
#include <SoftwareSerial.h>
/* Para que a comunicaçao com o modulo nao interfira na programacao da placa,
criamos uma nova porta serial para ele.
*/

SoftwareSerial minhaSoftSerial(11, 10); // pinos RX/TX para o modulo

void setup() 
{
Serial.begin(9600); //porta serial (hardware) para monitorar os caracteres enviados
Serial.println("labdegaragem.com"); // mensagem de inicializacao

minhaSoftSerial.begin(9600); // inicializacao da porta serial para o modulo

pinMode(5, OUTPUT); // declara pino 5 como saida para o Rele 1
pinMode(6, OUTPUT); // declara pino 6 como saida para o Rele 2
}

void loop()
{
  digitalWrite(5, HIGH); 
  digitalWrite(6, HIGH); 
  if (minhaSoftSerial.available()){ // Se a serial estiver disponivel, tem caracter para ler
    char caracter = minhaSoftSerial.read(); // salva o caracter lido na variavel 'a'
    Serial.write(caracter); // escreve o caracter recebido via bluetooth na serial do PC para conferencia
    if (caracter=='A'){
      digitalWrite(5, LOW); 
      delay(3000);
      digitalWrite(5, HIGH);
      }
    if (caracter=='B'){
      digitalWrite(6, LOW); 
      delay(500);
      digitalWrite(6, HIGH);
      }
  }
}
