#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include "Objects.h"

OtherObjects::OtherObjects(float x, float y)
{
    x = x;
    y = y;
}

void OtherObjects::createStar()
{
    glScalef(s1,s2,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glVertex3f(0.037f+x, 0.0f+y, 0.0f);
        glVertex3f(0.037f+x, 0.0428f+y, 0.0f);
        glVertex3f(0.0f+x, 0.0428f+y, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f+x, 0.0428f+y, 0.0f);
        glVertex3f(0.0185f+x, 0.3f+y, 0.0f);
        glVertex3f(0.037f+x, 0.0428f+y, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glVertex3f(0.0185f+x, -0.27f+y, 0.0f);
        glVertex3f(0.037f+x, 0.0f+y, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glVertex3f(0.0f+x, 0.0428f+y, 0.0f);
        glVertex3f(-0.2f+x, 0.0214f+y, 0.0f);
	glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.037f+x, 0.0f+y, 0.0f);
        glVertex3f(0.037f+x, 0.0428f+y, 0.0f);
        glVertex3f(0.25f+x, 0.0214f+y, 0.0f);
	glEnd();
}
