#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include<mmsystem.h>
#include "Enemy.h"
#include "OtherScenes.h"
#include "Life.h"
//#include "OtherObjects.h"
using namespace std;

char path[] = "G:\\study\\Graphics\\Final Project\\TopScore.txt";

int point=0;
int life=5;
int enemyCounter =0;
int lifeCounter=0;
int bossLaserCounter = 0;
float moveShip = 0.0f;
float moveShipNextLevel = 0.0f;
float shipHead = 0.0f;
float random=0.0f;
float randomEnemy1 = 0.0f;
float randomEnemy2 = 0.0f;
float randomEnemy3 = 0.0f;
float nextMove = 0.0f;
float manuSelector = 0.3f;
float boss1Falling = 0.0f;
float boss2Falling = 0.8f;
bool isLaser = false;
bool isBoss1 = false;
bool isBoss2 = false;
bool turnLeft = true;
bool isWin = false;
bool isCreateLife = false;
bool isGenerateRandomLife = true;
bool isGenerateEnemy1 = true;
bool isGenerateEnemy2 = true;
bool isGenerateEnemy3 = true;
bool stop = false;
bool isLevel1 = true;
bool isLevel2 = false;
bool isLevel3 = false;
bool isNewGame = false;
bool isExit = false;
bool isPause = false;
bool isBoss1Die = true;
bool isBoss2Die = true;
bool isDataSave = true;
bool isScoreOpen = false;
char scoreText[] = "Score : ";
char enemyCounterText[] = "Enemy Counter : ";
char newGameText[] = " Start New Game";
char highestScoreText[] = "Highest Score";
char exitText[] = "Exit";
char gameName[] = "Space Shooter Game";
char developedBy[] = "developed by -";
char myName[] = "MD.SABIR IBNA SAZZAD";
char date[] = "April 2018";
char resume[] = "Resume Game";
char score1[] = "Score 1 : ";
char score2[] = "Score 2 : ";
char score3[] = "Score 3 : ";
char score4[] = "Score 4 : ";
char score5[] = "Score 5 : ";
char enemyCounterString[3];
char pointString[5];
char score1Value[5];
char score2Value[5];
char score3Value[5];
char score4Value[5];
char score5Value[5];

Enemy e(0.0),e2(-0.5),e3(0.7);
Enemy eL2(0.0),e2L2(-0.5),e3L2(0.7);
Enemy boss(0.0),boss2(0.0),boss3(0.0);
OtherScenes g;
Life l;
//OtherObjects o,o1,o2;

//Print
void Sprint( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,1.0,0.7);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}
void Sprint2( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,1.0,0.7);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
}
void Sprint3( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,1.0,0.7);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, st[i]);
    }
}
void getScore()
{
    string line;
    int x=0,i=0;
    int arr[5] = {0};

    ifstream readFile (path);
    if (readFile.is_open())
    {
        while ( getline (readFile,line) )
        {
          stringstream geek(line);
          geek >> x;
          arr[i] = x;
          i++;
        }
        readFile.close();
    }
    itoa(arr[0],score1Value, 10);
    itoa(arr[1],score2Value, 10);
    itoa(arr[2],score3Value, 10);
    itoa(arr[3],score4Value, 10);
    itoa(arr[4],score5Value, 10);
}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 32:
            isLaser = true;
            Beep(900,50);
            break;
        case 113:
            boss.isBossLaser = true;
            break;
        case 13:
        if(manuSelector== 0.3f)
            {
                isNewGame = true;
                isPause = false;
            }
            else if(manuSelector == 0.16f)
            {
                isScoreOpen = true;
                getScore();
            }
            else if(manuSelector == 0)
            {
                glutDestroyWindow(1);
                exit (0);
            }
            break;
        case 27:
        case 'p':
            isNewGame = false;
            isPause = true;
            isScoreOpen = false;
            break;

    }

    glutPostRedisplay();
}
static void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
            moveShip += .06;
            if(moveShip > 1.0)
            {
                moveShip = -1.0;
            }
            glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
            moveShip -= .06;
            if(moveShip < -1.0)
            {
                moveShip = 1.0;
            }
            glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        if(manuSelector == 0.16f)
        {
            manuSelector = 0.3f;
        }
        else if(manuSelector == 0.3f)
        {
            manuSelector = 0;
        }
        else if(manuSelector == 0)
        {
            manuSelector = 0.16f;
        }
        break;

    case GLUT_KEY_DOWN:
        if(manuSelector == 0.16f)
        {
            manuSelector = 0;
        }
        else if(manuSelector == 0.3f)
        {
            manuSelector = 0.16f;
        }
        else if(manuSelector == 0)
        {
            manuSelector = 0.3f;
        }
        break;
    }

}
void drawMyShip()
{
    glPushMatrix();
    glTranslatef(moveShip,moveShipNextLevel,0.0f);
    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(shipHead, -0.514f, 0.0f);
        glVertex3f(-.05, -0.65f, 0.0f);
        glVertex3f(.05f, -0.65f, 0.0f);
    glEnd();
        glColor3d(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-.05, -0.65f, 0.0f);
        glVertex3f(-.08, -0.68f, 0.0f);
        glVertex3f(.08f, -0.68f, 0.0f);
        glVertex3f(.05f, -0.65f, 0.0f);
    glEnd();
        glColor3d(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(-.08, -0.68f, 0.0f);
        glVertex3f(-.08f, -0.71f, 0.0f);
        glVertex3f(.08f, -0.71f, 0.0f);
        glVertex3f(.08f, -0.68f, 0.0f);
    glEnd();
        glColor3d(0,0.54,0.585);
    glBegin(GL_POLYGON);
        glVertex3f(-.07f, -0.71f, 0.0f);
        glVertex3f(-.07, -0.73f, 0.0f);
        glVertex3f(-.03f, -0.73f, 0.0f);
        glVertex3f(-.03f, -0.71f, 0.0f);
    glEnd();
        glColor3d(0,0.54,0.585);
    glBegin(GL_POLYGON);
        glVertex3f(.07f, -0.71f, 0.0f);
        glVertex3f(.07f, -0.73f, 0.0f);
        glVertex3f(.03f, -0.73f, 0.0f);
        glVertex3f(.03f, -0.71f, 0.0f);
    glEnd();
        glColor3d(0.88,0.72,0.3);
    glBegin(GL_POLYGON);
        glVertex3f(.05f, -0.8f, 0.0f);
        glVertex3f(.07f, -0.73f, 0.0f);
        glVertex3f(.03f, -0.73f, 0.0f);
    glEnd();
        glColor3d(0.88,0.72,0.3);
    glBegin(GL_POLYGON);
        glVertex3f(-.05f, -0.8f, 0.0f);
        glVertex3f(-.07f, -0.73f, 0.0f);
        glVertex3f(-.03f, -0.73f, 0.0f);
    glEnd();
        glColor3d(0.54,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.01f, -0.58f, 0.0f);
        glVertex3f(-0.01f, -0.64f, 0.0f);
        glVertex3f(0.01f, -0.64f, 0.0f);
        glVertex3f(0.01f, -0.58f, 0.0f);
    glEnd();
//laser
    if(isLaser)
    {
        glColor3d(1,1,0);
        glLineWidth(5);
        glBegin(GL_LINES);
            glVertex3f(shipHead,-0.514f, 0.0f);
            glVertex3f(shipHead, 0.75f, 0.0f);
        glEnd();
    }
    glPopMatrix();
}

void printText()
{
    glPushMatrix();
    itoa(point, pointString, 10);
    itoa(enemyCounter, enemyCounterString, 10);
    l.drawTextBox();
    glColor3f(1.0,0.0,0.0);
    Sprint(-0.7,0.94,scoreText);
    Sprint(-0.5,0.94,pointString);
    Sprint(0.0,0.94,enemyCounterText);
    Sprint(0.4,0.94,enemyCounterString);
    glPopMatrix();
}

void level_1_BossLifeControl()
{
    l.bossLifeBox();
    if(boss.boosLife==5)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);      // draw boss life with life class
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
        l.drawLife(1.9,0.36);
    }
    else if(boss.boosLife==4)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
    }
    else if(boss.boosLife==3)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
    }
    else if(boss.boosLife==2)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
    }
    else if(boss.boosLife==1)
    {
        l.drawLife(1.9,0.0);
    }
}

void level_2_BossLifeControl()
{
    l.bossLifeBox();
    if(boss2.boosLife==5)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);      // draw boss life with life class
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
        l.drawLife(1.9,0.36);
    }
    else if(boss2.boosLife==4)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
    }
    else if(boss2.boosLife==3)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
    }
    else if(boss2.boosLife==2)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
    }
    else if(boss2.boosLife==1)
    {
        l.drawLife(1.9,0.0);
    }
}
void level_3_BossLifeControl()
{
    l.bossLifeBox();
    if(boss3.boosLife==5)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);      // draw boss life with life class
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
        l.drawLife(1.9,0.36);
    }
    else if(boss3.boosLife==4)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
        l.drawLife(1.9,0.27);
    }
    else if(boss3.boosLife==3)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
        l.drawLife(1.9,0.18);
    }
    else if(boss3.boosLife==2)
    {
        l.drawLife(1.9,0.0);
        l.drawLife(1.9,0.09);
    }
    else if(boss3.boosLife==1)
    {
        l.drawLife(1.9,0.0);
    }
}

void shipLifeControl()
{
    l.lifeBox();
    if(life==5)
    {
        l.drawLife(0,0.0);
        l.drawLife(0,0.09);
        l.drawLife(0,0.18);
        l.drawLife(0,0.27);
        l.drawLife(0,0.36);
    }
    else if(life==4)
    {
        l.drawLife(0,0.0);
        l.drawLife(0,0.09);
        l.drawLife(0,0.18);
        l.drawLife(0,0.27);
    }
    else if(life==3)
    {
        l.drawLife(0,0.0);
        l.drawLife(0,0.09);
        l.drawLife(0,0.18);
    }
    else if(life==2)
    {
        l.drawLife(0,0.0);
        l.drawLife(0,0.09);
    }
    else if(life==1)
    {
        l.drawLife(0,0.0);
    }
}

void killLavel_1_Enemy()
{
    if(moveShip>=e.enemyX1 && moveShip<=e.enemyX2)
    {
        e.moveEnemy = 0.01;
        e.create = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
    if(moveShip>=e2.enemyX1 && moveShip<=e2.enemyX2)
    {
        e2.moveEnemy = 0.01;
        e2.create = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
    if(moveShip>=e3.enemyX1 && moveShip<=e3.enemyX2)
    {
        e3.moveEnemy = 0.01;
        e3.create = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
}

void createLevel_1_Enemy()
{
    glPushMatrix();
    e.CreateLevel_1_Enemy();
    glPopMatrix();

    glPushMatrix();
    e2.CreateLevel_1_Enemy();
    glPopMatrix();

    glPushMatrix();
    e3.CreateLevel_1_Enemy();
    glPopMatrix();
}

void applyLevel_1_BossLogic()
{
    if(boss.boosLife<=0)
    {
        if(isBoss1Die)
        {
            glPushMatrix();
            glTranslatef(0.0f,boss1Falling,0.0f);
            boss.CreateLevel_1_Boos();
            glPopMatrix();
        }
        else
        {
            isLevel1 = false;
            isLevel2 = true;
            isBoss1 = false;
            eL2.moveEnemy = 0.01;
            e2L2.moveEnemy = 0.01;
            e3L2.moveEnemy = 0.01;
        }
    }
    else
    {
        glPushMatrix();
        boss.CreateLevel_1_Boos();
        if(boss.isBossLaser)
        {
            glColor3d(1,0,0);
            glLineWidth(5);
            glBegin(GL_LINES);
                glVertex3f(boss.bossHead,0.85f, 0.0f);
                glVertex3f(boss.bossHead, -1.0f, 0.0f);
            glEnd();
        }
        glPopMatrix();

        // space ship laser logic to kill boss
        if(isLaser)
        {
            if((shipHead+moveShip)>=(boss.bossX1+boss.moveBoss) && (shipHead+moveShip)<=(boss.bossX2+boss.moveBoss))
            {
                boss.boosLife--;
                point = point + 20;
            }
        }
        //boss laser logic to kill Space ship
        if(boss.isBossLaser)
        {
            if((-.08f+moveShip)<=(boss.bossHead+boss.moveBoss) && (.08f+moveShip)>=(boss.bossHead+boss.moveBoss))
            {
                life--;
            }
        }
        //Boss life control
        level_1_BossLifeControl();
        boss.isBossLaser = false;
    }

}

void drawStar()
{
    glPushMatrix();
    glTranslatef(0.2f,-0.2f,0.0f);
//    o.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.6f,0.0f);
//    o2.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,0.5f,0.0f);
//    o2.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f,-0.8f,0.0f);
//    o.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7f,0.7f,0.0f);
//    o1.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,-0.6f,0.0f);
//    o2.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.9f,-0.2f,0.0f);
//    o2.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f,0.2f,0.0f);
//    o1.createStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f,0.3f,0.0f);
//    o1.createStar();
    glPopMatrix();
}

void createComet()
{
    glPushMatrix();
    glTranslatef(-0.8,-0.8,0);
//    o.createComet();
    glPopMatrix();
}

void createLife()
{
    if(isCreateLife)
    {
        if(isGenerateRandomLife)
        {
            random = -0.8 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.6)));
            isGenerateRandomLife = false;
        }

        glPushMatrix();
        glTranslatef(random,0.9f,0.0f);
        l.createLife();
        glPopMatrix();
    }
    if(isCreateLife && isLaser)
    {
        if(moveShip>=random - l.lifeX1 && moveShip<=random + l.lifeX1)
        {
            l.moveLife = 0.0f;
            isCreateLife = false;
            isGenerateRandomLife = true;
            if(life<5)
            {
                life++;
            }
        }
    }
}

void createLevel_2_Enemy()
{
    if(isGenerateEnemy1)
    {
        randomEnemy1 = -0.8 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.6)));
        isGenerateEnemy1 = false;
    }
    if(isGenerateEnemy2)
    {
        randomEnemy2 = -0.8 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.6)));
        isGenerateEnemy2 = false;
    }
    if(isGenerateEnemy3)
    {
        randomEnemy3 = -0.8 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.6)));
        isGenerateEnemy3 = false;
    }

    glPushMatrix();
    glTranslatef(randomEnemy1,0.85,0);
    eL2.CreateLevel_2_Enemy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(randomEnemy2,0.85,0);
    e2L2.CreateLevel_2_Enemy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(randomEnemy3,0.85,0);
    e3L2.CreateLevel_2_Enemy();
    glPopMatrix();
}

void killLavel_2_Enemy()
{
    if(moveShip>=randomEnemy1-0.1 && moveShip<=randomEnemy1+0.1)
    {
        eL2.moveEnemy = 0.01;
        isGenerateEnemy1 = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
    if(moveShip>=randomEnemy2-0.1 && moveShip<=randomEnemy2+0.1)
    {
        e2L2.moveEnemy = 0.01;
        isGenerateEnemy2 = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
    if(moveShip>=randomEnemy3-0.1 && moveShip<=randomEnemy3+0.1)
    {
        e3L2.moveEnemy = 0.01;
        isGenerateEnemy3 = true;
        point = point + 10;
        enemyCounter++;
        lifeCounter++;
    }
}

void applyLevel_2_BossLogic()
{
    if(boss2.boosLife<=0)
    {
        if(isBoss2Die)
        {
            glPushMatrix();
            glTranslatef(0.0f,boss2Falling,0.0f);
            boss2.CreateLevel_2_Boos();
            glPopMatrix();
        }
        else
        {
            isLevel2 = false;
            isLevel3 = true;
            isBoss2 = false;
        }
    }
    else
    {
        glPushMatrix();
        glTranslatef(0.0f,0.83f,0.0f);
        boss2.CreateLevel_2_Boos();
        if(boss2.isBossLaser)
        {
            glColor3d(1,0,0);
            glLineWidth(5);
            glBegin(GL_LINES);
                glVertex3f(0.0,0.0f, 0.0f);
                glVertex3f(0.0, -1.6f, 0.0f);
            glEnd();
        }
        glPopMatrix();

        // space ship laser logic to kill boss
        if(isLaser)
        {
            if((shipHead+moveShip)>=(-0.15+boss2.moveBoss) && (shipHead+moveShip)<=(0.15+boss2.moveBoss))
            {
                boss2.boosLife--;
                point = point + 20;
            }
        }
        //boss laser logic to kill Space ship
        if(boss2.isBossLaser)
        {
            if((-.08f+moveShip)<=(boss2.bossHead+boss2.moveBoss) && (.08f+moveShip)>=(boss2.bossHead+boss2.moveBoss))
            {
                life--;
            }
        }
        //Boss life control
        level_2_BossLifeControl();
        boss2.isBossLaser = false;
    }
}

void drawStartManu()
{
    glPushMatrix();
    if(isScoreOpen)
    {
        Sprint(-.2,0.4,score1);
        Sprint(-.2,0.3,score2);
        Sprint(-.2,0.2,score3);
        Sprint(-.2,0.1,score4);
        Sprint(-.2,0.0,score5);
        Sprint(0.05,0.4,score1Value);
        Sprint(0.05,0.3,score2Value);
        Sprint(0.05,0.2,score3Value);
        Sprint(0.05,0.1,score4Value);
        Sprint(0.05,0.0,score5Value);
    }
    else
    {
        if(isPause)
        {
            Sprint2(-.15,.3,resume);
        }
        else
        {
            Sprint2(-.2,.3,newGameText);
        }
        Sprint2(-.145,.16,highestScoreText);
        Sprint2(-.03,0,exitText);
    }
    Sprint2(-.23,.6,gameName);
    Sprint3(0.7,-0.85,developedBy);
    Sprint3(0.63,-0.9,myName);
    Sprint3(0.72,-0.95,date);
    drawStar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.85f,0);
    e.CreateLevel_3_Boos();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.7,0.3f,0);
    e.CreateLevel_2_Enemy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.7,0.3f,0);
    e.CreateLevel_2_Enemy();
    glPopMatrix();

    drawMyShip();

    glColor3d(.2,.8,.1);
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex3f(-0.45, -0.2f, 0.0f);
        glVertex3f(0.5, -0.2f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.45, -0.2f, 0.0f);
        glVertex3f(-0.45, 0.7f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.45, 0.7f, 0.0f);
        glVertex3f(0.5, 0.7f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.5, 0.7f, 0.0f);
        glVertex3f(0.5, -0.2f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.45, 0.5f, 0.0f);
        glVertex3f(0.5, 0.5f, 0.0f);
    glEnd();
    if(!isScoreOpen)
    {
        glPushMatrix();
        glTranslatef(0,manuSelector,0);
        glColor3d(1,1,0);
        glLineWidth(4);
        glBegin(GL_LINES);
            glVertex3f(-0.25, -0.03f, 0.0f);
            glVertex3f(0.3, -0.03f, 0.0f);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(-0.25, -0.03f, 0.0f);
            glVertex3f(-0.25, 0.07f, 0.0f);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(0.3, 0.07f, 0.0f);
            glVertex3f(-0.25, 0.07f, 0.0f);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(0.3, 0.07f, 0.0f);
            glVertex3f(0.3, -0.03f, 0.0f);
        glEnd();
        glPopMatrix();
    }
    isLaser = false;
}
void printFinishingScore()
{
    glPushMatrix();
    itoa(point, pointString, 10);
    Sprint2(-0.2,-0.3,scoreText);
    Sprint2(0,-0.3,pointString);
    glPopMatrix();
    glutSwapBuffers();
}
void applyLevel_3_BossLogic()
{
    glPushMatrix();
    glTranslatef(0.0f,0.83f,0.0f);
    boss3.CreateLevel_3_Boos();
    if(boss3.isBossLaser)
    {
        glColor3d(1,0,0);
        glLineWidth(5);
        glBegin(GL_LINES);
            glVertex3f(-0.075f,0.02f, 0.0f);
            glVertex3f(-0.075f, -1.6f, 0.0f);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(0.075f,0.02f, 0.0f);
            glVertex3f(0.075, -1.6f, 0.0f);
        glEnd();
    }
    glPopMatrix();

    // space ship laser logic to kill boss
    if(isLaser)
    {
        if((shipHead+moveShip)>=(-0.05+boss3.moveBoss) && (shipHead+moveShip)<=(0.05+boss3.moveBoss))
        {
            boss3.boosLife--;
            point = point + 20;
        }
    }
    //boss laser logic to kill Space ship
    if(boss3.isBossLaser)
    {
        if((-.08f+moveShip)<=(-0.075+boss3.moveBoss) && (.08f+moveShip)>=(-0.075+boss3.moveBoss))
        {
            life--;
        }
        else if((-.08f+moveShip)<=(0.075+boss3.moveBoss) && (.08f+moveShip)>=(0.075+boss3.moveBoss))
        {
            life--;
        }
    }
    //Boss life control
    level_3_BossLifeControl();
    boss3.isBossLaser = false;
}

void saveScore()
{
    string line;
    int x=0,i=0;
    int arr[6] = {0};

    ifstream readFile (path);
    if (readFile.is_open())
    {
        while ( getline (readFile,line) )
        {
          stringstream geek(line);
          geek >> x;
          arr[i] = x;
          i++;
        }
    }
    arr[5] = point;
    sort(arr,arr+6);
    ofstream writeFile ("G:\\study\\Graphics\\Final Project\\TopScore.txt");
    if (writeFile.is_open())
    {
        for(i=5;i>0;i--)
        {
            writeFile << arr[i] << "\n";
        }
        writeFile.close();
    }
    isDataSave = false;
}
///////////////////////////base function /////////////////////////////////
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

    if(!isNewGame)
    {
        drawStartManu();
        glutSwapBuffers();
    }
    else if(boss3.boosLife<=0)
    {
        if (stop)
        {
            glClearColor(0.2, 0.0f, 0.4f, 1.0f );
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if(isDataSave)
            {
                saveScore();
            }
            g.victory();
            printFinishingScore();
        }
        else
        {
            isLaser = false;
            drawMyShip();
            glutSwapBuffers();
        }
    }
	else if(life<=0)
	{
	    //glClearColor(.874f, .843f, .235f, 1.0f );
	    glClearColor(0.2, 0.0f, 0.4f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(isDataSave)
        {
            saveScore();
        }
	    g.gameIsOver();
        printFinishingScore();
	}
    else
    {
        createLife();
        createComet();
        drawStar();
        printText(); //counters
        drawMyShip();

        //Enemy part
        if(isLevel1)
        {
            if(isBoss1)
            {
                applyLevel_1_BossLogic();
            }
            //if not boss, only enemy
            else
            {
                createLevel_1_Enemy();
                if(isLaser)
                {
                    killLavel_1_Enemy();
                }
                //after a specific amount of killing enemy boss will come
                if(enemyCounter>=15)
                {
                    isBoss1 = true;
                }
            }
        }
        else if(isLevel2)
        {
            if(isBoss2)
            {
                applyLevel_2_BossLogic();
            }
            else
            {
                createLevel_2_Enemy();
                if(isLaser)
                {
                    killLavel_2_Enemy();
                }
                //after a specific amount of killing enemy boss will come
                if(enemyCounter>=25)
                {
                    isBoss2 = true;
                }
            }
        }
        else if(isLevel3)
        {
            applyLevel_3_BossLogic();
        }

        //**********//

        if(enemyCounter != 0 && lifeCounter >= 10)
        {
            isCreateLife = true;
            lifeCounter = 0;
        }
        shipLifeControl();
        Sleep(50);
        isLaser = false;
        glutSwapBuffers();
    }
}

// set different timer for different enemy
void updateLevel_1_EnemySet1(int value) {

    if(!isBoss1 && isLevel1 && isNewGame)
    {
        e.moveEnemy -= .02f;
        if(e.moveEnemy < -1.35)
        {
            life--;
            e.moveEnemy = 0.01;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(70, updateLevel_1_EnemySet1, 0);
}
void updateLevel_1_EnemySet2(int value) {

    if(!isBoss1 && isLevel1 && isNewGame)
    {
        e2.moveEnemy -= .02f;
        e3.moveEnemy -= .02f;
        if(e2.moveEnemy < -1.35)
        {
            life--;
            e2.moveEnemy = 0.01;
        }
        if(e3.moveEnemy < -1.35)
        {
            life--;
            e3.moveEnemy = 0.01;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(120, updateLevel_1_EnemySet2, 0);
}

void updateLife(int value) {

    if(isCreateLife && isNewGame)
    {
        l.moveLife -= .02f;
        if(l.moveLife < -1.35)
        {
            if(moveShip>=random- l.lifeX1 && moveShip<=random + l.lifeX1)
            {
                if(life<5)
                {
                    life++;
                }
            }
            l.moveLife = 0.0f;
            isCreateLife = false;
            isGenerateRandomLife = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateLife, 0);
}

void updateToNext(int x)
{
    if(boss3.boosLife<=0 && !stop && isNewGame)
    {
        moveShipNextLevel +=0.02;
        if(moveShipNextLevel >= 2)
        {
            moveShipNextLevel = 0;
            stop = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateToNext, 0);
}

void updateLevel_2_EnemySet1(int value) {

    if(isLevel2 && !isBoss2 && isNewGame)
    {
        eL2.moveEnemy -= .02f;
        if(eL2.moveEnemy < -1.35)
        {
            life--;
            eL2.moveEnemy = 0.01;
            isGenerateEnemy1 = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateLevel_2_EnemySet1, 0);

}

void updateLevel_2_EnemySet2(int value) {

    if(isLevel2 && !isBoss2 && isNewGame)
    {
        e2L2.moveEnemy -= .02f;
        if(e2L2.moveEnemy < -1.35)
        {
            life--;
            e2L2.moveEnemy = 0.01;
            isGenerateEnemy2 = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(70, updateLevel_2_EnemySet2, 0);
}

void updateLevel_2_EnemySet3(int value) {

    if(isLevel2 && !isBoss2 && isNewGame)
    {
        e3L2.moveEnemy -= .02f;
        if(e3L2.moveEnemy < -1.35)
        {
            life--;
            e3L2.moveEnemy = 0.01;
            isGenerateEnemy3 = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateLevel_2_EnemySet3, 0);
}
void updateLevel_1_Boss(int value)
{
    if(isBoss1 && isNewGame && boss.boosLife>0)
    {
        bossLaserCounter++;
        if(bossLaserCounter>=10)
        {
            boss.isBossLaser = true;
            bossLaserCounter = 0;
        }
        if(turnLeft)
        {
            boss.moveBoss -= .02f;
            if(boss.moveBoss <= -0.85)
            {
               turnLeft = false;
            }
        }
        else
        {
            boss.moveBoss += .02f;
            if(boss.moveBoss >= 0.7)
            {
               turnLeft = true;
            }
        }
    }
    else if(boss.boosLife<=0  && isNewGame)
    {
        boss1Falling -= .02f;
        if(boss1Falling < -1.2)
        {
            isBoss1Die = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateLevel_1_Boss, 0);
}

void updateLevel_2_Boss(int value)
{
    if(isBoss2 && isNewGame && boss2.boosLife>0)
    {
        bossLaserCounter++;
        if(bossLaserCounter>=5)
        {
            boss2.isBossLaser = true;
            bossLaserCounter = 0;
        }
        if(turnLeft)
        {
            boss2.moveBoss -= .02f;
            if(boss2.moveBoss <= -0.85)
            {
               turnLeft = false;
            }
        }
        else
        {
            boss2.moveBoss += .02f;
            if(boss2.moveBoss >= 0.85)
            {
               turnLeft = true;
            }
        }
    }
    else if(boss2.boosLife<=0  && isNewGame)
    {
        boss2Falling -= .02f;
        if(boss2Falling < -0.45)
        {
            isBoss2Die = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateLevel_2_Boss, 0);
}

void updateLevel_3_Boss(int value)
{
    if(isLevel3 && isNewGame && boss3.boosLife>0)
    {
        bossLaserCounter++;
        if(bossLaserCounter>=10)
        {
            boss3.isBossLaser = true;
            bossLaserCounter = 0;
        }
        if(turnLeft)
        {
            boss3.moveBoss -= .02f;
            if(boss3.moveBoss <= -0.85)
            {
               turnLeft = false;
            }
        }
        else
        {
            boss3.moveBoss += .02f;
            if(boss3.moveBoss >= 0.85)
            {
               turnLeft = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateLevel_3_Boss, 0);
}

void menu(int id)
{
    switch(id)
    {
        case 1: life=5;
        break;
    }
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 700);
    glutInitWindowPosition(300, 0);
	glutCreateWindow("Transformation");
    glutDisplayFunc(drawScene);
    glutTimerFunc(70, updateLevel_1_EnemySet1, 0);
    glutTimerFunc(120, updateLevel_1_EnemySet2, 0);
    glutTimerFunc(50, updateLevel_2_EnemySet1, 0);
    glutTimerFunc(80, updateLevel_2_EnemySet2, 0);
    glutTimerFunc(120, updateLevel_2_EnemySet3, 0);
    glutTimerFunc(50, updateLevel_1_Boss, 0);
    glutTimerFunc(30, updateLevel_2_Boss, 0);
    glutTimerFunc(20, updateLevel_3_Boss, 0);
    glutTimerFunc(50, updateLife, 0);
    glutTimerFunc(50, updateToNext, 0);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKeys);
    glClearColor(0,0,0,0);
    glutCreateMenu(menu);
    glutAddMenuEntry("Life Full",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    sndPlaySound("background.wav",SND_ASYNC|SND_LOOP);
	glutMainLoop();
	return 0;
}
