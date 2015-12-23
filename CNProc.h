#pragma once

#include <linux/cn_proc.h>

#include <functional>

namespace CNProc {
    bool connect();
    bool subscribe();
    bool process(std::function<void(const struct proc_event&)>&);
    void stop();
}
