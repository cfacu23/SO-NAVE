// Activa un motor mediante un relé cuando una persona se sienta (sensor ultrasónico)

const int TRIG = 9;
const int ECHO = 10;
const int RELE = 2;

const int DISTANCIA_MINIMA = 30;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELE, OUTPUT);

  digitalWrite(RELE, LOW); // Apagar al inicio
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  long distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia > 0 && distancia < DISTANCIA_MINIMA) {
    digitalWrite(RELE, HIGH); // Motor ON
  } else {
    digitalWrite(RELE, LOW); // Motor OFF
  }

  delay(200);
}
