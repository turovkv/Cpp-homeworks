#include <iostream>
#include <fstream>
#include "HuffmanArchiver.hpp"
#include "CLI.hpp"

inline int64_t size_of_infile(std::ifstream &in) {
    in.clear();
    in.seekg(0, std::ios::end);
    return in.tellg();
}

inline int64_t size_of_outfile(std::ofstream &out) {
    out.clear();
    out.seekp(0, std::ios::end);
    return out.tellp();
}

int main(int argc, char* argv[]) {
    try {
        CLI::CLI parser(argc, argv);

        std::ifstream in(parser.get_input_file().data(), std::ios::binary);
        std::ofstream out(parser.get_output_file().data(), std::ios::binary);
        if (parser.get_archiver_mode() == CLI::COMPRESS) {
            int64_t header_size = HuffmanArchiver::HuffmanArchiver().compress(in, out);

            std::cout << size_of_infile(in) << '\n';
            std::cout << size_of_outfile(out) - header_size << '\n';
            std::cout << header_size << '\n';
        } else {
            int64_t header_size = HuffmanArchiver::HuffmanArchiver().extract(in, out);

            std::cout << size_of_infile(in) - header_size << '\n';
            std::cout << size_of_outfile(out) << '\n';
            std::cout << header_size << '\n';
        }

    } catch (CLI::CLIException &e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (...) {
        throw ;
    }
    return 0;
}