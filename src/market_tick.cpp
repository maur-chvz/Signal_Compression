#include "market_tick.h"

// Generate a random tick
MarketTick generate_tick(const std::string& symbol) {
    static std::default_random_engine rng(std::random_device{}());
    static std::uniform_real_distribution<double> price_dist(100.0, 200.0);
    static std::uniform_int_distribution<int> size_dist(10, 1000);
    static std::uniform_int_distribution<int> side_dist(0, 1);

    double price = price_dist(rng);
    int size = size_dist(rng);
    std::string side = side_dist(rng) ? "buy" : "sell";

    return MarketTick{symbol, price, size, side};
}

// Simulate market data feed
void simulate_market_feed(ThreadSafeQueue<MarketTick>& queue, std::atomic<bool>& stop_flag) {
    std::vector<std::string> symbols = {"AAPL", "GOOG", "TSLA"};
    
    while (!stop_flag.load()) {
        for (const auto& sym : symbols) {
            MarketTick tick = generate_tick(sym);

            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::tm* local_time = std::localtime(&now_time);

            std::cout <<  std::put_time(local_time, "%Y-%m-%d %H:%M:%S")
                      << " | " << tick.symbol
                      << " | " << tick.side
                      << " | " << tick.price
                      << " | " << tick.size << "\n";
        }

        // Simulate ~10 updates per second
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Stoping Market\n";
}