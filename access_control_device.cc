void setup() {
    Serial.begin(9600);

    pinMode(2, INPUT); // motion sensor
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
    int button1 = digitalRead(7);
    int button2 = digitalRead(6);

    switch (state) {
        case LOCKED:
            break;
        case WAITING1:
            break;
        case WAITING2:
            break;
        case UNLOCKED:
            break;
    }
}
