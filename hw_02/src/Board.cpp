#include <cassert>
#include "Board.hpp"

Position::Position(int x, int y) : x(x), y(y) {}

bool Position::operator==(const Position &pos) const {
    return x == pos.x && y == pos.y;
}

bool Position::operator!=(const Position &pos) const {
    return x != pos.x || y != pos.y;
}

Board::Board(int height, int width, int in_a_row, Player player) :
        height_(height), width_(width), in_a_row_to_win_(in_a_row), current_player_(player),
        field_(height, std::vector<SquareState>(width, SquareState::NONE)) {}

bool Board::isInside(Position pos) const {
    return 0 <= pos.x && pos.x < width_ && 0 <= pos.y && pos.y < height_;
}

bool Board::canMove(Position pos) const {
    if (!isInside(pos))
        return false;
    return field_[pos.y][pos.x] == SquareState::NONE;
}

void Board::move(Position pos) {
    assert(canMove(pos));
    if (current_player_ == Player::X) field_[pos.y][pos.x] = SquareState::X;
    if (current_player_ == Player::O) field_[pos.y][pos.x] = SquareState::O;
    changePlayer();
    count_moves_++;
}

void Board::changePlayer() {
    if (current_player_ == Player::X) {
        current_player_ = Player::O;
    } else {
        current_player_ = Player::X;
    }
}

GameState Board::getState() const {
    const int DIRECTIONS = 4;
    int dx[DIRECTIONS] = {1, 1, 1, 0};
    int dy[DIRECTIONS] = {-1, 0, 1, 1};
    GameState state = GameState::IN_PROGRESS;
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (field_[i][j] == SquareState::NONE) continue;
            if (state != GameState::IN_PROGRESS) continue;
            for (int k = 0; k < DIRECTIONS; k++) {
                int cnt = 1;
                Position pos;
                pos.x = j + dx[k];
                pos.y = i + dy[k];
                while (isInside(pos) && field_[pos.y][pos.x] == field_[i][j]) {
                    pos.x = pos.x + dx[k];
                    pos.y = pos.y + dy[k];
                    cnt++;
                }
                if (cnt >= in_a_row_to_win_) {
                    if (field_[i][j] == SquareState::X) state = GameState::X_WINS;
                    if (field_[i][j] == SquareState::O) state = GameState::O_WINS;
                }
            }
        }
    }
    if (state == GameState::IN_PROGRESS && count_moves_ == height_ * width_)
        state = GameState::DRAW;
    return state;
}

int Board::getHeight() const {
    return height_;
}

int Board::getWidth() const {
    return width_;
}

Player Board::getPlayer() const {
    return current_player_;
}

const std::vector<std::vector<SquareState>> &Board::getField() const {
    return field_;
}
