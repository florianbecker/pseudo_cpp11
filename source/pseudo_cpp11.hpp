/*
 * Copyright (c) 2021 Florian Becker <fb@vxapps.com> (VX APPS).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

/* Everything before C++11 - C++98 or C++03 */
#if __cplusplus < 201103L

  /* Override keyword fake */
  #define override

  /* Final keyword */
  #if defined(_MSC_VER)
    #if _MSC_VER >= 1600
      #define final sealed
    #else
      #define final
    #endif
  #else
    #define final
  #endif

  /* Explicit Keyword fake */
  #define explicit

  /* nullptr keyword fake */
  #ifndef nullptr
    #define nullptr 0
  #endif

  /* default and delete */
  #define DEFAULT {}
  #define DELETE {}
#else
  /* default and delete */
  #define DEFAULT = default;
  #define DELETE = delete;
#endif

/* range based loop function */
#if defined(_MSC_VER)
#define foreach( value, container ) for each ( value in container )
#else
#define var( v, init ) __typeof( init ) v = ( init )
#define foreach( iterator, container ) for ( var( iterator, ( container ).begin() ); iterator != ( container ).end(); iterator++ )
#endif

/* constexpr is available with C++11 */
/* @note Drop in replacement with C++11 build */
#ifndef __cpp_constexpr
  #define constexpr static const
#endif

/* noexcept keyword is available with C++11 */
/* @note Drop in replacement with C++11 build */
#ifndef __cpp_noexcept_function_type
  #ifdef __GNUC__
    #define noexcept __attribute__((nothrow))
  #elif defined(_MSC_VER)
    #define noexcept __declspec(nothrow)
  #else
    #pragma message("Unsupported compiler for pseudo_cpp11:noexcept");
    #define noexcept
  #endif
#endif

/* [[deprecated]] is available with C++14 */
/* @note Must be searched and replaced, with C++14 build to remove */
/* @todo Replace DEPRECATED with [[deprecated]] */
#if defined __has_cpp_attribute && __has_cpp_attribute(deprecated)
  #define DEPRECATED [[deprecated]]
#else
  #ifdef __GNUC__
    #define DEPRECATED __attribute__((deprecated))
  #elif defined(_MSC_VER)
    #define DEPRECATED __declspec(deprecated)
  #else
    #pragma message("Unsupported compiler for pseudo_cpp11:DEPRECATED");
    #define DEPRECATED
  #endif
#endif

/* [[noreturn]] is available with C++14 */
/* @note Just fake and mostly useless */
/* @note Must be searched and replaced, with C++14 build to remove */
/* @todo Replace NORETURN with [[noreturn]] */
#if defined __has_cpp_attribute && __has_cpp_attribute(noreturn)
  #define NORETURN [[noreturn]]
#else
  #if defined(_MSC_VER)
    #define NORETURN __declspec(noreturn)
  #else
    #define NORETURN
  #endif
#endif

/* [[maybe_usused]] is available with C++17 */
/* Suppress compiler warning for unused */
/* @note Must be searched and replaced, with C++17 build to remove */
/* @todo Replace MAYBE_UNUSED with [[maybe_unused]] */
#if defined __has_cpp_attribute && __has_cpp_attribute(maybe_unused)
  #define MAYBE_UNUSED [[maybe_unused]]
#else
  #ifdef __GNUC__
    #define MAYBE_UNUSED __attribute__((unused))
  #elif defined(_MSC_VER)
    #define MAYBE_UNUSED
  #endif
#endif

/* Not specific C++11, but needed with MAYBE_UNUSED */
/* @todo Remove lines with UNUSED and mark definition with [[maybe_unused]] */
#define UNUSED (void)

/* [[nodiscard]] is available with C++17 */
/* Disregard the return result */
/* @note Just fake */
/* @note Must be searched and replaced, with C++17 build to remove */
/* @todo Replace NODISCARD with [[nodiscard]] */
#if defined __has_cpp_attribute && __has_cpp_attribute(nodiscard)
  #define NODISCARD [[nodiscard]]
#else
  #ifdef __GNUC__
    #define NODISCARD __attribute__((warn_unused_result))
  #else
    #define NODISCARD
  #endif
#endif
