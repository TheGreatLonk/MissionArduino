
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

// the setup function runs once when you press reset or power the board
const int buzzer = 48; //buzzer to arduino pin 9

const char* A = "._";
const char* B = "_...";
const char* C = "_._.";
const char* D = "_..";
const char* E = ".";
const char* F = ".._.";
const char* G = "--.";
const char* H = "....";
const char* I = "..";
const char* J = ".___";
const char* K = "_._";
const char* L = "._..";
const char* M = "__";
const char* N = "_.";
const char* O = "___";
const char* P = ".__.";
const char* Q = "__._";
const char* R = "._.";
const char* S = "...";
const char* T = "_";
const char* U = ".._";
const char* V = "..._";
const char* W = ".__";
const char* X = "_.._";
const char* Y = "_.__";
const char* Z = "__..";

const char* one = ".____";
const char* two = "..___";
const char* three = "...__";
const char* four = "...._";
const char* five = ".....";
const char* six = "_....";
const char* seven = "__...";
const char* eight = "___..";
const char* nine = "____.";
const char* zero = "_____";

float multiplier = 1;

/*
//wire1
int input = 23;
int output = 22;
//wire2
int input = 23;
int output = 22;
*/


int output[6] = {22, 26, 30, 34, 38, 42};

     //order is:W,G,R,B,O,Y
int State[6] = {0,0,0,0,0,0};

int input[6] = {23, 27, 31, 35, 39, 43};

String order[6] = {"W", "R", "O", "B", "Y", "G"};

void setup() {

  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  int time = millis();
  time = millis() - time;
  Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(WHITE);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzer, OUTPUT);

  int rannumber = random(1000, 9999);

  //pinMode(input, INPUT);
  //pinMode(output, OUTPUT);
  int pini;
  for (pini = 0; pini <= 5; pini++){
    pinMode(pini, INPUT);
  }
}



void blink(int time, int tonev) {
  digitalWrite(LED_BUILTIN, HIGH);// turn the LED on (HIGH is the voltage level)
  tone(buzzer, tonev);
  delay(time);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  noTone(buzzer);
  delay(250);
}

void morse(const char* line){
  int len = strlen(line);
  int number = 0; // start from the first character
  while (len > 0){
    if(line[number] == '.'){
      blink(300,500);
    }
    else if(line[number] == '_'){
      blink(1250,500);
    }

    number += 1;
    len -= 1;
  }
  delay(2000);
}

void Mword(const char* line){
   int len = strlen(line);
   int number = 0; // start from the first character

   char letter = 'A';
   while (len > 0){
    if (line[number] == 'A'){
    morse(A);
    }

    else if (line[number] == 'B'){
    morse(B);
    }
      
    else if (line[number] == 'C'){
    morse(C);
    }
    
    else if (line[number] == 'D'){
    morse(D);
    }
    
    else if (line[number] == 'E'){
    morse(E);
    }
    
    else if (line[number] == 'F'){
    morse(F);
    }
    
    else if (line[number] == 'G'){
    morse(G);
    }
    
    else if (line[number] == 'H'){
    morse(H);
    }
    
    else if (line[number] == 'I'){
    morse(I);
    }
    
    else if (line[number] == 'J'){
    morse(J);
    }
    
    else if (line[number] == 'K'){
    morse(K);
    }
    
    else if (line[number] == 'L'){
    morse(L);
    }
    
    else if (line[number] == 'M'){
    morse(M);
    }
    
    else if (line[number] == 'N'){
    morse(N);
    }
    
    else if (line[number] == 'O'){
    morse(O);
    }
    
    else if (line[number] == 'P'){
    morse(P);
    }
    
    else if (line[number] == 'Q'){
    morse(Q);
    }
    
    else if (line[number] == 'R'){
    morse(R);
    }
    
    else if (line[number] == 'S'){
    morse(S);
    }
    
    else if (line[number] == 'T'){
    morse(T);
    }
    
    else if (line[number] == 'U'){
    morse(U);
    }
    
    else if (line[number] == 'V'){
    morse(U);
    }
    
    else if (line[number] == 'W'){
    morse(W);
    }
    
    else if (line[number] == 'X'){
    morse(X);
    }
    
    else if (line[number] == 'Y'){
    morse(Y);
    }
    
    else if (line[number] == 'Z'){
    morse(Z);
    }

    number += 1;
    len -= 1;
  }
  delay(4000);
}


uint8_t i=0;


const unsigned long duration = 600000;

void loop() {
  //Logic Area **********************************************************************************************************************************************************

  int long remainingtime = duration - (millis()*multiplier);

  int minutes = remainingtime / 60000;
  unsigned int seconds = (remainingtime / 1000) % 60;

  int i;
  int pullcount = 0;

  

  for (i = 0; i <= 5; i++){
    digitalWrite(output[i], HIGH); 
    State[i] = digitalRead(input[i]);
    digitalWrite(output[i], LOW);
  }

  //order is:G,R,B,O,Y
  // puzzle order: R,O,B,Y,G


  //the most atrocious if statement chain known to mankind**************************************************************************************************************

  
    if (State[2] == 0){
       if (State[4] == 0){
          if (State[3] == 0){
            if (State[5] == 0){
              if (State[1] == 0){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Next Code: 0112"); //pin for next puzzle
                blink(1000,800);
                delay(9000);
                lcd.clear();
  }
  }
  else if ((State[1] == 0)){
     multiplier += .5; blink(1000,200);
  }
  }
  else if ((State[1] == 0) || (State[5] == 0)){
     multiplier += .5; blink(1000,200);
  }
  }
  else if ((State[1] == 0) || (State[3] == 0) || (State[5] == 0)){
     multiplier += .5; blink(1000,200);
  }
  }else if ((State[1] == 0) || (State[3] == 0) || (State[4] == 0) || (State[5] == 0)){
     multiplier += .5; blink(1000,200);
  }
  


  //Print Area **********************************************************************************************************************************************************

  if (seconds < 10){
    lcd.setCursor(10, 1);
    lcd.print("0");

    lcd.setCursor(11, 1);
    lcd.print(seconds);

    
  }else{
    lcd.setCursor(10, 1);
    lcd.print(seconds);
  }

  lcd.setCursor(0, 1);
  lcd.print("Timer:");

  lcd.setCursor(7, 1);
  lcd.print(minutes);

  lcd.setCursor(9, 1);
  lcd.print(":");

  
  for (i = 0; i <= 5; i++){
    lcd.setCursor(i, 0);
    lcd.print(State[i]);
  }


  //End Code ************************************************************************************************************************************************************
  if (remainingtime <= 0){
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MISSION: FAILED");
      blink(60000,500);
      lcd.clear();
  }




  //Button interface ****************************************************************************************************************************************************

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_SELECT) {
      lcd.print("error code:");

      lcd.setCursor(12, 0);
      lcd.print(random(1000, 9999));
      
      lcd.setCursor(0, 1);
      lcd.print("Fixing error");
      Mword("ROBYG"); //Red wire, Oarnge wire, Black wire, Yellow wire, Green wire.
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fixed error");
      delay(5000);
      lcd.clear();
    }
  }

  
}
