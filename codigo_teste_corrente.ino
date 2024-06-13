//definir constantes
#define VOLTAGE_REFERENCE1 3.3  // Tensão de referência do ADC
#define ADC_RESOLUTION1 4095 // Resolução do ADC
#define ACS712_ZERO 1.58  // Valor de zero do ACS712 (em volts)
const float Vref = 3.3;
const int resistance = 0.165;

//pinos
#define SENSOR_PIN_CORRENTE 34
#define ADC_PIN 32

void setup() {
  Serial.begin(115200);
  //analogReadResolution(12); // Set ADC resolution to 12 bits (0-4095)

  Serial.println("CLEARDATA");
  Serial.println("LABEL,Tempo,Tensão sensor,Sensor de Corrente");
  Serial.println("RESETTIMER");
}

void sensorCorrente() {

  int rawValue = analogRead(SENSOR_PIN_CORRENTE);  // Leia o valor bruto do ADC
  float voltage = (rawValue / (float)ADC_RESOLUTION1) * VOLTAGE_REFERENCE1;  // Converta para tensão
  
  float current = (voltage - ACS712_ZERO) / 0.066;  // Converta para corrente (0.066 mV/A é a sensibilidade para ACS712 50A)

    Serial.print(voltage);
    Serial.print(",");
    Serial.println(current);

}

void loop() {
  Serial.print("DATA, TIME,");
  //shunt();
  sensorCorrente();
  delay(1000);

}
