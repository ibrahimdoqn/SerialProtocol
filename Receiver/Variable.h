#ifndef VARIABLE_H
#define VARIABLE_H

#include <Arduino.h>
#include <stdint.h>
#include "SerialProtocol.h"


/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */

class Variable {
public:

void (*CmdTransmitter)(byte* buf, byte cmdLength);

void int8tSend(int8_t variable, byte variableType );
void uint8tSend(uint8_t variable, byte variableType );
void int16tSend(int16_t variable, byte variableType );
void uint16tSend(uint16_t variable, byte variableType );
void int32tSend(int32_t variable, byte variableType );
void uint32tSend(uint32_t variable, byte variableType );
void int64tSend(int64_t variable, byte variableType );
void uint64tSend(uint64_t variable, byte variableType );

};
#endif
