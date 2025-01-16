#include <ModbusSerial.h>

// Used Pins
const int servoPin = 32;
const int TxenPin = 2;  // -1 disables the feature, change that if you are using an RS485 driver, this pin would be connected to the DE and /RE pins of the driver.

const byte SlaveId = 1;
const int ServoHreg = 0;

const int SensorPin = 34;
const int SensorIreg = 0;

const int SwitchPin = 25;
const int SwitchIsts = 0;


const int LedPin = 13;
const int Lamp1Coil = 0;


#define MySerial Serial2  // define serial port used, Serial most of the time, or Serial1, Serial2 ... if available
const unsigned long Baudrate = 9600;

// ModbusSerial object
ModbusSerial mb(MySerial, SlaveId, TxenPin);
// Servo object

long ts;

void setup() {

  Serial.begin(9600);
  
  MySerial.begin(Baudrate);  // works on all boards but the configuration is 8N1 which is incompatible with the MODBUS standard
  mb.config(Baudrate);

  mb.addHreg(ServoHreg, 0);
  mb.addHreg(ServoHreg + 1, 0);

  mb.addIreg(SensorIreg);
  mb.addIreg(SensorIreg + 1);

}



int inputRegister = 0;
int inputRegister2 = 0;

int holdingRegister = 0;
int holdingRegister2 = 0;
long number = 0;  // Armazena o número resultante




void loop() {


  leInputRegister();


  // Setting raw value (0-1024)
  mb.Ireg(SensorIreg, inputRegister);
  mb.Ireg(SensorIreg + 1, inputRegister2);

  mb.task();

  //digitalWrite(2,0);

  holdingRegister = mb.Hreg(ServoHreg);
  holdingRegister2 = mb.Hreg(ServoHreg + 1);

  leHoldingRegister();


}
