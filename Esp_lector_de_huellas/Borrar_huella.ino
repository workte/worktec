/***************************************************
  Este es un ejemplo para nuestro sensor óptico de huellas digitales

  Diseñado específicamente para funcionar con el sensor de huellas de Adafruit
  ----> http://www.adafruit.com/products/751

  Estos módulos usan comunicación Serial TTL, se requieren 2 pines
  para la conexión.
  Adafruit invierte tiempo y recursos en proveer este código de fuente abierta,
  por favor apoya a Adafruit y al hardware de código abierto comprando
  productos de Adafruit.

  Escrito por Limor Fried/Ladyada para Adafruit Industries.
  Licencia BSD, todo el texto anterior debe ser incluido en cualquier redistribución
 ****************************************************/

#include <Adafruit_Fingerprint.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// Para Arduino UNO y otros sin puerto serie por hardware, usamos SoftwareSerial...
// pin #2 es la ENTRADA desde el sensor (cable VERDE)
// pin #3 es la SALIDA hacia Arduino (cable BLANCO)
// Configuramos el puerto serie con SoftwareSerial..
SoftwareSerial mySerial(D1,D2);

#else
// En Leonardo/M0/etc, y otros con puerto serie por hardware, ¡usamos hardware serial!
// #0 es el cable verde, #1 es el cable blanco
#define mySerial Serial1

#endif

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  Serial.begin(9600);
  while (!Serial);  // Para Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nEliminar huella");

  // Configurar la velocidad de datos del sensor
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("¡Sensor de huellas encontrado!");
  } else {
    Serial.println("No se encontró el sensor de huellas :(");
    while (1);
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop()   // se ejecuta en bucle
{
  Serial.println("Por favor, escribe el número de ID (de 1 a 127) que deseas eliminar...");
  uint8_t id = readnumber();
  if (id == 0) { // El ID 0 no está permitido, intenta de nuevo
     return;
  }

  Serial.print("Eliminando ID #");
  Serial.println(id);

  deleteFingerprint(id);
}

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("¡Huella eliminada!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación");
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("No se pudo eliminar en esa ubicación");
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error al escribir en la memoria flash");
  } else {
    Serial.print("Error desconocido: 0x"); Serial.println(p, HEX);
  }

  return p;
}
