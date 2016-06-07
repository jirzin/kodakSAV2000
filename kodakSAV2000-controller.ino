const int pinForward = 13;
const int pinBackward = 13;
const int switchTime = 200;  // time for which switch is on



int index = 0;

// first number represent action
// 0 = step forwards
// 1 = step backwards
// 2.. = not implemented
// second number represent delay to another step
const int steps = 10;    // number of intervals to be executed
unsigned int intervalList [steps] [2] = {
  {0, 4000},
  {0, 4000},
  {0, 4000},
  {0, 4000},
  {1, 4000},
  {1, 4000},
  {1, 4000},
  {1, 4000},
  {2, 1000},
  {2, 1000}
};

void setup() {
  pinMode(pinForward, OUTPUT);
  pinMode(pinBackward, OUTPUT);
}


void loop() {
  readIntervals();
}


void readIntervals() {
  for (int i = 0; i < steps; i++) {
    int x = intervalList[i][0];
    unsigned int t = intervalList[i][1];
    switch (x) {
      case 0:
        digitalWrite(pinForward, HIGH);
        delay(switchTime);
        digitalWrite(pinForward, LOW);
        break;
      case 1:
        digitalWrite(pinBackward, HIGH);
        delay(switchTime);
        digitalWrite(pinBackward, LOW);
        break;
    }
    delay(t - switchTime);
  }
}
