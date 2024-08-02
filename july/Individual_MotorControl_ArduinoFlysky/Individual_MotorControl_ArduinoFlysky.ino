//YouTube|Tech at Home

double ch2=2;
double ch4=3;

int a=4; int b=5;
int c=6; int d=7;


void setup()
{
  Serial.begin(9600);

  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  pinMode(4,OUTPUT); pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); pinMode(7,OUTPUT);
  
}

void loop()
{
ch2 = pulseIn(2,HIGH);
ch4 = pulseIn(3,HIGH);

//Serial.println(ch2);
//Serial.println(ch4);

if(ch2 > 1530)
{ 
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);   
}

else if(ch2 < 1430)
{     
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
}

else if(ch4 > 1530)
{     
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
}

else if(ch4 < 1430)
{     
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
}

else
{     
 digitalWrite(a,LOW); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,LOW);
}

}
