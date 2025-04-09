// Arduino led pin
#define LED_PIN 13

// Only one channel was tested at a time
#define PWM_CH1 9

// I2C addresses for current sensors
#define CHANNEL4 0x40
#define CHANNEL3 0x41
#define CHANNEL2 0x44
#define CHANNEL1 0x45

// Channel count
#define CHANNELS_LENGTH 4

#include <INA219.h>
#include <TimerOne_V2.h>

// Define all current sensors
INA219 channels[CHANNELS_LENGTH] = {
  INA219(CHANNEL1),
  INA219(CHANNEL2),
  INA219(CHANNEL3),
  INA219(CHANNEL4)
};

void setup() {

    pinMode(LED_PIN, OUTPUT);

    // Set PWM frequency to 2.5 kHz
    Timer1.frequency(2.5);
    Serial.begin(9600);
    // Start I2C
    Wire.begin();

    // Check if all chips are presents
    for(int i = 0; i < CHANNELS_LENGTH; i++) {

        if(!channels[i].begin()) {
            Serial.print("Could not connect to INA219, channel ");
            Serial.print(i);
            Serial.println("!");
            while(1){delay(10);}
        }

        // Set current shunt values and sensor parameters
        channels[i].setMaxCurrentShunt(1.0, 0.1);
        channels[i].setShuntResolution(12);
        channels[i].setShuntSamples(7);
    }

}

void loop() {
  
    // Blink LED for performance
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
        
    // Set PWM duty cycle to ~ 18%
    Timer1.pwm(PWM_CH1, 185);

    // Print all sensor values to serial
    Serial.println("\n\t#\tBUS\t\tSHUNT\t\tCURRENT\t\tPOWER");
    for (int i = 0; i < CHANNELS_LENGTH; i++)
    {
        Serial.print("\t");
        Serial.print(i);
        Serial.print("\t");
        Serial.print(channels[i].getBusVoltage(), 2);
        Serial.print("\t\t");
        Serial.print(channels[i].getShuntVoltage_mV(), 2);
        Serial.print("\t\t");
        Serial.print(channels[i].getCurrent_mA(), 2);
        Serial.print("\t\t");
        Serial.print(channels[i].getPower_mW(), 2);
        Serial.println();
        delay(200);
    }
    delay(3000);

}