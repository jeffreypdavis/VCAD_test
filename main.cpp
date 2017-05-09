/* 
 * Copyright 2017 Jeffrey Davis
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * File:   main.cpp
 * Author: Jeffrey Davis
 */

#include <cstdlib>

#include "Test_2D.h"
#include "Test_3D.h"
#include "Test_2D3D.h"
#include "Test_STL.h"

using namespace std;

void test_2d()
{
    Test_2D test;
    test.test_all();
}

void test_3d()
{
    Test_3D test_3d;
    test_3d.test_all();
}

void test_2d3d()
{
    Test_2D3D test;
    test.test_all();
}

void test_stl()
{
    Test_STL test;
    test.test_all();
}

void test_all()
{
    test_2d();
    test_3d();
    test_2d3d();
    test_stl();
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    test_all();
    return 0;
}

