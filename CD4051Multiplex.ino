//8 channels cd4051 Library Free changes by: S.R.Marashi   srmarashi@yahoo.com
// Here is pinout for HW-529 CD4051 MultiPlexer Digital To analog
// S0 --> Arduino Digital 3
// S1 --> Arduino Digital 4
// S2 --> Arduino Digital 5
// E --> Arduino Digital 2
// Z --> Arduino analog A0
// VEE/GND --> Arduino GND (Connect Both of them to GND)
// VCC --> Arduino +5V
// Y0 to Y7 --> Analog Extended Pins

const byte ENPIN = 2; //Enable pin
const byte APIN = 3; //S0
const byte BPIN = 4; //S1
const byte CPIN = 5; //S2

// an analog pin need to Cycle Digital Pins
const byte SPIN = A0;

void setup() {

  //  pins out and LOW
  pinMode(APIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  pinMode(CPIN, OUTPUT);
  digitalWrite(APIN, LOW);
  digitalWrite(BPIN, LOW);
  digitalWrite(CPIN, LOW);

  // Enable pin should have Voltage for activating module
  pinMode(ENPIN, OUTPUT);
  digitalWrite(ENPIN, LOW);

  Serial.begin(9600);
  Serial.println("1 analog and 3 Digital pins give 7 ANALOG Low precision PIN ");
}

void loop()
{

  // for example pin0 and pin7 will read continusely and will print out analog Result Valuue
  Serial.println(CycleRecall(7));
  Serial.println(CycleRecall(0));
  delay(100);
}


// reading function for the CD4051B
int CycleRecall(byte channel) {

  digitalWrite(APIN, bitRead(channel, 0));
  digitalWrite(BPIN, bitRead(channel, 1));
  digitalWrite(CPIN, bitRead(channel, 2));
  //Cyle ReCall
  return analogRead(SPIN);
}
