#include <stdint.h>
#include "receive_data.hh"

#define STARTBYTE 0xFF
#define ENDBYTE   0xFE


  receive_data::receive_data() { //コンストラクタ
    //何もしない
  };

  //受信したデータの始めと終わりのバイトが正しいかを見る
  //true: 正しい, false: 正しくない
  bool receive_data::isCorrectBytes() {
    return (this->frame.initialByte == STARTBYTE) && (this->frame.finalByte == ENDBYTE);
  }

  //Serial1から受信してreceive_dataクラスに突っ込む
  //10バイト受信出来たらtrue, そうでないならfalseを返す
  bool receive_data::receiveByUART() {
    if (RECEIVE_BYTES == Serial1.readBytes(this->array, 10)) {
      return true;
    } else {
      return false;
    }
  };

  //変数名に&をつけると参照になる。
  //受信したデータのバイト数がRECEIVE_BYTESと同じかつ、
  //受信したデータの頭とケツのバイトがそれぞれSTARTBYTEとENDBYTEに一致するなら、
  //trueを返す。
  //isCorrectBytes()より先にreceiveByUART()が評価される(遅延評価)(たぶん言語仕様)
  bool receive_data::UART_Rx_Read() {
    return (this->receiveByUART()) && (this->isCorrectBytes());
  };


//変数名に&をつけると参照になる。
//受信したデータのバイト数がRECEIVE_BYTESと同じかつ、
//受信したデータの頭とケツのバイトがそれぞれSTARTBYTEとENDBYTEに一致するなら、
//trueを返す。
//isCorrectBytes()より先にreceiveByUART()が評価される(遅延評価)(たぶん言語仕様)
// bool UART_Rx_Read(receive_data &RxData) {
//   return (RxData.receiveByUART()) && (RxData.isCorrectBytes());
// }