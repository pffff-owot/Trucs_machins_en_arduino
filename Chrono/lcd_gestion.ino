void turn_on_lcd(){
  lcd.begin(16,2);
  light_on_lcd();
}

void light_on_lcd(){
  pinMode(6,OUTPUT);
  analogWrite(6,255);
  pinMode(5,OUTPUT);
  analogWrite(5,90);
}
