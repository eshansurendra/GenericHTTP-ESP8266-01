# GenericHTTP Arduino Library

The **GenericHTTP** library simplifies sending HTTP requests using the ESP8266-01 module (e.g., ESP-01) with an Arduino board. It provides a convenient way to establish Wi-Fi connection, send various types of HTTP requests, and handle responses.

## Features

- Connect to Wi-Fi network using provided SSID and password.
- Send HTTP GET and POST requests to specified endpoints.
- Handle HTTP responses, including parsing and extracting data.

## Installation

1. Download the [latest release](https://github.com/eshansajes/GenericHTTP-ESP8266-01/) of the library.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...** and select the downloaded ZIP file.
3. Restart the Arduino IDE.

## Usage

1. Import the `GenericHTTP.h` library at the beginning of your Arduino sketch:

```cpp
#include <GenericHTTP.h>
```
2. Create an instance of the GenericHTTP class:
   
```cpp
GenericHTTP http;
```

3. Connect to Wi-Fi using connectToWiFi function:
   
```cpp
http.connectToWiFi("your_wifi_ssid", "your_wifi_password");
```

4. Send an HTTP GET request:
   
```cpp
bool success = http.sendHTTPRequest("GET", "example.com", "80", "/path/to/endpoint", nullptr, nullptr);
if (success) {
  // Handle successful response
} else {
  // Handle failed request
}
```
## Examples

The library comes with several example sketches to help you get started:

- [Basic Usage](examples/BasicUsage/): Demonstrates the basic usage of the library to connect to Wi-Fi and send an HTTP GET request.
- [Advanced Usage](examples/AdvancedUsage/): Shows more advanced scenarios, such as handling responses and using custom headers.

Feel free to explore these examples to understand how to integrate the GenericHTTP library into your own projects.





