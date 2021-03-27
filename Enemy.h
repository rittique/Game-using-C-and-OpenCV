#ifndef Enemy_Create
#define Enemy_Create

class Enemy
{
public:
    float moveEnemy = 0.0f;
    float moveBoss = 0.0f;
    int boosLife = 5;
    bool create = false;
    float enemyX1,enemyX2;
    float bossX1=0.0f,bossX2=0.13f,bossHead=0.065;
    bool isBossLaser = false;
    float random;

    Enemy(float x);

	void CreateLevel_1_Enemy();
	void CreateLevel_2_Enemy();
	void CreateLevel_1_Boos();
	void CreateLevel_2_Boos();
	void CreateLevel_3_Boos();
};
#endif
