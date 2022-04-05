// Prototype with patient


#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS     1000
////////////
// Distance prediction 
//    * BLUETOOTH PROTOCOL
//    		* Process - Communication acknlowedgement.

// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;
//////////////////////////////////////////////spo2
uint32_t tsLastReport = 0;


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

//Bluetooth Section
int val;
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

//////////////////////////////////////////////spo2

void onBeatDetected()
{
    Serial.println("Beat!");
}
//////////////////////////////////////////////spo2

void Hrt(){
   pox.update();
   
  float spo2,Hr;
    // Asynchronously dump heart rate and oxidation levels to the serial
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
       
        Serial.print("Heart rate:");
        Hr=pox.getHeartRate();
        Serial.print(Hr);
        Firebase.setFloat(firebaseData, "/PatientHealth/HeartRate",Hr );
        Serial.print("bpm / SpO2:");
        spo2=pox.getSpO2();
        Serial.print(spo2);
        Firebase.set(firebaseData, "/PatientHealth/SpO2", spo2);
        Serial.println("%");

        tsLastReport = millis();
    }
      //////////////////////////////////////////////spo2
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status ==0){
    success = "Delivery Success :)";
    val=1;
  }
  else{
    success = "Delivery Fail :("; 
    val=0;
  }
  Serial.println(">>>>>");

}
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receive_Data, incomingData, sizeof(receive_Data));
  Serial.println();
 
  Serial.println(len);
  receive_rnd_val_1 = receive_Data.rnd_1;
  
  Serial.println(receive_rnd_val_2);
  Serial.println("<<<<<");
}
//Bluetooth Section


void setup()
{
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
 

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Bluetooth Section
//WiFi.mode(WIFI_STA); //--> Set device as a Wi-Fi Station

  //----------------------------------------Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  
        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  //----------------------------------------
  
  esp_now_register_recv_cb(OnDataRecv); 
  //Bluetooth section

  //////////////////////////////////////////////spo2
Serial.print("Initializing pulse oximeter..");

    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     // The default current for the IR LED is 50mA and it could be changed
    //   by uncommenting the following line. Check MAX30100_Registers.h for all the
    //   available options.
    // pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
  //////////////////////////////////////////////spo2


}

//Bluetooth Section

void sensorUpdate(){
  if(val==0){
      Firebase.setString(firebaseData, "/Fir/Btprox", "Far");
      Serial.println("Far");
  }
  else{
      Firebase.setString(firebaseData, "/Fir/Btprox", "Near");
      Serial.println("Near");
  }
 
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
  

 
}
void loop() {
  Hrt();  //////////////////////////////////////////////spo2
  sensorUpdate();


 
    delay(500);
}
