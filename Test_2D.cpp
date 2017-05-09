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
 * File:   Test_2D.cpp
 * Author: Jeffrey Davis
 */

#include "Test_2D.h"
#include <cfloat>

const bool Test_2D::within_round(const double val1, const double val2, const double precision) const
{
        return (fabs(val1 - val2) < precision);
}

const bool Test_2D::mesh_contains(const Facet_2D& facet, const Mesh_2D& mesh, const double precision) const
{
    Mesh_2D::const_iterator it = mesh.begin();
    while (it != mesh.end())
    {
        // try to locate the first point
        if (within_round(it->get_point1()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point1()->get_y(), precision))
        {
            // try for point2
            if (within_round(it->get_point2()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point2()->get_y(), precision))
            {
                // try point3
                if (within_round(it->get_point3()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point3()->get_y(), precision))
                    return true;
            }
        }
        else if (within_round(it->get_point2()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point1()->get_y(), precision))
        {
            // try for point2
            if (within_round(it->get_point3()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point2()->get_y(), precision))
            {
                // try point3
                if (within_round(it->get_point1()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point3()->get_y(), precision))
                    return true;
            }
        }
        else if (within_round(it->get_point3()->get_x(), facet.get_point1()->get_x(), precision) && 
                within_round(it->get_point3()->get_y(), facet.get_point1()->get_y(), precision))
        {
            // try for point2
            if (within_round(it->get_point1()->get_x(), facet.get_point2()->get_x(), precision) && 
                within_round(it->get_point1()->get_y(), facet.get_point2()->get_y(), precision))
            {
                // try point3
                if (within_round(it->get_point2()->get_x(), facet.get_point3()->get_x(), precision) && 
                within_round(it->get_point2()->get_y(), facet.get_point3()->get_y(), precision))
                    return true;
            }
        }
        ++it;
    }
    
    return false;
}

void Test_2D::test_all()
{
    cout << "Testing 2D sub-systems\n";
    this->test_Point_2D();
    cout << '.';
    this->test_Vector_2D();
    cout << '.';
    this->test_is_pt_on_vector();
    cout << '.';
    this->test_intersect_vector_vector();
    cout << '.';
    this->test_Facet_2D();
    cout << '.';
    this->test_facet_contains_point();
    cout << '.';
    this->test_Mesh_2D();
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
    cout << '.';
    this->test_intersect_meshes_16();
    cout << '.';
    this->test_intersect_meshes_17();
    cout << '.';
    this->test_intersect_meshes_18();
    cout << '.' << '\n';
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
    this->test_m_rectangle_1();
    cout << '.';
    this->test_m_rectangle_2();
    cout << '.';
    this->test_m_rectangle_3();
    cout << '.';
    this->test_m_rectangle_4();
    cout << '.' << '\n';
    this->test_m_circle_1();
    cout << '.';
    this->test_m_circle_2();
    cout << '.';
    this->test_m_ellipse_1();
    cout << '.';
    this->test_m_ellipse_2();
    cout << '.';
    this->test_m_ellipse_3();
    cout << '.';
    this->test_m_ellipse_4();
    cout << '.';
    this->test_rotate_1();
    cout << '.';
    this->test_rotate_2();
    cout << '.';
    this->test_rotate_3();
    cout << '.';
    this->test_rotate_4();
    cout << '.';
    this->test_scale_1();
    cout << '.';
    this->test_scale_2();
    cout << '.';
    this->test_scale_3();
    cout << '.';
    this->test_scale_4();
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
    this->test_valid_mesh_1();
    cout << '.';
    this->test_valid_mesh_2();
    cout << '.';
    this->test_valid_mesh_3();
    cout << '.';
    this->test_valid_mesh_4();
    cout << '.';
    cout << endl << endl;
}

void Test_2D::test_Point_2D()
{
    // test Point_2D object
    Point_2D p1(5,6);
    // test get
    assert(p1.get_x() == 5);
    assert(p1.get_y() == 6);
    // test r and theta
    assert(within_round(p1.get_r(), 7.8102, precision));
    assert(within_round(p1.get_theta(), 0.8761, precision));
    // test r and theta from another point
    Point_2D p2(10,0);
    assert(within_round(p1.get_r(p2), 7.81025, precision));
    assert(within_round(p1.get_theta(p2), 2.26553, precision));
    // test rotate
    p1 = Point_2D(8,8);
    p1.rotate(pi / 4);
    assert(within_round(p1.get_x(), 0, precision));
    assert(within_round(p1.get_y(), 11.3137, precision));
    p1.rotate(-pi / 4);
    assert(within_round(p1.get_x(), 8, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test rotate about an alternate origin
    p2 = Point_2D(8,0);
    p1.rotate(pi / 2, p2);
    assert(within_round(p1.get_x(), 0, precision));
    assert(within_round(p1.get_y(), 0, precision));
    p1.rotate(-pi / 2, p2);
    assert(within_round(p1.get_x(), 8, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test scale by doubles
    p1 = Point_2D(8,8);
    p1.scale(2, 1.5);
    assert(within_round(p1.get_x(), 16, precision));
    assert(within_round(p1.get_y(), 12, precision));
    p1.scale(0.5, 0.5);
    assert(within_round(p1.get_x(), 8, precision));
    assert(within_round(p1.get_y(), 6, precision));
    // test translate by doubles
    p1.translate(4,2);
    assert(within_round(p1.get_x(), 12, precision));
    assert(within_round(p1.get_y(), 8, precision));
    p1.translate(-2,0);
    assert(within_round(p1.get_x(), 10, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test translate by vector
    Vector_2D v(0.5, 0.5);
    p1.translate(v);
    assert(within_round(p1.get_x(), 10.5, precision));
    assert(within_round(p1.get_y(), 8.5, precision));
    v = Vector_2D(-0.5, 0.5);
    p1.translate(v);
    assert(within_round(p1.get_x(), 10, precision));
    assert(within_round(p1.get_y(), 9, precision));
    // test +=
    v = Vector_2D(-2,-3);
    p1 += v;
    assert(within_round(p1.get_x(), 8, precision));
    assert(within_round(p1.get_y(), 6, precision));
    v = Vector_2D(2,2);
    p1 += v;
    assert(within_round(p1.get_x(), 10, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test -=
    p1 -= v;
    assert(within_round(p1.get_x(), 8, precision));
    assert(within_round(p1.get_y(), 6, precision));
    v = Vector_2D(-2,-2);
    p1 -= v;
    assert(within_round(p1.get_x(), 10, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test *=
    p1 *= 2;
    assert(within_round(p1.get_x(), 20, precision));
    assert(within_round(p1.get_y(), 16, precision));
    p1 *= 0.5;
    assert(within_round(p1.get_x(), 10, precision));
    assert(within_round(p1.get_y(), 8, precision));
    // test ==
    p2 = Point_2D(10,8);
    assert(p1 == p2);
    p2 = Point_2D(10.1,7.9);
    assert(!(p1 == p2));
    // test !=
    assert(p1 != p2);
    p2 = Point_2D(10,8);
    assert(!(p1 != p2));
    // test +
    p2 = p1 + v;
    assert(within_round(p2.get_x(), 8, precision));
    assert(within_round(p2.get_y(), 6, precision));
    v = Vector_2D(2,2);
    p2 = p1 + v;
    assert(within_round(p2.get_x(), 12, precision));
    assert(within_round(p2.get_y(), 10, precision));
    // test -
    p2 = p1 - v;
    assert(within_round(p2.get_x(), 8, precision));
    assert(within_round(p2.get_y(), 6, precision));
    v = Vector_2D(-2,-2);
    p2 = p1 - v;
    assert(within_round(p2.get_x(), 12, precision));
    assert(within_round(p2.get_y(), 10, precision));
    // test *
    p2 = p1 * 0.5;
    assert(within_round(p2.get_x(), 5, precision));
    assert(within_round(p2.get_y(), 4, precision));
    p2 = p1 * 2;
    assert(within_round(p2.get_x(), 20, precision));
    assert(within_round(p2.get_y(), 16, precision));
    // test chaining ops
    p1 = Point_2D(8,8);
    p1.translate(v).rotate(pi / 4);
    assert(within_round(p1.get_x(), 0, precision));
    assert(within_round(p1.get_y(), 8.48528, precision));
    // test polar points
    p1 = polar_point(5, pi / 6);
    assert(within_round(p1.get_x(), 4.3301, precision));
    assert(within_round(p1.get_y(), 2.5, precision));
    p1 = polar_point(5, -pi / 6);
    assert(within_round(p1.get_x(), 4.3301, precision));
    assert(within_round(p1.get_y(), -2.5, precision));
    // test assignment
    p1 = Point_2D(5,4);
    p2 = p1;
    assert(within_round(p2.get_x(), 5, precision));
    assert(within_round(p2.get_y(), 4, precision));
    p2 += Vector_2D(4,5);
    assert(within_round(p1.get_x(), 5, precision));
    assert(within_round(p1.get_y(), 4, precision));
    assert(within_round(p2.get_x(), 9, precision));
    assert(within_round(p2.get_y(), 9, precision));
    // test move
    p1 = Point_2D(5,4);
    p1.move(Point_2D(0,0), Vector_2D(0,-1), true);
    assert(within_round(p1.get_x(), 4, precision));
    assert(within_round(p1.get_y(), -5, precision));
    p1 = Point_2D(5,4);
    p1.move(Point_2D(0,0), Vector_2D(0,-1), false);
    assert(within_round(p1.get_x(), -5, precision));
    assert(within_round(p1.get_y(), -4, precision));
    p1 = Point_2D(5,4);
    p1.move(Point_2D(3,3), Vector_2D(0,-1), true, Point_2D(4,3));
    assert(within_round(p1.get_x(), 4, precision));
    assert(within_round(p1.get_y(), 2, precision));
//    cout << "p1 x: " << p1.get_x() << " y: " << p1.get_y() << "\n";
}

void Test_2D::test_Vector_2D()
{
    // test Vector_2D object
    Vector_2D v1(5,6);
    // test get
    assert(v1.get_x() == 5);
    assert(v1.get_y() == 6);
    // test length
    assert(within_round(v1.length(), 7.8102, precision));
    // test normalize
    v1.normalize();
    assert(within_round(v1.get_x(), 0.640184, precision));
    assert(within_round(v1.get_y(), 0.768221, precision));
    // test vector constructors
    Point_2D p1(6,5);
    v1 = Vector_2D(p1);
    assert(v1.get_x() == 6);
    assert(v1.get_y() == 5);
    Point_2D p2(5,6);
    v1 = Vector_2D(p2, p1);
    assert(v1.get_x() == 1);
    assert(v1.get_y() == -1);
    // test +=
    Vector_2D v2(1,0);
    v1 = Vector_2D(3,4);
    v1 += v2;
    assert(within_round(v1.get_x(), 4, precision));
    assert(within_round(v1.get_y(), 4, precision));
    v2 = Vector_2D(-3, 4);
    v1 += v2;
    assert(within_round(v1.get_x(), 1, precision));
    assert(within_round(v1.get_y(), 8, precision));
    // test -=
    v1 -= v2;
    assert(within_round(v1.get_x(), 4, precision));
    assert(within_round(v1.get_y(), 4, precision));
    v2 = Vector_2D(2,-1);
    v1 -= v2;
    assert(within_round(v1.get_x(), 2, precision));
    assert(within_round(v1.get_y(), 5, precision));
    // test *=
    v1 *= 2;
    assert(within_round(v1.get_x(), 4, precision));
    assert(within_round(v1.get_y(), 10, precision));
    v1 *= 0.5;
    assert(within_round(v1.get_x(), 2, precision));
    assert(within_round(v1.get_y(), 5, precision));
    v1 *= -2;
    assert(within_round(v1.get_x(), -4, precision));
    assert(within_round(v1.get_y(), -10, precision));
    // test cross product
    v1 = Vector_2D(5,5);
    v2 = Vector_2D(0,1);
    assert(within_round(cross_product(v1, v2), 5, precision));
    v2 = Vector_2D(1,0);
    assert(within_round(cross_product(v1, v2), -5, precision));
    // test dot product
    assert(within_round(dot_product(v1, v2), 5, precision));
    v2 = Vector_2D(0,1);
    assert(within_round(dot_product(v1, v2), 5, precision));
    v2 = Vector_2D(-1,0);
    assert(within_round(dot_product(v1, v2), -5, precision));
    v2 = Vector_2D(0,-1);
    assert(within_round(dot_product(v1, v2), -5, precision));
    v2 = Vector_2D(1,1);
    assert(within_round(dot_product(v1, v2), 10, precision));
    v2 = Vector_2D(-1,-1);
    assert(within_round(dot_product(v1, v2), -10, precision));
    // test angle between
    v2 = Vector_2D(1,0);
    assert(within_round(angle_between(v1, v2), pi / 4, precision));
    v2 = Vector_2D(0,1);
    assert(within_round(angle_between(v1, v2), pi / 4, precision));
    v2 = Vector_2D(-1,0);
    assert(within_round(angle_between(v1, v2), 3 * pi / 4, precision));
    v2 = Vector_2D(0,-1);
    assert(within_round(angle_between(v1, v2), 3 * pi / 4, precision));
    v2 = Vector_2D(1,1);
    assert(within_round(angle_between(v1, v2), 0, precision));
    v2 = Vector_2D(-1,-1);
    assert(within_round(angle_between(v1, v2), pi, precision));
    // test ==
    v2 = Vector_2D(5,5);
    assert(v1 == v2);
    v2 = Vector_2D(-5,-5);
    assert(!(v1 == v2));
    // test !=
    assert(v1 != v2);
    v2 = Vector_2D(5,5);
    assert(!(v1 != v2));
    // test +
    v2 = Vector_2D(-1,1);
    Vector_2D v3 = v1 + v2;
    assert(within_round(v3.get_x(), 4, precision));
    assert(within_round(v3.get_y(), 6, precision));
    v2 = Vector_2D(1, -1);
    v3 = v1 + v2;
    assert(within_round(v3.get_x(), 6, precision));
    assert(within_round(v3.get_y(), 4, precision));
    // test -
    v3 = v1 - v2;
    assert(within_round(v3.get_x(), 4, precision));
    assert(within_round(v3.get_y(), 6, precision));
    v2 = Vector_2D(-1, 1);
    v3 = v1 - v2;
    assert(within_round(v3.get_x(), 6, precision));
    assert(within_round(v3.get_y(), 4, precision));
    // test *
    v3 = v1 * 2;
    assert(within_round(v3.get_x(), 10, precision));
    assert(within_round(v3.get_y(), 10, precision));
    v3 = v1 * -0.5;
    assert(within_round(v3.get_x(), -2.5, precision));
    assert(within_round(v3.get_y(), -2.5, precision));
}

void Test_2D::test_is_pt_on_vector()
{
    Vector_2D v(5,5);
    Point_2D o(2,1);
    // test origin
    Point_2D p(2,1);
    assert(is_pt_on_vector(p,o,o + v, precision));
    // test end point
    p = Point_2D(7,6);
    assert(is_pt_on_vector(p,o,o+v, precision));
    // test middle point
    p = Point_2D(4.5, 3.5);
    assert(is_pt_on_vector(p,o,o+v, precision));
    // test points not on vector
    p = Point_2D(1,0);
    assert(!is_pt_on_vector(p,o,o+v, precision));
    p = Point_2D(8,7);
    assert(!is_pt_on_vector(p,o,o+v, precision));
    p = Point_2D(5,5);
    assert(!is_pt_on_vector(p,o,o+v, precision));
    p = Point_2D(5,9);
    assert(!is_pt_on_vector(p,o,o+v, precision));
}

void Test_2D::test_intersect_vector_vector()
{
    Vector_2D v2(5,5);
    Point_2D o2(2,2);
    /*
     * test both vectors in the same line, same direction
     */
    // v1 before v2, no intersection
    Vector_2D v1(3,3);
    Point_2D o1(-2,-2);
    Vector_2D_idata vid; 
    assert(!intersect_vectors(o1, o1+v1, o2,o2+v2, vid, precision)); // zero points
    // v1 before v2, intersect at o2
    o1 = Point_2D(-1,-1);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o2);
    // v1 before v2, v1 passes o2
    o1 = Point_2D(0,0);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(is_equal(vid.p1, o2, precision));
    assert(is_equal(vid.p2, o1 + v1, precision));
    // v1 before v2, v1 covers v2, same end points
    v1 = Vector_2D(7,7);
    o1 = Point_2D(0,0);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(is_equal(vid.p1, o2, precision));
    assert(is_equal(vid.p2, o1 + v1, precision));
    // v1 before v2, v1 covers v2
    v1 = Vector_2D(8,8);
    o1 = Point_2D(0,0);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2);
    assert(vid.p2 == o2 + v2);
    // o1 same as o2, v1 inside v2
    v1 = Vector_2D(3,3);
    assert(intersect_vectors(o2,o2+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2);
    assert(vid.p2 == o2 + v1);
    // o1 same as o2, v1 same as v2
    v1 = Vector_2D(5,5);
    assert(intersect_vectors(o2,o2+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2);
    assert(vid.p2 == o2 + v1);
    // o1 same as o2, v1 longer than v2
    v1 = Vector_2D(6,6);
    assert(intersect_vectors(o2,o2+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2);
    assert(vid.p2 == o2 + v2);
    // o1 after o2, v1 inside v2
    o1 = Point_2D(3,3);
    v1 = Vector_2D(2,2);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o1 + v1);
    // o1 after o2, ep1 == ep2
    v1 = Vector_2D(4,4);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o1 + v1);
    // o1 after o2, ep1 past ep2
    v1 = Vector_2D(5,5);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o2 + v2);
    // o1 same as ep2
    o1 = Point_2D(7,7);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o1);
    // o1 past v2
    o1 = Point_2D(8,8);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision)); // no intersection
    /*
     * test both vectors in the same line, opposite direction
     */
    // v1 before v2, no intersection
    v1 = Vector_2D(-3,-3);
    o1 = Point_2D(1,1);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    // o1 == o2, 1 intersection
    assert(intersect_vectors(o2,o2+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o2);
    // o1 past o2, v1 before o2
    o1 = Point_2D(3,3);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o2);
    // o1 past o2, ep1 == o2
    o1 = Point_2D(5,5);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o2);
    // v1 inside v2
    o1 = Point_2D(6,6);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o1 + v1);
    // o1 on ep2, v1 inside v2
    o1 = Point_2D(7,7);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o1);
    assert(vid.p2 == o1 + v1);
    // o1 on ep2, ep1 before o2
    v1 = Vector_2D(-8,-8);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2 + v2);
    assert(vid.p2 == o2);
    // o1 after ep2, v1 before o2
    o1 = Point_2D(8,8);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2 + v2);
    assert(vid.p2 == o2);
    // o1 after ep2, ep1 == o2
    v1 = Vector_2D(-6,-6);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2 + v2);
    assert(vid.p2 == o2);
    // o1 after ep2, ep1 after o2
    v1 = Vector_2D(-4,-4);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 2);
    assert(vid.p1 == o2 + v2);
    assert(vid.p2 == o1 + v1);
    // o1 after ep2, ep1 == ep2
    v1 = Vector_2D(-1,-1);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o2 + v2);
    // v1 past v2, no intersections
    o1 = Point_2D(10,10);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision)); // no intersections
    /*
     * test both vectors not in the same line
     */
    // no intersection
    o1 = Point_2D(6,-1);
    v1 = Vector_2D(-3,3);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    // ep1 on middle v2
    o1 = Point_2D(5.5, -0.5);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o1 + v1);
    // v1 middle intersects v2 middle
    o1 = Point_2D(5,0);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == Point_2D(2.5,2.5));
    // o1 intersects v2 middle
    o1 = Point_2D(2.5,2.5);
    assert(intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    assert(vid.num == 1);
    assert(vid.p1 == o1);
    // no intersection
    o1 = Point_2D(3,4);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    // no intersection
    o1 = Point_2D(1,0);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    // vector parallel, no intersection
    v1 = Vector_2D(3,3);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
    // vector parallel, no intersection
    v1 = Vector_2D(-3,-3);
    assert(!intersect_vectors(o1,o1+v1,o2,o2+v2,vid, precision));
//    cout << "vid.num: " << vid.num << "\n";
//    cout << "vid.p1 x: " << vid.p1.get_x() << " y: " << vid.p1.get_y() << "\n";
//    cout << "vid.p2 x: " << vid.p2.get_x() << " y: " << vid.p2.get_y() << "\n";
}

void Test_2D::test_Facet_2D()
{
    Facet_2D f(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,0)));
    // test get methods
    assert(*f.get_point1() == Point_2D(1,1));
    assert(*f.get_point2() == Point_2D(5,0));
    assert(*f.get_point3() == Point_2D(5,5));
    // test equals
    Facet_2D f1(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(1,1)));
    assert(is_equal(f, f1, precision));
    f1 = Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,1)), shared_ptr<Point_2D>(new Point_2D(0,5)));
    assert(!is_equal(f, f1, precision));
//    cout << "p1: x=" << f.get_point1().get_x() << " y=" << f.get_point1().get_y() << endl;
//    cout << "p2: x=" << f.get_point2().get_x() << " y=" << f.get_point2().get_y() << endl;
//    cout << "p3: x=" << f.get_point3().get_x() << " y=" << f.get_point3().get_y() << endl;
}

void Test_2D::test_facet_contains_point()
{
    Facet_2D f(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(6,0)));
    bool pt_on_side(false);
    // test corner points
    assert(f.contains_point(Point_2D(0,0), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    assert(f.contains_point(Point_2D(3,3), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    assert(f.contains_point(Point_2D(6,0), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    // test outside points
    assert(!f.contains_point(Point_2D(0,1), pt_on_side, precision));
    assert(!f.contains_point(Point_2D(6,1), pt_on_side, precision));
    assert(!f.contains_point(Point_2D(3,-1), pt_on_side, precision));
    // test inside points
    assert(f.contains_point(Point_2D(2,1), pt_on_side, precision));
    assert(!pt_on_side);
    assert(f.contains_point(Point_2D(4,1), pt_on_side, precision));
    assert(!pt_on_side);
    assert(f.contains_point(Point_2D(3,2), pt_on_side, precision));
    assert(!pt_on_side);
    // test side points
    assert(f.contains_point(Point_2D(3,0), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    assert(f.contains_point(Point_2D(2,2), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
    assert(f.contains_point(Point_2D(4,2), pt_on_side, precision));
    assert(pt_on_side);
    pt_on_side = false;
}

void Test_2D::test_Mesh_2D()
{
    // test constructors
    Mesh_2D mesh;
    assert(mesh.get_precision() == DBL_EPSILON * 21);
    assert(mesh.size() == 0);
    mesh = Mesh_2D(DBL_EPSILON * 5);
    assert(mesh.get_precision() == DBL_EPSILON * 5);
    assert(mesh.size() == 0);
    // test add facet, size, and at
    Facet_2D facet(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh.push_back(facet);
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), facet, precision));
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0, 10)));
    mesh.push_back(facet1);
    assert(mesh.size() == 2);
    assert(is_equal(*(++mesh.begin()), facet1, precision));
    // test iterators
    Mesh_2D::const_iterator iter = mesh.begin();
    assert(is_equal(*iter, facet, precision));
    ++iter;
    assert(is_equal(*iter, facet1, precision));
    ++iter;
    assert(iter == mesh.end());
    // test rotate
    mesh.rotate(pi / 4);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(7.07107, 7.07107)), shared_ptr<Point_2D>(new Point_2D(0, 7.07107))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0, 7.07107)), shared_ptr<Point_2D>(new Point_2D(-7.07107, 7.07107))), precision));
    mesh.rotate(-pi / 4);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test rotate about a different origin
    mesh = Mesh_2D();
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0, 10))));
    mesh.rotate(pi / 4, Point_2D(10, 0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.92893,-7.07107)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(2.92893, 0))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.92893,-7.07107)), shared_ptr<Point_2D>(new Point_2D(2.92893, 0)), shared_ptr<Point_2D>(new Point_2D(-4.14214, 0))), precision));
    mesh.rotate(-pi / 4, Point_2D(10, 0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test scale
    mesh = Mesh_2D();
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0, 10))));
    mesh.scale(2, 0.5);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20, 0)), shared_ptr<Point_2D>(new Point_2D(10, 2.5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 2.5)), shared_ptr<Point_2D>(new Point_2D(0, 5))), precision));
    mesh.scale(0.5, 2);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test scale about a different origin
    mesh.scale(2, 0.5, Point_2D(10, 0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(0, 2.5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,0)), shared_ptr<Point_2D>(new Point_2D(0, 2.5)), shared_ptr<Point_2D>(new Point_2D(-10, 5))), precision));
    mesh.scale(0.5, 2, Point_2D(10, 0));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test translate
    mesh.translate(5,10);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(15, 10)), shared_ptr<Point_2D>(new Point_2D(10, 15))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(10, 15)), shared_ptr<Point_2D>(new Point_2D(5, 20))), precision));
    mesh.translate(Vector_2D(-5, -10));
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test +=
    mesh += Vector_2D(5, 10);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(15, 10)), shared_ptr<Point_2D>(new Point_2D(10, 15))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(10, 15)), shared_ptr<Point_2D>(new Point_2D(5, 20))), precision));
    mesh += Vector_2D(-5, -10);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test -=
    mesh -= Vector_2D(-5, -10);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(15, 10)), shared_ptr<Point_2D>(new Point_2D(10, 15))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,10)), shared_ptr<Point_2D>(new Point_2D(10, 15)), shared_ptr<Point_2D>(new Point_2D(5, 20))), precision));
    mesh -= Vector_2D(5, 10);
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
    // test *=
    mesh *= 2;
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20, 0)), shared_ptr<Point_2D>(new Point_2D(10, 10))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 10)), shared_ptr<Point_2D>(new Point_2D(0, 20))), precision));
    mesh *= 0.5;
    iter = mesh.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), precision));
//    int count = 0;
//    cout << "\n";
//    for (iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "] p1(x: " << (*iter)->get_point1().get_x() <<
//                " y: " << (*iter)->get_point1().get_y() << ") p2(x: " <<
//                (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() <<
//                ") p3(x: " << (*iter)->get_point3().get_x() << " y: " << 
//                (*iter)->get_point3().get_y() << ")\n";
//    }
//    count = 0;
//    for (iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "] p1(x: " << (*iter)->get_point1().get_x() <<
//                " y: " << (*iter)->get_point1().get_y() << ") p2(x: " <<
//                (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() <<
//                ") p3(x: " << (*iter)->get_point3().get_x() << " y: " << 
//                (*iter)->get_point3().get_y() << ")\n";
//    }
}

void Test_2D::test_intersect_meshes_1()
{
    // facet and other_facet do not intersect
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(5, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(-0.25, 0.25)), shared_ptr<Point_2D>(new Point_2D(-0.25, 0.75)), shared_ptr<Point_2D>(new Point_2D(-0.75, 0.25)));
    mesh1.push_back(facet1);

    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_2()
{
    // facet and other_facet do not intersect
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0.25, 0.5)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.75)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.25)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(5, 0)));
    mesh1.push_back(facet1);

    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25, 0.5)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.25)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.75))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25, 0.5)), shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.25))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0.25, 0.5)), shared_ptr<Point_2D>(new Point_2D(0, 10))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25, 0.5)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.75)), shared_ptr<Point_2D>(new Point_2D(0, 10))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 0)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.25))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.75, 0.25)), shared_ptr<Point_2D>(new Point_2D(5, 0)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.75))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.75, 0.75)), shared_ptr<Point_2D>(new Point_2D(5, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10))), result1, precision));
    assert(result2.size() == 1);
    assert(is_equal(*result2.begin(), facet2, precision));
}

void Test_2D::test_intersect_meshes_3()
{
    // facet and other_facet do not intersect
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(5, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0.25, 0.25)), shared_ptr<Point_2D>(new Point_2D(0.25, 0.75)), shared_ptr<Point_2D>(new Point_2D(0.75, 0.25)));
    mesh1.push_back(facet1);

    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25,0.25)), shared_ptr<Point_2D>(new Point_2D(0.75,0.25)), shared_ptr<Point_2D>(new Point_2D(0.25,0.75))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25,0.25)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0.75,0.25))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0.75,0.25))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25,0.25)), shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.75,0.25)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25,0.25)), shared_ptr<Point_2D>(new Point_2D(0.25,0.75)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.25,0.75)), shared_ptr<Point_2D>(new Point_2D(0.75,0.25)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
}

void Test_2D::test_intersect_meshes_4()
{
    // two corners of otherFacet in facet. otherFacet sides intersect same facet side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(5, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(-5, 3)), shared_ptr<Point_2D>(new Point_2D(1, 2)), shared_ptr<Point_2D>(new Point_2D(0.75, 1)));
    mesh1.push_back(facet1);

    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,1.26087)), shared_ptr<Point_2D>(new Point_2D(0,2.16667)), shared_ptr<Point_2D>(new Point_2D(-5,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,1.26087)), shared_ptr<Point_2D>(new Point_2D(0.75,1)), shared_ptr<Point_2D>(new Point_2D(0,2.16667))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,2.16667)), shared_ptr<Point_2D>(new Point_2D(0.75,1)), shared_ptr<Point_2D>(new Point_2D(1,2))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.75,1)), shared_ptr<Point_2D>(new Point_2D(1,2)), shared_ptr<Point_2D>(new Point_2D(0,1.26087))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,1.26087)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0.75,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0.75,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,2)), shared_ptr<Point_2D>(new Point_2D(0,2.16667)), shared_ptr<Point_2D>(new Point_2D(0,1.26087))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,2.16667)), shared_ptr<Point_2D>(new Point_2D(1,2)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,2)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.75,1)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(1,2))), result2, precision));
}

void Test_2D::test_intersect_meshes_5()
{
    // corner of otherFacet on side of facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(5, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(-5, 3)), shared_ptr<Point_2D>(new Point_2D(0, 5)), shared_ptr<Point_2D>(new Point_2D(-3, -1)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,5)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
}

void Test_2D::test_intersect_meshes_6()
{
    // otherFacet inside facet with a corners crossing each side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0, 3)), shared_ptr<Point_2D>(new Point_2D(5, -1)), shared_ptr<Point_2D>(new Point_2D(10, 3)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,0)), shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,0)), shared_ptr<Point_2D>(new Point_2D(5,-1)), shared_ptr<Point_2D>(new Point_2D(6.25,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(3,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(8.33333,1.66667)), shared_ptr<Point_2D>(new Point_2D(10,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(8.33333,1.66667))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667)), shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(7,3))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,0)), shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,0)), shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(8.33333,1.66667))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667)), shared_ptr<Point_2D>(new Point_2D(7,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(8.33333,1.66667))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.25,0)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(1.66667,1.66667))), result2, precision));
}

void Test_2D::test_intersect_meshes_7()
{
    // otherFacet inside facet with a corner touching each side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(3, 3)), shared_ptr<Point_2D>(new Point_2D(5, 0)), shared_ptr<Point_2D>(new Point_2D(7, 3)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(7,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7,3))), result2, precision));
}

void Test_2D::test_intersect_meshes_8()
{
    // otherFacet has one corner inside
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(2, -3)), shared_ptr<Point_2D>(new Point_2D(4, -3)), shared_ptr<Point_2D>(new Point_2D(3, 1)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.75,0)), shared_ptr<Point_2D>(new Point_2D(2,-3)), shared_ptr<Point_2D>(new Point_2D(3.25,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.75,0)), shared_ptr<Point_2D>(new Point_2D(3.25,0)), shared_ptr<Point_2D>(new Point_2D(3,1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,-3)), shared_ptr<Point_2D>(new Point_2D(4,-3)), shared_ptr<Point_2D>(new Point_2D(3.25,0))), result1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,1)), shared_ptr<Point_2D>(new Point_2D(2.75,0)), shared_ptr<Point_2D>(new Point_2D(3.25,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.75,0)), shared_ptr<Point_2D>(new Point_2D(3,1)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.25,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,1)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.25,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(3,1))), result2, precision));
}

void Test_2D::test_intersect_meshes_9()
{
    // otherFacet has sides passing through facet corners
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(5, 7)), shared_ptr<Point_2D>(new Point_2D(5, 3)), shared_ptr<Point_2D>(new Point_2D(-5, -3)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(0,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(-5,-3)), shared_ptr<Point_2D>(new Point_2D(0,0))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
}

void Test_2D::test_intersect_meshes_10()
{
    // otherFacet has one side passing through corner through opposite side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(5, 7)), shared_ptr<Point_2D>(new Point_2D(5, -3)), shared_ptr<Point_2D>(new Point_2D(-5, -3)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,-3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(-5,-3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,-3)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-5,-3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(-5,-3)), shared_ptr<Point_2D>(new Point_2D(0,0))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
}

void Test_2D::test_intersect_meshes_11()
{
    // otherFacet shares one side with facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 5)), shared_ptr<Point_2D>(new Point_2D(5, 5)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_12()
{
    // otherFacet shares some of one side with facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(0, 5)), shared_ptr<Point_2D>(new Point_2D(3, 3)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(3,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
}

void Test_2D::test_intersect_meshes_13()
{
    // otherFacet has 2 corners inside facet, one side on each of facet corner
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(2, 1)), shared_ptr<Point_2D>(new Point_2D(8, 1)), shared_ptr<Point_2D>(new Point_2D(5, 10)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2.5,2.5)), shared_ptr<Point_2D>(new Point_2D(7.5,2.5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(8,1)), shared_ptr<Point_2D>(new Point_2D(2.5,2.5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,2.5)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,10))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,2.5)), shared_ptr<Point_2D>(new Point_2D(8,1)), shared_ptr<Point_2D>(new Point_2D(7.5,2.5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(7.5,2.5)), shared_ptr<Point_2D>(new Point_2D(5,10))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(8,1)), shared_ptr<Point_2D>(new Point_2D(2.5,2.5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,2.5)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(2,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,2.5)), shared_ptr<Point_2D>(new Point_2D(7.5,2.5)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.5,2.5)), shared_ptr<Point_2D>(new Point_2D(8,1)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(8,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,1)), shared_ptr<Point_2D>(new Point_2D(7.5,2.5)), shared_ptr<Point_2D>(new Point_2D(2.5,2.5))), result2, precision));
}

void Test_2D::test_intersect_meshes_14()
{
    // otherFacet shares corner, two sides pass over facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(10, 0)), shared_ptr<Point_2D>(new Point_2D(4, 3)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(4, 3)), shared_ptr<Point_2D>(new Point_2D(7, 1)), shared_ptr<Point_2D>(new Point_2D(12, 2)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 4);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(12,2))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286))), result1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
}

void Test_2D::test_intersect_meshes_15()
{
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(2, 2)), shared_ptr<Point_2D>(new Point_2D(4, 4)), shared_ptr<Point_2D>(new Point_2D(2.5, 2)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,2)), shared_ptr<Point_2D>(new Point_2D(4,4)), shared_ptr<Point_2D>(new Point_2D(2,2))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(2.5,2))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2.5,2))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4,4)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(4,4)), shared_ptr<Point_2D>(new Point_2D(2.5,2))), result2, precision));
}

void Test_2D::test_intersect_meshes_16()
{
    // shares a corner, but no intersection
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(5, 5)), shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(10, 10)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_17()
{
    // facet shares part of other_facet side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(0, 10)), shared_ptr<Point_2D>(new Point_2D(11, -1)), shared_ptr<Point_2D>(new Point_2D(20, 5)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(20,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(20,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(11,-1)), shared_ptr<Point_2D>(new Point_2D(20,5))), result1, precision));
    assert(result2.size() == 1);
    assert(is_equal(*result2.begin(), facet2, precision));
}

void Test_2D::test_intersect_meshes_18()
{
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0, 0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10, 0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    Facet_2D facet1(shared_ptr<Point_2D>(new Point_2D(-2, 0)), shared_ptr<Point_2D>(new Point_2D(3, 6)), shared_ptr<Point_2D>(new Point_2D(1, -1)));
    mesh1.push_back(facet1);
        
    Mesh_2D result1;
    Mesh_2D result2;
    Intersect_Meshes_2D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1,-1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,-1)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-2,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(-2,0))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result2, precision));
}

void Test_2D::test_intersect_meshes_19()
{
    // intersect mesh with a mesh of one facet. other mesh does not touch facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-1,-1)), shared_ptr<Point_2D>(new Point_2D(-5,-5)), shared_ptr<Point_2D>(new Point_2D(-10,-1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-1,-1)), shared_ptr<Point_2D>(new Point_2D(-10,-1)), shared_ptr<Point_2D>(new Point_2D(-5,2))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,2)), shared_ptr<Point_2D>(new Point_2D(-1,-1)), shared_ptr<Point_2D>(new Point_2D(-3,6))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_20()
{
    // intersect mesh with a mesh of one facet. other mesh corner touches facet side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-5,-3)), shared_ptr<Point_2D>(new Point_2D(-10,-1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-10,-1)), shared_ptr<Point_2D>(new Point_2D(-5,1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,1)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-3,6))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-10,-1)), shared_ptr<Point_2D>(new Point_2D(-5,-3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-5,1)), shared_ptr<Point_2D>(new Point_2D(-10,-1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,1)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(-3,6))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
}

void Test_2D::test_intersect_meshes_21()
{
    // intersect mesh with a mesh of one facet. other mesh shares a side
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-5,-1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(-5,-1)), shared_ptr<Point_2D>(new Point_2D(-3,3))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-5,-1)), shared_ptr<Point_2D>(new Point_2D(-3,6))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_22()
{
    // intersect mesh with a mesh of one facet. other mesh overlaps corner with one facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(8,3)), shared_ptr<Point_2D>(new Point_2D(5,7))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(1,4))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(7,10))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(7,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(8,3)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(1,4))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,3)), shared_ptr<Point_2D>(new Point_2D(7,10)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(7,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(7,3)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7,3))), result2, precision));
}

void Test_2D::test_intersect_meshes_23()
{
    // intersect mesh with a mesh of one facet. other mesh 2 corners cover facet corner
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(5,7))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(1,4))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(12,1))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(5,7)), shared_ptr<Point_2D>(new Point_2D(1,4))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.8,2.2)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.8,2.2)), shared_ptr<Point_2D>(new Point_2D(12,1)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(12,1)), shared_ptr<Point_2D>(new Point_2D(5,7))), result1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(3,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(7.8,2.2)), shared_ptr<Point_2D>(new Point_2D(5,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.8,2.2)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,3)), shared_ptr<Point_2D>(new Point_2D(7.8,2.2)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
}

void Test_2D::test_intersect_meshes_24()
{
    // intersect mesh with a mesh of one facet. other mesh has facet inside facet
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,3)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,3))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7,1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(12,2))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(2,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(3,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(4,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(4,3))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(12,2)), shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result1, precision));
    assert(result2.size() == 11);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(2,2))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(4,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4,3))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(2,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(4,3))), result2, precision));
}

void Test_2D::test_intersect_meshes_25()
{
    // intersect mesh with a mesh of one facet. other mesh completely covers facet with several facets
    Mesh_2D mesh2;
    Facet_2D facet2(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0)));
    mesh2.push_back(facet2);
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,0)), shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(1,-1))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,-1)), shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(5,0))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(7,4))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,4)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(12,-2))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 17);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1,-1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,-1)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-2,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(-2,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(-2,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1,-1)), shared_ptr<Point_2D>(new Point_2D(5,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(1.28571,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(5,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7,4)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,6)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(5,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(12,-2)), shared_ptr<Point_2D>(new Point_2D(10,0))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7,4))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(12,-2)), shared_ptr<Point_2D>(new Point_2D(7,4)), shared_ptr<Point_2D>(new Point_2D(10,0))), result1, precision));
    assert(result2.size() == 6);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(5,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(5,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75))), result2, precision));
}

void Test_2D::test_intersect_meshes_26()
{
    // intersect mesh does not intersect mesh
    Mesh_2D mesh2;
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,4))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))));
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(1,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(3,10))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,6))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,6)), shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(8,8))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_27()
{
    // intersect mesh shares one side with mesh
    Mesh_2D mesh2;
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))));
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(1,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(3,10))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,0))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_2D::test_intersect_meshes_28()
{
    // intersect mesh overlaps part of one facet of mesh
    Mesh_2D mesh2;
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))));
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(1,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(3,10))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(2,1.5))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(0,8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(1.88889,1.88889))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1.88889,1.88889)), shared_ptr<Point_2D>(new Point_2D(2,1.5))), result1, precision));
    assert(result2.size() == 6);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1.5)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1.88889,1.88889))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1.5)), shared_ptr<Point_2D>(new Point_2D(2,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1.5)), shared_ptr<Point_2D>(new Point_2D(1.88889,1.88889)), shared_ptr<Point_2D>(new Point_2D(2,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(1.88889,1.88889)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))), result2, precision));
}

void Test_2D::test_intersect_meshes_29()
{
    // intersect mesh overlaps two mesh facets
    Mesh_2D mesh2;
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))));
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(1,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(3,10))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(4.5,4))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 6);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2,6)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(0,8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(0,8))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,10)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,5)), shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(4.5,4))), result1, precision));
    assert(result2.size() == 8);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(4.5,4)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.5,4)), shared_ptr<Point_2D>(new Point_2D(5,4))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4.5,4))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(4.5,4))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))), result2, precision));
}

void Test_2D::test_intersect_meshes_30()
{
    // intersect mesh facet is in center of facets
    Mesh_2D mesh2;
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,10))));
    mesh2.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,10))));
    Mesh_2D mesh1;
    mesh1.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(6,7))));

    Intersect_Meshes_2D intersect_meshes;
    
    Mesh_2D result1;
    Mesh_2D result2;
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
//    cout << "\n";
//    int count = 0;
//    for (Mesh2_2D::const_iterator it = result1.begin(); it != result1.end(); ++it)
//    {
//        cout << "result1[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " p2 x: " << it->get_point2()->get_x() << 
//                " y: " << it->get_point2()->get_y() << " p3 x: " << 
//                it->get_point3()->get_x() << " y: " << it->get_point3()->get_y() << "\n";
//    }
//    count = 0;
//    for (Mesh2_2D::const_iterator it = result2.begin(); it != result2.end(); ++it)
//    {
//        cout << "result2[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " p2 x: " << it->get_point2()->get_x() << 
//                " y: " << it->get_point2()->get_y() << " p3 x: " << 
//                it->get_point3()->get_x() << " y: " << it->get_point3()->get_y() << "\n";
//    }
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(1,1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4,1))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6,7)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(5,5))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))), result1, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))), result1, precision));
    assert(result2.size() == 15);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(1,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(5,5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(10,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(0,0))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(0.5,1))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6,7)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(6,7)), shared_ptr<Point_2D>(new Point_2D(0,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(6,7)), shared_ptr<Point_2D>(new Point_2D(10,10))), result2, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(10,10)), shared_ptr<Point_2D>(new Point_2D(6,7))), result2, precision));
}

void Test_2D::test_simplify_mesh_1()
{
    // mesh has three facets that should not be reduced
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(8,10))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(!simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(8,10))), mesh, precision));
}

void Test_2D::test_simplify_mesh_2()
{
    // mesh has one internal point to remove
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(8,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6,5)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(6,5))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(6,5))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(0,8))), mesh, precision));
}

void Test_2D::test_simplify_mesh_3()
{
    // mesh has one external point to remove
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(8,10))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(8,10))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), mesh, precision));
}

void Test_2D::test_simplify_mesh_4()
{
    // mesh has three internal points
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.5,7.5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(6.5,7.5)), shared_ptr<Point_2D>(new Point_2D(8,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.5, 7.5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(6.5, 7.5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(0,0))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(10,0))), mesh, precision));
}

void Test_2D::test_simplify_mesh_5()
{
    // mesh has three internal points and 2 external points
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(3,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(6,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.5,7.5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(6.5,7.5)), shared_ptr<Point_2D>(new Point_2D(8,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.5, 7.5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(6.5, 7.5)), shared_ptr<Point_2D>(new Point_2D(10, 0))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8,10)), shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(10,0))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,8)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0))), mesh, precision));
}

void Test_2D::test_simplify_mesh_6()
{
    // reverse intersect_mesh_mesh_12
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(5.25,4.75))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(4,1)), shared_ptr<Point_2D>(new Point_2D(1,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(4,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.25,4.75)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(1,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(4,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(1,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1,1)), shared_ptr<Point_2D>(new Point_2D(0.5,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(1,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(0.5,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0.5,1)), shared_ptr<Point_2D>(new Point_2D(0,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(6,7))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478)), shared_ptr<Point_2D>(new Point_2D(6,7))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(4.56522,5.43478))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5.5,5.5)), shared_ptr<Point_2D>(new Point_2D(10,10)), shared_ptr<Point_2D>(new Point_2D(6,7))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(6,7)), shared_ptr<Point_2D>(new Point_2D(10,10))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,10))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,10))), mesh, precision));
}

void Test_2D::test_simplify_mesh_7()
{
    // reverse intersect_mesh_mesh_11
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.11111,4.11111)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(0,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(4.5,4)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.29412,4.05882)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4.5,4))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4.5,4)), shared_ptr<Point_2D>(new Point_2D(5,4))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(4.5,4))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 3);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(6,0))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,4)), shared_ptr<Point_2D>(new Point_2D(5,5))), mesh, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), mesh, precision));
}

void Test_2D::test_simplify_mesh_8()
{
    // reverse intersect_mesh_mesh_7
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(4.60526,1.18421)), shared_ptr<Point_2D>(new Point_2D(5.49451,0.989011))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.15385,2.30769)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(5.49451,0.989011))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(6.15385,2.30769)), shared_ptr<Point_2D>(new Point_2D(5.49451,0.989011))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.60526,1.18421)), shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.75,3.75)), shared_ptr<Point_2D>(new Point_2D(6.15385,2.30769)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333)), shared_ptr<Point_2D>(new Point_2D(6.15385,2.30769)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(6.15385,2.30769)), shared_ptr<Point_2D>(new Point_2D(6.66667,3.33333))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(4.60526,1.18421))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(5.49451,0.989011)), shared_ptr<Point_2D>(new Point_2D(4.60526,1.18421))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5.49451,0.989011))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.60526,1.18421)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8)), shared_ptr<Point_2D>(new Point_2D(1.28571,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(1.28571,0)), shared_ptr<Point_2D>(new Point_2D(1.8,1.8))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), precision));
}

void Test_2D::test_simplify_mesh_9()
{
    // reverse intersect_mesh_mesh_6
    Mesh_2D mesh;
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(2,2))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(2,2))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,2)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(3,3))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.42857,2.57143)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(8.66667,1.33333))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(7,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.71429,1.14286)), shared_ptr<Point_2D>(new Point_2D(4,3)), shared_ptr<Point_2D>(new Point_2D(7,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(7,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2,1)), shared_ptr<Point_2D>(new Point_2D(7,1)), shared_ptr<Point_2D>(new Point_2D(4,3))));

    Simplify_Mesh_2D simplify_mesh;
    
    assert(simplify_mesh(mesh));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_2D::const_iterator it = mesh.begin(); it != mesh.end(); ++it)
//    {
//        cout << "mesh[" << count++ << "] facet p1 x: " << (*it)->get_point1().get_x() << " y: " <<
//                (*it)->get_point1().get_y() << " p2 x: " << (*it)->get_point2().get_x() << 
//                " y: " << (*it)->get_point2().get_y() << " p3 x: " << 
//                (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y() << "\n";
//    }
    assert(mesh.size() == 1);
    assert(is_equal(*mesh.begin(), Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), precision));
}

void Test_2D::test_m_rectangle_1()
{
    Mesh_2D shape;
    m_rectangle(shape,20,40);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20,40)), shared_ptr<Point_2D>(new Point_2D(0,40))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(20,40))), precision));
}

void Test_2D::test_m_rectangle_2()
{
    Mesh_2D shape;
    m_rectangle(shape,20,40,true);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-20)), shared_ptr<Point_2D>(new Point_2D(10,20)), shared_ptr<Point_2D>(new Point_2D(-10,20))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-20)), shared_ptr<Point_2D>(new Point_2D(10,-20)), shared_ptr<Point_2D>(new Point_2D(10,20))), precision));
}

void Test_2D::test_m_rectangle_3()
{
    Mesh_2D shape;
    m_rectangle(shape,20,40,false,Point_2D(5,-5));
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,-5)), shared_ptr<Point_2D>(new Point_2D(25,35)), shared_ptr<Point_2D>(new Point_2D(5,35))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(5,-5)), shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(25,35))), precision));
}

void Test_2D::test_m_rectangle_4()
{
    Mesh_2D shape;
    m_rectangle(shape,20,40,true,Point_2D(5,-5));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << (*it)->get_point1().get_x() << " y: " <<
//                (*it)->get_point1().get_y() << " p2 x: " << (*it)->get_point2().get_x() << 
//                " y: " << (*it)->get_point2().get_y() << " p3 x: " << 
//                (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y() << "\n";
//    }
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,-25)), shared_ptr<Point_2D>(new Point_2D(15,15)), shared_ptr<Point_2D>(new Point_2D(-5,15))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,-25)), shared_ptr<Point_2D>(new Point_2D(15,-25)), shared_ptr<Point_2D>(new Point_2D(15,15))), precision));
}

void Test_2D::test_m_circle_1()
{
    Mesh_2D shape;
    m_circle(shape,20,3);
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(17.3205,10)), shared_ptr<Point_2D>(new Point_2D(10,17.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10,17.3205)), shared_ptr<Point_2D>(new Point_2D(0,20))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(0,20)), shared_ptr<Point_2D>(new Point_2D(-10,17.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-10,17.3205)), shared_ptr<Point_2D>(new Point_2D(-17.3205,10))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-17.3205,10)), shared_ptr<Point_2D>(new Point_2D(-20,0))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-17.3205,-10))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-17.3205,-10)), shared_ptr<Point_2D>(new Point_2D(-10,-17.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-10,-17.3205)), shared_ptr<Point_2D>(new Point_2D(0,-20))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(0,-20)), shared_ptr<Point_2D>(new Point_2D(10,-17.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10,-17.3205)), shared_ptr<Point_2D>(new Point_2D(17.3205,-10))), shape, precision));
}

void Test_2D::test_m_circle_2()
{
    Mesh_2D shape;
    m_circle(shape,20,3,Point_2D(5,-5));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << (*it)->get_point1().get_x() << " y: " <<
//                (*it)->get_point1().get_y() << " p2 x: " << (*it)->get_point2().get_x() << 
//                " y: " << (*it)->get_point2().get_y() << " p3 x: " << 
//                (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y() << "\n";
//    }
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(22.3205,5)), shared_ptr<Point_2D>(new Point_2D(15,12.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(15,12.3205)), shared_ptr<Point_2D>(new Point_2D(5,15))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(5,15)), shared_ptr<Point_2D>(new Point_2D(-5,12.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(-5,12.3205)), shared_ptr<Point_2D>(new Point_2D(-12.3205,5))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(-12.3205,5)), shared_ptr<Point_2D>(new Point_2D(-15,-5))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-12.3205,-15))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(-12.3205,-15)), shared_ptr<Point_2D>(new Point_2D(-5,-22.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(-5,-22.3205)), shared_ptr<Point_2D>(new Point_2D(5,-25))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(5,-25)), shared_ptr<Point_2D>(new Point_2D(15,-22.3205))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(15,-22.3205)), shared_ptr<Point_2D>(new Point_2D(22.3205,-15))), shape, precision));
}

void Test_2D::test_m_ellipse_1()
{
    Mesh_2D shape;
    m_ellipse(shape,20,20,3);
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-6.66667,18.8562)), shared_ptr<Point_2D>(new Point_2D(-13.3333,14.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-13.3333,-14.9071)), shared_ptr<Point_2D>(new Point_2D(-6.66667,-18.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(0,20)), shared_ptr<Point_2D>(new Point_2D(-6.66667,18.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-6.66667,-18.8562)), shared_ptr<Point_2D>(new Point_2D(0,-20))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,18.8562)), shared_ptr<Point_2D>(new Point_2D(0,20))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(0,-20)), shared_ptr<Point_2D>(new Point_2D(6.66667,-18.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,14.9071)), shared_ptr<Point_2D>(new Point_2D(6.66667,18.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,-18.8562)), shared_ptr<Point_2D>(new Point_2D(13.3333,-14.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,14.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,-14.9071)), shared_ptr<Point_2D>(new Point_2D(20,0))), shape, precision));
}

void Test_2D::test_m_ellipse_2()
{
    Mesh_2D shape;
    m_ellipse(shape,20,20,3,Point_2D(5,-5));
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-1.66667,13.8562)), shared_ptr<Point_2D>(new Point_2D(-8.3333,9.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-8.3333,-19.9071)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-23.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(5,15)), shared_ptr<Point_2D>(new Point_2D(-1.66667,13.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-23.8562)), shared_ptr<Point_2D>(new Point_2D(5,-25))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(11.66667,13.8562)), shared_ptr<Point_2D>(new Point_2D(5,15))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(5,-25)), shared_ptr<Point_2D>(new Point_2D(11.66667,-23.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,9.9071)), shared_ptr<Point_2D>(new Point_2D(11.66667,13.8562))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(11.66667,-23.8562)), shared_ptr<Point_2D>(new Point_2D(18.3333,-19.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,9.9071))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,-19.9071)), shared_ptr<Point_2D>(new Point_2D(25,-5))), shape, precision));
}

void Test_2D::test_m_ellipse_3()
{
    Mesh_2D shape;
    m_ellipse(shape,20,5,3);
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-6.66667,4.71405)), shared_ptr<Point_2D>(new Point_2D(-13.3333,3.72678))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-13.3333,-3.72678)), shared_ptr<Point_2D>(new Point_2D(-6.66667,-4.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(0,5)), shared_ptr<Point_2D>(new Point_2D(-6.66667,4.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(-6.66667,-4.71405)), shared_ptr<Point_2D>(new Point_2D(0,-5))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,4.71405)), shared_ptr<Point_2D>(new Point_2D(0,5))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(0,-5)), shared_ptr<Point_2D>(new Point_2D(6.66667,-4.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,3.72678)), shared_ptr<Point_2D>(new Point_2D(6.66667,4.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(6.66667,-4.71405)), shared_ptr<Point_2D>(new Point_2D(13.3333,-3.72678))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,3.72678))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(13.3333,-3.72678)), shared_ptr<Point_2D>(new Point_2D(20,0))), shape, precision));
}

void Test_2D::test_m_ellipse_4()
{
    Mesh_2D shape;
    m_ellipse(shape,20,5,3,Point_2D(5,-5));
//    cout << "\n";
//    int count = 0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "shape[" << count++ << "] facet p1 x: " << (*it)->get_point1().get_x() << " y: " <<
//                (*it)->get_point1().get_y() << " p2 x: " << (*it)->get_point2().get_x() << 
//                " y: " << (*it)->get_point2().get_y() << " p3 x: " << 
//                (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y() << "\n";
//    }
    assert(shape.size() == 10);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-0.285955)), shared_ptr<Point_2D>(new Point_2D(-8.3333,-1.27322))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-8.3333,-8.72678)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-9.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(5,0)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-0.285955))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(-1.66667,-9.71405)), shared_ptr<Point_2D>(new Point_2D(5,-10))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(11.66667,-0.285955)), shared_ptr<Point_2D>(new Point_2D(5,0))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(5,-10)), shared_ptr<Point_2D>(new Point_2D(11.66667,-9.71405))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,-1.27322)), shared_ptr<Point_2D>(new Point_2D(11.66667,-0.285955))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(11.66667,-9.71405)), shared_ptr<Point_2D>(new Point_2D(18.3333,-8.72678))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(25,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,-1.27322))), shape, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,-5)), shared_ptr<Point_2D>(new Point_2D(18.3333,-8.72678)), shared_ptr<Point_2D>(new Point_2D(25,-5))), shape, precision));
}

void Test_2D::test_rotate_1()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.rotate(pi / 6);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(-1.33975,22.3205)), shared_ptr<Point_2D>(new Point_2D(-10,17.3205))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(8.66025,5)), shared_ptr<Point_2D>(new Point_2D(-1.33975,22.3205))), precision));
}

void Test_2D::test_rotate_2()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.rotate(-pi / 6);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(18.6603,12.3205)), shared_ptr<Point_2D>(new Point_2D(10,17.3205))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(8.66025,-5)), shared_ptr<Point_2D>(new Point_2D(18.6603,12.3205))), precision));
}

void Test_2D::test_rotate_3()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.rotate(pi / 6, Point_2D(50,10));
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.6987,-23.6603)), shared_ptr<Point_2D>(new Point_2D(10.359,-1.33975)), shared_ptr<Point_2D>(new Point_2D(1.69873,-6.33975))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.6987,-23.6603)), shared_ptr<Point_2D>(new Point_2D(20.359,-18.6603)), shared_ptr<Point_2D>(new Point_2D(10.359,-1.33975))), precision));
}

void Test_2D::test_rotate_4()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.rotate(-pi / 6, Point_2D(50,10));
//    cout << gen_openscad_polygon(shape,2) << '\n';
//    int count=0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_2D(Point_2D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << "), Point_2D(" << 
//                (*it)->get_point2().get_x() << ',' << (*it)->get_point2().get_y() << "), Point_2D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ")), precision));\n";
//    }
////    cout << "shape size: " << shape.size() << "\n";
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.69873,26.3397)), shared_ptr<Point_2D>(new Point_2D(20.359,38.6603)), shared_ptr<Point_2D>(new Point_2D(11.6987,43.6603))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.69873,26.3397)), shared_ptr<Point_2D>(new Point_2D(10.359,21.3397)), shared_ptr<Point_2D>(new Point_2D(20.359,38.6603))), precision));
}

void Test_2D::test_scale_1()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.scale(2,1);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20,20)), shared_ptr<Point_2D>(new Point_2D(0,20))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(20,20))), precision));
}

void Test_2D::test_scale_2()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.scale(1,0.5);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,10)), shared_ptr<Point_2D>(new Point_2D(0,10))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(10,10))), precision));
}

void Test_2D::test_scale_3()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.scale(2,1, Point_2D(5,10));
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,0)), shared_ptr<Point_2D>(new Point_2D(15,20)), shared_ptr<Point_2D>(new Point_2D(-5,20))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-5,0)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(15,20))), precision));
}

void Test_2D::test_scale_4()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.scale(1,0.5, Point_2D(5,10));
//    cout << gen_openscad_polygon(shape,2) << '\n';
//    int count=0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_2D(Point_2D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << "), Point_2D(" << 
//                (*it)->get_point2().get_x() << ',' << (*it)->get_point2().get_y() << "), Point_2D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ")), precision));\n";
//    }
////    cout << "shape size: " << shape.size() << "\n";
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,5)), shared_ptr<Point_2D>(new Point_2D(10,15)), shared_ptr<Point_2D>(new Point_2D(0,15))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,5)), shared_ptr<Point_2D>(new Point_2D(10,5)), shared_ptr<Point_2D>(new Point_2D(10,15))), precision));
}

void Test_2D::test_translate_1()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.translate(-10,-10);
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-10)), shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(-10,10))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-10)), shared_ptr<Point_2D>(new Point_2D(0,-10)), shared_ptr<Point_2D>(new Point_2D(0,10))), precision));
}

void Test_2D::test_translate_2()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.translate(Vector_2D(-10,-10));
//    cout << gen_openscad_polygon(shape,2) << '\n';
//    int count=0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_2D(Point_2D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << "), Point_2D(" << 
//                (*it)->get_point2().get_x() << ',' << (*it)->get_point2().get_y() << "), Point_2D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ")), precision));\n";
//    }
////    cout << "shape size: " << shape.size() << "\n";
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-10)), shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(-10,10))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10,-10)), shared_ptr<Point_2D>(new Point_2D(0,-10)), shared_ptr<Point_2D>(new Point_2D(0,10))), precision));
}

void Test_2D::test_move_1()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.move(Point_2D(0,0), Vector_2D(0,-1), true, Point_2D(10,20));
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,10)), shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(0,10))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,10)), shared_ptr<Point_2D>(new Point_2D(-20,0)), shared_ptr<Point_2D>(new Point_2D(0,0))), precision));
}

void Test_2D::test_move_2()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
    shape.move(Point_2D(0,10), Vector_2D(1,1), false, Point_2D(5,0));
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-3.53553,13.5355)), shared_ptr<Point_2D>(new Point_2D(17.6777,20.6066)), shared_ptr<Point_2D>(new Point_2D(10.6066,27.6777))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-3.53553,13.5355)), shared_ptr<Point_2D>(new Point_2D(3.53553,6.46447)), shared_ptr<Point_2D>(new Point_2D(17.6777,20.6066))), precision));
}

void Test_2D::test_move_3()
{
    Mesh_2D shape;
    m_rectangle(shape,10,20);
//    cout << '\n' << gen_openscad_polygon(shape,2) << '\n';
    shape.move(Point_2D(0,10), Vector_2D(1,-1), true, Point_2D(5,20));
//    cout << gen_openscad_polygon(shape,2) << '\n';
//    int count=0;
//    for (Mesh_2D::const_iterator it = shape.begin(); it != shape.end(); ++it)
//    {
//        cout << "    assert(is_equal(*shape.at(" << count++ << "), Facet_2D(Point_2D(" <<
//                (*it)->get_point1().get_x() << ',' << (*it)->get_point1().get_y() << "), Point_2D(" << 
//                (*it)->get_point2().get_x() << ',' << (*it)->get_point2().get_y() << "), Point_2D(" <<
//                (*it)->get_point3().get_x() << ',' << (*it)->get_point3().get_y() << ")), precision));\n";
//    }
    assert(shape.size() == 2);
    Mesh_2D::const_iterator iter(shape.begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-17.6777,-0.606602)), shared_ptr<Point_2D>(new Point_2D(3.53553,6.46447)), shared_ptr<Point_2D>(new Point_2D(-3.53553,13.5355))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(-17.6777,-0.606602)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-7.67767)), shared_ptr<Point_2D>(new Point_2D(3.53553,6.46447))), precision));
}

void Test_2D::test_mesh_difference_1()
{
    // shapes do not overlap
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10,false, Point_2D(20,20));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
}

void Test_2D::test_mesh_difference_2()
{
    // test shapes share side
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10,false, Point_2D(10,0));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.difference(shape,shape2, result);
    assert(result.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
}

void Test_2D::test_mesh_difference_3()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.difference(shape,shape2,result);
    assert(result.size() == 24);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066))), result, precision));
}

void Test_2D::test_mesh_difference_4()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2,Point_2D(0,20));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.difference(shape,shape2,result);
    assert(result.size() == 12);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(12.8033,14.6967)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(3.96447,6.64214))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579)), shared_ptr<Point_2D>(new Point_2D(-12.8033,14.6967))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.96447,6.64214)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-10.6066,9.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5)), shared_ptr<Point_2D>(new Point_2D(-10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421))), result, precision));
}

void Test_2D::test_mesh_difference_5()
{
    // shapes are the same
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.difference(shape,shape2,result);
//    cout << "\n";
//    cout << "result: polygon(points=[";
//    for (Mesh2_2D::const_point_iterator p_it = result.point_begin(); p_it != result.point_end(); ++p_it)
//    {
//        if (p_it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*p_it)->get_x() << ',' << (*p_it)->get_y() << ']';
//    }
//    cout << "], paths=[";
//    for (Mesh2_2D::const_facet_iterator f_it = result.facet_begin(); f_it != result.facet_end(); ++f_it)
//    {
//        if (f_it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << f_it->get_p1_index() << ',' << f_it->get_p3_index() << ',' << f_it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    int count = 0;
//    for (Mesh2_2D::const_iterator it = result.begin(); it != result.end(); ++it)
//    {
//        cout << "result[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " p2 x: " << it->get_point2()->get_x() << 
//                " y: " << it->get_point2()->get_y() << " p3 x: " << 
//                it->get_point3()->get_x() << " y: " << it->get_point3()->get_y() << "\n";
//    }
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_2D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_2D(shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point1()->get_x() << ',' << iter->get_point1()->get_y() << 
//                ")), shared_ptr<Point_2D>(new Point_2D(" << iter->get_point2()->get_x() << 
//                ',' << iter->get_point2()->get_y() << ")), shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << "))), result, precision));\n";
//    }
    assert(result.empty());
}

void Test_2D::test_mesh_intersection_1()
{
    // shapes completely overlap
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.intersection(shape,shape2,result);
    assert(result.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
}

void Test_2D::test_mesh_intersection_2()
{
    // test shapes share side
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10,false, Point_2D(10,0));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.intersection(shape,shape2,result);
    assert(result.empty());
}

void Test_2D::test_mesh_intersection_3()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.intersection(shape,shape2,result);
    assert(result.size() == 18);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(15,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645))), result, precision));
}

void Test_2D::test_mesh_intersection_4()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2,Point_2D(0,20));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.intersection(shape,shape2,result);
    assert(result.size() == 16);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066)), shared_ptr<Point_2D>(new Point_2D(7.5,12.5)), shared_ptr<Point_2D>(new Point_2D(7.5,16.8934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.5,12.5)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(10.6066,15.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066)), shared_ptr<Point_2D>(new Point_2D(7.5,16.8934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(12.8033,14.6967)), shared_ptr<Point_2D>(new Point_2D(10.6066,15.6066)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,15.6066)), shared_ptr<Point_2D>(new Point_2D(7.5,16.8934)), shared_ptr<Point_2D>(new Point_2D(7.5,12.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066)), shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355)), shared_ptr<Point_2D>(new Point_2D(7.5,12.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(7.5,12.5)), shared_ptr<Point_2D>(new Point_2D(2.32233,7.32233)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(-12.8033,14.6967)), shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.96447,6.64214)), shared_ptr<Point_2D>(new Point_2D(10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(2.32233,7.32233))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.32233,7.32233)), shared_ptr<Point_2D>(new Point_2D(7.5,12.5)), shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355)), shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066)), shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-12.8033,14.6967)), shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579)), shared_ptr<Point_2D>(new Point_2D(4.3934,15.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355)), shared_ptr<Point_2D>(new Point_2D(-12.2487,13.3579))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,9.3934)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5)), shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.32233,7.32233)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5)), shared_ptr<Point_2D>(new Point_2D(3.96447,6.64214))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.32233,7.32233)), shared_ptr<Point_2D>(new Point_2D(-6.64214,11.0355)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,5))), result, precision));
}

void Test_2D::test_mesh_intersection_5()
{
    // shapes are the same
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.intersection(shape,shape2,result);
//    cout << "\n";
//    cout << "result: polygon(points=[";
//    for (Mesh2_2D::const_point_iterator p_it = result.point_begin(); p_it != result.point_end(); ++p_it)
//    {
//        if (p_it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*p_it)->get_x() << ',' << (*p_it)->get_y() << ']';
//    }
//    cout << "], paths=[";
//    for (Mesh2_2D::const_facet_iterator f_it = result.facet_begin(); f_it != result.facet_end(); ++f_it)
//    {
//        if (f_it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << f_it->get_p1_index() << ',' << f_it->get_p3_index() << ',' << f_it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    int count = 0;
//    for (Mesh2_2D::const_iterator it = result.begin(); it != result.end(); ++it)
//    {
//        cout << "result[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " p2 x: " << it->get_point2()->get_x() << 
//                " y: " << it->get_point2()->get_y() << " p3 x: " << 
//                it->get_point3()->get_x() << " y: " << it->get_point3()->get_y() << "\n";
//    }
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_2D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_2D(shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point1()->get_x() << ',' << iter->get_point1()->get_y() << 
//                ")), shared_ptr<Point_2D>(new Point_2D(" << iter->get_point2()->get_x() << 
//                ',' << iter->get_point2()->get_y() << ")), shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << "))), result, precision));\n";
//    }
    assert(result.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
}

void Test_2D::test_mesh_merge_1()
{
    // shapes do not touch
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10, false, Point_2D(0,15));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.merge(shape,shape2,result);
    assert(result.size() == 4);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,15)),shared_ptr<Point_2D>(new Point_2D(10,25)),shared_ptr<Point_2D>(new Point_2D(0,25))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,15)),shared_ptr<Point_2D>(new Point_2D(10,15)),shared_ptr<Point_2D>(new Point_2D(10,25))),result,precision));
}

void Test_2D::test_mesh_merge_2()
{
    // test shapes share side
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10,false, Point_2D(10,5));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.merge(shape,shape2,result);
    assert(result.size() == 6);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,5)),shared_ptr<Point_2D>(new Point_2D(0,0))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,5)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,0))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,5)),shared_ptr<Point_2D>(new Point_2D(20,15)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,15)),shared_ptr<Point_2D>(new Point_2D(10,15)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,5)),shared_ptr<Point_2D>(new Point_2D(20,5)),shared_ptr<Point_2D>(new Point_2D(20,15))),result,precision));
}

void Test_2D::test_mesh_merge_3()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.merge(shape,shape2,result);
    assert(result.size() == 42);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,8.53553)), shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,11.4645)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(9.18485e-16,15)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(13.9645,2.5)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,11.6421)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,10.6066)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(15,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(15,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-15,1.83697e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-10.6066,-10.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(13.9645,-2.5)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(11.4645,-3.53553))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-8.1066,-11.6421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(11.4645,-8.53553)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(8.53553,-11.4645)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(10.6066,-10.6066))), result, precision));
}

void Test_2D::test_mesh_merge_4()
{
    // test shape inside shape
    Mesh_2D shape;
    m_circle(shape,20,2);
    Mesh_2D shape2;
    m_circle(shape2,15,2,Point_2D(0,30));
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.merge(shape,shape2,result);
    assert(result.size() == 24);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,17.5)), shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645)), shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(2.5,17.5)), shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645)), shared_ptr<Point_2D>(new Point_2D(14.1421,14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355)), shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,15)), shared_ptr<Point_2D>(new Point_2D(2.5,17.5)), shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,15)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(2.5,17.5)), shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,15)), shared_ptr<Point_2D>(new Point_2D(3.53553,16.4645))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(2.5,17.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-2.75546e-15,15)), shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(20,0))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-14.1421,14.1421)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-20,2.44929e-15)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-14.1421,-14.1421)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(20,0)), shared_ptr<Point_2D>(new Point_2D(-3.67394e-15,-20)), shared_ptr<Point_2D>(new Point_2D(14.1421,-14.1421))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(10.6066,40.6066)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,45))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(9.18485e-16,45)), shared_ptr<Point_2D>(new Point_2D(-10.6066,40.6066))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(-10.6066,40.6066)), shared_ptr<Point_2D>(new Point_2D(-15,30))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(-15,30)), shared_ptr<Point_2D>(new Point_2D(-10.6066,19.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-10.6066,19.3934)), shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(15,30))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355)), shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(-6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(1.22465e-15,20)), shared_ptr<Point_2D>(new Point_2D(15,30))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(15,30)), shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355)), shared_ptr<Point_2D>(new Point_2D(10.6066,19.3934))), result, precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(6.03553,17.5)), shared_ptr<Point_2D>(new Point_2D(10.6066,19.3934)), shared_ptr<Point_2D>(new Point_2D(3.53553,18.5355))), result, precision));
}

void Test_2D::test_mesh_merge_5()
{
    // shapes are the same
    Mesh_2D shape;
    m_rectangle(shape,10,10);
    Mesh_2D shape2;
    m_rectangle(shape2,10,10);
    Mesh_2D result;
    Intersect_Meshes_2D intersect_meshes;
    intersect_meshes.merge(shape,shape2,result);
//    cout << "\n";
//    cout << "result: polygon(points=[";
//    for (Mesh2_2D::const_point_iterator p_it = result.point_begin(); p_it != result.point_end(); ++p_it)
//    {
//        if (p_it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*p_it)->get_x() << ',' << (*p_it)->get_y() << ']';
//    }
//    cout << "], paths=[";
//    for (Mesh2_2D::const_facet_iterator f_it = result.facet_begin(); f_it != result.facet_end(); ++f_it)
//    {
//        if (f_it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << f_it->get_p1_index() << ',' << f_it->get_p3_index() << ',' << f_it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    int count = 0;
//    for (Mesh2_2D::const_iterator it = result.begin(); it != result.end(); ++it)
//    {
//        cout << "result[" << count++ << "] facet p1 x: " << it->get_point1()->get_x() << " y: " <<
//                it->get_point1()->get_y() << " p2 x: " << it->get_point2()->get_x() << 
//                " y: " << it->get_point2()->get_y() << " p3 x: " << 
//                it->get_point3()->get_x() << " y: " << it->get_point3()->get_y() << "\n";
//    }
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_2D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_2D(shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point1()->get_x() << ',' << iter->get_point1()->get_y() << 
//                ")), shared_ptr<Point_2D>(new Point_2D(" << iter->get_point2()->get_x() << 
//                ',' << iter->get_point2()->get_y() << ")), shared_ptr<Point_2D>(new Point_2D(" << 
//                iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << "))), result, precision));\n";
//    }
    assert(result.size() == 2);
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,10)),shared_ptr<Point_2D>(new Point_2D(0,10))),result,precision));
    assert(mesh_contains(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)),shared_ptr<Point_2D>(new Point_2D(10,0)),shared_ptr<Point_2D>(new Point_2D(10,10))),result,precision));
}

void Test_2D::test_valid_mesh_1()
{
    Mesh_2D mesh;
    
    // create an unaligned point 3,3
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(0,3))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(3,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,3))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,3)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,-5)), shared_ptr<Point_2D>(new Point_2D(10,0))));
    
    Valid_Mesh_2D valid(mesh);
    assert(!valid.validate());
    assert(!valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 1);
    assert(is_equal(**valid.pts_on_side_begin(), Point_2D(3,3), precision));
    assert(valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 0);
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
}

void Test_2D::test_valid_mesh_2()
{
    Mesh_2D mesh;
    
    // create a facet within a facet
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(3,3))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2,1))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,10))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,10)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(10,10))));
    
    Valid_Mesh_2D valid(mesh);
    assert(!valid.validate());
    assert(!valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 1);
    assert(is_equal(**valid.pts_on_side_begin(), Point_2D(3,3), precision));
    assert(!valid.too_many_share_side_empty());
//    cout << "\ntoo many share side size: " << valid.too_many_share_side_size() << "\n";
//    for (Valid_Mesh_2D::too_many_share_side_iterator iter = valid.too_many_share_side_begin(); iter != valid.too_many_share_side_end(); ++iter)
//    {
//        cout << "Group of Facets\n";
//        for (vector<Facet_2D>::const_iterator iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
//        {
//            cout << "    Facet_2D p1 x: " << iter2->get_point1()->get_x() << " y: " << iter2->get_point1()->get_y() <<
//                    " p2 x: " << iter2->get_point2()->get_x() << " y: " << iter2->get_point2()->get_y() << " p3 x: " << 
//                    iter2->get_point3()->get_x() << " y: " << iter2->get_point3()->get_y() << "\n";
//        }
//    }
    assert(valid.too_many_share_side_size() == 1);
    assert(valid.too_many_share_side_begin()->size() == 3);
    vector<Facet_2D>::const_iterator iter(valid.too_many_share_side_begin()->begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(3,3))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2,1))), precision));
    assert(!valid.facets_inside_facet_empty());
//    cout << "\nfacets_inside_facets size: " << valid.facets_inside_facet_size() << "\n";
//    for (Valid_Mesh_2D::facets_inside_facet_iterator iter = valid.facets_inside_facet_begin(); iter != valid.facets_inside_facet_end(); ++iter)
//    {
//        cout << "Large facet p1 x: " << iter->first.get_point1()->get_x() << " y: " << iter->first.get_point1()->get_y() << 
//                " p2 x: " << iter->first.get_point2()->get_x() << " y: " << iter->first.get_point2()->get_y() << " p3 x: " <<
//                iter->first.get_point3()->get_x() << " y: " << iter->first.get_point3()->get_y() << "\n";
//        for (vector<Facet_2D>::const_iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
//        {
//            cout << "    Facet_2D p1 x: " << iter2->get_point1()->get_x() << " y: " << iter2->get_point1()->get_y() <<
//                    " p2 x: " << iter2->get_point2()->get_x() << " y: " << iter2->get_point2()->get_y() << " p3 x: " << 
//                    iter2->get_point3()->get_x() << " y: " << iter2->get_point3()->get_y() << "\n";
//        }
//    }
    assert(valid.facets_inside_facet_size() == 2);
    pair<Facet_2D,vector<Facet_2D>> p(*valid.facets_inside_facet_begin());
    assert(is_equal(p.first, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(3,3))), precision));
    assert(p.second.size() == 1);
    assert(is_equal(*p.second.begin(), Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2,1))), precision));
    p = *++valid.facets_inside_facet_begin();
    assert(is_equal(p.first, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(p.second.size() == 2);
    iter = p.second.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(3,3))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(2,1))), precision));
}

void Test_2D::test_valid_mesh_3()
{
    Mesh_2D mesh;
    
    // create invalid facets
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5.00001,4.99999)), shared_ptr<Point_2D>(new Point_2D(5,5))));
    mesh.push_back(Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))));
    
    Valid_Mesh_2D valid(mesh);
    assert(!valid.validate());
    assert(!valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 1);
    assert(is_equal(**valid.pts_on_side_begin(), Point_2D(5,5), precision));
//    cout << "\ntoo many share side size: " << valid.too_many_share_side_size() << "\n";
//    for (Valid_Mesh_2D::too_many_share_side_iterator iter = valid.too_many_share_side_begin(); iter != valid.too_many_share_side_end(); ++iter)
//    {
//        cout << "Group of Facets\n";
//        for (vector<Facet_2D>::const_iterator iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
//        {
//            cout << "    Facet_2D p1 x: " << iter2->get_point1()->get_x() << " y: " << iter2->get_point1()->get_y() <<
//                    " p2 x: " << iter2->get_point2()->get_x() << " y: " << iter2->get_point2()->get_y() << " p3 x: " << 
//                    iter2->get_point3()->get_x() << " y: " << iter2->get_point3()->get_y() << "\n";
//        }
//    }
    assert(!valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 1);
    assert(valid.too_many_share_side_begin()->size() == 3);
    vector<Facet_2D>::const_iterator iter(valid.too_many_share_side_begin()->begin());
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5.00001,4.99999)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), precision));
    assert(!valid.facets_inside_facet_empty());
//    cout << "\nfacets_inside_facets size: " << valid.facets_inside_facet_size() << "\n";
//    for (Valid_Mesh_2D::facets_inside_facet_iterator iter = valid.facets_inside_facet_begin(); iter != valid.facets_inside_facet_end(); ++iter)
//    {
//        cout << "Large facet p1 x: " << iter->first.get_point1()->get_x() << " y: " << iter->first.get_point1()->get_y() << 
//                " p2 x: " << iter->first.get_point2()->get_x() << " y: " << iter->first.get_point2()->get_y() << " p3 x: " <<
//                iter->first.get_point3()->get_x() << " y: " << iter->first.get_point3()->get_y() << "\n";
//        for (vector<Facet_2D>::const_iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
//        {
//            cout << "    Facet_2D p1 x: " << iter2->get_point1()->get_x() << " y: " << iter2->get_point1()->get_y() <<
//                    " p2 x: " << iter2->get_point2()->get_x() << " y: " << iter2->get_point2()->get_y() << " p3 x: " << 
//                    iter2->get_point3()->get_x() << " y: " << iter2->get_point3()->get_y() << "\n";
//        }
//    }
    assert(!valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 2);
    pair<Facet_2D,vector<Facet_2D>> p(*valid.facets_inside_facet_begin());
    assert(is_equal(p.first, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(p.second.size() == 1);
    assert(is_equal(*p.second.begin(), Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5.00001,4.99999)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    p = *++valid.facets_inside_facet_begin();
    assert(is_equal(p.first, Facet_2D(shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5)), shared_ptr<Point_2D>(new Point_2D(0,0))), precision));
    assert(p.second.size() == 2);
    iter = p.second.begin();
    assert(is_equal(*iter++, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(10,0)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
    assert(is_equal(*iter, Facet_2D(shared_ptr<Point_2D>(new Point_2D(0,0)), shared_ptr<Point_2D>(new Point_2D(5.00001,4.99999)), shared_ptr<Point_2D>(new Point_2D(5,5))), precision));
}

void Test_2D::test_valid_mesh_4()
{
    Mesh_2D mesh;
    
    // create valid facets
    m_ellipse(mesh, 10, 20, 4);
    
    Valid_Mesh_2D valid(mesh);
    assert(valid.validate());
//    for (int i = 0; i < valid.unaligned_points_size(); ++i)
//    {
//        Point_2D p(valid.unaligned_point_at(i));
//        cout << "unaligned_points[" << i << "]: x: " << p.get_x() << " y: " << p.get_y() << "\n";
//    }
    assert(valid.pts_on_side_empty());
    assert(valid.pts_on_side_size() == 0);
//    assert(within_round(valid.unaligned_point_at(0), Point_2D(5,5), precision));
//    for (int i = 0; i < valid.facets_with_facets_size(); ++i)
//    {
//        Facet_2D f(valid.facets_with_facets_at(i));
//        cout << "facets_with_facets[" << i << "]: p1 x: " << f.get_point1().get_x() <<
//                " y: " << f.get_point1().get_y() << " p2 x: " << f.get_point2().get_x() <<
//                " y: " << f.get_point2().get_y() << " p3 x: " << f.get_point3().get_x() <<
//                " y: " << f.get_point3().get_y() << "\n";
//    }
    assert(valid.facets_inside_facet_empty());
    assert(valid.facets_inside_facet_size() == 0);
//    for (int i = 0; i < valid.too_many_facets_size(); ++i)
//    {
//        Facet_2D f(valid.too_many_facets_at(i));
//        cout << "too_many_facets[" << i << "]: p1 x: " << f.get_point1().get_x() <<
//                " y: " << f.get_point1().get_y() << " p2 x: " << f.get_point2().get_x() <<
//                " y: " << f.get_point2().get_y() << " p3 x: " << f.get_point3().get_x() <<
//                " y: " << f.get_point3().get_y() << "\n";
//    }
    assert(valid.too_many_share_side_empty());
    assert(valid.too_many_share_side_size() == 0);
//    assert(is_equal(valid.too_many_facets_at(0), Facet_2D(Point_2D(0,0), Point_2D(10,0), Point_2D(5,5)), precision));
//    assert(is_equal(valid.too_many_facets_at(1), Facet_2D(Point_2D(0,0), Point_2D(5.00001,4.99999), Point_2D(5,5)), precision));
}
