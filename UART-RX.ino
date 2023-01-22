#include "receive_data.hh"

receive_data RxData;

void setup(){
    pinMode(LED_BUILTIN , OUTPUT);
    Serial1.begin(9600);
    digitalWrite(LED_BUILTIN , LOW);
};

void loop() {
  while(Serial1.available() == 10);//受信バッファに10バイト溜まるまで待つ
  bool result = RxData.UART_Rx_Read();
  if (result == true) {
    
  }


  /*
  while (Serial1.available() >= 0) {
    char receivedData = Serial1.read();   // read one byte from serial buffer and save to receivedData
    if(receivedData == '1'){
        digitalWrite(LED_BUILTIN , HIGH);
    }
    else if(receivedData == '0'){
        digitalWrite(LED_BUILTIN , LOW);
    }
  }
  */
}