#pragma once
#include "playerNode.h"
#include "animation.h"
#include "timer.h"
#include "dummySkill.h"


class dummy : public playerNode
{
private:

	//이미지와 애니메이션은 플레이어 클래스에서 선언합니다
	image* _image;
	animation* _ani;

	image* _image2;
	animation* _ani2;

	image* punchImage;
	animation* punchAni;

	//펀치선언 (마치 총알처럼)
	skillPunch* _punch;

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey);
	virtual void release();
	virtual void update();
	virtual void render();

	//키 컨트롤 함수 (업데이트에 들어감)
	virtual void keyControl();
	//스테이트 컨트롤 함수 (업데이트에 들어감)
	virtual void stateControl();

	dummy();
	~dummy();
};

