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
  Serial.println("\n\nPrueba de detección de huella con Adafruit");

  // Configurar la velocidad de datos para el sensor
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("¡Sensor de huellas encontrado!");
  } else {
    Serial.println("No se encontró el sensor de huellas :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Leyendo parámetros del sensor"));
  finger.getParameters();
  Serial.print(F("Estado: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("ID del sistema: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacidad: ")); Serial.println(finger.capacity);
  Serial.print(F("Nivel de seguridad: ")); Serial.println(finger.security_level);
  Serial.print(F("Dirección del dispositivo: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Tamaño de paquete: ")); Serial.println(finger.packet_len);
  Serial.print(F("Velocidad en baudios: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("El sensor no contiene ninguna huella registrada. Por favor ejecuta el ejemplo 'enroll'.");
  }
  else {
    Serial.println("Esperando un dedo válido...");
    Serial.print("El sensor contiene "); Serial.print(finger.templateCount); Serial.println(" huellas registradas");
  }
}

void loop()   // se ejecuta en bucle
{
  getFingerprintID();
  delay(50); // no es necesario ejecutarlo a máxima velocidad
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No se detectó dedo");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error al capturar imagen");
      return p;
    default:
      Serial.println("Error desconocido");
      return p;
  }

  // Imagen capturada correctamente
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagen demasiado desordenada");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      return p;
    case FINGERPRINT_FEATUREFAIL:
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudieron encontrar características de la huella");
      return p;
    default:
      Serial.println("Error desconocido");
      return p;
  }

  // Imagen convertida correctamente
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("¡Huella encontrada!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("No se encontró coincidencia");
    return p;
  } else {
    Serial.println("Error desconocido");
    return p;
  }

  // Coincidencia encontrada
  Serial.print("Se encontró el ID #"); Serial.print(finger.fingerID);
  Serial.print(" con un nivel de confianza de "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// Devuelve -1 si falla, en caso contrario devuelve el ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // Coincidencia encontrada
  Serial.print("Se encontró el ID #"); Serial.print(finger.fingerID);
  Serial.print(" con un nivel de confianza de "); Serial.println(finger.confidence);
  return finger.fingerID;
}
