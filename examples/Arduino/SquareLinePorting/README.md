# SquareLine Porting Example

The example demonstrates how to port SquareLine. And for RGB LCD, it can enable the avoid tearing function.

## How to Use

To use this example, please firstly install the following dependent libraries:

- ESP32_Display_Panel (> 0.2.1)
- ESP32_IO_Expander (>= 0.1.0 && < 0.2.0)
- lvgl (>= v8.3.9, < v9)
- ESP32_Button (>= 0.0.1)
- ESP32_Knob (>= 0.0.1)
- ui

Follow the steps below to configure:

1. For **ESP32_Display_Panel**:

     `Note`:Since the latest version is still being updated and has not been released, please temporarily use the test version in this repository: `Libraries`->[`ESP32_Display_Panel`](https://github.com/VIEWESMART/UEDX24320028ESP32-3.5inch-320_480-Display/tree/main/Libraries/ESP32_Display_Panel).

     - Follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#configuring-drivers) to configure drivers if needed.
    - If using a supported development board, follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#using-supported-development-boards) to configure it.
    - If using a custom board, follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/tree/main/Arduino-FAQ/English/How_To_Use.md#using-custom-development-boards) to configure it.

2. For **ESP32_IO_Expander\ESP32_Button\ESP32_Knob**:
   - Just install it directly.

3. For **lvgl**:

    - Follow the [steps](https://github.com/VIEWESMART/VIEWE-FAQ/blob/main/Arduino-FAQ/English/FAQ.md#how-to-add-an-lvgl-library-and-how-to-configure) to add *lv_conf.h* file and change the configurations.
    - Modify the macros in the [lvgl_port_v8.h](./lvgl_port_v8.h) file to configure the LVGL porting parameters.

4. For **ui**:
   
Copy the [ui](./libraries/ui/) folder from `libraries` to [Arduino Library directory](../../../../README.md#where-is-the-directory-for-arduino-libraries).Here I have put ui into the libraries.


6. Navigate to the `Tools` menu in the Arduino IDE to choose a ESP board and configure its parameters.
     | Setting                               | Value                                 |
     | :-------------------------------: | :-------------------------------: |
     | Board                                 | ESP32C3 Dev Module           |
     | CPU Frequency                   | 160MHz (WiFi)                    |
     | Core Debug Level                | None                                 |
     | USB CDC On Boot                | Disabled                              |
     | Erase All Flash Before Sketch Upload                | Disabled                             |
     | Flash Frequency                     | 80MHz                               |  
     | Flash Mode                         | QIO                          |
     | Flash Size                           | 4MB (32Mb)                    |
     | JTAG Adapter                 | Disabled                               |
     | Partition Scheme                | Huge APP |
     | Upload Speed                     | 921600                               |
7. Verify and upload the example to your ESP board.
8. If burning fails Please hold down the "BOOT" button and try downloading the program again.

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

Please check the [FAQ](../../../../docs/FAQ.md) first to see if the same question exists. If not, please create a [Github issue](https://github.com/esp-arduino-libs/ESP32_Display_Panel/issues). We will get back to you as soon as possible.
