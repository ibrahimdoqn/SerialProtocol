#ifndef SERIALPROTOCOL_H
#define SERIALPROTOCOL_H
#include <stdint.h>

#include <Arduino.h>

/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */

class SerialProtocol {
public:
	static const byte BUF_MAX_LENGTH = 64;
	static const byte CMD_BEGIN_IND = 94; //^
	static const byte CMD_END_IND = 10;
	
	byte cmdBufferIdx;
	byte buf[BUF_MAX_LENGTH];
	boolean cmdBegan;
	boolean bufferFull;

	byte bufMaxLength;
	byte cmdBeginInd;
	byte cmdEndInd;

	void (*CmdReceivedPtr)(byte* buf, byte cmdLength);

	SerialProtocol();
	SerialProtocol(byte cmdBeginIndicator, byte cmdEndIndicator);
	
	void receive(byte *serialBuffer);
	void send(byte* cmd, byte cmdLength, byte* protocolData);
  void GetCRC(byte *message, char* CRC, int messageLength );

  
};
#endif
