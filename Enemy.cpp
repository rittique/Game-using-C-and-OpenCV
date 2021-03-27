#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include "Enemy.h"

void Enemy::CreateLevel_3_Boos()
{
    glTranslatef(moveBoss, 0.0f, 0.0f);
    glPushMatrix();
    glScalef(1.3,1.3,0);
    glPopMatrix();
    glColor3d(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.05f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
    glEnd();
    glColor3d(1,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.1f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
    glEnd();
    glColor3f(0.576,.286,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.075f, 0.025f, 0.0f);
        glVertex3f(-0.025f, -0.035f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.075f, 0.025f, 0.0f);
        glVertex3f(0.025f, -0.035f, 0.0f);
    glEnd();
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.075f, 0.025f, 0.0f);
        glVertex3f(-0.225f, -0.05f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.075f, 0.025f, 0.0f);
        glVertex3f(0.225f, -0.05f, 0.0f);
    glEnd();
    glColor3d(0,0,1);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.125f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.16f, -0.017f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.125f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.16f, -0.017f, 0.0f);
    glEnd();
    glColor3d(1,1,0);
    glBegin(GL_LINES);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.025f, -0.035f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.025f, -0.035f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.025f, -0.035f, 0.0f);
        glVertex3f(-0.1f, 0.075f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.025f, -0.035f, 0.0f);
        glVertex3f(0.1f, 0.075f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.1f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.025f, 0.025f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
    glEnd();
    glColor3d(1,0,1);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(-0.1f, 0.075f, 0.0f);
        glVertex3f(-0.225f, -0.05f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.075f, 0.025f, 0.0f);
        glVertex3f(-0.225f, -0.05f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.1f, 0.075f, 0.0f);
        glVertex3f(0.225f, -0.05f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.075f, 0.025f, 0.0f);
        glVertex3f(0.225f, -0.05f, 0.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f,-0.01f,0.0f);
    glColor3d(1,0,0);
    glutSolidSphere(0.015,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.075f,0.02f,0.0f);
    glColor3d(1,0,0);
    glutSolidSphere(0.01,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.075f,0.02f,0.0f);
    glutSolidSphere(0.01,50,50);
    glPopMatrix();
}

Enemy::Enemy(float x)
{
    random = x;
}
void Enemy::CreateLevel_1_Enemy()
{
    float yShift=0.1f;
    if(create)
    {
        random = -0.8 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.6)));
        create = false;
    }
    enemyX1 = random;
    enemyX2 = enemyX1+0.13;
    glTranslatef(0.0f, moveEnemy, 0.0f);
    glColor3d(0.0f, 0.2353f, 0.2353f);

    glColor3d(1,0,0);
    glPointSize(10);
    glBegin(GL_POLYGON);
        glVertex3f((enemyX1+enemyX2)/2, 0.85f-yShift, 0.0f);
        glVertex3f(enemyX1+0.028, 0.914f-yShift, 0.0f);
        glVertex3f(enemyX2-0.028, 0.914f-yShift, 0.0f);
    glEnd();

    glColor3d(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(enemyX1, 0.943f-yShift, 0.0f);
        glVertex3f(enemyX1+0.028, 0.914f-yShift, 0.0f);
        glVertex3f(enemyX2-0.028, 0.914f-yShift, 0.0f);
        glVertex3f(enemyX2, 0.943f-yShift, 0.0f);
    glEnd();
    glColor3d(1,0,1);
    glPointSize(10);
    glBegin(GL_POINTS);
        glVertex3f(enemyX1+0.04, 0.95f-yShift, 0.0f);
        glVertex3f(enemyX2-0.04, 0.95f-yShift, 0.0f);
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(enemyX1+0.04, 1.0f-yShift, 0.0f);
        glVertex3f(enemyX1+0.02, 0.97f-yShift, 0.0f);
        glVertex3f(enemyX1+0.06, 0.97f-yShift, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(enemyX2-0.04, 1.0f-yShift, 0.0f);
        glVertex3f(enemyX2-0.02, 0.97f-yShift, 0.0f);
        glVertex3f(enemyX2-0.06, 0.97f-yShift, 0.0f);
    glEnd();
}
void Enemy::CreateLevel_1_Boos()
{
    float yShift=0.1f;
    glTranslatef(moveBoss, 0.0f, 0.0f);
    glColor3d(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(bossX1, 0.943f-yShift, 0.0f);
        glVertex3f(bossX1+0.028, 0.914f-yShift, 0.0f);
        glVertex3f(bossX2-0.028, 0.914f-yShift, 0.0f);
        glVertex3f(bossX2, 0.943f-yShift, 0.0f);
    glEnd();
    glColor3d(1,0,1);
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(bossX1+0.04, 0.82f-yShift, 0.0f);
        glVertex3f(bossX1+0.04, 0.914f-yShift, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(bossX1+0.09, 0.82f-yShift, 0.0f);
        glVertex3f(bossX1+0.09, 0.914f-yShift, 0.0f);
    glEnd();
    glColor3d(0,1,0);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(bossX1+0.065, 0.85f-yShift, 0.0f);
        glVertex3f(bossX1+0.065, 0.914f-yShift, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(bossX1+0.028, 0.914f-yShift, 0.0f);
        glVertex3f(bossX2-0.028, 0.914f-yShift, 0.0f);
    glEnd();
    glLineWidth(10);
    glColor3d(.9,.9,0);
    glBegin(GL_LINES);
        glVertex3f(bossX1, 0.943f-yShift, 0.0f);
        glVertex3f(bossX2, 0.943f-yShift, 0.0f);
    glEnd();
    glLineWidth(10);
    glColor3d(.9,.2,.2);
    glBegin(GL_LINES);
        glVertex3f(bossX1+0.03, 1.0f-yShift, 0.0f);
        glVertex3f(bossX1+0.03, 0.943f-yShift, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(bossX2-0.03, 1.0f-yShift, 0.0f);
        glVertex3f(bossX2-0.03, 0.943f-yShift, 0.0f);
    glEnd();
    glColor3d(.392,.925,.914);
    glBegin(GL_POLYGON);
        glVertex3f(bossX1+0.03, 0.943f-yShift, 0.0f);
        glVertex3f(bossX2-0.03, 0.943f-yShift, 0.0f);
        glVertex3f((bossX1+bossX2)/2, 1.0f-yShift, 0.0f);
    glEnd();
    glPointSize(10);
    glColor3d(1,0,0);
    glBegin(GL_POINTS);
        glVertex3f(bossX1+0.065, 0.85f-yShift, 0.0f);
    glEnd();
}

void Enemy::CreateLevel_2_Boos()
{
    glTranslatef(moveBoss, 0.0f, 0.0f);

    glColor3d(0.8,0,0.2);
    glBegin(GL_POLYGON);
        glVertex3f(-0.15f, 0.0f, 0.0f);
        glVertex3f(0.15f, 0.0f, 0.0f);
        glVertex3f(0.0f, -0.025f, 0.0f);
    glEnd();
    glColor3d(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.15f, 0.0f, 0.0f);
        glVertex3f(0.0f, -0.025f, 0.0f);
        glVertex3f(-0.025f, -0.05f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.15f, 0.0f, 0.0f);
        glVertex3f(0.0f, -0.025f, 0.0f);
        glVertex3f(0.025f, -0.05f, 0.0f);
    glEnd();
    glColor3d(0.588,0.368,0.247);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.15f, 0.0f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-0.15f, 0.0f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
    glEnd();
    glColor3d(1,0,1);
    glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
        glVertex3f(0.0f, 0.1f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
    glEnd();
    glColor3d(0,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.15f, 0.025f, 0.0f);
        glVertex3f(-0.15f, 0.0f, 0.0f);
        glVertex3f(-0.025f, 0.025f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.15f, 0.025f, 0.0f);
        glVertex3f(-0.175f, 0.05f, 0.0f);
        glVertex3f(-0.27f, 0.05f, 0.0f);
        glVertex3f(-0.15f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.15f, 0.025f, 0.0f);
        glVertex3f(0.15f, 0.0f, 0.0f);
        glVertex3f(0.025f, 0.025f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.15f, 0.025f, 0.0f);
        glVertex3f(0.175f, 0.05f, 0.0f);
        glVertex3f(0.27f, 0.05f, 0.0f);
        glVertex3f(0.15f, 0.0f, 0.0f);
    glEnd();

    glColor3d(1,0,0);
    glPushMatrix();
    glTranslatef(0.0f,-0.05f,0.0f);
    glutSolidSphere(0.014,50,50);
    glPopMatrix();
}
void Enemy::CreateLevel_2_Enemy()
{
    glTranslatef(0.0f,moveEnemy, 0.0f);

    glColor3d(1,0,0);
    glPushMatrix();
    glTranslatef(0.0f,-0.035f,0.0f);
    glutSolidSphere(0.015,50,50);
    glPopMatrix();

    glColor3d(0,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(0.015f,-0.03f,0.0f);
        glVertex3f(0.025f, 0.05f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.015f,-0.03f,0.0f);
        glVertex3f(-0.025f, 0.05f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.015f,-0.03f,0.0f);
    glVertex3f(0.075f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.015f,-0.03f,0.0f);
    glVertex3f(-0.075f, 0.0f, 0.0f);
    glEnd();
    glColor3d(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0.025f, 0.05f, 0.0f);
        glVertex3f(0.075f, 0.0f, 0.0f);
        glVertex3f(0.1f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0.075f, 0.0f, 0.0f);
        glVertex3f(0.025f, -0.075f, 0.0f);
        glVertex3f(0.1f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.025f, 0.05f, 0.0f);
        glVertex3f(-0.075f, 0.0f, 0.0f);
        glVertex3f(-0.1f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.075f, 0.0f, 0.0f);
        glVertex3f(-0.025f, -0.075f, 0.0f);
        glVertex3f(-0.1f, 0.0f, 0.0f);
    glEnd();

}


