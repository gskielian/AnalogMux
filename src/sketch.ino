#define s0 8
#define s1 9
#define s2 10

int r0=0;
int r1=0;
int r2=0;

int count=0;


void setup()
{
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);

  digitalWrite(s0,LOW);
  digitalWrite(s1,LOW);
  digitalWrite(s2,LOW);

  Serial.begin(9600);
}

void loop()
{
  int i=0;
  for ( i = 0; i <= 7 ; i++ ) {
    r0=( count & 0x01);
    r1=( (count>>1) & 0x01);
    r2=( (count>>2) & 0x01);

    digitalWrite(s0,r0);
    digitalWrite(s1,r1);
    digitalWrite(s2,r2);

    Serial.print("Reading on ");
    Serial.print(count);
    Serial.print(" is ");
    Serial.println(analogRead(A0));

    (count >=7) ? count=0 : count++;
    delay(500);
  }
}
