//define constants etc.

#define LED_LOSE 13
#define LEDR 12
#define LEDY 11
#define LEDB 10
#define LEDG 9
#define LED_WIN 8

#define pb_red 7
#define pb_yellow 6
#define pb_blue 5
#define pb_green 4

int mode = 0;
int pressedButton = 0;
int LastpressTime = 0;
int newgameTime = 0;
int ledOnTime = 0;
int activeled = 0;

int waitTime = 2000;
int ledWaitTime = 1000;


bool newgame = true;

//variables to store the button states

//define functions prototypes

//function to reset the game for a new game

void reset(void){
  //turning off all the leds
  Serial.println("reset ran");
  digitalWrite(LED_LOSE, LOW);
  digitalWrite(LED_WIN, LOW);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDG, LOW);
  
  //startingn the new game
  newgame = true;
}

//initialization
void setup()
{
  Serial.begin(9600);
   //configure pin modes (inputs, outputs) etc.
  pinMode(pb_red, INPUT);
  pinMode(pb_yellow, INPUT);
  pinMode(pb_blue, INPUT);
  pinMode(pb_green, INPUT);
  
  pinMode(LED_LOSE,OUTPUT);
  pinMode(LEDR,OUTPUT);
  pinMode(LEDY,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LED_WIN,OUTPUT);
  
  randomSeed(analogRead(A0));
  
}


//main program loop
void loop()
{
  int now = millis();
  if(newgame){
     activeled =  random(9, 13);
    newgame = false;
    newgameTime = now;
    digitalWrite(activeled, HIGH);
    Serial.print("game started");
  }
  
  if(now-newgameTime <= waitTime){
    
    //Serial.println("checking which button is pressed");
    
     //checking the current state of the leds 
    int redState = digitalRead(pb_red);
    int yellowState = digitalRead(pb_yellow);
    int blueState = digitalRead(pb_blue);
    int greenState = digitalRead(pb_green);
    
    //checkign if the red button is on
    if(redState == HIGH ){
      Serial.println("red is pressed");
      pressedButton = LEDR;
    }
    //checking if the yellow led is on
    else if(yellowState == HIGH ){
      Serial.println("yellow is pressed");
       pressedButton = LEDY;
    }
    //checking if the blue led is on
    else if(blueState == HIGH ){
      Serial.println("blue is pressed");
       pressedButton = LEDB;
    }
    //checking if the green led is on
    else if(greenState == HIGH ){
      Serial.println("green is pressed");
       pressedButton = LEDG;
    }
    
    
  }//the button check ends here
  else{//if it has been more than 2secs since the led color displayed
    Serial.println("value of the pressed button");
  	Serial.println(pressedButton);
    Serial.println("vlaue of active led");
    Serial.println(activeled);
    now = millis();
    
    //checking if no button was pressed
    if(pressedButton==0){
      
      Serial.println("no button was pressed");
      digitalWrite(activeled, LOW);
      if(digitalRead(LED_LOSE)== LOW){
        digitalWrite(LED_LOSE, HIGH);
        ledOnTime = now;
      }
      if(now -ledOnTime >= ledWaitTime){
       reset();
      }
      
    }
    //checking if the right button was pressed
    else if(pressedButton == activeled){
      
      Serial.println("right button was pressed. You Won!");
      digitalWrite(activeled, LOW);
      
      if(digitalRead(LED_WIN)== LOW){
        digitalWrite(LED_WIN, HIGH);
        ledOnTime = now;
      }
      if(now -ledOnTime >= ledWaitTime){
       reset();
      }
      
    }
    //if the wrong button was pressed
    else{
      
      Serial.println("wrong button was pressed");
      digitalWrite(activeled, LOW);
      if(digitalRead(LED_LOSE)== LOW){
        digitalWrite(LED_LOSE, HIGH);
        ledOnTime = now;
      }
      if(now -ledOnTime >= ledWaitTime){
       reset();
      }
      
    }
    
  }

  
  
}//the loop()ends here