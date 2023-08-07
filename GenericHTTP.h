#ifndef GenericHTTP_h
#define GenericHTTP_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class GenericHTTP {
public:
  GenericHTTP();
  bool connectToWiFi(const char* ssid, const char* password);
  bool sendHTTPRequest(const char* method, const char* host, const char* port, const char* uri, const char* headers, const char* body);

private:
  SoftwareSerial espSerial;
  bool sendHttpRequest(const char* method, const char* host, const char* port, const char* uri, const char* headers, const char* body);
  void sendCommand(String command, unsigned int timeout, const char* expected);
};

#endif
