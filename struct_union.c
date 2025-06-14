// C style
#include <stdio.h>

struct Point {
    int x;
    int y;
};

union Data {
    int i;
    float f;
};

int main() {
    struct Point p = {10, 20};
    printf("Point: x=%d, y=%d\n", p.x, p.y);

    union Data d;
    d.i = 10;
    printf("Union int: %d\n", d.i);
    d.f = 3.14;
    printf("Union float: %f\n", d.f);

    return 0;
}
