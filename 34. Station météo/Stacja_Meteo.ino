#include <idDHT11.h>
#include <Wire.h>
#include <VirtualWire.h>
#include <BMP180.h>

int idDHT11pin = 3; 
int idDHT11intNumber = 1; 

void dht11_wrapper(); // must be declared before the lib initialization

idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);

BMP180 barometer;
// float seaLevelPressure = 101000;

String calosc, wilg, cisn, temp, wilg1, cisn1, temp1;
char Msg[27];


void setup()
{
  vw_setup(2000);
  
  wilg = String("W: ");
  cisn = String ("C: ");
  temp = String ("T: " );
  Serial.begin(9600);
  delay(5000);
  Serial.println("Stacja Meteo by ElektroMaras"); 
  
  Wire.begin();
  barometer = BMP180();
  if(barometer.EnsureConnected())
  {
    Serial.println("Connected to BMP180."); // Output we are connected to the computer.
    barometer.SoftReset();
    barometer.Initialize();
  }
  else
  { 
    Serial.println("Could not connect to BMP180.");

  }
  Serial.print("DHT 11 LIB version: ");
  Serial.println(IDDHT11LIB_VERSION);
  Serial.println("---------------");
  }

// This wrapper is in charge of calling 
// mus be defined like this for the lib work
void dht11_wrapper() 
{  DHT11.isrCallback();  }

void loop()
{
  Serial.print("\nRetrieving information from sensor: ");
    //delay(100);
  DHT11.acquire();
  while (DHT11.acquiring())
    ;
  int result = DHT11.getStatus();
  switch (result)
  {
  case IDDHTLIB_OK: 
    Serial.println("OK"); 
    break; }
  /* case IDDHTLIB_ERROR_CHECKSUM: 
    Serial.println("Error\n\r\tChecksum error"); 
    break;
  case IDDHTLIB_ERROR_ISR_TIMEOUT: 
    Serial.println("Error\n\r\tISR Time out error"); 
    break;
  case IDDHTLIB_ERROR_RESPONSE_TIMEOUT: 
    Serial.println("Error\n\r\tResponse time out error"); 
    break;
  case IDDHTLIB_ERROR_DATA_TIMEOUT: 
    Serial.println("Error\n\r\tData time out error"); 
    break;
  case IDDHTLIB_ERROR_ACQUIRING: 
    Serial.println("Error\n\r\tAcquiring"); 
    break;
  case IDDHTLIB_ERROR_DELTA: 
    Serial.println("Error\n\r\tDelta time to small"); 
    break;
  case IDDHTLIB_ERROR_NOTSTARTED: 
    Serial.println("Error\n\r\tNot started"); 
    break;
  default: 
    Serial.println("Unknown error"); 
    break;
  } */

int a = (DHT11.getHumidity());
String wilg1 = wilg + a + "%";
Serial.println (wilg1);

if(barometer.IsConnected)
  {
    // Retrive the current pressure in Pascals.
    long currentPressure = barometer.GetPressure();
    
    int b = (currentPressure/100);
    String cisn1 = cisn + b + " hPa"  ;
    Serial.println (cisn1);
 
    // Retrive the current temperature in degrees celcius.
    float currentTemperature = barometer.GetTemperature();

    int c = (currentTemperature);
    String temp1 = temp + c + " stC";
    Serial.println (temp1);
  
   String calosc = wilg1 + temp1 + cisn1 ;
   Serial.println(calosc);  
   
    calosc.toCharArray(Msg,(calosc.length()+1));
    for (int i = 0; i <= calosc.length(); i++) {
    Serial.print(Msg[i]);
   }
   
    vw_send((uint8_t *)Msg, strlen(Msg));
    vw_wait_tx(); 
    
    Serial.println("poszlo");         }
    Serial.println(); // Start a new line.
    delay(10000); 
}
