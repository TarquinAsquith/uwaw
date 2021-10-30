// C++ code
//
const int trigpin = 9;
const int echopin = 10;
const int trigpin2 = 11;
const int echopin2 = 12;
const int ledpin = 2;
const int ledpin2 = 3;
const int in=6;
long durasi, durasi2;
int jarak, jarak2;

void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  durasi=pulseIn(echopin, HIGH);
  jarak=durasi*0.034/2;
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);
  durasi2=pulseIn(echopin2, HIGH);
  jarak2=durasi2*0.034/2;
  if(jarak<=40 && jarak2>=40){
    digitalWrite(ledpin, HIGH);
    digitalWrite(ledpin2, LOW);
    digitalWrite(in, HIGH);
    delay(3000);
    digitalWrite(in, LOW);
  }
  else if(jarak2<=40 && jarak>=40){
    digitalWrite(ledpin, LOW);
    digitalWrite(ledpin2, HIGH);
  }
  else if(jarak<=40 && jarak2<=40){
    digitalWrite(ledpin, HIGH);
    digitalWrite(ledpin2, HIGH);
    delay(100);
  }
  else{
    digitalWrite(ledpin, LOW);
    digitalWrite(ledpin2, LOW);
    digitalWrite(in, LOW);
  }
  Serial.println(jarak);
  Serial.println(jarak2);
}
