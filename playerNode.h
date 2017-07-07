#pragma once
#include "gameNode.h"
#include "animation.h"


//케릭터 스테이트에 관련된 이넘문 (생각해보니 워크랑 백워크도 왼쪽 오른쪽 잇어야되요)
enum stateEnum
{
	idle,		// 이때는 이동 가능
	walk,		// 이때는 이동 가능
	backWalk,	// 이때는 이동 가능
	jump,		// 이때는 이동 불가능, jump를 시작할때 speedX 값을 받아서 x축 스피드를 줄것
	crouch,		// 이때는 이동 불가능, 앉아있는 상태
	hit1,		// 서잇을때 맞는모션 (넘어지는거 x)
	hit2,		// 맞으면서 날라가는 모션 (넘어지는거 o)
	standing,	// 누워있을때 - > idle 사이에 일어나는 애니메이션이 재생되는 state
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

//게임노드를 상속받은 플레이어의 마더 클래스 여러분은 이것을 상속받으시면 됩니다
class playerNode : public gameNode
{
protected:
	
	image* _image;			//케릭터의 이미지
	animation* _animation;	//케릭터의 애니메이션
	RECT rc;				//케릭터의 렉트 즉, 케릭터의 피격판정 박스
	float x, y;				//좌표
	float width, height;	//캐릭터 랙트의 가로와 세로
	float speedX, speedY;	//속도
	stateEnum state;		//상태
	bool isRight;			//방향판별불값 왼쪽 : false , 오른쪽 : true
	int maxHP;
	int currentHP;
	bool _isPlayer1;		//플레이어1(true) 인지 플레이어2(false) 인지 판별하는 함수
	float gravity;			//중력값
	int _upKey, _downKey, _rightKey, _leftKey, _punchKey, _kickKey;    //키입력 관련 변수

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey);
	virtual void release();
	virtual void update();
	virtual void render();


	//기본 이동 함수, 속도에 따른 좌표값이 변한다
	virtual void basicMove();
	


	playerNode();
	~playerNode();
};

