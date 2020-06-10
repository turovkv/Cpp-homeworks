#pragma once

#include <iosfwd>
#include "Huffman.hpp"
#include "BitStream.hpp"

namespace HuffmanArchiver {
    using namespace Huffman;

    class HuffmanArchiverException : public std::runtime_error {
    public:
        explicit HuffmanArchiverException(std::string_view message);
    };

    class HuffmanArchiver {
    public:
        int64_t compress(std::istream &is, std::ostream &os); //returns size of header
        int64_t extract(std::istream &is, std::ostream &os); //returns size of header

    private:
        std::map<uint8_t, int64_t> get_frequency();
    };

    namespace impl {
        class Compresser {
        private:
            BitStream::iBitStream b_in_;
            BitStream::oBitStream b_out_;

        };
    }
}