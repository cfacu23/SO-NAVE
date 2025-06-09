// Cambia el color de una LED RGB suavemente cuando se detecta presencia

const int TRIG = 9;
const int ECHO = 10;
const int R = 3;
const int G = 5;
const int B = 6;

const int DISTANCIA_MINIMA = 30;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  long distancia = duracion * 0.034 / 2;

  if (distancia > 0 && distancia < DISTANCIA_MINIMA) {
    analogWrite(R, 30);  // Rojo tenue
    analogWrite(G, 0);
    analogWrite(B, 30);
    delay(300);
    analogWrite(R, 0);
    analogWrite(G, 30);  // Verde tenue
    analogWrite(B, 30);
    delay(300);
    analogWrite(R, 30);  // Azul tenue
    analogWrite(G, 30);
    analogWrite(B, 0);
    delay(300);
  } else {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }

  delay(100);
}
