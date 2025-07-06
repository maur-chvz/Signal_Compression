#include <iostream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <atomic>
#include <csignal>

#include "market_tick.h"

std::atomic<bool>* g_stop_flag = nullptr;

int test() {
    std::setprecision(6);
    float f = 23.45f;
    // Use std::bit_cast to reinterpret the bits of the float as an integer
    int i = std::bit_cast<int>(f); 

    std::cout << "Original float: " << f << std::endl;
    std::cout << "Integer representation of the float's bit pattern: " << i << std::endl;

    std::bitset<32> b(i);
    std::cout << b << '\n';

    uint32_t rawBits = std::bit_cast<uint32_t>(f);
    std::bitset<32> fb(rawBits);
    std::cout << fb << '\n';

    return 0;
}

void signal_handler(int signum) {
    if (g_stop_flag) {
        std::cout << "\nInterrupt signal received\n";
        g_stop_flag->store(true);
    }
}

int main() {
    ThreadSafeQueue<MarketTick> queue;
    
    std::atomic<bool> stop_flag{false};
    g_stop_flag = &stop_flag;
    std::signal(SIGINT, signal_handler);
    
    std::thread market_thread(simulate_market_feed, std::ref(queue), std::ref(stop_flag));

    market_thread.join();
    std::cout << "Shutdown\n";

    return 0;
}