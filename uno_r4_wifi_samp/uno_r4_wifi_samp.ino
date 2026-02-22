#include <WiFiS3.h>

// ----------- WiFi 設定 -----------------
const char* ssid     = "AirPort";
const char* password = "e1008e1008";

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
	
  while (status != WL_CONNECTED) {
    Serial.println("WiFi ...");
    status = WiFi.begin(ssid, password);
    delay(10000);
  }
	
  Serial.println("WiFi OK");
  Serial.println("");

  printWifiData();

}

void loop() {
  delay(10000);
  printWifiData();
}

void printWifiData() {
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printMacAddress(mac);
}

void printMacAddress(byte mac[]) {
  for (int i = 0; i < 6; i++) {
    if (i > 0) {
      Serial.print(":");
    }
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
  }
  Serial.println();
}