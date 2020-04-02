#pragma once

#include "Board.hpp"
#include "BoardView.hpp"
#include "StdioBoardView.hpp"

enum class GameMode {
    STANDARD, SILENT, NCURSES,
};

class GameController {
public:
    explicit GameController(Board &board, BoardView &view, GameMode mode);

    void runGame();

private:
    Board &board_;
    BoardView &view_;
    GameMode mode_;
    const Position EXIT_MOVE = Position(-1, -1);
};