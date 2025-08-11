#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize graphics mode and the graphics driver
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the background color (optional)
    setbkcolor(WHITE);
    cleardevice();

    // Set the drawing color (optional)
    setcolor(BLUE);

    // Draw a circle with center (x, y) and radius r
    int x = 200, y = 200, radius = 100;
    circle(x, y, radius);

    // Display a message (optional)
    outtextxy(150, 320, "Circle Example in C++");

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}

