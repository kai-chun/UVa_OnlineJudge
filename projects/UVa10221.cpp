#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    double distFromSurface, angle;
    double earthRadius = 6440.0; // km
    double degreeOfmin = 360 / 1440;
    double arcDist, chordDist;
    string unit;

    while (cin >> distFromSurface >> angle){
        cin >> unit;

        // 1 degree = 60 arc min
        if (unit == "min"){
            angle = angle / 60;
        }
        while (angle > 360){
            angle -= 360;
        }
        if (angle > 180){
            angle = 360 - angle;
        }

        arcDist = 2 * (distFromSurface + earthRadius) * (angle/360) * M_PI;
        chordDist = sin(angle / 2 * M_PI / 180.0) * (earthRadius+distFromSurface) * 2;

        printf("%.6f %.6f\n", arcDist, chordDist);
    }
    return 0;
}