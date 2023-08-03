#ifndef ledstrip_h
#define ledstrip_h

#include "Arduino.h"

class ledstrip {
    private:
        int _pins[20];
        int _ledNum;
        bool _isRGB;
        bool _isAnalog;
        float mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh) {
            return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
        }
    public:
        ledstrip(int pins[], int ledNum, bool isRGB, bool isAnalog) {
            _ledNum = ledNum;
            _isRGB = isRGB;
            _isAnalog = isAnalog;

            for (int i = 0; i <= _ledNum - 1; i++) {
                _pins[i] = pins[i];
                pinMode(_pins[i], OUTPUT);
            }
        }
        void setLedState(int color[4], int led) {
            if (_isRGB) {
                analogWrite(_pins[led * 3], color[0] * mapFloat(color[3], 0, 255, 0, 1));
                analogWrite(_pins[led * 3 + 1], color[1] * mapFloat(color[3], 0, 255, 0, 1));
                analogWrite(_pins[led * 3 + 2], color[2] * mapFloat(color[3], 0, 255, 0, 1));
            }
            else {
                if (_isAnalog) {
                    analogWrite(_pins[led], color[1] * mapFloat(color[1], 0, 255, 0, 1));
                }
                else {
                    digitalWrite(_pins[led], color[0]);
                };
            };
        };
        void resetLeds() {
            for (int i = 0; i <= _ledNum - 1; i++) {
                digitalWrite(_pins[i], LOW);
            }
        }
};

#endif