const byte interruptPin = 2;
float rev=0;
int hit = 0;
float rpm;
long oldtime = millis();   
float dT;
int ledPin = 13;
int oldDigitalRead = 1;

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, RISING);
}

void isr(){
rev = 1;
dT = abs(millis())-oldtime;
oldtime = abs(millis());
}

void loop() {
delay(1000);
detachInterrupt(digitalPinToInterrupt(interruptPin));                      
rpm = (rev/dT)*60000;
rev = 0;
Serial.println(rpm);
attachInterrupt(digitalPinToInterrupt(interruptPin),isr,RISING);
}
