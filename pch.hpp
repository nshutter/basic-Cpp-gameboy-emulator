#ifndef PCH_HPP
#define PCH_HPP

// C++ standard library headers

// General utilities
#include <iostream>      // Input/Output streams
#include <iomanip>       // Formatting for I/O
#include <sstream>       // String streams
#include <cassert>       // Assert macros
#include <stdexcept>     // Standard exceptions

// Memory management
#include <memory>        // Smart pointers (unique_ptr, shared_ptr, weak_ptr)
#include <new>           // Placement new
#include <cstdlib>       // Standard library general utilities (malloc, free, etc.)
#include <cstddef>       // Size_t, nullptr, ptrdiff_t

// Containers
#include <vector>        // std::vector
#include <list>          // std::list
#include <deque>         // std::deque
#include <array>         // std::array
#include <set>           // std::set, std::unordered_set
#include <map>           // std::map, std::unordered_map
#include <unordered_map> // std::unordered_map
#include <unordered_set> // std::unordered_set

// Algorithms and iterators
#include <algorithm>     // Algorithms like sort, find, etc.
#include <iterator>      // Iterators and iterator utilities
#include <functional>    // Function objects, bind, function, etc.

// Strings
#include <string>        // std::string, std::wstring, string utilities
#include <cstring>       // C-style string functions (memcpy, strcmp, etc.)
#include <cwchar>        // Wide character functions (wcslen, etc.)

// Numerics
#include <cmath>         // Math functions (sqrt, sin, cos, etc.)
#include <complex>       // Complex numbers
#include <valarray>      // valarray and related utilities

// Date and time
#include <chrono>        // Time utilities, chrono literals, etc.
#include <ctime>         // C-style time handling (ctime, time_t, etc.)

// Multithreading
#include <thread>        // std::thread, thread support
#include <mutex>         // Mutex, locks
#include <condition_variable> // Condition variable
#include <future>        // Futures, promises, async, etc.
#include <atomic>        // Atomic operations and types

// File system (C++17)
#include <filesystem>    // File system operations (requires C++17 or later)

// Type traits and utilities
#include <type_traits>   // Type traits, type manipulation
#include <tuple>         // std::tuple, tuple utilities
#include <utility>       // Utility functions (std::move, std::swap, etc.)
#include <limits>        // Numeric limits

// C++20 and beyond (optional, if your compiler supports it)
#include <span>          // std::span (C++20)
#include <ranges>        // Ranges (C++20)
#include <concepts>      // Concepts (C++20)
#include <coroutine>     // Coroutines (C++20)

// Other utility headers
#include <random>        // Random number generation
#include <exception>     // Base exception class
#include <functional>    // Function pointers, bind, etc.
#include <locale>        // Locale support
#include <thread>        // Thread support

#endif // PCH_HPP
