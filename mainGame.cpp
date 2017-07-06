#include "stdafx.h"
#include "mainGame.h"

//======================================
// 持失切櫛 社瑚切澗 床走 省澗陥
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// 持失切櫛 社瑚切澗 床走 省澗陥
//======================================


//段奄鉢澗 蒋生稽 食奄拭陥亜 背虞
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("壕井析岡", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("missilePF", "missilePF.bmp", 0, 0, 576, 44, 16, 1, true, RGB(255, 0, 255));

	_starScene = new starcraftScene;
	_starScene->init();
	
	_selectScene = new selectScene;
	_selectScene->init();

	_currentScene = _selectScene;

	
	return S_OK;
}

//五乞軒 背薦澗 蒋生稽 食奄拭陥亜 背虞
void mainGame::release(void)
{
	gameNode::release();

}

//尻至精(澗) 蒋生稽 食奄拭陥亜 背虞
void mainGame::update(void)
{
	gameNode::update();

	_currentScene->update();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_currentScene = _selectScene;
		_currentScene->init();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_currentScene = _starScene;
		_currentScene->init();
	}

	
}

//蒋生稽 食奄拭陥 益形虞 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ 是拭 闇級走原虞 ================

	IMAGEMANAGER->findImage("壕井析岡")->render(getMemDC(), 0, 0);
 
	
	_currentScene->render();

	TIMEMANAGER->render(getMemDC());

	//===============焼掘亀 闇級走原虞 =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

// 沿肯辞奄 test 鞠虞 岨 kimguer0228
//蟹亀 掬虞たたたたたたたたたたたたたたたたたたたたたたたた
//遭促 菊劃たたたたたたたたた