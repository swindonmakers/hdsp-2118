
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

void write_to_display(char addr, char data) {
  digitalWrite(A0Pin, (addr>>0)&1);
  digitalWrite(A1Pin, (addr>>1)&1);
  digitalWrite(A2Pin, (addr>>2)&1);
  // A3, A4, and FL are currently hard-wired; all writes will go to the character ram.
  
  digitalWrite(CEPin, LOW);
  digitalWrite(WRPin, LOW);
  
  for (char i=0; i<8; i++)
   digitalWrite(DPin[i], (data>>i)&1);
  digitalWrite(WRPin, HIGH);
  digitalWrite(CEPin, HIGH);  
}

void setup() {
    // Configure output pins:
  pinMode(CEPin, OUTPUT);
  pinMode(WRPin, OUTPUT);
  pinMode(A0Pin, OUTPUT);
  pinMode(A1Pin, OUTPUT);
  pinMode(A2Pin, OUTPUT);
   for(int i = 0; i < 8; i++) { pinMode(DPin[i], OUTPUT);}
  pinMode(LedPin, OUTPUT);

  write_to_display(0, '@');
  write_to_display(1, 's');
  write_to_display(2, 'n');
  write_to_display(3, 'h');
  write_to_display(4, 'a');
  write_to_display(5, 'c');
  write_to_display(6, 'k');
  write_to_display(7, '!');
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
