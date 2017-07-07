#pragma once
#include "playerNode.h"
#include "animation.h"
#include "timer.h"
#include "dummySkill.h"


class dummy : public playerNode
{
private:

	//�̹����� �ִϸ��̼��� �÷��̾� Ŭ�������� �����մϴ�
	image* _image;
	animation* _ani;

	image* _image2;
	animation* _ani2;

	image* punchImage;
	animation* punchAni;

	//��ġ���� (��ġ �Ѿ�ó��)
	skillPunch* _punch;

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey);
	virtual void release();
	virtual void update();
	virtual void render();

	//Ű ��Ʈ�� �Լ� (������Ʈ�� ��)
	virtual void keyControl();
	//������Ʈ ��Ʈ�� �Լ� (������Ʈ�� ��)
	virtual void stateControl();

	dummy();
	~dummy();
};

