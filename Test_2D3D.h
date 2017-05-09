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
 * File:   Test_2D3D.h
 * Author: Jeffrey Davis
 */

#ifndef TEST_2D3D_H
#define TEST_2D3D_H

#include <assert.h>
#include <Point_2D.h>
#include <Point_3D.h>
#include <Vector_2D.h>
#include <Vector_3D.h>
#include <Facet_2D.h>
#include <Facet_3D.h>
#include <Mesh_2D.h>
#include <Mesh_3D.h>
#include <shapes.h>
#include <Intersect_Meshes_2D.h>
#include <Intersect_Meshes_3D.h>

using namespace std;
using VCAD_lib::is_equal;
using VCAD_lib::Point_2D;
using VCAD_lib::Point_3D;
using VCAD_lib::Vector_2D;
using VCAD_lib::Vector_3D;
using VCAD_lib::cross_product;
using VCAD_lib::Facet_2D;
using VCAD_lib::Facet_3D;
using VCAD_lib::Mesh_2D;
using VCAD_lib::Mesh_3D;
using VCAD_lib::m_rectangle;
using VCAD_lib::m_circle;
using VCAD_lib::m_ellipse;
using VCAD_lib::m_cuboid;
using VCAD_lib::m_cylinder;
using VCAD_lib::m_e_cylinder;
using VCAD_lib::m_sphere;
using VCAD_lib::m_ellipsoid;
using VCAD_lib::linear_extrude;
using VCAD_lib::Intersect_Meshes_2D;
using VCAD_lib::Intersect_Meshes_3D;

class Test_2D3D {
public:
    Test_2D3D() {}
    void test_all();
    void test_linear_extrude_1();
    void test_linear_extrude_2();
    void test_linear_extrude_3();
    void test_linear_extrude_4();
    void test_linear_extrude_5();
private:
    static const double precision;
    static const double pi;
    const double mesh_area(const Mesh_2D&) const;
    const double mesh_area(const Mesh_3D&) const;
    const bool within_round(const double val1, const double val2, const double precision) const;
    const bool mesh_contains(const Facet_2D& facet, const Mesh_2D& mesh, const double precision) const;
    const bool mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const;
};

#endif /* TEST_2D3D_H */

