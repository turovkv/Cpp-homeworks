#pragma once

#include "Board.hpp"
#include <optional>

class BoardView {
public:
    virtual void showField(const std::vector<std::vector<SquareState>> &, int height, int width) = 0;

    virtual void finishGame(GameState GameState) = 0; //print outcome?
    virtual void invitePlayer(Player player) = 0;

    virtual void badMove() = 0;

    virtual std::optional<Position> retrieveNextPosition() = 0;

    virtual ~BoardView() = default;
};