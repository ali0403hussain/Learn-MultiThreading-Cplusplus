#include <iostream>
#include <vector>
#include <numeric>                          //For accumulate
#include<algorithm>

void print(std::vector<int>& vec) 
{
    for(auto alter: vec)
        std::cout <<alter << ",";
    std::cout <<std::endl;
}
int main()
{
    std::vector<int> vec1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> vec2 = {10,20,30,40,50,60,70,80,90};

    //Accessing vec1 and vec2 by reference
    auto push_in = [&](int val1, int val2)
    {
        vec1.push_back(val1);
        vec2.push_back(val2);
    };

    push_in(10,100);

    print(vec1);
    print(vec2);

   
    //Accessing vec1 and vec2 by values
    auto Sum = [vec1, vec2](int a)
    {
        int sum = 0;

        if(a == 1)
        {
            sum = std::accumulate(vec1.begin(), vec1.end(), 0);
        }
        else if(a == 2)
        {
            sum = std::accumulate(vec2.begin(), vec2.end(), 0);
        }
        else
            sum = 0;
            
        return sum;
    };

    std::cout << "The sum of vector 1 :" << Sum(1) << std::endl;
    std::cout << "The sum of vector 2 :" << Sum(2) << std::endl;

    //Accessing vec1_cpy by reference and vec1 by value
    std::vector<int> vec1_cpy;
    auto Copy = [&vec1_cpy, vec1]()
    {
        vec1_cpy.assign(vec1.begin(),vec1.end());
    };

    Copy();
    print(vec1_cpy);

    return 0;
}