#include "Player.h"

#include "framework/SUGER.h"

void Player::Initialize() {
	SUGER::Create2DObject("white", "white.png");
	Object2DController::Initialize("white");
	Object2DController::SetPosition(Vector2(64.0f, 64.0f));
	Object2DController::SetSize(Vector2(128.0f, 128.0f));
}

void Player::Update() {

}

void Player::MoveRight() {
	this->SetPosition(this->GetPosition() + Vector2(1.0f, 0.0f));
}

void Player::MoveLeft() {
	this->SetPosition(this->GetPosition() + Vector2(-1.0f, 0.0f));
}
