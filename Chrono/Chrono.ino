#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int heures = 0;
int minutes = 0;
int secondes = -1;
void setup(){
  turn_on_lcd();
  lcd.cursor();
}

void loop(){
  if(secondes==60){
    secondes=0;
    minutes++;
    lcd.clear();
  }
  if(minutes==60){
    minutes=0;
    heures++;
    lcd.clear();
  }
  lcd.clear();
  lcd.print(String(heures)+':'+String(minutes)+':'+String(secondes++));
  delay(1000);
}
