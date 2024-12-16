// This
#include "SampleScene.h"

// ImGui
#include "externals/imgui/imgui.h"

// MyHedder
#include "framework/SUGER.h"
#include "debugTools/logger/Logger.h"

void SampleScene::Initialize() {
	// シーンの初期化(初期化処理の先頭)
	BaseScene::Initialize();

	// 
	// シーンの初期化処理ここから
	// 

	inputHandler_ = std::make_unique<InputHander>();

	// コマンドをアサイン
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	player_ = std::make_unique<Player>();
	player_->Initialize();

}

void SampleScene::Finalize() {
	// デバッグ用文字
	Logger::Log("SampleScene,Finalized\n");

}

void SampleScene::SceneStatePlayInitialize() {

}

void SampleScene::SceneStatePlayUpdate() {

	// コマンドを取得
	iCommand_ = inputHandler_->HandleInput();

	// コマンドをセット
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}

	player_->Update();

}