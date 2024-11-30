# SmartThermometer

Un projet Arduino pour mesurer et afficher la température en temps réel à l'aide d'un capteur DHT11/DHT22 et d'un écran LCD. Une LED s'allume si la température dépasse un seuil prédéfini.

## Matériel requis
- Arduino Uno (ou équivalent)
- Capteur DHT11 ou DHT22
- Écran LCD 16x2 avec interface I2C
- Résistance de 220 Ohms
- Une LED
- Fils de connexion et breadboard

## Fonctionnalités
1. Lecture et affichage de la température.
2. Alerte LED si la température dépasse un seuil.
3. Affichage des données sur le moniteur série.

## Instructions
1. Clonez ce dépôt.
2. Connectez les composants selon le schéma fourni.
3. Téléversez le code sur votre carte Arduino.

## Schéma de connexion
- **DHT11/DHT22** :
  - VCC -> 5V
  - GND -> GND
  - DATA -> Pin 2
- **LCD** :
  - Connectez via un module I2C (SDA -> A4, SCL -> A5 sur Arduino Uno).
- **LED** :
  - Anode -> Résistance 220 Ohms -> Pin 9
  - Cathode -> GND
