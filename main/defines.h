
/**************************************************************************************************/
/* Definitions                                                                                    */
/**************************************************************************************************/

#define MLX90614_I2CDEFAULTADDR 0x5A 
#define MLX90614_BROADCASTADDR  0       
#define MLX90614_CRC8POLY       7       
#define MLX90614_XDLY           25      

//  RAM addresses.
#define MLX90614_RAWIR1         0x04   
#define MLX90614_RAWIR2         0x05    
#define MLX90614_AMBIENT_TEMP   0x06 // RAM address for ambient temperature
#define MLX90614_OBJECT_TEMP    0x07  // RAM address for object temperature 
#define MLX90614_TOBJ2          0x08  

#define I2C_MASTER_NUM              I2C_NUM_1   // I2C port number for master
#define I2C_MASTER_FREQ_HZ          100000     // Frequency: 100 kHz
#define I2C_MASTER_SDA_IO           25         // Default GPIO number for I2C data (SDA)
#define I2C_MASTER_SCL_IO           26         // Default GPIO number for I2C clock (SCL)
#define I2C_BUFFER_SIZE             128        // I2C buffer size
#define GPIO_OUTPUT_IO              2          // GPIO pin to toggle
#define GPIO_OUTPUT_PIN_SEL         (1ULL << GPIO_OUTPUT_IO)
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0


// Actuators
#define PELTIER_GPIO 18            // GPIO to control Peltier
#define FAN_GPIO 19                // GPIO to control Fan
#define TEMP_SETPOINT 20.0         // Temperature setpoint in °C
#define PWM_FREQ 5000              // PWM frequency
#define PWM_RES LEDC_TIMER_8_BIT   // PWM resolution (0-255)