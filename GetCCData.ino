const int clockPin = 2;
const int dataPin = 4;
const int bitNum = 43;
const int arrayOffset = 15;

byte dataState = 0;
byte DDCmd[bitNum];
int i = 0;
int j = 0;
volatile boolean clkDetect = false; 

void setup() 
{
  Serial.begin(2400); 
  pinMode(clockPin, INPUT);
  pinMode(dataPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(clockPin), Activity, RISING);
}

void loop() 
{
  if (clkDetect == true)
  { 
    capture();  
  } 
}

void Activity() {clkDetect = true;}

void capture()
{
  clkDetect = false;
  if (digitalRead(dataPin) == HIGH)
  {  
    dataState = 1;
  } else {
    dataState = 0;
  }

  DDCmd[i] = dataState;
  
  if (i == 43)
  {
    i=0;
    for (j=0; j<= 42; j++) 
    {     
      Serial.print(DDCmd[j]);
    }  
    Serial.println(""); 

  } else {
    i++;  
  } 
}
