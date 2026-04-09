/*	   	 		  	   	 			 	  	 		 	*
 * ADD YOUR STANDARD SUBMISSION INFORMATION HERE	  	*
 * NAME:  SIMRANJEET KAUR				   		 	 	 	   	  	   	*
 * EMAIL: skaur711@student.ubc.ca												*
 * COOURSE AND LAB SECTION: apsc 160 L2P							*
 * DATE: 	April 2, 2026  		 		 	  	   	 	  	   	 	*
 *	purpose: to display the letters of the name  	   	   	 	 			   	  		   	 	 	*/


//symbolic constants for INPUT/OUTPUT pins
int const A = 11;
int const B = 10;
int const C = 7;
int const D = 8;
int const E = 9;
int const F = 12;
int const G = 13;
int const H = 6;
int const SW = 5;


// define any function(s), constants required to implement your program
int const waitTime = 1000;  //to wait for one second
int const pauseTime = 500; //to pause for 0.5 second
int currentState = LOW; // tp keep track of the switch state

// initialization
  
  //purpose to clear the display
//return none
//parameter none
  void clearDisplay(void){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
  }
  
  // purpose: to display the letter S
//return none
//parameter none
  void s(void){
  digitalWrite(A, HIGH);
 digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
	}

// purpose: to display the letter I
//return none
//parameter none
  void i(void){
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
	}

// purpose: to display the letter M
//return none
//parameter none
  void m(void){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
	}

// purpose: to display the letter R
//return none
//parameter none
  void r(void){
   digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(E, HIGH);
   digitalWrite(B, HIGH);
	}

// purpose: to display the letter A
//return none
//parameter none
  void a(void){
   digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(E, HIGH);
   digitalWrite(B, HIGH);
	}

// purpose: to display the letter N
//return none
//parameter none
  void n(void){
   digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
	}

// purpose: to display the letter J
//return none
//parameter none
  void j(void){
    digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
	}

// purpose: to display the letter E
//return none
//parameter none
  void e(void){
    digitalWrite(A, HIGH);
 	digitalWrite(F, HIGH);
  	digitalWrite(G, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
	}


//purpose: function to display letters depending on the value of count
//parameter: count type int
//return none
void displayLetters(int count){
  if(count == 1){
    s();
  }
  else if(count == 2){
    i();
  }
  else if(count == 3){
    m();
  }
  else if(count == 4){
    r();
  }
  else if(count == 5){
    a();
  }
  else if(count == 6){
    n();
  }
  else if(count == 7){
    j();
  }
  else if(count == 8){
    e();
  }
}


void setup(void){
  
  /* digital I/O pins mode setup */
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(SW, INPUT);
  
  Serial.begin(9600);
  
  /* additional code as needed */
}

//main loop to display the letters
void loop(void){
	currentState = digitalRead(SW);
  
  //var to keep track of the variable number
  static int count = 1;
  
  // if the switch is to the right then display the numbers in foward order
  if(currentState == HIGH && count <=8){
   	clearDisplay();//clear the display
    delay(pauseTime); //pause for 0.5 seconds
    displayLetters(count); // call the function ot display the letter
    delay(waitTime);//display letter for 1 second
    clearDisplay();//clear the display
    
    //Serial.println(count);
    //Serial.println(currentState);
    //Serial.println(" this is 1");
    
    count++;
    
  }//else to make sure the count doesn't go above 8
  else if(currentState == HIGH){
    count = 1;
  }
  else{
    clearDisplay();
  }

  // if the switch is to the left display the number in reverse order
  currentState = digitalRead(SW);
  if(currentState == LOW && count > 0){
   	clearDisplay();//clear the display
    delay(pauseTime);//pause for 0.5 seconds
    displayLetters(count);// call the function ot display the letter
    delay(waitTime);//display letter for 1 second
    clearDisplay();//clear the display
    
    Serial.println(count);
    Serial.println(currentState);
    Serial.println(" this is 2");
    
    count--;
  }//else to make sure the count doesn't go below 1
  else if(currentState == LOW){
  	count = 8;
  }
else{
    clearDisplay();
  }
  
}


