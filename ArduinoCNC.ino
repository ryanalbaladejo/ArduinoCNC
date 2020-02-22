#define EN        8 
#define X_DIR     5
#define X_STP     2

int delayTime=1000; //Delay between each pause (uS)
long int stps=50;// microsteps per revolution with 1/32 microstepping
const int limitPin = 9; //enable limitPin
boolean touched = false;
void step(boolean dir, byte dirPin, byte stepperPin, long int steps)

{

  digitalWrite(dirPin, dir);

  //delay(100);

  for (long int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime);

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(limitPin, INPUT_PULLUP);
  digitalWrite(EN, LOW);
}

void loop() {
    Serial.println(digitalRead(limitPin));
    if (touched==true && digitalRead(limitPin) == HIGH) {
      //delay(200);
      step(true, X_DIR, X_STP, stps);
     //touched = false;
    }
    else if(digitalRead(limitPin) == LOW) //clicked
    {
     touched=true;
       Serial.println("touched");
       delay(1000);
    } else if (digitalRead(limitPin) == HIGH){
     step(false, X_DIR, X_STP, stps); 
    //  Serial.println("elseif");
    } else {
      touched=false;
    //  Serial.println("else");
    } 
}
