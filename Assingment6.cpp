#include <GL/glut.h>
#include <cmath>

float sunY = -0.8f; // Initial position of the sun
bool rising = true; // Sun rising flag

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background to black
}

void drawSun() {
       glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
       glBegin(GL_POLYGON);
       for (int i = 0; i < 360; i++) {
              float theta = i * 3.14159f / 180;
              glVertex2f(0.1f * cos(theta), 0.1f * sin(theta) + sunY);
       }
       glEnd();
}

void display() {
       glClear(GL_COLOR_BUFFER_BIT);
       if (sunY >= 0.0f) {
              glClearColor(0.5f, 0.7f, 1.0f, 1.0f); 
       } else {
              glClearColor(0.0f, 0.0f, 0.2f, 1.0f); 
       }
       glClear(GL_COLOR_BUFFER_BIT);
       drawSun();

       glutSwapBuffers(); 
}

void update(int value) {
       if (rising) {
              sunY += 0.01f;
              if (sunY >= 0.8f) {
              rising = false;
              }
       } else {
              sunY -= 0.01f;
              if (sunY <= -0.8f) {
              rising = true;
              }
       }
    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(100, update, 0); // Call update after 100 milliseconds
}

int main(int argc, char** argv) {
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
       glutInitWindowSize(800, 600);
       glutCreateWindow("Sun Rise and Sunset");

       init();
       glutDisplayFunc(display);
       glutTimerFunc(100, update, 0);

       glutMainLoop();
       return 0;
}