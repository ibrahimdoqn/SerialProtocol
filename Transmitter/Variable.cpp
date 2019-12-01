#include "Variable.h"
#include "SerialProtocol.h"

/**
 * İbrahim DOĞAN
 * Livatya Roket Takımı
 */
 
SerialProtocol p;

void Variable::uint8Send(uint8_t variable, byte variableType ){//Min: 0   Max: 255
      byte dataType = 8;
      byte dataLenght = 1;
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint16Send(uint16_t variable, byte variableType ){//Min: 0   Max: 65,535
      byte dataType = 16;
      byte dataLenght = 2;
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint32Send(uint32_t variable, byte variableType ){//Min: 0 Max: 4,294,967,295
      byte dataType = 32;
      byte dataLenght = 4;
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}
void Variable::uint64Send(uint64_t variable, byte variableType ){//Min: 0 Max: 18,446,744,073,709,551,615
      byte dataType = 64;
      byte dataLenght = 8;
      byte list[dataLenght + 2] = {dataType,variableType};
      for(byte i = 0; i < dataLenght; i++) list[i+2] = (variable >> ((dataLenght * 8) - ((i * 8)) - 8)) & 0xFF;
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}

void Variable::floatSend(float variable, byte variableType ){
      byte dataType = 128;
      byte dataLenght = 4;
      byte list[dataLenght + 2] = {dataType,variableType};
      fVar dataFloat;
      dataFloat.varFloat = variable;
      for(byte i = 0; i < dataLenght; i++) list[i+2] = dataFloat.veri[i];
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}

void Variable::doubleSend(double variable, byte variableType ){
      byte dataType = 127;
      byte dataLenght = 4;
      byte list[dataLenght + 2] = {dataType,variableType};
      dVar dataDouble;
      dataDouble.varDouble = variable;
      for(byte i = 0; i < dataLenght; i++) list[i+2] = dataDouble.veri[i];
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}

void Variable::longSend(long variable, byte variableType ){
      byte dataType = 126;
      byte dataLenght = 4;
      byte list[dataLenght + 2] = {dataType,variableType};
      lVar dataLong;
      dataLong.varLong = variable;
      for(byte i = 0; i < dataLenght; i++) list[i+2] = dataLong.veri[i];
      byte data [dataLenght + 6];
      p.send(list, dataLenght + 2, data);
      CmdTransmitter(data,dataLenght + 6);
}

void Variable::Receive(byte* cmd, byte cmdLength )
{
  if(((byte)cmd[0] / 8) == cmdLength - 4){
    if((byte)cmd[0] == 8){
      uint8_t myInt1 = cmd[2];
      CmdReceivedPtr8(myInt1,cmd[1]);
    }
    else if((byte)cmd[0] == 16){
      uint16_t myInt1 =(cmd[2] << 8) + cmd[3];
      CmdReceivedPtr16(myInt1,cmd[1]);
    }
    else if((byte)cmd[0] == 32){
      uint32_t myInt1 = (cmd[2] << 24) + (cmd[3] << 16) + (cmd[4] << 8) + cmd[5];
      CmdReceivedPtr32(myInt1,cmd[1]);
    }
    else if((byte)cmd[0] == 64){
      uint64_t myInt1 = (cmd[2] << 56) + (cmd[3] << 48) + (cmd[4] << 40) + (cmd[5] << 32) + (cmd[6] << 24) + (cmd[7] << 16) + (cmd[8] << 8) + cmd[9];
      CmdReceivedPtr64(myInt1,cmd[1]);
    }
  }
  else if((byte)cmd[0] == 128){//Float
    fVar data;
    data.veri[0] = cmd[2];
    data.veri[1] = cmd[3];
    data.veri[2] = cmd[4];
    data.veri[3] = cmd[5];
    float myInt1 = data.varFloat;
    CmdReceivedPtrFloat(myInt1,cmd[1]);
  }
  else if((byte)cmd[0] == 127){//Double
    dVar data;
    data.veri[0] = cmd[2];
    data.veri[1] = cmd[3];
    data.veri[2] = cmd[4];
    data.veri[3] = cmd[5];
    double myInt1 = data.varDouble;
    CmdReceivedPtrDouble(myInt1,cmd[1]);
  }
  else if((byte)cmd[0] == 126){//Long
    lVar data;
    data.veri[0] = cmd[2];
    data.veri[1] = cmd[3];
    data.veri[2] = cmd[4];
    data.veri[3] = cmd[5];
    long myInt1 = data.varLong;
    CmdReceivedPtrLong(myInt1,cmd[1]);
  }
}
