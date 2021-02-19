# pseudo_cpp11
C++11 compatibility layer for old projects.

This will help you to port a C++98 project easily to C++11 and above.

## Usage
```cpp
#include <pseudo_cpp11.hpp>
```

## Keywords for C++98
Some are fake, some are functional, but all are direct compileable with --std=c++11
- explicit // (only fake)
- noexcept
- override // (only fake)
- final // (only fake)
- nullptr
- constexpr

## Macros
### Keywords
- DEFAULT as = default; // (only fake)
- DELETE as = delete; // (only fake)

### Attributes
- DEPRECATED as [[deprecated]]
- NORETURN as [[noreturn]] *only functional on Visual Studio
- NODISCARD as [[nodiscard]] *only functional on clang and gcc
- MAYBE_UNUSED as [[maybe_unused]] *only functional on clang and gcc
- UNUSED as (void) - not explicit C++11, but to compress compiler warnings until the project convertion is done.

## Loop
foreach macro
Visual Studio example:
```cpp
foreach ( const int &_value, container ) {

  std::cout << "Value: " << _value << std::endl;
}
```

Other example:
```cpp
foreach ( _value, container ) {

  std::cout << "Value: " << ( *_value ) << std::endl;
}
```

## User-defined build variables
Inside cmake/env.cmake you will find some user-defined build variables for particular purposes.

### Debugging
You can log the verbose build output.
```cmake
# Debugging of build steps
set(CMAKE_VERBOSE_MAKEFILE ON)
```

### C++ Standard
You can build the example with C++11 and above standard.
```cmake
# c++ standard - possible: 98, 11, 14, 17
set(CMAKE_CXX_STANDARD 11)
```

## Support
- from Microsoft Visual Studio 2008
- Clang and GCC projects
