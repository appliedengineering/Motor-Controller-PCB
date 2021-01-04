const byte interruptPin = 2;
float rev=0;
int hit = 0;
int rpm;
int oldtime=0;        
float dT;
int ledPin = 13;
int oldDigitalRead = 1;
volatile byte state = HIGH;

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  Serial.begin(115200);
  // attachInterrupt(digitalPinToInterrupt(interruptPin), isr, RISING);
}

/*
void isr(){
state = !state;
rev++;
hits++;
Serial.println(hits);
}
*/

void loop() {
delay(10);
digitalWrite(ledPin, state);
if (digitalRead(2)< oldDigitalRead){ 
  rev++;
}
oldDigitalRead = digitalRead(2);
// detachInterrupt(2);                      
if (hit%50==0) {
  rpmUpdate();
  Serial.print(rpm);
  Serial.print(" ");
  Serial.print(dT);
  Serial.print(" ");
  Serial.print(rev);
  Serial.println();
  rev = 0;
}
hit++;
// attachInterrupt(digitalPinToInterrupt(interruptPin),isr,RISING);
}

void rpmUpdate() {
  dT=millis()-oldtime;        
  rpm=(rev/dT)*60000;
  oldtime = millis();
}

