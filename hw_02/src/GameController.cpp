#include <GameController.hpp>

GameController::GameController(Board &board, BoardView &view, GameMode mode) :
        board_(board), view_(view), mode_(mode) {}

void GameController::runGame() {
    if (mode_ != GameMode::SILENT) {
        view_.showField(board_.getField(), board_.getHeight(), board_.getWidth());
    }
    while (true) {
        view_.invitePlayer(board_.getPlayer());
        std::optional<Position> optPosition = view_.retrieveNextPosition();
        if (!optPosition) {
            view_.badMove();
            continue;
        }
        if (optPosition.value() == EXIT_MOVE)
            break;
        if (!board_.canMove(optPosition.value())) {
            view_.badMove();
            continue;
        }
        board_.move(optPosition.value());
        if (board_.getState() != GameState::IN_PROGRESS) {
            view_.showField(board_.getField(), board_.getHeight(), board_.getWidth());
            view_.finishGame(board_.getState());
            break;
        }
        if (mode_ != GameMode::SILENT) {
            view_.showField(board_.getField(), board_.getHeight(), board_.getWidth());
        }
    }
}


