//======================================================
// File Name	: AIController.h
// Summary		: �`�h�R���g���[���[
// Date			: 2020/5/12
// Author		: Kyoya  Sakamoto
//======================================================
#pragma once

#include <Game\Controller\CharacterController.h>

class MoveModeSelection;

class AIController : public  CharacterController
{
public:
	enum  class Behavior
	{
		NONE,
		MOVE_FORWARD,	//1
		MOVE_BACKWARD,//2
		MOVE_LEFTWARD,//3
		MOVE_RIGHTWARD,	//4	
		TURN_LEFT,//5
		TURN_RIGHT,//6
		SHOOT,//7

		NUM
	};

public:
	//�R���X�g���N
	AIController(Character* character, Character* enemy);
	//�f�X�g���N�^
	~AIController();

public:
	//�X�V
	void Update(const DX::StepTimer& timer) override;
	//�f�o�b�N�`��
	void Render();

public:
	//�ړ����x
	static const float  MOVE_SPEED;
	//��]���x
	static const float  ROT_SPEED;
	//�V���b�g�C���^�[�o��
	static const float  SHOT_INTERVAL;
	static const float  STATE_INTERVAL;
	static const int    MODE_COUNT = 7;

private:
	std::unique_ptr<MoveModeSelection>   m_moveModeSelection;

	//�X�e�C�g�ύX�C���^�[�o��
	float m_stateInterval;
	//�X�e�C�g
	Behavior m_state;
	Character* m_enemy;

	int m_randMobeCount;
};