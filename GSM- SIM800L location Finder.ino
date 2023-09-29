#include <SoftwareSerial.h>

SoftwareSerial sim800l(10, 11); // RX, TX pins for communication with SIM800L

void setup() {
  Serial.begin(9600);   // Serial monitor
  sim800l.begin(9600);  // SIM800L module
  delay(1000);
}

void loop() {
  // Send the AT+CNETSCAN=1 command
  sim800l.println("AT+CNETSCAN=1");
  delay(1000);

  // Send the AT+CNETSCAN command
  sim800l.println("AT+CNETSCAN");
  delay(10000); // Wait for response, adjust as needed

  // Read and print response from SIM800L
  while (sim800l.available()) {
    char c = sim800l.read();
    Serial.write(c);
  }

  delay(5000); // Wait for 5 seconds before repeating
}
