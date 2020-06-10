#pragma once

#include <map>
#include <vector>

namespace CLI {
    using std::string_view;

    constexpr string_view COMPRESS = "c";
    constexpr string_view EXTRACT = "u";
    constexpr string_view INPUT1 = "f";
    constexpr string_view INPUT2 = "file";
    constexpr string_view OUTPUT1 = "o";
    constexpr string_view OUTPUT2 = "output";

    class CLIException : public std::logic_error {
    public:
        explicit CLIException(string_view message);
    };


    class CLI {
    public:
        CLI(int argc, char *argv[]);
        string_view get_archiver_mode();
        string_view get_input_file();
        string_view get_output_file();

    private:
        bool has_unknown_parameters() const;
        string_view get_single_existing(const std::vector<string_view> &params) const;

    private:
        std::map<string_view, string_view> parameters_;
        string_view archiver_mode_;
        string_view input_file_;
        string_view output_file_;
    };
}