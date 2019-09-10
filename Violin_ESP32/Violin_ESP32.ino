#include <BluetoothSerial.h>     //呼叫ESP32藍芽lib
BluetoothSerial SerialBT;        //宣告藍芽物件=SerialBT
int BT_Pin=4;                    //宣告拉弦腳位為第4隻腳
void setup() {
  SerialBT.begin("E_PON_Violin");//<<藍芽名稱，請自己記得   
  Serial.begin(9600);
  pinMode(BT_Pin,INPUT);
}
void loop() {
  int BTStat=0;                  //定義按鈕觸發狀態計數器初始值為0
  while(true){
    if(digitalRead(BT_Pin)==1){  //如果拉弦時
      delay(750);                //連續演奏速度請改這
      BTStat=1;                  //改變按鈕觸發狀態計數器初始值為1
      SerialBT.print("0");       //透過藍芽傳送"0"
      Serial.println("0");       //序列阜監控視窗顯示"0"
    }else{                       //如果無拉弦時
      if(BTStat==1){             //如果按鈕觸發狀態計數器初始值為1
        BTStat=0;                //改變按鈕觸發狀態計數器初始值為0
        SerialBT.print("1");     //透過藍芽傳送"0"
        Serial.println("1");     //序列阜監控視窗顯示"0"
        delay(10);
      }
    }
  }
}
