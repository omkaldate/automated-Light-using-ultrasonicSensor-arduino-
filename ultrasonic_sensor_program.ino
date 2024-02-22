 //############ sensor for in ##############
   int trig_in =13;
   int echo_in =12;
   long timein;
   int in;
 // ############ sensor for out ##############
   int trig_out=7;
   int echo_out=6;
   long timeout; 
   int out;
   
 //########## function decleration ##########
   void on_in_sensor2_func();  // function for light on
   void off_out_sensor1_func(); // funcion for light off
   int led =10;
   int buzz =5;
  
  void setup() {
   pinMode(trig_in , OUTPUT);
   pinMode(echo_in , INPUT);
   pinMode(trig_out , OUTPUT);
   pinMode(echo_out , INPUT);
   pinMode(led , OUTPUT);
   pinMode(buzz , OUTPUT);
   Serial.begin(9600); 
  }

 void loop() {
    off_out_sensor1_func();
    on_in_sensor2_func();
   Serial.println();
 }

   void off_out_sensor1_func(){
   digitalWrite(trig_out,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_out,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_out,LOW);

  timeout=pulseIn(echo_out,HIGH);
   out = timeout*0.034 /2;
 
  Serial.print("off sensor eco signal in time= ");
  Serial.println(timeout);
  Serial.print("off sensor detected distance= ");
  Serial.println(out);

  if(out < 480){
  digitalWrite(led , LOW);
  digitalWrite(buzz, LOW);
  }
  }
    



  void on_in_sensor2_func(){
  digitalWrite(trig_in,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_in,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig_in,LOW);

  timein=pulseIn(echo_in,HIGH);
   in = timein*0.034 /2;
 
  Serial.print(" on sensor eco signal in time= ");
  Serial.println(timein);
  Serial.print("on sensor detected distance= ");
  Serial.println(in);

  if(in < 480){
   digitalWrite(led , HIGH);
   digitalWrite(buzz, HIGH);
   }
  }
  
  
  



  
