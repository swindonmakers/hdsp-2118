
// constants won't change. Used here to 
// set pin numbers:

const int CEPin =  2;      // the number of the chip enable pin
const int WRPin =  3;

const int A3Pin =  0; // low
const int A4Pin =  1; // high

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
  pinMode(A3Pin, OUTPUT);
  pinMode(A4Pin, OUTPUT);
  for(int i = 0; i < 8; i++) { pinMode(DPin[i], OUTPUT);}
  pinMode(LedPin, OUTPUT);

  flipLed();
    // Access ControlWord:
  digitalWrite(A3Pin, LOW);
  digitalWrite(A4Pin, HIGH);
  flipLed();
//  delayMicroseconds(1);
    // ChipEnable Pin LOW
  digitalWrite(CEPin, LOW);
//  delayMicroseconds(1);
    // Write Pin LOW
  digitalWrite(WRPin, LOW);
  flipLed();
  
  for(int i=0; i<8; i++) {
     if(i==TestDPin) {
        digitalWrite(DPin[i], HIGH);
     } else {
        digitalWrite(DPin[i], LOW);
     }
  }
  
  flipLed();
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
