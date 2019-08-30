//Include libraries
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

//Setup software UART connections
SoftwareSerial UART4(3, 2);
SoftwareSerial UART6(5, 4);

//Define SD card chip select pin
uint8_t SD_CS = 10;
String filename;

///////////////////////////////////////// Setup
void setup()
{
  UART4.begin(9600);
  UART6.begin(9600);

  if (SD.begin(chipSelect))
  {
    Serial.print("Initialised SD Card");
  }
  else
  {
    Serial.println("SD Card Failed");
  }

  //Filename set by realtime clock current date and time
  filename = "a"//To change to real time input
}

///////////////////////////////////////// Loop
void loop()
{
  String data = "";

  //Attempt to create a file on the SD card
  File data_file = SD.open(filename, FILE_WRITE);

  //Check if SD is connected and file exists
  if(data_file)
  {
    //Print data to SD
    data_file.println(data);
    //Close file
    data_file.close();
    
    Serial.println(data);
  }

  //Transmit data
  //UART4.println("hello");
}
