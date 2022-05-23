//
// Created by chaos on 2022/5/23.
//

#include "ClassReader.h"
#include <fmt/core.h>
#include <fstream>
#include <iterator>
#include <vector>

namespace CycloneView {


    ClassReader::ClassReader(const char *filePath) {
            this->filePath = filePath;
    }

    ClassReader::~ClassReader() = default;

    ClassInfo ClassReader::read() {
        ClassInfo info{};

        std::ifstream input(this->filePath, std::ios::binary);

        std::vector<char> bytes(
                (std::istreambuf_iterator<char>(input)),
                (std::istreambuf_iterator<char>()));

        input.close();

        this->buf = bytes;

        assert<std::string, 8>();

        return info;
    }

    template<typename T, int L>
    Assertion<T, L> ClassReader::assert() {
        Assertion<T, L> assertion{};

        if constexpr(std::is_same<T, char>()) {
            std::array<char, L> holder{};

            if (pos + L < this->buf.size()) {
                for (int i = 0; i < L; i++, pos++) {
                    holder[i] = this->buf[pos];
                }

                assertion.message = "Ok";
            } else {
                assertion.message = fmt::format("Expected {} bytes but have {} bytes left on buffer", L, this->buf.size() - pos + 1);
            }

            assertion.result = holder;
        }

        return assertion;
    }
} // CycloneView