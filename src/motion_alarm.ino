int ledPin = 19; // LED light to show if the PIR works
int inputPin = 23; // Pin 23 is gonna read the PIR input
int val = 0;
int wait = 100;
const int buzzerPin = 26;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLDOWN);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH); // OFF
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  if (val == HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW);  // ON
    delay(wait);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, HIGH); // OFF
    delay(wait);
  }
  else{ 
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, HIGH); // Buzzer OFF
   }
  }
