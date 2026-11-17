# Arduino Morse Code Translator

A Morse code translator built with Arduino as a beginner project to explore programming and electronics.

## About the Project

This project converts text entered through the Arduino Serial Monitor into Morse code. The corresponding dots and dashes are displayed in the Serial Monitor and transmitted as light signals using an LED.

The program supports the letters A-Z, numbers 0-9, and the punctuation marks `.`, `,` and `?`.

## Hardware

- Elegoo UNO R3 (Arduino-compatible)
- LED
- Current-limiting resistor (220-330 ohms)
- Breadboard and jumper wires
- USB cable

The LED is controlled through digital pin 8.

## How to Use

1. Open `MorsecodeTranslator.ino` in the Arduino IDE.
2. Connect the Arduino board to your computer.
3. Select the correct board and port.
4. Upload the program.
5. Open the Serial Monitor.
6. Set the baud rate to 9600 and the line ending to "Newline".
7. Enter a text message and send it.

The Arduino translates the supported characters into Morse code and flashes the LED accordingly.

## Development History

The project was developed in five stages:

1. **SOS signal:** Created functions for dots and dashes and used them to transmit SOS.
2. **Morse code arrays:** Introduced arrays to associate letters with Morse code sequences.
3. **Single character translation:** Implemented the search and translation of individual letters.
4. **Text processing:** Extended the program to process multiple characters and spaces.
5. **Serial input:** Added interactive text input, the complete alphabet, numbers, selected punctuation marks, and output through the Serial Monitor.

The development stages were originally created locally and later documented as individual commits on GitHub.

## Future Improvements

- Improve input validation and handling of unsupported characters.
- Refine the timing and handling of spaces.
- Review and simplify the program structure.
- Explore additional input and output options.
- Implement a Morse code receiver: Simulate communication between two Arduino boards in Tinkercad, allowing one board to transmit Morse code and the other to decode it into text. Explore LAN or Wi-Fi communication as a future extension.
