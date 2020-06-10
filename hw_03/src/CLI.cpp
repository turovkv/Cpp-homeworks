//
// Created by kirill on 12/04/2020.
//

#include <set>
#include "CLI.hpp"

namespace CLI {
    CLIException::CLIException(string_view message) :
            std::logic_error(message.data()) {}


    CLI::CLI(int argc, char *argv[]) {
        string_view param_name;
        for (int i = 1; i < argc; i++) {
            string_view word = argv[i];
            if (word[0] == '-') {
                if (!param_name.empty()) {
                    parameters_[param_name] = "";
                    param_name = "";
                }
                word = word.substr(1);
                if (!word.empty() && word[0] == '-') {
                    word = word.substr(1);
                }
                param_name = word;
            } else {
                if (word.empty()) {
                    throw CLIException("invalid parameters: empty parameter value");
                }
                if (param_name.empty()) {
                    throw CLIException("invalid parameters: value without parameter");
                }
                parameters_[param_name] = word;
                param_name = "";
            }
        }
        if (!param_name.empty()) {
            parameters_[param_name] = "";
        }

        if (has_unknown_parameters()) {
            throw CLIException("invalid parameters: unknown_parameters");
        }

        archiver_mode_ = get_single_existing({COMPRESS, EXTRACT});
        if (!parameters_[archiver_mode_].empty()) {
            throw CLIException("invalid parameters: archiver mode must not have a value");
        }

        input_file_ = parameters_[get_single_existing({INPUT1, INPUT2})];
        if (input_file_.empty()) {
            throw CLIException("invalid parameters: input file must have a value");
        }

        output_file_ = parameters_[get_single_existing({OUTPUT1, OUTPUT2})];
        if (output_file_.empty()) {
            throw CLIException("invalid parameters: output file must have a value");
        }
    }

    string_view CLI::get_archiver_mode() {
        return archiver_mode_;
    }

    string_view CLI::get_input_file() {
        return input_file_;
    }

    string_view CLI::get_output_file() {
        return output_file_;
    }

    bool CLI::has_unknown_parameters() const {
        std::set<string_view> params;
        params = {COMPRESS, EXTRACT, INPUT1, INPUT2, OUTPUT1, OUTPUT2};

        bool result = false;
        for (const auto &[key, val] : parameters_) {
            (void) val;
            if (params.find(key) == params.end()) {
                result = true;
                break;
            }
        }

        return result;
    }

    string_view CLI::get_single_existing(const std::vector<string_view> &params) const {
        if (params.empty()) {
            throw std::runtime_error("CLI::get_single_existing: empty vector");
        }

        int32_t count = 0;
        string_view result;
        for (const auto &par : params) {
            if (parameters_.find(par) != parameters_.end()) {
                result = par;
                count++;
            }
        }

        if (count == 1) {
            return result;
        } else if (count > 1) {
            throw CLIException("invalid parameters: ambiguous parameter " +
                                static_cast<std::string>(result));
        } else {
            throw CLIException("invalid parameters: parameter " +
                                static_cast<std::string>(params.front()) +
                                " required");
        }
    }
}