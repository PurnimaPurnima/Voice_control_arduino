String voice;
#define led1 2 //connect the positive of the 1st LED to pin 2 of the arduino
#define led2 3 //connect the positive of the 2nd LED to pin 3 of the arduino
#define led3 4 //connect the positive of the 3rd LED to pin 4 of the arduino
#define led4 5 //connect the positive of the 4th LED to pin 5 of the arduino
#define buzzer 6 //connnect the positive of the buzzer to the 6th pin
#define motor 7 //connect the motor-driver input pin to pin 7 of arduino


void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() 
{
  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    if (c=='#')
    break;
    voice=voice+c;
  }
  if (voice=="one on" || voice=="won on" || voice=="1 on")
  digitalWrite(led1, HIGH);
  else if (voice=="two on" || voice=="2 on" || voice=="2 on")
  digitalWrite(led2, HIGH);
  else if (voice == "three on" || voice=="3 on")
  digitalWrite(led3, HIGH);
  else if (voice == "four on" || voice=="4 on")
  digitalWrite(led4, HIGH);
  else if (voice=="one off" || voice=="one of") //the commands like "one of" are written to avoid the errors due to less sensitive mic.
  digitalWrite(led1, LOW);
  else if (voice=="two off" || voice=="two of")
  digitalWrite(led2, LOW);
  else if (voice == "three off" || voice=="three of")
  digitalWrite(led3, LOW);
  else if (voice == "four off" || voice=="four of")
  digitalWrite(led4, LOW);
  else if (voice == "all off" || voice=="off" || voice=="all of" || voice=="of")
  alloff();
  else if (voice == "all on" || voice=="on")
  allon();
  else if (voice == "buzzer on" || voice=="bazaron" || voice=="Bazaar on") //"bazaron" and "Bazaar on" avoid the errors due to less sensitive mic.
  digitalWrite(buzzer, HIGH);
  else if (voice=="buzzer off" || voice=="Bazaar off" || voice=="buzzer of" || voice=="Bazaar of")
  digitalWrite(buzzer, LOW);
  else if (voice == "fan on")
  digitalWrite(motor, HIGH);
  else if (voice=="fan off" || voice=="fan of")
  digitalWrite(motor, LOW);
  else if (voice=="pattern" || voice=="Titan" || voice=="cartoon" || voice=="Patan") //again to avoid errors due to less sensitive mic.
  pattern();
  voice="";
}

void alloff()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(motor, LOW);
  digitalWrite(buzzer, LOW);
}

void allon()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(motor, HIGH);
  digitalWrite(buzzer, HIGH);
}

void pattern()
{
  digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(250);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    delay(250);
    digitalWrite(led4, LOW);
    while(Serial.available())
    {delay(10);
      char c=Serial.read();
    if (c=='#')
    break;
    voice=voice+c;
    }
    if(voice=="pattern" || voice=="Titan" || voice=="cartoon" || voice=="Patan")
    pattern();
    else
    alloff();
  
}

