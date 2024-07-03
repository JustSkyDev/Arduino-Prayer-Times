#include "PrayTimes.h"

PrayTimes JWS;

// Lokasi Los Angeles, California, USA.
double map_latitude = 34.0522;
double map_longitude = 118.2437;

int zona_waktu = -7;

int tahun = 2024;
int bulan = 6;
int tanggal = 13;

void setup() {
  Serial.begin(9600);

  // Set koordinat
  JWS.SetCoordinate(map_latitude, map_longitude);

  // Set zona waktunya
  JWS.SetTimezone(zona_waktu);

  // Adjust tanggalnya
  JWS.AdjustTime(tahun, bulan, tanggal);


  int subuh_jam = JWS.getFajr().hours;
  int subuh_menit = JWS.getFajr().minutes;

  Serial.print("Subuh Jam: ");
  Serial.print(subuh_jam);
  Serial.print(":");
  Serial.print(subuh_menit);
}

void loop() {
}