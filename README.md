# FOR ONLY ME AND MY FRIEND  
---
.  
.  
.  
.  
.  
---
# 使い方の簡単な説明(receive_data.ino, receive_data.hh)
## とても簡単に言うと:
たぶん **`(receive_dataのインスタンス).UART_Rx_Read()` と `(receive_dataのインスタンス).PickOutDataBytes(uint8_t* , size_t)` でどうにかなる**  
UART-RX.inoを見たらたぶんできる  


## もうちょっと詳しく言うと: 
### receive_dataクラス:
- メンバ変数: 受信した電文全体が格納される
  - 外部からアクセスできない(メンバ関数はアクセスできる)
- メンバ関数: 
  - 電文を受信したり受信した電文のデータ部のみを取り出したりする
  - UART_Rx_Read()  PickOutDataBytes() 以外の関数はこれらの関数内部で使われていたりいなかったりする
  - 以下関数の簡単な説明
    - 補足: STARTBYTE, ENDBYTE は receive_data.hh の#defineでそれぞれ0xFF, 0xFEになってる
    - 補足: DATA_BYTES_SIZE は receive_data.ino の#defineで8になってる
    - 補足: `(receive_dataのインスタンス).関数名()` って書くと呼び出せる

関数名                      | 説明
----------------------------|-------------
receive_data()              |コンストラクタ(インスタンスの初期化をするやつ)
bool isStartByteCorrect()   |最初のバイトが STARTBYTE と同じならtrue, そうでないならfalse を返す。
bool isEndByteCorrect()     |最後のバイトが  ENDBYTE  と同じならtrue, そうでないならfalse を返す。
bool isCorrectBytes()       |最初と最後のバイトがそれぞれ STARTBYTE と ENDBYTE に等しいならtrue, そうでないならfalse を返す。
void receiveFirstByte()     |最初の1バイトを受信してメンバ変数に格納する。
bool receiveOthersBytes()   |残りの9バイトを受信してメンバ変数に格納する。
bool UART_Rx_Read()         |10バイト受信して格納して最初と最後のバイトをチェックしてその結果を返す。
void PickOutDataBytes(uint8_t* array, size_t array_size) |格納した電文のデータ部を取り出して arrayに入れる。array_sizeがDATA_BYTES_SIZEと等しくない場合は考えてない。
