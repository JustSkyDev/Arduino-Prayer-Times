## Arduino Prayer Times Library

This Arduino library provides a simple way to calculate prayer times based on your location and date. It uses astronomical calculations to determine the precise times for each prayer, taking into account factors such as latitude, longitude, and timezone.

### Features

- **Accurate Prayer Time Calculations:** Utilizes precise astronomical algorithms for reliable results.
- **Customization:** Adjust parameters like Fajr and Isha angles for different calculation methods.
- **Easy Integration:** Simple interface for seamless inclusion in Arduino projects.
- **Timezone Support:** Automatically detects or manually sets timezone for accurate timings.
- **Complete Prayer Set:** Calculates Imsak, Fajr, Sunrise, Dhuhr, Asr, Sunset, Maghrib, Isha, and Midnight.

### Installation

1. **Download:**
    - Clone the repository using the command:
    ```sh
    git clone https://github.com/JustSkyDev/Arduino-Prayer-Times.git
    ```
    - Or, download the ZIP file from the repository page and extract it to a known location.

2. **Include the Library:**
    - Open the Arduino IDE.
    - Go to `Sketch -> Include Library -> Add .ZIP Library..`.

3. **Verify Installation:**
    - Go to `Sketch -> Include Library` and check if `PrayTimes` appears in the list.
    - Create a new sketch or open an existing one.
    - Add the following line at the beginning of your sketch to include the library:
    ```c++
    #include <PrayTimes.h>
    ```
4. **Example Usage:**
    - You can use the example code provided in the library to verify that it's working correctly.
    - Open an example sketch from the library: `File -> Examples -> PrayTimes -> Basic`.
    - Upload the sketch to your Arduino board to see the library in action.

### Additional Tips

- Ensure you have the latest version of the Arduino IDE installed.
- If you encounter any issues, check the library documentation or the repository's README for additional setup instructions and troubleshooting tips.

### Example

```c++
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

```

### API

#### Methods

- **void SetCoordinate(double latitude, double longitude, bool auto_timezone = true):** Set the geographical coordinates.
- **void AdjustTime(int year, int month, int day):** Adjust the date.
- **void SetTimezone(int timezone):** Set the timezone.
- **void AdjustDegree(double fajr_degree, double isha_degree):** Adjust the calculation degrees for Fajr and Isha.
- **HrsMin getImsak():** Get the Imsak time.
- **HrsMin getFajr():** Get the Fajr time.
- **HrsMin getSunrise():** Get the Sunrise time.
- **HrsMin getDhuhr():** Get the Dhuhr time.
- **HrsMin getAsr():** Get the Asr time.
- **HrsMin getSunset():** Get the Sunset time.
- **HrsMin getMaghrib():** Get the Maghrib time.
- **HrsMin getIsha():** Get the Isha time.
- **HrsMin getMidnight():** Get the Midnight time.

### Structures

#### HrsMin

```c++
struct HrsMin
{
    double raw;
    int hours;
    int minutes;
};

```

### Additional Notes

- You can adjust the `fajr_degree` and `isha_degree` parameters in `PrayTimes::AdjustDegree(double fajr_degree, double isha_degree)` to use different calculation methods (e.g., 15 degrees for Fajr and Isha for Shafi'i school).

### Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve this library.

### License

This library is licensed under the [MIT License](/LICENSE).
