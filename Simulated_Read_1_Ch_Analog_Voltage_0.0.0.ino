/*
  ReadAnalogVoltage

  Reads an analog input pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

String DatatoSend; //Data to send to serial port

//****_Inisasi settingan untuk jeda antar looping_****//
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time loop update
// constants won't change:
const long intervaltime = 20;           // intervaltime at which to looping (milliseconds)
/************************************************************************************/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  // sesuai dengan baudrate telemetry
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() 
{

  // check to see if it's time to run program; that is, if the difference
  // between the current time and last time run program is bigger than
  // the intervaltime at which you want to run program.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervaltime) 
  {
        
    // save the last time you start doing something in program
    float time_stamp = currentMillis/1000.00;
    previousMillis = currentMillis;

    // read the input on analog pin 0 for strain gage 1:
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float sensorDataRaw = sensorValue * (5.0 / 1023.0);
    //double sensorData = sin(sensorDataRaw);

    DatatoSend = String(time_stamp, 2) + "," + String(sensorDataRaw, 2);
    //DatatoSend = String(time_stamp, 2) + "," + String(sensorData, 2);
       
    Serial.println(DatatoSend);
    
  } // end of intervaltime
} //*************************************** end of the loop **************************************
