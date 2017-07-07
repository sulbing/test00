#include "stdafx.h"
#include "dummy.h"


HRESULT dummy::init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey)
{
	playerNode::init(isPlayer1, playerX, playerY, playerWidth, playerHeight, upKey, downKey, leftKey, rightKey, punchKey, kickKey);

	//�̹����� �ִϸ��̼��� �÷��̾� Ŭ�������� ������������ �ʱ�ȭ���� ���ݴϴ�.
	_image = IMAGEMANAGER->addFrameImage("������̵�", "dioImage/dio_idle_right.bmp", 900, 155, 5, 1, true, RGB(255, 0, 255));
	_image2 = IMAGEMANAGER->addFrameImage("������̵�2", "dioImage/dio_idle_left.bmp", 900, 155, 5, 1, true, RGB(255, 0, 255));
	punchImage = IMAGEMANAGER->addFrameImage("���������ġ", "dioImage/dio_lightAttack_right.bmp", 900, 155, 5, 1, true, RGB(255, 0, 255));

	_ani = new animation;
	_ani->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());
	_ani->setDefPlayFrame(false, true);
	_ani->setFPS(1);
	_ani->start();

	_ani2 = new animation;
	_ani2->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());
	_ani2->setDefPlayFrame(false, true);
	_ani2->setFPS(1);
	_ani2->start();

	punchAni = new animation;
	punchAni->init(punchImage->getWidth(), punchImage->getHeight(), punchImage->getFrameWidth(), punchImage->getFrameHeight());
	punchAni->setDefPlayFrame(false, false);
	punchAni->setFPS(1);
	//punchAni->start();


	//��ġ �ʱ�ȭ
	_punch = new skillPunch;
	_punch->init();



	return S_OK;
};
void dummy::release()
{

};
void dummy::update()
{
	playerNode::update();

	
	keyControl();
	stateControl();

	//�ִϸ��̼��� ���� ������ �����Ӿ�����Ʈ�� ���ݴϴ�
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	punchAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
};


void dummy::render()
{
	
	//�ִϸ��̼��� �������ݴϴ�
	if (isRight && state != punch)_image->aniRender(getMemDC(), x- 40, y - 77, _ani);
	else if(!isRight && state != punch)_image2->aniRender(getMemDC(), x - 120, y - 77, _ani2);

	if (state == punch) punchImage->aniRender(getMemDC(), x - 40, y - 77, punchAni);


	//��ġ ��Ʈ�ڽ� �����Դϴ�
	_punch->render();


};

void dummy::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(_upKey))
	{
		if (state == idle || state == walk)
		{
			state = jump;
			speedY -= 5;
		}
		
	}
	if (KEYMANAGER->isStayKeyDown(_rightKey))
	{
		if (state == idle || state == walk)
		{
			speedX = 1;
			state = walk;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(_rightKey))
	{
		if (state == walk || state == idle)
		{
			state = idle;
		}
	}

	if (KEYMANAGER->isStayKeyDown(_leftKey))
	{
		if (state == idle || state == walk)
		{
			speedX = -1;
			state = walk;
			
		}
	}
	if (KEYMANAGER->isOnceKeyUp(_leftKey))
	{
		if (state == walk)
		{
			state = idle;
		}
	}
	

	if (KEYMANAGER->isOnceKeyDown(_punchKey))
	{
		if (state == walk || state == idle)
		{
			state = punch;
			_punch->punchFire(x, y);
			punchAni->start();
		}
	}
};

void dummy::stateControl()
{
	if (state == jump)
	{
		if (speedY > 0 && y >= WINSIZEY /2)
		{
			state = idle;
			speedY = 0;
		}
	}
	if (state == idle)
	{
		speedX = 0;
		speedY = 0;
		y = WINSIZEY / 2;
	}
	if (state == walk)
	{
		speedY = 0;
	}
	if (state == punch)
	{
		if (punchAni->isPlay() == 0)
		{
			state = idle;
			_punch->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
}

dummy::dummy()
{
}


dummy::~dummy()
{
}
