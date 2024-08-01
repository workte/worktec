#include <Adafruit_NeoPixel.h>

#define PIN        2
#define NUMPIXELS  256

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Patrón de conexión de los píxeles
int pixelMap[8][32] = {
  {0, 15, 16, 31, 32, 47, 48, 63, 64, 79, 80, 95, 96, 111, 112, 127, 128, 143, 144, 159, 160, 175, 176, 191, 192, 207, 208, 223, 224, 239, 240, 255},
  {1, 14, 17, 30, 33, 46, 49, 62, 65, 78, 81, 94, 97, 110, 113, 126, 129, 142, 145, 158, 161, 174, 177, 190, 193, 206, 209, 222, 225, 238, 241, 254},
  {2, 13, 18, 29, 34, 45, 50, 61, 66, 77, 82, 93, 98, 109, 114, 125, 130, 141, 146, 157, 162, 173, 178, 189, 194, 205, 210, 221, 226, 237, 242, 253},
  {3, 12, 19, 28, 35, 44, 51, 60, 67, 76, 83, 92, 99, 108, 115, 124, 131, 140, 147, 156, 163, 172, 179, 188, 195, 204, 211, 220, 227, 236, 243, 252},
  {4, 11, 20, 27, 36, 43, 52, 59, 68, 75, 84, 91, 100, 107, 116, 123, 132, 139, 148, 155, 164, 171, 180, 187, 196, 203, 212, 219, 228, 235, 244, 251},
  {5, 10, 21, 26, 37, 42, 53, 58, 69, 74, 85, 90, 101, 106, 117, 122, 133, 138, 149, 154, 165, 170, 181, 186, 197, 202, 213, 218, 229, 234, 245, 250},
  {6, 9, 22, 25, 38, 41, 54, 57, 70, 73, 86, 89, 102, 105, 118, 121, 134, 137, 150, 153, 166, 169, 182, 185, 198, 201, 214, 217, 230, 233, 246, 249},
  {7, 8, 23, 24, 39, 40, 55, 56, 71, 72, 87, 88, 103, 104, 119, 120, 135, 136, 151, 152, 167, 168, 183, 184, 199, 200, 215, 216, 231, 232, 247, 248}
};

void setup() {
  pixels.begin();
  pixels.show(); // Inicializar todos los píxeles en apagado al inicio
}

void loop() {
  // Estado 1: Cara feliz
  drawHappyFace();
  delay(2000); // Esperar 2 segundos

  // Estado 2: Cara sorprendida
  drawSurprisedFace();
  delay(2000); // Esperar 2 segundos

  // Estado 3: Cara triste
  drawSadFace();
  delay(2000); // Esperar 2 segundos

  // Estado 4: Cara enojada
  drawAngryFace();
  delay(2000); // Esperar 2 segundos
}

void drawHappyFace() {
  // Dibujar cara feliz
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 128)); // Amarillo claro para la cara
  }

  // Dibujar ojos
  pixels.setPixelColor(96, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(97, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(98, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(111, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(112, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(110, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(109, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(113, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(114, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho



// Dibujar ojos
  pixels.setPixelColor(146, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(145, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(144, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(159, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(160, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(158, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(157, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(161, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(162, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho

  
  pixels.setPixelColor(52, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(53, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(59, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(58, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(68, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(69, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(75, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(74, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(84, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(85, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(91, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(90, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(100, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(101, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(107, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(106, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(116, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(117, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(123, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(122, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(132, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(133, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(139, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(138, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(148, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(149, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(155, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(154, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(164, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(165, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(171, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(170, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(180, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(181, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(187, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(186, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(196, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(197, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(203, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(202, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(212, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(213, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(219, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(218, pixels.Color(69, 179, 157)); // Rojo para la boca
  
  
  
  
    
  
  pixels.setPixelColor(50, pixels.Color(69, 179, 157));
  pixels.setPixelColor(51, pixels.Color(69, 179, 157));
  pixels.setPixelColor(61, pixels.Color(69, 179, 157));
  pixels.setPixelColor(60, pixels.Color(69, 179, 157));
  pixels.setPixelColor(66, pixels.Color(69, 179, 157));
  pixels.setPixelColor(67, pixels.Color(69, 179, 157));


  pixels.setPixelColor(205, pixels.Color(69, 179, 157));
  pixels.setPixelColor(204, pixels.Color(69, 179, 157));
  pixels.setPixelColor(210, pixels.Color(69, 179, 157));
  pixels.setPixelColor(211, pixels.Color(69, 179, 157));
  pixels.setPixelColor(220, pixels.Color(69, 179, 157));
  pixels.setPixelColor(221, pixels.Color(69, 179, 157));
  
  pixels.show(); // Mostrar la cara feliz
}

void drawSadFace() {
  // Dibujar cara triste
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(i, pixels.Color(128, 128, 255)); // Azul claro para la cara
  }

  // Dibujar ojos
  pixels.setPixelColor(96, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(97, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(98, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(111, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(112, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(113, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(114, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(110, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(109, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho


  // Dibujar ojos
  pixels.setPixelColor(146, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(145, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(144, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(159, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(160, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(158, pixels.Color(0,0,0)); // Blanco para el ojo derecho
  pixels.setPixelColor(157, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(161, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(162, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  
  
  pixels.setPixelColor(52, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(53, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(59, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(58, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(68, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(69, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(75, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(74, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(84, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(85, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(91, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(90, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(100, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(101, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(107, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(106, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(116, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(117, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(123, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(122, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(132, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(133, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(139, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(138, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(148, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(149, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(155, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(154, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(164, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(165, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(171, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(170, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(180, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(181, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(187, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(186, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(196, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(197, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(203, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(202, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(212, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(213, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(219, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(218, pixels.Color(69, 179, 157)); // Rojo para la boca
  
  
  

  pixels.show(); // Mostrar la cara triste
}

void drawSurprisedFace() {
  // Dibujar cara sorprendida
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 128)); // Amarillo claro para la cara
  }

  
  // Dibujar ojos
  pixels.setPixelColor(96, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(113, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(114, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(111, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(112, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(110, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(109, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(98, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(97, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho


// Dibujar ojos
  pixels.setPixelColor(161, pixels.Color(255, 255, 255)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(162, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(144, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(159, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho
  pixels.setPixelColor(160, pixels.Color(255, 255, 255)); // Blanco para el ojo derecho

  pixels.setPixelColor(158, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(157, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(145, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  pixels.setPixelColor(146, pixels.Color(0, 0, 0)); // Blanco para el ojo derecho
  
  
  pixels.setPixelColor(52, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(53, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(59, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(58, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(68, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(69, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(75, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(74, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(84, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(85, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(91, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(90, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(100, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(101, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(107, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(106, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(116, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(117, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(123, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(122, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(132, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(133, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(139, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(138, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(148, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(149, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(155, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(154, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(164, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(165, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(171, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(170, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(180, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(181, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(187, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(186, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(196, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(197, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(203, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(202, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(212, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(213, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(219, pixels.Color(69, 179, 157)); // Rojo para la boca
  pixels.setPixelColor(218, pixels.Color(69, 179, 157)); // Rojo para la boca
  
  
  
  pixels.setPixelColor(54, pixels.Color(69, 179, 157));
  pixels.setPixelColor(55, pixels.Color(69, 179, 157));
  pixels.setPixelColor(57, pixels.Color(69, 179, 157));
  pixels.setPixelColor(56, pixels.Color(69, 179, 157));
  pixels.setPixelColor(70, pixels.Color(69, 179, 157));
  pixels.setPixelColor(71, pixels.Color(69, 179, 157));



  pixels.setPixelColor(217, pixels.Color(69, 179, 157));
  pixels.setPixelColor(216, pixels.Color(69, 179, 157));
  pixels.setPixelColor(214, pixels.Color(69, 179, 157));
  pixels.setPixelColor(215, pixels.Color(69, 179, 157));
  pixels.setPixelColor(201, pixels.Color(69, 179, 157));
  pixels.setPixelColor(200, pixels.Color(69, 179, 157));
  pixels.show(); // Mostrar la cara sorprendida
}

void drawAngryFace() {
  // Dibujar cara enojada
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 128, 128)); // Rojo claro para la cara
  }
 
  // Dibujar ojos
  pixels.setPixelColor(96, pixels.Color(146, 43, 33)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(97, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(98, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(111, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(112, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho

  pixels.setPixelColor(110, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(109, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(113, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(114, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho


// Dibujar ojos
  pixels.setPixelColor(146, pixels.Color(146, 43, 33)); // Blanco para el ojo izquierdo
  pixels.setPixelColor(145, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(144, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(159, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(160, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho

  pixels.setPixelColor(158, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(157, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(161, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  pixels.setPixelColor(162, pixels.Color(146, 43, 33)); // Blanco para el ojo derecho
  
  // Dibujar boca sonriente
  pixels.setPixelColor(52, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(53, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(59, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(58, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(68, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(69, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(75, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(74, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(84, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(85, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(91, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(90, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(100, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(101, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(107, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(106, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(116, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(117, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(123, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(122, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(132, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(133, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(139, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(138, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(148, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(149, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(155, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(154, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(164, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(165, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(171, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(170, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(180, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(181, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(187, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(186, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(196, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(197, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(203, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(202, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(212, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(213, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(219, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.setPixelColor(218, pixels.Color(146, 43, 33)); // Rojo para la boca
  
    pixels.setPixelColor(121, pixels.Color(146, 43, 33)); // Rojo para la boca
    pixels.setPixelColor(120, pixels.Color(146, 43, 33)); // Rojo para la boca
    pixels.setPixelColor(134, pixels.Color(146, 43, 33)); // Rojo para la boca
    pixels.setPixelColor(135, pixels.Color(146, 43, 33)); // Rojo para la boca
    pixels.setPixelColor(137, pixels.Color(146, 43, 33)); // Rojo para la boca
    pixels.setPixelColor(136, pixels.Color(146, 43, 33)); // Rojo para la boca
  pixels.show(); // Mostrar la cara enojada
}
