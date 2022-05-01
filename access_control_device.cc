void setup() {
    pinMode(2, INPUT); // sensor
    pinMode(6, INPUT); // button2
    pinMode(7, INPUT); // button1

    pinMode(11, OUTPUT); // red LED
    pinMode(12, OUTPUT); // yellow LED
    pinMode(13, OUTPUT); // green LED
}


// states
const int LOCKED = 1;
const int WAITING1 = 2;
const int WAITING2 = 3;
const int UNLOCKED = 4;

int state = LOCKED;

void loop() {
}
