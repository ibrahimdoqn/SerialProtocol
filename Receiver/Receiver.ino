#include "SerialProtocol.h"
#include <SoftwareSerial.h>
#include "Variable.h"


SoftwareSerial yeniSeriPort(10, 11);

SerialProtocol protocol;
Variable var;

void setup()
{
    Serial.begin(9600);
    protocol.CmdReceivedPtr = CmdReceived;
    var.CmdReceivedPtr8 = CmdReceived8;
    var.CmdReceivedPtr16 = CmdReceived16;
    var.CmdReceivedPtr32 = CmdReceived32;
    var.CmdReceivedPtr64 = CmdReceived64;
    var.CmdReceivedPtrFloat = CmdReceivedFloat;
    var.CmdReceivedPtrDouble = CmdReceivedDouble;
    var.CmdReceivedPtrLong = CmdReceivedLong;
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
  var.Receive(cmd,cmdLength);
}


//Alınan datalar
void CmdReceived8(uint8_t cmd, byte data)
{
  yeniSeriPort.print((char)data);
  yeniSeriPort.print(" Degiskeninden alinan data....:");
  yeniSeriPort.println((char)cmd);
}

void CmdReceived16(uint16_t cmd, byte data)
{
  yeniSeriPort.print((char)data);
  yeniSeriPort.print(" Degiskeninden alinan data....:");
  yeniSeriPort.println((int)cmd);
}

void CmdReceived32(uint32_t cmd, byte data)
{
    yeniSeriPort.print((char)data);
    yeniSeriPort.print(" Degiskeninden alinan data....:");
    yeniSeriPort.println(cmd);
}

void CmdReceived64(uint64_t cmd, byte data)
{
  
}

void CmdReceivedFloat(float cmd, byte data)
{
    yeniSeriPort.print((char)data);
    yeniSeriPort.print(" Degiskeninden alinan data....:");
    yeniSeriPort.println(cmd);
}

void CmdReceivedDouble(double cmd, byte data)
{
    yeniSeriPort.print((char)data);
    yeniSeriPort.print(" Degiskeninden alinan data....:");
    yeniSeriPort.println(cmd);
}

void CmdReceivedLong(long cmd, byte data)
{
    yeniSeriPort.print((char)data);
    yeniSeriPort.print(" Degiskeninden alinan data....:");
    yeniSeriPort.println(cmd);
}
