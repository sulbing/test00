#include "stdafx.h"
#include "starcraftScene.h"
#include "battle.h"
#include "dummy.h"

starcraftScene::starcraftScene()
{
}


starcraftScene::~starcraftScene()
{

}

HRESULT starcraftScene::init()
{
	//_battle = new battle;
	//_battle->init("battle", WINSIZEX / 2, WINSIZEY / 2);

	player1 = new dummy;
	player1->init(true, WINSIZEX / 4, WINSIZEY / 2, 40, 40, VK_UP,VK_DOWN,VK_LEFT,VK_RIGHT,'A','S');

	player2 = new dummy;
	player2->init(false, WINSIZEX * 3 / 4, WINSIZEY / 2, 40, 40, VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, 'O', 'P');

	return S_OK;
}
void starcraftScene::release()
{

}

void starcraftScene::update() 
{
	//_battle->update();
	player1->update();
	player2->update();
}

void starcraftScene::render() 
{
	char str[128];

	sprintf(str, "½ºÅ¸ ¾À");
	TextOut(getMemDC(), WINSIZEX / 2 + 200, WINSIZEY / 2, str, strlen(str));

	//_battle->render();
	player1->render();
	player2->render();


}
