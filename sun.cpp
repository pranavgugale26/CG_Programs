#include <math.h>
#include <GL/glut.h>

// Sun position
float sunX = -0.7;
float sunY = -0.3;
float sunZ = -1.4;

// Colour of sun
float sunR = 2.0;
float sunG = 1.0;
float sunB = 0.0;

// Background color
float bgR = 0;
float bgG = 0;
float bgB = 0;

bool flag = true;

void drawSun() {
    glColor3f(sunR, sunG, sunB);
    glTranslatef(sunX, sunY, sunZ);
    glutSolidSphere(0.2, 30, 30); // Smooth sun
}

void reshape(int w, int h) {
    // Change according to viewport
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); // 3D objects map into 2D
    glLoadIdentity();
    double aspect = (double)w / h;
    gluPerspective(45, aspect, 0.1, 200);
}

void update(int value) {
    if (flag) {
        sunX += 0.01;
        sunY += 0.007;
        sunR -= 0.001;
        sunG += 0.002;
        bgB += 0.001;

        if (sunX > 0.3)
            flag = false;
    }
    else {
        sunX += 0.01;
        sunY -= 0.007;
        sunR += 0.001;
        sunG -= 0.002;
        bgB -= 0.001;

        if (sunX < -0.3)
            flag = true;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(bgR, bgG, bgB, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set up camera
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    drawSun();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500); // Correct function name
    glutCreateWindow("Sunrise Sunset Transition");

    // Registering functions
    glutDisplayFunc(display); // Correct the function name
    glutReshapeFunc(reshape);  // Correct the function registration for reshaping
    glutTimerFunc(20, update, 0);

    glEnable(GL_DEPTH_TEST);  // Enable depth testing

    glutMainLoop();
    return 0;
}

