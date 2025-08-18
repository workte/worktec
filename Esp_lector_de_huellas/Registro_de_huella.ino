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

uint8_t id;

void setup()
{
  Serial.begin(9600);
  while (!Serial);  // Para Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nRegistro de huella digital con sensor Adafruit");

  // Configurar la velocidad de datos para el sensor
  finger.begin(57600);

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
  Serial.println("¡Listo para registrar una huella digital!");
  Serial.println("Por favor, escribe el número de ID (de 1 a 127) en el que deseas guardar esta huella...");
  id = readnumber();
  if (id == 0) { // El ID 0 no está permitido, intenta de nuevo
     return;
  }
  Serial.print("Registrando ID #");
  Serial.println(id);

  while (! getFingerprintEnroll() );
}

uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.print("Esperando un dedo válido para registrar como #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error al capturar la imagen");
      break;
    default:
      Serial.println("Error desconocido");
      break;
    }
  }

  // Imagen capturada correctamente
  p = finger.image2Tz(1);
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

  Serial.println("Retira el dedo");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }

  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Coloca el mismo dedo nuevamente");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagen tomada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error al capturar la imagen");
      break;
    default:
      Serial.println("Error desconocido");
      break;
    }
  }

  // Imagen capturada correctamente
  p = finger.image2Tz(2);
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

  // Ambas imágenes convertidas correctamente
  Serial.print("Creando modelo para #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("¡Las huellas coinciden!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Las huellas no coinciden");
    return p;
  } else {
    Serial.println("Error desconocido");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("¡Huella guardada correctamente!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("No se pudo guardar en esa ubicación");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error al escribir en la memoria flash");
    return p;
  } else {
    Serial.println("Error desconocido");
    return p;
  }

  return true;
}
