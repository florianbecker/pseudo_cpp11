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

/* stl header */
#include <iostream>
#include <vector>

/* psuedoCPP11 header */
#include <pseudo_cpp11.hpp>

class Test {

public:
  explicit Test() {}
  virtual ~Test() {}

protected:
  virtual void blub() {}
};

class Test2 : Test {

public:
  explicit Test2() : Test() {}

protected:
  void blub() override noexcept {}
};

class Test3 : Test2 {

public:
  explicit Test3() : Test2() {}

protected:
  void blub() final {}
};

constexpr int b = 5;

int main() {

  MAYBE_UNUSED int a = 0;
  UNUSED a;

  std::cout << "C++ Build: " << __cplusplus << std::endl;
  std::cout << "Contexpr: " << b << std::endl;

  MAYBE_UNUSED int *c = nullptr;
  if ( c == nullptr ) {

    std::cout << "c == nullptr" << std::endl;
  }
  else {

    std::cout << "This should never happen." << std::endl;
  }

//  const int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//  std::vector<int> v = { 0, 1, 2, 3, 4, 5 };
/*  int set1v[] = {10, 20, 30, 40};
  std::vector<int> v = {0, 1, 2, 3, 4, 5};

      for (const int& i : v) // access by const reference
          std::cout << i << ' ';
      std::cout << '\n'; */

  return EXIT_SUCCESS;
}
