#include "PrayTimes.h"

PrayTimes JWS; // Create PrayTimes object

// Set your location
double map_latitude = 34.0522;  // Replace with your latitude
double map_longitude = 118.2437; // Replace with your longitude

// Set timezone (optional, automatic detection if not set)
int time_zone = -7; // Replace with your timezone offset

// Adjust date (optional, defaults to current date)
int years = 2024;    // Replace with the desired year
int month = 6;       // Replace with the desired month
int day = 13;     // Replace with the desired day

void setup() 
{
  // Start the Serial Communication
  Serial.begin(9600);

  // Initialize PrayTimes with location
  JWS.SetCoordinate(map_latitude, map_longitude);

  // Set timezone if needed
  JWS.SetTimezone(time_zone);

  // Adjust date if needed
  JWS.AdjustTime(years, month, day);

  // Get Fajr time (example)
  int fajr_hours = JWS.getFajr().hours;
  int fajr_minutes = JWS.getFajr().minutes;

  // Print to Serial Monitor
  Serial.print("Fajr: ");
  Serial.print(fajr_hours);
  Serial.print(":");
  Serial.print(fajr_minutes);
}

void loop() 
{
  // Your main code
}
