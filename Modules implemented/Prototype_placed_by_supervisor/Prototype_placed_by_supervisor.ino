// Prototype placed by supervisor

#include <DHT.h>  // Including library for dht
#define DHTPIN 13    // Connect Data pin of DHT to D2
#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);
////////////
// Distance prediction 
//    * BLUETOOTH PROTOCOL
//    		* Process - Communication acknlowedgement.
#include <FirebaseESP32.h>
#include <esp_now.h> 
#include <WiFi.h>
#define FIREBASE_HOST "  HOST ID " //Without http:// or https:// schemes
#define FIREBASE_AUTH "  FIREBASE AUTHENTICATION CODE"
#define WIFI_SSID " WIFI NAME"
#define WIFI_PASSWORD " WIFI PASSOWRD"
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;
FirebaseJson json;

//ADXL335 section 
int xpin = 12;                
 int ypin = 14;                
 int zpin = 27; 
 int xvalue;
 int yvalue;
 int zvalue;
 //ADXL335 section 

//Bluetooth Section
uint8_t broadcastAddress[] = {MAC ID OF Wi-Fi-cum-BT module}; 
int send_rnd_val_1;
int send_rnd_val_2;
int receive_rnd_val_1;
int receive_rnd_val_2;
String success;
typedef struct struct_message {
    int rnd_1;
    int rnd_2;
} struct_message;
struct_message send_Data; 
struct_message receive_Data; 
//Bluetooth Section


void setup()
{
  Serial.begin(9600);

  dht.begin();
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);


  //Bluetooth Section

  //----------------------------------------Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  
        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  //----------------------------------------
  
  esp_now_register_recv_cb(OnDataRecv); 
  //Bluetooth section
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(s
    success = "Delivery Success :)";
  }
  else{
    success = "Delivery Fail :("; 
  }
  Serial.println(">>>>>");
//Firebase.setString(firebaseData, "/FirebaseIOT/Bt", "Far");
}
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receive_Data, incomingData, sizeof(receive_Data));
  Serial.println();
  Seral_1 = receive_Data.rnd_1;
  receive_rnd_val_2 = receive_Data.rnd_2;
  Serial.println("Receive Data: ");
  Serial.println(receive_rnd_val_1);
  Serial.println(receive_rnd_val_2);
  Serial.println("<<<<<");
}

//Bluetooth Section

void sensorUpdate(){

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

xvalue = analogRead(xpin);                              //reads values from x-pin & measures acceleration in X direction 
    int x = map(xvalue, 267, 400, -100, 100);               //maps the extreme ends analog values from -100 to 100 for our understanding
    float xg = (float)x/(-100.00);  
    Serial.println(xg);
Firebase.setFloat(firebaseData, "/base/x-axis", xg);
    yvalue = analogRead(ypin);
    int y = map(yvalue, 272, 406, -100, 100);
    float yg = (float)y/(-100.00);
        Serial.println(yg);
Firebase.setFloat(firebaseData, "/base/y-axis", yg);
    zvalue = analogRead(zpin);
    int z = map(zvalue, 277, 410, -100, 100);
    float zg = (float)z/(100.00);
        Serial.println(zg);
Firebase.setFloat(firebaseData, "/base/z-axis", zg);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Firebase.setFloat(firebaseData, "/FirebaseIOT/humidity", h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C  ,"));
  Serial.print(f);
  Serial.println(F("°F  "));

  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/temperature", t))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/temperatureinfaranheit", f))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
if (Firebase.setFloat(firebaseData, "/base/x-axis", xg))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
  if (Firebase.setFloat(firebaseData, "/base/x-axis", yg))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
  if (Firebase.setFloat(firebaseData, "/base/x-axis", zg))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
  // Prototype placed with patient

//Bluetooth Section
  send_rnd_val_1 = random(0, 255);
  send_rnd_val_2 = random(0, 255);
  send_Data.rnd_1 = send_rnd_val_1;
  send_Data.rnd_2 = send_rnd_val_2;
  //----------------------------------------
  
  Serial.println();
  Serial.print(">>>>> ");
  Serial.println("Send data");

  //----------------------------------------Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &send_Data, sizeof(send_Data));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  //----------------------------------------
//Bluetooth Section
  
}
void loop() {
  sensorUpdate();
  delay(200);
}
