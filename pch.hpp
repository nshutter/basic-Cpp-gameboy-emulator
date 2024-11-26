#ifndef PCH_HPP
#define PCH_HPP
#pragma once

// C++ standard library headers

// General utilities
#include <iostream> // Input/Output streams
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

// String streams
#include <sstream> // String streams
using std::istringstream;
using std::ostringstream;
using std::stringstream;

// Standard exceptions
#include <stdexcept> // Standard exceptions
using std::exception;
using std::logic_error;
using std::runtime_error;

// Memory management
#include <memory> // Smart pointers (unique_ptr, shared_ptr, weak_ptr)
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

// Placement new
#include <new> // Placement new
using std::nothrow;

// Size_t, nullptr, ptrdiff_t
#include <cstddef> // Size_t, nullptr, ptrdiff_t
using std::nullptr_t;
using std::ptrdiff_t;
using std::size_t;

// Containers
#include <vector> // std::vector
using std::vector;

// List
#include <list> // std::list
using std::list;

// Deque
#include <deque> // std::deque
using std::deque;

// Array
#include <array> // std::array
using std::array;

#include <set> // std::set, std::unordered_set
using std::set;

// Map and unordered map
#include <map> // std::map, std::unordered_map
using std::map;

// Algorithms and iterators
#include <algorithm> // Algorithms like sort, find, etc.
using std::copy;
using std::find;
using std::sort;

// Iterators
#include <iterator> // Iterators and iterator utilities
using std::iterator;

// Function objects
#include <functional> // Function objects, bind, function, etc.
using std::bind;
using std::function;

// Strings
#include <string> // std::string, std::wstring, string utilities
using std::string;
using std::wstring;

// Numerics
#include <cmath> // Math functions (sqrt, sin, cos, etc.)
using std::cos;
using std::sin;
using std::sqrt;

// Complex numbers
#include <complex> // Complex numbers
using std::complex;

// Valarray
#include <valarray> // valarray and related utilities
using std::valarray;

// Date and time
#include <chrono> // Time utilities, chrono literals, etc.
using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::time_point;

// Multithreading
#include <thread> // std::thread, thread support
using std::thread;

// Mutex
#include <mutex> // Mutex, locks
using std::lock_guard;
using std::mutex;

// Condition variable
#include <condition_variable> // Condition variable
using std::condition_variable;

// Futures and promises
#include <future> // Futures, promises, async, etc.
using std::async;
using std::future;
using std::promise;

// Atomic operations
#include <atomic> // Atomic operations and types
using std::atomic;

// File system (C++17)
#include <filesystem> // File system operations (requires C++17 or later)
using std::filesystem::path;

// Type traits and utilities
#include <type_traits> // Type traits, type manipulation
using std::enable_if;
using std::is_same;

// Tuple
#include <tuple> // std::tuple, tuple utilities
using std::make_tuple;
using std::tuple;

// Utility functions
#include <utility> // Utility functions (std::move, std::swap, etc.)
using std::move;
using std::swap;

// Numeric limits
#include <limits> // Numeric limits
using std::numeric_limits;

// Random number generation
#include <random> // Random number generation
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

// Base exception class
#include <exception> // Base exception class
using std::exception;

// Locale support
#include <locale> // Locale support
using std::locale;

// Thread support
#include <thread> // Thread support
using std::thread;

#endif // PCH_HPP
