#include <Wire.h>
#include <RTClib.h>
#include <IRremote.h>

#define PIR_PIN 7
#define IR_PIN 11
#define RELE_PIN 8

#define BTN_OK 0xFF38C7

RTC_DS1307 rtc;
IRrecv irrecv(IR_PIN);
decode_results results;

bool luz_lig = false;
bool modo_man = false;
unsigned long ult_mov = 0;
const long temp_desl = 10000;

void lig_luz() {
  digitalWrite(RELE_PIN, HIGH);
  luz_lig = true;
}

void desl_luz() {
  digitalWrite(RELE_PIN, LOW);
  luz_lig = false;
}

bool hor_noturno() {
  DateTime now = rtc.now();
  int hora = now.hour();
  return (hora >= 23 || hora < 6);
}

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELE_PIN, OUTPUT);
  digitalWrite(RELE_PIN, LOW);
  irrecv.enableIRIn();
  rtc.begin();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == BTN_OK) {
      modo_man = !modo_man;
      
      if (modo_man) {
        desl_luz();
      }
    }
    irrecv.resume();
  }

  if (modo_man) return;

  if (hor_noturno()) {
    desl_luz();
    return;
  }

  if (digitalRead(PIR_PIN) == HIGH) {
    ult_mov = millis();

    if (!luz_lig) {
      lig_luz();
    }

    if (luz_lig && (millis() - ult_mov >= temp_desl)) {
      desl_luz();
    }
  }
}

