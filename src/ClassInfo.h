//
// Created by chaos on 2022/5/23.
//

#ifndef CYCLONEVIEW_CLASSINFO_H
#define CYCLONEVIEW_CLASSINFO_H

#include "Assertion.h"

namespace CycloneView {

    class ClassInfo {
    public:
        CycloneView::Assertion<char, 8> magicNumber;

        ClassInfo();
    };

} // CycloneView

#endif //CYCLONEVIEW_CLASSINFO_H
