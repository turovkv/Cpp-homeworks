#include <iostream>
#include "StdioBoardView.hpp"

void StdioBoardView::showField(const std::vector<std::vector<SquareState>> &field, int height, int width) {
    std::cout << '\n';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (field[i][j] == SquareState::NONE)
                std::cout << '.';
            if (field[i][j] == SquareState::X)
                std::cout << 'X';
            if (field[i][j] == SquareState::O)
                std::cout << 'O';
        }
        std::cout << '\n';
    }
}

void StdioBoardView::finishGame(GameState state) {
    if (state == GameState::X_WINS) {
        std::cout << "X wins!\n";
    }
    if (state == GameState::O_WINS) {
        std::cout << "O wins!\n";
    }
    if (state == GameState::DRAW) {
        std::cout << "Draw.\n";
    }
}

void StdioBoardView::invitePlayer(Player player) {
    if (player == Player::O) {
        std::cout << "O move: ";
    }
    if (player == Player::X) {
        std::cout << "X move: ";
    }
}

void StdioBoardView::badMove() {
    std::cout << "Bad move!\n";
}

std::optional<Position> StdioBoardView::retrieveNextPosition() {
    std::string str;
    std::getline(std::cin, str);

    const int sscanf_check = 3;
    char ch1, ch2;
    int x, y;
    if (sscanf(str.c_str(), "%d%c%d %c", &y, &ch1, &x, &ch2) != sscanf_check || ch1 != ' ') {
        return std::nullopt;
    } else {
        return Position(x, y);
    }
}