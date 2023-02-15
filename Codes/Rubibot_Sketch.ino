// pins for motor 1
#define dir_1 2
#define step_1 3
// pins for motor 2
#define dir_2 4
#define step_2 5
// pins for motor 3
#define dir_3 7
#define step_3 6
// pins for motor 4
#define dir_4 8
#define step_4 9
// pins for motor 5
#define dir_5 12
#define step_5 10
// pins for motor 6
#define dir_6 13
#define step_6 11
// enable pin
#define epin 1

char turn;
int index =0;
int flag =1;
String str;

void rotate(int dirpin, int steppin, int dirval){
  if(dirval==1){
    digitalWrite(dirpin, HIGH);
  }
  else{
    digitalWrite(dirpin, LOW);
  }

  for(int i=0; i<100; i++){
    digitalWrite(steppin, HIGH);
    delayMicroseconds(500);
    digitalWrite(steppin, LOW);
    delayMicroseconds(500);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(step_1, OUTPUT);
  pinMode(dir_1, OUTPUT);
  pinMode(step_2, OUTPUT);
  pinMode(dir_2, OUTPUT);
  pinMode(step_3, OUTPUT);
  pinMode(dir_3, OUTPUT);
  pinMode(step_4, OUTPUT);
  pinMode(dir_4, OUTPUT);
  pinMode(step_5, OUTPUT);
  pinMode(dir_5, OUTPUT);
  pinMode(step_6, OUTPUT);
  pinMode(dir_6, OUTPUT);
  pinMode(epin, OUTPUT);
  digitalWrite(epin, LOW);
  Serial.println("<Arduino is ready>");
}


void loop() {
  
  if(flag){
      while(!Serial.available()){};
      str = Serial.readString();
      flag = 0;
  }
  turn = str[index];
  
  switch (turn) {
    case 'L':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_1, step_1, 1);
      break;
    case 'l':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_1, step_1, -1);
      break;
     case 'R':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_2, step_2, -1);
      break;
    case 'r':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_2, step_2, 1);
      break;
    case 'F':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_3, step_3, -1);
      break;
    case 'f':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_3, step_3, 1);
      break;
    case 'B':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_4, step_4, 1);
      break;
    case 'b':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_4, step_4, -1);
      break;
    case 'U':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_5, step_5, -1);
      break;
    case 'u':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_5, step_5, 1);
      break;
    case 'D':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_6, step_6, 1);
      break;
    case 'd':
      Serial.print("The move you've chosen is: ");
      Serial.println(turn);
      rotate(dir_6, step_6, -1);
      break;
    default:
     Serial.println("Please choose a valid move");
  }
  index++;
  delay(1000);
}
