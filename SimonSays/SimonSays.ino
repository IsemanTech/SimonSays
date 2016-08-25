#include <cVector.h>
#include <EasyIO.h>

int levelMax = 4;

int chosenLed;

int bLed = 12;
int yLed = 11;
int rLed = 10;
int gLed = 9;

int bButton = 7;
int yButton = 6;
int rButton = 5;
int gButton = 4;

//flags
bool done1 = false;
bool correct;

EasyIO game;
cVector vecPins;
cVector userPins;

 
void setup() {
  //random number generator
  randomSeed(analogRead(0));
  
//Initialize Leds and push buttons 
game.initLed(bLed);
game.initLed(yLed);
game.initLed(rLed);
game.initLed(gLed);

game.initButton(bButton);
game.initButton(yButton);
game.initButton(rButton);
game.initButton(gButton);

//Using Serial for debug purposes
Serial.begin(9600);

//Intro to setup complete
game.turnAllOn(gLed, bLed);
delay(300);
game.turnAllOff(gLed, bLed);
}

void Level1()
{
  //First Challange (easy)
  if (!done1)
  {
    for (int count = 0; count < levelMax; count++)
    {
      delay(500);
      chosenLed = random(gLed, bLed + 1);
      //Serial.print(chosenLed);
      vecPins.push_back(chosenLed);
      digitalWrite(chosenLed, HIGH);
      delay(500);
      digitalWrite(chosenLed, LOW);
    }
      UserInput();
      clearLeds();
      Check();
      done1 = true;
  }
}

void UserInput()
{
  int count = 0;
 do
 {
    
    if (game.pushTurnOn(bLed, bButton))
    {
      count++;
      userPins.push_back(bLed);
      Serial.print(" ");
      Serial.print(bLed);
  } 
  if (game.pushTurnOn(yLed, yButton))
    {
      count++;
      userPins.push_back(yLed);
      Serial.print(" ");
      Serial.print(yLed);
    }
  if (game.pushTurnOn(rLed, rButton))
    {
      count++;
      userPins.push_back(rLed);
      Serial.print(" ");
      Serial.print(rLed);
    }
  if (game.pushTurnOn(gLed, gButton))
    {
      count++;
      userPins.push_back(gLed);
      Serial.print(" ");
      Serial.print(gLed);
    }
 }while(count < levelMax);
}

bool Check()
{
  //true until proven false
  correct = true;
  for (int i = 0; i < levelMax; i++)
  {
    if (vecPins[i]!= userPins[i])
    {
      correct = false;
      
    }
    
  }
  
  Serial.print(" ");
  Serial.print(correct);
 
  if (correct == true)
  {
    correctShow();
  }
  else
    wrongShow();
}
void clearLeds()
{
  game.turnAllOff(gLed, bLed);
}

void correctShow()
{
  game.turnAllOn(gLed, bLed);
  delay(300);
  game.turnAllOff(gLed, bLed);
  delay(300);
  game.turnAllOn(gLed, bLed);
  delay(300);
  game.turnAllOff(gLed, bLed);
  
}

void wrongShow()
{
  digitalWrite(gLed, HIGH);
  delay(150);
  digitalWrite(gLed, LOW);
  delay(150);
  digitalWrite(rLed, HIGH);
  delay(150);
  digitalWrite(rLed, LOW);
  delay(150);
  digitalWrite(yLed,HIGH);
  delay(150);
  digitalWrite(yLed, LOW);
  delay(150);
  digitalWrite(bLed, HIGH);
  delay(300);
  digitalWrite(bLed, LOW);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  Level1();


}
