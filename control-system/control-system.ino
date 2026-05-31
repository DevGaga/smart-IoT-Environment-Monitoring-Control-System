#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2       // Declaring and initializing the DHTPIN to use
#define DHTTYPE DHT11  // Type of Sensor (DHT11 / DHT21 / DHT22)

DHT_Unified dht(DHTPIN, DHTTYPE);  // Mounting the Pin of the DHT type
uint32_t delayMS;                  // delay in Milliseconds (to be obtained from the Sensors Minimun Delay)

// ── Struct to hold sensor readings ──────────────────────────────────────────
struct SensorReading {
  float temperature;  // Holds Temperature value
  float humidity;     // Holds Humidity value
  bool tempValid;     // Contain the Boolean value of wheather the received temperature is valid or not
  bool humidValid;    // Contain the Boolean value of wheather the received Humidity is valid or not
};

// ── Returns a populated SensorReading struct ─────────────────────────────────
SensorReading readDHTSensor() {
  SensorReading reading;  // Declares the SensorReading
  sensors_event_t event;  // Declares sensor events

  // ----- Read/Default Temperature Values -----
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    reading.temperature = 0.0;  // Set Temperature value to 0.0
    reading.tempValid = false;  // Set Temparature validity to false
  } else {
    reading.temperature =
      event.temperature;       // Set Temperature value to the value read from the sensor
    reading.tempValid = true;  // Set Temperature validity to true
  }

  // ----- Read/Default Humidity Values -----
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    reading.humidity = 0.0;      // Set Humidity value to 0.0
    reading.humidValid = false;  // Set Humidity validity to false
  } else {
    reading.humidity =
      event.relative_humidity;  // Set Humidity value to the value read from the sensor
    reading.humidValid = true;  // Set Humidity validity to true
  }

  return reading;
}

// ── Prints a SensorReading to Serial ─────────────────────────────────────────
void printReading(const SensorReading& reading) {
  if (!reading.tempValid) {
    Serial.println(F("Error reading temperature!"));
  } else {
    Serial.print(F("Temperature: "));
    Serial.print(reading.temperature);
    Serial.println(F("°C"));
  }

  if (!reading.humidValid) {
    Serial.println(F("Error reading humidity!"));
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(reading.humidity);
    Serial.println(F("%"));
  }
}

// ── Arduino lifecycle ─────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  delay(delayMS);
  SensorReading reading = readDHTSensor();
  printReading(reading);

  // Data Sent to the Wifi Cappable Microcontroller.
  if (reading.tempValid && reading.humidValid) {
    Serial1.print(F("T:"));
    Serial1.print(reading.temperature);
    Serial1.print(F(",H:"));
    Serial1.println(reading.humidity);  // \n marks end of message
  }
}