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
 * File:   Test_STL.cpp
 * Author: Jeffrey Davis
 */

#include "Test_STL.h"

Test_STL::~Test_STL()
{
    remove("test.stl");
}

const double Test_STL::precision = 0.0001;

void Test_STL::create_file(const string& filename,const vector<string>& content)
{
    ofstream ofs(filename);
    for (vector<string>::const_iterator it = content.begin(); it != content.end(); ++it)
    {
        ofs << *it << '\n';
    }
    ofs.close();
}

void Test_STL::create_bin_file(const string& filename, stringstream& content)
{
    ofstream ofs(filename);
    int val = content.get();
    while (!content.eof())
    {
        ofs.put(val);
        val = content.get();
    }
    ofs.close();
}

void Test_STL::swap_float_bytes(stringstream& ofs, const float val)
{
    stringstream ss;
    ss.write((char *) &val, 4);
    int c1 = ss.get();
    int c2 = ss.get();
    int c3 = ss.get();
    int c4 = ss.get();
    ofs.put(c4);
    ofs.put(c3);
    ofs.put(c2);
    ofs.put(c1);
}

const bool Test_STL::within_round(const double val1, const double val2, const double precision) const
{
        return (fabs(val1 - val2) < precision);
}

const bool Test_STL::mesh_contains(const Facet_3D& facet, const Mesh_3D& mesh, const double precision) const
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

void Test_STL::test_all()
{
    cout << "Testing STL sub-systems\n";
    this->test_read_stl_1();
    cout << '.';
    this->test_read_stl_2();
    cout << '.';
    this->test_read_stl_3();
    cout << '.';
    this->test_read_stl_4();
    cout << '.';
    this->test_read_stl_5();
    cout << '.';
    this->test_read_stl_6();
    cout << '.';
    this->test_read_stl_7();
    cout << '.';
    this->test_read_stl_8();
    cout << '.';
    this->test_read_stl_9();
    cout << '.';
    this->test_read_stl_10();
    cout << '.';
    this->test_read_stl_11();
    cout << '.';
    this->test_read_stl_12();
    cout << '.';
    this->test_read_stl_13();
    cout << '.';
    this->test_read_stl_14();
    cout << '.';
    this->test_read_stl_15();
    cout << '.';
    this->test_read_stl_16();
    cout << '.';
    this->test_read_stl_17();
    cout << '.';
    this->test_read_stl_18();
    cout << '.';
    this->test_read_stl_19();
    cout << '.';
    this->test_read_stl_20();
    cout << '.';
    this->test_read_stl_21();
    cout << '.';
    this->test_read_stl_22();
    cout << '.';
    this->test_read_stl_23();
    cout << '.';
    this->test_read_stl_24();
    cout << '.';
    this->test_read_stl_25();
    cout << '.' << '\n';
    this->test_read_stl_26();
    cout << '.';
    this->test_read_stl_27();
    cout << '.';
    this->test_read_stl_28();
    cout << '.';
    this->test_read_stl_bin_1();
    cout << '.';
    this->test_read_stl_bin_2();
    cout << '.';
    this->test_read_stl_bin_3();
    cout << '.';
    this->test_read_stl_bin_4();
    cout << '.';
    this->test_read_stl_bin_5();
    cout << '.';
    this->test_read_stl_bin_6();
    cout << '.';
    this->test_read_stl_bin_7();
    cout << '.';
    this->test_read_stl_bin_8();
    cout << '.';
    this->test_read_stl_bin_9();
    cout << '.';
    this->test_read_stl_bin_10();
    cout << '.';
    this->test_read_stl_bin_11();
    cout << '.';
    this->test_write_stl_1();
    cout << '.';
    this->test_write_stl_2();
    cout << '.';
    this->test_write_stl_3();
    cout << '.';
    this->test_write_stl_4();
    cout << '.';
    this->test_write_stl_5();
    cout << '.';
    this->test_write_stl_6();
    cout << '.';
    this->test_write_stl_7();
    cout << '.';
    this->test_write_stl_8();
    cout << '.';
    cout << endl << endl;
}

void Test_STL::test_read_stl_1()
{
    // try to read a non existing stl file
    Mesh_3D shape;
    string filename = "123.stl";
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Unable to open file '123.stl'") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_2()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Invalid STL file: test.stl") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_3()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("sol");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Invalid STL file: test.stl") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_4()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soli");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Invalid STL file: test.stl") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_5()
{
    // try to read an empty stl file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("sOLId");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_6()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("sOLId incomplete");
    content.push_back("fAc8t normal 0 0 0");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'facet', found 'fac8t' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_7()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet n0rmal 0 0 0");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'normal', found 'n0rmal' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_8()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet noRMal a 0 0");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the first facet normal decimal value on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_9()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 t12 0");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the second facet normal decimal value on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_10()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 ~12");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the third facet normal decimal value on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_11()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("0ut3R loop");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'outer', found '0ut3r' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_12()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR 3L00p");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'loop', found '3l00p' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_13()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("\tvert3x 1 2 3");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'vertex', found 'vert3x' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_14()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex !2 2 3");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the first decimal value on facet 0 vertex #1") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_15()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 -=2 3");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the second decimal value on facet 0 vertex #1") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_16()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 &3");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the third decimal value on facet 0 vertex #1") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_17()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  verte& 1 1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'vertex', found 'verte&' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_18()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex $1 1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the first decimal value on facet 0 vertex #2") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_19()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 #1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the second decimal value on facet 0 vertex #2") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_20()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 *1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the third decimal value on facet 0 vertex #2") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_21()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex3 1 1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'vertex', found 'vertex3' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_22()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex d$1 1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the first decimal value on facet 0 vertex #3") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_23()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex 1 ^#1 1");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the second decimal value on facet 0 vertex #3") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_24()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex 1 1 Hi");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"unable to read the third decimal value on facet 0 vertex #3") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_25()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("endloop@");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'endloop', found 'endloop@' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_26()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("endloop");
    content.push_back("endf@cet");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"expected 'endfacet', found 'endf@cet' on facet 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_27()
{
    // try to read an incomplete file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    content.push_back("soliD incomplete");
    content.push_back("facet normal 0 12.0 .12");
    content.push_back("OuTeR LOOp");
    content.push_back("    vertex 2 2 -3");
    content.push_back("\t  vertex 1 1 -2");
    content.push_back("\t  vertex 1 1 1");
    content.push_back("endloop");
    content.push_back("endfacet");
    content.push_back("endsolid");
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
        assert(num_facets == 1);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << ex.what() << "\n";
        assert(strcmp(ex.what(),"expected 'endfacet', found 'endf@cet' on facet 0") == 0);
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"incomplete") == 0);
    assert(shape.size() == 1);
    assert(is_equal(*shape.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(2,2,-3)),shared_ptr<Point_3D>(new Point_3D(1,1,-2)),shared_ptr<Point_3D>(new Point_3D(1,1,1))), precision));
//    cout << "unv x: " << (*shape.at(0)).get_unv().get_x() << " y: " << (*shape.at(0)).get_unv().get_y() << 
//            " z: " << (*shape.at(0)).get_unv().get_z() << "\n"; 
    assert(is_equal(shape.begin()->get_unv(), Vector_3D(-0.707107,0.707107,0), precision));
}

void Test_STL::test_read_stl_28()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    for (int i = 0; i < 30; ++i)
        content.put(0);
    unsigned int size = 2;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    short a = 0;
    content.write((char *) &a, 2);
    val = 2;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -5;
    content.write((char *) &val, 4);
    a = 0;
    content.write((char *) &a, 2);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read short") == 0);
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.size() == 2);
    Mesh_3D::const_iterator iter(shape.begin());
    assert(is_equal(iter->get_unv(), Vector_3D(0.811107, -0.486664, -0.32443), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,5))), precision));
//    cout << "unv x: " << (*shape.at(1)).get_unv().get_x() << " y: " << (*shape.at(1)).get_unv().get_y() << " z: " << (*shape.at(1)).get_unv().get_z() << "\n";
    assert(is_equal(iter->get_unv(), Vector_3D(-0.566139, 0.792594, -0.226455), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,-5))), precision));
}

void Test_STL::test_read_stl_bin_1()
{
    // try to read a non existing stl file
    Mesh_3D shape;
    string filename = "123.stl";
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Unable to open file '123.stl'") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_2()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    vector<string> content;
    create_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Invalid STL file: test.stl") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_3()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "This is a comment";
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        assert(strcmp(ex.what(),"Invalid STL file: test.stl") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"initialized comment") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_4()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read unsigned int") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_5()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    unsigned int size = 1;
    content.write((char *) &size, 4);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file. Expected 1 facets and found 0") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_6()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    unsigned int size = 1;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read float") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_7()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    unsigned int size = 1;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read short") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_8()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    unsigned int size = 1;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    short a = 0;
    content.write((char *) &a, 2);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read short") == 0);
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.size() == 1);
//    cout << "unv x: " << (*shape.at(0)).get_unv().get_x() << " y: " << (*shape.at(0)).get_unv().get_y() << " z: " << (*shape.at(0)).get_unv().get_z() << "\n";
    assert(is_equal(shape.begin()->get_unv(), Vector_3D(0.811107, -0.486664, -0.32443), precision));
    assert(is_equal(*shape.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,5))), precision));
}

void Test_STL::test_read_stl_bin_9()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    for (int i = 0; i < 30; ++i)
        content.put(0);
    unsigned int size = 2;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    short a = 0;
    content.write((char *) &a, 2);
    val = 2;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -5;
    content.write((char *) &val, 4);
    a = 0;
    content.write((char *) &a, 2);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read short") == 0);
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.size() == 2);
    Mesh_3D::const_iterator iter(shape.begin());
    assert(is_equal(iter->get_unv(), Vector_3D(0.811107, -0.486664, -0.32443), precision));
    assert(is_equal(*iter++, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,5))), precision));
//    cout << "unv x: " << (*shape.at(1)).get_unv().get_x() << " y: " << (*shape.at(1)).get_unv().get_y() << " z: " << (*shape.at(1)).get_unv().get_z() << "\n";
    assert(is_equal(iter->get_unv(), Vector_3D(-0.566139, 0.792594, -0.226455), precision));
    assert(is_equal(*iter, Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,-5))), precision));
}

void Test_STL::test_read_stl_bin_10()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    for (int i = 0; i < 30; ++i)
        content.put(0);
    unsigned int size = 1;
    content.write((char *) &size, 4);
    float val = 1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    short a = 0;
    content.write((char *) &a, 2);
    val = 2;
    content.write((char *) &val, 4);
    val = 5;
    content.write((char *) &val, 4);
    val = -1;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 1;
    content.write((char *) &val, 4);
    val = 2;
    content.write((char *) &val, 4);
    val = 0;
    content.write((char *) &val, 4);
    val = -5;
    content.write((char *) &val, 4);
    a = 0;
    content.write((char *) &a, 2);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
//        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file. Expected 1 facets and found 2") == 0);
    }
    assert(caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.empty());
}

void Test_STL::test_read_stl_bin_11()
{
    // try to read an empty file
    Mesh_3D shape;
    string filename = "test.stl";
    stringstream content;
    content << "MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-";
    for (int i = 0; i < 30; ++i)
        content.put(0);
    content.put(0);
    content.put(0);
    content.put(0);
    content.put(1); // big endian size 1
    swap_float_bytes(content, 1);
    swap_float_bytes(content, 0);
    swap_float_bytes(content, -1);
    swap_float_bytes(content, 0);
    swap_float_bytes(content, 0);
    swap_float_bytes(content, 0);
    swap_float_bytes(content, 1);
    swap_float_bytes(content, 1);
    swap_float_bytes(content, 1);
    swap_float_bytes(content, 2);
    swap_float_bytes(content, 0);
    swap_float_bytes(content, 5);
    content.put(0);
    content.put(0);
    create_bin_file(filename, content);
    string comment = "initialized comment";
    bool caught_ex = false;
    try
    {
        int num_facets = read_stl_bin_cbo(shape, filename, comment);
    } 
    catch (const STL_Error& ex)
    {
        caught_ex = true;
        cout << "what: " << ex.what() << "\n";
        assert(strcmp(ex.what(),"Invalid STL file.  Unable to read short") == 0);
    }
    assert(!caught_ex);
    assert(strcmp(comment.c_str(),"MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-MESH-") == 0);
    assert(shape.size() == 1);
    assert(is_equal(shape.begin()->get_unv(), Vector_3D(0.811107, -0.486664, -0.32443), precision));
    assert(is_equal(*shape.begin(), Facet_3D(shared_ptr<Point_3D>(new Point_3D(0,0,0)), shared_ptr<Point_3D>(new Point_3D(1,1,1)), shared_ptr<Point_3D>(new Point_3D(2,0,5))), precision));
//    cout << "unv x: " << (*shape.at(1)).get_unv().get_x() << " y: " << (*shape.at(1)).get_unv().get_y() << " z: " << (*shape.at(1)).get_unv().get_z() << "\n";
}

void Test_STL::test_write_stl_1()
{
    // create a cube, write it in ascii and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl(shape, "test.stl", "cuboid shape 10x10x10");
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_2()
{
    // create a cube, write it in binary and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl_bin(shape, "test.stl", "cuboid shape 10x10x10");
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_3()
{
    // create a cube, write it in binary and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl_bin_nbo(shape, "test.stl", "cuboid shape 10x10x10");
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_4()
{
    // create a cube, write it in ascii and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl(shape, "test.stl", "cuboid shape 10x10x10", false, true);
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_5()
{
    // create a cube, write it in binary and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl_bin(shape, "test.stl", "cuboid shape 10x10x10", 0, false, true);
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_6()
{
    // create a cube, write it in binary and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl_bin(shape, "test.stl", "cuboid shape 10x10x10", 0, true, true);
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment, true);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_7()
{
    // create a cube, write it in ascii and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl(shape, "test.stl", "cuboid shape 10x10x10", true);
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}

void Test_STL::test_write_stl_8()
{
    // create a cube, write it in ascii and test result
    Mesh_3D shape;
    m_cuboid(shape, 10, 10, 10);
    write_stl(shape, "test.stl", "cuboid shape 10x10x10", true, true);
    Mesh_3D result;
    string comment;
    read_stl(result, "test.stl", comment, false, true);
    assert(strcmp(comment.c_str(),"cuboid shape 10x10x10") == 0);
    assert(shape.size() == result.size());
    Mesh_3D::const_iterator r_it = result.begin();
    for (Mesh_3D::const_iterator it = shape.begin(); it != shape.end(); ++it)
    {
//        cout << "shape p1 x: " << (*it)->get_point1().get_x() << " y: " << (*it)->get_point1().get_y() << 
//                " z: " << (*it)->get_point1().get_z() << " p2 x: " << (*it)->get_point2().get_x() << " y: " <<
//                (*it)->get_point2().get_y() << " z: " << (*it)->get_point2().get_z() << " p3 x: " <<
//                (*it)->get_point3().get_x() << " y: " << (*it)->get_point3().get_y() << " z: " <<
//                (*it)->get_point3().get_z() << "\n";
//        cout << "result p1 x: " << (*r_it)->get_point1().get_x() << " y: " << (*r_it)->get_point1().get_y() << 
//                " z: " << (*r_it)->get_point1().get_z() << " p2 x: " << (*r_it)->get_point2().get_x() << " y: " <<
//                (*r_it)->get_point2().get_y() << " z: " << (*r_it)->get_point2().get_z() << " p3 x: " <<
//                (*r_it)->get_point3().get_x() << " y: " << (*r_it)->get_point3().get_y() << " z: " <<
//                (*r_it)->get_point3().get_z() << "\n";
        assert(is_equal(*it, *r_it, precision));
        ++r_it;
    }
}
