#include <TTP229.h> // On inclut la bibliothèque TTP229 pour Arduino.

const int SCL_PIN = 2;  // La broche SCL est connectée à la broche 2 de l’Arduino. 
const int SDO_PIN = 3;  // La broche SDO est connectée à la broche 3 de l’Arduino.
TTP229 ttp229(SCL_PIN, SDO_PIN); // On crée une instance de la classe TTP229 et l’initialise avec les broches SCL et SDO pour connecter le clavier TTP229.

void setup()
{
  Serial.begin(115200); // On initialise la communication série à une vitesse de 115200 bauds. 
  Serial.println("Commencez à appuyer sur une touche à la fois!");// On affiche un message sur le moniteur série.
}

void loop()
{
  uint8_t key = ttp229.ReadKey16(); //  On lit les entrées du clavier. et les afficher sur le moniteur série.
  if (key) Serial.println(key);//On affiche les entrées du clavier sur le moniteur série.
}
