
//define variables
#define trigerPin 12
#define echoPin 13
#define ledPin 2
#define speakerPin 10
#define pitch 262

double duration, distance;

void setup() {
  
  Serial.begin(9600);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  pinMode(ledPin, OUTPUT);


  pinMode(speakerPin, OUTPUT);

}

void loop() {
  
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);

  
  duration = pulseIn(echoPin,HIGH);

 
  distance = (duration/2) * 0.0343;

  
  if(distance<200){
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, pitch);
    delay(300);

    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
    delay(300);
  }else{
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
  }
}
