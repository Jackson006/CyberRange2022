#ifndef _THINKINK_154_MONO_D67_H
#define _THINKINK_154_MONO_D67_H

// This file is #included by Adafruit_ThinkInk.h and does not need to
// #include anything else to pick up the EPD header or ink mode enum.

class ThinkInk_154_Mono_D67 : public Adafruit_SSD1681 {
public:
  ThinkInk_154_Mono_D67(int16_t SID, int16_t SCLK, int16_t DC, int16_t RST,
                        int16_t CS, int16_t SRCS, int16_t MISO,
                        int16_t BUSY = -1)
      : Adafruit_SSD1681(200, 200, SID, SCLK, DC, RST, CS, SRCS, MISO, BUSY){};

  ThinkInk_154_Mono_D67(int16_t DC, int16_t RST, int16_t CS, int16_t SRCS,
                        int16_t BUSY = -1, SPIClass *spi = &SPI)
      : Adafruit_SSD1681(200, 200, DC, RST, CS, SRCS, BUSY, spi){};

  void begin(thinkinkmode_t mode = THINKINK_MONO) {
    Adafruit_SSD1681::begin(true);
    setColorBuffer(0, true); // layer 0 uninverted
    setBlackBuffer(0, true); // only one buffer

    inkmode = mode; // Preserve ink mode for ImageReader or others

    layer_colors[EPD_WHITE] = 0b00;
    layer_colors[EPD_BLACK] = 0b01;
    layer_colors[EPD_RED] = 0b01;
    layer_colors[EPD_GRAY] = 0b01;
    layer_colors[EPD_LIGHT] = 0b00;
    layer_colors[EPD_DARK] = 0b01;

    default_refresh_delay = 1000;
    setRotation(3);
    powerDown();
  }
};

#endif // _THINKINK_154_MONO_D67_H
