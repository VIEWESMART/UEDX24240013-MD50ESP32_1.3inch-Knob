/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

/* Set to 1 if using a supported board */
#define ESP_PANEL_USE_SUPPORTED_BOARD       (1)         // 0/1

#if ESP_PANEL_USE_SUPPORTED_BOARD
/**
 * Uncomment one of the following macros to select an supported development board. If multiple macros are uncommented
 * at the same time, an error will be prompted during compilation.
 *
 */


#define BOARD_UEDX24240013_MD50E
// #define BOARD_UEDX48480021_MD80E
// #define BOARD_UEDX48480021_MD80ET
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_24  
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_28 
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_35_V1  //The resolution is 240*320
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_35_V2     //The resolution is 320*480
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_40
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_43_V1 //The resolution is 800*480
//  #define BOARD_VIEWE_ESP_S3_Touch_LCD_43_V2 //The resolution is 480*272
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_50_V1
// #define BOARD_VIEWE_ESP_S3_Touch_LCD_70

/*
The following products control IM through software
*/
#if defined(BOARD_VIEWE_ESP_S3_Touch_LCD_24) || \
    defined(BOARD_VIEWE_ESP_S3_Touch_LCD_28) || \
    defined(BOARD_VIEWE_ESP_S3_Touch_LCD_35_V1) || \
    defined(BOARD_VIEWE_ESP_S3_Touch_LCD_35_V2)
#define IM
#define IM0 47
#define IM1 48
#endif

#if defined(BOARD_UEDX48480021_MD80ET) || defined(BOARD_UEDX48480021_MD80E)
#define KNOB21
#endif
#if defined(BOARD_UEDX24240013_MD50E)
#define KNOB13
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// File Version ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Do not change the following versions, they are used to check if the configurations in this file are compatible with
 * the current version of `ESP_Panel_Board_Supported.h` in the library. The detailed rules are as follows:
 *
 *   1. If the major version is not consistent, then the configurations in this file are incompatible with the library
 *      and must be replaced with the file from the library.
 *   2. If the minor version is not consistent, this file might be missing some new configurations, which will be set to
 *      default values. It is recommended to replace it with the file from the library.
 *   3. If the patch version is not consistent, it will not affect normal functionality.
 *
 */
#define ESP_PANEL_BOARD_SUPPORTED_FILE_VERSION_MAJOR 0
#define ESP_PANEL_BOARD_SUPPORTED_FILE_VERSION_MINOR 7
#define ESP_PANEL_BOARD_SUPPORTED_FILE_VERSION_PATCH 0

#endif
