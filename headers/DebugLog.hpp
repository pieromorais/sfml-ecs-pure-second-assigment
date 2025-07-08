#ifndef DEBUG_LOGGING_HEADERS
#define DEBUG_LOGGING_HEADERS

// creating degub logging messages
#if DEBUG_LOGGING_ENABLED
#include <iostream>
#define LOG(msg) std::cout << "[DEBUG]: " << msg << std::endl
#else 
#define LOG(msg)
#endif

#endif
