#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define lampuMerah 5
#define lampuKuning 18
#define lampuHijau 23

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuKuning, OUTPUT);
  pinMode(lampuHijau, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
    while(true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); 
}

void loop() {
  merah(7); // -> Ganti sesuai waktu yang kalian inginkan
  hijau(4); // -> Ganti sesuai waktu yang kalian inginkan
  kuning(2); // -> Ganti sesuai waktu yang kalian inginkan
}

void merah(int waktu){
  digitalWrite(lampuMerah, HIGH);
  digitalWrite(lampuKuning, LOW);
  digitalWrite(lampuHijau, LOW);
  laluLintas(waktu);
}
void kuning(int waktu){
  digitalWrite(lampuMerah, LOW);
  digitalWrite(lampuKuning, HIGH);
  digitalWrite(lampuHijau, LOW);
  laluLintas(waktu);
}
void hijau(int waktu){
  digitalWrite(lampuMerah, LOW);
  digitalWrite(lampuKuning, LOW);
  digitalWrite(lampuHijau, HIGH);
  laluLintas(waktu);
}
void laluLintas(int waktu){
  for(int i = waktu; i >= 0; i--){
  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(40,20);

  if(i < 10) display.print("0");
  display.print(i);
  display.display();
  delay(1000);
  }
}
