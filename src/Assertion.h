//
// Created by chaos on 2022/5/23.
//

#ifndef CYCLONEVIEW_ASSERTION_H
#define CYCLONEVIEW_ASSERTION_H

#include <array>

namespace CycloneView {
    template<typename name, int L>
    struct Assertion {
        std::array<name, L> result;
        const char *message;
    };
} // CycloneView

#endif //CYCLONEVIEW_ASSERTION_H
