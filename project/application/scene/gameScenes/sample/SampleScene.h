#pragma once

// Common
#include "iScene/base/BaseScene.h"
#include "2d/controller/Object2dController.h"
#include "3d/entityController/EntityController.h"
#include "VFX/particle/emitterController/EmitterController.h"
#include "3d/lineController/LineController.h"

#include "inputHandler/InputHandler.h"
#include "command/Command.h"

// SampleScene
#include "objects/player/Player.h"

class SampleScene :public BaseScene {
public: // 公開メンバ関数
	// コンストラクタ
	SampleScene() = default;
	// デストラクタ
	~SampleScene() = default;
	// 初期化
	void Initialize()override;
	// 終了
	void Finalize()override;

	// プレイフェーズ初期化
	void SceneStatePlayInitialize()override;
	// プレイフェーズ更新
	void SceneStatePlayUpdate()override;

private: // 非公開メンバ変数
	// インプットハンドラー
	std::unique_ptr<InputHander> inputHandler_;
	// コマンドを受け取る箱
	ICommand* iCommand_ = nullptr;
	// プレイヤー
	std::unique_ptr<Player> player_;
};