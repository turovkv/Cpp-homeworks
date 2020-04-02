#pragma once

#include "Board.hpp"
#include "BoardView.hpp"

class StdioBoardView final : public BoardView {
public:
    void showField(const std::vector<std::vector<SquareState>> &, int height, int width) override;

    void finishGame(GameState state) override;

    void invitePlayer(Player player) override;

    void badMove() override;

    std::optional<Position> retrieveNextPosition() override;
};