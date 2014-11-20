/*
  File storing functions that operate on leds.
 */
void setupLeds(){
  for(int i = 0; i<tableSize; i++){
    pinMode(pins[i], OUTPUT);
  }
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

void executeLeds(){
  selectRandomOrder();
  sendInfoToLeds(HIGH);
  //oczekiwanie na wcisniecie przycisku (tymczasowo delay)
  //bedzie trzeba zmierzyc czas i dodac brzeczyk po wcisnieciu przycisku
  delay(5000);
  sendInfoToLeds(LOW);
}
