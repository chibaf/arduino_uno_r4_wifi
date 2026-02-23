import socket

# 設定：Arduino側で指定した送信先ポートと同じにする
UDP_IP = "0.0.0.0"  # すべてのネットワークインターフェースで待ち受け
UDP_PORT = 5005    # Arduinoの送信先ポート番号

# ソケットの作成 (UDP)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"UDPサーバー起動: ポート {UDP_PORT} で受信待機中...")

try:
    while True:
        # データを受信（最大2048バイト）
        data, addr = sock.recvfrom(2048)
        
        # 受信データを文字列に変換して表示
        message = data.decode('utf-8')
        print(f"受信元: {addr} | データ: {message}")
        
except KeyboardInterrupt:
    print("\nサーバーを停止します。")
finally:
    sock.close()
