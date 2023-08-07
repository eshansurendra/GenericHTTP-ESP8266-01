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
  // Set custom headers
  const char* customHeaders = "Authorization: Bearer YOUR_ACCESS_TOKEN\r\n";

  // Send an HTTP GET request with custom headers
  bool success = http.sendHTTPRequest("GET", "example.com", "80", "/path/to/endpoint", customHeaders, nullptr);

  if (success) {
    Serial.println("Request successful!");

    // Read and parse the response data
    String response;
    while (http.espSerial.available()) {
      char c = http.espSerial.read();
      response += c;
    }
    Serial.println("Response: " + response);
    
    // Process the response data here
  } else {
    Serial.println("Request failed!");
  }

  delay(5000);
}
