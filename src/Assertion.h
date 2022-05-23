//
// Created by chaos on 2022/5/23.
//

#ifndef CYCLONEVIEW_ASSERTION_H
#define CYCLONEVIEW_ASSERTION_H

#include <string>
#include <array>

namespace CycloneView {
    template<int L>
    struct Assertion {
        std::array<char, L> result;
        std::string message;
    };
} // CycloneView

#endif //CYCLONEVIEW_ASSERTION_H
