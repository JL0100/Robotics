// Define motor control pins
int enA = 5;
int in1 = 6;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int enB = 12;

// Define speed sensor pins
int sensor1 = 2;
int sensor2 = 3;

// Define variables for distance and speed calculations
unsigned int ticks1;
unsigned int ticks2;
double distanceRx;
double distanceLx;
double distanceRy;
double distanceLy;
double distanceRrotx;
double distanceLrotx;
double distanceRroty;
double distanceLroty;

// Define constants and wheel dimensions
const double pi = 3.141592653589793238463;
int wheelrad = 3.3;
int wheeldist = 14;
double wheelangleA = 110;
double wheelangleB = 110;
double wheelangleC = 110;
int xstage = 0;
int ystage = 0;
int prexstage = 0;
int preystage = 0;

// Define desired goal
double xf = 100;
int negx = 0;
double yf = 0;
int negy = 0;

void setup() {
  // Set motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  // Set speed sensor pins as inputs
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  pinMode(sensor1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensor1), LeftTick, RISING);
  pinMode(sensor2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensor2), RightTick, RISING);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  
  if(negx == 0 && xstage == 0 && ystage == 0 && preystage == 0)
  {
    distanceRx = (2*pi*wheelrad) * (ticks2/20);
    distanceLx = (2*pi*wheelrad) * (ticks1/20);

    if (distanceRx < xf && distanceLx < xf)
    {
      analogWrite(enA, 255);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enB, 128);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    if (distanceRx >= xf && distanceLx >= xf)
    {
      analogWrite(enA, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enB, 0);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      ticks1=0;
      ticks2=0;
      xstage=1;

      delay(1000); 
    }
  }

  if(negx == 1 && xstage == 0 && ystage == 0 && preystage == 0 && prexstage == 0)
  {
    distanceLrotx = (2*pi*wheelrad) * (ticks1/20);


    if(distanceLrotx < wheelangleB)
    {
      analogWrite(enA, 150);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enB, 0);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    if (distanceLrotx >= wheelangleB)
    {
      analogWrite(enA, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enB, 0);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      ticks1=0;
      ticks2=0;
      prexstage=1;

      delay(1000);

      
    }
  }

    if(negx == 1 && prexstage == 1 && ystage == 0 && preystage == 0)
    {
      
      distanceRx = (2*pi*wheelrad) * (ticks2/20);
      distanceLx = (2*pi*wheelrad) * (ticks1/20);

      if (distanceRx < xf && distanceLx < xf)
      {
        analogWrite(enA, 255);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enB, 128);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
      }
      if (distanceRx >= xf && distanceLx >= xf)
      {
        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enB, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

        ticks1=0;
        ticks2=0;
        xstage=1;

        delay(1000);
      }
    }

    if (negy == 0 && preystage == 0 && xstage == 1)
    {
      distanceRroty = (2*pi*wheelrad) * (ticks2/20);
      distanceLroty = (2*pi*wheelrad) * (ticks1/20);

      if(distanceLroty < wheelangleA)
      {
       analogWrite(enA, 150);
       digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
      }

      if (distanceLroty >= wheelangleA)
      {
        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);


        ticks1=0;
        ticks2=0;
        preystage=1;

        delay(1000);      
      }
    }

    if (negy == 1 && preystage == 0 && xstage == 1)
    {
      distanceLroty = (2*pi*wheelrad) * (ticks1/20);

      if(distanceLroty < wheelangleC)
      {
       analogWrite(enA, 150);
       digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
      }

      if (distanceLroty >= wheelangleC)
      {
        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enB, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

        ticks1=0;
        ticks2=0;
        preystage=1;

        delay(1000);      
      }
    }

    if (ystage == 0 && preystage == 1)
    {
      distanceRy = (2*pi*wheelrad) * (ticks2/20);
      distanceLy = (2*pi*wheelrad) * (ticks1/20);

      if (distanceRy < yf && distanceLy < yf)
      {
        analogWrite(enA, 255);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enB, 128);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
      }
      if (distanceRy >= yf && distanceLy >= yf)
      {
        analogWrite(enA, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enB, 0);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);

        ticks1=0;
        ticks2=0;
        ystage=1;

        delay(1000); 
      }
    }

  




    
  
  
} 

// Read sensor 1
  void LeftTick()
  {
    ticks1++;
  }
  
  // Read sensor 2
  void RightTick()
  {
    ticks2++;
  }