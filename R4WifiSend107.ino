#include <WiFiS3.h>
#include <WiFiUdp.h>

const char ssid[] = "TP-Link_4D1C";     // WiFiのSSID
const char pass[] = "50426171"; // WiFiのパスワード
const char* hostIp = "192.168.150.107"; // 送信先PCのIPアドレス
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
