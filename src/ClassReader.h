//
// Created by chaos on 2022/5/23.
//

#ifndef CYCLONEVIEW_CLASSREADER_H
#define CYCLONEVIEW_CLASSREADER_H

#include "ClassInfo.h"
#include "Assertion.h"
#include "fmt/format.h"
#include <string>
#include <vector>
#include <array>

namespace CycloneView {
    class ClassReader {
    private:
        std::string filePath;
        std::vector<char> buf;
        int pos = 0;

    public:
        explicit ClassReader(const char *filePath);

        ~ClassReader();

        ClassInfo read();

        template<int L>
        Assertion<L> assertLen() {
            Assertion<L> assertion{};
            std::array<char, L> holder{};

            if (pos + L < this->buf.size()) {
                for (int i = 0; i < L; i++, pos++) {
                    holder[i] = this->buf[pos];
                }

                assertion.message = "Ok";
            } else {
                assertion.message = fmt::format("Expected {} bytes but have {} bytes left on buffer", L,
                                                this->buf.size() - pos + 1);
            }

            assertion.result = holder;

            return assertion;
        }
    };
} // CycloneView

#endif //CYCLONEVIEW_CLASSREADER_H
