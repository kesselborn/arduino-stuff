# Malroboter für den Girl's Day 2019
... blabla

## Voraussetzungen
- [snap4arduino](http://snap4arduino.rocks/)
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)

## Quellcode von snap4arduino zu Arduino exportieren

Siehe [Screencast](./exporting-code.mp4)

Hier gibt es ein paar seltsame Schritte:
- der gesamte Code muss in den "setze code auf" Block gezogen werden
- die Variable "code" muss sichtbar gemacht werden
- dann auf das Fenster klicken und exportieren
- Datei abspeichern, ausgeben und die Ausgabe in die Zwischenablage kopieren
- dann in die Arduino-IDE kopieren **auf macos kann nicht einfach die Datei geöffnet werden, da es Encoding-Probleme gibt**

## Arduino-IDE-Einstellungen
- Board: "Arduino Nano"
- Prozessor: "ATmega 328p (Old Bootloader)

## Malroboter für snap4arduino vorbereiten
Um snap4arduino zu nutzen, muss der Malroboter eine bestimmte Firmware bekommen. Dazu in der Arduino-IDE folgendes Beispiel öffnen:

    Datei/Beispiele/Firmdata/StandardFirmdata

und auf den Arduino hochladen. Danach ist es möglich, sich in snap4arduino zu verbinden.

## Work in progress
- zur Zeit erzeugen die Buchstabenblöcke noch keinen Arduino-Code, weshalb das Beispielprogramm alle Blöcke expandiert hat ... dies ist relativ einfach zu fixen (mache ich noch)
- [nodemcu](https://en.wikipedia.org/wiki/NodeMCU) statt Arduino-Nano probieren:
  - bringt Wifi-Modul mit und ist unbedeutend (<1 €) teuerer
  - Firmware-Flashen via Wifi geht wohl
  - keine Ahnung ob genügend GPIO-Ports zur verfügung stehen
  - empfohlen werden [Boards mit CP2102](https://www.ebay.de/itm/NodeMCU-v3-2-ESP8266-Dev-Kit-WIFI-Lolin-Amica-CP2102-v2-Arduino-IOT/252712258856?hash=item3ad6d30d28:g:TtsAAOSwlkpb3ZkV:rk:6:pf:0)
- Servo statt Schrittmotor für Stift heben / senken: Servo ist schneller, billiger, einfacher zu steuern und braucht nur einen Port statt 4
- Druckvorlage für das Breadboard erstellen ... da gibt es bestimmt 'ne Software für
