int redled = 9;  //selecting digital pins to display output
int greenled = 10;
int yellowled = 11;

bool serverSignal0;
bool serverSignal1;
bool serverSignal2;


void getserverSignal()
{
    serverSignal0 = digitalRead(0);
    serverSignal1 = digitalRead(1);
    serverSignal2 = digitalRead(2);

}
 //function depends on the use of communication module

void setup()
{

    // output pins
    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(yellowled, OUTPUT);

    //input pins
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);

    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(yellowled, LOW);
}

void loop()
{
    getserverSignal();


    if(serverSignal0 == HIGH && serverSignal1 == LOW && serverSignal2 == LOW ) { //indicating clear from server
        digitalWrite(greenled, HIGH);
        digitalWrite(redled, LOW);
        digitalWrite(yellowled, LOW);

    }
    else if (serverSignal0 == LOW && serverSignal1 == HIGH && serverSignal2 == LOW)
    {
        digitalWrite(greenled, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(yellowled, HIGH);
    }
    else if(serverSignal0 == LOW && serverSignal1 == LOW && serverSignal2 == HIGH){
        digitalWrite(greenled, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(yellowled, HIGH);
    }
}
