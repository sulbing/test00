#pragma once
#include "gameNode.h"

struct tagSkill
{
	RECT hitbox;
	int damage;
	bool isDown;
	bool isFire;
};

class skillPunch : public gameNode
{
private:
	tagSkill _punch;

public:
	void render();
	
	HRESULT init();
	skillPunch();
	~skillPunch();


	void punchFire(float playerX, float playerY);
	void makeisFireFalse(void);
};

