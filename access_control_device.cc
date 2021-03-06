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

int push_handled = 0;

const int VALUE1_CORRECT = 2;
const int VALUE2_CORRECT = 1;
int value1_entered = 0;
int value2_entered = 0;

const int TIMEOUT_SECONDS = 10;

void loop() {
    int motion_sensor = digitalRead(2);
    int button1 = digitalRead(7);
    int button2 = digitalRead(6);

    if (button1 == LOW && button2 == LOW) {
        push_handled = 0;
    }

    switch (state) {
        case LOCKED:
            if (motion_sensor == HIGH) {
                digitalWrite(11, LOW);
                digitalWrite(12, HIGH);
                state = WAITING1;
            }
            break;
        case WAITING1:
            if (button1 == HIGH && !push_handled) {
                push_handled = 1;
                value1_entered = 1;
            } else if (button2 == HIGH && !push_handled) {
                push_handled = 1;
                value1_entered = 2;
            }

            if (value1_entered) {
                blink(12, 1);
                state = WAITING2;
            }
            break;
        case WAITING2:
            if (button1 == HIGH && !push_handled) {
                push_handled = 1;
                value2_entered = 1;
            } else if (button2 == HIGH && !push_handled) {
                push_handled = 1;
                value2_entered = 2;
            }

            if (value2_entered) {
                blink(12, 1);

                if (value1_entered == VALUE1_CORRECT && value2_entered == VALUE2_CORRECT) {
                    digitalWrite(12, LOW);
                    digitalWrite(13, HIGH);
                    state = UNLOCKED;
                } else {
                    digitalWrite(12, LOW);
                    blink(11, 0);
                    digitalWrite(11, HIGH);
                    state = LOCKED;
                }

                reset_entered_values();
            }
            break;
        case UNLOCKED:
            delay(TIMEOUT_SECONDS * 1000);
            digitalWrite(13, LOW);
            digitalWrite(11, HIGH);
            state = LOCKED;
            break;
    }
}

// parameter original_state: 1 if the LED is on, 0 if it is off
void blink(int led_id, int original_state) {
    int led_state = original_state;

    for (int i = 0; i < 8; i++) {
        led_state = !led_state;
        digitalWrite(led_id, led_state ? HIGH : LOW);
        delay(200);
    }
}

void reset_entered_values() {
    value1_entered = 0;
    value2_entered = 0;
}
