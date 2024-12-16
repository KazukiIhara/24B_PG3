#include "objects/player/Player.h"

#include "command/Command.h"

void MoveRightCommand::Exec(Player& player) {
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player) {
	player.MoveLeft();
}
