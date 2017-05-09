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
 * File:   Test_2D.h
 * Author: Jeffrey Davis
 */

#ifndef TEST_2D_H
#define TEST_2D_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <assert.h>
#include <Point_2D.h>
#include <Vector_2D.h>
#include <Facet_2D.h>
#include <Facet_2D.h>
#include <Mesh_2D.h>
#include <Mesh_2D.h>
#include <Intersect_Meshes_2D.h>
#include <Simplify_Mesh_2D.h>
#include <shapes.h>
#include <Valid_Mesh_2D.h>

using namespace std;
using VCAD_lib::Point_2D;
using VCAD_lib::polar_point;
using VCAD_lib::Vector_2D;
using VCAD_lib::cross_product;
using VCAD_lib::dot_product;
using VCAD_lib::angle_between;
using VCAD_lib::is_pt_on_vector;
using VCAD_lib::Vector_2D_idata;
using VCAD_lib::intersect_vectors;
using VCAD_lib::Facet_2D;
using VCAD_lib::Facet_2D;
using VCAD_lib::Mesh_2D;
using VCAD_lib::Mesh_2D;
using VCAD_lib::Intersect_Meshes_2D;
using VCAD_lib::Simplify_Mesh_2D;
using VCAD_lib::m_rectangle;
using VCAD_lib::m_circle;
using VCAD_lib::m_ellipse;
using VCAD_lib::Valid_Mesh_2D;

class Test_2D {
public:
    Test_2D() {}
    void test_all();
    void test_Point_2D();
    void test_Vector_2D();
    void test_is_pt_on_vector();
    void test_intersect_vector_vector();
    void test_Facet_2D();
    void test_facet_contains_point();
    void test_Mesh_2D();
    void test_intersect_meshes_1();
    void test_intersect_meshes_2();
    void test_intersect_meshes_3();
    void test_intersect_meshes_4();
    void test_intersect_meshes_5();
    void test_intersect_meshes_6();
    void test_intersect_meshes_7();
    void test_intersect_meshes_8();
    void test_intersect_meshes_9();
    void test_intersect_meshes_10();
    void test_intersect_meshes_11();
    void test_intersect_meshes_12();
    void test_intersect_meshes_13();
    void test_intersect_meshes_14();
    void test_intersect_meshes_15();
    void test_intersect_meshes_16();
    void test_intersect_meshes_17();
    void test_intersect_meshes_18();
    void test_intersect_meshes_19();
    void test_intersect_meshes_20();
    void test_intersect_meshes_21();
    void test_intersect_meshes_22();
    void test_intersect_meshes_23();
    void test_intersect_meshes_24();
    void test_intersect_meshes_25();
    void test_intersect_meshes_26();
    void test_intersect_meshes_27();
    void test_intersect_meshes_28();
    void test_intersect_meshes_29();
    void test_intersect_meshes_30();
    void test_simplify_mesh_1();
    void test_simplify_mesh_2();
    void test_simplify_mesh_3();
    void test_simplify_mesh_4();
    void test_simplify_mesh_5();
    void test_simplify_mesh_6();
    void test_simplify_mesh_7();
    void test_simplify_mesh_8();
    void test_simplify_mesh_9();
    void test_m_rectangle_1();
    void test_m_rectangle_2();
    void test_m_rectangle_3();
    void test_m_rectangle_4();
    void test_m_circle_1();
    void test_m_circle_2();
    void test_m_ellipse_1();
    void test_m_ellipse_2();
    void test_m_ellipse_3();
    void test_m_ellipse_4();
    void test_rotate_1();
    void test_rotate_2();
    void test_rotate_3();
    void test_rotate_4();
    void test_scale_1();
    void test_scale_2();
    void test_scale_3();
    void test_scale_4();
    void test_translate_1();
    void test_translate_2();
    void test_move_1();
    void test_move_2();
    void test_move_3();
    void test_mesh_difference_1();
    void test_mesh_difference_2();
    void test_mesh_difference_3();
    void test_mesh_difference_4();
    void test_mesh_difference_5();
    void test_mesh_intersection_1();
    void test_mesh_intersection_2();
    void test_mesh_intersection_3();
    void test_mesh_intersection_4();
    void test_mesh_intersection_5();
    void test_mesh_merge_1();
    void test_mesh_merge_2();
    void test_mesh_merge_3();
    void test_mesh_merge_4();
    void test_mesh_merge_5();
    void test_valid_mesh_1();
    void test_valid_mesh_2();
    void test_valid_mesh_3();
    void test_valid_mesh_4();
private:
    const double precision = 0.0001;
    const double pi = 3.14159265358979;
    const bool within_round(const double val1, const double val2, const double precision) const;
    const bool mesh_contains(const Facet_2D& facet, const Mesh_2D& mesh, const double precision) const;
};

#endif /* TEST_2D_H */

