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

        info.magicNumber = assertLen<4>();

        return info;
    }
} // CycloneView