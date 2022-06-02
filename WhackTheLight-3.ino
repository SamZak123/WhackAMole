
//declares color locations on the board
const int red = 13;
const int blue = 12;
const int green = 11;
const int yellow = 10;
const int white = 9;

//declares button locations on board
const int but1 = 6;
const int but2 = 5;
const int but3 = 4;
const int but4 = 3;
const int but5 = 2;

//creates random number, initializes score to 0, sets game boolean to true, and creates tick (what is used to end game)
long randnumber;
int score = 0;
bool game = true;  
int tick;

//setup function 
void setup() {
  //creates random number up to that point
  randomSeed(analogRead(0));
  
  // declare the LED pins as outputs 
  pinMode(red, OUTPUT); // red
  pinMode(blue, OUTPUT); // blue
  pinMode(green, OUTPUT); // green
  pinMode(yellow, OUTPUT); // yellow
  pinMode(white, OUTPUT); // white

  //declare buttons as inputs 
  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);
  pinMode(but5, INPUT_PULLUP);

//initializes the serial connection at 9600 bits per second.
  Serial.begin(9600);
}

void loop() {
  
  randnumber = random(50);      // random number is set to print a number from 0 to 49 
  if(game == true){ // sets game to be true so game starts (if statement) 

//Displays at start
    Serial.println ("Hello welcome to Whack The Light!"); 
    delay(2000);
    Serial.println ("There are three levels to this game, with each level getting progressively harder.");
    delay(3000);
    Serial.println ("In each level, 10 lights will flash and you must press the button before the light turns off."); 
    delay(4000);
    Serial.println("Each button press for its respective light will grant the player 10 points for a maximum score of 300 points.");
    delay(4500);   
    Serial.println("Good luck! The game will start in "); 
    delay(1000); 
    Serial.println("3... ");
    delay(1000);
    Serial.println("2... ");
    delay(1000);
    Serial.println("1...");
    delay (1000);
//Does beginning light sequence 
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(yellow,HIGH);
  delay(1000);
  digitalWrite(white,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  delay(500);
  digitalWrite(blue,LOW);
  delay(500);
  digitalWrite(green,LOW);
  delay(500);
  digitalWrite(yellow,LOW);
  delay(500);
  digitalWrite(white,LOW);
  delay(500);

   //************************************************************ Level 1 ********************************************************
      Serial.println ("-----------------------------------------------------Level 1-------------------------------------------------------------"); 
   //for loop that loops 10 times for the ten flashes per level  
   for (int i=0; i < 10; i++){  
      randnumber = random(50);
   //random number 0 - 9 = red, 10-19 = blue, 20-29 = green, 30-39 = yellow, 40-49 white 
      if (randnumber < 10){      
        digitalWrite(red, HIGH); //turn the red LED on
        // if button red is pressed and button one is pressed, then add 10 to score and print score, and turn off all other lights 
        if (digitalRead(red) == HIGH){       
          delay(1000);    //delay one second 
          if(digitalRead(but1) == LOW){
            score += 10;        
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  // turn the blue LED off
        digitalWrite(green, LOW);  // turn the green LED off
        digitalWrite(yellow, LOW);  // turn the yellow LED off
        digitalWrite(white, LOW);   //turn the white LED off 
        delay (100);                //delay set to 1/10th of a second 
        digitalWrite(red, LOW); //turn the red LED off after all others
 //same thing except for blue light within an else if 
      } else if (randnumber < 20){ 
        digitalWrite(red, LOW);  //turn the red LED off
        digitalWrite(blue, HIGH); // turn the blue LED on 
        if (digitalRead(blue) == HIGH){
          delay(1000);                 
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE:  ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW);  
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(blue, LOW); 
 //same thing except for green light 
      } else if (randnumber < 30) {
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, HIGH);  
        if ((digitalRead(green)== HIGH)){ 
          delay(1000);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW); 
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(green, LOW); 
 // same thing except for yellow 
      } else if (randnumber < 40){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, HIGH); 
        if ((digitalRead(yellow)==HIGH)){
          delay(1000);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println(score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (100);
        digitalWrite(yellow, LOW); // turn the yellow LED off
  //same thing except for white 
      } else if (randnumber < 50){
        digitalWrite(red, LOW); //turn the red LED off
        digitalWrite(blue, LOW); // turn the blue LED off
        digitalWrite(green, LOW); // turn the green LED off
        digitalWrite(yellow, LOW); // turn the yellow LED off 
        digitalWrite(white, HIGH); //turn white on
        if ((digitalRead(white)==HIGH)){
          delay(1000);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println(score);
            Serial.println("****************");
          }
        }
        delay (100);
        digitalWrite(white, LOW); 
      }
      delay (100);
      tick = tick + 1; //At the end of each light flash, regardless of the color, tick is increased by one
   }
   
   //************************************************************* Level 2 ********************************************************
    Serial.println ("-----------------------------------------------------Level 2 ------------------------------------------------------------"); 
   //for loop that just loops twice just to do flash for change in level --> 2 times for level 2
    for(int i = 0; i<2; i++){
        //all lights turn on at once
        digitalWrite(red, HIGH); 
        digitalWrite(blue, HIGH); 
        digitalWrite(green, HIGH); 
        digitalWrite(yellow, HIGH); 
        digitalWrite(white, HIGH); 
        delay (300); //delay so flashes are visible
        //turn all lights off
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, LOW);
        delay(300); //delay so flashes are visible
    }
//level 2 for loop (10 flashes) 
   for (int i=0; i < 10; i++){
      randnumber = random(50);
//lvl 2 red flash, turns on red, then turns off all other lights after, and then the red off 
      if (randnumber < 10){
        digitalWrite(red, HIGH); 
        if (digitalRead(red) == HIGH){
          delay(800);        //lower delay from level 1 so gives user less time for press 
          if(digitalRead(but1) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  
        digitalWrite(green, LOW);  
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (75);    //lower delay so light turns off sooner
        digitalWrite(red, LOW); 
 //lvl 2 blue light flash same concept
      } else if (randnumber < 20){
        digitalWrite(red, LOW);  
        digitalWrite(blue, HIGH); 
        if (digitalRead(blue) ==HIGH){
          delay(800);
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW);  
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (75);
        digitalWrite(blue, LOW); 
//lvl 2 green flash
      } else if (randnumber < 30) {
        digitalWrite(red, LOW);  
        digitalWrite(blue, LOW);  
        digitalWrite(green, HIGH); 
        if ((digitalRead(green)== HIGH)){
          delay(800);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (75);
        digitalWrite(green, LOW); 
//lvl 2 yellow flash
      } else if (randnumber < 40){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, HIGH); 
        if ((digitalRead(yellow)==HIGH)){
          delay(800);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (75);
        digitalWrite(yellow, LOW); 
// lvl 2 white flash
      } else if (randnumber < 50){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, HIGH);
        if ((digitalRead(white)==HIGH)){
          delay(800);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        delay (75);
        digitalWrite(white, LOW); 
      }
      delay (75);
      tick = tick + 1; //again, adds one to tick regardless of what light pressed at the end of for loop outside the big if statement
   }


   //************************************************************Level 3********************************************************
    Serial.println ("-----------------------------------------------------Level 3-------------------------------------------------------------"); 
   //for loop with same concept as before to show change in level (3 flashes) 
    for(int i = 0; i< 3; i++){
        digitalWrite(red, HIGH); //turn the Red LED on 
        digitalWrite(blue, HIGH); // turn the blue LED on 
        digitalWrite(green, HIGH); // turn the green LED on 
        digitalWrite(yellow, HIGH); // turn the yellow LED on
        digitalWrite(white, HIGH);  //turn the white LED on 
        delay (300);               // delay 4/10th of a second so you can see the flash --> change from all on to all off
        digitalWrite(red, LOW); //turn the red off
        digitalWrite(blue, LOW); // turn the blue off
        digitalWrite(green, LOW); // turn the green off
        digitalWrite(yellow, LOW); // turn the yellow LED off
        digitalWrite(white, LOW);  //turn the white off
        delay(300); //delay again 
        }
//for loop for 10 flashes for lvl 3
   for (int i=0; i < 10; i++){
      randnumber = random(50);
//lvl 3 red
      if (randnumber < 10){
        digitalWrite(red, HIGH); 
        if (digitalRead(red) == HIGH){
          delay(750);  //even lower for level 3
          if(digitalRead(but1) == LOW){
            score += 10; 
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(blue, LOW);  
        digitalWrite(green, LOW);  
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW); 
        delay (50);  //shorter delay for level 3
        digitalWrite(red, LOW); 
// lvl 3 blue
      } else if (randnumber < 20){
        digitalWrite(red, LOW);  
        digitalWrite(blue, HIGH); 
        if (digitalRead(blue) ==HIGH){
          delay(750);
          if(digitalRead(but2) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(blue, LOW); 
//lvl 3 green
      } else if (randnumber < 30) {
        digitalWrite(red, LOW);  
        digitalWrite(blue, LOW); 
        digitalWrite(green, HIGH); 
        if ((digitalRead(green)== HIGH)){
          delay(750);
          if(digitalRead(but3) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(yellow, LOW);  
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(green, LOW); 
 //lvl 3 yellow
      } else if (randnumber < 40){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, HIGH); 
        if ((digitalRead(yellow)==HIGH)){
          delay(750);
          if(digitalRead(but4) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        digitalWrite(white, LOW);
        delay (50);
        digitalWrite(yellow, LOW); 
 //lvl 3 white
      } else if (randnumber < 50){
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, HIGH);
        if ((digitalRead(white)==HIGH)){
          delay(750);
          if(digitalRead(but5) == LOW){
            score += 10;
            Serial.println("****************");
            Serial.print("SCORE: ");
            Serial.println (score);
            Serial.println("****************");
          }
        }
        delay (50);
        digitalWrite(white, LOW); // turn the red LED on pin 5 on
      }
      
      delay (50); 
      tick = tick + 1;  //same thing, except for third level, increasing tick by 1 each time
   }

//long flash to end the game 
    for(int i = 0; i < 1; i++){
        digitalWrite(red, HIGH); //turn the red LED on 
        digitalWrite(blue, HIGH); // turn the blue LED on 
        digitalWrite(green, HIGH); // turn the green LED on 
        digitalWrite(yellow, HIGH); // turn the yellow LED on 
        digitalWrite(white, HIGH);  //turn the white LED on  
        delay (1250);             //delays for 1.25 seconds
        //turns all off
        digitalWrite(red, LOW); 
        digitalWrite(blue, LOW); 
        digitalWrite(green, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(white, LOW);   
    }

    //tick will always reach 30 as it is added 10 times in each of the 3 for loops --> way of ending game
     if (tick == 30){
      game = false; // sets game to false 
      Serial.println ("-------------------------------------------------------------------------------------------------------------------------"); 
    //Prints total score 
      Serial.print("Game over! Your score was "); 
      Serial.print(score); 
      Serial.println(" / 300"); 

     }
 }
}
  
