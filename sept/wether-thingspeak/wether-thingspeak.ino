#include <WiFi.h>

#include <HTTPClient.h>

#include "DHT.h"

 

#define DHTPIN 5

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

 

const char* ssid = "your WiFi ssid";

const char* password = "Your WiFi password";

// Domain Name with full URL Path for HTTP POST Request

const char* serverName = "http://api.thingspeak.com/update";

// write API Key provided by thingspeak

String apiKey = "your write API key";

 

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  dht.begin();

 

  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.print("Connected to WiFi network with IP Address: ");

  Serial.println(WiFi.localIP());

}

void loop() {

  if(WiFi.status()== WL_CONNECTED){

      WiFiClient client;

      HTTPClient http;

      delay(10000); // wait for 10 seconds

     //float h = dht.readHumidity();

      float t = dht.readTemperature();

 

      if (isnan(t)) {

       Serial.println(F("Failed to read from DHT sensor!"));

       return;

      }

   

      // Your Domain name with URL path or IP address with path

      http.begin(client, serverName);

     

      // Specify content-type header

      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      // Data to send with HTTP POST

      String httpRequestData = "api_key=" + apiKey + "&field1=" + String(t);          

      // Send HTTP POST request

      int httpResponseCode = http.POST(httpRequestData);

     

      /*

      // If you need an HTTP request with a content type: application/json, use the following:

      http.addHeader("Content-Type", "application/json");

      // JSON data to send with HTTP POST

      String httpRequestData = "{\"api_key\":\"" + apiKey + "\",\"field1\":\"" + String(random(40)) + "\"}";          

      // Send HTTP POST request

      int httpResponseCode = http.POST(httpRequestData);*/

     

      Serial.print("HTTP Response code: ");

      Serial.println(httpResponseCode);

 

      http.end();

    }

    else {

      Serial.println("WiFi Disconnected");

    }

}