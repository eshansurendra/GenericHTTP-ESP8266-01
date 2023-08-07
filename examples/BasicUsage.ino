#include <GenericHTTP.h>

const char* SSID = "your_wifi_ssid";
const char* PASSWORD = "your_wifi_password";

GenericHTTP http;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open

  // Initialize the "GenericHTTP" library and connect to Wi-Fi
  http.connectToWiFi(SSID, PASSWORD);
}

void loop() {
  bool success = http.sendHTTPRequest("GET", "example.com", "80", "/path/to/endpoint", nullptr, nullptr);

  if (success) {
    Serial.println("Request successful!");
    // Process the response data here
  } else {
    Serial.println("Request failed!");
  }

  delay(5000);
}
