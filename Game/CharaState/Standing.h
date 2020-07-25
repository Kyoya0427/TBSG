//======================================================
// File Name	: Standing.h
// Summary		: �����X�e�[�g
// Date			: 2020/7/23
// Author		: Kyoya  Sakamoto
//======================================================
#pragma once

#include <Game/CharaState/CharaState.h>

#include <Game/Controller/CharacterController.h>

class Standing : public CharaState
{
public:
	//�R���X�g���N�^
	Standing();
	//�f�X�g���N�^
	~Standing();
public:
	//������
	void Initialize(Character* chara, CharacterController* controller) override;
	//�X�V
	void Update(const DX::StepTimer& timer) override;
	//�`��
	void Render() override;

private:
	Character*           m_chara;
	CharacterController* m_controller;

};