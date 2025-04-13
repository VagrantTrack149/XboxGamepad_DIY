// Definición de pines
const int pinVRX = 1;  
const int pinVRY = 2;  
const int pinSW = 3;   

const int pinL = 9;     
const int pinR = 44;     
const int pinSelect = 8; 
const int pinStart = 7; 
const int pinA = 5;     
const int pinB = 4;     
const int pinX = 43;    
const int pinY = 6;     

void setup() {
  Serial.begin(115200);

  pinMode(pinVRX, INPUT);
  pinMode(pinVRY, INPUT);
  pinMode(pinSW, INPUT_PULLUP);  

  pinMode(pinL, INPUT_PULLUP);
  pinMode(pinR, INPUT_PULLUP);
  pinMode(pinSelect, INPUT_PULLUP);
  pinMode(pinStart, INPUT_PULLUP);
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinX, INPUT_PULLUP);
  pinMode(pinY, INPUT_PULLUP);
}

void loop() {
  int valorVRX = analogRead(pinVRX);
  int valorVRY = analogRead(pinVRY);
  int estadoSW = digitalRead(pinSW);

  int estadoL = digitalRead(pinL);
  int estadoR = digitalRead(pinR);
  int estadoSelect = digitalRead(pinSelect);
  int estadoStart = digitalRead(pinStart);
  int estadoA = digitalRead(pinA);
  int estadoB = digitalRead(pinB);
  int estadoX = digitalRead(pinX);
  int estadoY = digitalRead(pinY);

  Serial.print("VRX: ");
  Serial.print(valorVRX);
  Serial.print(" VRY: ");
  Serial.print(valorVRY);
  Serial.print(" SW: ");
  Serial.print(estadoSW);

  Serial.print(" L: ");
  Serial.print(estadoL);
  Serial.print(" R: ");
  Serial.print(estadoR);
  Serial.print(" Select: ");
  Serial.print(estadoSelect);
  Serial.print(" Start: ");
  Serial.print(estadoStart);
  Serial.print(" A: ");
  Serial.print(estadoA);
  Serial.print(" B: ");
  Serial.print(estadoB);
  Serial.print(" X: ");
  Serial.print(estadoX);
  Serial.print(" Y: ");
  Serial.println(estadoY);

  delay(100);
}