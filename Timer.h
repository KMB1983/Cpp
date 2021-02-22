#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>


class Timer
{
    private:

        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;

    public:
        Timer() {
            m_StartTimePoint = std::chrono::high_resolution_clock::now();
        }


    void Stop(){
        auto EndTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << " us  (" << ms << " ms) \n";
    }


        ~Timer(){
            Stop();
        }


};

#endif // TIMER_H
