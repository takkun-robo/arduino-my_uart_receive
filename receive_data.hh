#ifndef RECEIVE_DATA_HH
#define RECEIVE_DATA_HH


#define RECEIVE_BYTES 10 //受信するデータ列のバイト数


class receive_data {
  private:
    union {
      uint8_t array[RECEIVE_BYTES] = {};
      struct{
        uint8_t initialByte;
        uint8_t dataBytes[RECEIVE_BYTES-2];
        uint8_t finalByte;
        }frame;
    };
  public:
    receive_data();
    bool isCorrectBytes();
    bool receiveByUART();
    bool UART_Rx_Read();
};


#endif //RECEIVE_DATA_HH