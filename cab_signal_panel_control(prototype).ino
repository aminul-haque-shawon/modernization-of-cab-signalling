int redled = 9;  //selecting digital pins to display output
int greenled = 10;
int yellowled = 11;

int serverSignal

int getserverSignal(); //function depends on the use of communication module

void setup()
{
    serial.begin(9600);

    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(yellowled, OUTPUT);

    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(yellowled, LOW);
}

void loop()
{
    serverSignal = getserverSignal();

    //let serverSignal = 0 for clear drive, 1 for careful drive and -1 for stop
    if(serverSignal == 0) {
        digitalWrite(greenled, HIGH);
        digitalWrite(redled, LOW);
        digitalWrite(yellowled, LOW);

    }
    else if (serverSignal == 1)
    {
        digitalWrite(greenled, LOW);
        digitalWrite(redled, HIGH);
        digitalWrite(yellowled, LOW);
    }
    else {
        digitalWrite(greenled, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(yellowled, HIGH);
    }
}
