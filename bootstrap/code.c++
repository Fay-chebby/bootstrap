#ifdef _APPLE_CC_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawHut() {
  // Draw the body of the hut
  glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-0.4, -0.6, 0.5);

    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(0.4, -0.6, 0);

    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(0.4, 0.2, 0);

    glColor3f(1.0, 1.0, 1.0); // White
    glVertex3f(-0.4, 0.2, 0.5);
  glEnd();

  // Draw the roof of the hut
  glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-0.4, 0.2, 0.5);

    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(0, 1.0, 0);

    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(0.4, 0.2, 0.5);
  glEnd();
}

void display() {
  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw the hut
  drawHut();

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}

int main(int argc, char** argv) {
  // Use a single buffered window in RGB mode.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("A Simple Colored Hut");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events. This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
  return 0;
}
