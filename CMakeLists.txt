cmake_minimum_required(VERSION 3.20)
project(SignalCompression LANGUAGES CXX)

set(SOURCES
    src/signal_compression.cpp
    src/market_tick.cpp
)

set(HEADERS
    src/market_tick.h
    src/thread_safe_queue.h
)

add_executable(SignalCompression ${SOURCES} ${HEADERS})

target_include_directories(SignalCompression PRIVATE src)

target_compile_features(SignalCompression PRIVATE cxx_std_20)

set_target_properties(SignalCompression PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
