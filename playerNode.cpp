#include "stdafx.h"
#include "playerNode.h"


playerNode::playerNode()
{
}


playerNode::~playerNode()
{
}


//�÷��̾� ���� �ʱ�ȭ �Լ�
HRESULT playerNode::init(int playerX, int playerY, int playerWidth, int playerHeight)
{
	
	x = playerX;
	y = playerY;
	width = playerWidth;
	height = playerHeight;

	rc = RectMakeCenter(x, y, width, height);

	speedX = 0;
	speedY = 0;
	state = idle;
	bool isRight = true;

	return S_OK;
};
void playerNode::release()
{

};
void playerNode::update()
{

};
void playerNode::render()
{

};