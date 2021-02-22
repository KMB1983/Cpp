#include <iostream>
#include <chrono>
#include <array>
#include <memory>

using namespace std;

class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
    Timer(){
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto EndTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << " us  (" << ms << " ms) \n";

    }

};



int main() {

    struct Vector2{
        float x, y;
    };

    {
        std::array<std::shared_ptr<Vector2>, 1000> sharePtrs;
        Timer timer;
        for (size_t i =0; i<sharePtrs.size(); i++){
            sharePtrs[i] = std::make_shared<Vector2>();
        }
    }

    /*
    int val{0};
    {
        Timer timer;
        for (size_t i=0; i<100000; i++){
            val+=2;
        }

    }
    */

    return 0;
}


