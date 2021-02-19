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

/* psuedo_cpp11 header */
#include <pseudo_cpp11.hpp>

class Test {

public:
  explicit Test() DEFAULT
  virtual ~Test() DEFAULT

protected:
  virtual void blub() {}
};

class Test2 : Test {

public:
  explicit Test2() : Test() {}

protected:
  void blub() noexcept override {}
};

class Test3 : Test2 {

public:
  explicit Test3() : Test2() {}

protected:
  DEPRECATED void blub() noexcept final {}
};

constexpr int b = 5;

int main() {

  MAYBE_UNUSED int a = 0;
//  UNUSED a;

  std::cout << "C++ Build: " << __cplusplus << std::endl;
  std::cout << "Contexpr: " << b << std::endl;

  /* MAYBE_UNUSED - Will return compile error :) */ int *c = nullptr;
  if ( c == nullptr ) {

    std::cout << "c == nullptr" << std::endl;
  }
  else {

    std::cout << "This should never happen." << std::endl;
  }

//  const int container[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
  std::vector<int> container;
  container.push_back( 0 );
  container.push_back( 1 );
  container.push_back( 1 );
  container.push_back( 2 );
  container.push_back( 3 );
  container.push_back( 5 );
  container.push_back( 8 );
  container.push_back( 13 );
  container.push_back( 21 );
  container.push_back( 34 );
  container.push_back( 55 );
  container.push_back( 89 );
  container.push_back( 144 );

  /* Original in C++98 */
  /* for(std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {

    std::cout << "Value: " << (*it) << std::endl;
  } */

#if defined(_MSC_VER)
  foreach ( const int & _value, container ) {

    std::cout << "Value: " << _value << std::endl;
  }
#else
  foreach ( /* const int & */ _value, container ) {

    std::cout << "Value: " << ( *_value ) << std::endl;
  }
#endif

  /* C++11 */
  /* for ( const int &_value : container ) {

    std::cout << "Value: " << ( *_iterator ) << std::endl;
  } */

  return EXIT_SUCCESS;
}
