#ifndef VARIABLE_H
#define VARIABLE_H
#include "SerialProtocol.h"
#include <stdint.h>
#include <stdbool.h>
/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */
typedef uint8_t byte;
typedef bool boolean;

typedef union {
    float varFloat;
    byte veri[4];
  } fVar;

typedef union {
    double varDouble;
    byte veri[4];
  } dVar;
  
typedef union {
    long varLong;
    byte veri[4];
  } lVar;
 

class Variable {
public:

void (*CmdTransmitter)(byte* buf, byte cmdLength);

void uint8Send(uint8_t variable, byte variableType );
void uint16Send(uint16_t variable, byte variableType );
void uint32Send(uint32_t variable, byte variableType );
void uint64Send(uint64_t variable, byte variableType );
void floatSend(float variable, byte variableType );
void doubleSend(double variable, byte variableType );
void longSend(long variable, byte variableType );

void Variable::Receive(byte* cmd, byte cmdLength );

void (*CmdReceivedPtr8)(uint8_t buf, byte variable);
void (*CmdReceivedPtr16)(uint16_t buf, byte variable);
void (*CmdReceivedPtr32)(uint32_t buf, byte variable);
void (*CmdReceivedPtr64)(uint64_t buf, byte variable);
void (*CmdReceivedPtrFloat)(float buf, byte variable);
void (*CmdReceivedPtrDouble)(double buf, byte variable);
void (*CmdReceivedPtrLong)(long buf, byte variable);


};
#endif
