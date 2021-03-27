#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include "OtherScenes.h"
using namespace std;

void OtherScenes::gameIsOver()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if(isSoundOn)
    {
       sndPlaySound("gameOver.wav",SND_ASYNC|SND_LOOP);
       isSoundOn = false;
    }
    //E
    glColor3d(1,0,0);
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(0.0-.04f, 0.0f, 0.0f);
        glVertex3f(-0.125-.04f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125-.04f, 0.248f, 0.0f);
        glVertex3f(-0.125-.04f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125-.04f, 0.248f, 0.0f);
        glVertex3f(0.0-.04f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125-.04f, 0.124f, 0.0f);
        glVertex3f(0.002-.04f, 0.124f, 0.0f);
    glEnd();

    //M
    glBegin(GL_LINES);
        glVertex3f(-0.375f, 0.248f, 0.0f);
        glVertex3f(-0.375f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.25f, 0.248f, 0.0f);
        glVertex3f(-0.25f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.3125f, 0.124f, 0.0f);
        glVertex3f(-0.25f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.3125f, 0.124f, 0.0f);
        glVertex3f(-0.375f, 0.248f, 0.0f);
    glEnd();

    //A
    glBegin(GL_LINES);
        glVertex3f(-0.4375f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.5625f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.475f, 0.124f, 0.0f);
        glVertex3f(-0.53f, 0.124f, 0.0f);
    glEnd();

    //G
    glBegin(GL_LINES);
        glVertex3f(-0.825+.06f, 0.248f, 0.0f);
        glVertex3f(-0.6875+.06f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.825+.06f, 0.248f, 0.0f);
        glVertex3f(-0.825+.06f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.75+.06f, 0.0f, 0.0f);
        glVertex3f(-0.825+.06f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.75+.06f, 0.0f, 0.0f);
        glVertex3f(-0.75+.06f, 0.085f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.68+.06f, 0.085f, 0.0f);
        glVertex3f(-0.75+.06f, 0.085f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.68+.06f, 0.085f, 0.0f);
        glVertex3f(-0.68+.06f, 0.0f, 0.0f);
    glEnd();

    //O
    glBegin(GL_LINES);
        glVertex3f(0.125+.04f, 0.0f, 0.0f);
        glVertex3f(0.125+.04f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.25+.04f, 0.248f, 0.0f);
        glVertex3f(0.125+.04f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.25+.04f, 0.248f, 0.0f);
        glVertex3f(0.25+.04f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.125+.04f, 0.0f, 0.0f);
        glVertex3f(0.25+.04f, 0.0f, 0.0f);
    glEnd();

    //V
    glBegin(GL_LINES);
        glVertex3f(0.4375f, 0.0f, 0.0f);
        glVertex3f(0.35f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.4375f, 0.0f, 0.0f);
        glVertex3f(0.525f, 0.248f, 0.0f);
    glEnd();

    //E 2nd
    glBegin(GL_LINES);
        glVertex3f(0.0+.7f, 0.0f, 0.0f);
        glVertex3f(-0.125+.7f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125+.7f, 0.248f, 0.0f);
        glVertex3f(-0.125+.7f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125+.7f, 0.248f, 0.0f);
        glVertex3f(0.0+.7f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.125+.7f, 0.124f, 0.0f);
        glVertex3f(0.002+.7f, 0.124f, 0.0f);
    glEnd();

    //R
    glBegin(GL_LINES);
        glVertex3f(0.78f, 0.0f, 0.0f);
        glVertex3f(0.78f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.9f, 0.248f, 0.0f);
        glVertex3f(0.78f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.9f, 0.248f, 0.0f);
        glVertex3f(0.9f, 0.124f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.78f, 0.124f, 0.0f);
        glVertex3f(0.9f, 0.124f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.78f, 0.124f, 0.0f);
        glVertex3f(0.93f, 0.0f, 0.0f);
    glEnd();

}
void OtherScenes::victory()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
    if(isSoundOn)
    {
       sndPlaySound("victory.wav",SND_ASYNC|SND_LOOP);
       isSoundOn = false;
    }

    glColor3d(0,1,0);
    glLineWidth(10);

    //T
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.248f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.15f, 0.248f, 0.0f);
        glVertex3f(-0.15f, 0.248f, 0.0f);
    glEnd();

    //C
    glBegin(GL_LINES);
        glVertex3f(-0.2f, 0.0f, 0.0f);
        glVertex3f(-0.387f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.387f, 0.248f, 0.0f);
        glVertex3f(-0.387f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.387f, 0.248f, 0.0f);
        glVertex3f(-0.2f, 0.248f, 0.0f);
    glEnd();

    //I
    glBegin(GL_LINES);
        glVertex3f(-0.5375f, 0.0f, 0.0f);
        glVertex3f(-0.5375f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.475f, 0.0f, 0.0f);
        glVertex3f(-0.6f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.475f, 0.248f, 0.0f);
        glVertex3f(-0.6f, 0.248f, 0.0f);
    glEnd();

    //V
    glBegin(GL_LINES);
        glVertex3f(-0.8f, 0.0f, 0.0f);
        glVertex3f(-0.7f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.8f, 0.0f, 0.0f);
        glVertex3f(-0.9f, 0.248f, 0.0f);
    glEnd();

    //O
    glBegin(GL_LINES);
        glVertex3f(0.125+.12f, 0.0f, 0.0f);
        glVertex3f(0.125+.12f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.25+.12f, 0.248f, 0.0f);
        glVertex3f(0.125+.12f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.25+.12f, 0.248f, 0.0f);
        glVertex3f(0.25+.12f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.125+.12f, 0.0f, 0.0f);
        glVertex3f(0.25+.12f, 0.0f, 0.0f);
    glEnd();

    //R
    glBegin(GL_LINES);
        glVertex3f(0.78-.29f, 0.0f, 0.0f);
        glVertex3f(0.78-.29f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.9-.29f, 0.248f, 0.0f);
        glVertex3f(0.78-.29f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.9-.29f, 0.248f, 0.0f);
        glVertex3f(0.9-.29f, 0.124f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.78-.29f, 0.124f, 0.0f);
        glVertex3f(0.9-.29f, 0.124f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.78-.29f, 0.124f, 0.0f);
        glVertex3f(0.93-.29f, 0.0f, 0.0f);
    glEnd();

    //Y
    glBegin(GL_LINES);
        glVertex3f(0.75f, 0.0f, 0.0f);
        glVertex3f(0.9f, 0.248f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.82f, 0.124f, 0.0f);
        glVertex3f(0.7f, 0.248f, 0.0f);
    glEnd();
}
