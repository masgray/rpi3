#include "tasks.h"

std::atomic<bool> sExitCalled(false);

void SignalCallback(int sig)
{
    sExitCalled = true;
}

Tasks::Tasks()
{
    m_signalActions.sa_handler = SignalCallback;
    sigemptyset(&m_signalActions.sa_mask);
    sigaddset(&m_signalActions.sa_mask, SIGINT);
    sigaddset(&m_signalActions.sa_mask, SIGTERM);
    sigaction(SIGINT, &m_signalActions, 0);
    sigaction(SIGTERM, &m_signalActions, 0);
}

void ThreadFunction(TaskFunction taskFunction)
{
    while(!sExitCalled)
    {
        taskFunction(sExitCalled);
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
