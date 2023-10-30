char cmd="";
char old_cmd;
boolean enable=false;


void setup(){
  // Initialize serial port
  Serial.begin(9600);
  Serial.println("ENTER Commands:");        
}

void loop(){
  old_cmd=cmd;
  if (Serial.available()){ // Verify that data are available
    cmd=Serial.read();  // Read data on serial port
  } 
  
  if(cmd!=old_cmd){
    if(cmd=='O'){
      Serial.println("Set to ON"); // Send data to serial port
      enable=true;
    }else if(cmd=='F'){
      Serial.println("Set to OFF"); // Send data to serial port
      enable=false;
    }
  }

   if(enable){
      Serial.println("System is running");
      delay(200);
    }
}
