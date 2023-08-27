#pragma once

#include <chrono>

class StopWatch
{
public:
    constexpr StopWatch() { }

    void start() { _start = std::chrono::system_clock::now(); }
    [[nodiscard]] std::chrono::system_clock::duration stop() { return std::chrono::system_clock::now() - _start; }

    constexpr std::chrono::system_clock::time_point getStart() const { return _start; }

private:
    std::chrono::system_clock::time_point _start;
};