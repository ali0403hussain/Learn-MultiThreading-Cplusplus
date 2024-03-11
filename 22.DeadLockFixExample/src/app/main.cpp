#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <string>

using namespace std::literals;

constexpr int nforks = 5;
constexpr int nphilosopher = nforks;
std::string names[nphilosopher] = {"A","B","C","D","E"};

//Keep track of how many times a philosopher is able to eat
int mouthfuls[nphilosopher] = {0};

//A philosopher who has not picked up both forks is thinking
constexpr auto think_time = 2s;

//A philosopher has picked up both fork is eating
constexpr auto eat_time = 1s;

//A mutex prevents more than one philosopher picking up the same fork
// A philosopher thread can only pick up a fork if it can lock the corresponsing mutex
std::mutex fork_mutex[nforks];

//Mutex to protect output
std::mutex print_mutex;

//Function to display info about nth philosopher
//Interactions with fork
void print(int n, const std::string& str, int lfork, int rfork)
{
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "Philosopher " << names[n] <<str;
    std::cout << lfork << " and " << rfork << '\n';
}

//The philosopher state
void print(int n, const std::string& str)
{
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "Philosopher " << names[n] <<str << '\n';
}

//Thread which represents a dinning philosopher
void dine(int nphilo)
{
    //Philosopher A has fork 0 on their left
    //and fork 1 on their right
    //Philosopher B has fork 1 on their left
    //and 2 on their right
    //....
    //Philosopher E has fork 4 on their left
    //and fork 0 on their right
    //Each philosopher must pick up their left fork first

    int lfork = nphilo;
    int rfork = (nphilo+1) % nforks;

    //Use hierarchical ordering
    if(lfork > rfork)
    {
        std::swap(lfork, rfork);
    }

    print(nphilo, "\'s forks are ", lfork, rfork);
    print(nphilo, " is thinking...");

    std::this_thread::sleep_for(think_time);

    //Make an attempt to eat
    print(nphilo, "reaches for forks ", lfork, rfork);

    //Try to pick up bothh forks
    std::lock(fork_mutex[lfork], fork_mutex[rfork]);
    print(nphilo, " picks up fork ", lfork , rfork);

    //Secceeded - this philosopher can now eat
    print(nphilo, "is eating...");
    ++mouthfuls[nphilo];

    std::this_thread::sleep_for(eat_time);

    print(nphilo, " puts down fork ", lfork, rfork);
    print(nphilo, " is thinking....");

    fork_mutex[lfork].unlock();
    fork_mutex[rfork].unlock();
    std::this_thread::sleep_for(think_time);
}

int main()
{
    //start a separate thread for each philosopher
    std::vector<std::thread> philos;

    for(int i =0; i < nphilosopher; i++)
    {
        philos.push_back(std::move(std::thread{dine, i}));
    }

    for(auto& philo: philos)
        philo.join();

    //How many times were the philosopher able to eat
    for(int i =0; i < nphilosopher; i++)
    {
        std::cout << "Philosopher " << names[i];
        std::cout << "has " << mouthfuls[i] << " mouthfuls\n";
    }   
    return 0;
}
