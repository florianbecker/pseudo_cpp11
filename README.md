# pseudo_cpp11
C++11 compatibility layer for old projects.

This will help you to port a C++98 project easily to C++11 and above.

## Usage
```cpp
#include <pseudo_cpp11.hpp>
```

## Keywords for C++98
Some are fake, some are functional, but all are direct compileable with --std=c++11
- explicit
- noexcept
- override/final
- nullptr
- constexpr

## Macros
- NORETURN as [[noreturn]]
- NODISCARD as [[nodiscard]]
- MAYBE_UNUSED as [[maybe_unused]]
- UNUSED as (void) - not explicit C++11, but for compress compiler warnings until the project convertion is done.

## Loop
foreach macro
Example:
```cpp
foreach ( _value, container ) {

  std::cout << "Value: " << ( *_value ) << std::endl;
}
```

## Support
- from Microsoft Visual Studio 2008
- Clang and GCC projects
