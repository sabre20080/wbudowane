/*
  Reflex game.
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
#define tableSize 3

int pins[] = {8, 12, 13};
int order[] = {0, 1, 2};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for(int i = 0; i<tableSize; i++){
    pinMode(pins[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  beginning(2000);
  //dodac na wyswietlaczu ze zaczyna sie gra
  selectRandomOrder();
  sendInfoToLeds(HIGH);
  //oczekiwanie na wcisniecie przycisku (tymczasowo delay)
  //bedzie trzeba zmierzyc czas i dodac brzeczyk po wcisnieciu przycisku
  delay(5000);
  sendInfoToLeds(LOW);
}

void beginning(int time){
  sendInfoToLeds(HIGH);
  delay(time);
  sendInfoToLeds(LOW);
}

void sendInfoToLeds(int info){
  for(int i = 0; i<tableSize; i++){
    digitalWrite(pins[order[i]], info);
  }
}

void selectRandomOrder(){
  int previousIndex = -1;
  boolean goodValue = false;
  for(int i = 0; i<tableSize; i++){
    int currentIndex;
    while(goodValue==false){
      currentIndex = random(0,2);
      if(currentIndex!=previousIndex){
        order[i]=currentIndex;
        goodValue=true;
      }
    }
    previousIndex = currentIndex;
  }
}
