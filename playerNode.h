#pragma once
#include "gameNode.h"
#include "animation.h"

//�ɸ��� ������Ʈ�� ���õ� �̳ѹ� (�����غ��� ��ũ�� ���ũ�� ���� ������ �վ�ߵǿ�)
enum stateEnum
{
	idle,		// �̶��� �̵� ����
	walk,		// �̶��� �̵� ����
	backWalk,	// �̶��� �̵� ����
	jump,		// �̶��� �̵� �Ұ���, jump�� �����Ҷ� speedX ���� �޾Ƽ� x�� ���ǵ带 �ٰ�
	crouch,		// �̶��� �̵� �Ұ���, �ɾ��ִ� ����
	hit1,		// �������� �´¸�� (�Ѿ����°� x)
	hit2,		// �����鼭 ���󰡴� ��� (�Ѿ����°� o)
	standing,	// ���������� - > idle ���̿� �Ͼ�� �ִϸ��̼��� ����Ǵ� state
	punch,
	kick,
	jumpPunch,
	jumpKick,
	crouchPunch,
	crouchKick,
	skill1,
	skill2,
	skill3
};

//���ӳ�带 ��ӹ��� �÷��̾��� ���� Ŭ���� �������� �̰��� ��ӹ����ø� �˴ϴ�
class playerNode : public playerNode
{
protected:
	
	image* _image;			//�ɸ����� �̹���
	animation* _animation;	//�ɸ����� �ִϸ��̼�
	RECT rc;				//�ɸ����� ��Ʈ ��, �ɸ����� �ǰ����� �ڽ�
	float x, y;				//��ǥ
	float width, height;	//ĳ���� ��Ʈ�� ���ο� ����
	float speedX, speedY;	//�ӵ�
	stateEnum state;		//����
	bool isRight;			//�����Ǻ��Ұ� ���� : false , ������ : true

public:
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render();



	playerNode();
	~playerNode();
};

