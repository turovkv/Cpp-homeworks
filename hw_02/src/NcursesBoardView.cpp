#include "NcursesBoardView.hpp"

NcursesBoardView::NcursesBoardView() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void NcursesBoardView::showField(const std::vector<std::vector<SquareState>> &field, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (field[i][j] == SquareState::X) mvaddch(i, j, 'X');
            if (field[i][j] == SquareState::O) mvaddch(i, j, 'O');
            if (field[i][j] == SquareState::NONE) mvaddch(i, j, '.');
        }
    }
    mvaddstr(LINES - error_line_, 0, "                         ");
    mvaddstr(LINES - exit_line_, 0, "Press \'x\' to exit");
}

void NcursesBoardView::finishGame(GameState state) {
    if (state == GameState::DRAW) {
        mvaddstr(LINES - message_line_, 0, "Draw. ");
    }
    if (state == GameState::X_WINS) {
        mvaddstr(LINES - message_line_, 0, "X wins!");
    }
    if (state == GameState::O_WINS) {
        mvaddstr(LINES - message_line_, 0, "O wins!");
    }

    while (getch() != 'x');
}

void NcursesBoardView::invitePlayer(Player player) {
    if (player == Player::O) {
        mvaddstr(LINES - message_line_, 0, "O move");
    }
    if (player == Player::X) {
        mvaddstr(LINES - message_line_, 0, "X move");
    }
}

void NcursesBoardView::badMove() {
    mvaddstr(LINES - error_line_, 0, "Bad move!");
}

std::optional<Position> NcursesBoardView::retrieveNextPosition() {
    int y = current_pos_.y;
    int x = current_pos_.x;
    move(y, x);
    while (true) {
        getyx(stdscr, y, x);
        int LastKey = getch();
        if (LastKey == KEY_UP && y > 0) {
            move(y - 1, x);
        }
        if (LastKey == KEY_DOWN && y < LINES - 1) {
            move(y + 1, x);
        }
        if (LastKey == KEY_LEFT && x > 0) {
            move(y, x - 1);
        }
        if (LastKey == KEY_RIGHT && x < COLS) {
            move(y, x + 1);
        }
        if (LastKey == ' ') {
            current_pos_ = Position(x, y);
            break;
        }
        if (LastKey == 'x') {
            current_pos_ = EXIT_MOVE;
            break;
        }
    }
    return current_pos_;
}

NcursesBoardView::~NcursesBoardView() {
    endwin();
}