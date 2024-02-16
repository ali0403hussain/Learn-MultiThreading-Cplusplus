#include <iostream>
#include <chrono>

auto function = [](int times){
    for(int alter = 0; alter < times; alter++);
};

int main()
{
    std::chrono::milliseconds milisec(1000);
    std::cout << "Duration milliseconds :" <<milisec.count() <<std::endl;
    
    auto start = std::chrono::system_clock::now();
    function(10000);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout <<"Function(1000) consumes time : " << elapsed_seconds.count() << " sec\n"; 

    return 0;
}
 