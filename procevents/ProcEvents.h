#pragma once

#include <functional>

namespace ProcEvents {
    void process(std::function<void(const int&)>&);
}
