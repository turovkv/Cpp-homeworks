#include "BoardTest.hpp"

void BoardTest::runAllTests() {
    test_1_isInside();
    test_2_isInside();
    test_3_isInside();

    test_1_canMove();
    test_2_canMove();
    test_3_canMove();
    test_4_canMove();

    test_1_move();
    test_2_move();
    test_3_move();

    test_1_changePlayer();
    test_2_changePlayer();
    test_3_changePlayer();

    test_1_getState();
    test_2_getState();
    test_3_getState();
    test_4_getState();

    test_1_getHeight();
    test_2_getHeight();
    test_3_getHeight();

    test_1_getWidth();
    test_2_getWidth();
    test_3_getWidth();

    test_1_getPlayer();
    test_2_getPlayer();
    test_3_getPlayer();

    test_1_getField();
    test_2_getField();
    test_3_getField();
}

void BoardTest::test_1_isInside() {
    Board b(3, 3);
    DO_CHECK(b.isInside(Position(1, 1)));
}

void BoardTest::test_2_isInside() {
    Board b(3, 3);
    DO_CHECK(!b.isInside(Position(-1, 1)));
}

void BoardTest::test_3_isInside() {
    Board b(10, 10);
    DO_CHECK(!b.isInside(Position(4, 10)));
}

void BoardTest::test_1_canMove() {
    Board b(3, 3);
    DO_CHECK(!b.canMove(Position(-1, 1)));
}

void BoardTest::test_2_canMove() {
    Board b(3, 3);
    b.move(Position(0, 0));
    DO_CHECK(!b.canMove(Position(0, 0)));
}

void BoardTest::test_3_canMove() {
    Board b(3, 3);
    b.move(Position(0, 0));
    b.move(Position(1, 1));
    DO_CHECK(b.canMove(Position(1, 2)));
}

void BoardTest::test_4_canMove() {
    Board b(3, 3);
    b.move(Position(1, 1));
    b.move(Position(2, 2));
    DO_CHECK(!b.canMove(Position(1, 1)));
}

void BoardTest::test_1_move() {
    int height = 4;
    int width = 4;
    bool flag = true;
    Board b(height, width);
    for (int j = 0; j < width; j++)
        b.move(Position(j, 1));

    auto field = b.getField();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 1 && j % 2 == 0 && field[i][j] != SquareState::O) flag = false;
            if (i == 1 && j % 2 == 1 && field[i][j] != SquareState::X) flag = false;
            if (i != 1 && field[i][j] != SquareState::NONE) flag = false;
        }
    }

    DO_CHECK(flag);
}

void BoardTest::test_2_move() {
    int height = 10;
    int width = 10;
    bool flag = true;
    Board b(height, width);
    b.move(Position(7, 8));

    auto field = b.getField();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 8 && j == 7 && field[i][j] != SquareState::O) flag = false;
            if (i != 8 && j != 7 && field[i][j] != SquareState::NONE) flag = false;
        }
    }

    DO_CHECK(flag);
}

void BoardTest::test_3_move() {
    int height = 2;
    int width = 2;
    bool flag = true;
    Board b(height, width);
    b.move(Position(0, 0));
    b.move(Position(1, 0));
    b.move(Position(0, 1));
    b.move(Position(1, 1));

    auto field = b.getField();
    if (field[0][0] != SquareState::O) flag = false;
    if (field[1][0] != SquareState::O) flag = false;
    if (field[0][1] != SquareState::X) flag = false;
    if (field[1][1] != SquareState::X) flag = false;

    DO_CHECK(flag);
}

void BoardTest::test_1_changePlayer() {
    Board b;
    b.changePlayer();
    DO_CHECK(b.getPlayer() == Player::X);
}

void BoardTest::test_2_changePlayer() {
    Board b;
    b.changePlayer();
    b.changePlayer();
    DO_CHECK(b.getPlayer() == Player::O);
}

void BoardTest::test_3_changePlayer() {
    Board b;
    for (int i = 0; i < 100; i++)
        b.changePlayer();
    DO_CHECK(b.getPlayer() == Player::O);
}

void BoardTest::test_1_getState() {
    Board b;
    b.move(Position(0, 0));
    DO_CHECK(b.getState() == GameState::IN_PROGRESS);
}

void BoardTest::test_2_getState() {
    Board b(3, 3, 3);
    b.move(Position(0, 0));
    b.move(Position(0, 1));
    b.move(Position(1, 0));
    b.move(Position(0, 2));
    b.move(Position(2, 0));
    DO_CHECK(b.getState() == GameState::O_WINS);
}

void BoardTest::test_3_getState() {
    Board b(3, 3, 3);
    b.move(Position(0, 0));
    b.move(Position(0, 1));
    b.move(Position(1, 0));
    b.move(Position(0, 2));
    b.move(Position(2, 2));
    b.move(Position(2, 1));
    b.move(Position(1, 2));
    b.move(Position(1, 1));
    DO_CHECK(b.getState() == GameState::X_WINS);
}

void BoardTest::test_4_getState() {
    Board b(2, 2);
    b.move(Position(0, 0));
    b.move(Position(1, 0));
    b.move(Position(0, 1));
    b.move(Position(1, 1));
    DO_CHECK(b.getState() == GameState::DRAW)
}

void BoardTest::test_1_getHeight() {
    Board b;
    DO_CHECK(b.getHeight() == 10);
}

void BoardTest::test_2_getHeight() {
    Board b(5);
    DO_CHECK(b.getHeight() == 5);
}

void BoardTest::test_3_getHeight() {
    Board b(10, 10);
    b.move(Position(0, 0));
    DO_CHECK(b.getHeight() == 10);
}

void BoardTest::test_1_getWidth() {
    Board b;
    DO_CHECK(b.getWidth() == 10);
}

void BoardTest::test_2_getWidth() {
    Board b(5, 5);
    DO_CHECK(b.getWidth() == 5);
}

void BoardTest::test_3_getWidth() {
    Board b;
    b.move(Position(0, 0));
    DO_CHECK(b.getWidth() == 10);
}

void BoardTest::test_1_getPlayer() {
    Board b;
    DO_CHECK(b.getPlayer() == Player::O);
}

void BoardTest::test_2_getPlayer() {
    Board b;
    b.move(Position(0, 0));
    DO_CHECK(b.getPlayer() == Player::X);
}

void BoardTest::test_3_getPlayer() {
    Board b(1, 1, 1);
    b.move(Position(0, 0));
    DO_CHECK(b.getPlayer() == Player::X);
}

void BoardTest::test_1_getField() {
    Board b;
    auto field = b.getField();
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j] != SquareState::NONE)
                flag = false;
        }
    }
    DO_CHECK(flag);
}

void BoardTest::test_2_getField() {
    Board b(3, 4);
    DO_CHECK(b.getField().size() == 3 && b.getField()[0].size() == 4);
}

void BoardTest::test_3_getField() {
    Board b(2, 2);
    auto field1 = b.getField();
    auto field2 = b.getField();
    DO_CHECK(field1 == field2);
}
