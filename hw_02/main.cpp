#include <cstring>
#include <Board.hpp>
#include <StdioBoardView.hpp>
#include <GameController.hpp>
#include <NcursesBoardView.hpp>

int main(int argc, char *argv[]) {

    GameMode mode;
    Board board;
    BoardView *view;
    if (argc == 1) {
        mode = GameMode::STANDARD;
        view = new StdioBoardView();
    } else if (argc > 1 && strcmp(argv[1], "silent") == 0) {
        mode = GameMode::SILENT;
        view = new StdioBoardView();
    } else if (argc > 1 && strcmp(argv[1], "ncurses") == 0) {
        mode = GameMode::NCURSES;
        view = new NcursesBoardView();
    } else {
        return -1;
    }

    GameController game(board, *view, mode);
    game.runGame();

    delete view;
    return 0;
}
