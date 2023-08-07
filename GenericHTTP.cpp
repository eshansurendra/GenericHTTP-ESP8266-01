#include "GenericHTTP.h"

GenericHTTP::GenericHTTP() : espSerial(WIFI_PIN_RX, WIFI_PIN_TX) {
  espSerial.begin(9600);
}

bool GenericHTTP::connectToWiFi(const char* ssid, const char* password) {
  // Reset ESP8266 module
  sendCommand("AT+RST", 5000, "ready");

  // Set ESP8266 to client mode
  sendCommand("AT+CWMODE=1", 2000, "OK");

  // Connect to Wi-Fi network
  Serial.println("Connecting to Wi-Fi...");
  sendCommand("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"", 10000, "OK");

  // Check if the Wi-Fi connection was successful
  return espSerial.find("OK");
}

bool GenericHTTP::sendHTTPRequest(const char* method, const char* host, const char* port, const char* uri, const char* headers, const char* body) {
  return sendHttpRequest(method, host, port, uri, headers, body);
}

bool GenericHTTP::sendHttpRequest(const char* method, const char* host, const char* port, const char* uri, const char* headers, const char* body) {
  String request = String(method) + " " + uri + " HTTP/1.1\r\n";
  request += "Host: " + String(host) + "\r\n";
  request += headers;
  request += "\r\n";
  if (body) {
    request += body;
  }

  sendCommand("AT+CIPMUX=1", 5000, "OK");
  sendCommand("AT+CIPSTART=0,\"TCP\",\"" + String(host) + "\"," + String(port), 10000, "OK");
  sendCommand("AT+CIPSEND=0," + String(request.length() + 2), 5000, ">");
  espSerial.println(request);
  delay(1000); // Give some time for the response

  // Read and parse the value from the response
  String response;
  while (espSerial.available())
  {
    char c = espSerial.read();
    response += c;
  }
  Serial.println(response);

  // Check if the response contains the expected result
  bool success = response.indexOf("200 OK") != -1;

  sendCommand("AT+CIPCLOSE=0", 5000, "OK");

  return success;
}

void GenericHTTP::sendCommand(String command, unsigned int timeout, const char* expected) {
  espSerial.println(command);
  unsigned long startTime = millis();
  String response;
  
  while (millis() - startTime < timeout)
  {
    while (espSerial.available())
    {
      char c = espSerial.read();
      response += c;
    } 
    if (response.indexOf(expected) != -1)
    {
      break;
    }
  }

  // Process the response as needed
  // You can check for specific responses from the ESP8266 and handle them accordingly

  response = ""; // Reset the response variable for the next use
}
