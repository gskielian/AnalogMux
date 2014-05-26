#define s0 8
#define s1 9
#define s2 10

#define e0 6
#define e1 5

#define arrayLength 16

int r0=0;
int r1=0;
int r2=0;

int count=0;

int sensorOutput[arrayLength] = { 0 }; // all elements init to 0

void setup()
{
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);

  pinMode(e0,OUTPUT);
  pinMode(e1,OUTPUT);

  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);

  Serial.begin(9600);
}

void loop()
{
readSensors(sensorOutput, 0);
readSensors(sensorOutput, 1);
printResults(sensorOutput);
}

void printResults( int * arrayPointer) {
//output will look like [0, 140, 24, 250, ... ,249 ]
  int i;
  Serial.print("[" );

  for(i=0; i < (arrayLength - 1); i++ ){
    Serial.print(*(arrayPointer + i));
    Serial.print(",");
  }

  Serial.print(*(arrayPointer + i));
  Serial.println("]");
}


void readSensors( int* arrayPointer, int enableBit) {
int sensorReading=0;


  int i;
  for ( i = 0; i <= 7 ; i++ ) {
    r0=( i & 0x01);
    r1=( ( i >>1) & 0x01);
    r2=( ( i >>2) & 0x01);

    /*
    Serial.print(" ");
    Serial.print(r0);
    Serial.print(" ");
    Serial.print(r1);
    Serial.print(" ");
    Serial.println(r2);
    */

    digitalWrite(s0,r0);
    digitalWrite(s1,r1);
    digitalWrite(s2,r2);

    if (enableBit == 0) {
      digitalWrite(e1,1);
      digitalWrite(e0,0);
    } else {
      digitalWrite(e0,1);
      digitalWrite(e1,0);
    }

    if (enableBit == 1) {
      sensorReading = *(arrayPointer + i + 8) = analogRead(A0);
    } else {
      sensorReading = *(arrayPointer + i) = analogRead(A1);
    }

    /*
    Serial.print("Reading on ");
    Serial.print(i + enableBit*8);
    Serial.print(" is ");
    Serial.println(sensorReading);
    */

    delay(10);
  }

}
