#include "receive_data.hh"

receive_data RxData;

void setup(){
    pinMode(LED_BUILTIN , OUTPUT);
    Serial1.begin(9600);
    Serial.begin(9600);
    digitalWrite(LED_BUILTIN , LOW);
    Serial.println("setup finished");
};

void loop() {
  while(1){
    while(Serial1.available() >= 0){
      uint8_t receiveData = Serial1.read();
      if(receiveData == 0x01){
        digitalWrite(LED_BUILTIN , HIGH);
      }
      else{
        digitalWrite(LED_BUILTIN , LOW);
      }
    }
  }
  while (1)
  {
    if (Serial1.available() > 0) {
      uint8_t RxByte = Serial1.read();
      Serial.print("receive: ");
      Serial.println(RxByte);
    }
  }
//ここまでデバッグ

//ここからメイン
  bool result = RxData.UART_Rx_Read();
  if (result == true) {
    Serial.println("receive success");
    uint8_t dataBytes[DATA_BYTES_SIZE];
    RxData.PickOutDataBytes(dataBytes, DATA_BYTES_SIZE);
    for (int i = 0; i < DATA_BYTES_SIZE; i++) {
      Serial.println(dataBytes[i]);
    }
  } else {
    Serial.println("receive failed");
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