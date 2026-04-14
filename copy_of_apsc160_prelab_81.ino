// --------------------------------------------------------------
// APSC 160 - Flashlight Controller (Starter Code)
// Complete this exercise before lab 8
// --------------------------------------------------------------

const int BUTTON_PIN = 2;   // pushbutton
const int LED1 = 13; // LED1
const int LED2 = 9; // LED2

// Mode variables
int mode = 0;

// Button state tracking
bool lastButtonState = LOW;
unsigned long lastPressTime = 0;
bool waitingForSecondClick = false;

const unsigned long DOUBLE_CLICK_MAX = 500;   // maximum time (ms) allowed between clicks

// Emergency mode timing
unsigned long lastBlinkTime = 0;
bool blinkState = false;
const unsigned long BLINK_HALF_PERIOD = 500;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop() {
    unsigned long now = millis();

    // ---------------------------
    // 1. Detect button press (LOW -> HIGH); set appropriate mode
    // ---------------------------
    bool buttonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == LOW && buttonState == HIGH) {
        // TODO: handle click timing and detect double-clicks
      if(waitingForSecondClick){
        if(now-lastPressTime<=DOUBLE_CLICK_MAX){
          if(mode+1>3){
            mode = 0;
          }
          else{
          	mode++;
          }
        }
      }
      else{
        waitingForSecondClick = true;
        lastPressTime = now;
      }
    }

    // timeout: if too much time passed after first click, cancel
    if (now-lastPressTime > DOUBLE_CLICK_MAX) {
      waitingForSecondClick = false;}
    lastButtonState = buttonState;

    // ---------------------------
    // 2. Control LEDs depending on current mode
    // ---------------------------
    if (mode == 0) {
        // TODO: implement OFF mode
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
    }
    else if (mode == 1) {
        // TODO: implement LOW mode
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
    }
    else if (mode == 2) {
        // TODO: implement HIGH mode
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
    }
    else if (mode == 3) {
        // TODO: implement EMERGENCY mode using millis() blinking
      now = millis();
      
      if(blinkState){
          digitalWrite(LED1, HIGH);
      	  digitalWrite(LED2, LOW);
      }
      else{
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, HIGH);
      }
      
      if(now-lastBlinkTime > BLINK_HALF_PERIOD){
        blinkState =  !blinkState;
        lastBlinkTime = now;
      }
    }
}
