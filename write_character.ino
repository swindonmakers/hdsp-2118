
// constants won't change. Used here to 
// set pin numbers:

const int CEPin =  2;      // the number of the chip enable pin
const int WRPin =  3;

const int A0Pin = 12;
const int A1Pin =  0; // low
const int A2Pin =  1; // high

const int DPin[8] = {4,5,6,7,8,9,10,11};
const int TestDPin =  6; // high D pin

const int LedPin = 13;
int LedState = LOW;
// Access control word register - A4 high, A3 low
// Reset - reset pin hig

void flipLed();

void setup() {
    // Configure output pins:
  pinMode(CEPin, OUTPUT);
  pinMode(WRPin, OUTPUT);
  pinMode(A0Pin, OUTPUT);
  pinMode(A1Pin, OUTPUT);
  pinMode(A2Pin, OUTPUT);
   for(int i = 0; i < 8; i++) { pinMode(DPin[i], OUTPUT);}
  pinMode(LedPin, OUTPUT);

//  flipLed();
  digitalWrite(A0Pin, LOW);
  digitalWrite(A1Pin, LOW);
  digitalWrite(A2Pin, LOW);
//  flipLed();
    // ChipEnable Pin LOW
  digitalWrite(CEPin, LOW);
//  delayMicroseconds(1);
    // Write Pin LOW
  digitalWrite(WRPin, LOW);
//  flipLed();
  
  digitalWrite(DPin[0], HIGH);
  digitalWrite(DPin[1], HIGH);
  digitalWrite(DPin[2], LOW);
  digitalWrite(DPin[3], LOW);
  digitalWrite(DPin[4], HIGH);
  digitalWrite(DPin[5], LOW);
  digitalWrite(DPin[6], HIGH);
  digitalWrite(DPin[7], LOW);
    /*
  for(int i=0; i<8; i++) {
     if(i==TestDPin) {
        digitalWrite(DPin[i], HIGH);
     } else {
        digitalWrite(DPin[i], LOW);
     }
  }
    */
  
//  flipLed();
  // Done writing
  digitalWrite(WRPin, HIGH);
//  delayMicroseconds(1);
  digitalWrite(CEPin, HIGH);  
      
}

void loop()
{
}

void flipLed() {
    if(LedState == LOW) {
        LedState = HIGH;
    } else {
        LedState = LOW;
    }
    
    digitalWrite(LedPin, LedState);
}
