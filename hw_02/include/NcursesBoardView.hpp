#pragma once

#include <ncurses.h>
#include "Board.hpp"
#include "BoardView.hpp"


class NcursesBoardView final : public BoardView {
public:
    NcursesBoardView();

    void showField(const std::vector<std::vector<SquareState>> &, int height, int width) override;

    void finishGame(GameState state) override;

    void invitePlayer(Player player) override;

    void badMove() override;

    std::optional<Position> retrieveNextPosition() override;

    ~NcursesBoardView() override;

private:
    Position current_pos_ = Position(0, 0);
    const int message_line_ = 3;
    const int error_line_ = 4;
    const int exit_line_ = 1;
    const Position EXIT_MOVE = Position(-1, -1);
};