#include <Arduino.h>
#include <ESP8266WiFi.h>

// WiFi Credentials
const char* ssid = "SmartHome";
const char* password = "12345678";

// Web Server
WiFiServer server(80);

// HTTP Request Header
String header;

// Output States
String output0State = "off";
String output1State = "off";
String output2State = "off";
String output3State = "off";

// GPIO Pin Configuration
const int output0 = D2;  // GPIO 4
const int output1 = D5;  // GPIO 14
const int output2 = D6;  // GPIO 12
const int output3 = D1;  // GPIO 5

void setup() {

  Serial.begin(115200);

  // Initialize GPIO Pins
  pinMode(output0, OUTPUT);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);

  // Default Output State
  digitalWrite(output0, LOW);
  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);

  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start Server
  server.begin();
}

void loop() {

  WiFiClient client = server.available();

  if (client) {

    Serial.println("New Client.");

    String currentLine = "";

    while (client.connected()) {

      if (client.available()) {

        char c = client.read();

        Serial.write(c);
        header += c;

        if (c == '\n') {

          if (currentLine.length() == 0) {

            // HTTP Response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // GPIO 4 CONTROL
            if (header.indexOf("GET /4/on") >= 0) {

              Serial.println("GPIO 4 ON");
              output0State = "on";
              digitalWrite(output0, HIGH);

            }
            else if (header.indexOf("GET /4/off") >= 0) {

              Serial.println("GPIO 4 OFF");
              output0State = "off";
              digitalWrite(output0, LOW);

            }

            // GPIO 14 CONTROL
            else if (header.indexOf("GET /14/on") >= 0) {

              Serial.println("GPIO 14 ON");
              output1State = "on";
              digitalWrite(output1, HIGH);

            }
            else if (header.indexOf("GET /14/off") >= 0) {

              Serial.println("GPIO 14 OFF");
              output1State = "off";
              digitalWrite(output1, LOW);

            }

            // GPIO 12 CONTROL
            else if (header.indexOf("GET /12/on") >= 0) {

              Serial.println("GPIO 12 ON");
              output2State = "on";
              digitalWrite(output2, HIGH);

            }
            else if (header.indexOf("GET /12/off") >= 0) {

              Serial.println("GPIO 12 OFF");
              output2State = "off";
              digitalWrite(output2, LOW);

            }

            // GPIO 5 CONTROL
            else if (header.indexOf("GET /5/on") >= 0) {

              Serial.println("GPIO 5 ON");
              output3State = "on";
              digitalWrite(output3, HIGH);

            }
            else if (header.indexOf("GET /5/off") >= 0) {

              Serial.println("GPIO 5 OFF");
              output3State = "off";
              digitalWrite(output3, LOW);

            }

            // ==============================
            // TECHNICAL BD WEB DASHBOARD
            // ==============================

            client.println("<!DOCTYPE html>");
            client.println("<html lang='en'>");

            client.println("<head>");

            client.println("<meta charset='UTF-8'>");

            client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");

            client.println("<title>Technical BD | Home Automation</title>");

            // CSS STYLING
            client.println("<style>");

            client.println("*{box-sizing:border-box;margin:0;padding:0;}");

            client.println("body{");
            client.println("font-family:Arial,Helvetica,sans-serif;");
            client.println("background:linear-gradient(135deg,#eaf2ff,#dce5f2,#f4e9ec);");
            client.println("color:#172033;");
            client.println("min-height:100vh;");
            client.println("}");

            // HEADER
            client.println(".header{");
            client.println("background:linear-gradient(120deg,#101d3a,#163d78,#9e263c);");
            client.println("color:white;");
            client.println("text-align:center;");
            client.println("padding:30px 15px;");
            client.println("border-bottom:4px solid #e63950;");
            client.println("}");

            client.println(".brand{");
            client.println("font-size:30px;");
            client.println("font-weight:900;");
            client.println("letter-spacing:2px;");
            client.println("}");

            client.println(".brand span{color:#ff596b;}");

            client.println(".subtitle{");
            client.println("font-size:13px;");
            client.println("margin-top:9px;");
            client.println("color:#d8e6ff;");
            client.println("letter-spacing:1px;");
            client.println("}");

            // MAIN CONTAINER
            client.println(".container{");
            client.println("max-width:850px;");
            client.println("margin:30px auto;");
            client.println("padding:15px;");
            client.println("}");

            client.println(".section-title{");
            client.println("text-align:center;");
            client.println("font-size:23px;");
            client.println("font-weight:bold;");
            client.println("color:#183b70;");
            client.println("margin-bottom:8px;");
            client.println("}");

            client.println(".section-info{");
            client.println("text-align:center;");
            client.println("font-size:13px;");
            client.println("color:#68758a;");
            client.println("margin-bottom:25px;");
            client.println("}");

            // CARD GRID
            client.println(".grid{");
            client.println("display:grid;");
            client.println("grid-template-columns:repeat(2,1fr);");
            client.println("gap:18px;");
            client.println("}");

            // CONTROL CARD
            client.println(".card{");
            client.println("background:rgba(255,255,255,0.92);");
            client.println("border:1px solid #d6e0ef;");
            client.println("border-radius:16px;");
            client.println("padding:22px 15px;");
            client.println("text-align:center;");
            client.println("box-shadow:0 6px 18px rgba(20,45,85,0.09);");
            client.println("transition:0.2s;");
            client.println("}");

            client.println(".card h3{");
            client.println("font-size:19px;");
            client.println("color:#183b70;");
            client.println("margin-bottom:12px;");
            client.println("}");

            client.println(".gpio{");
            client.println("font-size:12px;");
            client.println("color:#7b8798;");
            client.println("margin-bottom:14px;");
            client.println("}");

            // STATUS
            client.println(".status{");
            client.println("display:inline-block;");
            client.println("padding:7px 17px;");
            client.println("border-radius:20px;");
            client.println("font-size:12px;");
            client.println("font-weight:bold;");
            client.println("margin-bottom:18px;");
            client.println("}");

            client.println(".on-status{");
            client.println("background:#d9f8e6;");
            client.println("color:#08783c;");
            client.println("}");

            client.println(".off-status{");
            client.println("background:#ffe1e4;");
            client.println("color:#c6283d;");
            client.println("}");

            // BUTTONS
            client.println(".btn{");
            client.println("display:inline-block;");
            client.println("padding:12px 27px;");
            client.println("border-radius:9px;");
            client.println("text-decoration:none;");
            client.println("color:white;");
            client.println("font-size:14px;");
            client.println("font-weight:bold;");
            client.println("margin:3px;");
            client.println("min-width:90px;");
            client.println("transition:0.2s;");
            client.println("}");

            client.println(".on-btn{");
            client.println("background:linear-gradient(135deg,#1769d2,#2589f5);");
            client.println("}");

            client.println(".off-btn{");
            client.println("background:linear-gradient(135deg,#c5223d,#f04c60);");
            client.println("}");

            client.println(".btn:active{transform:scale(0.95);}");

            // FOOTER
            client.println(".footer{");
            client.println("text-align:center;");
            client.println("padding:22px 10px;");
            client.println("margin-top:30px;");
            client.println("background:#17243c;");
            client.println("color:#dce7f7;");
            client.println("font-size:12px;");
            client.println("}");

            client.println(".footer strong{");
            client.println("color:#ff596b;");
            client.println("}");

            // MOBILE RESPONSIVE
            client.println("@media(max-width:520px){");
            client.println(".grid{grid-template-columns:1fr;}");
            client.println(".brand{font-size:25px;}");
            client.println(".container{margin:20px auto;}");
            client.println("}");

            client.println("</style>");
            client.println("</head>");

            // BODY
            client.println("<body>");

            // HEADER CONTENT
            client.println("<div class='header'>");
            client.println("<div class='brand'>TECHNICAL <span>BD</span></div>");
            client.println("<div class='subtitle'>SMART HOME AUTOMATION SYSTEM</div>");
            client.println("</div>");

            // MAIN SECTION
            client.println("<div class='container'>");

            client.println("<div class='section-title'>CONTROL PANEL</div>");
            client.println("<div class='section-info'>Manage your connected devices using WiFi</div>");

            client.println("<div class='grid'>");

            // CHANNEL 1
            client.println("<div class='card'>");
            client.println("<h3>CHANNEL 01</h3>");
            client.println("<div class='gpio'>GPIO 4 | D2</div>");

            if (output0State == "on") {
              client.println("<div class='status on-status'>STATUS: ON</div>");
              client.println("<br><a class='btn off-btn' href='/4/off'>TURN OFF</a>");
            }
            else {
              client.println("<div class='status off-status'>STATUS: OFF</div>");
              client.println("<br><a class='btn on-btn' href='/4/on'>TURN ON</a>");
            }

            client.println("</div>");

            // CHANNEL 2
            client.println("<div class='card'>");
            client.println("<h3>CHANNEL 02</h3>");
            client.println("<div class='gpio'>GPIO 14 | D5</div>");

            if (output1State == "on") {
              client.println("<div class='status on-status'>STATUS: ON</div>");
              client.println("<br><a class='btn off-btn' href='/14/off'>TURN OFF</a>");
            }
            else {
              client.println("<div class='status off-status'>STATUS: OFF</div>");
              client.println("<br><a class='btn on-btn' href='/14/on'>TURN ON</a>");
            }

            client.println("</div>");

            // CHANNEL 3
            client.println("<div class='card'>");
            client.println("<h3>CHANNEL 03</h3>");
            client.println("<div class='gpio'>GPIO 12 | D6</div>");

            if (output2State == "on") {
              client.println("<div class='status on-status'>STATUS: ON</div>");
              client.println("<br><a class='btn off-btn' href='/12/off'>TURN OFF</a>");
            }
            else {
              client.println("<div class='status off-status'>STATUS: OFF</div>");
              client.println("<br><a class='btn on-btn' href='/12/on'>TURN ON</a>");
            }

            client.println("</div>");

            // CHANNEL 4
            client.println("<div class='card'>");
            client.println("<h3>CHANNEL 04</h3>");
            client.println("<div class='gpio'>GPIO 5 | D1</div>");

            if (output3State == "on") {
              client.println("<div class='status on-status'>STATUS: ON</div>");
              client.println("<br><a class='btn off-btn' href='/5/off'>TURN OFF</a>");
            }
            else {
              client.println("<div class='status off-status'>STATUS: OFF</div>");
              client.println("<br><a class='btn on-btn' href='/5/on'>TURN ON</a>");
            }

            client.println("</div>");

            client.println("</div>");
            client.println("</div>");

            // FOOTER
            client.println("<div class='footer'>");
            client.println("POWERED BY <strong>TECHNICAL BD</strong>");
            client.println("<br><br>");
            client.println("ESP8266 LOCAL WEB SERVER");
            client.println("</div>");

            client.println("</body>");
            client.println("</html>");

            client.println();

            break;

          }
          else {
            currentLine = "";
          }

        }
        else if (c != '\r') {
          currentLine += c;
        }

      }

    }

    // Clear HTTP Header
    header = "";

    // Close Client
    client.stop();

    Serial.println("Client disconnected.");
    Serial.println("");

  }

}
