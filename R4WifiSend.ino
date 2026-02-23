#include <WiFiS3.h>
#include <WiFiUdp.h>

const char ssid[] = "AirPort";     // WiFiのSSID
const char pass[] = "e1008e1008"; // WiFiのパスワード
const char* hostIp = "192.168.0.6"; // 送信先PCのIPアドレス
const int hostPort = 5005;           // 送信先ポート番号

WiFiUDP udp;
int count = 0;

void setup() {
  Serial.begin(9600);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected!");
  udp.begin(2390); // ローカルポート（任意）
}

void loop() {
  String message = "Count: " + String(count++);
  
  udp.beginPacket(hostIp, hostPort);
  udp.print(message);
  udp.endPacket();

  Serial.println("Sent: " + message);
  delay(1000); // 1秒おきに送信
}
