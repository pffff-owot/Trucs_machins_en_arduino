#include <PololuLedStrip.h> 
PololuLedStrip<4> LEDS;
#define LED_COUNT 16  
rgb_color colors[LED_COUNT];
long a;
long b;
long c;
int speed;
bool debug = false;
String message;

//Allume toutes les leds de la couleur rgb_color(r,g,b) spécifiée
void on(int r, int g, int b, int led=-1){
  //off();
    if(debug){
      Serial.print(" blue:");Serial.print(b);
      Serial.print(" red:");Serial.print(r);
      Serial.print(" green:");Serial.print(g);
      Serial.print(" delay:");Serial.print(speed);
      Serial.print(" LED_Operating:");Serial.println(led);
    }
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
void handle_serial_commands(String command){
  char first_char = command[0] ;
  switch (first_char) {
    case 't':
      debug = !debug;
      Serial.print("Debugging infos (0/1) : ");Serial.println(debug);
      delay(500);
      break;
    case 'w':
      on(255,255,255);
      delay(10000);
      off();
      break;
    case 'b':
      off();
      delay(10000);
      break;
    case 'h':
      Serial.println("h : dispaly this help message\nt : toggle debugging infos\nw : turn all leds white for 10secs\nb :  turn all leds black for 10secs");
      break;
    default:
      Serial.println("Unkown command\nsend \"help\" to get a list of all avaiable commands.");
      on(255,0,0);
      delay(3000);
      setup();
  }
}

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("To toggle debugging infos in the Serial Monitor, send \"t\" to it.");
}

void loop(){
  speed=88;
  a = random(256);
  b = random(256);
  c = random(256);
  if (Serial.available() > 0) {
    message = Serial.readString();
    message.trim();
    handle_serial_commands(message);
  }
  for(int i = 0 ; i < 8 ; i++){
    on(a,b,c,i);
    speed=speed-11;
    delay(speed);
  }  
  for(int i = 8 ; i < 16 ; i++){
    on(a,b,c,i);
    speed=speed+11;
    delay(speed);
  }
  for(int i = 0 ; i < 8 ; i++){
    on(0,0,0,i);
    speed=speed-11;
    delay(speed);
  }  
  for(int i = 8 ; i < 16 ; i++){
    on(0,0,0,i);
    speed=speed+11;
    delay(speed);
  }
}