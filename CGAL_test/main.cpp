#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/algorithm.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/convex_hull_3.h>
#include <vector>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef Polyhedron::Facet_iterator Facet_iterator;
typedef Polyhedron::Halfedge_around_facet_circulator Halfedge_facet_circulator;

int main()
{
    std::vector<Point_3> points;

    points.push_back(Point_3(2.0f, 3.535533905932738f, 3.535533905932737f));
    points.push_back(Point_3(4.0f, 2.0f, 0.0f));
    points.push_back(Point_3(0.0f, 2.0f, 0.0f));
    points.push_back(Point_3(1.0f, 0.0f, 0.0f));
    points.push_back(Point_3(4.0f, 1.414213562373095f, 1.414213562373095f));
    points.push_back(Point_3(0.0f, 1.414213562373095f, 1.414213562373095f));
    points.push_back(Point_3(3.0f, 0.0f, 0.0f));
    points.push_back(Point_3(2.0f, 5.0f, 0.0f));

    Polyhedron P;

    CGAL::convex_hull_3(points.begin(), points.end(), P);

    std::cout << "- Number of vertices  = " << P.size_of_vertices()    << std::endl;
    std::cout << "- Number of edges     = " << P.size_of_halfedges()/2 << std::endl;
    std::cout << "- Number of faces     = " << P.size_of_facets()      << std::endl;

    for ( Facet_iterator i = P.facets_begin(); i != P.facets_end(); ++i)
    {
        Halfedge_facet_circulator j = i->facet_begin();
        CGAL_assertion( CGAL::circulator_size(j) >= 3);
        std::cout << CGAL::circulator_size(j) << ' ';
        do{
            //std::cout << ' ' << std::distance(P.vertices_begin(), j->vertex());
            std::cout << " (" << j->vertex()->point().x() << ' ' << j->vertex()->point().y() << ' ' << j->vertex()->point().z() << ')' << ", ";
        } while ( ++j != i->facet_begin());

        std::cout << std::endl;
    }
    return 0;
}
