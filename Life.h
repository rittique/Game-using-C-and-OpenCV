#ifndef Life_Control
#define Life_Control

class Life
{
public:

    float moveLife = 0.0f;
    bool isCreateLife = false;
    float lifeX1=0.0625f,lifeX2=-0.0625f;
    float lifeMove=0.0f;


	void lifeBox();
	void bossLifeBox();
	void drawTextBox();
	void createLife();
	void drawLife(float x, float y);

};
#endif
