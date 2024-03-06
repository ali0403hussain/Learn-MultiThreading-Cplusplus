#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std::literals;

class Vector {
    std::mutex mutex_Vector;
    std::vector<int> vec;
public:
    void push_back(const int& i)
    {
        mutex_Vector.lock();
        vec.push_back(i);
        mutex_Vector.unlock();
    }
    void print()
    {
        mutex_Vector.lock();
        for(auto alter : vec)
            std::cout << alter << ",";
        std::cout<<std::endl;
        mutex_Vector.unlock();
    }
};

void InsertVectorValues(Vector& vec, const int start, const int end)
{
    for(int alter = start; alter <= end; alter++)
    {
        vec.push_back(alter);
    }

}

void PrintVector(Vector& vec)
{
    vec.print();
}
int main()
{
    Vector vec1,vec2,vec3;
    std::thread thrd1(InsertVectorValues, std::ref(vec1), 0, 10); 
    std::thread thrd2(InsertVectorValues, std::ref(vec2), 11, 20);
    std::thread thrd3(InsertVectorValues, std::ref(vec3), 21, 30);

    thrd1.join();
    thrd2.join();
    thrd3.join();

    std::thread thrd4(PrintVector, std::ref(vec1)); 
    std::thread thrd5(PrintVector, std::ref(vec2));
    std::thread thrd6(PrintVector, std::ref(vec3));

    thrd4.join();
    thrd5.join();
    thrd6.join();

    return 0;
}