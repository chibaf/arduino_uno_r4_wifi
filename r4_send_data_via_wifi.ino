#include <WiFi.h>
#include <WiFiUdp.h>

char ssid[] = "AirPort";
char pass[] = "e1008e1008";

WiFiUDP udp;
WiFiServer server(139);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Serial.println("WiFi connected.");
  
  udp.begin(139);
  Serial.println("UDP initialized.");
  server.begin();
  Serial.println("Server started.");
}

WiFiClient client = server.available();
int a = 30;
void loop() 
{    
    udp.beginPacket("192.168.0.9", 139);
    udp.print(a);
    udp.endPacket();
}