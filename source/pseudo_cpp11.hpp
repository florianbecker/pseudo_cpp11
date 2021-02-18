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
    #define final sealed
  #else
    #define final
  #endif

  /* Explicit Keyword fake */
  #define explicit

  /* TODO: Default operator */

  /* TODO: Delete operator */

  /* nullptr keyword fake */
  #ifndef nullptr
    #define nullptr 0
  #endif
#endif

/* TODO: for range based */

/* TODO: __cpp_decltype_auto */

/* constexpr is available with C++11 */
/* @note Drop in replacement with C++11 build */
#if !(__has_cpp_attribute(__cpp_constexpr))
  #define constexpr static const
#endif

/* noexcept keyword is available with C++11 */
/* @note Drop in replacement with C++11 build */
#if !(__has_cpp_attribute(__cpp_noexcept_function_type))
  #ifdef __GNUC__
    #define noexcept
  #elif defined(_MSC_VER) // __declspec(nothrow)
    #define noexcept
  #endif
#endif

/* [[noreturn]] is available with C++14 */
/* @note Just fake and mostly useless */
/* @note Must be searched and replaced, with C++14 build to remove */
#if __has_cpp_attribute(noreturn)
  #pragma message("Replace NORETURN with [[noreturn]]")
#endif
#define NORETURN

/* [[maybe_usused]] is available with C++17 */
/* Suppress compiler warning for unused */
/* @note Must be searched and replaced, with C++17 build to remove */
#if __has_cpp_attribute(maybe_unused)
  #pragma message("Replace MAYBE_UNUSED with [[maybe_unused]]")
#endif
#define MAYBE_UNUSED (void)

/* [[nodiscard]] is available with C++17 */
/* Disregard the return result */
/* @note Just fake */
/* @note Must be searched and replaced, with C++17 build to remove */
#if __has_cpp_attribute(nodiscard)
  #pragma message("Replace NODISCARD with [[nodiscard]]")
#endif
#define NODISCARD
