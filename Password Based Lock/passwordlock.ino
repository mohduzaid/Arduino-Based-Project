#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Servo.h>

Servo lockServo;

LiquidCrystal_I2C lcd(0x27,16,2);
int securityLength;
char* securityKey;
char key;
int timePressed = 0 ;int lockTime;

const byte ROWS = 4;
const byte COLUMNS = 4;

char keypadKeys[ROWS][COLUMNS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {9,8,7,6};
byte columnPins[COLUMNS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keypadKeys),rowPins,columnPins,ROWS,COLUMNS);
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(11, HIGH);
  while(1){
  	lcd.setCursor(0,0);
  	lcd.print("ENTER LENGTH");
  	lcd.setCursor(0,1);
    do{
      key = keypad.getKey();
    } while(!key);
    securityLength = key - '0';
    lcd.print(securityLength);
    do{
      key = keypad.getKey();
      if(key == 'A'){
          lcd.setCursor(0,1);
          lcd.print(securityLength);
          delay(200);
          
      }
      else if(key>='0' && key<='9'){
          securityLength = (securityLength*10) + key - '0';
          lcd.setCursor(0,1);
          lcd.print(securityLength);
          while(key!='A'){
            key = keypad.getKey();
          }
          
      }
      
    } while(!key);
    if(key == 'A'){
      break;
    }
    lcd.clear();
  }
  
  securityKey = (char*)malloc((securityLength+1)*sizeof(char)); 
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("SET PASSWORD");
  lcd.setCursor(0,1);
  for(int i = 0; i<securityLength; i++){
    do {
      key = keypad.getKey();
    } while(!key);
    securityKey[i] = key;
    lcd.print(key);
  }
  securityKey[securityLength] = '\0'; 
  delay(500);
  lockServo.attach(13);  
  lockServo.write(0);  

  lcd.clear();
  digitalWrite(11, LOW);
}

void loop()
{
  int i;
  char yourEntry[securityLength+1];
  lcd.setCursor(0,0);
  
  
  
  digitalWrite(10, HIGH);
  lcd.setCursor(0,0);
  lcd.print("ENTER PASSWORD");

  for(i = 0; i<securityLength; i++){
    do {
      key = keypad.getKey();
    } while (!key);
    
    lcd.setCursor(i,1);
    
    if(key>='0' && key<='9'){
    	lcd.print("*");
    	yourEntry[i] = key;
   	}
   	else if(key == 'B' && i>0){
      	for (int n = 0; n < securityLength+1; n++) {
    		yourEntry[n] = '\0';
		}

      	lcd.clear();
      	lcd.setCursor(0,0);
  		lcd.print("ENTER PASSWORD");
      	lcd.setCursor(0,1);
      	i=-1;
    }
   	else if(key == 'C'){
   		break;
    }
    else if(key == 'D'){
      lcd.clear();
      return;
    }
  }
  delay(200);
  do{
    key = keypad.getKey();
  	yourEntry[i] = '\0';
  }while(key != 'C');
  lcd.clear();
  if(strcmp(yourEntry,securityKey)==0){
    lcd.setCursor(0,0);
    lcd.print("ACCESS GRANTED");
    timePressed=0;lockTime = 0;
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    lockServo.write(90);    
    delay(2000);            
    lockServo.write(0);     
    delay(1000);
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("ACCESS DENIED");
    timePressed+=1;
    if(timePressed == 1){
      lockTime = 5;
    }
   	else if(timePressed == 2){
      lockTime = 15;
    }
    else if(timePressed == 3){
      lockTime = 30;
    }
    else if(timePressed == 4){
    	
    	lcd.setCursor(0,0);
    	lcd.print("SYSTEM LOCKED");
    	
		while(digitalRead(12) == LOW); // wait until reset switch
        timePressed = 0;  // reset attempts
        lockTime = 0;
        lcd.clear();
      	
    }
  }
  for(int j = 0; j<lockTime; j++){
      	digitalWrite(10, HIGH);
      	delay(500);
    	digitalWrite(10, LOW);
      	delay(500);
  }
  lcd.setCursor(0,0);
  lcd.print("SYSTEM REBOOTING");
  delay(200);
  lcd.clear();
  
  delay(5000);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  
}