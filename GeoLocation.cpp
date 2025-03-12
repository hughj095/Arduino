#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define GPS module RX and TX pins
#define RXPin 4
#define TXPin 3
#define GPSBaud 9600

// Create software serial port
SoftwareSerial gpsSerial(RXPin, TXPin);

// Create TinyGPS++ object
TinyGPSPlus gps;

void setup() {
    Serial.begin(115200);  // Monitor baud rate
    gpsSerial.begin(GPSBaud);  // GPS baud rate

    Serial.println("GPS module initialized...");
}

void loop() {
    while (gpsSerial.available()) {
        char c = gpsSerial.read();
        gps.encode(c);  // Feed data to GPS parser

        if (gps.location.isUpdated()) {  // New location available
            Serial.print("Latitude: ");
            Serial.print(gps.location.lat(), 6);
            Serial.print(", Longitude: ");
            Serial.println(gps.location.lng(), 6);
        }
    }
}
