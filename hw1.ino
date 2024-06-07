#define BUZZER_PIN 7
#define HC_TRIG_PIN 11
#define HC_ECHO_PIN 12
#define SENSOR_PIN 13
#define DISTANCE 100

long duration, cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(SENSOR_PIN, INPUT);
  pinMode(HC_ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(HC_TRIG_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN,LOW);
  if(digitalRead(SENSOR_PIN) == HIGH){
    digitalWrite(HC_TRIG_PIN, LOW);
    delayMicroseconds(5);
    digitalWrite(HC_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(HC_TRIG_PIN, LOW);

    pinMode(HC_ECHO_PIN, INPUT);
    duration = pulseIn(HC_ECHO_PIN, HIGH);
  
    // 將時間轉換為距離
    cm = (duration/2) / 29.1;
    Serial.print(cm);
    Serial.print("cm\n");

    if(DISTANCE > cm){
      digitalWrite(BUZZER_PIN,HIGH);
    }
  }

  delay(400);
}
