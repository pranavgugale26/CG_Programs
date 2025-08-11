#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

// Encapsulation: Triangle class
class Triangle {
private:
    int x1, y1, x2, y2, x3, y3;

public:
    // Constructor to initialize triangle vertices
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    // DDA Line Drawing Algorithm
    void drawLineDDA(int x1, int y1, int x2, int y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        float steps = max(abs(dx), abs(dy));

        float xInc = dx / steps;
        float yInc = dy / steps;

        float x = x1, y = y1;
        for (int i = 0; i <= steps; ++i) {
            putpixel(round(x), round(y), WHITE);
            x += xInc;
            y += yInc;
        }
    }

    // Function to draw the triangle
    void drawTriangle() {
        drawLineDDA(x1, y1, x2, y2);
        drawLineDDA(x2, y2, x3, y3);
        drawLineDDA(x3, y3, x1, y1);
    }

    // Function to draw circle points for Bresenham's algorithm
	void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + x, yc - y, YELLOW);
    putpixel(xc - x, yc - y, YELLOW);
    putpixel(xc + y, yc + x, YELLOW);
    putpixel(xc - y, yc + x, YELLOW);
    putpixel(xc + y, yc - x, YELLOW);
    putpixel(xc - y, yc - x, YELLOW);
	}

	// Modified Bresenham's Circle Drawing Algorithm
	void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (y >= x) {
        drawCirclePoints(xc, yc, x, y);
        ++x;

        if (d > 0) {
            --y;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        	}
    	}
	}


    // Function to draw the incircle of the triangle
    void drawIncircle() {
        float a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        float b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        float c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        float p = a + b + c;  // Perimeter
        float s = p / 2;      // Semi-perimeter

        int ix = (a * x1 + b * x2 + c * x3) / p;
        int iy = (a * y1 + b * y2 + c * y3) / p;

        float radius = sqrt((s - a) * (s - b) * (s - c) / s);
        drawCircleBresenham(ix, iy, round(radius));
    }

    // Function to draw the circumcircle of the triangle
    void drawCircumcircle() {
        float d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

        int ux = ((pow(x1, 2) + pow(y1, 2)) * (y2 - y3) +
                  (pow(x2, 2) + pow(y2, 2)) * (y3 - y1) +
                  (pow(x3, 2) + pow(y3, 2)) * (y1 - y2)) /
                 d;

        int uy = ((pow(x1, 2) + pow(y1, 2)) * (x3 - x2) +
                  (pow(x2, 2) + pow(y2, 2)) * (x1 - x3) +
                  (pow(x3, 2) + pow(y3, 2)) * (x2 - x1)) /
                 d;

        float r = sqrt(pow(x1 - ux, 2) + pow(y1 - uy, 2));
        drawCircleBresenham(ux, uy, round(r));
    }
};

// Main Function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Create a Triangle object
    Triangle t(150, 200, 250, 100, 350, 200);

    // Draw the triangle
    t.drawTriangle();

    // Draw the incircle
    t.drawIncircle();

    // Draw the circumcircle
    t.drawCircumcircle();

    getch();
    closegraph();
    return 0;
}

