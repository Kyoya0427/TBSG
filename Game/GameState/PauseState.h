//======================================================
// File Name	 : PauseState.h
// Summary		 : �|�[�Y�X�e�C�g
// Date		     : 2020/5/12
// Author		 : Kyoya Sakamoto
//======================================================
#pragma once

#include <Game\GameState\IGameState.h>

class PauseState :public IGameState
{
public:
	PauseState();

public:
	virtual ~PauseState();

public:
	//������
	void Initialize() override;
	//�X�V
	void Update(const DX::StepTimer& timer) override;
	//�`��
	void Render() override;
	//�I��
	void Finalize() override;
};
