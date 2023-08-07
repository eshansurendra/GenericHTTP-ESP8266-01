# GenericHTTP-ESP8266-01
# GenericHTTP Arduino Library

The **GenericHTTP** library simplifies sending HTTP requests using the ESP8266 module (e.g., ESP-01) with an Arduino board. It provides a convenient way to establish Wi-Fi connection, send various types of HTTP requests, and handle responses.

## Features

- Connect to Wi-Fi network using provided SSID and password.
- Send HTTP GET and POST requests to specified endpoints.
- Handle HTTP responses, including parsing and extracting data.

## Installation

1. Download the [latest release](https://github.com/eshansajes/GenericHTTP-ESP8266-01/releases) of the library.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...** and select the downloaded ZIP file.
3. Restart the Arduino IDE.

## Usage

1. Import the `GenericHTTP.h` library at the beginning of your Arduino sketch:

```cpp
#include <GenericHTTP.h>

2. Create an instance of the GenericHTTP class:
```cpp
GenericHTTP http;

3. Connect to Wi-Fi using connectToWiFi function:
```cpp
http.connectToWiFi("your_wifi_ssid", "your_wifi_password");

4. Send an HTTP GET request:
```cpp
bool success = http.sendHTTPRequest("GET", "example.com", "80", "/path/to/endpoint", nullptr, nullptr);
if (success) {
  // Handle successful response
} else {
  // Handle failed request
}





