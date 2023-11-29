#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TridentTD_LineNotify.h>
#define SSID        ""      // บรรทัดที่ 11 ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    ""     // บรรทัดที่ 12 ใส่ รหัส Wifi
#define LINE_TOKEN  ""
int sensor; #ตรวจจับ
int sensor1; #วัดระดับน้ำ
int relay = D4;
LiquidCrystal_I2C lcd(0x3f, 20, 4);

byte customChar3[] = { //ยิ
  B01110,
  B11111,
  B00000,
  B11001,
  B10001,
  B11101,
  B10001,
  B01110
};
byte customChar4[] = { //น
  B00000,
  B00000,
  B00000,
  B11010,
  B01010,
  B01010,
  B01011,
  B01111
};
byte customChar5[] = {//ต้
  B01010,
  B00100,
  B01010,
  B10101,
  B10001,
  B10101,
  B11001,
  B10001
};
byte customChar6[] = { //อ
  B00000,
  B00000,
  B00000,
  B01110,
  B00001,
  B11101,
  B10001,
  B01110
};
byte customChar8[] = { //บ
  B00111,
  B00000,
  B01111,
  B01000,
  B01100,
  B00010,
  B00110,
  B00110
};
byte customChar7[] = { // ♥
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};
byte customChar9[] = { //บ
  B00000,
  B00000,
  B00000,
  B11001,
  B01001,
  B01001,
  B01001,
  B01111
};

byte customChar10[] = { //ดี
  B00010,
  B01110,
  B00000,
  B01110,
  B10001,
  B10101,
  B11001,
  B10001
};

void Show_lcd(){
  lcd.setCursor(6, 1);
  lcd.write((byte)3); 
  lcd.setCursor(7, 1); 
  lcd.write((byte)4); 
  lcd.setCursor(8, 1); 
  lcd.write((byte)10); 
  lcd.setCursor(9, 1);
  lcd.write((byte)5); 
  lcd.setCursor(10, 1); 
  lcd.write((byte)6); 
  lcd.setCursor(11, 1); 
  lcd.write((byte)4); 
  lcd.setCursor(12, 1);
  lcd.write((byte)8);
  lcd.setCursor(13, 1); 
  lcd.write((byte)9); 
   //สร้างกรอบหัวใจ
  lcd.setCursor(1, 0);
  lcd.write((byte)7);
  lcd.setCursor(0, 0);
  lcd.write((byte)7);
  lcd.setCursor(0, 1);
  lcd.write((byte)7);
  lcd.setCursor(0, 2);
  lcd.write((byte)7);
  lcd.setCursor(0, 3);
  lcd.write((byte)7);
  lcd.setCursor(1, 3);
  lcd.write((byte)7);
  lcd.setCursor(1, 3);
  lcd.write((byte)7);
  lcd.setCursor(2, 3);
  lcd.write((byte)7);
  lcd.setCursor(3, 3);
  lcd.write((byte)7);
  lcd.setCursor(4, 3);
  lcd.write((byte)7);
  lcd.setCursor(5, 3);
  lcd.write((byte)7);
  lcd.setCursor(6, 3);
  lcd.write((byte)7);
  lcd.setCursor(7, 3);
  lcd.write((byte)7);
  lcd.setCursor(8, 3);
  lcd.write((byte)7);
  lcd.setCursor(9, 3);
  lcd.write((byte)7);
  lcd.setCursor(10, 3);
  lcd.write((byte)7);
  lcd.setCursor(11, 3);
  lcd.write((byte)7);
  lcd.setCursor(12, 3);
  lcd.write((byte)7);
  lcd.setCursor(13, 3);
  lcd.write((byte)7);
  lcd.setCursor(14, 3);
  lcd.write((byte)7);
  lcd.setCursor(15, 3);
  lcd.write((byte)7);
  lcd.setCursor(16, 3);
  lcd.write((byte)7);
  lcd.setCursor(17, 3);
  lcd.write((byte)7);
  lcd.setCursor(18, 3);
  lcd.write((byte)7);
  lcd.setCursor(19, 3);
  lcd.write((byte)7);
  lcd.setCursor(19, 2);
  lcd.write((byte)7);
  lcd.setCursor(19, 1);
  lcd.write((byte)7);
  lcd.setCursor(19, 0);
  lcd.write((byte)7);
  lcd.setCursor(18, 0);
  lcd.write((byte)7);
}
void working_lcd(){
  if (sensor1 >= 400){
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working.");
  lcd.setCursor(2,3);
  lcd.print("LOW WATER LEVEL");
  delay(500);
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working..");
  lcd.setCursor(2,3);
  lcd.print("LOW WATER LEVEL");
  delay(500);
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working...");
  lcd.setCursor(2,3);
  lcd.print("LOW WATER LEVEL");
  LINE.notify("น้ำก๊อกหมด");
  }
  else{
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working.");
  lcd.setCursor(2,3);
  lcd.print("HIGH WATER LEVEL");
  delay(500);
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working..");
  lcd.setCursor(2,3);
  lcd.print("HIGH WATER LEVEL");
  delay(500);
  lcd.clear();   
  lcd.setCursor(6,1);
  lcd.print("Working...");
  lcd.setCursor(2,3);
  lcd.print("HIGH WATER LEVEL");
  }

}
void setup() {
  Serial.begin(9600);
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
  // กำหนด Line Token

  lcd.begin();
  lcd.backlight();
  
  //นำตัวเก็บข้อมูลอักษรมาเปลี่ยนเป็นตัวแปรตามลำดับ
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4); 
  lcd.createChar(5, customChar5); 
  lcd.createChar(6, customChar6); 


  lcd.createChar(7, customChar7); 
  lcd.createChar(8, customChar8);
  lcd.createChar(9, customChar9);
  lcd.createChar(10, customChar10);


  Show_lcd();
  pinMode(D4,OUTPUT);
  digitalWrite(D4, HIGH);

}
void loop() { 
  sensor = digitalRead(D7);
  sensor1 = analogRead(A0);
  Serial.println(sensor);
  Serial.println(sensor1);

  if (sensor == 0){
    digitalWrite(D4, LOW);
    Serial.println("เปิดRelay");
  }
    
  else if(sensor == 1){
    digitalWrite(D4, HIGH);
  }
  delay(1000);
  sensor = digitalRead(D7);
  Serial.println(sensor);
  lcd.clear();
  if (sensor == 0){
    digitalWrite(D4, LOW);
    Serial.println("เปิดRelay");
  }
    
  else if(sensor == 1){
    digitalWrite(D4, HIGH);
  }
  delay(1000);
  sensor = digitalRead(D7);
  Serial.println(sensor);
  if (sensor == 0){
    digitalWrite(D4, LOW);
    Serial.println("เปิดRelay");
    working_lcd(); 
  }
    
  else if(sensor == 1){
    digitalWrite(D4, HIGH);
    Show_lcd();
  }
  }
