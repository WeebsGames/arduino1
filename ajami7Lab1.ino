/*HEADER
Areeb Jamili
Lab 1 - 3 Way Blink
This code makes 3 led lights blink at different intervals
I assumed the arduino would be able to run the compiled code. I also assumed that the resistors that were labeled 220 ohms would be 220 ohms. 
I used the lab recording as reference for the wiring.
*/
unsigned long prev1 = 0;
unsigned long prev2 = 0;   
//start with one led on to make sure the if statements work                                            
int status1 = HIGH;
int status2 = LOW;
int status3 = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long curr = millis();
  if(curr-prev1 >= 1000){
    prev1 = curr;
    //these if else statements make sure only one led is on at the same time  
    if(status1){
      //turn off led1 and turn on led2
      status1 = !status1;
      status2 = !status2;
    }else if(status2){
      //turn off led2 and turn on led3
      status2 = !status2;
      status3 = !status3;
    }else if(status3){
      //turn off led3 and turn on led1
      status3 = !status3;
      status1 = !status1;
    }
    digitalWrite(11, status1);
    digitalWrite(12, status2);
    digitalWrite(13, status3);
  }
  // if(curr-prev2 >= 3000){
  //   prev2 = curr;
  //   digitalWrite(13, status2);
  //   status2 = !status2;
  // }
}
