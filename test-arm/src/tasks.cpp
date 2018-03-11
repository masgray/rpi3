#include "tasks.h"

void ThreadFunction(TaskFunction taskFunction)
{
    for (;;)
    {
        taskFunction();
    }
}

void Tasks::CreateTask(TaskFunction taskFunction)
{
    m_threads.emplace_back(ThreadFunction, taskFunction);
}

void Tasks::WaitForTasksEnds()
{
    for (auto& th: m_threads)
        th.join();
}
