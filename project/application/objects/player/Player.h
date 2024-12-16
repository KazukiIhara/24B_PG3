#pragma once

#include "2d/controller/Object2dController.h"

class Player : public Object2DController {
public:
	Player() = default;
	~Player() = default;

	void Initialize();

	void Update();

	void MoveRight();
	void MoveLeft();

private:

};