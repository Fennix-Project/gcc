// { dg-options "-std=gnu++0x" }

// 2008-07-03 Chris Fairles <chris.fairles@gmail.com>

// Copyright (C) 2008 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#include <ratio>
#include <testsuite_hooks.h>

#ifdef _GLIBCXX_USE_C99_STDINT_TR1

void
test01()
{
  bool test __attribute__((unused)) = true;

  std::ratio<1,3> r0;
  std::ratio<2,6> r1;  
  std::ratio<2,-6> r2;
  std::ratio<-2,6> r3;

  VERIFY( r0.num == 1 );
  VERIFY( r0.den == 3 );

  VERIFY( r1.num == r0.num );
  VERIFY( r1.den == r0.den );  
  VERIFY( r2.num == -r0.num );
  VERIFY( r2.den == r0.den ); 
  VERIFY( r3.num == -r0.num );
  VERIFY( r3.den == r0.den );  
}

#endif //_GLIBCXX_USE_C99_STDINT_TR1

int main()
{
#ifdef _GLIBCXX_USE_C99_STDINT_TR1
  test01();
#endif //_GLIBCXX_USE_C99_STDINT_TR1
  return 0;
}
