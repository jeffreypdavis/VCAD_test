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
 * File:   Test_3D_Intersect.cpp
 * Author: Jeffrey Davis
 */

#include "Test_3D.h"

void Test_3D::test_intersect_meshes_1()
{
    // different planes: no intersection - parallel
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 1)), shared_ptr<Point_3D>(new Point_3D(0, 10, 1)), shared_ptr<Point_3D>(new Point_3D(5, 0, 1)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(-5, 3, 0)), shared_ptr<Point_3D>(new Point_3D(1, 2, 0)), shared_ptr<Point_3D>(new Point_3D(0.75, 1, 0)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_2()
{
    // different planes: corner touches corner
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 5)), shared_ptr<Point_3D>(new Point_3D(1, 2, 5)), shared_ptr<Point_3D>(new Point_3D(0.75, 1, 5)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_3()
{
    // different planes: corner touches side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 3)), shared_ptr<Point_3D>(new Point_3D(1, 2, 3)), shared_ptr<Point_3D>(new Point_3D(0.75, 1, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
}

void Test_3D::test_intersect_meshes_4()
{
    // different planes: side touches side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(-1, 0, 3)), shared_ptr<Point_3D>(new Point_3D(1, 0, 3)), shared_ptr<Point_3D>(new Point_3D(-0.75, -1, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,0,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(-0.75,-1,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,0,3)), shared_ptr<Point_3D>(new Point_3D(-0.75,-1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
}

void Test_3D::test_intersect_meshes_5()
{
    // different planes: corner touches inside of facet
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 1, 3)), shared_ptr<Point_3D>(new Point_3D(1, 2, 3)), shared_ptr<Point_3D>(new Point_3D(0.75, 1, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,1,3))), result2, precision));
}

void Test_3D::test_intersect_meshes_6()
{
    // different planes: corner pierces inside of facet
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(-0.5, 1, 3)), shared_ptr<Point_3D>(new Point_3D(1, 1, 3)), shared_ptr<Point_3D>(new Point_3D(1, 2, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3)), shared_ptr<Point_3D>(new Point_3D(-0.5,1,3))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(1,1,3)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1.33333,3)), shared_ptr<Point_3D>(new Point_3D(1,1,3)), shared_ptr<Point_3D>(new Point_3D(1,2,3))), result1, 0.0001));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1.33333,3))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1.33333,3)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, 0.0001));
}

void Test_3D::test_intersect_meshes_7()
{
    // different planes: 1 side inside, 1 side out
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(-1, 1, 3)), shared_ptr<Point_3D>(new Point_3D(1, 1, 3)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(-1,1,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,3)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,1,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,1,3)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_8()
{
    // different planes: other facet outside, facet inside
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(1, -2, 4)), shared_ptr<Point_3D>(new Point_3D(-2, -3, 4)), shared_ptr<Point_3D>(new Point_3D(0, 10, 4)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(1,-2,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,-2,4)), shared_ptr<Point_3D>(new Point_3D(-2,-3,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(-2,-3,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,-2,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,10,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(-2,-3,4)), shared_ptr<Point_3D>(new Point_3D(0,10,4))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
}

void Test_3D::test_intersect_meshes_9()
{
    // one side on same plane: no intersection
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -1, 0)), shared_ptr<Point_3D>(new Point_3D(0, -1, 5)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_10()
{
    // one side on same plane: share same side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_11()
{
    // one side on same plane: share same side, but other_facet side is longer
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, -1)), shared_ptr<Point_3D>(new Point_3D(0, 0, 6)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);
    
    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,6)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(result2.size() == 1);
    assert(is_equal(*result2.begin(), facet2, precision));
}

void Test_3D::test_intersect_meshes_12()
{
    // one side on same plane: touches corner
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 5)), shared_ptr<Point_3D>(new Point_3D(0, 0, 6)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_13()
{
    // one side on same plane: side smaller than side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 1)), shared_ptr<Point_3D>(new Point_3D(0, 0, 4)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_14()
{
    // one side on same plane: side half in, half out
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 7)), shared_ptr<Point_3D>(new Point_3D(0, 0, 3)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,7)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,3)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,3))), result2, precision));
}

void Test_3D::test_intersect_meshes_15()
{
    // one side on same plane: side half in, through a corner point
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0, -1, -1)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-1,-1)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,1,1))), result2, precision));
}

void Test_3D::test_intersect_meshes_16()
{
    // one side on same plane: side half in, half out
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, 1)), shared_ptr<Point_3D>(new Point_3D(0, 0, -1)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-1)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,1,0))), result1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,2,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,2,1))), result2, precision));
}

void Test_3D::test_intersect_meshes_17()
{
    // one side on same plane: cross facet
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, -1)), shared_ptr<Point_3D>(new Point_3D(0, 2, 6)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,-1)), shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,2,6)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_18()
{
    // one side on same plane: side half in, half out
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, 1)), shared_ptr<Point_3D>(new Point_3D(0, 2, 6)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(1,-10,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,6)), shared_ptr<Point_3D>(new Point_3D(1,-10,3)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_19()
{
    // one side on same plane: side inside
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, 1)), shared_ptr<Point_3D>(new Point_3D(0, 2, 3)), shared_ptr<Point_3D>(new Point_3D(1, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_20()
{
    // facets on same plane: no intersection
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 1)), shared_ptr<Point_3D>(new Point_3D(0, -2, 6)), shared_ptr<Point_3D>(new Point_3D(0, -10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_21()
{                  
    // facets on similar plane: no intersection
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0.1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0.1, 1, 2)), shared_ptr<Point_3D>(new Point_3D(0.1, 2, 1)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_22()
{
    // facets on same plane: share corner
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 12, 0)), shared_ptr<Point_3D>(new Point_3D(0, 11, 2)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_23()
{
    // facets on same plane: share side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)), shared_ptr<Point_3D>(new Point_3D(0, 8, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_24()
{
    // facets on same plane: share side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 6)), shared_ptr<Point_3D>(new Point_3D(0, 12, -1)), shared_ptr<Point_3D>(new Point_3D(0, 12, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,6)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,12,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,12,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,12,-1)), shared_ptr<Point_3D>(new Point_3D(0,12,10))), result1, precision));
    assert(result2.size() == 1);
    assert(is_equal(*result2.begin(), facet2, precision));
}

void Test_3D::test_intersect_meshes_25()
{
    // facets on same plane: share part of side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 6)), shared_ptr<Point_3D>(new Point_3D(0, 2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,6)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_26()
{
    // facets on same plane: partial side intersection
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 12, -1)), shared_ptr<Point_3D>(new Point_3D(0, 2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,12,-1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_27()
{
    // facets on same plane: side inside side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 8, 1)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,8,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,8,1)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_28()
{
    // facets on same plane: two side through corners
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -5, -1)), shared_ptr<Point_3D>(new Point_3D(0, 5, 1)), shared_ptr<Point_3D>(new Point_3D(0, 15, -1)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-5,-1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,15,-1)), shared_ptr<Point_3D>(new Point_3D(0,-5,-1))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,5,1))), result2, precision));
}

void Test_3D::test_intersect_meshes_29()
{
    // facets on same plane: one side through corner, one side through side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -5, -1)), shared_ptr<Point_3D>(new Point_3D(0, 5, 1)), shared_ptr<Point_3D>(new Point_3D(0, 5, -1)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-5,-1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,5,-1)), shared_ptr<Point_3D>(new Point_3D(0,-5,-1))), result1, precision));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,5,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_30()
{
    // facets on same plane: overlap one corner
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 3, 4)), shared_ptr<Point_3D>(new Point_3D(0, -2, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,3,4)), shared_ptr<Point_3D>(new Point_3D(0,-2,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,-2,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,-2,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_31()
{
    // facets on same plane: overlap corner
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 2, 4)), shared_ptr<Point_3D>(new Point_3D(0, -1, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,-1,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,-1,10))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_32()
{
    // facets on same plane: corner overlap
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -1, 6)), shared_ptr<Point_3D>(new Point_3D(0, 1, 2)), shared_ptr<Point_3D>(new Point_3D(0, 3, 6)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,-1,6))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,-1,6))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,1,2)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-1,6)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,3,6))), result1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,2)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,1,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,1,2)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,2)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_33()
{
    // facets on same plane: corner on side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 5, 2.5)), shared_ptr<Point_3D>(new Point_3D(0, 2, 10)), shared_ptr<Point_3D>(new Point_3D(0, 15, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,5,2.5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,2.5)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_34()
{
    // facets on same plane: corner over side
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 2, 3)), shared_ptr<Point_3D>(new Point_3D(0, 2, 5)), shared_ptr<Point_3D>(new Point_3D(0, 10, 3)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,4,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,2,5)), shared_ptr<Point_3D>(new Point_3D(0,4,3))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,5)), shared_ptr<Point_3D>(new Point_3D(0,10,3)), shared_ptr<Point_3D>(new Point_3D(0,4,3))), result1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,4,3)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,2,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,4,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,2,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,3)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,4,3))), result2, precision));
}

void Test_3D::test_intersect_meshes_35()
{
    // facets on same plane: two corners inside facet
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0, 4, 1)), shared_ptr<Point_3D>(new Point_3D(0, 1, -2)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,3,0)), shared_ptr<Point_3D>(new Point_3D(0,1,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,3,0)), shared_ptr<Point_3D>(new Point_3D(0,1,-2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,3,0)), shared_ptr<Point_3D>(new Point_3D(0,1,1))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,4,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,3,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,3,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,4,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,0)), shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
}

void Test_3D::test_intersect_meshes_36()
{
    // facets on same plane: corners out, body in
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -2, 4)), shared_ptr<Point_3D>(new Point_3D(0, 4, -2)), shared_ptr<Point_3D>(new Point_3D(0, 10, 4)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,0,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,-2,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,4,-2)), shared_ptr<Point_3D>(new Point_3D(0,6,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,7.33333,1.33333)), shared_ptr<Point_3D>(new Point_3D(0,10,4))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,7.33333,1.33333))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,2,0)), shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,0,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,7.33333,1.33333))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,4)), shared_ptr<Point_3D>(new Point_3D(0,2,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,7.33333,1.33333)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,2)), shared_ptr<Point_3D>(new Point_3D(0,6,0)), shared_ptr<Point_3D>(new Point_3D(0,2,4))), result2, precision));
}

void Test_3D::test_intersect_meshes_37()
{
    // facets on same plane: all inside
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0, 4, 1)), shared_ptr<Point_3D>(new Point_3D(0, 1, 4)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 1);
    assert(is_equal(*result1.begin(), facet1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,1,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,4,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,4,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,1)), shared_ptr<Point_3D>(new Point_3D(0,1,4)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,1,4)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,4,1)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,1,4))), result2, precision));
}

void Test_3D::test_intersect_meshes_38()
{
    // facets on same plane: same facets
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(!intersect_meshes(mesh1, mesh2, result1, result2));
}

void Test_3D::test_intersect_meshes_39()
{
    // facets on same plane: facet2 inside facet1
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(0, 10, 0)), shared_ptr<Point_3D>(new Point_3D(0, 0, 5)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(0, -1, -1)), shared_ptr<Point_3D>(new Point_3D(0, 12, -1)), shared_ptr<Point_3D>(new Point_3D(0, -1, 10)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,-1,-1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-1,-1)), shared_ptr<Point_3D>(new Point_3D(0,12,-1)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-1,-1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,-1,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,12,-1)), shared_ptr<Point_3D>(new Point_3D(0,-1,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,-1,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,-1,10))), result1, precision));
    assert(result2.size() == 1);
    assert(is_equal(*result2.begin(), facet2, precision));
}

void Test_3D::test_intersect_meshes_40()
{
    // facets on same plane.  corner of other_facet on facet
    Mesh_3D mesh2;
    Facet_3D facet2(shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10)));
    mesh2.push_back(facet2);
    Mesh_3D mesh1;
    Facet_3D facet1(shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7)));
    mesh1.push_back(facet1);

    Mesh_3D result1;
    Mesh_3D result2;
    Intersect_Meshes_3D intersect_meshes;
    
    // intersect facets and get segments. 
    assert(intersect_meshes(mesh1, mesh2, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4,1,1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(4,1,1))), result1, precision));
    assert(result2.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_41()
{
    // no intersection
    Facet_3D facet(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)));
    Mesh_3D mesh;
    mesh.push_back(facet);
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,-1,-1)), shared_ptr<Point_3D>(new Point_3D(-5,-5,-5)), shared_ptr<Point_3D>(new Point_3D(-10, -1, 0))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,-1,-1)), shared_ptr<Point_3D>(new Point_3D(-5,-5,-5)), shared_ptr<Point_3D>(new Point_3D(-20, -2, 0))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-1,0)), shared_ptr<Point_3D>(new Point_3D(-20,-2,0)), shared_ptr<Point_3D>(new Point_3D(-3, -1.5, -2))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(!intersect_meshes(intersecting_mesh, mesh, result1, result2));
}

void Test_3D::test_intersect_meshes_42()
{
    // mesh shares one side with facet
    Facet_3D facet(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)));
    Mesh_3D mesh;
    mesh.push_back(facet);
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(-10, -1, 0))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,-1,-1)), shared_ptr<Point_3D>(new Point_3D(-5,-5,-5)), shared_ptr<Point_3D>(new Point_3D(-20, -2, 0))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-1,0)), shared_ptr<Point_3D>(new Point_3D(-20,-2,0)), shared_ptr<Point_3D>(new Point_3D(-3, -1.5, -2))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(!intersect_meshes(intersecting_mesh, mesh, result1, result2));
}

void Test_3D::test_intersect_meshes_43()
{
    // mesh shares part of a side with facet
    Facet_3D facet(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)));
    Mesh_3D mesh;
    mesh.push_back(facet);
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4,4,4)), shared_ptr<Point_3D>(new Point_3D(8, -5, 2))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,-1,-1)), shared_ptr<Point_3D>(new Point_3D(-5,-5,-5)), shared_ptr<Point_3D>(new Point_3D(-20, -2, 0))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-1,0)), shared_ptr<Point_3D>(new Point_3D(-20,-2,0)), shared_ptr<Point_3D>(new Point_3D(-3, -1.5, -2))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4,4,4)), shared_ptr<Point_3D>(new Point_3D(8, -5, 2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1,-1,-1)), shared_ptr<Point_3D>(new Point_3D(-5,-5,-5)), shared_ptr<Point_3D>(new Point_3D(-20, -2, 0))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-1,0)), shared_ptr<Point_3D>(new Point_3D(-20,-2,0)), shared_ptr<Point_3D>(new Point_3D(-3, -1.5, -2))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(4,4,4)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_44()
{
    // mesh pierces facet with two facets
    Facet_3D facet(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)));
    Mesh_3D mesh;
    mesh.push_back(facet);
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,0)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(6, 2, 5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,0)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(4, 2, 5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,3,5)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(4,2,5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,0)), shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(6,2,5)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.6,2,2)), shared_ptr<Point_3D>(new Point_3D(5,2,0)), shared_ptr<Point_3D>(new Point_3D(5,2,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(4.6,2,2))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.6,2,2)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(4,2,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,3,5)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(4,2,5))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.6,2,2)), shared_ptr<Point_3D>(new Point_3D(5,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(4.6,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.6,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,2,2)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5.4,2,2)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.4,2,2)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
}

void Test_3D::test_intersect_meshes_45()
{
    // one mesh facet intersects two facets
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,0)), shared_ptr<Point_3D>(new Point_3D(0,1,5)), shared_ptr<Point_3D>(new Point_3D(2, 1, 5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,1,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,0)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1)), shared_ptr<Point_3D>(new Point_3D(2,1,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.8,1,1)), shared_ptr<Point_3D>(new Point_3D(0,1,5)), shared_ptr<Point_3D>(new Point_3D(2,1,5))), result1, precision));
    assert(result2.size() == 9);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1.2,1,1)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0.8,1,1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.8,1,1)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
}

void Test_3D::test_intersect_meshes_46()
{
    // intersect mesh intersects first and third facets
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,0)), shared_ptr<Point_3D>(new Point_3D(5,1,5)), shared_ptr<Point_3D>(new Point_3D(5, 2, 5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,5)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(8,5,7))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8,5,7)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,0)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1,5)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,5)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,5)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(8,5,7))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8,5,7)), shared_ptr<Point_3D>(new Point_3D(5,2,5)), shared_ptr<Point_3D>(new Point_3D(6,7,7))), result1, precision));
    assert(result2.size() == 9);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,1,1)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,1.25,1.25)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(6,7,7))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(6,7,7))), result2, precision));
}

void Test_3D::test_intersect_meshes_47()
{
    // intersect mesh facet is on the same plane crosses each mesh facet
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,1,1)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,1,1)), shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(1, 3, 7))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(3, 1.5, -2))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 11);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(5.25, 4.75, 4.75)), shared_ptr<Point_3D>(new Point_3D(4, 1, 1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(5.5, 5.5, 5.5)), shared_ptr<Point_3D>(new Point_3D(5.25, 4.75, 4.75))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.5, 5.5, 5.5)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(5.5, 5.5, 5.5))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 3, 7)), shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 3, 7)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3, 1.5, -2)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3, 1.5, -2)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7))), result1, 0.0001));
    assert(result2.size() == 15);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(5.25, 4.75, 4.75)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0, 0, 0)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(5.25, 4.75, 4.75)), shared_ptr<Point_3D>(new Point_3D(5, 5, 5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.25, 4.75, 4.75)), shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4, 1, 1)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(10, 0, 0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1)), shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1)), shared_ptr<Point_3D>(new Point_3D(0, 0, 0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1, 1, 1)), shared_ptr<Point_3D>(new Point_3D(5, 5, 5)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0.5,1,1)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10)), shared_ptr<Point_3D>(new Point_3D(0.5, 1, 1))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(4.56522,5.43478,5.43478)), shared_ptr<Point_3D>(new Point_3D(5.5,5.5,5.5))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(6, 7, 7)), shared_ptr<Point_3D>(new Point_3D(0, 10, 10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.5, 5.5, 5.5)), shared_ptr<Point_3D>(new Point_3D(4.56522, 5.43478, 5.43478)), shared_ptr<Point_3D>(new Point_3D(5, 5, 5))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.5,5.5,5.5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(6,7,7))), result2, precision));
}

void Test_3D::test_intersect_meshes_48()
{
    // mesh edge crosses corner with end points inside two facets
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3, 3, 6))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3,3,6))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(result2.size() == 7);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(6,3,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(6,3,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4,7,7))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(4,7,7))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
}

void Test_3D::test_intersect_meshes_49()
{
    // mesh sides intersect mesh
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5, 3.5, 3.5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825)), shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825)), shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result1, precision));
    assert(result2.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(5.325,3.825,3.825))), result2, precision));
}

void Test_3D::test_intersect_meshes_50()
{
    // mesh sides intersect mesh
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(3, 3.5, 5.5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(7, 7.5, 9.5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(7, 7.5, 9.5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5)), shared_ptr<Point_3D>(new Point_3D(4,7.5,6.5)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,3.5,5.5)), shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3.5,2.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(7,7.5,9.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25))), result1, precision));
    assert(result2.size() == 14);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.75,4.25,4.25)), shared_ptr<Point_3D>(new Point_3D(5,3.5,3.5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.5,4.5,4.5)), shared_ptr<Point_3D>(new Point_3D(3.66667,6.16667,6.16667)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.75,6.25,6.25)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(5,7.5,7.5))), result2, precision));
}

void Test_3D::test_intersect_meshes_51()
{
    // mesh intersects facet twice
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3, 3, 6))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,2,2)), shared_ptr<Point_3D>(new Point_3D(2,2,5)), shared_ptr<Point_3D>(new Point_3D(3, 2, 5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3,3,6))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,2,2)), shared_ptr<Point_3D>(new Point_3D(2,2,5)), shared_ptr<Point_3D>(new Point_3D(3,2,5))), result1, precision));
    assert(result2.size() == 9);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(6,3,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(3,2,2)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(3,2,2))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,2,2)), shared_ptr<Point_3D>(new Point_3D(6,3,3)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4,7,7))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(4,7,7))), result2, precision));
}

void Test_3D::test_intersect_meshes_52()
{
    // mesh intersects side with facets
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(5,3,3)), shared_ptr<Point_3D>(new Point_3D(3, 3, 6))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7, 7, 10))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 5);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(3,3,6))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(3,3,6))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,3,3)), shared_ptr<Point_3D>(new Point_3D(3,3,6)), shared_ptr<Point_3D>(new Point_3D(7,7,10))), result1, precision));
    assert(result2.size() == 11);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(5,3,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3,3)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,3,3))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(4.6,4.6,4.6)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(4,7,7)), shared_ptr<Point_3D>(new Point_3D(4.33333,5.66667,5.66667))), result2, 0.0001));
}

void Test_3D::test_intersect_meshes_53()
{
    // intersecting mesh is on the same plane as mesh
    Mesh_3D mesh;
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))));
    mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))));
    
    Mesh_3D intersecting_mesh;
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5, 4, 4))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(5, 5, 5))));
    intersecting_mesh.push_back(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4, 5, 5))));
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result1, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(4,5,5))), result1, precision));
    assert(result2.size() == 11);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(3,4,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,5,5)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1,2,2)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4,5,5)), shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.5,4,4)), shared_ptr<Point_3D>(new Point_3D(4,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result2, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result2, precision));
}

void Test_3D::test_intersect_meshes_54()
{
    // intersecting mesh is on the same plane as mesh
    Mesh_3D mesh;
    // make a 3D circle with radius 20, but keep only the third facet
    const Point_3D::Angle_Meas two_pi = 6.283185307179586;
    const Point_3D::Angle_Meas step = two_pi / 8;
    // generate 3 dimensional circle
    Point_3D::Angle_Meas angle = step;
    Point_3D origin(0,0,0);
    shared_ptr<Point_3D> begin(new Point_3D(20, 0, 0)); // radius is 20
    shared_ptr<Point_3D> middle(new Point_3D(cylindrical_point(20, angle, 0, origin)));
    angle += step;
    int count = 0;
    while (angle < two_pi)
    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(20, angle, 0, origin)));

        if (count++ == 2)
        {
            mesh.push_back(Facet_3D(begin, middle, last));
            break;
        }
        middle = last;
        angle += step;
    }
    
    Mesh_3D intersecting_mesh;
    // make a 3D circle with radius 15, but only keep the first facet
    begin = shared_ptr<Point_3D>(new Point_3D(15, 0, 0)); // radius is 15
    angle = step;
    middle = shared_ptr<Point_3D>(new Point_3D(cylindrical_point(15, angle, 0, origin)));
    angle += step;
//    while (angle < two_pi)
//    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(15, angle, 0, origin)));

        intersecting_mesh.push_back(Facet_3D(begin, middle, last));
//        middle = last;
//        angle += step;
//    }

    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 3);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(0,15,0))), result1, 0.0001));
    assert(result2.size() == 4);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,0,0))), result2, 0.0001));
}

void Test_3D::test_intersect_meshes_55()
{
    // intersecting mesh is on the same plane as mesh
    Mesh_3D mesh;
    // make a 3D circle with radius 20
    const Point_3D::Angle_Meas two_pi = 6.283185307179586;
    const Point_3D::Angle_Meas step = two_pi / 8;
    // generate 3 dimensional circle
    Point_3D::Angle_Meas angle = step;
    Point_3D origin(0,0,0);
    shared_ptr<Point_3D> begin(new Point_3D(20, 0, 0)); // radius is 20
    shared_ptr<Point_3D> middle(new Point_3D(cylindrical_point(20, angle, 0, origin)));
    angle += step;
    while (angle < two_pi)
    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(20, angle, 0, origin)));

        mesh.push_back(Facet_3D(begin, middle, last));
        middle = last;
        angle += step;
    }
    
    Mesh_3D intersecting_mesh;
    // make a 3D circle with radius 15
    // generate 3 dimensional circle
    begin = shared_ptr<Point_3D>(new Point_3D(15, 0, 0)); // radius is 15
    angle = step;
    middle = shared_ptr<Point_3D>(new Point_3D(cylindrical_point(15, angle, 0, origin)));
    angle += step;
    while (angle < two_pi)
    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(15, angle, 0, origin)));

        intersecting_mesh.push_back(Facet_3D(begin, middle, last));
        middle = last;
        angle += step;
    }

//    int count = 0;
//    for (Mesh_3D::const_iterator iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
//    count = 0;
//    for (Mesh_3D::const_iterator iter = intersecting_mesh.begin(); iter != intersecting_mesh.end(); ++iter)
//    {
//        cout << "intersecting_mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 18);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result1, 0.0001));
    assert(result2.size() == 42);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result2, 0.0001));
}

void Test_3D::test_intersect_meshes_56()
{
    // intersecting mesh is on the same plane as mesh
    Mesh_3D mesh;
    // make a 3D circle with radius 20
    const Point_3D::Angle_Meas two_pi = 6.283185307179586;
    const Point_3D::Angle_Meas step = two_pi / 8;
    // generate 3 dimensional circle
    Point_3D::Angle_Meas angle = step;
    Point_3D origin(0,0,0);
    shared_ptr<Point_3D> begin(new Point_3D(20, 0, 10)); // radius is 20
    shared_ptr<Point_3D> middle(new Point_3D(cylindrical_point(20, angle, 10, origin)));
    angle += step;
    while (angle < two_pi)
    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(20, angle, 10, origin)));

        mesh.push_back(Facet_3D(begin, middle, last));
        middle = last;
        angle += step;
    }
    
    Mesh_3D intersecting_mesh;
    m_cylinder(intersecting_mesh,15,15,10,2,false);
    
//    int count = 0;
//    for (Mesh_3D::const_iterator iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
//    count = 0;
//    for (Mesh_3D::const_iterator iter = intersecting_mesh.begin(); iter != intersecting_mesh.end(); ++iter)
//    {
//        cout << "intersecting_mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
    assert(result1.size() == 48);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result1, 0.0001));
    assert(result2.size() == 42);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result2, 0.0001));
}

void Test_3D::test_intersect_meshes_57()
{
    // intersecting mesh is on the same plane as mesh
    Mesh_3D mesh;
    // make a 3D circle with radius 20
    const Point_3D::Angle_Meas two_pi = 6.283185307179586;
    const Point_3D::Angle_Meas step = two_pi / 8;
    // generate 3 dimensional circle
    Point_3D::Angle_Meas angle = step;
    Point_3D origin(0,0,0);
    shared_ptr<Point_3D> begin(new Point_3D(20, 0, 10)); // radius is 20
    shared_ptr<Point_3D> middle(new Point_3D(cylindrical_point(20, angle, 10, origin)));
    angle += step;
    while (angle < two_pi)
    {
        shared_ptr<Point_3D> last(new Point_3D(cylindrical_point(20, angle, 10, origin)));

        mesh.push_back(Facet_3D(begin, middle, last));
        middle = last;
        angle += step;
    }
    
    Mesh_3D intersecting_mesh;
    m_cylinder(intersecting_mesh,15,15,20,2);
    
//    int count = 0;
//    for (Mesh_3D::const_iterator iter = mesh.begin(); iter != mesh.end(); ++iter)
//    {
//        cout << "mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
//    count = 0;
//    for (Mesh_3D::const_iterator iter = intersecting_mesh.begin(); iter != intersecting_mesh.end(); ++iter)
//    {
//        cout << "intersecting_mesh[" << count++ << "]: p1 x: " << (*iter)->get_point1().get_x() << " y: " 
//                << (*iter)->get_point1().get_y() << " z: " << (*iter)->get_point1().get_z() << " p2 x: "
//                << (*iter)->get_point2().get_x() << " y: " << (*iter)->get_point2().get_y() << " z: "
//                << (*iter)->get_point2().get_z() << " p3 x: " << (*iter)->get_point3().get_x() << " y: "
//                << (*iter)->get_point3().get_y() << " z: " << (*iter)->get_point3().get_z() << "\n"; 
//    }
    
    Intersect_Meshes_3D intersect_meshes;
    Mesh_3D result1;
    Mesh_3D result2;
    assert(intersect_meshes(intersecting_mesh, mesh, result1, result2));
//    int count = 0;
//    for (Mesh2_3D::const_iterator iter = result1.begin(); iter != result1.end(); ++iter)
//    {
//        cout << "result1[" << count++ << "]: p1 x: " << iter->get_point1()->get_x() << " y: " 
//                << iter->get_point1()->get_y() << " z: " << iter->get_point1()->get_z() << " p2 x: "
//                << iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() << " z: "
//                << iter->get_point2()->get_z() << " p3 x: " << iter->get_point3()->get_x() << " y: "
//                << iter->get_point3()->get_y() << " z: " << iter->get_point3()->get_z() << "\n"; 
//    }
//    count = 0;
//    for (Mesh2_3D::const_iterator iter = result2.begin(); iter != result2.end(); ++iter)
//    {
//        cout << "result2[" << count++ << "]: p1 x: " << iter->get_point1()->get_x() << " y: " 
//                << iter->get_point1()->get_y() << " z: " << iter->get_point1()->get_z() << " p2 x: "
//                << iter->get_point2()->get_x() << " y: " << iter->get_point2()->get_y() << " z: "
//                << iter->get_point2()->get_z() << " p3 x: " << iter->get_point3()->get_x() << " y: "
//                << iter->get_point3()->get_y() << " z: " << iter->get_point3()->get_z() << "\n"; 
//    }
//    cout << "result1: polyhedron(points=[";
//    for (Mesh2_3D::const_point_iterator it = result1.point_begin(); it != result1.point_end(); ++it)
//    {
//        if (it != result1.point_begin())
//            cout << ',';
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    for (Mesh2_3D::const_facet_iterator it = result1.facet_begin(); it != result1.facet_end(); ++it)
//    {
//        if (it != result1.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << it->get_p1_index() << ',' << it->get_p3_index() << ',' << it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    cout << "result2: polyhedron(points=[";
//    for (Mesh2_3D::const_point_iterator it = result2.point_begin(); it != result2.point_end(); ++it)
//    {
//        if (it != result2.point_begin())
//            cout << ',';
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    for (Mesh2_3D::const_facet_iterator it = result2.facet_begin(); it != result2.facet_end(); ++it)
//    {
//        if (it != result2.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << it->get_p1_index() << ',' << it->get_p3_index() << ',' << it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    cout << "    assert(result1.size() == " << result1.size() << ");\n";
//    for (Mesh2_3D::const_iterator iter = result1.begin(); iter != result1.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_3D(shared_ptr<Point_3D>(new Point_3D(" << iter->get_point1()->get_x() << 
//                ',' << iter->get_point1()->get_y() << ',' << iter->get_point1()->get_z() << ")), shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << ',' << iter->get_point2()->get_y() << ',' << iter->get_point2()->get_z() <<
//                ")), shared_ptr<Point_3D>(new Point_3D(" << iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << 
//                ',' << iter->get_point3()->get_z() << "))), result1, 0.0001));\n";
//    }
//    cout << "    assert(result2.size() == " << result2.size() << ");\n";
//    for (Mesh2_3D::const_iterator iter = result2.begin(); iter != result2.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_3D(shared_ptr<Point_3D>(new Point_3D(" << iter->get_point1()->get_x() << 
//                ',' << iter->get_point1()->get_y() << ',' << iter->get_point1()->get_z() << ")), shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << ',' << iter->get_point2()->get_y() << ',' << iter->get_point2()->get_z() <<
//                ")), shared_ptr<Point_3D>(new Point_3D(" << iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << 
//                ',' << iter->get_point3()->get_z() << "))), result2, 0.0001));\n";
//    }
    assert(result1.size() == 76);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result1, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result1, 0.0001));
    assert(result2.size() == 54);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result2, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result2, 0.0001));
}

void Test_3D::test_mesh_difference_1()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(20,20,20));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(10,0,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,10,10)),shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,10)),shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(0,10,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, precision));
}

void Test_3D::test_mesh_difference_2()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(10,0,0));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.size() == 10);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(10,0,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,0,10)),shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,10,10)),shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,10)),shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(0,10,10)),shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, precision));
}

void Test_3D::test_mesh_difference_3()
{
    // shape2 is smaller than shape
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,5,5,5);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.size() == 24);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,5,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5,0,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5)), shared_ptr<Point_3D>(new Point_3D(0,5,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(5,5,5))), result, 0.0001));
}

void Test_3D::test_mesh_difference_4()
{
    // shape inside shape
    Mesh_3D shape;
    m_cylinder(shape,20,20,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.size() == 96);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
}

void Test_3D::test_mesh_difference_5()
{
    // shape inside shape, but initial shape is completely inside other shape
    Mesh_3D shape;
    m_cylinder(shape,15,15,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,20,20,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.empty());
}

void Test_3D::test_mesh_difference_6()
{
    // shapes are the same
    Mesh_3D shape;
    m_cylinder(shape,15,15,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
    assert(result.empty());
}

void Test_3D::test_mesh_difference_7()
{
    // shape2 doesn't pass all the way through shape
    Mesh_3D shape;
    m_ellipsoid(shape,10,40,20,3);
    Mesh_3D shape2;
    m_e_cylinder(shape2,5,20,15,30,20,3);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.difference(shape, shape2, result);
//    cout << "result: polyhedron(points=[";
//    for (Mesh2_3D::const_point_iterator it = result.point_begin(); it != result.point_end(); ++it)
//    {
//        if (it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    for (Mesh2_3D::const_facet_iterator it = result.facet_begin(); it != result.facet_end(); ++it)
//    {
//        if (it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << it->get_p1_index() << ',' << it->get_p3_index() << ',' << it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_3D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_3D(shared_ptr<Point_3D>(new Point_3D(" << iter->get_point1()->get_x() << 
//                ',' << iter->get_point1()->get_y() << ',' << iter->get_point1()->get_z() << ")), shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << ',' << iter->get_point2()->get_y() << ',' << iter->get_point2()->get_z() <<
//                ")), shared_ptr<Point_3D>(new Point_3D(" << iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << 
//                ',' << iter->get_point3()->get_z() << "))), result, 0.0001));\n";
//    }
    assert(result.size() == 214);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
}

void Test_3D::test_mesh_intersection_1()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(20,20,20));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.empty());
}

void Test_3D::test_mesh_intersection_2()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(10,0,0));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.size() == 2);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10)),shared_ptr<Point_3D>(new Point_3D(10,0,10))), result,precision));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,10,0)),shared_ptr<Point_3D>(new Point_3D(10,10,10))),result,precision));
}

void Test_3D::test_mesh_intersection_3()
{
    // shape2 is smaller than shape
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,5,5,5);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.size() == 12);
}

void Test_3D::test_mesh_intersection_4()
{
    // shape inside shape
    Mesh_3D shape;
    m_cylinder(shape,20,20,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.size() == 68);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
}

void Test_3D::test_mesh_intersection_5()
{
    // shape inside shape, but initial shape is completely inside other shape
    Mesh_3D shape;
    m_cylinder(shape,15,15,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,20,20,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.size() == 68);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
}

void Test_3D::test_mesh_intersection_6()
{
    // shapes are the same
    Mesh_3D shape;
    m_cylinder(shape,15,15,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
    assert(result.size() == 28);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
}

void Test_3D::test_mesh_intersection_7()
{
    // shape2 doesn't pass all the way through shape
    Mesh_3D shape;
    m_ellipsoid(shape,10,40,20,3);
    Mesh_3D shape2;
    m_e_cylinder(shape2,5,20,15,30,20,3);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.intersection(shape, shape2, result);
//    cout << "result: polyhedron(points=[";
//    for (Mesh2_3D::const_point_iterator it = result.point_begin(); it != result.point_end(); ++it)
//    {
//        if (it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    for (Mesh2_3D::const_facet_iterator it = result.facet_begin(); it != result.facet_end(); ++it)
//    {
//        if (it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << it->get_p1_index() << ',' << it->get_p3_index() << ',' << it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_3D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_3D(shared_ptr<Point_3D>(new Point_3D(" << iter->get_point1()->get_x() << 
//                ',' << iter->get_point1()->get_y() << ',' << iter->get_point1()->get_z() << ")), shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << ',' << iter->get_point2()->get_y() << ',' << iter->get_point2()->get_z() <<
//                ")), shared_ptr<Point_3D>(new Point_3D(" << iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << 
//                ',' << iter->get_point3()->get_z() << "))), result, 0.0001));\n";
//    }
    assert(result.size() == 118);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,13.3333)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(-1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,20,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.44089e-16,-20,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(1.66667,18.8562,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(1.66667,-18.8562,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,14.9071,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-14.9071,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
}

void Test_3D::test_mesh_merge_1()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(20,20,20));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 24);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(20,30,20)), shared_ptr<Point_3D>(new Point_3D(30,30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(30,30,20)), shared_ptr<Point_3D>(new Point_3D(30,20,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)), shared_ptr<Point_3D>(new Point_3D(30,30,30)), shared_ptr<Point_3D>(new Point_3D(20,30,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,30)), shared_ptr<Point_3D>(new Point_3D(30,20,30)), shared_ptr<Point_3D>(new Point_3D(30,30,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(20,20,30)), shared_ptr<Point_3D>(new Point_3D(20,30,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(20,30,30)), shared_ptr<Point_3D>(new Point_3D(20,30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,20)), shared_ptr<Point_3D>(new Point_3D(30,30,30)), shared_ptr<Point_3D>(new Point_3D(30,20,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(30,20,20)), shared_ptr<Point_3D>(new Point_3D(30,30,20)), shared_ptr<Point_3D>(new Point_3D(30,30,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(30,20,30)), shared_ptr<Point_3D>(new Point_3D(20,20,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,20,20)), shared_ptr<Point_3D>(new Point_3D(30,20,20)), shared_ptr<Point_3D>(new Point_3D(30,20,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,30,20)), shared_ptr<Point_3D>(new Point_3D(20,30,30)), shared_ptr<Point_3D>(new Point_3D(30,30,30))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,30,20)), shared_ptr<Point_3D>(new Point_3D(30,30,30)), shared_ptr<Point_3D>(new Point_3D(30,30,20))), result, 0.0001));
}

void Test_3D::test_mesh_merge_2()
{
    // shapes do not overlap
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,10,10,10,false, Point_3D(10,0,0));
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 22);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(20,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(20,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(20,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(20,10,10)), shared_ptr<Point_3D>(new Point_3D(20,10,0))), result, 0.0001));
}

void Test_3D::test_mesh_merge_3()
{
    // shape2 is smaller than shape
    Mesh_3D shape;
    m_cuboid(shape,10,10,10);
    Mesh_3D shape2;
    m_cuboid(shape2,5,5,5);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 24);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,5,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(5,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,5,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,0,10)), shared_ptr<Point_3D>(new Point_3D(0,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,5)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,5,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(0,10,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,10)), shared_ptr<Point_3D>(new Point_3D(0,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(5,0,5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,0,5)), shared_ptr<Point_3D>(new Point_3D(10,0,0)), shared_ptr<Point_3D>(new Point_3D(10,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(0,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,10,0)), shared_ptr<Point_3D>(new Point_3D(10,10,10)), shared_ptr<Point_3D>(new Point_3D(10,10,0))), result, 0.0001));
}

void Test_3D::test_mesh_merge_4()
{
    // shape inside shape
    Mesh_3D shape;
    m_cylinder(shape,20,20,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,20,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 128);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
}

void Test_3D::test_mesh_merge_5()
{
    // shape inside shape, but initial shape is completely inside other shape
    Mesh_3D shape;
    m_cylinder(shape,15,15,20,2);
    Mesh_3D shape2;
    m_cylinder(shape2,20,20,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 128);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(15,3.06162e-16,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(15,3.06162e-16,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,20)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,20)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-3.53553,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,20)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,3.06162e-16,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,8.53553,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,11.4645,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,12.8033,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.22465e-15,20,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,2.5,10)), shared_ptr<Point_3D>(new Point_3D(15,3.06162e-16,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0)), shared_ptr<Point_3D>(new Point_3D(15,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-15,2.14313e-15,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(15,3.06162e-16,10)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-20,2.44929e-15,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(13.9645,-2.5,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(12.8033,-5.3033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-8.1066,-11.6421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.3033,-12.8033,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,0)), shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.53553,-11.4645,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(11.4645,-8.53553,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.67394e-15,-20,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(20,0,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(20,0,0)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,10)), shared_ptr<Point_3D>(new Point_3D(14.1421,-14.1421,0))), result, 0.0001));
}

void Test_3D::test_mesh_merge_6()
{
    // shapes are the same
    Mesh_3D shape;
    m_cylinder(shape,15,15,10,2);
    Mesh_3D shape2;
    m_cylinder(shape2,15,15,10,2);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
    assert(result.size() == 28);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(15,0,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.18485e-16,15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,1.83697e-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.75546e-15,-15,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(15,0,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,0)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,10)), shared_ptr<Point_3D>(new Point_3D(10.6066,-10.6066,0))), result, 0.0001));
}

void Test_3D::test_mesh_merge_7()
{
    // shape2 doesn't pass all the way through shape
    Mesh_3D shape;
    m_ellipsoid(shape,10,40,20,3);
    Mesh_3D shape2;
    m_e_cylinder(shape2,5,20,15,30,20,3);
    Mesh_3D result;
    Intersect_Meshes_3D intersect_meshes;
    intersect_meshes.merge(shape, shape2, result);
//    cout << "result: polyhedron(points=[";
//    for (Mesh2_3D::const_point_iterator it = result.point_begin(); it != result.point_end(); ++it)
//    {
//        if (it != result.point_begin())
//            cout << ',';
//        cout << '[' << (*it)->get_x() << ',' << (*it)->get_y() << ',' << (*it)->get_z() << ']';
//    }
//    cout << "], faces=[";
//    for (Mesh2_3D::const_facet_iterator it = result.facet_begin(); it != result.facet_end(); ++it)
//    {
//        if (it != result.facet_begin())
//            cout << ',';
//        // write points in clockwise order because openscad prefers it
//        cout << '[' << it->get_p1_index() << ',' << it->get_p3_index() << ',' << it->get_p2_index() << ']';
//    }
//    cout << "], convexity=4);\n";
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    for (Mesh2_3D::const_iterator iter = result.begin(); iter != result.end(); ++iter)
//    {
//        cout << "    assert(mesh_contains(Facet2_3D(shared_ptr<Point_3D>(new Point_3D(" << iter->get_point1()->get_x() << 
//                ',' << iter->get_point1()->get_y() << ',' << iter->get_point1()->get_z() << ")), shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << ',' << iter->get_point2()->get_y() << ',' << iter->get_point2()->get_z() <<
//                ")), shared_ptr<Point_3D>(new Point_3D(" << iter->get_point3()->get_x() << ',' << iter->get_point3()->get_y() << 
//                ',' << iter->get_point3()->get_z() << "))), result, 0.0001));\n";
//    }
    assert(result.size() == 216);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-20)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-8.88178e-16,-29.8142,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333)), shared_ptr<Point_3D>(new Point_3D(4.96904,22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(4.96904,-22.2222,-13.3333)), shared_ptr<Point_3D>(new Point_3D(7.45356,0,-13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,-6.66667)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,-6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(-3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(8.88178e-16,-40,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(3.33333,37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.33333,-37.7124,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(6.66667,29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.66667,-29.8142,1.77636e-15)), shared_ptr<Point_3D>(new Point_3D(10,0,1.77636e-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(-3.1427,35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(0,37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-37.7124,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.1427,35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(3.1427,-35.5556,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.28539,28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.28539,-28.1091,6.66667)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(9.42809,0,6.66667))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(0,-29.8142,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(2.48452,28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.48452,-28.1091,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-7.38484,10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-7.69908,-8.61671,9.25168)), shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-10,22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-5.07188,22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-4.43091,23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125)), shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(-5.07188,-22.6821,12.8125))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-4.43091,-23.7166,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(0,30,20)), shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(0,-30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(0,30,20)), shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(0,30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(0,30,20)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-2.29442,25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-3.71122,25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(0,30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,30,20)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(-0.502802,26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-30,20)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-3.71122,-25.2025,13.3333)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(-5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(-2.29442,-25.9583,13.8434))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,-30,20)), shared_ptr<Point_3D>(new Point_3D(-0.502802,-26.6381,13.9664)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(0,30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(0,-30,20)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,30,20)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(2.30796,26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(3.675,25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(0,-30,20)), shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(1.33973e-16,-26.9832,13.9664)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071)), shared_ptr<Point_3D>(new Point_3D(0,-30,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(0,-30,20)), shared_ptr<Point_3D>(new Point_3D(2.30796,-26.1116,13.8071))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.35688,-25.5619,13.4275)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(3.675,-25.2884,13.3333))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5.15033,23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(5,28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.00593,20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(3.86183,-25.065,13.171)), shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(4.77743,-23.6211,12.6339)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(5,-28.2843,20)), shared_ptr<Point_3D>(new Point_3D(5.15033,-23.033,12.4152))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(6.00593,-20.681,10.4142)), shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(-15,0,20)), shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(0,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(0,0,20)), shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(10,22.3607,20)), shared_ptr<Point_3D>(new Point_3D(6.78876,15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(9.02084,0,8.04168)), shared_ptr<Point_3D>(new Point_3D(15,0,20)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(15,0,20))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.38484,-10.6653,9.53936)), shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(6.51312,-18.4622,9.53936)), shared_ptr<Point_3D>(new Point_3D(6.78876,-15.9968,9.53936)), shared_ptr<Point_3D>(new Point_3D(10,-22.3607,20))), result, 0.0001));
}
