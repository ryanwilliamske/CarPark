int trigger = 2;
int echo = 3;
int beep = 11;
int beep_start = 100;
int min_distance = 5; 
float c = 0.0343;
//float c = 0.000001;
  
long tempo;
float space;

void setup(){
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(beep, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  tempo = pulseIn(echo, HIGH)/2;
  space = tempo * c;
  
  Serial.println("Distance  = " + String(space, 1) + " cm");
  
  if (space < beep_start){
    tone(beep, 1000);
    delay(40);
  }
  delay(50);
}