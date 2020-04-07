//======================================================
// File Name	 : IGameState.h
// Summary	 : �Q�[���X�e�C�g�̃C���^�[�t�F�C�X
// Author		 : Kyoya Sakamoto
//======================================================
#pragma once
#include <Framework\StepTimer.h>

class IGameState
{
public:
	IGameState() = default;

public:
	virtual ~IGameState() = default;

public:
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(const DX::StepTimer& timer) = 0;
	//�`��
	virtual void Render(const DX::StepTimer& timer) = 0;
	//�I��
	virtual void Finalize() = 0;
};