//
// Created by chaos on 2022/5/23.
//

#ifndef CYCLONEVIEW_CLASSREADER_H
#define CYCLONEVIEW_CLASSREADER_H

#include "ClassInfo.h"
#include "Assertion.h"
#include <string>
#include <vector>
#include <array>

namespace CycloneView {
    class ClassReader {
    private:
        std::string filePath;
        std::vector<char> buf;
        int pos;
        template<typename T, int L>
        Assertion<T, L> assert();

    public:
        explicit ClassReader(const char* filePath);
        ~ClassReader();

        ClassInfo read();
    };
} // CycloneView

#endif //CYCLONEVIEW_CLASSREADER_H
