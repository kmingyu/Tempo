#include "stdafx.h"
#include "MainScene.h"
#include <iostream>


MainScene::MainScene()
{
	enemy = new ZeroSprite("Resources/Image/bullet.png");
	button = new ZeroSprite("Resources/Image/startButton.png");
}


MainScene::~MainScene()
{
	enemy = new ZeroSprite("Resources/Image/bullet.png");
	enemy->SetPos(100, 100);
	button = new ZeroSprite("Resources/Image/startButton.png");
	button->SetPos(500, 500);
}

void MainScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN){
		if (button->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			ZeroSceneMgr->ChangeScene(new GameScene());
			return;
		}
	}
}

void MainScene::Render() {
	ZeroIScene::Render();
	enemy->Render();
	button->Render();
}
