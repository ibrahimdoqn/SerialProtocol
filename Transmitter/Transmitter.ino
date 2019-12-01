#include "SerialProtocol.h"
#include "Variable.h"

SerialProtocol protocol;
Variable var;

void setup()
{
    Serial.begin(9600);
    var.CmdTransmitter = Transmitter;
}

void Transmitter(byte* data, byte dataLenght){
  for (byte i = 0; i < dataLenght; i++) Serial.write(data[i]);
}



int sayi2 = -15780;
char a = 'S';
float sayi1 = -1.5780;
double sayi3 = 1.256512;
void loop()
{
  var.uint16Send(sayi2,'A');
  var.uint8Send(a,'B');
  var.floatSend(sayi1,'C');
  var.doubleSend(sayi3,'D');
}
