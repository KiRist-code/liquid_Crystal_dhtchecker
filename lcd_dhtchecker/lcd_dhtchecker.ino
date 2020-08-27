#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<DHT11.h>

LiquidCrystal_I2C lcd(0x27,16,2);
DHT11 dht(7);

float temp,humi;
int value;
int nx = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Hello!!");
  lcd.setCursor(0,1);
  lcd.print("NOW LOADING...");
  delay(2000);
  lcd.clear();
}

void loop() {
  value = dht.read(humi,temp);
  if(digitalRead(3) == 1) {
    nx++;
    delay(100);
  }
  if(nx % 2 == 0){
    lcd.setCursor(0,0);
    lcd.print("temperature:");
    lcd.setCursor(0,1);
    lcd.print(temp);
    for(int i=0;i<5;i++){
      delay(1000);
      lcd.scrollDisplayRight();
    }
  }
  if(nx % 2 == 1){
    lcd.setCursor(7,0);
    lcd.print("humidity:");
    lcd.setCursor(7,1);
    lcd.print(humi);
    for(int i=0;i<8;i++){
      delay(1000);
      lcd.scrollDisplayLeft();
    }
  }
  lcd.clear();
}
