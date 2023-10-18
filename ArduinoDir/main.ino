#define xAxis A0
#define yAxis A1

#define TRESH 50
#define MID 512

int xVal = 512;
int yVal = 512;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(xAxis, OUTPUT);
  pinMode(yAxis, OUTPUT);
}




void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xAxis);
  yVal = analogRead(yAxis);

  if(xVal >= MID + TRESH){
      if(yVal >= MID + TRESH){
        Serial.println("up_right");
      } 
      else if (yVal < MID - TRESH){
        Serial.println("up_left");    
      }
    
  } 
  else if (xVal < MID - TRESH){
      if(yVal >= MID + TRESH){
        Serial.println("down_right");     
      } 
      else if (yVal < MID - TRESH){
        Serial.println("down_leftt");    
      }
  }
}
