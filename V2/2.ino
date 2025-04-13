#include <Bluepad32.h>

// Pines del joystick y botones
const int pinVRX = 1;
const int pinVRY = 2;
const int pinSW = 3;

const int pinL = 9;
const int pinR = 8;
const int pinSelect = 7;
const int pinStart = 44;
const int pinA = 5;
const int pinB = 4;
const int pinX = 43;
const int pinY = 6;

// Objeto para el gamepad
GamepadPtr myGamepad;

void setup() {
  Serial.begin(115200);
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

  // Configurar los pines
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
  BP32.update();

  if (myGamepad && myGamepad->isConnected()) {
    // Leer valores de pines
    int valorVRX = analogRead(pinVRX);
    int valorVRY = analogRead(pinVRY);
    bool estadoSW = !digitalRead(pinSW);
    bool estadoA = !digitalRead(pinA);
    bool estadoB = !digitalRead(pinB);
    bool estadoX = !digitalRead(pinX);
    bool estadoY = !digitalRead(pinY);
    bool estadoL = !digitalRead(pinL);
    bool estadoR = !digitalRead(pinR);
    bool estadoSelect = !digitalRead(pinSelect);
    bool estadoStart = !digitalRead(pinStart);

    valorVRX = constrain(valorVRX, 0, 4095);
    valorVRY = constrain(valorVRY, 0, 4095);

    // Mapear valores de ejes
    int ejeX = map(valorVRX, 0, 4095, -512, 512);
    int ejeY = map(valorVRY, 0, 4095, -512, 512);

    // Mostrar el estado en el monitor serial
    Serial.print("Joystick X: ");
    Serial.print(ejeX);
    Serial.print(" Y: ");
    Serial.println(ejeY);

    Serial.print("Botones -> SW: ");
    Serial.print(estadoSW);
    Serial.print(", A: ");
    Serial.print(estadoA);
    Serial.print(", B: ");
    Serial.print(estadoB);
    Serial.print(", X: ");
    Serial.print(estadoX);
    Serial.print(", Y: ");
    Serial.print(estadoY);
    Serial.print(", L: ");
    Serial.print(estadoL);
    Serial.print(", R: ");
    Serial.print(estadoR);
    Serial.print(", Select: ");
    Serial.print(estadoSelect);
    Serial.print(", Start: ");
    Serial.println(estadoStart);
  }

  delay(100);
}

void onConnectedGamepad(GamepadPtr gp) {
  myGamepad = gp;
  Serial.println("Gamepad conectado!");
}

void onDisconnectedGamepad(GamepadPtr gp) {
  if (myGamepad == gp) {
    myGamepad = nullptr;
    Serial.println("Gamepad desconectado!");
  }
}
