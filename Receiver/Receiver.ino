#include "SerialProtocol.h"
#include <SoftwareSerial.h>


SoftwareSerial yeniSeriPort(10, 11);

SerialProtocol protocol;

void setup()
{
    Serial.begin(9600);
    protocol.CmdReceivedPtr = CmdReceived;
    yeniSeriPort.begin(9600);
}

void loop()
{
  while (Serial.available()) {
        protocol.receive(Serial.read());
        }
}


void CmdReceived(byte* cmd, byte cmdLength)
{
      byte dataTypeInt32 = 5;//Int32_t veri yapısını encode eder.
      if((byte)cmd[0] == dataTypeInt32){
        int32_t myInt1 = (cmd[2] << 24) + (cmd[3] << 16) + (cmd[4] << 8) + cmd[5];
            if(char(cmd[1]) == 'a'){
              yeniSeriPort.print("Birinci Veri....:");
              yeniSeriPort.print(myInt1);
              yeniSeriPort.println("");
            }
            else if(char(cmd[1]) == 'b'){
              yeniSeriPort.print("Ikinci Veri....:");
              yeniSeriPort.print(myInt1);
              yeniSeriPort.println("");
            }
            else if(char(cmd[1]) == 'c'){
              yeniSeriPort.print("Ucuncu Veri....:");
              yeniSeriPort.print(myInt1);
              yeniSeriPort.println("");
            }
      }
}
