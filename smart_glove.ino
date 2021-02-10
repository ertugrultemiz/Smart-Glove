#include<Wire.h>    // I2C fonksiyonlarını kullanabilmek için Wire.h kütüphanesi
  #include <SPI.h>    // SPI fonksiyonlarını kullanabilmek için SPI.h kütüphanesi


  #define CSpin    4


  const int MPU=0x68;//MPU-6050'nin I2C haberleşme adresi
  int AcZ_value;
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;// IMU'dan alınacak değerlerin kaydedileceği değişkenler 

  int sensor1,sensor2,sensor3,sensor4,sensor5; // Her bir parmak için kullanılacak olan flex sensorlerin değerlerinin okunacağı değişkenler
  

void setup(){

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0); // MPU-6050 çalıştırıldı 
  Wire.endTransmission(true);
  // I2C haberleşmesi başlatıldı ve MPU-6050'nin ilk ayarları yapıldı
  
  Serial.begin(9600); // serial açılıyor
  
  
}

void loop(){
  
  verileriOku();//IMU'dan değerler okundu 

  Serial.print("ivmeX = ");
  Serial.print(AcX);
  Serial.print(" | ivmeY = "); 
  Serial.print(AcY);
  Serial.print(" | ivmeZ = "); 
  Serial.print(AcZ);  
  Serial.print(" | GyroX = "); 
  Serial.print(GyX);
  Serial.print(" | GyroY = "); 
  Serial.print(GyY);
  Serial.print(" | GyroZ = "); 
  Serial.println(GyZ);
  
    
  AcZ_value = map(AcZ, 0, 17000, 0,255);
  Serial.print(" | AcZ_value = ");
  Serial.println( AcZ_value);

  sensor1= analogRead(0);
  sensor1=map(sensor1, 700, 900, 0,255);
  Serial.print("analog input1: ");
  Serial.println(sensor1,DEC);
 
  sensor2= analogRead(1);
  sensor2=map(sensor2, 700, 900, 0,255);
  Serial.print("analog input2: ");
  Serial.println(sensor2,DEC);
    
  sensor3= analogRead(2);
  sensor3=map(sensor3, 700, 900, 0,255);
  Serial.print("analog input3: ");
  Serial.println(sensor3,DEC);
  
  sensor4= analogRead(3);
  sensor4=map(sensor4, 700, 900, 0,255);
  Serial.print("analog input4: ");
  Serial.println(sensor4,DEC);
  
  sensor5= analogRead(4);
  sensor5=map(sensor5, 700, 900, 0,255);
  Serial.print("analog input5: ");
  Serial.println(sensor5,DEC);
  
  delay(5000);

  //Sensorlerden okunan değerlere göre ekrana harfler yazdırılmaktadır.
    
if (sensor1>-600 && sensor2<-730 && sensor4<-670 && sensor4<-670 && sensor5<-125){
  Serial.println("A"); 
  delay(5000);
 }

if (sensor1 > -590 && sensor2 > -655 && sensor3>-600 && sensor4>-600 && sensor5>-115) {
  Serial.println("B"); 
  delay(5000);
 }

if (sensor1<-630 && sensor2 < -710 && sensor3<-720 && sensor4<-700 && sensor5<-110 && AcZ_value<-110) {
  Serial.println("C"); 
  delay(5000);
 }

 if (sensor1>-600 && sensor2 > -620 && sensor3<-715 && sensor4<-685 && sensor5<-120) {
  Serial.println("D"); 
  delay(5000);
 }

  if (sensor1<-640 && sensor2 < -720 && sensor3<-720 && sensor4<-700 && sensor5>-130 && AcZ_value>-110 ) {
  Serial.println("E"); 
  delay(5000);
 }

 if (sensor1>-640 && sensor2 < -710 && sensor3>-610 && sensor4>-610 && sensor5>-115) {
  Serial.println("F"); 
  delay(5000);
 }

  if (sensor1>-590 && sensor2 < -650 && sensor3<-730 && sensor4<-660 && sensor5>-135) {
  Serial.println("G"); 
  delay(5000);
 }
   
  if (sensor1>-610 && sensor2 > -635 && sensor3>-615 && sensor4<-680 && sensor5>-130) {
  Serial.println("H"); 
  delay(5000);
 }

  if (sensor1<-620 && sensor2 < -725 && sensor3<-715 && sensor4<-680 && sensor5>-110) {
  Serial.println("I"); 
  delay(5000);
}

  if (sensor1>-610 && sensor2 < -725 && sensor3<-715 && sensor4<-680 && sensor5>-110 && AcZ_value > -50) {
  Serial.println("J"); 
  delay(5000);
}
 
  if (sensor1>-610 && sensor2 < -635 && sensor3>-635 && sensor4<-680 && sensor5>-130 ) {
  Serial.println("K"); 
  delay(5000);
}

  if (sensor1>-600 && sensor2 > -640 && sensor3<-725 && sensor4<-700 && sensor5<-125 && AcZ_value>-150  ) {
  Serial.println("L"); 
  delay(5000);
}

  if (sensor1>-630 && sensor2 < -730 && sensor3<-705 && sensor4<-620 && sensor5<-125 ) {
  Serial.println("M"); 
  delay(5000);
}

  if (sensor1>-630 && sensor2 < -680 && sensor3>-725 && sensor4<-650 && sensor5<-120 ) {
  Serial.println("N"); 
  delay(5000);
}

  if (sensor1<-630 && sensor2 > -740 && sensor3<-655 && sensor4<-650 && sensor5<-120 && AcZ_value > -150 ) {
  Serial.println("O"); 
  delay(5000);
}

  if (sensor1>-600 && sensor2 < -610 && sensor3>-670 && sensor4<-670 && sensor5<-120 && AcZ_value < -190 ) {
  Serial.println("P"); 
  delay(5000);
}

  if (sensor1>-600 && sensor2 > -640 && sensor3<-725 && sensor4<-700 && sensor5<-125 && AcZ_value<-150 ) {
  Serial.println("Q"); 
  delay(5000);
}

  if (sensor1>-630 && sensor2 > -610 && sensor3>-605 && sensor4<-680 && sensor5<-120 ) {
  Serial.println("R"); 
  delay(5000);
}
  
  if (sensor1<-630 && sensor2 < -740 && sensor3<-715 && sensor4<-650 && sensor5<-125 ) {
  Serial.println("S"); 
  delay(5000);
}

  if (sensor1>-630 && sensor2 < -700 && sensor3<-725 && sensor4<-670 && sensor5<-125 ) {
  Serial.println("T"); 
  delay(5000);
}

  if (sensor1<-615 && sensor2 > -630 && sensor3>-610 && sensor4<-710 && sensor5<-125 ) {
  Serial.println("U"); 
  delay(5000);
}
  
  if (sensor1<-615 && sensor2 > -630 && sensor3>-610 && sensor4<-710 && sensor5>-125 ) {
  Serial.println("V"); 
  delay(5000);
}

  if (sensor1<-615 && sensor2 > -630 && sensor3>-610 && sensor4>-610 && sensor5<-135 ) {
  Serial.println("W"); 
  delay(5000);
}

  if (sensor1<-630 && sensor2 < -740 && sensor3<-715 && sensor4<-700 && sensor5<-120 && AcZ_value<-200 ) {
  Serial.println("X"); 
  delay(5000);
}

  if (sensor1>-600 && sensor2 < -730 && sensor3<-690 && sensor4<-690 && sensor5>-120 ) {
  Serial.println("Y"); 
  delay(5000);
}

  if (sensor1>-640 && sensor2> -615 && sensor3<-690 && sensor4<-670 && sensor5<-120 && AcZ_value <-150) {
  Serial.println("Z"); 
  delay(5000);
}
}
void verileriOku(){
  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);
  
   /* 
  * Sırası ile okunan her iki byte birleştirilerek sırası ile değişkenlere yazdırıldı
  * Böylece IMU'dan tüm değerler okunmuş oldu
  * 0X3B adresi imu değerlerinden ilk sensörün değerine denk gelmektedir.
  * IMU'dan tüm değerlerin okunabilmesi için bu adresten başlandı
  */
  
  AcX=Wire.read()<<8|Wire.read();   
  AcY=Wire.read()<<8|Wire.read(); 
  AcZ=Wire.read()<<8|Wire.read(); 
  Tmp=Wire.read()<<8|Wire.read(); 
  GyX=Wire.read()<<8|Wire.read(); 
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();
 
}
