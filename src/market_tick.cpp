#include "./market_tick.h"

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
void simulate_market_feed() {
    std::vector<std::string> symbols = {"AAPL", "GOOG", "TSLA"};
    
    while (true) {
        for (const auto& sym : symbols) {
            MarketTick tick = generate_tick(sym);
            std::cout << "Symbol: " << tick.symbol
                      << " | Side: " << tick.side
                      << " | Price: " << tick.price
                      << " | Size: " << tick.size << "\n";
        }

        // Simulate ~10 updates per second
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    simulate_market_feed();
    return 0;
}
