#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ssd1306.h"
#include "ssd1306_draw.h"
#include "ssd1306_font.h"
#include "ssd1306_default_if.h"

#define USE_I2C_DISPLAY
#define USE_SPI_DISPLAY

#if defined USE_I2C_DISPLAY
    static const int I2CDisplayAddress = 0x3C;
    static const int I2CDisplayWidth = 128;
    static const int I2CDisplayHeight = 64;
    static const int I2CResetPin = -1;

    struct SSD1306_Device I2CDisplay;
#endif

#if defined USE_SPI_DISPLAY
    static const int SPIDisplayChipSelect = 15;
    static const int SPIDisplayWidth = 128;
    static const int SPIDisplayHeight = 64;
    static const int SPIResetPin = 5;

    struct SSD1306_Device SPIDisplay;
#endif

static struct SSD1306_Device* Displays[ ] = {
#if defined USE_I2C_DISPLAY
    &I2CDisplay,
#endif
#if defined USE_SPI_DISPLAY
    &SPIDisplay,
#endif
    NULL
};

const int DisplayCount = sizeof( Displays ) / sizeof( Displays[ 0 ] );

const struct SSD1306_FontDef* FontList[ ] = {
    &Font_droid_sans_fallback_11x13,
    &Font_droid_sans_fallback_15x17,
    &Font_droid_sans_fallback_24x28,
    &Font_droid_sans_mono_7x13,
    &Font_droid_sans_mono_13x24,
    &Font_droid_sans_mono_16x31,
    &Font_liberation_mono_9x15,
    &Font_liberation_mono_13x21,
    &Font_liberation_mono_17x30,
    NULL
};


bool DefaultBusInit( void ) {
    #if defined USE_I2C_DISPLAY
        assert( SSD1306_I2CMasterInitDefault( ) == true );
        assert( SSD1306_I2CMasterAttachDisplayDefault( &I2CDisplay, I2CDisplayWidth, I2CDisplayHeight, I2CDisplayAddress, I2CResetPin ) == true );
    #endif

    #if defined USE_SPI_DISPLAY
        assert( SSD1306_SPIMasterInitDefault( ) == true );
        assert( SSD1306_SPIMasterAttachDisplayDefault( &SPIDisplay, SPIDisplayWidth, SPIDisplayHeight, SPIDisplayChipSelect, SPIResetPin ) == true );
    #endif

    return true;
}



void screen_print(char * text1, char * text2, char * text3)
{
    
   SSD1306_SetFont( Displays[0], FontList[0] );
   SSD1306_Clear( Displays[0], SSD_COLOR_BLACK );
   SSD1306_FontDrawAnchoredString( Displays[0], TextAnchor_North, text1, SSD_COLOR_WHITE);
   SSD1306_FontDrawAnchoredString( Displays[0], TextAnchor_Center, text2, SSD_COLOR_WHITE);
   SSD1306_FontDrawAnchoredString( Displays[0], TextAnchor_South, text3, SSD_COLOR_WHITE);
   SSD1306_Update( Displays[0]);
}