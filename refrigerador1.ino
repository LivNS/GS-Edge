// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
float valor_sen=0;
float temperatura=0;
void setup() {
  	pinMode(8, OUTPUT);	
	pinMode(13, OUTPUT);
  	pinMode(10, OUTPUT);//VENTILADOR IZQUIERDO 1
  	pinMode(9, OUTPUT);//VENTILADOR IZQUIERDO 2
  	pinMode(7, OUTPUT);//VENTILADOR DERECHO  1
  	pinMode(6, OUTPUT);//VENTILADOR DERECHO  2
	LCD.begin(16,2);
	LCD.print("-Temperatura:");
	LCD.setCursor(0,1);
	LCD.print("    °C       ");
}

void loop() {
	
  valor_sen = analogRead(A0); //variable que almacenara los datos que tomara el sensor 
  temperatura = ((((valor_sen*5.0)/1024)*1000)-500)/10; //esta formula nos permite la conversion de los datos a grados

  	LCD.setCursor(0,1);
	LCD.print(temperatura);//imprime temperatura en Celcuis
	LCD.setCursor(9,1);
  
  	if (temperatura>=35){
  		digitalWrite(13, HIGH);
  		digitalWrite(8,  LOW);//LED ROJO
      	digitalWrite(10, HIGH);
      	digitalWrite(9, HIGH);
      	digitalWrite(7, HIGH);
      	digitalWrite(6, HIGH);
    }
  	else {
  		digitalWrite(8, HIGH);
  		digitalWrite(13, LOW);
      	digitalWrite(10, LOW);
      	digitalWrite(9, LOW);
      	digitalWrite(7, LOW);
      	digitalWrite(6, LOW);
  	}

  	delay(1000);
}