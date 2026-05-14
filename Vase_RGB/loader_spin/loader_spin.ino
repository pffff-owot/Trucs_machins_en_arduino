#include <PololuLedStrip.h> 
PololuLedStrip<4> LEDS;
#define LED_COUNT 16  
rgb_color colors[LED_COUNT];
long a;
long b;
long c;
int speed;
bool debug = false;

//Allume toutes les leds de la couleur rgb_color(r,g,b) spécifiée
void on(int r, int g, int b, int led=-1){
  //off();
    Serial.print(" blue:");Serial.print(b);
    Serial.print(" red:");Serial.print(r);
    Serial.print(" green:");Serial.print(g);
    Serial.print(" delay:");Serial.print(speed);
    Serial.print(" LED_Operating:");Serial.println(led);
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
  Serial.print("To toggle debugging infos in the Serial Monitor, send any information to it.");
}

void loop(){
  speed=90;
  a = random(256);
  b = random(256);
  c = random(256);
  if (Serial.available() > 0) {
    debug = !debug;
    Serial.println("Debugging infos turned on/off.");
    delay(500);
  }
  for(int i = 0 ; i < 8 ; i++){
    on(a,b,c,i);
    speed=speed-10;
    delay(speed);
  }  
  for(int i = 8 ; i < 16 ; i++){
    on(a,b,c,i);
    speed=speed+10;
    delay(speed);
  }
  for(int i = 0 ; i < 8 ; i++){
    on(0,0,0,i);
    speed=speed-10;
    delay(speed);
  }  
  for(int i = 8 ; i < 16 ; i++){
    on(0,0,0,i);
    speed=speed+10;
    delay(speed);
  }
}