/* 
 * File:   Test_3D.h
 * Author: Jeffrey Davis
 * Version: 1.0
 *
 * Created on February 23, 2016, 2:17 PM
 */

#ifndef TEST_3D_H
#define TEST_3D_H

#include <iostream>
#include <memory>
#include <assert.h>
#include <string>
#include <cstring>
#include <cfloat>
#include <Point_3D.h>
#include <Vector_3D.h>
#include <Facet_3D.h>
#include <Facet_3D.h>
#include <Mesh_3D.h>
#include <Mesh_3D.h>
#include <Intersect_Meshes_3D.h>
#include <Simplify_Mesh_3D.h>
#include <shapes.h>
#include <Valid_Mesh_3D.h>

using namespace std;
using VCAD_lib::is_equal;
using VCAD_lib::Point_3D;
using VCAD_lib::Angle;
using VCAD_lib::cylindrical_point;
using VCAD_lib::spherical_point;
using VCAD_lib::Vector_3D;
using VCAD_lib::cross_product;
using VCAD_lib::dot_product;
using VCAD_lib::angle_between;
using VCAD_lib::orthogonal_projection;
using VCAD_lib::is_pt_on_vector;
using VCAD_lib::intersect_vectors;
using VCAD_lib::Vector_3D_idata;
using VCAD_lib::Facet_3D;
using VCAD_lib::Facet_3D;
using VCAD_lib::is_pt_on_facet_plane;
using VCAD_lib::intersect_line_facet_plane;
using VCAD_lib::Vector_3D_idata;
using VCAD_lib::Mesh_3D;
using VCAD_lib::Mesh_3D;
using VCAD_lib::Simplify_Mesh_3D;
using VCAD_lib::Valid_Mesh_3D;
using VCAD_lib::m_cuboid;
using VCAD_lib::m_cylinder;
using VCAD_lib::m_e_cylinder;
using VCAD_lib::m_sphere;
using VCAD_lib::m_ellipsoid;
using VCAD_lib::Intersect_Meshes_3D;

class Test_3D {
public:
    Test_3D() {}
    void test_all();
    void test_Point_3D();
    void test_Vector_3D();
    void test_is_pt_on_vector_3d();
    void test_intersect_vectors_3d();
    void test_Facet_3D();
    void test_Facet_verify();
    void test_intersect_line_facet_plane();
    void test_point_on_facet_plane();
    void test_facet_contains_point();
    void test_Mesh_3D();
    void test_mesh_contains_point();
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
    void test_intersect_meshes_31();
    void test_intersect_meshes_32();
    void test_intersect_meshes_33();
    void test_intersect_meshes_34();
    void test_intersect_meshes_35();
    void test_intersect_meshes_36();
    void test_intersect_meshes_37();
    void test_intersect_meshes_38();
    void test_intersect_meshes_39();
    void test_intersect_meshes_40();
    void test_intersect_meshes_41();
    void test_intersect_meshes_42();
    void test_intersect_meshes_43();
    void test_intersect_meshes_44();
    void test_intersect_meshes_45();
    void test_intersect_meshes_46();
    void test_intersect_meshes_47();
    void test_intersect_meshes_48();
    void test_intersect_meshes_49();
    void test_intersect_meshes_50();
    void test_intersect_meshes_51();
    void test_intersect_meshes_52();
    void test_intersect_meshes_53();
    void test_intersect_meshes_54();
    void test_intersect_meshes_55();
    void test_intersect_meshes_56();
    void test_intersect_meshes_57();
    void test_mesh_difference_1();
    void test_mesh_difference_2();
    void test_mesh_difference_3();
    void test_mesh_difference_4();
    void test_mesh_difference_5();
    void test_mesh_difference_6();
    void test_mesh_difference_7();
    void test_mesh_intersection_1();
    void test_mesh_intersection_2();
    void test_mesh_intersection_3();
    void test_mesh_intersection_4();
    void test_mesh_intersection_5();
    void test_mesh_intersection_6();
    void test_mesh_intersection_7();
    void test_mesh_merge_1();
    void test_mesh_merge_2();
    void test_mesh_merge_3();
    void test_mesh_merge_4();
    void test_mesh_merge_5();
    void test_mesh_merge_6();
    void test_mesh_merge_7();
    void test_simplify_mesh_1();
    void test_simplify_mesh_2();
    void test_simplify_mesh_3();
    void test_simplify_mesh_4();
    void test_simplify_mesh_5();
    void test_simplify_mesh_6();
    void test_simplify_mesh_7();
    void test_simplify_mesh_8();
    void test_simplify_mesh_9();
    void test_simplify_mesh_10();
    void test_simplify_mesh_11();
    void test_simplify_mesh_12();
    void test_m_cuboid_1();
    void test_m_cuboid_2();
    void test_m_cuboid_3();
    void test_m_cuboid_4();
    void test_m_cylinder_1();
    void test_m_cylinder_2();
    void test_m_cylinder_3();
    void test_m_cylinder_4();
    void test_m_cylinder_5();
    void test_m_cylinder_6();
    void test_m_cylinder_7();
    void test_m_e_cylinder_1();
    void test_m_e_cylinder_2();
    void test_m_e_cylinder_3();
    void test_m_e_cylinder_4();
    void test_m_e_cylinder_5();
    void test_m_e_cylinder_6();
    void test_m_e_cylinder_7();
    void test_m_sphere_1();
    void test_m_sphere_2();
    void test_m_ellipsoid_1();
    void test_m_ellipsoid_2();
    void test_rotate_1();
    void test_rotate_2();
    void test_rotate_3();
    void test_rotate_4();
    void test_rotate_5();
    void test_rotate_6();
    void test_rotate_7();
    void test_rotate_8();
    void test_rotate_9();
    void test_rotate_10();
    void test_rotate_11();
    void test_rotate_12();
    void test_rotate_13();
    void test_rotate_14();
    void test_rotate_15();
    void test_rotate_16();
    void test_scale_1();
    void test_scale_2();
    void test_scale_3();
    void test_scale_4();
    void test_scale_5();
    void test_scale_6();
    void test_translate_1();
    void test_translate_2();
    void test_move_1();
    void test_move_2();
    void test_move_3();
    void test_move_4();
    void test_move_5();
    void test_move_6();
    void test_move_7();
    void test_move_8();
    void test_move_9();
    void test_move_10();
    void test_move_11();
    void test_move_12();
    void test_valid_mesh_1();
    void test_valid_mesh_2();
    void test_valid_mesh_3();
    void test_valid_mesh_4();
    void test_valid_mesh_5();
private:
    static const double precision;
    static const double pi;
    const bool within_round(const double val1, const double val2, const double precision) const;
    const bool mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const;
};

#endif /* TEST_3D_H */

