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
class playerNode : public gameNode
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
	int maxHP;
	int currentHP;
	bool _isPlayer1;		//�÷��̾�1(true) ���� �÷��̾�2(false) ���� �Ǻ��ϴ� �Լ�
	float gravity;			//�߷°�
	int _upKey, _downKey, _rightKey, _leftKey, _punchKey, _kickKey;    //Ű�Է� ���� ����

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey);
	virtual void release();
	virtual void update();
	virtual void render();


	//�⺻ �̵� �Լ�, �ӵ��� ���� ��ǥ���� ���Ѵ�
	virtual void basicMove();
	


	playerNode();
	~playerNode();
};

