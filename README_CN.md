<h1 align = "center">UEDX24240013-MD50ESP32_1.3inch-Knob-Display</h1>

<p align="center" width="90%">
    <img src="image/1.3.png" alt="">
</p>

## **[English](./README.md)**

## 仓库目录介绍

```
├── Libraries                 Arduino示例所需的库文件  
├── Schematic                 产品的电路原理图  
├── examples                  示例文件，包括IDF框架和Arduino框架
├── image                     产品或示例项目相关图片
├── information               产品规格说明，包括涉及的集成电路或外设
├── tools                     烧录工具和图像转换工具
└── README_CN.md               这是您当前正在阅读的文件，简要介绍了该产品
```

## 版本迭代：
| 开发板版本 | 屏幕尺寸 | 分辨率 | 更新日期 | 更新说明 |
| :-------------------------------: | :-------------------------------: | :-------------------------------: | :-------------------------------: | :-------------------------------: |
| UEDX24240013-MD50E | 1.3英寸 | 240*240 | 2024-07-23 | 初始版本 |

## 购买链接
| 产品                     | 系统级芯片（SOC） | 闪存（FLASH） | 随机存取存储器（RAM） | 链接                   |
| :----------------------: | :-------------: | :----------: | :----------------: | :------------------: |
| UEDX24240013-MD50E   | ESP32c3         | 4M          | 400KB              | [VIEWE商城](https://viewedisplay.com/product/esp32-7-inch-800x480-rgb-ips-tft-display-touch-screen-arduino-lvgl-uart/)  |

## 目录
- [硬件模块](#module)
- [引脚概述](#pinoverview)
- [适配板引脚对照表](#适配板引脚对照表)
- [快速入门](#快速入门)
- [固件下载](#固件下载)
- [常见问题](#常见问题)
- [原理图](#原理图)
- [相关资料](#相关资料)

## 模块
### 1.微控制单元（MCU）
* 芯片：ESP32-C3
* 闪存（FLASH）：4M
* 更多详细信息，请访问[乐鑫ESP32-C3数据手册](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)
### 2. 屏幕
* 尺寸：1.3英寸IPS屏幕
* 分辨率：240x240像素
* 屏幕类型：IPS
* 驱动芯片：GC9A01
* 兼容库：ESP32_Display_Panel
* 总线通信协议：4线SPI
### 3. 触摸
* 芯片：无触摸功能

## 引脚概述
| IPS屏幕引脚 | ESP32C3引脚|
| :------------------: | :------------------:|
| SPI-CS         | IO10      |
| SPI-SCK      | IO1       |
| SPI-SDA      | IO0      |
| SPI-DC       | IO4       |
|   LCD-TE       |  IO5   | 
| BACKLIGHT  | IO8       |


| 按钮引脚 | ESP32C3引脚 |
| :------------------: | :------------------:|
|   boot    | IO9       |

| 编码器引脚 | ESP32C3引脚 |
| :------------------: | :------------------:|
| PHA         | IO7       |
| PHB         | IO6       |

| USB | ESP32C3引脚 |
| :------------------: | :------------------:|
| USB-DN         | IO18      |
| USB-DP         | IO19      |

| UART引脚 | ESP32C3引脚 |
| :------------------: | :------------------:|
|   UART0RXD     | IO20      |
|   UART0TXD     | IO21      |

## 适配板引脚对照表
| FPC 编号 | 适配器引脚 | ESP32C3 引脚 |
| :------------------: | :------------------: | :------------------:|
|  1  |    5V      |    5V    |
|  2  |    PB7     |  GPIO3   |
|  3  |    GND     |    GND   |
|  4  |    RX2     |    NC    |
|  5  |    TX2     |    NC    |
|  6  |    RX1     |    UART0RXD/IO20    |
|  7  |    TX1     |    UART0TXD/IO21    |
|  8  |     NC     |    CHIP-EN    |
|  9  |   SK & D+   |   USB-DP/ IO19    |
|  10 |   SD & D-   |    USB-DN/ IO18   |

## 快速入门
### 软件框架配置
| 支持的集成开发环境 | 版本 |
| ------  | ------  |
| `[ESP-IDF]` | `[V5.1/5.2/5.3/5.4]` |
| `[Arduino IDE]` | `[esp32 >=v3.1.0]` | 
| `[Platformio IDE]` |  |

### ESP-IDF框架（[新手教程](https://github.com/VIEWESMART/VIEWE-Tutorial/blob/main/esp-idf/esp-idf%E6%96%B0%E6%89%8B%E5%85%A5%E9%97%A8%E6%95%99%E7%A8%8B.md)）
- 支持版本：v5.1/5.2/5.3
- 从代码仓库下载示例代码，可直接编译/运行。
- 仓库地址：[示例](examples/esp_idf)

### Arduino框架（[新手教程](https://github.com/VIEWESMART/VIEWE-Tutorial/blob/main/Arduino%20Tutorial/Arduino%20Getting%20Started%20Tutorial.md)）
1. **安装[Arduino](https://www.arduino.cc/en/software)**
- 根据你的系统类型选择安装方式。
- 新手请参考[初学者教程](https://github.com/VIEWESMART/VIEWE-Tutorial/blob/main/Arduino%20Tutorial/Arduino%20Getting%20Started%20Tutorial.md)。

2. **安装ESP32 SDK**
- 打开Arduino IDE
- 前往 `File` > `Preferences`
- 添加到 `Additional boards manager URLs`:
  ```
  https://espressif.github.io/arduino-esp32/package_esp32_index.json
  ```
  
- 导航至`Tools` > `Board` > `Boards Manager`
- 搜索 `esp32` by `Espressif Systems`
- 选择 `3.1.0` 以及以上，点击 `INSTALL` 按钮安装新版本低一个版本）。

3. **安装所需库**

| 编号 | 库 | 版本 |
| :------------------: | :------------------: | :------------------: |
|1|[ESP32_Display_Panel](https://github.com/esp-arduino-libs/ESP32_Display_Panel)|推荐最新版本|
|2|[ESP32_Button](https://github.com/esp-arduino-libs/ESP32_Button)|推荐最新版本|
|3|[ESP32_Knob](https://github.com/esp-arduino-libs/ESP32_Knob)|推荐最新版本|
|4|[lvgl-8.4.0](https://lvgl.io)|8.4.0（暂不支持V9）|
   
  `ESP32_Display_Panel` 及其依赖项可在Arduino库管理器中获取。在线安装：

 - 在Arduino IDE中，前往 `Sketch` > `Include Library` > `Manage Libraries...`.
 - 搜索`ESP32_Display_Panel` 库和选择 `1.0.3` 及其以上, 点击 `Install` 按键安装, 系统会提示您是否安装其依赖项，请点击 `INSTALL ALL` 安装所有.
 - 安装`LVGL`库（可选），推荐版本为`8.4.0`。
 对于手动安装，您可以从[Github](https://github.com/esp-arduino-libs/ESP32_Display_Panel)或[Arduino Library](https://www.arduinolibraries.info/libraries/esp32_display_panel)下载所需版本的`.zip`文件，然后在Arduino IDE中依次点击`Sketch` > `Include Library` > `Add .ZIP Library...`，选择下载好的`.zip`文件并点击`Open`进行安装。

> [!NOTE]
> * LVGL仅在图形用户界面示例中是必需的
> * 
4. **选择并配置开发板**
- 导航至 `Tools` > `Board` > `esp32` > `ESP32S3 Dev Module`

5. **打开示例**
- 导航至 `File` > `Examples` > `ESP32_Display_Panel`
- 选择 `Arduino` > `gui` > `lvgl_v8` > `simple_port`
  
6. **修改代码**
- 修改`esp_panel_board_supported_conf.h`中的宏定义以启用目标板。
- 启用文件宏定义：`#define ESP_PANEL_BOARD_DEFAULT_USE_SUPPORTED       (0)` ---> `#define ESP_PANEL_BOARD_DEFAULT_USE_SUPPORTED       (1)`
- 取消相应板卡的注释：`// #define BOARD_VIEWE_UEDX24240013-MD50E` ---> `#define BOARD_VIEWE_UEDX24240013-MD50E`
- 以下是修改后的`esp_panel_board_supported_conf.h`文件的部分内容：

    ```c
    ...
    /**
    * @brief Flag to enable supported board configuration (0/1)
    *
    * Set to `1` to enable supported board configuration, `0` to disable
    */
    #define ESP_PANEL_BOARD_DEFAULT_USE_SUPPORTED       (1)
    ...
    // #define BOARD_VIEWE_SMARTRING
    #define BOARD_VIEWE_UEDX24240013_MD50E
    // #define BOARD_VIEWE_UEDX24320024E_WB_A
    // #define BOARD_VIEWE_UEDX24320028E_WB_A
    // #define BOARD_VIEWE_UEDX24320035E_WB_A
    // #define BOARD_VIEWE_UEDX32480035E_WB_A
    // #define BOARD_VIEWE_UEDX46460015_MD50ET
    // #define BOARD_VIEWE_UEDX48270043E_WB_A
    // #define BOARD_VIEWE_UEDX48480021_MD80E_V2
    // #define BOARD_VIEWE_UEDX48480021_MD80E
    // #define BOARD_VIEWE_UEDX48480021_MD80ET
    // #define BOARD_VIEWE_UEDX48480028_MD80ET
    // #define BOARD_VIEWE_UEDX48480040E_WB_A
    // #define BOARD_VIEWE_UEDX80480043E_WB_A
    // #define BOARD_VIEWE_UEDX80480050E_AC_A
    // #define BOARD_VIEWE_UEDX80480050E_WB_A
    // #define BOARD_VIEWE_UEDX80480050E_WB_A_2
    // #define BOARD_VIEWE_UEDX80480070E_WB_A
    ...
    ```

> [!WARNING]
> * 不要同时启用`ESP_PANEL_BOARD_DEFAULT_USE_SUPPORTED`和`ESP_PANEL_BOARD_DEFAULT_USE_CUSTOM`
> * 你不能同时启用多个板

7. **配置工具选项：**
#### ESP32-C3
    | 设置 | 值 |
    | :-------------------------------: | :-------------------------------: |
    | Board                                 | ESP32C3 Dev Module           |
    | CPU Frequency                   | 160MHz (WiFi)                    |
    | Core Debug Level                | None                                 |
    | USB CDC On Boot                | Disabled                              |
    | Erase All Flash Before Sketch Upload                | Disabled         |
    | Flash Frequency                     | 80MHz                            |  
    | Flash Mode                         | QIO                               |
    | Flash Size                           | 4MB (32Mb)                      |
    | JTAG Adapter                 | Disabled                                |
    | Partition Scheme                | Custom |
    | Upload Speed                     | 921600                               |

   
8. 选择正确的端口。
9. 点击右上角的“<kbd>[√](image/8.png)</kbd>”进行编译，若编译正确，将微控制器连接到电脑，点击右上角的“<kbd>[→](image/9.png)</kbd>”进行下载。

> [!NOTE]
> LVGL颜色交换设置：`SPI`和`QSPI`屏幕需要将`lv_conf.h`中的宏`LV_COLOR_16_SWAP`设置为`1`，而`RGB`屏幕则设置为`0`，如下所示：
    ```c
    /**
     * @file lv_conf.h
     * Configuration file for v8.4.0
     */
    
    /* clang-format off */
    #if 1 /*Set it to "1" to enable content*/
    
    #ifndef LV_CONF_H
    #define LV_CONF_H
    
    #include <stdint.h>
    
    /*====================
       COLOR SETTINGS
     *====================*/
    
    /*Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888)*/
    #define LV_COLOR_DEPTH 16
    
    /*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
    #define LV_COLOR_16_SWAP 1
    ...
    ```

### PlatformIO
1. 安装[Visual Studio Code](https://code.visualstudio.com/Download)，根据你的系统类型选择安装版本。
2. 打开Visual Studio Code软件侧边栏的“扩展”部分（或者使用“<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd>”打开扩展），搜索“PlatformIO IDE”扩展并下载。
3. 在扩展程序安装过程中，你可以前往GitHub下载该程序。点击绿色文字的“<> Code”，即可下载主分支。
4. 扩展程序安装完成后，打开侧边栏中的资源管理器（或者使用“<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>E</kbd>”打开），点击“打开文件夹”，找到你刚刚下载的项目代码（整个文件夹），然后找到PlatformIO文件夹并点击“添加”。此时，项目文件将被添加到你的工作区。
5. 打开项目文件夹中的“platformio.ini”文件（PlatformIO会自动打开与所添加文件夹对应的“platformio.ini”文件）。在“[platformio]”部分下，取消注释并选择你想要烧录的示例程序（该程序应以“default_envs = xxx”开头）。然后点击左下角的“<kbd>[√](image/4.png)</kbd>”进行编译，若编译正确，将微控制器连接到电脑，再点击左下角的“<kbd>[→](image/5.png)</kbd>”下载程序。

## 固件下载
1. 打开项目文件“tools”，找到ESP32烧录工具并打开它。
2. 选择正确的烧录芯片和烧录方式，然后点击“确定”。如图所示，按照步骤1->2->3->4->5进行程序烧录。如果烧录不成功，按住“BOOT-0”按钮，然后重新下载并烧录。
3. 烧录项目文件根目录下的“[firmware](./firmware/)”文件，里面有固件文件版本的说明，只需选择合适的版本进行下载即可。
   
<p align="center" width="100%">
    <img src="image/10.png" alt="example">
    <img src="image/11.png" alt="example">
</p>

## 常见问题
* 问：阅读了上述教程后，我仍然不知道如何搭建编程环境。我该怎么办？
* 答：如果阅读上述教程后仍不理解如何搭建环境，您可以参考[VIEWE-FAQ]()文档中的说明进行搭建。
<br />

* 问：为什么打开Arduino IDE时会提示我更新库文件？我应该更新它们吗？
* 答：选择不更新库文件。不同版本的库文件可能不兼容，因此不建议更新库文件。
<br />

* 问：为什么我的开发板上的“Uart”接口没有串行数据输出？它是不是有缺陷，不能用了？
* 答：默认的项目配置将USB接口用作Uart0串行输出，用于调试。“Uart”接口与Uart0相连，因此如果不进行配置，它不会输出任何数据。<br />对于PlatformIO用户，请打开项目文件“platformio.ini”，将“build_flags = xxx”下的选项从“-D ARDUINO_USB_CDC_ON_BOOT=true”修改为“-D ARDUINO_USB_CDC_ON_BOOT=false”，以启用外部“Uart”接口。<br />对于Arduino用户，打开“工具”菜单，选择“USB CDC On Boot: Disabled”，以启用外部“Uart”接口。
<br />

* 问：为什么我的开发板总是无法下载程序？
* 答：请按住“BOOT”按钮，然后尝试再次下载程序。
<br />

## 原理图
<p align="center" width="100%">
    <img src="Schematic/1.3.png" alt="example">
</p>

## 相关资料
[产品规格](information/UEDX24240013-MD50E%20V3.3%20SPEC.pdf)

[显示屏数据表](information/UE013QV-RH13-A003B.pdf)

[按钮](information/6x6Silent%20switch.pdf)

[编码器](information/EC110101R6D-HA1-011%20YBGW080.pdf)

[esp32c3数据手册(英文)](information/esp32-c3_datasheet_en.pdf)

[esp32c3数据手册(中文)](information/esp32-c3_datasheet_cn.pdf)
