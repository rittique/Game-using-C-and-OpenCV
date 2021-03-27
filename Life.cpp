#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include "Life.h"

void Life::drawTextBox()
{
    glColor3d(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.8f-0.07, 1.0f, 0.0f);
        glVertex3f(0.8f-0.07, 0.9f, 0.0f);
        glVertex3f(0.8f-1.55, 0.9f, 0.0f);
        glVertex3f(0.8f-1.55, 1.0f, 0.0f);
    glEnd();
}

void Life::lifeBox()
{
    glColor3d(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.9f, 1.0f, 0.0f);
        glVertex3f(0.99f, 1.0f, 0.0f);
        glVertex3f(0.99f, 0.9f, 0.0f);
        glVertex3f(0.9f, 0.9f, 0.0f);
    glEnd();
    glColor3d(0,0,1);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(0.9+0.027f, 0.98f, 0.0f);
        glVertex3f(0.9+0.027f, 0.91f, 0.0f);
    glEnd();
    glPointSize(13);
    glBegin(GL_POINTS);
        glVertex3f(0.9+0.038f, 0.98f-.017, 0.0f);
    glEnd();
}
void Life::bossLifeBox()
{
    glColor3d(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.9-1.89f, 1.0f, 0.0f);
        glVertex3f(0.99-1.89f, 1.0f, 0.0f);
        glVertex3f(0.99-1.89f, 0.9f, 0.0f);
        glVertex3f(0.9-1.89f, 0.9f, 0.0f);
    glEnd();

    glColor3d(1,0,0);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(0.9-1.86f, 0.98f, 0.0f);
        glVertex3f(0.9-1.86f, 0.91f, 0.0f);
    glEnd();
    glPointSize(11);
    glBegin(GL_POINTS);
        glVertex3f(0.9-1.85f, 0.98f-.017, 0.0f);
        glVertex3f(0.9-1.85f, 0.91f+.017, 0.0f);
    glEnd();

}
void Life::drawLife(float x, float y)
{
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.96f-x, 0.714f-y, 0.0f);
        glVertex3f(0.995f-x, 0.77f-y, 0.0f);
        glVertex3f(0.92f-x, 0.77f-y, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.94f-x, 0.8f-y, 0.0f);
        glVertex3f(0.96f-x, 0.77f-y, 0.0f);
        glVertex3f(0.92f-x, 0.77f-y, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.9775f-x, 0.8f-y, 0.0f);
        glVertex3f(0.96f-x, 0.77f-y, 0.0f);
        glVertex3f(0.995f-x, 0.77f-y, 0.0f);
    glEnd();
}

void Life::createLife()
{
    glTranslatef(0.0f,moveLife,0.0f);
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.0625f, 0.0f, 0.0f);
        glVertex3f(-0.0625f, 0.0f, 0.0f);
        glVertex3f(0.0f, -0.085f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.03125f, 0.05f, 0.0f);
        glVertex3f(0.0625f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.03125f, 0.05f, 0.0f);
        glVertex3f(-0.0625f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}
