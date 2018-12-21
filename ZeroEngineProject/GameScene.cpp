#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetSpeed(0);
	ZeroCameraMgr->SetPos(0, 0);
	player = new ZeroSprite("Resources/Image/enemy.png");
	background = new ZeroSprite("Resources/Image/background.png");
	isRender = true;
}


GameScene::~GameScene()
{
	player = new ZeroSprite("Resources/Image/player/png");

}

void GameScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x + 200 * eTime, ZeroCameraMgr->Pos().y);
	}
	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x + -200 * eTime, ZeroCameraMgr->Pos().y);
	}
	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y - 200 * eTime);
	}
	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y + 200 * eTime);
	}
	if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN) {
		isRender = !isRender;
	}
}

void GameScene::Render() {
	ZeroIScene::Render();
	background->Render();
	if(isRender) {
		player->Render();
	}
}