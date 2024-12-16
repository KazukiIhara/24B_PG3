#pragma once

#include "command/Command.h"

class InputHander {
public:
	InputHander() = default;
	~InputHander() = default;

	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;

};