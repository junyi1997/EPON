int pinADC[]={36, 39, 34, 35, 32, 33};//ADC1腳位
int state[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//狀態陣列
int small_R=4000;//觸發區間<ADC_V0
int small_R_ADC1=3700;//觸發區間<ADC_V0
int big_R=100;//觸發區間>ADC_V0
int ADC_V0[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//取樣計數器
int k=100;//取樣次數
#include <driver/adc.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include "esp32-hal-adc.h" 
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
void setup()
{
    for (int i=0; i<6; i++){pinMode(pinADC[i], ANALOG);}
    Serial.begin(115200);//序列視窗
    SerialBT.begin("E_PON_Piano");//<<藍芽名稱，請自己記得
}
void loop()
{
  for(int j = 0 ; j < k ; j++)
  {
    for(int i = 0 ; i < 7 ; i++)
    {
      ADC_V0[i]+=analogRead(pinADC[i]);
    }
    int read_raw1;int read_raw2;int read_raw3;int read_raw4;
    int read_raw5;int read_raw6;int read_raw7;int read_raw8;
    adc2_config_channel_atten( ADC2_CHANNEL_8, ADC_ATTEN_6db );
    esp_err_t r = adc2_get_raw( ADC2_CHANNEL_8, ADC_WIDTH_12Bit, &read_raw1);
    adc2_config_channel_atten( ADC2_CHANNEL_9, ADC_ATTEN_6db );
    esp_err_t r1 = adc2_get_raw( ADC2_CHANNEL_9, ADC_WIDTH_12Bit, &read_raw2); 
    adc2_config_channel_atten( ADC2_CHANNEL_7, ADC_ATTEN_6db );
    esp_err_t r2 = adc2_get_raw( ADC2_CHANNEL_7, ADC_WIDTH_12Bit, &read_raw3); 
    adc2_config_channel_atten( ADC2_CHANNEL_6, ADC_ATTEN_6db );
    esp_err_t r3 = adc2_get_raw( ADC2_CHANNEL_6, ADC_WIDTH_12Bit, &read_raw4); 
    adc2_config_channel_atten( ADC2_CHANNEL_5, ADC_ATTEN_6db );
    esp_err_t r4 = adc2_get_raw( ADC2_CHANNEL_5, ADC_WIDTH_12Bit, &read_raw5); 
    adc2_config_channel_atten( ADC2_CHANNEL_4, ADC_ATTEN_6db );
    esp_err_t r5 = adc2_get_raw( ADC2_CHANNEL_4, ADC_WIDTH_12Bit, &read_raw6); 
    adc2_config_channel_atten( ADC2_CHANNEL_0, ADC_ATTEN_6db );
    esp_err_t r6 = adc2_get_raw( ADC2_CHANNEL_0, ADC_WIDTH_12Bit, &read_raw7); 
    adc2_config_channel_atten( ADC2_CHANNEL_3, ADC_ATTEN_6db );
    esp_err_t r7 = adc2_get_raw( ADC2_CHANNEL_3, ADC_WIDTH_12Bit, &read_raw8); 
    
    ADC_V0[6]+=read_raw1;
    ADC_V0[7]+=read_raw2;
    ADC_V0[8]+=read_raw3;
    ADC_V0[9]+=read_raw4;
    ADC_V0[10]+=read_raw5;
    ADC_V0[11]+=read_raw6;
    ADC_V0[12]+=read_raw7;
    ADC_V0[13]+=read_raw8;
    
  }
    for (int i=0;i<14;i++){ADC_V0[i]=ADC_V0[i]/k;}//Serial.print(ADC_V0[i]);Serial.print("\t");}Serial.println();
    
    //delay(100);
  if (ADC_V0[0]<small_R_ADC1 && ADC_V0[0]>big_R){//Do0
    if(state[0]==0){
      state[0]=1;
      Serial.println("Do0");SerialBT.print("Do0");
    }
  }else{
    if(state[0]==1){
      state[0]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[1]<small_R_ADC1 && ADC_V0[1]>big_R){//Re0
    if(state[1]==0){
      state[1]=1;
      Serial.println("Re0");SerialBT.print("Re0");
    }
  }else{
    if(state[1]==1){
      state[1]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[2]<small_R_ADC1 && ADC_V0[2]>big_R){//Mi0
    if(state[2]==0){
      state[2]=1;
      Serial.println("Mi0");SerialBT.print("Mi0");
    }
  }else{
    if(state[2]==1){
      state[2]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[3]<small_R_ADC1 && ADC_V0[3]>big_R){//Fa0
    if(state[3]==0){
      state[3]=1;
      Serial.println("Fa0");SerialBT.print("Fa0");
    }
  }else{
    if(state[3]==1){
      state[3]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[4]<small_R_ADC1 && ADC_V0[4]>big_R){//So0
    if(state[4]==0){
      state[4]=1;
      Serial.println("So0");SerialBT.print("So0");
    }
  }else{
    if(state[4]==1){
      state[4]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[5]<small_R_ADC1 && ADC_V0[5]>big_R){//La0
    if(state[5]==0){
      state[5]=1;
      Serial.println("La0");SerialBT.print("La0");
    }
  }else{
    if(state[5]==1){
      state[5]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[6]<small_R && ADC_V0[6]>big_R){//Si0
    if(state[6]==0){
      state[6]=1;
      Serial.println("Si0");SerialBT.print("Si0");
    }
  }else{
    if(state[6]==1){
      state[6]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[7]<small_R && ADC_V0[7]>big_R){//Do1
    if(state[7]==0){
      state[7]=1;
      Serial.println("Do1");SerialBT.print("Do1");
    }
  }else{
    if(state[7]==1){
      state[7]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[8]<small_R && ADC_V0[8]>big_R){//Re1
    if(state[8]==0){
      state[8]=1;
      Serial.println("Re1");SerialBT.print("Re1");
    }
  }else{
    if(state[8]==1){
      state[8]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[9]<small_R && ADC_V0[9]>big_R){//Mi1
    if(state[9]==0){
      state[9]=1;
      Serial.println("Mi1");SerialBT.print("Mi1");
    }
  }else{
    if(state[9]==1){
      state[9]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[10]<small_R && ADC_V0[10]>big_R){//Fa1
    if(state[10]==0){
      state[10]=1;
      Serial.println("Fa1");SerialBT.print("Fa1");
    }
  }else{
    if(state[10]==1){
      state[10]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[11]<small_R && ADC_V0[11]>big_R){//So1
    if(state[11]==0){
      state[11]=1;
      Serial.println("So1");SerialBT.print("So1");
    }
  }else{
    if(state[11]==1){
      state[11]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[12]<small_R && ADC_V0[12]>big_R){//La1
    if(state[12]==0){
      state[12]=1;
      Serial.println("La1");SerialBT.print("La1");
    }
  }else{
    if(state[12]==1){
      state[12]=0;
      SerialBT.print("000");
    }
  }
  if (ADC_V0[13]<small_R && ADC_V0[13]>big_R){//Si1
    if(state[13]==0){
      state[13]=1;
      Serial.println("Si1");SerialBT.print("Si1");
    }
  }else{
    if(state[13]==1){
      state[13]=0;
      SerialBT.print("000");
    }
  }
}
