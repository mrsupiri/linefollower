/*
  Line following robot for 3 sensors
  work for both digital and analog inputs.
  The code is written to follow a black line on a white background.
  works best with L298D Motor Driver

  Author - Suvin Nimnaka
  www.suvink9.wordpress.com
*/


int s1_in = 0;//your sensor pin;
int s2_in = 0;//your sensor pin;
int s3_in = 0;//your sensor pin;

int  rme = 00; //enable pin for right motor
int  lme = 00; //enable pin for left motor

int rmf = 0; //Right motor foreward pin
int rmr = 0; //Right motor reverse pin

int lmf = 0; //Left motor foreward pin
int lmr = 0; //Left motor reverse pin

//comment below 7 lines if you are using digital inputs for infrared sensors.
int s1_val;
int s2_val;
int s3_val;

int s1;
int s2;
int s3


void setup() {
  
  pinMode (s1_in, INPUT);
  pinMode (s2_in, INPUT);
  pinMode (s3_in, INPUT);

  pinMode(rme,OUTPUT);
  pinMode(lme,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rmf,OUTPUT);
  pinMode(rmr,OUTPUT);
  
  
}

void loop() {

analogreadings(); //Comment this if using digital inputs for sensors

linefollow(); 
  
}

void analogreadings()

  s1_val = analogRead(s1_pin);
  s2_val = analogRead(s2_pin);
  s2_val = analogRead(s2_pin); 
  
  if (s1_val<640){
    s1 == 1;
    }
  else {
    s1 = 0;
    }
  
  if (s2_val<640){
    s2 == 1;
    }
  else {
    s2 = 0;
    }
  
  if (s3_val<640){
    s3 == 1;
    }
  else {
    s3 = 0;
    } 
 }

void linefollow(){

       if(s1== 0 && s2 == 0 && s3 == 0){
           movefwd();
         }
  else if(s1== 0 && s2 == 0 && s3 == 1){
     turnright();
    }
  else if(s1== 0 && s2 == 1 && s3 == 0){
      movefwd();
    }
  else if(s1== 0 && s2 == 1 && s3 == 1){
      turnright();
    }
  else if(s1== 1 && s2 == 0 && s3 == 0){
      turnleft();
    }
  else if(s1== 1 && s2 == 0 && s3 == 1){
      movefwd();
    }
  else if(s1== 1 && s2 == 1 && s3 == 0){
      turnleft();
    }
  else if(s1== 1 && s2 == 1 && s3 == 1){
      movestop();
    }
   
  
  }

void movefwd(){
  digitalWrite(rme, HIGH);
  digitalWrite(lme, HIGH);

  digitalWrite(rmf,HIGH);
  digitalWrite(rmr,LOW);

  digitalWrite(lmf,HIGH);
  digitalWrite(lmr,LOW);
  
  }


void turnleft(){
  digitalWrite(rme, HIGH);
  digitalWrite(lme, LOW);

  digitalWrite(rmf,HIGH);
  digitalWrite(rmr,LOW);

  }


void turnright(){
  digitalWrite(lme, HIGH);
  digitalWrite(rme, LOW);

  digitalWrite(lmf,HIGH);
  digitalWrite(lmr,LOW);
  }

void reverse(){
  digitalWrite(rme, HIGH);
  digitalWrite(lme, HIGH);

  digitalWrite(rmr,HIGH);
  digitalWrite(rmf,LOW);

  digitalWrite(lmr,HIGH);
  digitalWrite(lmf,LOW);
  
  }

void movestop(){
  digitalWrite(rme, LOW);
  digitalWrite(lme, LOW);
  }

void dispara(){
  Serial.prinln ("Sensor 1 value"+);
  Serial.prinln ("Sensor 1 value"+);
  Serial.prinln ("Sensor 1 value"+);
  
  }
