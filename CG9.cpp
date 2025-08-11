#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

// Base class Shape to demonstrate polymorphism
class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape" << endl;
    }
};

// Class for drawing the head
class Head : public Shape {
public:
    void draw() override {
        cout << "    O    " << endl; // Head representation
    }
};

// Class for drawing the body
class Body : public Shape {
public:
    void draw() override {
        cout << "   /|\\   " << endl; // Arms and torso
        cout << "   / \\   " << endl; // Legs
    }
};

// Class for drawing the umbrella
class Umbrella : public Shape {
public:
    void draw() override {
        cout << "  ~~~~~~  " << endl; // Umbrella top
        cout << "   | |    " << endl; // Umbrella handle
    }
};

// Class for drawing the rain
class Rain : public Shape {
public:
    void draw() override {
        for (int i = 0; i < 5; i++) {
            cout << "~~~~~~~~~~" << endl; // Rain drops
        }
    }
};

// Function to clear the console
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Global objects
Head head;
Body body;
Umbrella umbrella;
Rain rain;

// Function to draw the scene
void drawScene(int position) {
    clearScreen();

    rain.draw();

    // Draw spaces for the walking effect
    for (int i = 0; i < position; i++) {
        cout << " ";
    }

    umbrella.draw();

    for (int i = 0; i < position; i++) {
        cout << " ";
    }

    head.draw();

    for (int i = 0; i < position; i++) {
        cout << " ";
    }

    body.draw();
}

int main() {
    int position = 0;
    bool movingRight = true;

    while (true) {
        drawScene(position);

        // Update position
        if (movingRight) {
            position++;
            if (position >= 10) movingRight = false;
        } else {
            position--;
            if (position <= 0) movingRight = true;
        }

        // Delay for animation
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    return 0;
}

