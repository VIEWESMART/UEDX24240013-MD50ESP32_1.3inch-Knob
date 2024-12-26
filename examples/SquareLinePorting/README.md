# LVGL Porting Example

The example demonstrates how to port LVGL(v8). And for RGB LCD, it can enable the avoid tearing function.

## How to Use
### Installing arduino-esp32
For installation of the esp32 in the Arduino IDE, refer to [How_To_Configure_Arduino-esp32](https://github.com/VIEWESMART/VIEWE-FAQ/blob/main/Arduino-FAQ/English/How_To_Configure_Arduino-esp32.md#install-esp32).

### Installing the Library
To use this example, please firstly install the following dependent libraries:

- lvgl (>= v8.3.9, < v9)
- ESP32_Display_Panel (> 0.2.1)
- ESP32_IO_Expander (>= 0.1.0 && < 0.2.0)
- ESP32_Knob (>= 0.1.3)
- ESP32_Button (>= 3.1.2)
- ui

Follow the steps below to configure:

1. For **ESP32_Display_Panel**:

    `Note`:Since the latest version is still being updated and has not been released, please temporarily use the test version in this repository: `Libraries`->[`ESP32_Display_Panel`](https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/tree/main/Libraries/ESP32_Display_Panel).

     - Follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#configuring-drivers) to configure drivers if needed.
    - If using a supported development board, follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#using-supported-development-boards) to configure it.
    - If using a custom board, follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#using-custom-development-boards) to configure it.
  
2. For **ESP32_IO_Expander**:
   - Just install it directly.

3. For **ESP32_Knob**:
   - Just install it directly.
     
4. For **ESP32_Button**:
   - Just install it directly.
     
5. Copy the [ui](https://github.com/VIEWESMART/UEDX48480021-MD80ESP32_2.1inch-Knob/tree/main/Libraries/ui) folder from `libraries` to `lvgl` and other libraries under the same level directory.Here I have put ui into the [`Libraries`](https://github.com/VIEWESMART/UEDX48480021-MD80ESP32_2.1inch-Knob/edit/main/Libraries).

6. For **lvgl**:

    - Follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/blob/main/Arduino-FAQ/English/FAQ.md#how-to-add-an-lvgl-library-and-how-to-configure) to add *lv_conf.h* file and change the configurations.
    - Modify the macros in the [lvgl_port_v8.h](./lvgl_port_v8.h) file to configure the LVGL porting parameters.

7. Navigate to the `Tools` menu in the Arduino IDE to choose a ESP board and configure its parameters.
    | Setting                               | Value                                 |
    | :-------------------------------: | :-------------------------------: |
    | Board                                 | ESP32S3 Dev Module           |
    | CPU Frequency                   | 240MHz (WiFi)                    |
    | Core Debug Level                | None                                 |
    | USB CDC On Boot                | Disabled                              |
    | USB DFU On Boot                | Disabled                             |
    | Events Run On                     | Core 1                               |  
    | Flash Mode                         | QIO 80MHz                         |
    | Flash Size                           | 16MB (128Mb)                    |
    | Arduino Runs On                  | Core 1                               |
    | USB Firmware MSC On Boot | Disabled                             |
    | Partition Scheme                | 16M Flash (3MB APP/9.9MB FATFS) |
    | PSRAM                                | OPI PSRAM                         |
    | Upload Mode                     |     UART0/Hardware CDC            |
    | Upload Speed                     | 921600                               |
    | USB Mode                           | Hardware CDC and JTAG     |
8. Verify and upload the example to your ESP board.
9. If burning fails Please hold down the "BOOT" button and try downloading the program again.

## Serial Output

```bash
...
LVGL porting example start
Initialize panel device
Initialize LVGL
Create UI
LVGL porting example end
IDLE loop
IDLE loop
...
```

## Troubleshooting

Please check the [FAQ](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/FAQ.md) first to see if the same question exists. If not, please create a [Github issue](https://github.com/VIEWESMART/VIEWE-FAQ/issues). We will get back to you as soon as possible.
