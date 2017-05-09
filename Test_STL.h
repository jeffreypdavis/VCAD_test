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
 * File:   Test_STL.h
 * Author: Jeffrey Davis
 */

#ifndef TEST_STL_H
#define TEST_STL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <stl.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <Mesh_3D.h>
#include <Facet_3D.h>
#include <Vector_3D.h>
#include <Point_3D.h>
#include <VSCAD_Error.h>
#include <shapes.h>

using namespace std;
using VCAD_lib::STL_Error;
using VCAD_lib::is_equal;
using VCAD_lib::read_stl;
using VCAD_lib::read_stl_bin;
using VCAD_lib::read_stl_bin_cbo;
using VCAD_lib::write_stl;
using VCAD_lib::write_stl_bin;
using VCAD_lib::write_stl_bin_nbo;
using VCAD_lib::write_stl_bin_cbo;
using VCAD_lib::Mesh_3D;
using VCAD_lib::Facet_3D;
using VCAD_lib::Vector_3D;
using VCAD_lib::Point_3D;
using VCAD_lib::VSCAD_Error;
using VCAD_lib::m_cuboid;

class Test_STL {
public:
    Test_STL() {}
    ~Test_STL();
    void test_all();
    void test_read_stl_1();
    void test_read_stl_2();
    void test_read_stl_3();
    void test_read_stl_4();
    void test_read_stl_5();
    void test_read_stl_6();
    void test_read_stl_7();
    void test_read_stl_8();
    void test_read_stl_9();
    void test_read_stl_10();
    void test_read_stl_11();
    void test_read_stl_12();
    void test_read_stl_13();
    void test_read_stl_14();
    void test_read_stl_15();
    void test_read_stl_16();
    void test_read_stl_17();
    void test_read_stl_18();
    void test_read_stl_19();
    void test_read_stl_20();
    void test_read_stl_21();
    void test_read_stl_22();
    void test_read_stl_23();
    void test_read_stl_24();
    void test_read_stl_25();
    void test_read_stl_26();
    void test_read_stl_27();
    void test_read_stl_28();
    void test_read_stl_29();
    void test_read_stl_bin_1();
    void test_read_stl_bin_2();
    void test_read_stl_bin_3();
    void test_read_stl_bin_4();
    void test_read_stl_bin_5();
    void test_read_stl_bin_6();
    void test_read_stl_bin_7();
    void test_read_stl_bin_8();
    void test_read_stl_bin_9();
    void test_read_stl_bin_10();
    void test_read_stl_bin_11();
    void test_write_stl_1();
    void test_write_stl_2();
    void test_write_stl_3();
    void test_write_stl_4();
    void test_write_stl_5();
    void test_write_stl_6();
    void test_write_stl_7();
    void test_write_stl_8();
private:
    static const double precision;
    void create_file(const string& filename, const vector<string>& content);
    void create_bin_file(const string& filename, stringstream& content);
    void swap_float_bytes(stringstream& ofs, const float val);
    const bool within_round(const double val1, const double val2, const double precision) const;
    const bool mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const;
};

#endif /* TEST_STL_H */

