#define sensorHujan A0
#define sensorCahaya D0
#define buzzer D1
#define relayKanan D2
#define relayKiri D3

const int cahayaMati = 0;
const int durasibuzzer = 1000;

int kondisi = 0;
float curahHujan = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorCahaya, INPUT);
  pinMode(sensorHujan, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relayKanan, OUTPUT);
  pinMode(relayKiri, OUTPUT);

  digitalWrite(relayKanan, HIGH);
  digitalWrite(relayKiri, HIGH);
  digitalWrite(buzzer, LOW);
  delay(100);
}

int jemuranLoop() {
  int curahHujan = analogRead(sensorHujan);
  int cahayaMati = digitalRead(sensorCahaya);
  
  Serial.print("curah hujan: ");
  Serial.println(curahHujan);  //ganti port
  Serial.print("cahayaMati: ");
  Serial.println(cahayaMati);
  Serial.print("Kondisi: ");
  if(kondisi == 1) {
    Serial.println("Luar");
  } else {
    Serial.println("Dalam");
  }

    //Hujan & Gelap
  if (curahHujan < 500 and cahayaMati == 1) {
    if (kondisi == 1){
      digitalWrite(buzzer, HIGH);
      delay(durasibuzzer);
      digitalWrite(buzzer, LOW);
      digitalWrite(relayKanan, LOW);
      kondisi = 0;
      delay(500);
      digitalWrite(relayKanan, HIGH);
    }
  }
  //Hujan & Terang
  else if (curahHujan < 500 and cahayaMati == 0) {
    if (kondisi == 1){
      digitalWrite(buzzer, HIGH);
      delay(durasibuzzer);
      digitalWrite(buzzer, LOW);
      digitalWrite(relayKanan, LOW);
      kondisi = 0;
      delay(500);
      digitalWrite(relayKanan, HIGH);
    }
  }
  //Gak Hujan & Gelap
  else if (curahHujan >= 500 and cahayaMati == 1) {
    if (kondisi == 1){
      digitalWrite(buzzer, HIGH);
      delay(durasibuzzer);
      digitalWrite(buzzer, LOW);
      digitalWrite(relayKanan, LOW);
      kondisi = 0;
      delay(500);
      digitalWrite(relayKanan, HIGH);
    }
  }
  //Gak Hujan & Terang
  else if (curahHujan >= 500 and cahayaMati == 0) {
    if (kondisi == 0){
      digitalWrite(buzzer, HIGH);
      delay(durasibuzzer);
      digitalWrite(buzzer, LOW);
      digitalWrite(relayKiri, LOW);
      kondisi = 1;
      delay(500);
      digitalWrite(relayKiri, HIGH);
    }
  }
  return kondisi;
}

void loop(){
  int kondisiTerkini = jemuranLoop();
  delay(2000);
}