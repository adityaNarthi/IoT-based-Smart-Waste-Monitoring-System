#include <AWS_IOT.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <HX711.h>

AWS_IOT hornbill;   // AWS_IOT instance

const char* ssid = "G 5G";     // Replace with your WiFi Name
const char* password = "12345678";   // Replace with your WiFi Password
char HOST_ADDRESS[] = "a1s9aag49sr2zc-ats.iot.ap-southeast-2.amazonaws.com"; // Replace with your AWS Custom endpoint Address

char CLIENT_ID[] = "DHT11";
char TOPIC_NAME[] = "ESP32/DHT11";
int status = WL_IDLE_STATUS;
char payload[512];

const int LOADCELL_DOUT_PIN = 2;   // Data pin connected to D2
const int LOADCELL_SCK_PIN = 4;    // Clock pin connected to D4
HX711 scale;

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize AWS IoT
  if (hornbill.connect(HOST_ADDRESS, CLIENT_ID) == 0) {
    Serial.println("Connected to AWS");
  } else {
    Serial.println("AWS connection failed, Check the HOST Address");
    while (1);
  }
  
  // Initialize the load cell
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(107.883);  
  scale.tare();              

  // Fetch current time from HTTP Time API
  fetchTimeFromHTTPTimeAPI();
}

void loop() {
  // Read weight from the load cell
  float weight = scale.get_units(10);
  
  // Get current timestamp
  time_t now = time(nullptr);
  struct tm *timeinfo;
  timeinfo = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
  
  // Create the payload with TimeStamp
  snprintf(payload, sizeof(payload), "{\"TimeStamp\": \"%s\", \"DeviceID\": \"DHT0125896\", \"Weight\": %f}", timestamp, weight);

  // Publish the message to AWS
  if (hornbill.publish(TOPIC_NAME, payload) == 0) {
    Serial.print("Publish Message: ");
    Serial.println(payload);
  } else {
    Serial.println("Publish failed");
  }
  
  // Publish the weight every 5 seconds
  delay(5000);
}

void fetchTimeFromHTTPTimeAPI() {
  HTTPClient http;

 
  http.begin("http://worldtimeapi.org/api/timezone/Asia/Kolkata"); // Indian Standard Time (IST)
  int httpResponseCode = http.GET();

  if (httpResponseCode == HTTP_CODE_OK) {
    String payload = http.getString();

    // Parse JSON response
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);
    
    // Extract time
    const char* dateTime = doc["datetime"]; // ISO 8601 format
    struct tm tm;
    strptime(dateTime, "%Y-%m-%dT%H:%M:%S", &tm);
    time_t timestamp = mktime(&tm);

    // Set system time
    struct timeval tv = {timestamp, 0};
    settimeofday(&tv, nullptr);
    
    Serial.println("Time synchronized successfully.");
  } else {
    Serial.print("Failed to fetch time from HTTP Time API. HTTP error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}
