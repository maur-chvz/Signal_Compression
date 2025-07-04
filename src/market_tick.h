#ifndef MARKET_TICK_H
#define MARKET_TICK_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <random>

struct MarketTick {
    std::string symbol;
    double price;
    int size;
    std::string side;
};

MarketTick generate_tick(const std::string& symbol);

#endif
