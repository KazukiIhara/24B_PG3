#include "InputHandler.h"

#include "framework/SUGER.h"


ICommand* InputHander::HandleInput() {
	if (SUGER::PushKey(DIK_D)) {
		return pressKeyD_;
	}
	if (SUGER::PushKey(DIK_A)) {
		return pressKeyA_;
	}
	// 何もコマンドがない場合はnullptr
	return nullptr;
}

void InputHander::AssignMoveLeftCommand2PressKeyA() {
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHander::AssignMoveRightCommand2PressKeyD() {
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}
