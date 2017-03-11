//Author: Iseman Johnson last updated: 02/11/2017
#include <cVector.h>
#include <EasyIO.h>

const int LevelMax = 11;
int level = 1;


int chosenLed;

int bLed = 12;
int yLed = 11;
int rLed = 10;
int gLed = 9;

int bButton = 7;
int yButton = 6;
int rButton = 5;
int gButton = 4;

//speaker
int spin = 3;

//flags
bool done1 = false;
bool correct;
//Tones E Note


EasyIO game;
cVector ranPins;
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

void SimonSays()
{
  //First Challange (easy)
  while (level < LevelMax)
  {
    for (int count = 0; count < level; count++)
    {
      delay(500);
      chosenLed = random(gLed, bLed + 1);
      //Serial.print(chosenLed);
      ranPins.push_back(chosenLed);
      digitalWrite(chosenLed, HIGH);
      if (chosenLed == bLed)
      {
        tone(spin, 200, 50);
      }
      if (chosenLed == yLed)
      {
        tone(spin, 250, 50);
      }
      if (chosenLed == rLed)
      {
        tone(spin, 300, 50);
      }
      if (chosenLed == gLed)
      {
        tone(spin, 350, 50);
      }
      //tone(spin, 390, 50);
      delay(500);
      noTone(spin);
      digitalWrite(chosenLed, LOW);
    }
      UserInput();
      clearLeds();
      delay(150);
      Check();
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
      tone(spin, 200, 50);
      
  } 
  if (game.pushTurnOn(yLed, yButton))
    {
      count++;
      userPins.push_back(yLed);
      Serial.print(" ");
      Serial.print(yLed);
      tone(spin, 250, 50);
    }
  if (game.pushTurnOn(rLed, rButton))
    {
      count++;
      userPins.push_back(rLed);
      Serial.print(" ");
      Serial.print(rLed);
      tone(spin, 300, 50);
    }
  if (game.pushTurnOn(gLed, gButton))
    {
      count++;
      userPins.push_back(gLed);
      Serial.print(" ");
      Serial.print(gLed);
      tone(spin, 350, 50);
    }
    delay(150);
    noTone(spin);
 }while(count < level);
}

bool Check()
{
  //true until proven false
  correct = true;
  for (int i = 0; i < level; i++)
  {
    if (ranPins[i]!= userPins[i])
    {
      correct = false;
      
    }
    
  }
  
  Serial.print(" ");
  Serial.print(correct);
 
  if (correct == true)
  {
    correctShow();
    level++;
  }
  else
  {
    wrongShow();
    level = 100;
  }
}
void clearLeds()
{
  game.turnAllOff(gLed, bLed);
  userPins.clearAll();
  ranPins.clearAll();
}

void correctShow()
{
  game.turnAllOn(gLed, bLed);
  tone(spin, 780, 90);
  delay(200);
  game.turnAllOff(gLed, bLed);
  noTone(spin);
  delay(200);
  game.turnAllOn(gLed, bLed);
  tone(spin, 780, 90);
  delay(200);
  game.turnAllOff(gLed, bLed);
  noTone(spin);
  
}

void wrongShow()
{
  digitalWrite(gLed, HIGH);
  tone(spin, 250);
  delay(150);
  digitalWrite(gLed, LOW);
  noTone(spin);
  delay(150);
  digitalWrite(rLed, HIGH);
  tone(spin, 200);
  delay(150);
  digitalWrite(rLed, LOW);
  noTone(spin);
  delay(150);
  digitalWrite(yLed,HIGH);
  tone(spin, 150);
  delay(150);
  digitalWrite(yLed, LOW);
  noTone(spin);
  delay(150);
  digitalWrite(bLed, HIGH);
  tone(spin, 100);
  delay(300);
  digitalWrite(bLed, LOW);
  noTone(spin);
}
void showlevel()
{
  /*print the level number to the lcd screen to show the player*/
}
void loop() 
{
  // put your main code here, to run repeatedly:
  SimonSays();
}
