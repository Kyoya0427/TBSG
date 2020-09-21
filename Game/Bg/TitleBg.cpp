//======================================================
// File Name	: TitleBg.cpp
// Summary		: �w�i
// Date			: 2020/5/12
// Author		: Kyoya  Sakamoto
//======================================================
#include "TitleBg.h"

#include <DirectXTK/Effects.h>

#include <Game/Common/GameContext.h>
#include <Game/Common/DeviceResources.h>

#include <Game/Camera/Camera.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleBg::TitleBg()
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleBg::~TitleBg()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="pos">�Z���^�[���W</param>
void TitleBg::Initialize(const Vector3& pos)
{
	m_spriteBatch = std::make_unique<SpriteBatch>(GameContext().Get<DX::DeviceResources>()->GetD3DDeviceContext());
	CreateWICTextureFromFile(GameContext().Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources//Textures//title.png", NULL, m_texture.ReleaseAndGetAddressOf());

	m_position = pos;
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="timer">�^�C�}�[</param>
void TitleBg::Update(const DX::StepTimer& timer)
{
	timer;
}

/// <summary>
/// �`��
/// </summary>
void TitleBg::Render()
{
	m_spriteBatch->Begin();
	m_spriteBatch->Draw(m_texture.Get(), m_position);
	m_spriteBatch->End();
}

/// <summary>
/// ����������̏���
/// </summary>
/// <param name="object">���������I�u�W�F�N�g</param>
void TitleBg::OnCollision(GameObject* object)
{
	object;
}