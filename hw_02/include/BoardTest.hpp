#pragma once

#include "Board.hpp"
#include "Test.hpp"

class BoardTest : public Test {
private:
    static void test_1_isInside();

    static void test_2_isInside();

    static void test_3_isInside();

    static void test_1_canMove();

    static void test_2_canMove();

    static void test_3_canMove();

    static void test_4_canMove();

    static void test_1_move();

    static void test_2_move();

    static void test_3_move();

    static void test_1_changePlayer();

    static void test_2_changePlayer();

    static void test_3_changePlayer();

    static void test_1_getState();

    static void test_2_getState();

    static void test_3_getState();

    static void test_4_getState();

    static void test_1_getHeight();

    static void test_2_getHeight();

    static void test_3_getHeight();

    static void test_1_getWidth();

    static void test_2_getWidth();

    static void test_3_getWidth();

    static void test_1_getPlayer();

    static void test_2_getPlayer();

    static void test_3_getPlayer();

    static void test_1_getField();

    static void test_2_getField();

    static void test_3_getField();

public:
    void runAllTests() override;

};