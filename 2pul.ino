int ledverde=2; 
int ledrojo=3;
int estado=0;     // comparar si mi estado es alto o bajo
int encender=0;    // si mi estado es alto encender el rele 
int anterior=0;    // nos regresa al estado de apagdao 
int     brillo=128;
int val=0;
bool inicio = false;   /// se coloca un inicio como menu



void setup() {
  // put your setup code here, to run once:

 pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, INPUT);
   analogWrite(3, brillo);    //Modifica el brillo del LED por medio de una señal PWM
  /// delay(3000);
 ////   inicio = true; ///////// nos manda directamente al menu o al inicio 


}

void loop() {

  
   
  // put your main code here, to run repeatedly:
 estado = digitalRead(4);

 if (estado == 1)  // si el estado es 0 se enciende el rele

 {
  
    brillo++;      //Aumenta el brillo si se presiona el pulsador

 if (brillo >= 255)
    {
      brillo = 255;    //El brillo no aumenta mas alla de 255
    }

 }

 
 val = digitalRead(5);

 if (val == 1)  // si el estado es 0 se enciende el rele
{    // funcion llamada cuando es diferente a 1
      brillo--;    //Disminuye el brillo si se presiona el pulsador

    if (brillo <= 0)
    {
      brillo = 0;     //El brillo no puede ser menor de cero
      
    }

  }

 if (val && estado == 1)  // si el estado es 0 se enciende el rele
 {
   brillo++;      //Aumenta el brillo si se presiona el pulsador

 if (brillo >= 255)
    {
      brillo = 255;    //El brillo no aumenta mas alla de 255
    }
  }
  
  analogWrite(3, brillo);    //Modifica el brillo del LED por medio de una señal PWM
  delay(50);
  }
