#include "SerialProtocol.h"
#include <stdint.h>
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




void loop()
{
      for(int32_t i = 0; i < 1998217; i++){
        var.int32tSend(i,'a');
        var.int32tSend(i+1,'b');
        var.int32tSend(1998217-i,'c');
      }

      

      
}
