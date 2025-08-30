#define BLYNK_TEMPLATE_ID "....."
#define BLYNK_TEMPLATE_NAME "....."
#define BLYNK_AUTH_TOKEN "....."

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

// === WIDGET TERMINAL ===
WidgetTerminal terminal(V5);

// === CONEXIÓN SENSOR (ESP8266) ===
SoftwareSerial mySerial(D1, D2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// === LEDS ===
#define LED_VERDE D5
#define LED_ROJO  D6

// WiFi
char ssid[] = "NOMBRE";
char pass[] = "CLAVE";

// ====== Estados ======
enum Mode {
  MODE_IDENTIFY = 0,
  MODE_WAIT_ENROLL_ID,
  MODE_WAIT_ENROLL_NAME,
  MODE_WAIT_DELETE_ID,
  MODE_ENROLL,
  MODE_DELETE
};
Mode mode = MODE_IDENTIFY;

// ID actual y nombre
int currentID = 1;
String currentName = "";

// === Estructura para personas ===
struct Persona {
  int id;
  String nombre;
};
Persona personas[50];  // hasta 50 registros
int totalPersonas = 0;

// ====== Helper para imprimir en Serial y en Terminal ======
void termPrint(String msg) {
  Serial.println(msg);
  terminal.println(msg);
  terminal.flush();
}

// Prototipos
uint8_t enrollAtID(uint8_t id);
uint8_t deleteAtID(uint8_t id);
int identifyOnce();

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, LOW);

  termPrint("\n=== Sistema de Huellas con Blynk ===");
  termPrint("Flujo: V0=Guardar | V1=Eliminar | V2=Lista");
  termPrint(" - Escribe ID en Terminal después de V0 o V1.");
  termPrint(" - Después de ID, escribe el NOMBRE en Terminal (para guardar).");

  finger.begin(57600);
  delay(5);

  if (finger.verifyPassword()) {
    termPrint("Sensor de huellas encontrado.");
  } else {
    termPrint("ERROR: No se encontró el sensor de huellas.");
    while (1) { delay(1); }
  }

  finger.getParameters();
  finger.getTemplateCount();
  termPrint("Huellas guardadas: " + String(finger.templateCount));

  mode = MODE_IDENTIFY;
}

void loop() {
  Blynk.run();

  // siempre identificar
  if (mode == MODE_IDENTIFY) {
    identifyOnce();
    delay(50);
  }
}

// === TERMINAL (para escribir el ID o nombre) ===
BLYNK_WRITE(V5) {
  String cmd = param.asStr();

  // Si estamos esperando NOMBRE
  if (mode == MODE_WAIT_ENROLL_NAME) {
    currentName = cmd;
    termPrint("📛 Nombre recibido: " + currentName);

    // Ahora registrar la huella
    uint8_t r = enrollAtID(currentID);
    if (r == FINGERPRINT_OK) {
      // ✅ Guardamos en la lista SOLO si la huella se registró bien
      personas[totalPersonas].id = currentID;
      personas[totalPersonas].nombre = currentName;
      totalPersonas++;

      termPrint("✔ Huella guardada correctamente en ID #" + String(currentID) +
                " → " + currentName);

      // LED Verde (OK)
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_ROJO, LOW);
      delay(2000);
      digitalWrite(LED_VERDE, LOW);

    } else {
      termPrint("✖ Falló el registro. Código: 0x" + String(r, HEX));

      // LED Rojo (Error)
      digitalWrite(LED_ROJO, HIGH);
      digitalWrite(LED_VERDE, LOW);
      delay(2000);
      digitalWrite(LED_ROJO, LOW);
    }

    mode = MODE_IDENTIFY;
    return;
  }

  // Si esperamos un ID para guardar
  if (mode == MODE_WAIT_ENROLL_ID) {
    int id = cmd.toInt();
    if (id <= 0) {
      termPrint("⚠ Ingresa un número válido mayor a 0");
      return;
    }
    currentID = id;
    termPrint("✅ ID recibido para GUARDAR: " + String(currentID));
    termPrint("✍ Ahora escribe el NOMBRE en la Terminal.");
    mode = MODE_WAIT_ENROLL_NAME;
    return;
  }

  // Si esperamos un ID para eliminar
  if (mode == MODE_WAIT_DELETE_ID) {
    int id = cmd.toInt();
    if (id <= 0) {
      termPrint("⚠ Ingresa un número válido mayor a 0");
      return;
    }
    currentID = id;
    termPrint("✅ ID recibido para ELIMINAR: " + String(currentID));
    uint8_t r = deleteAtID(currentID);
    if (r == FINGERPRINT_OK) {
      termPrint("✔ Huella eliminada ID #" + String(currentID));
      // eliminar de la lista también
      for (int i = 0; i < totalPersonas; i++) {
        if (personas[i].id == currentID) {
          for (int j = i; j < totalPersonas - 1; j++) {
            personas[j] = personas[j + 1];
          }
          totalPersonas--;
          break;
        }
      }

      // LED Verde para éxito
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_ROJO, LOW);
      delay(2000);
      digitalWrite(LED_VERDE, LOW);

    } else {
      termPrint("✖ No se pudo eliminar. Código: 0x" + String(r, HEX));

      // LED Rojo en fallo
      digitalWrite(LED_ROJO, HIGH);
      digitalWrite(LED_VERDE, LOW);
      delay(2000);
      digitalWrite(LED_ROJO, LOW);
    }
    mode = MODE_IDENTIFY;
    return;
  }
}

// === BOTÓN GUARDAR (V0) ===
BLYNK_WRITE(V0) {
  if (param.asInt() == 1) {
    termPrint("\n[GUARDAR] Escribe un ID en la Terminal para registrar la huella.");
    mode = MODE_WAIT_ENROLL_ID;
  }
}

// === BOTÓN ELIMINAR (V1) ===
BLYNK_WRITE(V1) {
  if (param.asInt() == 1) {
    termPrint("\n[ELIMINAR] Escribe un ID en la Terminal para borrar la huella.");
    mode = MODE_WAIT_DELETE_ID;
  }
}

// === BOTÓN LISTA (V2) ===
BLYNK_WRITE(V2) {
  if (param.asInt() == 1) {
    termPrint("\n📋 Lista de Personas Registradas:");
    if (totalPersonas == 0) {
      termPrint("⚠ No hay personas registradas.");
    }
    for (int i = 0; i < totalPersonas; i++) {
      termPrint("ID #" + String(personas[i].id) + " → " + personas[i].nombre);
    }
  }
}

// ===== Identificación (una pasada) =====
int identifyOnce() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    // Buscar el nombre
    String nombre = "Desconocido";
    for (int i = 0; i < totalPersonas; i++) {
      if (personas[i].id == finger.fingerID) {
        nombre = personas[i].nombre;
        break;
      }
    }
    termPrint("✅ Huella reconocida: ID #" + String(finger.fingerID) +
              " → " + nombre +
              " (Confianza: " + String(finger.confidence) + ")");

    // LED Verde
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_ROJO, LOW);
    delay(2000);
    digitalWrite(LED_VERDE, LOW);

    return finger.fingerID;
  } else {
    termPrint("❌ Huella no encontrada.");
    // LED Rojo
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    delay(2000);
    digitalWrite(LED_ROJO, LOW);
  }
  return -1;
}

// ===== Registro (enroll) =====
uint8_t enrollAtID(uint8_t id) {
  int p = -1;
  termPrint("Coloca el dedo para ID #" + String(id));

  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    if (p == FINGERPRINT_NOFINGER) { delay(50); continue; }
    if (p == FINGERPRINT_PACKETRECIEVEERR) { termPrint("Error de comunicación"); return p; }
    if (p == FINGERPRINT_IMAGEFAIL) { termPrint("Error al capturar imagen"); return p; }
  }
  termPrint("Imagen tomada");
  p = finger.image2Tz(1);
  if (p != FINGERPRINT_OK) return p;

  termPrint("Retira el dedo...");
  delay(1500);
  while (finger.getImage() != FINGERPRINT_NOFINGER) { delay(50); }

  termPrint("Coloca el MISMO dedo otra vez");
  p = -1;
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    if (p == FINGERPRINT_NOFINGER) { delay(50); continue; }
    if (p == FINGERPRINT_PACKETRECIEVEERR) { termPrint("Error de comunicación"); return p; }
    if (p == FINGERPRINT_IMAGEFAIL) { termPrint("Error al capturar imagen"); return p; }
  }
  termPrint("Imagen tomada (2)");
  p = finger.image2Tz(2);
  if (p != FINGERPRINT_OK) return p;

  p = finger.createModel();
  if (p != FINGERPRINT_OK) return p;

  p = finger.storeModel(id);
  return p;
}

// ===== Eliminar por ID =====
uint8_t deleteAtID(uint8_t id) {
  return finger.deleteModel(id);
}

