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
 * File:   Test_3D.cpp
 * Author: Jeffrey Davis
 */

#include "Test_3D.h"
#include <cfloat>

const double Test_3D::precision = DBL_EPSILON * 21;//0.0001;
const double Test_3D::pi = 3.14159265358979;

const bool Test_3D::within_round(const double val1, const double val2, const double precision) const
{
        return (fabs(val1 - val2) < precision);
}

const bool Test_3D::mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const
{

    Mesh_3D::const_iterator it = mesh.begin();
    while (it != mesh.end())
    {
        // try to locate the first point
        if (within_round(it->get_point1()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point1()->get_y(), precision) &&
                within_round(it->get_point1()->get_z(), facet.get_point1()->get_z(), precision))
        {
            // try for point2
            if (within_round(it->get_point2()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point2()->get_y(), precision) &&
                within_round(it->get_point2()->get_z(), facet.get_point2()->get_z(), precision))
            {
                // try point3
                if (within_round(it->get_point3()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point3()->get_y(), precision) &&
                within_round(it->get_point3()->get_z(), facet.get_point3()->get_z(), precision))
                    return true;
            }
        }
        else if (within_round(it->get_point2()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point1()->get_y(), precision) &&
                within_round(it->get_point2()->get_z(), facet.get_point1()->get_z(), precision))
        {
            // try for point2
            if (within_round(it->get_point3()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point2()->get_y(), precision) &&
                within_round(it->get_point3()->get_z(), facet.get_point2()->get_z(), precision))
            {
                // try point3
                if (within_round(it->get_point1()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point3()->get_y(), precision) &&
                within_round(it->get_point1()->get_z(), facet.get_point3()->get_z(), precision))
                    return true;
            }
        }
        else if (within_round(it->get_point3()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point1()->get_y(), precision) &&
                within_round(it->get_point3()->get_z(), facet.get_point1()->get_z(), precision))
        {
            // try for point2
            if (within_round(it->get_point1()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point2()->get_y(), precision) &&
                within_round(it->get_point1()->get_z(), facet.get_point2()->get_z(), precision))
            {
                // try point3
                if (within_round(it->get_point2()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point3()->get_y(), precision) &&
                within_round(it->get_point2()->get_z(), facet.get_point3()->get_z(), precision))
                    return true;
            }
        }
        ++it;
    }
    
    return false;
}

void Test_3D::test_all()
{
    cout << "Testing 3D sub-systems\n";
    this->test_Point_3D();
    cout << '.';
    this->test_Vector_3D();
    cout << '.';
    this->test_is_pt_on_vector_3d();
    cout << '.';
    this->test_intersect_vectors_3d();
    cout << '.';
    this->test_Facet_3D();
    cout << '.';
    this->test_point_on_facet_plane();
    cout << '.';
    this->test_intersect_line_facet_plane();
    cout << '.';
    this->test_facet_contains_point();
    cout << '.';
    this->test_Mesh_3D();
    cout << '.';
    this->test_mesh_contains_point();
    cout << '.';
    this->test_intersect_meshes_1();
    cout << '.';
    this->test_intersect_meshes_2();
    cout << '.';
    this->test_intersect_meshes_3();
    cout << '.';
    this->test_intersect_meshes_4();
    cout << '.';
    this->test_intersect_meshes_5();
    cout << '.';
    this->test_intersect_meshes_6();
    cout << '.';
    this->test_intersect_meshes_7();
    cout << '.';
    this->test_intersect_meshes_8();
    cout << '.';
    this->test_intersect_meshes_9();
    cout << '.';
    this->test_intersect_meshes_10();
    cout << '.';
    this->test_intersect_meshes_11();
    cout << '.';
    this->test_intersect_meshes_12();
    cout << '.';
    this->test_intersect_meshes_13();
    cout << '.';
    this->test_intersect_meshes_14();
    cout << '.';
    this->test_intersect_meshes_15();
    cout << '.' << '\n';
    this->test_intersect_meshes_16();
    cout << '.';
    this->test_intersect_meshes_17();
    cout << '.';
    this->test_intersect_meshes_18();
    cout << '.';
    this->test_intersect_meshes_19();
    cout << '.';
    this->test_intersect_meshes_20();
    cout << '.';
    this->test_intersect_meshes_21();
    cout << '.';
    this->test_intersect_meshes_22();
    cout << '.';
    this->test_intersect_meshes_23();
    cout << '.';
    this->test_intersect_meshes_24();
    cout << '.';
    this->test_intersect_meshes_25();
    cout << '.';
    this->test_intersect_meshes_26();
    cout << '.';
    this->test_intersect_meshes_27();
    cout << '.';
    this->test_intersect_meshes_28();
    cout << '.';
    this->test_intersect_meshes_29();
    cout << '.';
    this->test_intersect_meshes_30();
    cout << '.';
    this->test_intersect_meshes_31();
    cout << '.';
    this->test_intersect_meshes_32();
    cout << '.';
    this->test_intersect_meshes_33();
    cout << '.';
    this->test_intersect_meshes_34();
    cout << '.';
    this->test_intersect_meshes_35();
    cout << '.';
    this->test_intersect_meshes_36();
    cout << '.';
    this->test_intersect_meshes_37();
    cout << '.';
    this->test_intersect_meshes_38();
    cout << '.';
    this->test_intersect_meshes_39();
    cout << '.';
    this->test_intersect_meshes_40();
    cout << '.' << '\n';
    this->test_intersect_meshes_41();
    cout << '.';
    this->test_intersect_meshes_42();
    cout << '.';
    this->test_intersect_meshes_43();
    cout << '.';
    this->test_intersect_meshes_44();
    cout << '.';
    this->test_intersect_meshes_45();
    cout << '.';
    this->test_intersect_meshes_46();
    cout << '.';
    this->test_intersect_meshes_47();
    cout << '.';
    this->test_intersect_meshes_48();
    cout << '.';
    this->test_intersect_meshes_49();
    cout << '.';
    this->test_intersect_meshes_50();
    cout << '.';
    this->test_intersect_meshes_51();
    cout << '.';
    this->test_intersect_meshes_52();
    cout << '.';
    this->test_intersect_meshes_53();
    cout << '.';
    this->test_intersect_meshes_54();
    cout << '.';
    this->test_intersect_meshes_55();
    cout << '.';
    this->test_intersect_meshes_56();
    cout << '.';
    this->test_intersect_meshes_57();
    cout << '.';
    this->test_mesh_difference_1();
    cout << '.';
    this->test_mesh_difference_2();
    cout << '.';
    this->test_mesh_difference_3();
    cout << '.';
    this->test_mesh_difference_4();
    cout << '.';
    this->test_mesh_difference_5();
    cout << '.';
    this->test_mesh_difference_6();
    cout << '.';
    this->test_mesh_difference_7();
    cout << '.';
    this->test_mesh_intersection_1();
    cout << '.' << '\n';
    this->test_mesh_intersection_2();
    cout << '.';
    this->test_mesh_intersection_3();
    cout << '.';
    this->test_mesh_intersection_4();
    cout << '.';
    this->test_mesh_intersection_5();
    cout << '.';
    this->test_mesh_intersection_6();
    cout << '.';
    this->test_mesh_intersection_7();
    cout << '.';
    this->test_mesh_merge_1();
    cout << '.';
    this->test_mesh_merge_2();
    cout << '.';
    this->test_mesh_merge_3();
    cout << '.';
    this->test_mesh_merge_4();
    cout << '.';
    this->test_mesh_merge_5();
    cout << '.';
    this->test_mesh_merge_6();
    cout << '.';
    this->test_mesh_merge_7();
    cout << '.';
    this->test_simplify_mesh_1();
    cout << '.';
    this->test_simplify_mesh_2();
    cout << '.';
    this->test_simplify_mesh_3();
    cout << '.';
    this->test_simplify_mesh_4();
    cout << '.';
    this->test_simplify_mesh_5();
    cout << '.';
    this->test_simplify_mesh_6();
    cout << '.';
    this->test_simplify_mesh_7();
    cout << '.';
    this->test_simplify_mesh_8();
    cout << '.';
    this->test_simplify_mesh_9();
    cout << '.';
    this->test_simplify_mesh_10();
    cout << '.';
    this->test_simplify_mesh_11();
    cout << '.';
    this->test_simplify_mesh_12();
    cout << '.' << '\n';
    this->test_m_cuboid_1();
    cout << '.';
    this->test_m_cuboid_2();
    cout << '.';
    this->test_m_cuboid_3();
    cout << '.';
    this->test_m_cuboid_4();
    cout << '.';
    this->test_m_cylinder_1();
    cout << '.';
    this->test_m_cylinder_2();
    cout << '.';
    this->test_m_cylinder_3();
    cout << '.';
    this->test_m_cylinder_4();
    cout << '.';
    this->test_m_cylinder_5();
    cout << '.';
    this->test_m_cylinder_6();
    cout << '.';
    this->test_m_cylinder_7();
    cout << '.';
    this->test_m_e_cylinder_1();
    cout << '.';
    this->test_m_e_cylinder_2();
    cout << '.';
    this->test_m_e_cylinder_3();
    cout << '.';
    this->test_m_e_cylinder_4();
    cout << '.';
    this->test_m_e_cylinder_5();
    cout << '.';
    this->test_m_e_cylinder_6();
    cout << '.';
    this->test_m_e_cylinder_7();
    cout << '.';
    this->test_m_sphere_1();
    cout << '.';
    this->test_m_sphere_2();
    cout << '.';
    this->test_m_ellipsoid_1();
    cout << '.';
    this->test_m_ellipsoid_2();
    cout << '.';
    this->test_rotate_1();
    cout << '.';
    this->test_rotate_2();
    cout << '.';
    this->test_rotate_3();
    cout << '.' << '\n';
    this->test_rotate_4();
    cout << '.';
    this->test_rotate_5();
    cout << '.';
    this->test_rotate_6();
    cout << '.';
    this->test_rotate_7();
    cout << '.';
    this->test_rotate_8();
    cout << '.';
    this->test_rotate_9();
    cout << '.';
    this->test_rotate_10();
    cout << '.';
    this->test_rotate_11();
    cout << '.';
    this->test_rotate_12();
    cout << '.';
    this->test_rotate_13();
    cout << '.';
    this->test_rotate_14();
    cout << '.';
    this->test_rotate_15();
    cout << '.';
    this->test_rotate_16();
    cout << '.';
    this->test_scale_1();
    cout << '.';
    this->test_scale_2();
    cout << '.';
    this->test_scale_3();
    cout << '.';
    this->test_scale_4();
    cout << '.';
    this->test_scale_5();
    cout << '.';
    this->test_scale_6();
    cout << '.';
    this->test_translate_1();
    cout << '.';
    this->test_translate_2();
    cout << '.';
    this->test_move_1();
    cout << '.';
    this->test_move_2();
    cout << '.';
    this->test_move_3();
    cout << '.';
    this->test_move_4();
    cout << '.' << '\n';
    this->test_move_5();
    cout << '.';
    this->test_move_6();
    cout << '.';
    this->test_move_7();
    cout << '.';
    this->test_move_8();
    cout << '.';
    this->test_move_9();
    cout << '.';
    this->test_move_10();
    cout << '.';
    this->test_move_11();
    cout << '.';
    this->test_move_12();
    cout << '.';
    this->test_valid_mesh_1();
    cout << '.';
    this->test_valid_mesh_2();
    cout << '.';
    this->test_valid_mesh_3();
    cout << '.';
    this->test_valid_mesh_4();
    cout << '.';
    this->test_valid_mesh_5();
    cout << '.';
    cout << endl << endl;
}

void Test_3D::test_Point_3D()
{
    Point_3D p(5, 6, 7);
    // test get
    assert(p.get_x() == 5);
    assert(p.get_y() == 6);
    assert(p.get_z() == 7);
    // test r, theta, p, and phi
    p = Point_3D(4,4,4);
    assert(within_round(p.get_r(), 5.65685, 0.0001));
    assert(within_round(p.get_theta(), 0.785398, 0.0001));
    assert(within_round(p.get_p(), 6.9282, 0.0001));
    assert(within_round(p.get_phi(), 0.955317, 0.0001));
    p = Point_3D(4,4,-4);
    assert(within_round(p.get_r(), 5.65685, 0.0001));
    assert(within_round(p.get_theta(), 0.785398, 0.0001));
    assert(within_round(p.get_p(), 6.9282, 0.0001));
    assert(within_round(p.get_phi(), 2.18628, 0.0001));
    // test r, theta, p, and phi with a different origin
    p = Point_3D(0,0,4);
    Point_3D p2(4,4,0);
    assert(within_round(p.get_r(p2), 5.65685, 0.0001));
    assert(within_round(p.get_theta(p2), 3.92699, 0.0001));
    assert(within_round(p.get_p(p2), 6.9282, 0.0001));
    assert(within_round(p.get_phi(p2), 0.955317, 0.0001));
    p2 = Point_3D(4,4,8);
    assert(within_round(p.get_r(p2), 5.65685, 0.0001));
    assert(within_round(p.get_theta(p2), 3.92699, 0.0001));
    assert(within_round(p.get_p(p2), 6.9282, 0.0001));
    assert(within_round(p.get_phi(p2), 2.18628, 0.0001));
    // test translate
    p.translate(5,6,3);
    assert(p.get_x() == 5);
    assert(p.get_y() == 6);
    assert(p.get_z() == 7);
    Vector_3D v(-3, 2, -1);
    p.translate(v);
    assert(p.get_x() == 2);
    assert(p.get_y() == 8);
    assert(p.get_z() == 6);
    // test scale by 2
    p = Point_3D(2,8,6);
    p.scale(2,2,2);
    assert(p.get_x() == 4);
    assert(p.get_y() == 16);
    assert(p.get_z() == 12);
    p.scale(0.5,0.5,0.5);
    assert(p.get_x() == 2);
    assert(p.get_y() == 8);
    assert(p.get_z() == 6);
    p.scale(2, 0.5, 3);
    assert(p.get_x() == 4);
    assert(p.get_y() == 4);
    assert(p.get_z() == 18);
    p.scale(2, 3, 0.5);
    assert(p.get_x() == 8);
    assert(p.get_y() == 12);
    assert(p.get_z() == 9);
    // test rotate 45 degrees in x, y, and z separately
    Angle a(pi / 4, 0,0);
    p = Point_3D(8,8,8);
    p.rotate(a);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 0, 0.0001));
    assert(within_round(p.get_z(), 11.3137, 0.0001));
    a.angle_x = -pi / 4;
    p.rotate(a);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_x = 0;
    a.angle_y = pi / 4;
    p.rotate(a);
    assert(within_round(p.get_x(), 11.3137, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 0, 0.0001));
    a.angle_y = -pi / 4;
    p.rotate(a);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_y = 0;
    a.angle_z = pi / 4;
    p.rotate(a);
    assert(within_round(p.get_x(), 0, 0.0001));
    assert(within_round(p.get_y(), 11.3137, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_z = -pi / 4;
    p.rotate(a);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_z = 0;
    // test rotate 90 degrees about a different origin
    a.angle_x = pi / 2;
    Point_3D o(-2,-2,-2);
    p.rotate(a, o);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), -12, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_x = -pi / 2;
    p.rotate(a, o);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_x = 0;
    a.angle_y = pi / 2;
    p.rotate(a, o);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), -12, 0.0001));
    a.angle_y = -pi / 2;
    p.rotate(a, o);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_y = 0;
    a.angle_z = pi / 2;
    p.rotate(a, o);
    assert(within_round(p.get_x(), -12, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    a.angle_z = -pi / 2;
    p.rotate(a, o);
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    // test multiplication
    p = Point_3D(8,8,8);
    p *= 0.5;
    assert(within_round(p.get_x(), 4, 0.0001));
    assert(within_round(p.get_y(), 4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p *= 2;
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    // test addition
    v = Vector_3D(1,2,-3);
    p += v;
    assert(within_round(p.get_x(), 9, 0.0001));
    assert(within_round(p.get_y(), 10, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    // test subtraction
    p -= v;
    assert(within_round(p.get_x(), 8, 0.0001));
    assert(within_round(p.get_y(), 8, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    // test multiplication
    o = p * 0.5;
    assert(within_round(o.get_x(), 4, 0.0001));
    assert(within_round(o.get_y(), 4, 0.0001));
    assert(within_round(o.get_z(), 4, 0.0001));
    o = p * 2;
    assert(within_round(o.get_x(), 16, 0.0001));
    assert(within_round(o.get_y(), 16, 0.0001));
    assert(within_round(o.get_z(), 16, 0.0001));
    // test addition
    v = Vector_3D(1,2,-3);
    o = p + v;
    assert(within_round(o.get_x(), 9, 0.0001));
    assert(within_round(o.get_y(), 10, 0.0001));
    assert(within_round(o.get_z(), 5, 0.0001));
    // test subtraction
    o = p - v;
    assert(within_round(o.get_x(), 7, 0.0001));
    assert(within_round(o.get_y(), 6, 0.0001));
    assert(within_round(o.get_z(), 11, 0.0001));
    // cylindrical point
    p = cylindrical_point(5, pi / 6, 5);
    assert(within_round(p.get_x(), 4.330127, 0.0001));
    assert(within_round(p.get_y(), 2.5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = cylindrical_point(5, -pi / 6, 5);
    assert(within_round(p.get_x(), 4.330127, 0.0001));
    assert(within_round(p.get_y(), -2.5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    // test cylindrical point from different origin
    p2 = Point_3D(1,2,3);
    p = cylindrical_point(5, pi / 6, 5, p2);
    assert(within_round(p.get_x(), 5.330127, 0.0001));
    assert(within_round(p.get_y(), 4.5, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    p = cylindrical_point(5, -pi / 6, 5, p2);
    assert(within_round(p.get_x(), 5.330127, 0.0001));
    assert(within_round(p.get_y(), -0.5, 0.0001));
    assert(within_round(p.get_z(), 8, 0.0001));
    // spherical point
    p = spherical_point(5, pi / 6, pi / 3);
    assert(within_round(p.get_x(), 3.75, 0.0001));
    assert(within_round(p.get_y(), 2.16506, 0.0001));
    assert(within_round(p.get_z(), 2.5, 0.0001));
    p = spherical_point(5, -pi / 6, 2*pi / 3);
    assert(within_round(p.get_x(), 3.75, 0.0001));
    assert(within_round(p.get_y(), -2.16506, 0.0001));
    assert(within_round(p.get_z(), -2.5, 0.0001));
    // test spherical point from different origin
    p2 = Point_3D(1,2,3);
    p = spherical_point(5, pi / 6, pi / 3, p2);
    assert(within_round(p.get_x(), 4.75, 0.0001));
    assert(within_round(p.get_y(), 4.16506, 0.0001));
    assert(within_round(p.get_z(), 5.5, 0.0001));
    p = spherical_point(5, -pi / 6, 2*pi / 3, p2);
    assert(within_round(p.get_x(), 4.75, 0.0001));
    assert(within_round(p.get_y(), -0.16506, 0.0001));
    assert(within_round(p.get_z(), 0.5, 0.0001));
    // test move
    p = Point_3D(1,0,1);
    p.move_x_pxy(Point_3D(-5,-5,5), Vector_3D(0,1,0), Point_3D(-4,-5,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(1,0,1);
    p.move_x_pxz(Point_3D(-5,-5,5), Vector_3D(0,1,0), Point_3D(-5,-5,4));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(1,0,1);
    p.move_y_pxy(Point_3D(-5,-5,5), Vector_3D(1,0,0), Point_3D(-5,-4,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(1,0,1);
    p.move_y_pyz(Point_3D(-5,-5,5), Vector_3D(1,0,0), Point_3D(-5,-5,4));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(1,0,1);
    p.move_z_pxz(Point_3D(-5,-5,5), Vector_3D(0,0,-1), Point_3D(-5,-4,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(1,0,1);
    p.move_z_pyz(Point_3D(-5,-5,5), Vector_3D(0,0,-1), Point_3D(-4,-5,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -4, 0.0001));
    assert(within_round(p.get_z(), 4, 0.0001));
    p = Point_3D(0,0,0);
    p.move_x_pxy(Point_3D(-5,-5,5), Vector_3D(0,1,0), Point_3D(-4,-5,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = Point_3D(0,0,0);
    p.move_x_pxz(Point_3D(-5,-5,5), Vector_3D(0,1,0), Point_3D(-5,-5,4));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = Point_3D(0,0,0);
    p.move_y_pxy(Point_3D(-5,-5,5), Vector_3D(1,0,0), Point_3D(-5,-4,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = Point_3D(0,0,0);
    p.move_y_pyz(Point_3D(-5,-5,5), Vector_3D(1,0,0), Point_3D(-5,-5,4));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = Point_3D(0,0,0);
    p.move_z_pxz(Point_3D(-5,-5,5), Vector_3D(0,0,-1), Point_3D(-5,-4,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
    p = Point_3D(0,0,0);
    p.move_z_pyz(Point_3D(-5,-5,5), Vector_3D(0,0,-1), Point_3D(-4,-5,5));
    assert(within_round(p.get_x(), -5, 0.0001));
    assert(within_round(p.get_y(), -5, 0.0001));
    assert(within_round(p.get_z(), 5, 0.0001));
//    cout << "p x: " << p.get_x() << " y: " << p.get_y() << " z: " << p.get_z() << "\n";
}

void Test_3D::test_Vector_3D()
{
    Vector_3D v(5,6,7);
    assert(v.get_x() == 5);
    assert(v.get_y() == 6);
    assert(v.get_z() == 7);
    v = Vector_3D(5,5,5);
    assert(within_round(v.length(), 8.660254, 0.0001));
    v.normalize();
    assert(within_round(v.length(), 1, 0.0001));
    assert(within_round(v.get_x(), 0.577350, 0.0001));
    assert(within_round(v.get_y(), 0.577350, 0.0001));
    assert(within_round(v.get_z(), 0.577350, 0.0001));
    // cross product
    v = Vector_3D(5,5,5);
    Vector_3D v2(-1, 1, 1);
    Vector_3D v3 = cross_product(v, v2);
    assert(within_round(v3.get_x(), 0, 0.0001));
    assert(within_round(v3.get_y(), -10, 0.0001));
    assert(within_round(v3.get_z(), 10, 0.0001));
    v = Vector_3D(3, -1, 1);
    v2 = Vector_3D(1, 2, -1);
    v3 = cross_product(v, v2);
    assert(within_round(v3.get_x(), -1, 0.0001));
    assert(within_round(v3.get_y(), 4, 0.0001));
    assert(within_round(v3.get_z(), 7, 0.0001));
    // dot product
    v = Vector_3D(3, 1, -2);
    v2 = Vector_3D(1, -1, 1);
    assert(dot_product(v, v2) == 0);
    v = Vector_3D(2, 1, -1);
    v2 = Vector_3D(0, -2, 3);
    assert(dot_product(v, v2) == -5);
    // angle between
    v = Vector_3D(5, 5, 0);
    v2 = Vector_3D(1, 0, 0);
    assert(within_round(angle_between(v, v2), pi / 4, 0.0001));
    v2 = Vector_3D(0, 1, 0);
    assert(within_round(angle_between(v, v2), pi / 4, 0.0001));
    v2 = Vector_3D(1, 0, 0);
    assert(within_round(angle_between(v, v2), pi / 4, 0.0001));
    v2 = Vector_3D(0, -1, 0);
    assert(within_round(angle_between(v, v2), 3 * pi / 4, 0.0001));
    v2 = Vector_3D(-1, 0, 0);
    assert(within_round(angle_between(v, v2), 3 * pi / 4, 0.0001));
    v2 = Vector_3D(1, -1, 0);
    assert(within_round(angle_between(v, v2), pi / 2, 0.0001));
    v = Vector_3D(5, 5, 5);
    v2 = Vector_3D(1, 1, 1);
    assert(within_round(angle_between(v, v2), 0, 0.0001));
    v2 = Vector_3D(-1, -1, -1);
    assert(within_round(angle_between(v, v2), pi, 0.0001));
    // orthogonal projection
    v = Vector_3D(5, 5, 5);
    v2 = Vector_3D(1, 0, 0);
    v3 = orthogonal_projection(v, v2);
    assert(within_round(v3.get_x(), 5, 0.0001));
    assert(within_round(v3.get_y(), 0, 0.0001));
    assert(within_round(v3.get_z(), 0, 0.0001));
    v2 = Vector_3D(0, 1, 0);
    v3 = orthogonal_projection(v, v2);
    assert(within_round(v3.get_x(), 0, 0.0001));
    assert(within_round(v3.get_y(), 5, 0.0001));
    assert(within_round(v3.get_z(), 0, 0.0001));
    v2 = Vector_3D(0, 0, 1);
    v3 = orthogonal_projection(v, v2);
    assert(within_round(v3.get_x(), 0, 0.0001));
    assert(within_round(v3.get_y(), 0, 0.0001));
    assert(within_round(v3.get_z(), 5, 0.0001));
    // add
    v2 = Vector_3D(1,2,3);
    v += v2;
    assert(within_round(v.get_x(), 6, 0.0001));
    assert(within_round(v.get_y(), 7, 0.0001));
    assert(within_round(v.get_z(), 8, 0.0001));
    v2 = Vector_3D(-1, -2, -3);
    v3 = v + v2;
    assert(within_round(v3.get_x(), 5, 0.0001));
    assert(within_round(v3.get_y(), 5, 0.0001));
    assert(within_round(v3.get_z(), 5, 0.0001));
    // subtract
    v2 = Vector_3D(1,2,3);
    v -= v2;
    assert(within_round(v.get_x(), 5, 0.0001));
    assert(within_round(v.get_y(), 5, 0.0001));
    assert(within_round(v.get_z(), 5, 0.0001));
    v2 = Vector_3D(-1, -2, -3);
    v3 = v - v2;
    assert(within_round(v3.get_x(), 6, 0.0001));
    assert(within_round(v3.get_y(), 7, 0.0001));
    assert(within_round(v3.get_z(), 8, 0.0001));
    // multiply
    v *= 2;
    assert(within_round(v.get_x(), 10, 0.0001));
    assert(within_round(v.get_y(), 10, 0.0001));
    assert(within_round(v.get_z(), 10, 0.0001));
    v3 = v * 0.5;
    assert(within_round(v3.get_x(), 5, 0.0001));
    assert(within_round(v3.get_y(), 5, 0.0001));
    assert(within_round(v3.get_z(), 5, 0.0001));
//    cout << "x: " << v.get_x() << " y: " << v.get_y() << " z: " << v.get_z() << "\n";
}

void Test_3D::test_is_pt_on_vector_3d()
{
//    Vector_3D v(5, 5, 5);
    Point_3D o(2, 1, 0);
    Point_3D ep(7, 6, 5);
    // test origin point
    Point_3D p(2, 1, 0);
    assert(is_pt_on_vector(p, o, ep, precision));
    // test end point
    p = Point_3D(7, 6, 5);
    assert(is_pt_on_vector(p, o, ep, precision));
    // test middle point
    p = Point_3D(4.5, 3.5, 2.5);
    assert(is_pt_on_vector(p, o, ep, precision));
    // test points not on vector
    p = Point_3D(1, 0, 0);
    assert(!is_pt_on_vector(p, o, ep, precision));
    p = Point_3D(8, 7, 6);
    assert(!is_pt_on_vector(p, o, ep, precision));
    p = Point_3D(5, 5, 5);
    assert(!is_pt_on_vector(p, o, ep, precision));
    p = Point_3D(5, 9, -3);
    assert(!is_pt_on_vector(p, o, ep, precision));
}

void Test_3D::test_intersect_vectors_3d()
{
    // test vector
    Point_3D tv_start(2, 1, 1);
    Point_3D tv_end(7, 6, 6);
//    Vector_3D tv_end(5, 5, 5);
    // vector that crosses in the middle
    Point_3D v_start(6, 1, 1);
    Point_3D v_end(1, 6, 6);
    Vector_3D_idata idata;
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, Point_3D(4,3,3), precision));
    // vector crosses at origin
    v_start = Point_3D(4, -1, -1);
    v_end = Point_3D(-1,4,4);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, tv_start, precision));
    // vector crosses at tip of tv
    v_start = Point_3D(9, 4, 4);
    v_end = Point_3D(4,9,9);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, Point_3D(7,6,6), precision));
    // both vectors start at origin
    v_end = Point_3D(-3, 6, 6);
    assert(intersect_vectors(tv_start, tv_end, tv_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, tv_start, precision));
    // vector starts at end point
    v_start = Point_3D(7, 6, 6);
    v_end = Point_3D(4, 9, 9);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_start, precision));
    // test vector
//    tv = Vector_3D(0, 5, 0);
    tv_start = Point_3D(0, 1, 0);
    tv_end = Vector_3D(0, 6, 0);
    // vector in same line does not meet
    v_start = Point_3D(0, 0, 0);
    v_end = Point_3D(0, -5, 0);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    // vector in same line does not meet
    v_start = Point_3D(0, 12, 0);
    v_end = Point_3D(0,7,0);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    // vector in same line meets at endpoint of v1
    v_start = Point_3D(0, 11, 0);
    v_end = Point_3D(0, 6, 0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, tv_end, precision));
    // vector in same line meets at origin of v1
    v_start = Point_3D(0, -2, 0);
    v_end = Point_3D(0, 1, 0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, tv_start, precision));
    // vector meets at tip of v2 and middle v1
    v_start = Point_3D(-3, 1, 0);
    v_end = Point_3D(0, 4, 0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, Point_3D(0,4,0), precision));
    // vectors do not meet
    v_start = Point_3D(-3.1, 1, 0);
    v_end = Point_3D(-0.1, 4, 0);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    // reverse vector could intersect
    tv_start = Point_3D(0.25, 0.75, 0.5);
    tv_end = Point_3D(0, 0, 0);
    v_start = Point_3D(0, 10, 4);
    v_end = Point_3D(5, 0, 0);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    // result is not quite on original vector
    tv_start = Point_3D(4, 3, 0);
    tv_end = Point_3D(10, 0, 0);
    v_start = Point_3D(7, 1, 0);
    v_end = Point_3D(12, 2, 0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, Point_3D(7.71429,1.14286,0), 0.0001));
    tv_start = Point_3D(5, 5, 5);
    tv_end = Point_3D(1, 1, 1);
    v_start = Point_3D(3, 3, 3);
    v_end = Point_3D(0, 0, 0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, v_start, precision));
    assert(is_equal(idata.p2, tv_end, precision));
//    tv = Vector_3D(4, 4, 4);
    tv_start = Point_3D(1, 1, 1);
    tv_end = Point_3D(5, 5, 5);
    v_start = Point_3D(0, 0, 0);
    v_end = Point_3D(3, 3, 3);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, Point_3D(1,1,1), precision));
    assert(is_equal(idata.p2, v_end, precision));
    v_start = Point_3D(5.1, 5.1, 5.1);
    v_end = Point_3D(8.1, 8.1, 8.1);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    v_start = Point_3D(0.5, 0.5, 0.5);
    v_end = Point_3D(7.5, 7.5, 7.5);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, tv_start, precision));
    assert(is_equal(idata.p2, Point_3D(5,5,5), precision));
    v_start = Point_3D(1.1, 1.1, 1.1);
    v_end = Point_3D(3.1, 3.1, 3.1);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, v_start, precision));
    assert(is_equal(idata.p2, v_end, precision));
    v_start = Point_3D(-1, -1, -1);
    v_end = Point_3D(1,1,1);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_end, precision));
    v_start = Point_3D(5, 5, 5);
    v_end = Point_3D(7,7,7);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_start, precision));
    v_start = Point_3D(5.1, 5.1, 5.1);
    v_end = Point_3D(7.1, 7.1, 7.1);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    v_start = Point_3D(-1.1, -1.1, -1.1);
    v_end = Point_3D(0.9, 0.9, 0.9);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    v_start = Point_3D(0, 0, 0);
    v_end = Point_3D(2,2,2);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, tv_start, precision));
    assert(is_equal(idata.p2, v_end, precision));
    v_start = Point_3D(3, 3, 3);
    v_end = Point_3D(5,5,5);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, v_start, precision));
    assert(is_equal(idata.p2, v_end, precision));
    v_start = Point_3D(0.9, 0.9, 0.9);
    v_end = Point_3D(-1.1, -1.1, -1.1);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    v_start = Point_3D(7.1, 7.1, 7.1);
    v_end = Point_3D(5.1, 5.1, 5.1);
    assert(!intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    v_start = Point_3D(7, 7, 7);
    v_end = Point_3D(5,5,5);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_end, precision));
    v_start = Point_3D(1, 1, 1);
    v_end = Point_3D(-1,-1,-1);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_start, precision));
    v_start = Point_3D(2, 2, 2);
    v_end = Point_3D(0,0,0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, tv_start, precision));
    assert(is_equal(idata.p2, v_start, precision));
    v_start = Point_3D(6, 6, 6);
    v_end = Point_3D(4,4,4);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, v_end, precision));
    assert(is_equal(idata.p2, tv_end, precision));
    v_start = Point_3D(0, 0, 0);
    v_end = Point_3D(7, 7, 7);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 2);
    assert(is_equal(idata.p1, tv_start, precision));
    assert(is_equal(idata.p2, tv_end, precision));
    tv_start = Point_3D(0,1,1);
    tv_end = Point_3D(0,-1,-1);
    v_start = Point_3D(0,0,0);
    v_end = Vector_3D(0,10,0);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, v_start, precision));
    tv_start = Point_3D(-1, 0, 3);
    tv_end = Point_3D(1, 0, 3);
    v_start = Point_3D(0, 0, 0);
    v_end = Point_3D(0, 0, 5);
    assert(intersect_vectors(tv_start, tv_end, v_start, v_end, idata, precision));
    assert(idata.num == 1);
    assert(is_equal(idata.p1, Point_3D(0, 0, 3), precision));
//    cout << "RUNNING TEST!!!!!\n";
//    cout << "tv x: " << tv.get_x() << " y: " << tv.get_y() << " z: " << tv.get_z() << "\n";
//    cout << "tvo x: " << tvO.get_x() << " y: " << tvO.get_y() << " z: " << tvO.get_z() << "\n";
//    cout << "v x: " << v.get_x() << " y: " << v.get_y() << " z: " << v.get_z() << "\n";
//    cout << "o x: " << o.get_x() << " y: " << o.get_y() << " z: " << o.get_z() << "\n";
//    cout << "idata num: " << idata.num << "\n";
//    if (idata.num > 0)
//        cout << "p1 x: " << idata.p1.get_x() << " y: " << idata.p1.get_y() << " z: " << idata.p1.get_z() << "\n";
//    if (idata.num == 2)
//        cout << "p2 x: " << idata.p2.get_x() << " y: " << idata.p2.get_y() << " z: " << idata.p2.get_z() << "\n";
}

void Test_3D::test_Facet_3D()
{
    Facet_3D f(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)));
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(5,1,1), precision));
    assert(is_equal(*f.get_point3(), Point_3D(1,1,5), precision));
    Vector_3D unv = f.get_unv();
    assert(unv.get_x() == 0);
    assert(unv.get_y() == -1);
    assert(unv.get_z() == 0);
    f.invert_unv();
    unv = f.get_unv();
    assert(unv.get_x() == 0);
    assert(unv.get_y() == 1);
    assert(unv.get_z() == 0);
    // test swapping points constructor
    f = Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), true);
    unv = f.get_unv();
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(1,1,5), precision));
    assert(is_equal(*f.get_point3(), Point_3D(5,1,1), precision));
    assert(unv.get_x() == 0);
    assert(unv.get_y() == 1);
    assert(unv.get_z() == 0);
    // test constructor with unit normal vector set to zero
    f = Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), Vector_3D(0,0,0));
    unv = f.get_unv();
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(5,1,1), precision));
    assert(is_equal(*f.get_point3(), Point_3D(1,1,5), precision));
    assert(unv.get_x() == 0);
    assert(unv.get_y() == -1);
    assert(unv.get_z() == 0);
    f = Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), Vector_3D(0,0,0), true);
    unv = f.get_unv();
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(1,1,5), precision));
    assert(is_equal(*f.get_point3(), Point_3D(5,1,1), precision));
    assert(is_equal(unv, Vector_3D(0,1,0), precision));
    f = Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), Vector_3D(0,-1,0));
    unv = f.get_unv();
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(5,1,1), precision));
    assert(is_equal(*f.get_point3(), Point_3D(1,1,5), precision));
    assert(unv.get_x() == 0);
    assert(unv.get_y() == -1);
    assert(unv.get_z() == 0);
    f = Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), Vector_3D(0,-1,0));
    unv = f.get_unv();
    assert(is_equal(*f.get_point1(), Point_3D(1,1,1), precision));
    assert(is_equal(*f.get_point2(), Point_3D(5,1,1), precision));
    assert(is_equal(*f.get_point3(), Point_3D(1,1,5), precision));
    assert(unv.get_x() == 0);
    assert(unv.get_y() == -1);
    assert(unv.get_z() == 0);
//    cout << "fp1: x: " << f.get_point1().get_x() << " y: " << f.get_point1().get_y() << " z: " << f.get_point1().get_z() << "\n";
//    cout << "fp2: x: " << f.get_point2().get_x() << " y: " << f.get_point2().get_y() << " z: " << f.get_point2().get_z() << "\n";
//    cout << "fp3: x: " << f.get_point3().get_x() << " y: " << f.get_point3().get_y() << " z: " << f.get_point3().get_z() << "\n";
//    cout << "unv: x: " << unv.get_x() << " y: " << unv.get_y() << " z: " << unv.get_z() << "\n";
}

void Test_3D::test_point_on_facet_plane()
{
    Facet_3D f(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), shared_ptr<Point_3D>(new Point_3D(5,1,1)));
    Point_3D p(0,1,0);
    assert(is_pt_on_facet_plane(p, f, precision));
    p = Point_3D(0,0,0);
    assert(!is_pt_on_facet_plane(p, f, precision));
    p = Point_3D(2,0,2);
    assert(!is_pt_on_facet_plane(p, f, precision));
    p = Point_3D(2,1,2);
    assert(is_pt_on_facet_plane(p, f, precision));
}

void Test_3D::test_intersect_line_facet_plane()
{
    Facet_3D f(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), shared_ptr<Point_3D>(new Point_3D(5,1,1)));
    Point_3D p(0,1,0);
    Vector_3D v(1,0,0);
    Point_3D result(0,0,0); 
    assert(intersect_line_facet_plane(v, p, f, result, precision));
    assert(is_equal(result, p, precision));
    p = Point_3D(2,4,3);
    assert(!intersect_line_facet_plane(v, p, f, result, precision));
    v = Vector_3D(0, -2, -1);
    assert(intersect_line_facet_plane(v, p, f, result, precision));
    assert(is_equal(result, Point_3D(2, 1, 1.5), precision));
    p = Point_3D(-4, -5, -6);
    assert(intersect_line_facet_plane(v, p, f, result, precision));
    assert(is_equal(result, Point_3D(-4, 1, -3), precision));
    v = Vector_3D(0, 0, 0);
    assert(!intersect_line_facet_plane(v, p, f, result, precision));
//    cout << "result x: " << result->get_x() << " y: " << result->get_y() << " z: " << result->get_z() << "\n";
}

void Test_3D::test_facet_contains_point()
{
    Facet_3D f(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,5)), shared_ptr<Point_3D>(new Point_3D(5,1,1)));
    Point_3D p(0,1,0);
    bool pt_on_side(false);
    assert(!f.contains_point(p, pt_on_side, precision));
    // corner points
    p = Point_3D(1,1,1);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    p = Point_3D(1,1,5);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    p = Point_3D(5,1,1);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    // side points
    p = Point_3D(2,1,1);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    p = Point_3D(1,1,3);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    p = Point_3D(3,1,3);
    assert(f.contains_point(p, pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    // inside point
    p = Point_3D(3,2,3);
    assert(!f.contains_point(p, pt_on_side, precision));
    assert(!pt_on_side);
//    f = Facet_3D(Point_3D(-3.33333,37.7124,1.77636e-15), Point_3D(-6.28539,28.1091,-6.66667), Point_3D(-6.66667,29.8142,1.77636e-15));
//    Facet_3D f2(Point_3D(6.66667,29.8142,1.77636e-15), Point_3D(3.1427,35.5556,-6.66667), Point_3D(3.33333,37.7124,1.77636e-15));
//    assert(!f.contains_point(f2.get_inside_point(), precision));
//    assert(!f.contains_point(Point_3D(4.95234,33.2241,-1.66667), precision));
//    f = Facet_3D(Point_3D(4, 1, 1), Point_3D(0.5, 1, 1), Point_3D(6, 7, 7));
//    f2 = Facet_3D(Point_3D(4.56522,5.43478,5.43478), Point_3D(5,5,5), Point_3D(1,1,1));
//    assert(f.contains_point(f2.get_inside_point(), precision));
//    f = Facet_3D(Point_3D(0, 0, 0), Point_3D(5, 5, 5), Point_3D(0, 10, 10));
//    f2 = Facet_3D(Point_3D(0.5, 1, 1), Point_3D(4.56522, 5.43478, 5.43478), Point_3D(1, 1, 1));
//    assert(f.contains_point(f2.get_inside_point(), precision));
}

void Test_3D::test_Mesh_3D()
{
    // test constructors
    Mesh_3D mesh;
    assert(mesh.get_precision() == DBL_EPSILON * 21);
    assert(mesh.size() == 0);
    mesh = Mesh_3D(DBL_EPSILON * 6);
    assert(mesh.get_precision() == DBL_EPSILON * 6);
    assert(mesh.size() == 0);
    // test add facet, size
    Facet_3D facet(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0)));
    mesh.push_back(facet);
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), facet, precision));
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0)));
    mesh.push_back(facet1);
    assert(mesh.size() == 2);
    assert(is_equal(*(++mesh.begin()), facet1, precision));
    // test iterators
    Mesh_3D::const_iterator iter = mesh.begin();
    assert(is_equal(*iter, facet, precision));
    ++iter;
    assert(is_equal(*iter, facet1, precision));
    ++iter;
    assert(iter == mesh.end());
    // test rotate x_axis
    Angle angle(pi/4,0,0);
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*(*iter).get_point1(), Point_3D(0,0,0), precision));
    assert(within_round((*iter).get_point2()->get_x(), 5, 0.0001));
    assert(within_round((*iter).get_point2()->get_y(), 3.53553, 0.0001));
    assert(within_round((*iter).get_point2()->get_z(), 3.53553, 0.0001));
    assert(is_equal(*(*iter++).get_point3(), Point_3D(10,0,0), precision));
    assert(is_equal(*(*iter).get_point1(), Point_3D(0,0,0), precision));
    assert(within_round((*iter).get_point2()->get_x(), 5, 0.0001));
    assert(within_round((*iter).get_point2()->get_y(), 3.53553, 0.0001));
    assert(within_round((*iter).get_point2()->get_z(), 3.53553, 0.0001));
    assert(within_round((*iter).get_point3()->get_x(), 0, 0.0001));
    assert(within_round((*iter).get_point3()->get_y(), 7.07107, 0.0001));
    assert(within_round((*iter).get_point3()->get_z(), 7.07107, 0.0001));
    angle.angle_x = -pi / 4;
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test rotate y_Axis
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    angle.angle_x = 0;
    angle.angle_y = pi / 4;
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 3.53553, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), -3.53553, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 7.07107, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 0, 0.0001));
    assert(within_round(iter++->get_point3()->get_z(), -7.07107, 0.0001));
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 3.53553, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), -3.53553, 0.0001));
    assert(is_equal(*(iter->get_point3()), Point_3D(0,10,0), precision));
    angle.angle_y = -pi / 4;
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test rotate z_axis
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    angle.angle_y = 0;
    angle.angle_z = pi / 4;
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 6.21725e-15, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 7.07107, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 7.07107, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 7.07107, 0.0001));
    assert(within_round(iter++->get_point3()->get_z(), 0, 0.0001));
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 6.21725e-15, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 7.07107, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), -7.07107, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 7.07107, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 0, 0.0001));
    angle.angle_z = -pi / 4;
    mesh.rotate(angle);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test rotate x_axis about a different origin
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    angle.angle_z = 0;
    angle.angle_x = pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 3.53553, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 3.53553, 0.0001));
    assert(is_equal(*(iter++->get_point3()), Point_3D(10,0,0), precision));
    assert(is_equal(*(iter->get_point1()), Point_3D(0,0,0), precision));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 3.53553, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 3.53553, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 7.07107, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 7.07107, 0.0001));
    angle.angle_x = -pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test rotate y_Axis about a different origin
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    angle.angle_x = 0;
    angle.angle_y = pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(within_round(iter->get_point1()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 7.07107, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 6.46447, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 3.53553, 0.0001));
    assert(is_equal(*(iter++->get_point3()), Point_3D(10,0,0), precision));
    assert(within_round(iter->get_point1()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 7.07107, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 6.46447, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 3.53553, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 7.07107, 0.0001));
    angle.angle_y = -pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(within_round(iter->get_point1()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 0, 0.0001));
    assert(within_round(iter++->get_point3()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 0, 0.0001));
    // test rotate z_axis about a different origin
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    angle.angle_y = 0;
    angle.angle_z = pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(within_round(iter->get_point1()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), -7.07107, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 0, 0.0001));
    assert(within_round(iter++->get_point3()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), -7.07107, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 2.92893, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), -4.14214, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 0, 0.0001));
    angle.angle_z = -pi / 4;
    mesh.rotate(angle, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(within_round(iter->get_point1()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 0, 0.0001));
    assert(within_round(iter++->get_point3()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_y(), 0, 0.0001));
    assert(within_round(iter->get_point1()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point2()->get_x(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_y(), 5, 0.0001));
    assert(within_round(iter->get_point2()->get_z(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_x(), 0, 0.0001));
    assert(within_round(iter->get_point3()->get_y(), 10, 0.0001));
    assert(within_round(iter->get_point3()->get_z(), 0, 0.0001));
    // test scale
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    mesh.scale(2,0.5,2);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10, 2.5, 0)), shared_ptr<Point_3D>(new Point_3D(20, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10, 2.5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 5, 0))), precision));
    mesh.scale(0.5,2,0.5);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test scale about a different origin
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    mesh.scale(2,0.5,2, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)), shared_ptr<Point_3D>(new Point_3D(0, 2.5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)), shared_ptr<Point_3D>(new Point_3D(0, 2.5, 0)), shared_ptr<Point_3D>(new Point_3D(-10, 5, 0))), precision));
    mesh.scale(0.5,2,0.5, Point_3D(10,0,0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test translate
    mesh = Mesh_3D();
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10, 0))));
    mesh.translate(5,7,-3);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(15, 7, -3))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(5, 17, -3))), precision));
    mesh.translate(Vector_3D(-5,-7,3));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test +=
    mesh += Vector_3D(5,7,-3);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(15, 7, -3))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(5, 17, -3))), precision));
    mesh += Vector_3D(-5,-7,3);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test -=
    mesh -= Vector_3D(-5,-7,3);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(15, 7, -3))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7,-3)), shared_ptr<Point_3D>(new Point_3D(10, 12, -3)), shared_ptr<Point_3D>(new Point_3D(5, 17, -3))), precision));
    mesh -= Vector_3D(5,7,-3);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
    // test *=
    mesh *= 2;
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10, 10, 0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), precision));
    mesh *= 0.5;
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0))), precision));
//    int count = 0;
//    cout << "\n";
//    for (iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "] p1(x: " << iter->get_point1()->get_x() <<
//                " y: " << iter->get_point1()->get_y() << " z: " <<
//                iter->get_point1()->get_z() << ") p2(x: " <<
//                iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() <<
//                " z: " << iter->get_point2()->get_z() << ") p3(x: " << 
//                iter->get_point3()->get_x() << " y: " << iter->get_point3()->get_y() << 
//                " z: " << iter->get_point3()->get_z() << ")\n";
//    }
}

void Test_3D::test_mesh_contains_point()
{
    // generate test mesh
    Mesh_3D mesh;
    // end1
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,15)), shared_ptr<Point_3D>(new Point_3D(0,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)), shared_ptr<Point_3D>(new Point_3D(0,10,15)), shared_ptr<Point_3D>(new Point_3D(0,10,0))));
    // end2
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,20)), shared_ptr<Point_3D>(new Point_3D(20,0,20))));
    // side1
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(0,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(5,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(10,0,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(10,0,20)), shared_ptr<Point_3D>(new Point_3D(5,0,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,15)), shared_ptr<Point_3D>(new Point_3D(10,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,20)), shared_ptr<Point_3D>(new Point_3D(15,0,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,15)), shared_ptr<Point_3D>(new Point_3D(20,0,20)), shared_ptr<Point_3D>(new Point_3D(15,0,20))));
    // side2
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,15)), shared_ptr<Point_3D>(new Point_3D(10,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,0)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(10,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(10,10,20)), shared_ptr<Point_3D>(new Point_3D(10,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(10,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,20)), shared_ptr<Point_3D>(new Point_3D(20,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,0)), shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(20,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(20,10,20))));
    // bottom
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(5,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,10,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(15,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(15,10,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))));
    // top
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)), shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(0,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(5,0,20)), shared_ptr<Point_3D>(new Point_3D(5,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,15)), shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,20)), shared_ptr<Point_3D>(new Point_3D(10,0,20)), shared_ptr<Point_3D>(new Point_3D(10,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,20)), shared_ptr<Point_3D>(new Point_3D(10,10,20)), shared_ptr<Point_3D>(new Point_3D(5,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(10,10,15)), shared_ptr<Point_3D>(new Point_3D(10,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(10,10,20)), shared_ptr<Point_3D>(new Point_3D(10,0,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(15,0,15)), shared_ptr<Point_3D>(new Point_3D(15,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,15)), shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(10,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,15)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,15)), shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,15))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(20,0,20)), shared_ptr<Point_3D>(new Point_3D(20,10,20))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(20,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20))));
    
    // test points outside
    bool pt_on_surface(false);
    Point_3D p(-1,4,4);
    assert(!mesh_contains_point(mesh, p, pt_on_surface));
//    p = Point_3D(12.5,5,21);
//    assert(!mesh_contains_point(mesh, p, pt_on_surface));
//    p = Point_3D(2.5,5,16);
//    assert(!mesh_contains_point(mesh, p, pt_on_surface));
//    p = Point_3D(7.5,5,20.5);
//    assert(!mesh_contains_point(mesh, p, pt_on_surface));
//    // corner points
//    p = Point_3D(0,0,0);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(pt_on_surface);
//    pt_on_surface = false;
//    p = Point_3D(15,10,20);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(pt_on_surface);
//    pt_on_surface = false;
//    // points on sides
//    p = Point_3D(0, 5, 5);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(pt_on_surface);
//    pt_on_surface = false;
//    p = Point_3D(6, 5, 0);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(pt_on_surface);
//    pt_on_surface = false;
//    // points inside
//    p = Point_3D(1, 1, 1);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(!pt_on_surface);
//    pt_on_surface = false;
//    p = Point_3D(6, 9, 16);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(!pt_on_surface);
//    pt_on_surface = false;
//    p = Point_3D(16, 2, 18);
//    assert(mesh_contains_point(mesh, p, pt_on_surface));
//    assert(!pt_on_surface);
//    pt_on_surface = false;
}

void Test_3D::test_simplify_mesh_1()
{
    // no simplification
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1,7,7))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,7,7)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(8,9,9))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(!simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1,7,7))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,7,7)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(8,9,9))), mesh, precision));
}

void Test_3D::test_simplify_mesh_2()
{
    // no simplification
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(!simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), mesh, precision));
}

void Test_3D::test_simplify_mesh_3()
{
    // reverse intersect_mesh_mesh_5
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))),  mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
}

void Test_3D::test_simplify_mesh_4()
{
    // reverse intersect_mesh_mesh_7
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.25,4.75,4.75)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5.25,4.75,4.75)), shared_ptr<Point_3D>(new Point_3D(4,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.25,4.75,4.75)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(4,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(1,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(5.5,5.5,5.5)), shared_ptr<Point_3D>(new Point_3D(6,7,7))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(6,7,7))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5.5,5.5,5.5)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.5,5.5,5.5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(6,7,7))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), mesh, precision));
}

void Test_3D::test_simplify_mesh_5()
{
    // reverse intersect_mesh_mesh_9
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), mesh, precision));
}

void Test_3D::test_simplify_mesh_6()
{
    // reverse intersect_facet_facet_6
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1.33333,3)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), precision));
}

void Test_3D::test_simplify_mesh_7()
{
    // reverse intersect_facet_facet_7
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,10,0))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), precision));
}

void Test_3D::test_simplify_mesh_8()
{
    // reverse intersect_facet_facet_32
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,1,2))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,2)), shared_ptr<Point_3D>(new Point_3D(0,0,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,1,2))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,2))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), precision));
}

void Test_3D::test_simplify_mesh_9()
{
    // reverse intersect_mesh_mesh_12
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1,2,2))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3,4,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4,5,5)), shared_ptr<Point_3D>(new Point_3D(3.6,4.6,4.6))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.8125,4.375,4.375)), shared_ptr<Point_3D>(new Point_3D(3.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(4,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(4,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.8125,4.375,4.375)), shared_ptr<Point_3D>(new Point_3D(4,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3.6,4.6,4.6))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(3.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(2.8125,4.375,4.375))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.8125,4.375,4.375)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(2.8125,4.375,4.375)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
}

void Test_3D::test_simplify_mesh_10()
{
    // two planes with some extra points between them
    Mesh_3D mesh;
    // plane 1
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(1,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(3,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(4,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))));
    // plane 2
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(1,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(2,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(4,0,0))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
}

void Test_3D::test_simplify_mesh_11()
{
    // two planes with some extra points between them - 3 planes for part
    Mesh_3D mesh;
    // plane 1
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(1,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(3,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(4,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))));
    // plane 2
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(1,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(2,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(2,0,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,5)))); // different plane
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,5)))); // different plane
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(4,0,5)), shared_ptr<Point_3D>(new Point_3D(4,0,0))));
    

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 10);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(3,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(2,0,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,5)), shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,5))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(4,0,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,0,0)), shared_ptr<Point_3D>(new Point_3D(4,0,5)), shared_ptr<Point_3D>(new Point_3D(4,0,0))), mesh, precision));
}

void Test_3D::test_simplify_mesh_12()
{
    // two planes with same unit normal vector - 1 internal point & external
    // point in each plane
    Mesh_3D mesh;
    // plane 1
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(1,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0)), shared_ptr<Point_3D>(new Point_3D(3,1,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0)), shared_ptr<Point_3D>(new Point_3D(4,4,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,4,0)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0))));
    // plane 2
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0.001)), shared_ptr<Point_3D>(new Point_3D(0,5,0.001)), shared_ptr<Point_3D>(new Point_3D(1,0,0.001))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0.001)), shared_ptr<Point_3D>(new Point_3D(0,5,0.001)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0.001))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,0.001)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0.001)), shared_ptr<Point_3D>(new Point_3D(2,0,0.001))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,0,0.001)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0.001)), shared_ptr<Point_3D>(new Point_3D(3,1,0.001))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0.001)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0.001)), shared_ptr<Point_3D>(new Point_3D(4,4,0.001))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,4,0.001)), shared_ptr<Point_3D>(new Point_3D(1.5,2.5,0.001)), shared_ptr<Point_3D>(new Point_3D(0,5,0.001))));

    Simplify_Mesh_3D simplify_mesh;
    
    assert(simplify_mesh(mesh));
//    cout << "\n";
//    int count = 0;
//    for (Mesh2_3D::const_iterator it = mesh.begin(); it != mesh.end(); ++it)
//    {
//        cout << "mesh[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " z: " << it->get_point1()->get_z() << " p2 x: " << 
//                it->get_point2()->get_x() << " y: " << it->get_point2()->get_y() << " z: " << 
//                it->get_point2()->get_z() << " p3 x: " << it->get_point3()->get_x() << " y: " << 
//                it->get_point3()->get_y() << " z: " << it->get_point3()->get_z() << "\n";
//    }
    assert(mesh.size() == 6);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(4,4,0))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0.001)), shared_ptr<Point_3D>(new Point_3D(2,0,0.001)), shared_ptr<Point_3D>(new Point_3D(0,5,0.001))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,1,0.001)), shared_ptr<Point_3D>(new Point_3D(0,5,0.001)), shared_ptr<Point_3D>(new Point_3D(4,4,0.001))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0.001)), shared_ptr<Point_3D>(new Point_3D(2,0,0.001)), shared_ptr<Point_3D>(new Point_3D(0,0,0.001))), mesh, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(2,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), mesh, precision));
}

void Test_3D::test_m_cuboid_1()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,30);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(0,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
}

void Test_3D::test_m_cuboid_2()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,30,true);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(-5,10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,-15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,-15)), shared_ptr<Point_3D>(new Point_3D(5,-10,-15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(-5,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,15)), shared_ptr<Point_3D>(new Point_3D(5,-10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(-5,-10,15)), shared_ptr<Point_3D>(new Point_3D(-5,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(-5,10,15)), shared_ptr<Point_3D>(new Point_3D(-5,10,-15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,-10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,-10,15)), shared_ptr<Point_3D>(new Point_3D(-5,-10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,-10,-15)), shared_ptr<Point_3D>(new Point_3D(5,-10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,10,-15)), shared_ptr<Point_3D>(new Point_3D(-5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,10,-15)), shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,-15))), shape, precision));
}

void Test_3D::test_m_cuboid_3()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,30,false,Point_3D(5,10,15));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,30,15)), shared_ptr<Point_3D>(new Point_3D(15,30,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(15,30,15)), shared_ptr<Point_3D>(new Point_3D(15,10,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,45)), shared_ptr<Point_3D>(new Point_3D(15,30,45)), shared_ptr<Point_3D>(new Point_3D(5,30,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,45)), shared_ptr<Point_3D>(new Point_3D(15,10,45)), shared_ptr<Point_3D>(new Point_3D(15,30,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,10,45)), shared_ptr<Point_3D>(new Point_3D(5,30,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(5,30,45)), shared_ptr<Point_3D>(new Point_3D(5,30,15))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(15,30,45)), shared_ptr<Point_3D>(new Point_3D(15,10,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(15,30,15)), shared_ptr<Point_3D>(new Point_3D(15,30,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,45)), shared_ptr<Point_3D>(new Point_3D(5,10,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,15)), shared_ptr<Point_3D>(new Point_3D(15,10,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,15)), shared_ptr<Point_3D>(new Point_3D(5,30,45)), shared_ptr<Point_3D>(new Point_3D(15,30,45))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,15)), shared_ptr<Point_3D>(new Point_3D(15,30,45)), shared_ptr<Point_3D>(new Point_3D(15,30,15))), shape, precision));
}

void Test_3D::test_m_cuboid_4()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,30,true,Point_3D(5,10,15));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << (*it)->get_point1().get_x() << " y: " <<
//                (*it)->get_point1().get_y() << " z: " << (*it)->get_point1().get_z() << " p2 x: " << 
//                (*it)->get_point2().get_x() << " y: " << (*it)->get_point2().get_y() << " z: " << 
//                (*it)->get_point2().get_z() << " p3 x: " << (*it)->get_point3().get_x() << " y: " << 
//                (*it)->get_point3().get_y() << " z: " << (*it)->get_point3().get_z() << "\n";
//    }
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(0,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
}

void Test_3D::test_m_cylinder_1()
{
    Mesh_3D shape;
    m_cylinder(shape,10,20,30,3);
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(20,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,0)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,0)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,0)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,0)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_2()
{
    Mesh_3D shape;
    m_cylinder(shape,10,20,30,3,false,Point_3D(10,20,30));
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60)),shared_ptr<Point_3D>(new Point_3D(30,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,40,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(10,40,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,0,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(10,0,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_3()
{
    Mesh_3D shape;
    m_cylinder(shape,10,20,30,3,true);
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,15)),shared_ptr<Point_3D>(new Point_3D(20,0,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,15)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,15)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,-15)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,15)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,15)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,-15)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,15)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,-15)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,15)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,-15)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,15)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,15)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,-15)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,-15)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,-15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,15)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,15)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,15)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,-15)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,15)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,15)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,-15)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,15)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,-15)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,15)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,-15)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,15)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,15)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,-15)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,-15)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(20,0,15)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,15)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,-15))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_4()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,30,3);
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(20,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(20,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,30))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_5()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,30,3,false,Point_3D(10,20,30));
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60)),shared_ptr<Point_3D>(new Point_3D(30,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,40,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(10,40,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,0,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(10,0,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(30,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,60))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_6()
{
    Mesh_3D shape;
    m_cylinder(shape,20,0,30,3);
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,10,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(10,17.3205,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,0)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,10,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,0)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-20,1.13311e-14,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,0)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-17.3205,-10,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,-17.3205,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,0)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,0)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(10,-17.3205,0)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(17.3205,-10,0)),shared_ptr<Point_3D>(new Point_3D(20,0,0))), shape, 0.0001));
}

void Test_3D::test_m_cylinder_7()
{
    Mesh_3D shape;
    m_cylinder(shape,20,0,30,3,false,Point_3D(10,20,30));
//    cout << "\n";
//    cout << "polyhedron(points=[";
//    bool write_comma(false);
//    for (Mesh_3D::const_point_iterator it = shape.point_begin(); it != shape.point_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    write_comma = false;
//    for (Mesh_3D::const_facet_iterator it = shape.facet_begin(); it != shape.facet_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << it->get_p1_index() << ',' << it->get_p2_index() << ',' << it->get_p3_index() << ']';
//    }
//    cout << "], convexity = 4);\n";
//    Mesh_3D::const_iterator iter(shape.begin());
//    while (iter != shape.end())
//    {
//        cout << "    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(" << 
//                iter->get_point1()->get_x() << "," << iter->get_point1()->get_y() << "," <<
//                iter->get_point1()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << "," << iter->get_point2()->get_y() << "," <<
//                iter->get_point2()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point3()->get_x() << "," << iter->get_point3()->get_y() << "," <<
//                iter->get_point3()->get_z() << "))), shape, 0.0001));\n";
//        ++iter;
//    }
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,30,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(10,40,30)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(20,37.3205,30)),shared_ptr<Point_3D>(new Point_3D(10,40,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,30)),shared_ptr<Point_3D>(new Point_3D(10,40,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(10,40,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,30)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(3.55271e-15,37.3205,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,30,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,30)),shared_ptr<Point_3D>(new Point_3D(-10,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,30)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(-7.32051,10,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-15,2.67949,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(20,2.67949,30)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(27.3205,10,30)),shared_ptr<Point_3D>(new Point_3D(30,20,30))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_1()
{
    Mesh_3D shape;
    m_e_cylinder(shape,20,20,10,10,30,3);
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,0)),shared_ptr<Point_3D>(new Point_3D(20,0,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)),shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,0))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_2()
{
    Mesh_3D shape;
    m_e_cylinder(shape,20,20,10,10,30,3,false,Point_3D(10,20,30));
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(-3.33333,34.9071,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(0,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,5.09288,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,34.9071,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,38.8562,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,5.09288,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,34.9071,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,34.9071,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,38.8562,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,5.09288,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,5.09288,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(10,40,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,1.14382,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(10,30,60)),shared_ptr<Point_3D>(new Point_3D(10,40,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(10,10,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(10,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,40,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,38.8562,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,40,30)),shared_ptr<Point_3D>(new Point_3D(10,30,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,40,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,38.8562,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,34.9071,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,5.09288,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,1.14382,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6667,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6667,38.8562,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(23.3333,34.9071,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6667,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6667,1.14382,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,5.09288,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,34.9071,30)),shared_ptr<Point_3D>(new Point_3D(30,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,20,30)),shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,5.09288,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(23.3333,34.9071,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(20,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(23.3333,5.09288,30))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_3()
{
    Mesh_3D shape;
    m_e_cylinder(shape,20,20,10,10,30,3,true);
    assert(shape.size() == 44);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,15)),shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,15)),shared_ptr<Point_3D>(new Point_3D(-10,0,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-13.3333,-14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,-15)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,15)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,-15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,-15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,20,-15)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,-15)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,15)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.77636e-15,-20,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-18.8562,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(20,0,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,-15)),shared_ptr<Point_3D>(new Point_3D(20,0,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,-15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,-15)),shared_ptr<Point_3D>(new Point_3D(13.3333,14.9071,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,-15)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,15)),shared_ptr<Point_3D>(new Point_3D(13.3333,-14.9071,-15))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_4()
{
    Mesh_3D shape;
    m_e_cylinder(shape,0,0,10,10,30,3);
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,30)),shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,30))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_5()
{
    Mesh_3D shape;
    m_e_cylinder(shape,0,0,10,10,30,3,false,Point_3D(10,20,30));
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(0,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,10,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(10,30,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(10,30,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(10,10,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,60)),shared_ptr<Point_3D>(new Point_3D(20,20,60))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,30)),shared_ptr<Point_3D>(new Point_3D(20,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,60))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_6()
{
    Mesh_3D shape;
    m_e_cylinder(shape,10,10,0,0,30,3);
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,0)),shared_ptr<Point_3D>(new Point_3D(-10,0,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,0)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,0)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,0)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, 0.0001));
}

void Test_3D::test_m_e_cylinder_7()
{
    Mesh_3D shape;
    m_e_cylinder(shape,10,10,0,0,30,3,false,Point_3D(10,20,30));
//    cout << "\n";
//    cout << "polyhedron(points=[";
//    bool write_comma(false);
//    for (Mesh_3D::const_point_iterator it = shape.point_begin(); it != shape.point_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    write_comma = false;
//    for (Mesh_3D::const_facet_iterator it = shape.facet_begin(); it != shape.facet_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << it->get_p1_index() << ',' << it->get_p2_index() << ',' << it->get_p3_index() << ']';
//    }
//    cout << "], convexity = 4);\n";
//    Mesh_3D::const_iterator iter(shape.begin());
//    while (iter != shape.end())
//    {
//        cout << "    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(" << 
//                iter->get_point1()->get_x() << "," << iter->get_point1()->get_y() << "," <<
//                iter->get_point1()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << "," << iter->get_point2()->get_y() << "," <<
//                iter->get_point2()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point3()->get_x() << "," << iter->get_point3()->get_y() << "," <<
//                iter->get_point3()->get_z() << "))), shape, 0.0001));\n";
//        ++iter;
//    }
    assert(shape.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,30)),shared_ptr<Point_3D>(new Point_3D(3.33333,27.4536,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(3.33333,12.5464,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(6.66667,29.4281,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.5719,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,30)),shared_ptr<Point_3D>(new Point_3D(13.3333,29.4281,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(13.3333,10.5719,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,30)),shared_ptr<Point_3D>(new Point_3D(20,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(16.6667,27.4536,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,60)),shared_ptr<Point_3D>(new Point_3D(16.6667,12.5464,30)),shared_ptr<Point_3D>(new Point_3D(20,20,30))), shape, 0.0001));
}

void Test_3D::test_m_sphere_1()
{
    Mesh_3D shape;
    m_sphere(shape,10,3);
    assert(shape.size() == 120);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(5,0,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(5,0,8.66025)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)),shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)),shared_ptr<Point_3D>(new Point_3D(5,0,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(5,0,-8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(5,0,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,8.66025)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,5)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(6.12323e-16,10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(5.30288e-16,8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(3.06162e-16,5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,5)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-5,8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,8.66025)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5)),shared_ptr<Point_3D>(new Point_3D(-7.5,4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,8.66025)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,5)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-10,5.66554e-15,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,4.9065e-15,-5)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-5,2.83277e-15,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(-4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,8.66025)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,5)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-1.83697e-15,-10,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-1.59086e-15,-8.66025,-5)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(-9.18485e-16,-5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,5)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(5,-8.66025,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-7.5,-5)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,-8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(2.5,-4.33013,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(5,0,8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,8.66025)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,8.66025)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(8.66025,-5,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,6.12323e-16)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)),shared_ptr<Point_3D>(new Point_3D(7.5,-4.33013,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,-8.66025)),shared_ptr<Point_3D>(new Point_3D(5,0,-8.66025))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(5,0,-8.66025)),shared_ptr<Point_3D>(new Point_3D(4.33013,-2.5,-8.66025))), shape, 0.0001));
}

void Test_3D::test_m_sphere_2()
{
    Mesh_3D shape;
    m_sphere(shape,10,3,Point_3D(10,20,30));
//    cout << "\n";
//    cout << "polyhedron(points=[";
//    bool write_comma(false);
//    for (Mesh_3D::const_point_iterator it = shape.point_begin(); it != shape.point_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    write_comma = false;
//    for (Mesh_3D::const_facet_iterator it = shape.facet_begin(); it != shape.facet_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << it->get_p1_index() << ',' << it->get_p2_index() << ',' << it->get_p3_index() << ']';
//    }
//    cout << "], convexity = 4);\n";
//    Mesh_3D::const_iterator iter(shape.begin());
//    while (iter != shape.end())
//    {
//        cout << "    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(" << 
//                iter->get_point1()->get_x() << "," << iter->get_point1()->get_y() << "," <<
//                iter->get_point1()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << "," << iter->get_point2()->get_y() << "," <<
//                iter->get_point2()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point3()->get_x() << "," << iter->get_point3()->get_y() << "," <<
//                iter->get_point3()->get_z() << "))), shape, 0.0001));\n";
//        ++iter;
//    }
    assert(shape.size() == 120);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(15,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(15,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,35)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,35)),shared_ptr<Point_3D>(new Point_3D(20,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,25)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,25)),shared_ptr<Point_3D>(new Point_3D(15,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(15,20,21.3397)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(15,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,25,30)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25)),shared_ptr<Point_3D>(new Point_3D(17.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,21.3397)),shared_ptr<Point_3D>(new Point_3D(14.3301,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,25,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,25,38.6603)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,25,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,28.6603,35)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,35)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,28.6603,35)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(15,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,28.6603,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,27.5,25)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,28.6603,25)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,21.3397)),shared_ptr<Point_3D>(new Point_3D(10,25,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(10,25,21.3397)),shared_ptr<Point_3D>(new Point_3D(12.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(10,25,38.6603)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,25,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,35)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,35)),shared_ptr<Point_3D>(new Point_3D(10,30,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,30,30)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25)),shared_ptr<Point_3D>(new Point_3D(10,28.6603,25)),shared_ptr<Point_3D>(new Point_3D(10,25,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25)),shared_ptr<Point_3D>(new Point_3D(10,25,21.3397)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,21.3397)),shared_ptr<Point_3D>(new Point_3D(10,25,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,35)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(5,28.6603,30)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,27.5,25)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,21.3397)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(7.5,24.3301,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(5,20,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,20,35)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,20,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,25,30)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,20,25)),shared_ptr<Point_3D>(new Point_3D(2.5,24.3301,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,20,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(5,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(5,20,21.3397)),shared_ptr<Point_3D>(new Point_3D(5.66987,22.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(5,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(5,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,35)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,35)),shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(0,20,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,25)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(1.33975,20,25)),shared_ptr<Point_3D>(new Point_3D(5,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(5,20,21.3397)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(5,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(1.33975,15,30)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25)),shared_ptr<Point_3D>(new Point_3D(2.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,21.3397)),shared_ptr<Point_3D>(new Point_3D(5.66987,17.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,15,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,15,38.6603)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,15,38.6603)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,35)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,35)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,35)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(5,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,25)),shared_ptr<Point_3D>(new Point_3D(5.66987,12.5,25)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,25)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,21.3397)),shared_ptr<Point_3D>(new Point_3D(10,15,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(10,15,21.3397)),shared_ptr<Point_3D>(new Point_3D(7.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(10,15,38.6603)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,15,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,35)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,35)),shared_ptr<Point_3D>(new Point_3D(10,10,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,10,30)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25)),shared_ptr<Point_3D>(new Point_3D(10,11.3397,25)),shared_ptr<Point_3D>(new Point_3D(10,15,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25)),shared_ptr<Point_3D>(new Point_3D(10,15,21.3397)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,21.3397)),shared_ptr<Point_3D>(new Point_3D(10,15,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,35)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(15,11.3397,30)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,12.5,25)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,21.3397)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(12.5,15.6699,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,40)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(15,20,38.6603))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,38.6603)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,20,38.6603)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,35))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,20,35)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,20,35)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(20,20,30))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(18.6603,15,30)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(18.6603,20,25))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,20,25)),shared_ptr<Point_3D>(new Point_3D(17.5,15.6699,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(18.6603,20,25)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,21.3397)),shared_ptr<Point_3D>(new Point_3D(15,20,21.3397))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,20)),shared_ptr<Point_3D>(new Point_3D(15,20,21.3397)),shared_ptr<Point_3D>(new Point_3D(14.3301,17.5,21.3397))), shape, 0.0001));
}

void Test_3D::test_m_ellipsoid_1()
{
    Mesh_3D shape;
    m_ellipsoid(shape,10,10,10,3);
    assert(shape.size() == 120);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,7.45356,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-7.45356,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,7.45356,-6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-7.45356,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-10)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,-6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,7.45356,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-7.45356,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,7.45356,-6.66667)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,7.45356,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-7.45356,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-7.45356,-6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,-6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,-6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,-6.66667)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,-6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,-3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,-3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,-3.33333)),shared_ptr<Point_3D>(new Point_3D(9.42809,0,-3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-6.66667,7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(-3.33333,9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,10,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-10,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(3.33333,9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.33333,-9.42809,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(6.66667,7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.66667,-7.45356,8.88178e-16)),shared_ptr<Point_3D>(new Point_3D(10,0,8.88178e-16))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-6.28539,7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(-3.1427,8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(-3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(0,7.45356,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(0,9.42809,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,-7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,-9.42809,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(3.1427,8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(3.1427,-8.88889,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333)),shared_ptr<Point_3D>(new Point_3D(6.28539,7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(6.28539,-7.02728,3.33333)),shared_ptr<Point_3D>(new Point_3D(9.42809,0,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(-4.96904,5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(0,7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(-2.48452,7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(-2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,-7.45356,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,7.45356,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(0,-7.45356,6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(2.48452,7.02728,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(2.48452,-7.02728,6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667)),shared_ptr<Point_3D>(new Point_3D(4.96904,5.55556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(4.96904,-5.55556,6.66667)),shared_ptr<Point_3D>(new Point_3D(7.45356,0,6.66667))), shape, 0.0001));
}

void Test_3D::test_m_ellipsoid_2()
{
    Mesh_3D shape;
    m_ellipsoid(shape,20,40,10,3,Point_3D(20,40,10));
//    cout << "\n";
//    cout << "polyhedron(points=[";
//    bool write_comma(false);
//    for (Mesh_3D::const_point_iterator it = shape.point_begin(); it != shape.point_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    write_comma = false;
//    for (Mesh_3D::const_facet_iterator it = shape.facet_begin(); it != shape.facet_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << it->get_p1_index() << ',' << it->get_p2_index() << ',' << it->get_p3_index() << ']';
//    }
//    cout << "], convexity = 4);\n";
//    Mesh_3D::const_iterator iter(shape.begin());
//    while (iter != shape.end())
//    {
//        cout << "    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(" << 
//                iter->get_point1()->get_x() << "," << iter->get_point1()->get_y() << "," <<
//                iter->get_point1()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << "," << iter->get_point2()->get_y() << "," <<
//                iter->get_point2()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point3()->get_x() << "," << iter->get_point3()->get_y() << "," <<
//                iter->get_point3()->get_z() << "))), shape, 0.0001));\n";
//        ++iter;
//    }
    assert(shape.size() == 120);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,3.33333)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,3.33333)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,3.33333)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,3.33333)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,3.33333)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,3.33333)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,0)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,3.33333)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,3.33333)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,3.33333)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,3.33333)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,3.33333)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,3.33333)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,3.33333)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,3.33333)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,3.33333)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,3.33333)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,3.33333)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,3.33333)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,3.33333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(0,40,10)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,80,10)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,80,10)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)),shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,80,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(20,0,10)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,6.66667)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667)),shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,6.66667)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(40,40,10)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667)),shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(40,40,10)),shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(40,40,10)),shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(40,40,10)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,6.66667)),shared_ptr<Point_3D>(new Point_3D(38.8562,40,6.66667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(0,40,10)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(0,40,10)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(6.66667,69.8142,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(6.66667,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,80,10)),shared_ptr<Point_3D>(new Point_3D(13.3333,77.7124,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.3333,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(20,0,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,80,10)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(20,80,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,0,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,0,10)),shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(26.6667,77.7124,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.6667,2.28764,10)),shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(40,40,10)),shared_ptr<Point_3D>(new Point_3D(33.3333,69.8142,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(33.3333,10.1858,10)),shared_ptr<Point_3D>(new Point_3D(40,40,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(1.14382,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(7.42921,68.1091,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(7.42921,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,69.8142,16.6667)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,69.8142,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333)),shared_ptr<Point_3D>(new Point_3D(13.7146,75.5556,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,10.1858,16.6667)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,10.1858,16.6667)),shared_ptr<Point_3D>(new Point_3D(13.7146,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(20,77.7124,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,2.28764,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(26.2854,75.5556,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(26.2854,4.44444,13.3333)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333)),shared_ptr<Point_3D>(new Point_3D(32.5708,68.1091,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(32.5708,11.8909,13.3333)),shared_ptr<Point_3D>(new Point_3D(38.8562,40,13.3333))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(5.09288,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(10.0619,62.2222,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(10.0619,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,16.6667)),shared_ptr<Point_3D>(new Point_3D(15.031,68.1091,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(15.031,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,16.6667)),shared_ptr<Point_3D>(new Point_3D(20,69.8142,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(20,10.1858,16.6667)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,16.6667)),shared_ptr<Point_3D>(new Point_3D(24.969,68.1091,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(24.969,11.8909,16.6667)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667)),shared_ptr<Point_3D>(new Point_3D(29.9381,62.2222,16.6667))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,40,20)),shared_ptr<Point_3D>(new Point_3D(29.9381,17.7778,16.6667)),shared_ptr<Point_3D>(new Point_3D(34.9071,40,16.6667))), shape, 0.0001));
}

void Test_3D::test_rotate_1()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(pi / 6,0,0);
    shape.rotate(angle);
    assert(shape.size() == 12);
    Mesh_3D::const_iterator iter(shape.begin());
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,17.3205,10)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,10)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641)), shared_ptr<Point_3D>(new Point_3D(0,-2.67949,44.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,-20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,-20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,-2.67949,44.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,-2.67949,44.641)), shared_ptr<Point_3D>(new Point_3D(0,17.3205,10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641)), shared_ptr<Point_3D>(new Point_3D(10,-20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,10)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,-20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,17.3205,10)), shared_ptr<Point_3D>(new Point_3D(0,-2.67949,44.641)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,17.3205,10)), shared_ptr<Point_3D>(new Point_3D(10,-2.67949,44.641)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,10))), shape, 0.0001));
}

void Test_3D::test_rotate_2()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(-pi / 6,0,0);
    shape.rotate(angle);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,17.3205,-10)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,-10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,-10)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641)), shared_ptr<Point_3D>(new Point_3D(0,37.3205,24.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,20,34.641)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,37.3205,24.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,37.3205,24.641)), shared_ptr<Point_3D>(new Point_3D(0,17.3205,-10))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641)), shared_ptr<Point_3D>(new Point_3D(10,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,-10)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,17.3205,-10)), shared_ptr<Point_3D>(new Point_3D(0,37.3205,24.641)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,17.3205,-10)), shared_ptr<Point_3D>(new Point_3D(10,37.3205,24.641)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,-10))), shape, 0.0001));
}

void Test_3D::test_rotate_3()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,pi / 6,0);
    shape.rotate(angle);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,-5)), shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641)), shared_ptr<Point_3D>(new Point_3D(20,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(28.6603,0,29.641)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(20,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(20,20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641)), shared_ptr<Point_3D>(new Point_3D(28.6603,0,29.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,-5)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(28.6603,0,29.641)), shared_ptr<Point_3D>(new Point_3D(20,0,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,0,-5)), shared_ptr<Point_3D>(new Point_3D(28.6603,0,29.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(20,20,34.641)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(28.6603,20,29.641)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,-5))), shape, 0.0001));
}

void Test_3D::test_rotate_4()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,-pi / 6,0);
    shape.rotate(angle);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,5)), shared_ptr<Point_3D>(new Point_3D(8.66025,0,5))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641)), shared_ptr<Point_3D>(new Point_3D(-20,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(-11.3397,0,39.641)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,34.641)), shared_ptr<Point_3D>(new Point_3D(-20,20,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,20,34.641)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641)), shared_ptr<Point_3D>(new Point_3D(-11.3397,0,39.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,5)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-11.3397,0,39.641)), shared_ptr<Point_3D>(new Point_3D(-20,0,34.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,0,5)), shared_ptr<Point_3D>(new Point_3D(-11.3397,0,39.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(-20,20,34.641)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(-11.3397,20,39.641)), shared_ptr<Point_3D>(new Point_3D(8.66025,20,5))), shape, 0.0001));
}

void Test_3D::test_rotate_5()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,0,pi / 6);
    shape.rotate(angle);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,40)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,40)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,40)), shared_ptr<Point_3D>(new Point_3D(0,0,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,5,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(-10,17.3205,40)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,40)), shared_ptr<Point_3D>(new Point_3D(-1.33975,22.3205,0))), shape, 0.0001));
}

void Test_3D::test_rotate_6()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,0,-pi / 6);
    shape.rotate(angle);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,40)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,40)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,40)), shared_ptr<Point_3D>(new Point_3D(0,0,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,0)), shared_ptr<Point_3D>(new Point_3D(8.66025,-5,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(10,17.3205,40)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,17.3205,0)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,40)), shared_ptr<Point_3D>(new Point_3D(18.6603,12.3205,0))), shape, 0.0001));
}

void Test_3D::test_rotate_7()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(pi / 6,0,0);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,7.67949))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,-2.32051))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(0,-8.66025,32.3205)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,42.3205)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,7.67949))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,32.3205)), shared_ptr<Point_3D>(new Point_3D(0,-8.66025,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,28.6603,7.67949)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,28.6603,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,7.67949))), shape, 0.0001));
}

void Test_3D::test_rotate_8()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(-pi / 6,0,0);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,-2.32051))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,7.67949))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,11.3397,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,42.3205)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(0,11.3397,42.3205)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,32.3205)), shared_ptr<Point_3D>(new Point_3D(0,8.66025,-2.32051))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,42.3205)), shared_ptr<Point_3D>(new Point_3D(0,11.3397,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,-8.66025,7.67949)), shared_ptr<Point_3D>(new Point_3D(10,11.3397,42.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,8.66025,-2.32051)), shared_ptr<Point_3D>(new Point_3D(0,28.6603,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,8.66025,-2.32051)), shared_ptr<Point_3D>(new Point_3D(10,28.6603,32.3205)), shared_ptr<Point_3D>(new Point_3D(10,8.66025,-2.32051))), shape, 0.0001));
}

void Test_3D::test_rotate_9()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,pi / 6,0);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,27.6795)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,22.6795))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,22.6795)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,22.6795))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,62.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,62.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,62.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,0,57.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(16.6987,0,62.3205)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,62.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,62.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,27.6795))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.35898,0,22.6795)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,0,57.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.35898,0,22.6795)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,22.6795)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(25.359,0,57.3205)), shared_ptr<Point_3D>(new Point_3D(16.6987,0,62.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,27.6795)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,22.6795)), shared_ptr<Point_3D>(new Point_3D(25.359,0,57.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,20,27.6795)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,62.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,20,27.6795)), shared_ptr<Point_3D>(new Point_3D(25.359,20,57.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,22.6795))), shape, 0.0001));
}

void Test_3D::test_rotate_10()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,-pi / 6,0);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,-22.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,-17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,-17.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,0,-17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,12.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,12.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.30127,0,12.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,17.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,0,12.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,12.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,12.3205)), shared_ptr<Point_3D>(new Point_3D(16.6987,20,-22.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(25.359,0,-17.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(25.359,0,-17.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,-17.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,17.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,0,12.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,0,-22.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,0,-17.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,0,17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,20,-22.3205)), shared_ptr<Point_3D>(new Point_3D(-3.30127,20,12.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(16.6987,20,-22.3205)), shared_ptr<Point_3D>(new Point_3D(5.35898,20,17.3205)), shared_ptr<Point_3D>(new Point_3D(25.359,20,-17.3205))), shape, 0.0001));
}

void Test_3D::test_rotate_11()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,0,pi / 6);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,0)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,40)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,40)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,40)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,40)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,40)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,40)), shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,-23.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,-18.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,0)), shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,40)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,-6.33975,0)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,40)), shared_ptr<Point_3D>(new Point_3D(10.359,-1.33975,0))), shape, 0.0001));
}

void Test_3D::test_rotate_12()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    Angle angle(0,0,-pi / 6);
    shape.rotate(angle, Point_3D(50,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,0)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,40)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,40)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,40)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,40)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,40)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,40)), shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.69873,26.3397,0)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,0)), shared_ptr<Point_3D>(new Point_3D(10.359,21.3397,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,0)), shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,40)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.6987,43.6603,0)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,40)), shared_ptr<Point_3D>(new Point_3D(20.359,38.6603,0))), shape, 0.0001));
}

void Test_3D::test_rotate_13()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.rotate(pi / 6, Vector_3D(1,0,1), Point_3D(-10,0,-10));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094)), shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916)), shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094))), shape, 0.0001));
}

void Test_3D::test_rotate_14()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.rotate(-pi / 6, Vector_3D(1,0,1), Point_3D(-10,0,-10));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119)), shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494)), shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119))), shape, 0.0001));
}

void Test_3D::test_rotate_15()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.rotate(pi / 6, Vector_3D(1,0,1), Point_3D(10,0,10));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094)), shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916)), shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(2.67949,-14.1421,37.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.33013,3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(12.0096,-10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(-4.39158,3.17837,44.3916)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.07107,17.3205,7.07107)), shared_ptr<Point_3D>(new Point_3D(4.93855,6.71391,45.0614)), shared_ptr<Point_3D>(new Point_3D(2.25906,20.856,7.74094))), shape, 0.0001));
}

void Test_3D::test_rotate_16()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.rotate(-pi / 6, Vector_3D(1,0,1), Point_3D(10,0,10));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " z: " << it->get_point1()->get_z() << " p2 x: " << 
//                it->get_point2()->get_x() << " y: " << it->get_point2()->get_y() << " z: " << 
//                it->get_point2()->get_z() << " p3 x: " << it->get_point3()->get_x() << " y: " << 
//                it->get_point3()->get_y() << " z: " << it->get_point3()->get_z() << "\n";
//    }
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119)), shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494)), shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904)), shared_ptr<Point_3D>(new Point_3D(2.67949,14.1421,37.3205))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(9.33013,-3.53553,0.669873)), shared_ptr<Point_3D>(new Point_3D(12.0096,10.6066,37.9904))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(9.75056,31.4626,30.2494)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.07107,17.3205,-7.07107)), shared_ptr<Point_3D>(new Point_3D(19.0807,27.9271,30.9193)), shared_ptr<Point_3D>(new Point_3D(16.4012,13.785,-6.40119))), shape, 0.0001));
}

void Test_3D::test_scale_1()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(2,1,1);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(20,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(20,20,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(20,20,40)), shared_ptr<Point_3D>(new Point_3D(0,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(20,0,40)), shared_ptr<Point_3D>(new Point_3D(20,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(0,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,40)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,20,40)), shared_ptr<Point_3D>(new Point_3D(20,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,20,0)), shared_ptr<Point_3D>(new Point_3D(20,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,40)), shared_ptr<Point_3D>(new Point_3D(0,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(0,20,40)), shared_ptr<Point_3D>(new Point_3D(20,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(20,20,40)), shared_ptr<Point_3D>(new Point_3D(20,20,0))), shape, precision));
}

void Test_3D::test_scale_2()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(1,3,1);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,60,0)), shared_ptr<Point_3D>(new Point_3D(10,60,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,60,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(10,60,40)), shared_ptr<Point_3D>(new Point_3D(0,60,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(10,0,40)), shared_ptr<Point_3D>(new Point_3D(10,60,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,40)), shared_ptr<Point_3D>(new Point_3D(0,60,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,60,40)), shared_ptr<Point_3D>(new Point_3D(0,60,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,60,40)), shared_ptr<Point_3D>(new Point_3D(10,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,60,0)), shared_ptr<Point_3D>(new Point_3D(10,60,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,40)), shared_ptr<Point_3D>(new Point_3D(0,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,60,0)), shared_ptr<Point_3D>(new Point_3D(0,60,40)), shared_ptr<Point_3D>(new Point_3D(10,60,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,60,0)), shared_ptr<Point_3D>(new Point_3D(10,60,40)), shared_ptr<Point_3D>(new Point_3D(10,60,0))), shape, precision));
}

void Test_3D::test_scale_3()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(1,1,0.5);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(10,20,20)), shared_ptr<Point_3D>(new Point_3D(0,20,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(10,0,20)), shared_ptr<Point_3D>(new Point_3D(10,20,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(0,20,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,20,20)), shared_ptr<Point_3D>(new Point_3D(0,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,20)), shared_ptr<Point_3D>(new Point_3D(10,0,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,20)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(0,20,20)), shared_ptr<Point_3D>(new Point_3D(10,20,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,0)), shared_ptr<Point_3D>(new Point_3D(10,20,20)), shared_ptr<Point_3D>(new Point_3D(10,20,0))), shape, precision));
}

void Test_3D::test_scale_4()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(2,1,1, Point_3D(5,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-5,20,0)), shared_ptr<Point_3D>(new Point_3D(15,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(15,20,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,40)), shared_ptr<Point_3D>(new Point_3D(15,20,40)), shared_ptr<Point_3D>(new Point_3D(-5,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,40)), shared_ptr<Point_3D>(new Point_3D(15,0,40)), shared_ptr<Point_3D>(new Point_3D(15,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-5,0,40)), shared_ptr<Point_3D>(new Point_3D(-5,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-5,20,40)), shared_ptr<Point_3D>(new Point_3D(-5,20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,20,40)), shared_ptr<Point_3D>(new Point_3D(15,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,20,0)), shared_ptr<Point_3D>(new Point_3D(15,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,40)), shared_ptr<Point_3D>(new Point_3D(-5,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,20,0)), shared_ptr<Point_3D>(new Point_3D(-5,20,40)), shared_ptr<Point_3D>(new Point_3D(15,20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,20,0)), shared_ptr<Point_3D>(new Point_3D(15,20,40)), shared_ptr<Point_3D>(new Point_3D(15,20,0))), shape, precision));
}

void Test_3D::test_scale_5()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(1,3,1, Point_3D(5,10,20));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(10,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,40,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,40)), shared_ptr<Point_3D>(new Point_3D(10,40,40)), shared_ptr<Point_3D>(new Point_3D(0,40,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,40)), shared_ptr<Point_3D>(new Point_3D(10,-20,40)), shared_ptr<Point_3D>(new Point_3D(10,40,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(0,-20,40)), shared_ptr<Point_3D>(new Point_3D(0,40,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(0,40,40)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,40,40)), shared_ptr<Point_3D>(new Point_3D(10,-20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,40,0)), shared_ptr<Point_3D>(new Point_3D(10,40,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,40)), shared_ptr<Point_3D>(new Point_3D(0,-20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,0)), shared_ptr<Point_3D>(new Point_3D(10,-20,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,40)), shared_ptr<Point_3D>(new Point_3D(10,40,40))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(10,40,40)), shared_ptr<Point_3D>(new Point_3D(10,40,0))), shape, precision));
}

void Test_3D::test_scale_6()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.scale(1,1,0.5, Point_3D(5,10,20));
//    cout << gen_openscad_polyhedron(shape,4) << '\n';
//    int count=0;
//    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
////        cout << "Facet p1 x: " << (*it)->get_point1().get_x() << " y: " << (*it)->get_point1().get_y()
////                << " z: " << (*it)->get_point1().get_z() << " p2 x: " << (*it)->get_point2().get_x() 
////                << " y: " << (*it)->get_point2().get_y() << " z: " << (*it)->get_point2().get_z()
////                << " p3 x: " << (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y()
////                << " z: " << (*it)->get_point3().get_z() << "\n";
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_3D(Point_3D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << ',' <<
//                (*it)->get_point1().get_z() << "), Point_3D(" << (*it)->get_point2().get_x() << ',' <<
//                (*it)->get_point2().get_y() << ',' << (*it)->get_point2().get_z() << "), Point_3D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ',' <<
//                (*it)->get_point3().get_z() << ")), precision));\n";
//    }
//    cout << "shape size: " << shape.size() << "\n";
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,20,10)), shared_ptr<Point_3D>(new Point_3D(10,20,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,20,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,30)), shared_ptr<Point_3D>(new Point_3D(0,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(0,20,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,20,10)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,30)), shared_ptr<Point_3D>(new Point_3D(0,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,10)), shared_ptr<Point_3D>(new Point_3D(0,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,30))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,20,10)), shared_ptr<Point_3D>(new Point_3D(10,20,30)), shared_ptr<Point_3D>(new Point_3D(10,20,10))), shape, precision));
}

void Test_3D::test_translate_1()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.translate(5,10,20);
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(5,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(15,10,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(5,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,30,60)), shared_ptr<Point_3D>(new Point_3D(5,30,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(15,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,60)), shared_ptr<Point_3D>(new Point_3D(5,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(5,30,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(15,30,20))), shape, precision));
}

void Test_3D::test_translate_2()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.translate(Vector_3D(5,10,20));
//    cout << gen_openscad_polyhedron(shape,4) << '\n';
//    int count=0;
//    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
////        cout << "Facet p1 x: " << (*it)->get_point1().get_x() << " y: " << (*it)->get_point1().get_y()
////                << " z: " << (*it)->get_point1().get_z() << " p2 x: " << (*it)->get_point2().get_x() 
////                << " y: " << (*it)->get_point2().get_y() << " z: " << (*it)->get_point2().get_z()
////                << " p3 x: " << (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y()
////                << " z: " << (*it)->get_point3().get_z() << "\n";
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_3D(Point_3D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << ',' <<
//                (*it)->get_point1().get_z() << "), Point_3D(" << (*it)->get_point2().get_x() << ',' <<
//                (*it)->get_point2().get_y() << ',' << (*it)->get_point2().get_z() << "), Point_3D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ',' <<
//                (*it)->get_point3().get_z() << ")), precision));\n";
//    }
//    cout << "shape size: " << shape.size() << "\n";
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(5,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(15,10,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,10,60)), shared_ptr<Point_3D>(new Point_3D(5,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(5,30,60)), shared_ptr<Point_3D>(new Point_3D(5,30,20))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(15,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,60)), shared_ptr<Point_3D>(new Point_3D(5,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,20)), shared_ptr<Point_3D>(new Point_3D(15,10,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(5,30,60)), shared_ptr<Point_3D>(new Point_3D(15,30,60))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,30,20)), shared_ptr<Point_3D>(new Point_3D(15,30,60)), shared_ptr<Point_3D>(new Point_3D(15,30,20))), shape, precision));
}

void Test_3D::test_move_1()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_x_pxy(Point_3D(-20,0,0), Vector_3D(0,0,1), Point_3D(-19,0,0));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_2()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_x_pxz(Point_3D(-20,0,0), Vector_3D(0,0,1), Point_3D(-20,1,0));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_3()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_y_pxy(Point_3D(-20,0,0), Vector_3D(1,0,0), Point_3D(-20,0,1));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_4()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_y_pyz(Point_3D(-20,0,0), Vector_3D(1,0,0), Point_3D(-20,1,0));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_5()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_z_pxz(Point_3D(-20,0,0), Vector_3D(0,1,0), Point_3D(-20,0,1));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_6()
{
    Mesh_3D shape;
    m_cuboid(shape,10,20,40);
    shape.move_z_pyz(Point_3D(-20,0,0), Vector_3D(0,1,0), Point_3D(-19,0,0));
    assert(shape.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,0,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,40,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,0))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,0,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,10)), shared_ptr<Point_3D>(new Point_3D(-20,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10))), shape, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,40,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), shape, precision));
}

void Test_3D::test_move_7()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_x_pxy(Point_3D(0,0,20), Vector_3D(1,-1,0), Point_3D(0,0,21),Point_3D(0,0,20));
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_move_8()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_x_pxz(Point_3D(0,0,20), Vector_3D(1,-1,0), Point_3D(-1,-1,20),Point_3D(0,0,20));
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_move_9()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_y_pxy(Point_3D(0,0,20), Vector_3D(0,0,1), Point_3D(1,-1,20),Point_3D(0,0,20));
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_move_10()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_y_pyz(Point_3D(0,0,20), Vector_3D(0,0,1), Point_3D(-1,-1,20),Point_3D(0,0,20));
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_move_11()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_z_pxz(Point_3D(0,0,20), Vector_3D(-1,-1,0), Point_3D(1,-1,20),Point_3D(0,0,20));
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_move_12()
{
    Mesh_3D shape;
    m_cylinder(shape,0,20,40,2);
    // x 1,-1,0
    // y 0,0,1
    // z -1,-1,0
    shape.move_z_pyz(Point_3D(0,0,20), Vector_3D(-1,-1,0), Point_3D(0,0,21),Point_3D(0,0,20));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " z: " << it->get_point1()->get_z() << " p2 x: " << 
//                it->get_point2()->get_x() << " y: " << it->get_point2()->get_y() << " z: " << 
//                it->get_point2()->get_z() << " p3 x: " << it->get_point3()->get_x() << " y: " << 
//                it->get_point3()->get_y() << " z: " << it->get_point3()->get_z() << "\n";
//    }
    assert(shape.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,40))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,34.1421))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-28.2843,0,20))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-24.1421,-4.14214,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), shape, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,20)), shared_ptr<Point_3D>(new Point_3D(0,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.14214,-24.1421,5.85786))), shape, 0.0001));
}

void Test_3D::test_valid_mesh_1()
{
    Mesh_3D mesh;
    
    // invalid mesh
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(0,3,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    
    Valid_Mesh_3D valid(mesh);
    assert(!valid.validate());
    assert(!valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 1);
    assert(is_equal(**valid.pts_on_side_begin(), Point_3D(3,3,3), precision));
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
    assert(!valid.edge_facets_empty());
//    cout << "edge_facets_size: " << valid.edge_facets_size() << "\n";
//    for (Valid_Mesh_3D::edge_facet_iterator iter = valid.edge_facets_begin(); iter != valid.edge_facets_end(); ++iter)
//    {
//        cout << "edge facet p1 x: " << iter->get_point1()->get_x() << " y: " << iter->get_point1()->get_y() << " z: " << 
//                iter->get_point1()->get_z() << " p2 x: " << iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() << 
//                " z: " << iter->get_point2()->get_z() << " p3 x: " << iter->get_point3()->get_x() << " y: " << iter->get_point3()->get_y() << 
//                " z: " << iter->get_point3()->get_z() << "\n";
//    }
    assert(valid.edge_facets_size() == 6);
    Valid_Mesh_3D::edge_facet_iterator iter(valid.edge_facets_begin());
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(valid.too_many_share_side_size() == 0);
    assert(valid.too_many_share_side_empty());
}

void Test_3D::test_valid_mesh_2()
{
    Mesh_3D mesh;
    
    // invalid mesh
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(2,2,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    
    Valid_Mesh_3D valid(mesh);
    assert(!valid.validate());
    assert(valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 0);
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
    assert(!valid.edge_facets_empty());
//    cout << "edge_facets_size: " << valid.edge_facets_size() << "\n";
//    for (Valid_Mesh_3D::edge_facet_iterator iter = valid.edge_facets_begin(); iter != valid.edge_facets_end(); ++iter)
//    {
//        cout << "edge facet p1 x: " << iter->get_point1()->get_x() << " y: " << iter->get_point1()->get_y() << " z: " << 
//                iter->get_point1()->get_z() << " p2 x: " << iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() << 
//                " z: " << iter->get_point2()->get_z() << " p3 x: " << iter->get_point3()->get_x() << " y: " << iter->get_point3()->get_y() << 
//                " z: " << iter->get_point3()->get_z() << "\n";
//    }
    assert(valid.edge_facets_size() == 6);
    Valid_Mesh_3D::edge_facet_iterator iter(valid.edge_facets_begin());
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(2,2,10))), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(!valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 1);
    Valid_Mesh_3D::too_many_share_side_iterator iter2(valid.too_many_share_side_begin());
    vector<Facet_3D> v = *iter2;
    assert(v.size() == 3);
    vector<Facet_3D>::const_iterator iter3(v.begin());
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter3, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(2,2,10))), precision));
}

void Test_3D::test_valid_mesh_3()
{
    Mesh_3D mesh;
    
    // invalid mesh
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(0,3,3))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    
    Valid_Mesh_3D valid(mesh);
    assert(!valid.validate());
    assert(!valid.pts_on_side_empty());
//    cout << "pts on side size: " << valid.pts_on_side_size() << "\n";
//    for (Valid_Mesh_3D::pt_on_side_iterator it = valid.pts_on_side_begin(); it != valid.pts_on_side_end(); ++it)
//    {
//        cout << "pt on side x: " << (*it)->get_x() << " y: " << (*it)->get_y() << " z: " << (*it)->get_z() << "\n";
//    }
    assert(valid.pts_on_side_size() == 1);
    Valid_Mesh_3D::pt_on_side_iterator iter(valid.pts_on_side_begin());
    assert(is_equal(**iter++, Point_3D(3,3,3), precision));
    assert(!valid.facets_inside_facet_empty());
//    cout << "Facets inside facet size: " << valid.facets_inside_facet_size() << "\n";
//    for (Valid_Mesh_3D::facets_inside_facet_iterator it = valid.facets_inside_facet_begin(); it != valid.facets_inside_facet_end(); ++it)
//    {
//        cout << "Larger facet p1 x: " << it->first.get_point1()->get_x() << " y: " << it->first.get_point1()->get_y() << 
//                " z: " << it->first.get_point1()->get_z() << " p2 x: " << it->first.get_point2()->get_x() << " y: " << 
//                it->first.get_point2()->get_y() << " z: " << it->first.get_point2()->get_z() << " p3 x: " << 
//                it->first.get_point3()->get_x() << " y: " << it->first.get_point3()->get_y() << " z: " << 
//                it->first.get_point3()->get_z() << "\n";
//        for (vector<Facet_3D>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
//        {
//            cout << "    Facet p1 x: " << it2->get_point1()->get_x() << " y: " << it2->get_point1()->get_y() << 
//                    " z: " << it2->get_point1()->get_z() << " p2 x: " << it2->get_point2()->get_x() << " y: " << 
//                    it2->get_point2()->get_y() << " z: " << it2->get_point2()->get_z() << " p3 x: " << 
//                    it2->get_point3()->get_x() << " y: " << it2->get_point3()->get_y() << " z: " << 
//                    it2->get_point3()->get_z() << "\n";
//        }
//    }
    assert(valid.facets_inside_facet_size() == 1);
    Valid_Mesh_3D::facets_inside_facet_iterator iter2(valid.facets_inside_facet_begin());
    pair<Facet_3D,vector<Facet_3D>> p(*iter2);
    assert(is_equal(p.first, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(p.second.size() == 2);
    vector<Facet_3D>::const_iterator iter3(p.second.begin());
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(!valid.edge_facets_empty());
//    cout << "edge_facets_size: " << valid.edge_facets_size() << "\n";
//    for (Valid_Mesh_3D::edge_facet_iterator iter = valid.edge_facets_begin(); iter != valid.edge_facets_end(); ++iter)
//    {
//        cout << "edge facet p1 x: " << iter->get_point1()->get_x() << " y: " << iter->get_point1()->get_y() << " z: " << 
//                iter->get_point1()->get_z() << " p2 x: " << iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() << 
//                " z: " << iter->get_point2()->get_z() << " p3 x: " << iter->get_point3()->get_x() << " y: " << iter->get_point3()->get_y() << 
//                " z: " << iter->get_point3()->get_z() << "\n";
//    }
    assert(valid.edge_facets_size() == 6);
    Valid_Mesh_3D::edge_facet_iterator iter4(valid.edge_facets_begin());
    assert(is_equal(*iter4++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), precision));
    assert(is_equal(*iter4++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter4++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter4++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter4++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter4, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), precision));
    assert(!valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 1);
    vector<Facet_3D> v(*valid.too_many_share_side_begin());
    assert(v.size() == 3);
    iter3 = v.begin();
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,3,3))), precision));
    assert(is_equal(*iter3++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), precision));
    assert(is_equal(*iter3, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,3)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), precision));
}

void Test_3D::test_valid_mesh_4()
{
    Mesh_3D mesh;
    
    // valid mesh
    m_ellipsoid(mesh, 10,15,17,4);
    
    Valid_Mesh_3D valid(mesh);
    assert(valid.validate());
    assert(valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 0);
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
    assert(valid.edge_facets_empty());
    assert(valid.edge_facets_size() == 0);
    assert(valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 0);
}

void Test_3D::test_valid_mesh_5()
{
    Mesh_3D mesh;
    
    // valid mesh
    m_e_cylinder(mesh, 10,15,15,10,17,4);
    
    Valid_Mesh_3D valid(mesh);
    assert(valid.validate());
//    for (int i = 0; i < valid.unaligned_points_size(); ++i)
//    {
//        Point_3D p(valid.unaligned_point_at(i));
//        cout << "unaligned_points[" << i << "]: x: " << p.get_x() << " y: " << p.get_y() << " z: " << p.get_z() << "\n";
//    }
    assert(valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 0);
//    assert(is_equal(valid.unaligned_point_at(0), Point_3D(3,3,3), precision));
//    assert(is_equal(valid.unaligned_point_at(1), Point_3D(2,2,2), precision));
//    assert(is_equal(valid.unaligned_point_at(2), Point_3D(4,0.000001,-0.000001), precision));
//    for (int i = 0; i < valid.facets_with_facets_size(); ++i)
//    {
//        Facet_3D f(valid.facets_with_facets_at(i));
//        cout << "facets_with_facets[" << i << "]: p1 x: " << f.get_point1().get_x() <<
//                " y: " << f.get_point1().get_y() << " z: " << f.get_point1().get_z() << 
//                " p2 x: " << f.get_point2().get_x() << " y: " << f.get_point2().get_y() << 
//                " z: " << f.get_point2().get_z() << " p3 x: " << f.get_point3().get_x() <<
//                " y: " << f.get_point3().get_y() << " z: " << f.get_point3().get_z() << "\n";
//    }
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
//    assert(is_equal(valid.facets_with_facets_at(0), Facet_3D(Point_3D(0,0,0), Point_3D(10,0,0), Point_3D(5,5,5)), precision));
//    assert(is_equal(valid.facets_with_facets_at(1), Facet_3D(Point_3D(0,0,0), Point_3D(5,5,5), Point_3D(0,3,3)), precision));
//    assert(is_equal(valid.facets_with_facets_at(2), Facet_3D(Point_3D(0,0,0), Point_3D(3,3,3), Point_3D(0,3,3)), precision));
//    for (int i = 0; i < valid.invalid_facets_size(); ++i)
//    {
//        Facet_3D f(valid.invalid_facets_at(i));
//        cout << "invalid_facets[" << i << "]: p1 x: " << f.get_point1().get_x() <<
//                " y: " << f.get_point1().get_y() << " z: " << f.get_point1().get_z() << 
//                " p2 x: " << f.get_point2().get_x() << " y: " << f.get_point2().get_y() << 
//                " z: " << f.get_point2().get_z() << " p3 x: " << f.get_point3().get_x() <<
//                " y: " << f.get_point3().get_y() << " z: " << f.get_point3().get_z() << "\n";
//    }
    assert(valid.edge_facets_empty());
    assert(valid.edge_facets_size() == 0);
//    assert(is_equal(valid.edge_facets_at(0), Facet_3D(Point_3D(0,0,0), Point_3D(10,0,0), Point_3D(5,5,5)), precision));
//    assert(is_equal(valid.edge_facets_at(1), Facet_3D(Point_3D(0,0,0), Point_3D(5,5,5), Point_3D(0,3,3)), precision));
//    assert(is_equal(valid.edge_facets_at(2), Facet_3D(Point_3D(0,0,0), Point_3D(3,3,3), Point_3D(0,3,3)), precision));
//    assert(is_equal(valid.edge_facets_at(3), Facet_3D(Point_3D(0,3,3), Point_3D(3,3,3), Point_3D(5,5,5)), precision));
//    assert(is_equal(valid.edge_facets_at(4), Facet_3D(Point_3D(0,3,3), Point_3D(5,5,5), Point_3D(0,10,10)), precision));
//    assert(is_equal(valid.edge_facets_at(5), Facet_3D(Point_3D(0,10,10), Point_3D(5,5,5), Point_3D(10,10,10)), precision));
//    assert(is_equal(valid.edge_facets_at(6), Facet_3D(Point_3D(10,0,0), Point_3D(10,10,10), Point_3D(5,5,5)), precision));
//    for (int i = 0; i < valid.too_many_facets_size(); ++i)
//    {
//        Facet_3D f(valid.too_many_facets_at(i));
//        cout << "too_many_facets[" << i << "]: p1 x: " << f.get_point1().get_x() <<
//                " y: " << f.get_point1().get_y() << " z: " << f.get_point1().get_z() << 
//                " p2 x: " << f.get_point2().get_x() << " y: " << f.get_point2().get_y() << 
//                " z: " << f.get_point2().get_z() << " p3 x: " << f.get_point3().get_x() <<
//                " y: " << f.get_point3().get_y() << " z: " << f.get_point3().get_z() << "\n";
//    }
    assert(valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 0);
//    assert(is_equal(valid.too_many_facets_at(0), Facet_3D(Point_3D(0,0,0), Point_3D(5,5,5), Point_3D(0,3,3)), precision));
//    assert(is_equal(valid.too_many_facets_at(1), Facet_3D(Point_3D(0,3,3), Point_3D(3,3,3), Point_3D(5,5,5)), precision));
//    assert(is_equal(valid.too_many_facets_at(2), Facet_3D(Point_3D(0,3,3), Point_3D(5,5,5), Point_3D(0,10,10)), precision));
}
