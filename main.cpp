/* 
 * File:   main.cpp
 * Author: Jeffrey Davis
 * Version: 1.0
 *
 * Created on February 23, 2016, 1:56 PM
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

