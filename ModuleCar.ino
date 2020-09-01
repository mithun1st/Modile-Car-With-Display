#include<Servo.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(42,44,46,48,50,52);

Servo s1;
int bo=0;
int so;
int a1=8;
int a2=9;
int b1=10;
int b2=11;
int sp=40;
int t=22;
int e=23;
int hled=53;
String s;

void setup(){
  s1.attach(sp);
  
  pinMode(hled,OUTPUT);
  
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);

  pinMode(t,OUTPUT);
  pinMode(e,INPUT);

  lcd.begin(16,2);
  Serial.begin(9600);

  lcd.print("Mahadi Hassan");
  lcd.setCursor(3,1);
  lcd.print("Mithun");
}

void loop(){


   so=sonic(t,e);


//input 
  while(Serial.available()){
    s+=(char)Serial.read();
    delay(5);
  }


   if(so<=5 && bo==1){
      ba(); 
      delay(500);
      st();
      bo=0;
  }
  else if(s=="go"){ 
      bo=1;
      fr();     
  }
      
 
//control
  if(s=="0" ||s=="stop"){
    st();
    bo=0;
  }

  else if(s=="back"){
    ba();
  }
  else if(s=="left"){
    le();
  }
  else if(s=="right"){
    ri();
  }
  
//servo
  if(s=="m"){
    sl();
  }
  else if(s=="n"){
    sr();
  }
  else if(s=="y"){
    s1.write(90);
    delay(100);
  }
  else if(s=="x"){
    s1.write(90);
    delay(100);
    st();
    digitalWrite(hled,0);
  }
  
  
//led
  if(s=="led on"){
    digitalWrite(hled,1);
  }
  else if(s=="led off"){
    digitalWrite(hled,0);
  }
  
  s="";
}

////////////////////////function Define_-----------

void st(){
  digitalWrite(a1,0);
  digitalWrite(a2,0);
  digitalWrite(b1,0);
  digitalWrite(b2,0);
}

void fr(){

  digitalWrite(a1,1);
  digitalWrite(a2,0);
  digitalWrite(b1,0);
  digitalWrite(b2,1);
  
}

void ba(){
  digitalWrite(a1,0);
  digitalWrite(a2,1);
  digitalWrite(b1,1);
  digitalWrite(b2,0);
}

void le(){
  digitalWrite(a1,1);
  digitalWrite(a2,0);
  digitalWrite(b1,1);
  digitalWrite(b2,0);
}

void ri(){
  digitalWrite(a1,0);
  digitalWrite(a2,1);
  digitalWrite(b1,0);
  digitalWrite(b2,1);
}

void sl(){
  for(int i=90;i<=140;i+=10){
    s1.write(i);
    delay(50);
  }
}

void sr(){
  for(int i=90;i>=40;i-=10){
    s1.write(i);
    delay(50);
  }
}

int sonic(int a, int b){
  digitalWrite(a,0);
  delay(2);
  digitalWrite(a,1);
  delay(10);
  digitalWrite(a,0);

  return pulseIn(b,1)*0.0133/2;
}


