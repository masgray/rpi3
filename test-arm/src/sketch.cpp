#include "sketch.h"
#include "tasks.h"

#include <wiringPi.h>
#include <softPwm.h>

#include <cstdio>
#include <cstdint>
#include <cstdbool>
#include <atomic>

constexpr int LED = 0;

std::atomic<bool> LedOn(false);

void LedLoop(std::atomic<bool>& stop)
{
    int i = 0;
    if (!LedOn)
    {
        softPwmWrite(LED, 0);
        std::this_thread::yield();
        return;
    }

    for (i = 0; i <= 100; ++i)
    {
        softPwmWrite(LED, i);
        if (stop)
            break;
        delay(10);
    }
    if (!stop)
        delay(50);

    for (i = 100; i >= 0; --i)
    {
        softPwmWrite(LED, i);
        if (stop)
            break;
        delay(10);
    }
    if (!stop)
        delay(10);

    if (stop)
        softPwmWrite(LED, 0);
}

void OnOffLoop(std::atomic<bool>& stop)
{
    LedOn = !LedOn;
    for (int i = 1; i < 60; ++i)
    {
        if (stop)
            break;
        delay(100);
    }
}

void setup(Tasks& tasks)
{
    printf("TEST-ARM on Rasberry Pi 3\n");

    wiringPiSetup();

    int major;
    int minor;
    wiringPiVersion (&major, &minor);
    printf("wiringPi version %d.%d\n", major, minor);

    pinMode(LED, OUTPUT);
    softPwmCreate(LED, 0, 100);

    tasks.CreateTask(LedLoop);
    tasks.CreateTask(OnOffLoop);
}
