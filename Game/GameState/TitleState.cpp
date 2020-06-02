//======================================================
// File Name	: TitleState.cpp
// Summary	: タイトルステイト
// Author		: Kyoya Sakamoto
//======================================================
#include"TitleState.h"

#include <Game\Common\GameContext.h>

#include <Game\GameState\GameStateManager.h>

#include <Game\Common\DebugFont.h>
/// <summary>
/// コンストラクタ
/// </summary>
TitleState::TitleState()
	: IGameState()
{
}

/// <summary>
/// デストラクタ
/// </summary>
TitleState::~TitleState()
{
}

/// <summary>
/// イニシャライズ
/// </summary>
void TitleState::Initialize()
{
}

/// <summary>
///アップデート 
/// </summary>
/// <param name="elapsedTime">タイマー</param>
void TitleState::Update(const DX::StepTimer& timer)
{
	timer;
	DirectX::Keyboard::State keyState = DirectX::Keyboard::Get().GetState();
	m_keyTracker.Update(keyState);
	if (m_keyTracker.IsKeyReleased(DirectX::Keyboard::Z))
	{
		using StateID = GameStateManager::GameStateID;
		GameStateManager* gameStateManager = GameContext().Get<GameStateManager>();
		gameStateManager->RequestState(StateID::PLAY_STATE);
	}
}

/// <summary>
/// 描画
/// </summary>
void TitleState::Render()
{
	DebugFont* debugFont = DebugFont::GetInstance();
	debugFont->print(10, 10, L"TitleState");
	debugFont->draw();
}

/// <summary>
/// 終了
/// </summary>
void TitleState::Finalize()
{
}

