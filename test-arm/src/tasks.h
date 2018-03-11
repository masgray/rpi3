#pragma once

#include <thread>
#include <vector>
#include <functional>

using TaskFunction = std::function<void()>;

class Tasks
{
public:
    Tasks() = default;

    void CreateTask(TaskFunction taskFunction);
    void WaitForTasksEnds();

private:
    std::vector<std::thread> m_threads;
};
