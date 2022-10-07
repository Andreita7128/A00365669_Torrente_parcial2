const int HUM_SENSOR = A0;
const int BZZ = 3;
const int BTN = 2;

int humValue = 0;
int btnState = 0;

bool btnPressed = false;

int myLEDs [5] = {4,5,6,7,8};


void setup()
{
  Serial.begin(9600);
  
  pinMode(HUM_SENSOR, INPUT);
  pinMode(BTN,INPUT);
  pinMode(BZZ, OUTPUT);
  
  for(int i = 0; i < 5; i++){
  pinMode(myLEDs[i], OUTPUT);
  }
  
}

void loop()
{
  humValue = round(analogRead(HUM_SENSOR)/876.00 * 100); 
  
  btnPressed = digitalRead(BTN);
  
  Serial.print(humValue);
  Serial.println();
  
  if(humValue == 100){
    for(int i=0; i<5; i++){
      digitalWrite(myLEDs[i], HIGH);
    }
    
  } else if(humValue == 0){
    for(int i=0; i<5; i++){
      digitalWrite(myLEDs[i], LOW);
    }
    
  }else if(humValue >= 1 && humValue < 30){
    for(int i=0; i < 1; i++){
      digitalWrite(myLEDs[i], HIGH);
    }
    for(int i=1; i < 5; i++){
      digitalWrite(myLEDs[i], LOW);
    }
    
  }else if(humValue >= 30 && humValue < 60){
    for(int i = 0; i < 2; i++){
    digitalWrite(myLEDs[i], HIGH);
    }
    
    for(int i=2; i < 5; i++){
      digitalWrite(myLEDs[i], LOW);
    }
    
    
  }else if(humValue >= 60 && humValue < 90){
    for(int i = 0; i < 3; i++){
    digitalWrite(myLEDs[i], HIGH);
    }
    
    for(int i=3; i < 5; i++){
      digitalWrite(myLEDs[i], LOW);
    }
    
  }else if(humValue >= 90 && humValue < 100){
    for(int i = 0; i < 4; i++){
    digitalWrite(myLEDs[i], HIGH);
    }
    
  }

  
  
  if(humValue < 20){
    tone(BZZ, 1000, 100);
    delay(500);
    
  } else if(humValue > 80){
    tone(BZZ, 700);
    
    if(btnPressed == true){
      noTone(BZZ);
      delay(5000);
    }
    
  } else {
    noTone(BZZ);
    
  }

}
