//======================================================
// File Name	: GameStateManager.h
// Summary		: �Q�[���X�e�C�g�}�l�W���[
// Date			: 2020/5/12
// Author		: Kyoya Sakamoto
//======================================================
#pragma once

#include <functional>
#include <memory>
#include <deque>
#include <unordered_map>

#include <Game\Common\StepTimer.h>

class IGameState;

class GameStateManager
{
public:
	//�X�e�C�gID
	enum class GameState
	{
		NONE_STATE = -1,
		TITLE_STATE,
		PLAY_STATE,
		PAUSE_STATE,
		RESULT_STATE,
	};

private:
	//���O�ύX
	using IGameStatePtr         = std::unique_ptr<IGameState>;
	using IGameStateStack       = std::deque<IGameStatePtr>;
	using IGameStateFactory     = std::function<IGameStatePtr()>;
	using IGameStateFactoryList = std::unordered_map<GameState, IGameStateFactory>;

public:
	GameStateManager();
	~GameStateManager();

private:
	template<typename State>
	static IGameStatePtr CrateState();

public:
	
	void Update(const DX::StepTimer& timer);
	void Render();

public:
	template<typename State>
	void RegisterState(const GameState id);
	void SetStartState(const GameState id);
	void RequestState(const GameState id);
	void PushState(const GameState id);
	void PopState(int count = 1);

private:
	void ChangeState();

private:
	IGameStateFactoryList m_stateFactories;
	IGameStateStack       m_states;
	int                   m_popCount;
	GameState             m_nextStateName;

};


template<typename State>
/// <summary>
/// �X�e�C�g�쐬
/// </summary>
/// <returns></returns>
 GameStateManager::IGameStatePtr GameStateManager::CrateState()
{
	return std::make_unique<State>();
}



template<typename State>
/// <summary>
///  �X�e�C�g��o�^
/// </summary>
/// <param name="id"></param>
 void GameStateManager::RegisterState(const GameState id)
{
	 m_stateFactories.emplace(std::make_pair(id, CrateState<State>));
}