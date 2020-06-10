#include "doctest.h"
#include "CLI.hpp"

TEST_CASE ("constructor") {
    SUBCASE ("NOTHROW 1") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-c", "-f", "kek.in", "-o", "kek.out"};
        CHECK_NOTHROW(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("NOTHROW 2") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "-f", "kek.in", "-o", "kek.out"};
        CHECK_NOTHROW(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("NOTHROW 3") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "--file", "k e k.in", "--output", "k_e_k.out"};
        CHECK_NOTHROW(CLI::CLI(argc, const_cast<char **>(argv)));
    }

    SUBCASE ("THROW 1") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "c", "-f", "kek.in", "-o", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 2") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "-f", "kek.in", "o", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 4") {
        constexpr int argc = 7;
        const char *argv[argc] = {"./hw_03", "-u", "--file", "ke+k.in", "--output", "k_e_k.out", "-p"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 5") {
        constexpr int argc = 7;
        const char *argv[argc] = {"./hw_03", "-u", "-c", "-f", "kek.in", "-o", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 6") {
        constexpr int argc = 5;
        const char *argv[argc] = {"./hw_03", "-f", "kek.in", "-o", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 7") {
        constexpr int argc = 7;
        const char *argv[argc] = {"./hw_03", "-c", "44", "-f", "kek.in", "-o", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 8") {
        constexpr int argc = 5;
        const char *argv[argc] = {"./hw_03", "-c", "-f", "kek.in", "-o"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
    SUBCASE ("THROW 9") {
        constexpr int argc = 7;
        const char *argv[argc] = {"./hw_03", "-c", "--file", "kek.in", "-o", "--output", "kek.out"};
        CHECK_THROWS(CLI::CLI(argc, const_cast<char **>(argv)));
    }
}

TEST_CASE ("get_archiver_mode") {
    SUBCASE ("NOTHROW 1") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "-f", "kek.in", "-o", "kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_archiver_mode() == CLI::EXTRACT);
    }
    SUBCASE ("NOTHROW 2") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-c", "-f", "kek.in", "-o", "kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_archiver_mode() == CLI::COMPRESS);
    }
}

TEST_CASE ("get_input_file") {
    SUBCASE ("NOTHROW 1") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "-f", "kek.in", "-o", "kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_input_file() == "kek.in");
    }
    SUBCASE ("NOTHROW 2") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-c", "--file", "kek.in", "-o", "kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_input_file() == "kek.in");
    }
}

TEST_CASE ("get_output_file") {
    SUBCASE ("NOTHROW 1") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-u", "-f", "kek.in", "-o", "kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_output_file() == "kek.out");
    }
    SUBCASE ("NOTHROW 2") {
        constexpr int argc = 6;
        const char *argv[argc] = {"./hw_03", "-c", "--file", "/src/kek.in", "--output", "/src/kek.out"};
        CLI::CLI p(argc, const_cast<char **>(argv));
        CHECK(p.get_output_file() == "/src/kek.out");
    }
}