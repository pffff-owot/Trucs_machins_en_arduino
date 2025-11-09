#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int heures = 0;
int minutes = 0;
int secondes = 3;
void setup() {
  turn_on_lcd();
  lcd.print("hello world");
  Serial.begin(9600);
}

void loop() {
  if(secondes==0){
    secondes=60;
    minutes--;
  }
  if(minutes==0&&heures!=0){
    minutes=60;
    heures--;
  }
  lcd.clear();
  lcd.print(String(heures)+':'+String(minutes)+':'+String(secondes--));
  delay(1000);
  if(heures==0&&minutes==0&&secondes==0){
    end_of_time();
  }
}

//fonction qui permet de faire clignoter l'écran en boucle afin de signaler la fin du chronomètre.
void end_of_time(){
  lcd.clear();
    lcd.print("0:0:0");
  while (true){
    off();
    delay(500);
    on();
    delay(500);
  }
}