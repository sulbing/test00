#include "stdafx.h"
#include "dummySkill.h"


skillPunch::skillPunch()
{
}


skillPunch::~skillPunch()
{
}

void skillPunch::punchFire(float playerX, float playerY)
{
	_punch.hitbox = RectMakeCenter(playerX + 55, playerY - 30, 60, 15);
	_punch.isFire = true;
}

void skillPunch::render()
{
	if(_punch.isFire)Rectangle(getMemDC(), _punch.hitbox.left, _punch.hitbox.top, _punch.hitbox.right, _punch.hitbox.bottom);
}

HRESULT skillPunch::init()
{
	_punch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_punch.damage = 0;
	_punch.isDown = false;
	_punch.isFire = false;

	return S_OK;
}

void skillPunch::makeisFireFalse()
{
	_punch.isFire = false;
}