#include <IRremote.h>

#define PIR_PIN 8
#define IR_PIN 11
#define LED_PIN 13

#define BTN_OK 0xE31CFF00

bool luz_lig = false;
unsigned long ult_mov = 0;
const long temp_apag = 3000;
bool modo_man = false;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("Iniciando...");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long codigo = IrReceiver.decodedIRData.decodedRawData;

    Serial.println(codigo, HEX);

    if (codigo == BTN_OK) {
      modo_man = !modo_man;

      if (modo_man) {
        luz_lig = false;
        digitalWrite(LED_PIN, LOW);
      }
    }
    IrReceiver.resume();
  }

  if (!modo_man) {
    if (digitalRead(PIR_PIN) == HIGH) {
      ult_mov = millis();

      if (!luz_lig) {
        luz_lig = true;
        digitalWrite(LED_PIN, HIGH);
      }
    }

    if (luz_lig && (millis() - ult_mov >= temp_apag)) {
      luz_lig = false;
      digitalWrite(LED_PIN, LOW);
    }
  }
}
