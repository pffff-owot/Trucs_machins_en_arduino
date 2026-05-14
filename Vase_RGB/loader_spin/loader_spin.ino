#include <PololuLedStrip.h> 
PololuLedStrip<4> LEDS;
#define LED_COUNT 16  
rgb_color colors[LED_COUNT];
  long a;
  long b;
  long c;

//Allume toutes les leds de la couleur rgb_color(r,g,b) spécifiée
void on(int r, int g, int b, int led=-1){
  //off();
  if(led== -1){
    for(int i = 0 ; i < LED_COUNT ; i++){
      colors[i] = rgb_color(r,g,b);
    }
  }
  else{
    colors[led] = rgb_color(r,g,b);
  }
  LEDS.write(colors, LED_COUNT);
}
void on(rgb_color couleur){
  //Allume toutes les leds de la couleur rgb_color(couleur) spécifiée 

  for(int i = 0 ; i < LED_COUNT ; i++){
    colors[i] = rgb_color(couleur);
  }
  LEDS.write(colors, LED_COUNT);
}
void off(){
  for(int i = 0 ; i < LED_COUNT ; i++){
    colors[i] = rgb_color(0,0,0);
  }
  LEDS.write(colors, LED_COUNT);
}

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop(){
  a = random(256);
  b = random(256);
  c = random(256);
  for(int i = 0 ; i < LED_COUNT ; i++){
    on(a,b,c,i);
    delay(50);
  }
  for(int i = 0 ; i < LED_COUNT ; i++){
    on(0,0,0,i);
    delay(50);
  }
}