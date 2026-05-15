#include <PololuLedStrip.h> 
PololuLedStrip<4> LEDS;
#define LED_COUNT 16  
rgb_color colors[LED_COUNT];
int speed;
bool debug = false;

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
  Serial.println("To toggle debugging infos in the Serial Monitor, send any information to it.");
  delay(500);
}

void loop(){
  if (Serial.available() > 0) {
    debug = !debug;
    Serial.println("Debugging infos turned on/off.");
    Serial.readString();
    delay(500);
  }

  for(int i = 0; i < 8; i++){
    on(255,0,0);
    on(0,255,0,i);
    on(0,255,0,i+8);
    delay(50);
  }
}