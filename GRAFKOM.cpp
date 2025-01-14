#include <GL/glut.h>
#include <math.h>

float ypos = 0, zpos = 0, xpos = 0;
float a = -9, b = -5, c = -30;
float angleX = 0.0f, angleY = 0.0f;
float lastX = 0.0f, lastY = 0.0f;
float scale_factor = 1.0f;
float pintu = 0;
bool hidden = true;
void initLighting();

void kotak(float x1, float y1, float z1, float x2, float y2, float z2)
{
    glTranslatef(0.0f, -0.85f, -2.005f);
    glScalef(0.8f, 0.1f, 0.8f);

    // Depan
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x1, y2, z1);
    glEnd();

    // Atas
    glBegin(GL_QUADS);
    glVertex3f(x1, y2, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();

    // Belakang
    glBegin(GL_QUADS);
    glVertex3f(x1, y2, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);
    glEnd();

    // Bawah
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y1, z1);
    glVertex3f(x1, y1, z1);
    glEnd();

    // Samping kiri
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y1, z2);
    glEnd();

    // Samping kanan
    glBegin(GL_QUADS);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y1, z2);
    glEnd();
}

void Dinding()
{
    // Dinding kanan
    glPushMatrix();
    glTranslatef(24.75f, 5.25f, 12.0f);
    glScalef(0.5f, 9.5f, 14.0f);
    glColor3ub(178, 201, 173);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Dinding kiri
    glPushMatrix();
    glTranslatef(0.25f, 5.25f, 9.5f);
    glScalef(0.5f, 9.5f, 19.0f);
    glColor3ub(178, 201, 173);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Dinding belakang
    glPushMatrix();
    glTranslatef(12.5f, 5.25f, 0.25f);
    glScalef(25.0f, 9.5f, 0.5f);
    glColor3ub(145, 172, 143);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Atap()
{
    glPushMatrix();
    glTranslatef(12.5f, 10.25f, 9.5f);
    glScalef(25.0f, 0.5f, 19.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Lantai()
{
    glPushMatrix();
    glTranslatef(12.5f, 0.25f, 9.5f);
    glScalef(25.0f, 0.5f, 19.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Pintu()
{
    glPushMatrix();
    glTranslatef(24.5, 0, 6);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(pintu, 0.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    glColor3ub(203, 163, 92);
    kotak(6, 0.5, 0, 1, 10, 0.5);
    glEnd();
    glPopMatrix();
}

void Saklar()
{
    // Saklar
    glPushMatrix();
    glTranslatef(7.0f, 7.0f, 0.6f);
    glScalef(1.0f, 1.0f, 0.1f);
    glColor3f(1.1f, 1.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Tombol saklar
    glPushMatrix();
    glTranslatef(6.8f, 7.0f, 0.65f);
    glScalef(0.2f, 0.6f, 0.2f);
    glColor3f(0.1f, 0.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.2f, 7.0f, 0.65f);
    glScalef(0.2f, 0.6f, 0.2f);
    glColor3f(0.1f, 0.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void PapanTulis()
{
    // Bingkai Papan Tulis
    glPushMatrix();
    glTranslatef(13.0f, 6.55f, 0.5f);
    glScalef(10.0f, 5.0f, 0.3f);
    glColor3f(0, 0, 0);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Media Papan Tulis
    glPushMatrix();
    glTranslatef(13.0f, 6.55f, 0.6f);
    glScalef(9.5f, 4.5f, 0.3f);
    glColor3ub(251, 246, 233);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Meja()
{
    // Alas Meja
    glPushMatrix();
    glTranslatef(4.5f, 3.2f, 5.5f); // Pinggir, Atas, Depan
    glScalef(4.01f, 0.2f, 2.01f);
    glColor3f(0.6f, 0.3f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kanan Depan
    glPushMatrix();
    glTranslatef(2.6f, 1.85f, 6.4f);
    glScalef(0.2f, 2.5f, 0.2f);
    glColor3f(0.4f, 0.2f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Depan Kiri
    glPushMatrix();
    glTranslatef(6.4f, 1.85f, 6.4f);
    glScalef(0.2f, 2.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Belakang Kanan
    glPushMatrix();
    glTranslatef(2.6f, 1.85f, 4.6f);
    glScalef(0.2f, 2.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Belakang Kiri
    glPushMatrix();
    glTranslatef(6.4f, 1.85f, 4.6f);
    glScalef(0.2f, 2.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Kursi()
{
    // Alas Kursi
    glPushMatrix();
    glTranslatef(4.5f, 2.25f, 3.0f); // Pinggir, Atas, Depan
    glScalef(1.5f, 0.1f, 1.5f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Sandaran Kursi
    glPushMatrix();
    glTranslatef(4.5f, 3.55f, 2.35f);
    glScalef(1.5f, 0.75f, 0.3f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kanan Sandaran Kursi
    glPushMatrix();
    glTranslatef(3.85f, 2.75f, 2.35f);
    glScalef(0.2f, 0.90f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kiri Sandaran Kursi
    glPushMatrix();
    glTranslatef(5.15f, 2.75f, 2.35f);
    glScalef(0.2f, 0.90f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kanan Depan
    glPushMatrix();
    glTranslatef(3.85f, 1.4f, 3.65f);
    glScalef(0.2f, 1.65f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kiri Depan
    glPushMatrix();
    glTranslatef(5.15f, 1.4f, 3.65f);
    glScalef(0.2f, 1.65f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Kanan Belakang
    glPushMatrix();
    glTranslatef(3.85f, 1.4f, 2.35f);
    glScalef(0.2f, 1.65f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki Belakang Kiri
    glPushMatrix();
    glTranslatef(5.15f, 1.4f, 2.35f);
    glScalef(0.2f, 1.65f, 0.2f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Laptop()
{
    // Body Layar
    glPushMatrix();
    glTranslatef(4.5f, 3.90f, 5.901f); // Pinggir, Atas, Depan
    glScalef(1.5f, 1.0f, 0.1f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Layar LCD laptop
    glPushMatrix();
    glTranslatef(4.5f, 3.90f, 5.845f);
    glScalef(1.3f, 0.75f, 0.01f);
    glColor3f(0.0f, 1.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Body Bawah Laptop
    glPushMatrix();
    glTranslatef(4.5f, 3.35f, 5.5f);
    glScalef(1.5f, 0.1f, 0.9f);
    glColor3f(0.3f, 0.3f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Keyboard Laptop
    glPushMatrix();
    glTranslatef(4.5f, 3.28f, 5.57f);
    glScalef(1.2f, 0.25f, 0.4f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Touchpad Laptop
    glPushMatrix();
    glTranslatef(4.5f, 3.28f, 5.22f);
    glScalef(0.2f, 0.25f, 0.2f);
    glColor3ub(66, 66, 66);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawCartesius()
{
    glLineWidth(5.0);
    glPushMatrix();
    glTranslatef(12.5f, 5.25f, 9.5f);
    glBegin(GL_LINES);

    // Sumbu X (Merah)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-16.0, 0.0, 0.0);
    glVertex3f(16.0, 0.0, 0.0);

    // Sumbu Y (Hijau)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, -16.0, 0.0);
    glVertex3f(0.0, 16.0, 0.0);

    // Sumbu Z (Biru)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, -16.0);
    glVertex3f(0.0, 0.0, 16.0);

    glEnd();
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        ypos = ypos + 5;
        if (ypos > 360)
            ypos = 0;
        glutPostRedisplay();
        break;
    case 'e':
        ypos = ypos - 5;
        if (ypos > 360)
            ypos = 0;
        glutPostRedisplay();
        break;
    case 'f':
        b = b + 1;
        glutPostRedisplay();
        break;
    case 'r':
        b = b - 1;
        glutPostRedisplay();
        break;
    case 'a':
        a = a + 1;
        glutPostRedisplay();
        break;
    case 'd':
        a = a - 1;
        glutPostRedisplay();
        break;
    case 'w':
        c = c + 1;
        glutPostRedisplay();
        break;
    case 's':
        c = c - 1;
        glutPostRedisplay();
        break;
    case 'o':
        pintu = pintu - 5;
        if (pintu < -0)
            pintu = -0;
        glutPostRedisplay();
        break;
    case 'p':
        pintu = pintu + 5;
        if (pintu > 45)
            pintu = 0;
        glutPostRedisplay();
        break;
    case 'z':
        xpos = xpos + 5;
        if (xpos > 360)
            xpos = 0;
        glutPostRedisplay();
        break;
    case 'c':
        xpos = xpos - 5;
        if (xpos > 360)
            xpos = 0;
        glutPostRedisplay();
    case 'b':
        scale_factor += 0.1f;
        if (scale_factor > 5.0f)
            scale_factor = 5.0f;
        glutPostRedisplay();
        break;
    case 'k':
        scale_factor -= 0.1f;
        if (scale_factor < 0.1f)
            scale_factor = 0.1f;
        glutPostRedisplay();
        break;
    case 'h':
        hidden = !hidden;
        break;
    }
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    glTranslatef(a, b, c);
    glScalef(scale_factor, scale_factor, scale_factor);
    glRotatef(xpos, 1, 0, 0);
    glRotatef(ypos, 0, 1, 0);
    glRotatef(zpos, 0, 0, 1);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    // Meja  pertama
    glPushMatrix();
    glTranslatef(8.5f, 0.0f, 18.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    //  Kursi pertama
    glPushMatrix();
    glTranslatef(8.5f, 0.0f, 17.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja kedua
    glPushMatrix();
    glTranslatef(13.5f, 0.0f, 18.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    // kursi pertama
    glPushMatrix();
    glTranslatef(13.5f, 0.0f, 17.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja  ketiga
    glPushMatrix();
    glTranslatef(18.5f, 0.0f, 18.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();
    // Kursi ketiga
    glPushMatrix();
    glTranslatef(18.5f, 0.0f, 17.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja  keempat
    glPushMatrix();
    glTranslatef(23.5f, 0.0f, 18.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    // Kursi keempat
    glPushMatrix();
    glTranslatef(23.5f, 0.0f, 17.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja  pertama
    glPushMatrix();
    glTranslatef(8.5f, 0.0f, 22.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    //  Kursi pertama
    glPushMatrix();
    glTranslatef(8.5f, 0.0f, 21.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja 8
    glPushMatrix();
    glTranslatef(13.5f, 0.0f, 22.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    // kursi 8
    glPushMatrix();
    glTranslatef(13.5f, 0.0f, 21.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja  8
    glPushMatrix();
    glTranslatef(18.5f, 0.0f, 22.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    // Kursi 8
    glPushMatrix();
    glTranslatef(18.5f, 0.0f, 21.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    // Meja  8
    glPushMatrix();
    glTranslatef(23.5f, 0.0f, 22.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Meja();
    glPopMatrix();

    // Kursi 8
    glPushMatrix();
    glTranslatef(23.5f, 0.0f, 21.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    Kursi();
    glPopMatrix();

    Meja();
    Kursi();
    Laptop();
    Atap();
    Lantai();
    Dinding();
    Pintu();
    Saklar();
    PapanTulis();

    if (!hidden)
    {
        drawCartesius();
    }
    glFlush();
    glutSwapBuffers();
}
void initLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPos[] = {50.0f, 50.0f, 50.0f, 1.0f};
    GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightDiffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);
}

void mouseMotion(int x, int y)
{
    angleY += (x - lastX);
    angleX -= (y - lastY);
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 0.0);
    initLighting();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0 * (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Dimas x Wildan");

    init();
    glutDisplayFunc(display);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
