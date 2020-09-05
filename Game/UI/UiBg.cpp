//======================================================
// File Name	: UiBg.cpp
// Summary		: 背景
// Date			: 2020/5/12
// Author		: Kyoya  Sakamoto
//======================================================
#include "UiBg.h"

#include <DirectXTK/Effects.h>
#include <DirectXTK/CommonStates.h>

#include <Game/Common/GameContext.h>
#include <Game/Common/DeviceResources.h>

#include <Game/Camera/Camera.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
UiBg::UiBg()
{
}

/// <summary>
/// デストラクタ
/// </summary>
UiBg::~UiBg()
{
}

/// <summary>
/// 初期化
/// </summary>
void UiBg::Initialize(const DirectX::SimpleMath::Vector3& pos)
{
	m_spriteBatch = std::make_unique<SpriteBatch>(GameContext().Get<DX::DeviceResources>()->GetD3DDeviceContext());
	CreateWICTextureFromFile(GameContext().Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources\\Textures\\bg01.png", NULL, m_texture.ReleaseAndGetAddressOf());

	m_position = pos;
}

/// <summary>
/// 更新
/// </summary>
/// <param name="timer">タイマー</param>
void UiBg::Update(const DX::StepTimer& timer)
{
	timer;
}

/// <summary>
/// 描画
/// </summary>
void UiBg::Render()
{
	m_spriteBatch->Begin();
	m_spriteBatch->Draw(m_texture.Get(), m_position);
	m_spriteBatch->End();
}

/// <summary>
/// 当たった後の処理
/// </summary>
/// <param name="object">当たったオブジェクト</param>
void UiBg::OnCollision(GameObject* object)
{
	object;
}
