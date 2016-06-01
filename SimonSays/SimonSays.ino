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
//hold boolean
bool ch;
//Array to collect the led pin numbers
const int MAX_PINS = 4;
int pins[MAX_PINS];
//Array to collect the button numbers
const int MAX_USER_LEDS = 4;
int userLeds[MAX_USER_LEDS];
//variable to hold index user led number
int x = 0;
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
Serial.begin(9600);
}
void Blue_Button()
{
  ledPin = 13;
  blue = digitalRead(blueButton);
  //If blue button is pressed
  if (blue == HIGH)
  {
    //for contact balance
    delay(150);
    //turn it on
    digitalWrite(ledPin, HIGH);
    //collect led user chose
    userLeds[x] = ledPin;
    //Serial.print(x);
    x++;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    //delay(100);
  }
  
}
void Yellow_Button()
{
  ledPin = 12;
  yellow = digitalRead(yellowButton);
  if (yellow == HIGH)
  {
    delay(150);
    digitalWrite(ledPin, HIGH);
    userLeds[x] = ledPin;
    //Serial.print(x);
    x++;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    //delay(100);
  }
}
void Red_Button()
{
  ledPin = 11;
  red = digitalRead(redButton);
  if (red == HIGH)
  {
    delay(150);
    digitalWrite(ledPin, HIGH);
    userLeds[x] = ledPin;
    //Serial.print(x);
    x++;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    //delay(100);
  }
}
void Green_Button()
{
  delay(150);
  ledPin = 10;
  green = digitalRead(greenButton);
  if (green == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    userLeds[x] = ledPin;
    //Serial.print(x);
    x++;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    //delay(100);
  }
}
//check user input NOT WORKING
bool check1()
{
  bool correct = true;
  for (int i = 0; i < 4; i++)
  {
    if (pins[i] != userLeds[i])
    {
      correct = false;
      return correct;
    }
  }
  return correct;
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
    delay(1000);
    //store pin numbers into the array
    pins[blinkTimes] = ledPin;
  }
  done = true;
}
  Blue_Button();
  Yellow_Button();
  Red_Button();
  Green_Button();
//Check if user input is correct
if (x >= 4)
{
  ch = check1();
  if (ch == false)
  {
    Serial.print("Wrong!");
  }
  else
  {
    Serial.print("Correct!");
  }
  //Print out 1 if correct and 0 if wrong
 // Serial.print(ch);
  x = 0;
}
}
