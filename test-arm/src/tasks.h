#pragma once

#include <signal.h>

#include <thread>
#include <vector>
#include <functional>
#include <atomic>

using TaskFunction = std::function<void(std::atomic<bool>& stop)>;

class Tasks
{
public:
    Tasks();

    void CreateTask(TaskFunction taskFunction);
    void WaitForTasksEnds();

private:
    std::vector<std::thread> m_threads;
    struct sigaction m_signalActions = {};
};
