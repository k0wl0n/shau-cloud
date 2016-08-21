#include <FastLED.h>

#define LED_PIN     8
#define NUM_LEDS    20
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_STRIPS   3
#define UPDATES_PER_SECOND 100

CRGB leds[NUM_STRIPS][NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
const uint8_t PIN_NO[] = { 8, 9, 11 };

extern CRGBPalette16 langitsenja, langitbiru;
extern const TProgmemPalette16 langitsenja_p PROGMEM;
extern const TProgmemPalette16 langitbiru_p PROGMEM;

void setup() {
    delay( 3000 ); // power-up safety delay

//    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds[0], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds[1], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 11, COLOR_ORDER>(leds[2], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds[3], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds[4], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 11, COLOR_ORDER>(leds[5], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds[6], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds[7], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 11, COLOR_ORDER>(leds[8], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds[9], NUM_LEDS).setCorrection( TypicalLEDStrip );
//    FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds[10], NUM_LEDS).setCorrection( TypicalLEDStrip );

    FastLED.setBrightness(BRIGHTNESS);    
}


void loop(){

    static uint8_t startIndex = 0;
    startIndex = startIndex + 1;

    awan(langitbiru_p, startIndex);
    
    FastLED.show();
    FastLED.delay(15000 / UPDATES_PER_SECOND);
}

void awan( CRGBPalette16 warna, uint8_t colorIndex ){
    currentPalette = langitbiru_p;           
    currentBlending = LINEARBLEND;
    
    uint8_t brightness = 255;
    
    for(uint8_t a=0;a<NUM_STRIPS;a++){
      for( uint8_t i = 0; i < NUM_LEDS; i++) {
          leds[a][i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
      }
      colorIndex += 3;
    }
}

// leds[10] = { "M", "I", "C", "L", "I", "B" }
// leds[9]  = { "O", "D", "I", "N", "E" }
// leds[8]  = { "A", "D", "A", "L", "A", "H" }
// leds[7]  = { "B", "U", "K", "U", "Q" }
// leds[6]  = { "C", "A", "L", "Y", "D", "A" }
// leds[5]  = { "H", "N", "E", "E", "L" }
// leds[4]  = { "S", "L", "D", "S", "E", "L" }
// leds[3]  = { "I", "I", "U", "D", "R" }
// leds[2]  = { "X", "U", "V", "N", "E", "U" }
// leds[1]  = { "M", "A", "E", "G", "Z"" }
// leds[0]  = { "I", "N", "J", "S", "U", "N" }

//sequence
// 1. BUKU
// leds[7][0-3]
// 2. ADALAH
// leds[8][0-6]
// 3. JENDELA
// leds[0][2], leds[1][2], leds[2][3], leds[3][3], leds[4][4], leds[5][4], leds[6][5]
// 4. DUNIA
// leds[9][1], leds[7][1], leds[5][1], leds[3][1], leds[1][1]
// 5. MICLIB
// leds[10][0-6]
// 6. ALUN
// leds[6][5], leds[4][5], leds[2][5], leds[0][5]
// 7. BANDUNG
// leds[7][0], leds[6][1], leds[5][1], leds[4][2], leds[3][2], leds[2][3], leds[1][3]
// 8. SHAU
// leds[4][0], leds[5][0], leds[6][1], leds[7][1]

// v0.1 crosswords without animation effect

void crosswords(uint8_t timedelay){

    uint8_t i=0;
    
    resetLed(timedelay);
    for(i=0;i<3;i++){ leds[7][i] = 0xffffff; } resetLed(timedelay);
    for(i=0;i<6;i++){ leds[8][i] = 0xffffff; } resetLed(timedelay);
    leds[0][2] = 0xffffff; leds[1][2] = 0xffffff; leds[2][3] = 0xffffff;
    leds[3][3] = 0xffffff; leds[4][4] = 0xffffff; leds[5][4] = 0xffffff;
    resetLed(timedelay);   leds[9][1] = 0xffffff; leds[7][1] = 0xffffff; 
    leds[5][1] = 0xffffff; leds[3][1] = 0xffffff; leds[1][1] = 0xffffff; 
    resetLed(timedelay+2000); 
    for(i=0;i<6;i++){ leds[10][i] = 0xffffff; } resetLed(timedelay);
    leds[6][5] = 0xffffff; leds[4][5] = 0xffffff; leds[2][5] = 0xffffff;
    leds[0][5] = 0xffffff; resetLed(timedelay)    leds[7][0] = 0xffffff;
    leds[6][1] = 0xffffff; leds[5][1] = 0xffffff; leds[4][2] = 0xffffff;
    leds[3][2] = 0xffffff; leds[2][3] = 0xffffff; leds[1][3] = 0xffffff;
    resetLed(timedelay);   leds[4][0] = 0xffffff; leds[7][1] = 0xffffff;
    resetLed(timedelay+2000);    
    
}

private void resetLed(uint8_t timedelay){
    delay(timedelay);
    for(uint8_t i=0;i<NUM_STRIPS;i++){
        for(uint8_t j=0;j<NUM_LEDS;j++){
            leds[i][j] = 0x000000;
        }
    }
}

const TProgmemRGBPalette16 langitsenja_p PROGMEM ={
    0xff751a, 0xff6600, 0xff6600, 0x87ceeb,    
    0xff751a, 0xff6600, 0xff6600, 0x87ceeb,  
    0xff751a, 0xff6600, 0xff6600, 0x87ceeb,    
    0xff751a, 0xff6600, 0xff6600, 0x87ceeb
};

const TProgmemRGBPalette16 langitbiru_p PROGMEM ={
    0x0000ff, 0x0000ff, 0xadd8e6, 0x87ceeb,    
    0x0000ff, 0x0000ff, 0xadd8e6, 0x87ceeb,    
    0x0000ff, 0x0000ff, 0xadd8e6, 0x87ceeb,    
    0x0000ff, 0x0000ff, 0xadd8e6, 0x87ceeb
};

