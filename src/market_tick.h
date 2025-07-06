#ifndef MARKET_TICK_H
#define MARKET_TICK_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <thread>
#include <random>

#include "thread_safe_queue.h"

struct MarketTick {
    std::string symbol;
    double price;
    int size;
    std::string side;
};

MarketTick generate_tick(const std::string& symbol);
void simulate_market_feed(ThreadSafeQueue<MarketTick>& queue, std::atomic<bool>& stop_flag);

#endif
