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
void on(){
  pinMode(6,OUTPUT);
  analogWrite(6,255);
}

void off(){
  pinMode(6,OUTPUT);
  analogWrite(6,0);
}

void change_lum(){
  int lum = 6;
  pinMode(lum, OUTPUT);
  //log("25 lcd");
  if(up==true){
    for(int count = 55; count < 155; count = count + 1){
      //log("28 lcd");
      analogWrite(lum, count);
      Serial.println("lum level:"+String(count));
      delay(10);
    }
    up=false;
  }
  else if(up==false){
    //log("36 lcd");
    for (int count = 155; count > 55; count = count - 1){
      //log("38 lcd");
      analogWrite(lum, count);
      Serial.println("lum_level:"+String(count));
      delay(10);
    }
    up=true;
  }
}