#include "sketch.h"
#include "tasks.h"

int main (int argc, char *argv[])
{
    Tasks tasks;
    setup(tasks);
    tasks.WaitForTasksEnds();
    return 0;
}
