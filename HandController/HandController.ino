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

// ! QUESTE RIGHE SERVONO PER MUOVERE I SERVO IN BASE ALL'ANGOLAZIONE DELLE DITA
//  int angle1 = map(incoming[0], 25, 70, 0, 90);
//  thumb.write(angle1);
//
//  int angle2 = map(incoming[1], 10, 85, 0, 90);
//  index.write(angle2);
//
//  int angle3 = map(incoming[2], 20, 100, 0, 90);
//  middle.write(angle3);
//
//  int angle4 = map(incoming[3], 20, 90, 0, 90);
//  ring.write(angle4);
//
//  int angle5 = map(incoming[4], 15, 70, 0, 90);
//  pinky.write(angle5);

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
