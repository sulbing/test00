#include "stdafx.h"
#include "playerNode.h"


playerNode::playerNode()
{
}


playerNode::~playerNode()
{
}


//플레이어 최초 초기화 함수
HRESULT playerNode::init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey)
{
	//키 관련 변수
	_upKey = upKey;
	_downKey = downKey;
	_leftKey = leftKey;
	_rightKey = rightKey;
	_punchKey = punchKey;
	_kickKey = kickKey;

	//플레이어 렉트 관련 변수
	x = playerX;
	y = playerY;
	width = playerWidth;
	height = playerHeight;

	//플레이어 렉트
	rc = RectMakeCenter(x, y, width, height);

	//플레이어의 물리값
	speedX = 0;
	speedY = 0;
	state = idle;
	maxHP = 100;
	currentHP = 100;

	//1피 지정
	_isPlayer1 = isPlayer1;
	isRight = isPlayer1;

	//중력초기화
	gravity = 0;

	return S_OK;
};
void playerNode::release()
{

};
void playerNode::update()
{
	basicMove();

};
void playerNode::render()
{
	
};

void playerNode :: basicMove()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveTime = elapsedTime * 100;

	x += speedX * moveTime;
	y += speedY * moveTime;
	speedY += gravity * moveTime;

	// 점프일때           점프공격일때           점프공격일때         맞아서 다운되고 있을때
	if (state == jump || state == jumpKick || state == jumpPunch || state == hit2)
	{
		gravity = 0.08;
	}
	else gravity = 0;
};