/*
  Reflex game.
 */
 
#define tableSize 3

int pins[] = {8, 12, 13};
int order[] = {0, 1, 2};

// the setup function runs once when you press reset or power the board
void setup() {
  setupLeds();
}

// the loop function runs over and over again forever
void loop() {
  beginning(2000);
  //dodac na wyswietlaczu ze zaczyna sie gra
  executeLeds();
}

void beginning(int time){
  sendInfoToLeds(HIGH);
  delay(time);
  sendInfoToLeds(LOW);
}
