#include <stdint.h>
#include "receive_data.hh"


#define STARTBYTE 0xFF
#define ENDBYTE   0xFE


  receive_data::receive_data() { //コンストラクタ
    //ヘッダのほうで初期化を書いてるから
    //何もしない
  };

  bool receive_data::isStartByteCorrect() {
    return this->frame.initialByte == STARTBYTE;
  }
  bool receive_data::isEndByteCorrect() {
    return this->frame.finalByte == ENDBYTE;
  }
  //受信したデータの始めと終わりのバイトが正しいかを見る
  //true: 正しい, false: 正しくない
  bool receive_data::isCorrectBytes() {
    return isStartByteCorrect() && isEndByteCorrect();
  }

  void receive_data::receiveFirstByte() {
    this->frame.initialByte = Serial1.read();
  }
  bool receive_data::receiveOthersBytes() {
    if (DATA_BYTES_SIZE+1 == Serial1.readBytes(this->array+1, DATA_BYTES_SIZE+1)) {
      return true;
    } else {
      return false;
    }
  }

/*
  //Serial1から受信してreceive_dataクラスに突っ込む
  //10バイト受信出来たらtrue, そうでないならfalseを返す
  bool receive_data::receiveByUART() {
    if (RECEIVE_BYTES_SIZE+RECEIVE_BYTES_SIZE_OFFSET == Serial1.readBytes(this->array, RECEIVE_BYTES_SIZE)) {
      return true;
    } else {
      return false;
    }
  };
*/

  //受信したデータのバイト数がRECEIVE_BYTES_SIZEと同じかつ、
  //受信したデータの頭とケツのバイトがそれぞれSTARTBYTEとENDBYTEに一致するなら、
  //trueを返す。
  bool receive_data::UART_Rx_Read() {
    while (Serial1.available() == 1);
    
    this->receiveFirstByte();
    if (!this->isStartByteCorrect()) {
      return false;
    } else {
      while (Serial1.available() == DATA_BYTES_SIZE+1);
      if (this->receiveOthersBytes() && this->isEndByteCorrect()) {
        return true;
      } else {
        return false;
      }
    }
    

  };

  void receive_data::GetDataBytes(uint8_t* array, size_t array_size) {
    for(int i = 0; i < array_size; i++) {
      if (i > DATA_BYTES_SIZE) {
        return;
      } else {
        array[i] = this->frame.dataBytes[i];
        return;
      }
    }
  }