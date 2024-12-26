[![Arduino Lint](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/arduino_lint.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/arduino_lint.yml) [![pre-commit](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/pre-commit.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/pre-commit.yml) [![Build Test Apps](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/build_test.yml/badge.svg)](https://github.com/esp-arduino-libs/ESP32_Knob/actions/workflows/build_test.yml)

# ESP32_Knob

ESP32_Knob is an Arduino library designed for driving encoders (such as EC11) using ESP SoCs. This library has implemented the quadrature decoding function similar to the ESP PCNT peripheral through software. It is useful for chips that do not have this peripheral, such as ESP32-C2 and ESP32-C3.

ESP32_Knob encapsulates the component from the [Espressif Components Registry](https://components.espressif.com/). It is developed based on [arduino-esp32](https://github.com/espressif/arduino-esp32) and can be easily downloaded and integrated into the Arduino IDE.

## Features

* Support for all ESP SoCs.
* Support multiple events, including `left`, `right`, `high limit`, `low limit`, and `back to zero`.

## Supported Drivers

|                             **Driver**                             | **Version** |
| ------------------------------------------------------------------ | ----------- |
| [knob](https://components.espressif.com/components/espressif/knob) | 0.1.3       |

## Dependencies Version

|                          **Name**                           | **Version** |
| ----------------------------------------------------------- | ----------- |
| ESP32_Knob                                                  | v0.x.x      |
| [arduino-esp32](https://github.com/espressif/arduino-esp32) | >= v2.0.4   |

## How to Use

For information on how to use the library in the Arduino IDE, please refer to the documentation for [Arduino IDE v1.x.x](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries) or [Arduino IDE v2.x.x](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library).

### Examples

* [Test Functions](examples/TestFunctions): Demonstrates how to use ESP32-Knob and test all functions.

### Detailed Usage

```cpp
#include <ESP_Knob.h>

#define GPIO_KNOB_A 1
#define GPIO_KNOB_B 2

ESP_Knob *knob = new ESP_Knob(GPIO_KNOB_A, GPIO_KNOB_B);

static void knob_left_cb(void *arg, void *data)
{
    Serial.printf("KNOB_LEFT Count is %d\n", knob->getCountValue());
}

knob->begin();
knob->registerEvent(KNOB_LEFT, knob_left_cb, NULL);

// Release the ESP_Knob object
delete knob;
```

**Note**: This component is only suitable for decoding low-speed rotary encoders such as EC11, and does not guarantee the complete correctness of the pulse count. For high-speed and accurate calculations, please use hardware [PCNT](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/pcnt.html?highlight=pcnt)
