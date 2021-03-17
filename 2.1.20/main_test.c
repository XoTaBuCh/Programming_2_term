/*Copyright 2021 XoT@B*/
#include "main.h"
#include <math.h>
#include <assert.h>

int test_circle() {
    assert(AreaOfCircle(1) == 3.1415926535);
    assert(AreaOfCircle(2) == 12.566370614);
    assert(AreaByAngle(1, 0.6) == 0.30);
    assert(AreaByAngle(2, 4) == 8.00);
    assert(Circumference(1) == 6.283185307);
    assert(Circumference(2) == 12.566370614);
    assert(fabs(SideInscribedSquare(1) - 1.41421356237) < 0.0001);
    assert(fabs(SideInscribedSquare(2) - 2.82842712475) < 0.0001);
    assert(fabs(VolumeOfCone(1) - 1.04719755117) < 0.0001);
    assert(fabs(VolumeOfCone(2) - 8.37758040933) < 0.0001);
    }
#undef main
int main() {
    test_circle();
}
