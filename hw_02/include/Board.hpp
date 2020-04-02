#pragma once

#include <vector>

enum class Player {
    X, O
};
enum class SquareState {
    NONE, X, O
};
enum class GameState {
    IN_PROGRESS,
    X_WINS,
    O_WINS,
    DRAW
};

struct Position {
    int x, y;

    explicit Position(int x = 0, int y = 0);

    bool operator==(const Position &pos) const;

    bool operator!=(const Position &pos) const;
};

class Board {
public:
    explicit Board(int height = 10, int width = 10, int in_a_row = 5, Player player = Player::O);

    bool isInside(Position pos) const;

    bool canMove(Position pos) const;

    void move(Position pos);

    void changePlayer();

    GameState getState() const;

    int getHeight() const;

    int getWidth() const;

    Player getPlayer() const;

    const std::vector<std::vector<SquareState>> & getField() const;

private:
    int height_;
    int width_;
    int in_a_row_to_win_;
    Player current_player_;
    int count_moves_ = 0;
    std::vector<std::vector<SquareState>> field_;
};