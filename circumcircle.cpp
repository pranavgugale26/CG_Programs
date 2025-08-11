#include <iostream>
#include <graphics.h>
#include <algorithm>
#include <cmath>

using namespace std;

void ddaline(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xIncreament = dx / (float)steps;
    float yIncreament = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncreament;
        y += yIncreament;
    }
}

void brezhmanscircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int s = 3 - 2 * r;
    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (s > 0) {
            y--;
            s += 4 * (x - y) + 10;
        } else {
            s += 4 * x + 6;
        }
    }
}

void drawtriangle(int xc, int yc, int r) {
    int x1 = xc + r * cos(M_PI / 6);
    int y1 = yc - r * sin(M_PI / 6);
    int x2 = xc + r * cos(M_PI / 6 + M_PI / 3);
    int y2 = yc - r * sin(M_PI / 6 + M_PI / 3);
    int x3 = xc + r * cos(M_PI / 6 + 2 * M_PI / 3);
    int y3 = yc - r * sin(M_PI / 6 + 2 * M_PI / 3);
    
    ddaline(x1, y1, x2, y2);
    ddaline(x2, y2, x3, y3);
    ddaline(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc = 320, yc = 240, r = 100;
    int inner_r = r / 2;

    brezhmanscircle(xc, yc, r);
    brezhmanscircle(xc, yc, inner_r);
    drawtriangle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}

