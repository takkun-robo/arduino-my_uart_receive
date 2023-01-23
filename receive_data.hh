#ifndef RECEIVE_DATA_HH
#define RECEIVE_DATA_HH


#define RECEIVE_BYTES_SIZE 10 //受信するデータ列のバイト数
#define RECEIVE_BYTES_SIZE_OFFSET -1
#define DATA_BYTES_SIZE RECEIVE_BYTES_SIZE - 2


class receive_data {
  private:
    union {
      uint8_t array[RECEIVE_BYTES_SIZE] = {}; // 0で初期化
      struct {
        uint8_t initialByte;
        uint8_t dataBytes[DATA_BYTES_SIZE];
        uint8_t finalByte;
        }frame;
    };
  public:
    receive_data();
    bool isStartByteCorrect();
    bool isEndByteCorrect();
    bool isCorrectBytes();

    void receiveFirstByte();
    bool receiveOthersBytes();
    // bool receiveByUART();
    bool UART_Rx_Read();
    // bool UART_Rx_Read(receive_data&);

    void GetDataBytes(uint8_t*, size_t);
};


#endif //RECEIVE_DATA_HH