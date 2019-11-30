#include "Variable.h"
#include "SerialProtocol.h"

/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */
 
SerialProtocol p;

void Variable::int8tSend(int8_t variable, byte variableType ){//Min: −128   Max: 127
      byte dataType = 1;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint8tSend(uint8_t variable, byte variableType ){//Min: 0   Max: 255
      byte dataType = 2;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::int16tSend(int16_t variable, byte variableType ){//Min: -32,768   Max: 32,767
      byte dataType = 3;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint16tSend(uint16_t variable, byte variableType ){//Min: 0   Max: 65,535
      byte dataType = 4;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::int32tSend(int32_t variable, byte variableType ){//Min: −2,147,483,648 Max: 2,147,483,647
      byte dataType = 5;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint32tSend(uint32_t variable, byte variableType ){//Min: 0 Max: 4,294,967,295
      byte dataType = 6;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::int64tSend(int64_t variable, byte variableType ){//Min: −9,223,372,036,854,775,808 Max: 9,223,372,036,854,775,807
      byte dataType = 7;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint64tSend(uint64_t variable, byte variableType ){//Min: 0 Max: 18,446,744,073,709,551,615
      byte dataType = 8;
      byte dataLenght = sizeof(variable);
      byte bytes[dataLenght];
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
