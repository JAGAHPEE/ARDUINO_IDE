#include <Firebase.h>
#include <FirebaseESP32.h>

#include <WiFi.h>


#define FIREBASE_HOST "esp-data-123-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "jYfS5eaMJ4vWQl2bCNpTyrMN05to1BTyAZFEXuu3"
#define WIFI_SSID "LAPTOP"
#define WIFI_PASSWORD "78799008333"

#define s1 27
#define led 2
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(s1,INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void sensorUpdate(){
  int ir1= digitalRead(s1);
  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t) || isnan(f)|| isnan(ir1) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }

  
  Serial.print(ir1);
  Serial.println(F("State  "));

  if (Firebase.setFloat(firebaseData, "/ESP-data-123/ir3", ir1))
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
}
void loop() {
  sensorUpdate();
  
  if (Firebase.getString(ledData, "/ESP-data-123/ir1")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "1") {
    digitalWrite(led, HIGH);
    }
  else if (ledData.stringData() == "0"){
    digitalWrite(led, LOW);
    }
  }
  delay(100);
}
