// IMPORTO LE LIBRERIE CHE SERVONO
#include <Servo.h>

// VARIABILI SERVO
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinky;

// VARIABILI INT
int incoming[5];

void setup() {
  // INIZIALIZZO SERIALE
  Serial.begin(9600);

  // INIZIALIZZO I SERVO
  thumb.attach(3);
  index.attach(5);
  middle.attach(6);
  ring.attach(9);
  pinky.attach(10);

  // IMPOSTO A 0 I SERVO ALL'INIZIO
  thumb.write(0);
  index.write(0);
  middle.write(0);
  ring.write(0);
  pinky.write(0);
}

void loop() {
  // RICEVO I DATI
  Receive();

  // APPLICO I DATI
  // POLLICE
  if (incoming[0] == 1) {
    thumb.write(90);
  } else {
    thumb.write(0);
  }

  // INDICE
  if (incoming[1] == 1) {
    index.write(90);
  } else {
    index.write(0);
  }

  // MEDIO
  if (incoming[2] == 1) {
    middle.write(90);
  } else {
    middle.write(0);
  }

  // ANULARE
  if (incoming[3] == 1) {
    ring.write(90);
  } else {
    ring.write(0);
  }

  // MIGNOLO
  if (incoming[4] == 1) {
    pinky.write(90);
  } else {
    pinky.write(0);
  }
}

void Receive() {
  if(Serial.available() >= 5){
    // METTO TUTTI I DATI RICEVUTI NELL'ARRAY
    for (int i = 0; i < 5; i++){
      incoming[i] = Serial.read();
    }
  }
}
