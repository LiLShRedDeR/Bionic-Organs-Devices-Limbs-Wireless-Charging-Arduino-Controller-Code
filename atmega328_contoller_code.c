//Sonar 1
int initPin1 = 2;
int echoPin1 = 3;
int ENABLE = 4;

int SENSE = 0;


void setup() {
  
  pinMode(echoPin1, INPUT);
  pinMode(initPin1, OUTPUT);
  pinMode(ENABLE, OUTPUT);  
}


void loop() {
  
  digitalWrite(ENABLE, HIGH);

  SENSE = getDistance(initPin1, echoPin1);
  delay(150);
  
 
  while ( SENSE == 1){
    
    Activ_Trans();
  }
  
}


int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 
   if (distance  >= 120 || distance  <= 0 ){
     
      return 1;
   }
   
   else{
     
     return 0;      
   }
}

void Activ_Trans()
{
  digitalWrite(ENABLE, LOW);
}
 

