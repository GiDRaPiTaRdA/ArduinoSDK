static void ConnectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.println("Connecting to " + (String)ssid); //  "Подключаемся к "
}

static int ScanWiFINetworks(){
  int foundNets = WiFi.scanNetworks();
  if (foundNets == -1)
  {
    Serial.println("Couldn't get a wifi connection");
    while (true);

    delay(1000);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(foundNets);

  return foundNets;
}

static bool IsSSIDAvailbale(String ssid, int foundNets) {

  bool any = false;

  for (int thisNet = 0; thisNet < foundNets; thisNet++) {

    any |= WiFi.SSID(thisNet) == ssid;

    Serial.println(WiFi.SSID(thisNet));
  }

  return any;
}

static void PrintWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
