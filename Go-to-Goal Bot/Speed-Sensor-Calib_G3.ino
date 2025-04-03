// Define speed sensor pins
int sensor1 = 2;
int sensor2 = 3;

// Define variables for distance and speed calculations
unsigned int ticks1;
unsigned int ticks2;
double distanceR;
double distanceL;

// Define constants and wheel dimensions
const double pi = 3.141592653589793238463;
int wheelrad = 3.3;
int wheeldist = 14;

void setup()
{
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

void loop()
{

  distanceR = (2*pi*wheelrad) * (ticks2/20);
  distanceL = (2*pi*wheelrad) * (ticks1/20);

}

void LeftTick()
{
  ticks1++;
}
  
void RightTick()
{
  ticks2++;
}
