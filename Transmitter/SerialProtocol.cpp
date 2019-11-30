#include "SerialProtocol.h"
#include <stdint.h>

/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */

SerialProtocol::SerialProtocol()
{
	cmdBufferIdx = 0;
	cmdBegan = false;
	bufferFull = false;
	
	cmdBeginInd = CMD_BEGIN_IND;
	cmdEndInd = CMD_END_IND;
}

SerialProtocol::SerialProtocol(byte cmdBeginIndicator, byte cmdEndIndicator)
{
	cmdBufferIdx = 0;
	cmdBegan = false;
	bufferFull = false;
	
	cmdBeginInd = cmdBeginIndicator;
	cmdEndInd = cmdEndIndicator;
}

void SerialProtocol::receive(byte *serialBuffer)
{
        
   	if (serialBuffer == cmdBeginInd) 
        {
                cmdBegan = true;
                bufferFull = false;
                cmdBufferIdx = 0;                
	}
	else if (serialBuffer == cmdEndInd)
	{
                cmdBegan = false;
                if (cmdBufferIdx > 0 && cmdBufferIdx < BUF_MAX_LENGTH) {
                  byte CRC16[2];
                  CRC16[0] = char(buf[cmdBufferIdx - 2]);
                  CRC16[1] = char(buf[cmdBufferIdx - 1]);

                  byte CRC16c[2];
                  CRC16c[0];
                  CRC16c[1];
    
                  byte list[cmdBufferIdx - 2];
                  for(int i = 0; i < cmdBufferIdx - 2; i++)list[i] = buf[i];
                  GetCRC(list, CRC16c, cmdBufferIdx - 2);
                  if(CRC16[0] == CRC16c[0] && CRC16[1] == CRC16c[1]){
                    CmdReceivedPtr(list, cmdBufferIdx);
                  }

    }           
	} 
	else
	{
                if (cmdBegan) {
                    if (cmdBufferIdx >= BUF_MAX_LENGTH) {
                        bufferFull = true;
                    } else {
                        buf[cmdBufferIdx] = serialBuffer;
                        cmdBufferIdx++;
                    }
                }
        }
    
}

void SerialProtocol::send(byte* cmd, byte cmdLength, byte* protocolData)
{
  byte CRC16[2];
  protocolData[0] = cmdBeginInd;
	for (byte i = 0; i < cmdLength; i++) protocolData[i+1] = cmd[i];
  GetCRC(cmd, CRC16, cmdLength);
  protocolData[cmdLength + 1] = CRC16[0];
  protocolData[cmdLength + 2] = CRC16[1];
  protocolData[cmdLength + 3] = cmdEndInd;
}


void SerialProtocol::GetCRC(byte *message, char* CRC, int messageLength )
{
  unsigned int CRCFull = 0xFFFF;
  int i,j;
  byte CRCHigh = 0xFF, CRCLow = 0xFF;
  char CRCLSB;

  for (i = 0; i < (messageLength) - 2; i++)
  {
    CRCFull = (unsigned int)(CRCFull ^ message[i]);

    for (j = 0; j < 8; j++)
    {
      CRCLSB = (char)(CRCFull & 0x0001);
      CRCFull = (unsigned int)((CRCFull >> 1) & 0x7FFF);

      if (CRCLSB == 1)
        CRCFull = (unsigned int)(CRCFull ^ 0xA001);
    }
  }
  CRC[1] = CRCHigh = (byte)((CRCFull >> 8) & 0xFF);
  CRC[0] = CRCLow = (byte)(CRCFull & 0xFF);
}
