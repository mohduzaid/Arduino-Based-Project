#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

int count8 = 0;
int count9 = 0;
int count10 = 0;
int count11 = 0;

void setup()
{
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("EVM");
  lcd.setCursor(0,1);
  lcd.print("Enter your Votes");
  delay(1000);
  lcd.clear();
 
}

void loop()
{
  int pin8 = digitalRead(8);
  int pin9 = digitalRead(9);
  int pin10 = digitalRead(10);
  int pin11= digitalRead(11);
  int pin12= digitalRead(12);
  
  if(pin8==HIGH){
    count8++;
    
    lcd.setCursor(0,0);
    lcd.print("TEAM A:");
    lcd.setCursor(0,1);
    lcd.print(count8);
    
    
    
  }
  else if(pin9==HIGH){
    count9++;
    lcd.setCursor(0,0);
    lcd.print("TEAM B:");
    lcd.setCursor(0,1);
    lcd.print(count9);
  }
  else if(pin10==HIGH){
    count10++;
    lcd.setCursor(0,0);
    lcd.print("TEAM C:");
    lcd.setCursor(0,1);
    lcd.print(count10);
  }
  else if(pin11==HIGH){
    count11++;
    lcd.setCursor(0,0);
    lcd.print("TEAM D:");
    lcd.setCursor(0,1);
    lcd.print(count11);
  }
  else if(pin12==HIGH){
    lcd.setCursor(0,0);
    lcd.print("Voting Ended");
    lcd.setCursor(0,1);
    lcd.print("Wait for Result");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("A");
    lcd.setCursor(0,1);
    lcd.print(count8);
    lcd.setCursor(3,0);
    lcd.print("B");
    lcd.setCursor(3,1);
    lcd.print(count9);
    lcd.setCursor(6,0);
    lcd.print("C");
    lcd.setCursor(6,1);
    lcd.print(count10);
    lcd.setCursor(9,0);
    lcd.print("D");
    lcd.setCursor(9,1);
    lcd.print(count11);
    delay(5000);
    lcd.clear();
    if(count8>count9 && count8>count10 && count8>count11){
    	lcd.setCursor(0,0);
    	lcd.print("Team A WINS");
    	lcd.setCursor(0,1);
    	lcd.print("With ");
    	lcd.print(count8);
    	lcd.print(" Votes");
	}
    else if(count9>count10 && count9>count8 && count9>count11){
    	lcd.setCursor(0,0);
    	lcd.print("Team B WINS");
    	lcd.setCursor(0,1);
    	lcd.print("With ");
    	lcd.print(count9);
    	lcd.print(" Votes");
	}
    else if(count10>count9 && count10>count11 && count10>count8){
    	lcd.setCursor(0,0);
    	lcd.print("Team C WINS");
    	lcd.setCursor(0,1);
    	lcd.print("With ");
    	lcd.print(count10);
    	lcd.print(" Votes");
	}
    else if(count11>count10 && count11>count9 && count11>count8){
    	lcd.setCursor(0,0);
    	lcd.print("Team D WINS");
    	lcd.setCursor(0,1);
    	lcd.print("With ");
    	lcd.print(count9);
    	lcd.print(" Votes");
	}
    else{
      lcd.setCursor(0,0);
      lcd.print("NO RESULT");
    }
    
  }
 delay(200);
}