void setup() {
    Serial.begin(9600);

    pinMode(2, INPUT); // motion sensor
    pinMode(7, INPUT); // button1
    pinMode(6, INPUT); // button2

    pinMode(11, OUTPUT); // red LED
    pinMode(12, OUTPUT); // yellow LED
    pinMode(13, OUTPUT); // green LED

    digitalWrite(11, HIGH);
}


// states
const int LOCKED = 1;
const int WAITING1 = 2;
const int WAITING2 = 3;
const int UNLOCKED = 4;

int state = LOCKED;

int push_handled1 = 0;
int push_handled2 = 0;

void loop() {
    int motion_sensor = digitalRead(2);
    int button1 = digitalRead(7);
    int button2 = digitalRead(6);

    switch (state) {
        case LOCKED:
            if (motion_sensor == HIGH) {
                digitalWrite(11, LOW);
                digitalWrite(12, HIGH);
                state = WAITING1;
            }
            break;
        case WAITING1:
            break;
        case WAITING2:
            break;
        case UNLOCKED:
            break;
    }
}
