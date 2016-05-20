 //Simon Says
 //led pin
 int ledPin;
 //Buttons
int blueButton = 7;
int yellowButton = 6;
int redButton = 5;
int greenButton = 4;
//times the leds will blink
int blinkTimes;
//button states
int blue;
int yellow;
int red;
int green;
//lets try setting a flag to stop the blinking
bool done = false;
bool flag = false;
//Check User Input
bool check1 = false;
//Array to collect the led pins randomly generated
const int MAX_PINS = 3;
int pins[MAX_PINS];
//Array to collect the leds the user chose
const int MAX_INPUTS = 3;
int userPins[MAX_INPUTS];

void setup() {
  //random number generator
  randomSeed(analogRead(0));
//LEDS
for (int ledPin = 10; ledPin < 14; ledPin++)
{
  pinMode(ledPin, OUTPUT);
}
//Set push buttons to input
pinMode(blueButton, INPUT);
pinMode(yellowButton, INPUT);
pinMode(redButton, INPUT);
pinMode(greenButton, INPUT);

//Signal that the game has started
for (ledPin = 10; ledPin < 14; ledPin++)
{ 
 digitalWrite(ledPin, HIGH);
 delay(50);
 digitalWrite(ledPin, LOW);
}
delay(1000);
//Serial port test
//Serial.begin(9600);
}
void Blue_Button()
{
  ledPin = 13;
  blue = digitalRead(blueButton);
  //If blue button is pressed
  if (blue == HIGH)
  {
    //turn it on
    digitalWrite(ledPin, HIGH);
    //delay(50);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
}
void Yellow_Button()
{
  ledPin = 12;
  yellow = digitalRead(yellowButton);
  if (yellow == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    //delay(50);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
void Red_Button()
{
  ledPin = 11;
  red = digitalRead(redButton);
  if (red == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
void Green_Button()
{
  ledPin = 10;
  green = digitalRead(greenButton);
  if (green == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
//Not sure if this will work
bool Check1()
{
  for (int i = 0; i < 4; i++)
  {
    if (pins[i] != userPins[i])
    {
      return false; 
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
//First Challange (easy)
if (!done)
{
  for (blinkTimes = 0; blinkTimes < 4; blinkTimes++)
  {
    ledPin = random(10, 14);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    //store pin numbers into the array
    pins[blinkTimes] = ledPin;
  }
  done = true;
}
do
{
  Blue_Button();
  Yellow_Button();
  Red_Button();
  Green_Button();
}while(!check1);

/*
//Grab the status of the blue button
blue = digitalRead(blueButton);
if (blue == HIGH)
{
  ledPin = 13;
  digitalWrite(ledPin, LOW);
}
else if (blue == LOW)
  {
   ledPin = 13;
   digitalWrite(ledPin, LOW);
  }
  */
}

