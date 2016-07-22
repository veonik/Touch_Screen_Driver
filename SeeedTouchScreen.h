/*
  SeeedTouchScreen.h - Library for 4-line resistance touch screen.
  Modified by loovee Aug 12, 2012.
  (c) ladyada / adafruit
  Code under MIT License.
*/
#define MIN_TOUCH_PRESSURE 10

//Measured ADC values for (0,0) and (210-1,320-1)
//TS_MINX corresponds to ADC value when X = 0
//TS_MINY corresponds to ADC value when Y = 0
//TS_MAXX corresponds to ADC value when X = 240 -1
//TS_MAXY corresponds to ADC value when Y = 320 -1

#define TS_MINX 116*2
#define TS_MAXX 890*2
#define TS_MINY 83*2
#define TS_MAXY 913*2

class TouchPoint {
    public:
    int x, y, z;

    TouchPoint(void);
    TouchPoint(int x, int y, int z);
    bool operator==(TouchPoint);
    bool operator!=(TouchPoint);

};

class TouchScreen {
    private:
    unsigned long _lastRead;
    TouchPoint _lastTouch;
    unsigned char _yp, _ym, _xm, _xp;

    public:
    TouchScreen(unsigned char xp, unsigned char yp, unsigned char xm, unsigned char ym);
    TouchPoint getPoint();
    int isTouching(int x1, int y1, int x2, int y2);
};
