#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int heures = 00;
int minutes = 00;
int secondes = 00;
const int BTN_PIN = 2;
void setup(){
  turn_on_lcd();
  if(digitalRead(BTN_PIN)==0){
    lcd.print(minutes);
    while(true){}
  }
}

void loop(){
  lcd.print("cac");
  delay(100);
}
