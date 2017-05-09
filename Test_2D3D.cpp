/* 
 * File:   Test_2D3D.cpp
 * Author: Jeffrey Davis
 * Version: 1.0
 * 
 * Created on May 23, 2016, 11:07 PM
 */

#include "Test_2D3D.h"


const double Test_2D3D::precision = 0.0001;
const double Test_2D3D::pi = 3.14159265358979;

const double Test_2D3D::mesh_area(const Mesh_2D& mesh) const
{
    double twice_area(0);
    
    for (Mesh_2D::const_iterator it = mesh.begin(); it != mesh.end(); ++it)
        twice_area += cross_product(Vector_2D(*(it->get_point1()), *(it->get_point2())), Vector_2D(*(it->get_point1()), *(it->get_point3())));

    return twice_area / 2;
}

const double Test_2D3D::mesh_area(const Mesh_3D& mesh) const 
{
    double twice_area(0);
    
    for (Mesh_3D::const_iterator it = mesh.begin(); it != mesh.end(); ++it)
        twice_area += cross_product(Vector_3D(*(it->get_point1()), *(it->get_point2())), Vector_3D(*(it->get_point1()), *(it->get_point3()))).length();

    return twice_area / 2;
}

const bool Test_2D3D::within_round(const double val1, const double val2, const double precision) const
{
        return (fabs(val1 - val2) < precision);
}

const bool Test_2D3D::mesh_contains(const Facet_2D& facet, const Mesh_2D& mesh, const double precision) const
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

const bool Test_2D3D::mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const
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

void Test_2D3D::test_all()
{
    cout << "Testing 2D3D sub-systems\n";
    this->test_linear_extrude_1();
    cout << '.';
    this->test_linear_extrude_2();
    cout << '.';
    this->test_linear_extrude_3();
    cout << '.';
    this->test_linear_extrude_4();
    cout << '.';
    this->test_linear_extrude_5();
    cout << '.';
    cout << endl << endl;
}

void Test_2D3D::test_linear_extrude_1()
{
    Mesh_2D mesh_2d;
    m_rectangle(mesh_2d, 10,20);
    Mesh_3D result;
    linear_extrude(mesh_2d, result, 15, false);
    assert(result.size() == 12);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,20,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(10,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(0,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(0,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
}

void Test_2D3D::test_linear_extrude_2()
{
    Mesh_2D mesh_2d;
    m_rectangle(mesh_2d, 10, 20);
    Mesh_2D m2d;
    m_rectangle(m2d, 5, 15);
    m2d.translate(2.5,2.5);
    Intersect_Meshes_2D intersect_meshes;
    Mesh_2D mesh;
    intersect_meshes.difference(mesh_2d, m2d, mesh);
    Mesh_3D result;
    linear_extrude(mesh, result, 15, false);
    assert(result.size() == 40);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(2.5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)),shared_ptr<Point_3D>(new Point_3D(2.5,5,15)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,15)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,15)),shared_ptr<Point_3D>(new Point_3D(0,0,15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(7.5,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,15)),shared_ptr<Point_3D>(new Point_3D(7.5,15,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15)),shared_ptr<Point_3D>(new Point_3D(7.5,15,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15)),shared_ptr<Point_3D>(new Point_3D(0,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15)),shared_ptr<Point_3D>(new Point_3D(2.5,5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(0,0,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15)),shared_ptr<Point_3D>(new Point_3D(2.5,5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15)),shared_ptr<Point_3D>(new Point_3D(7.5,15,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15)),shared_ptr<Point_3D>(new Point_3D(10,20,15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,15))), result, 0.0001));
}

void Test_2D3D::test_linear_extrude_3()
{
    Mesh_2D mesh_2d;
    m_rectangle(mesh_2d, 10, 20);
    Mesh_2D m2d;
    m_rectangle(m2d, 5, 15);
    m2d.translate(2.5,2.5);
    Intersect_Meshes_2D intersect_meshes;
    Mesh_2D mesh;
    intersect_meshes.difference(mesh_2d, m2d, mesh);
    Mesh_3D result;
    linear_extrude(mesh, result, 15, true);
    assert(result.size() == 40);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
}

void Test_2D3D::test_linear_extrude_4()
{
    Mesh_2D mesh_2d;
    m_rectangle(mesh_2d, 10, 20);
    Mesh_2D m2d;
    m_rectangle(m2d, 5, 15);
    m2d.translate(2.5,2.5);
    Intersect_Meshes_2D intersect_meshes;
    Mesh_2D mesh;
    intersect_meshes.difference(mesh_2d, m2d, mesh);
    Mesh_3D result;
    linear_extrude(mesh, result, -15, false);
    assert(result.size() == 40);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,5,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(10,20,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(0,0,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,0)),shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,15,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,0)),shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-15))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,0)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,0)),shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,-15)),shared_ptr<Point_3D>(new Point_3D(10,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(0,0,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0)),shared_ptr<Point_3D>(new Point_3D(2.5,5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-15)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0)),shared_ptr<Point_3D>(new Point_3D(7.5,15,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-15)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,0)),shared_ptr<Point_3D>(new Point_3D(10,20,0))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,-15)),shared_ptr<Point_3D>(new Point_3D(0,20,0))), result, 0.0001));
}

void Test_2D3D::test_linear_extrude_5()
{
    Mesh_2D mesh_2d;
    m_rectangle(mesh_2d, 10, 20);
    Mesh_2D m2d;
    m_rectangle(m2d, 5, 15);
    m2d.translate(2.5,2.5);
    Intersect_Meshes_2D intersect_meshes;
    Mesh_2D mesh;
    intersect_meshes.difference(mesh_2d, m2d, mesh);
    Mesh_3D result;
    linear_extrude(mesh, result, -15, true);
//    cout << "\n";
//    cout << "polyhedron(points=[";
//    bool write_comma(false);
//    for (Mesh_3D::const_point_iterator it = result.point_begin(); it != result.point_end(); ++it)
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
//    for (Mesh_3D::const_facet_iterator it = result.facet_begin(); it != result.facet_end(); ++it)
//    {
//        if (write_comma)
//            cout << ',';
//        else
//            write_comma = true;
//        
//        cout << '[' << it->get_p1_index() << ',' << it->get_p2_index() << ',' << it->get_p3_index() << ']';
//    }
//    cout << "], convexity = 4);\n";
//    cout << "    assert(result.size() == " << result.size() << ");\n";
//    Mesh_3D::const_iterator iter(result.begin());
//    while (iter != result.end())
//    {
//        cout << "    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(" << 
//                iter->get_point1()->get_x() << "," << iter->get_point1()->get_y() << "," <<
//                iter->get_point1()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point2()->get_x() << "," << iter->get_point2()->get_y() << "," <<
//                iter->get_point2()->get_z() << ")),shared_ptr<Point_3D>(new Point_3D(" <<
//                iter->get_point3()->get_x() << "," << iter->get_point3()->get_y() << "," <<
//                iter->get_point3()->get_z() << "))), result, 0.0001));\n";
//        ++iter;
//    }
    assert(result.size() == 40);
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(10,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(0,0,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(2.5,5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(2.5,2.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,15,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(7.5,15,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,-7.5)),shared_ptr<Point_3D>(new Point_3D(7.5,17.5,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5)),shared_ptr<Point_3D>(new Point_3D(10,20,7.5))), result, 0.0001));
    assert(mesh_contains(Facet_3D(shared_ptr<Point_3D>(new Point_3D(10,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,-7.5)),shared_ptr<Point_3D>(new Point_3D(0,20,7.5))), result, 0.0001));
}

