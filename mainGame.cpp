#include "stdafx.h"
#include "mainGame.h"

//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================


//초기화는 앞으로 여기에다가 해라
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경일껄", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
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

//메모리 해제는 앞으로 여기에다가 해라
void mainGame::release(void)
{
	gameNode::release();

}

//연산은(는) 앞으로 여기에다가 해라
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

//앞으로 여기에다 그려라 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ 위에 건들지마라 ================

	IMAGEMANAGER->findImage("배경일껄")->render(getMemDC(), 0, 0);
 
	
	_currentScene->render();

	TIMEMANAGER->render(getMemDC());

	//===============아래도 건들지마라 =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

// 김민서기 test 되라 좀 kimguer0228