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
  value = dht.read(humi,temp);
  delay(2000);
}

void loop() {
  if(digitalRead(3) == 1) {
    if(nx == 2) nx = 1;
    else nx++;
  }
  if(nx == 0){
    lcd.setCursor(0,0);
    lcd.print("Hello!!");
    lcd.setCursor(0,1);
    lcd.print("NOW LOADING...");
  }
  else {
    if(nx = 1){`
      lcd.setCursor(0,0);
      lcd.print("temperature:");
      lcd.setCursor(0,1);
      lcd.print(temp);
    }
    else {
      lcd.setCursor(0,0);
      lcd.print("humidity :");
      lcd.setCursor(0,1);
      lcd.print(humi);
    }
  }
  delay(1000);
  lcd.clear();
}
