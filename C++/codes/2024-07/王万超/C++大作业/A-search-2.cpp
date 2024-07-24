
#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/random.hpp>
#include <boost/graph/graphviz.hpp>
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <math.h> // for sqrt

using namespace boost;
using namespace std;

// auxiliary types
struct location
{
    float y, x; // lat, long
};
typedef float cost;

template < class Name, class LocMap >

class city_writer
{
public:
    city_writer(Name n, LocMap l, float _minx, float _maxx, float _miny,
        float _maxy, unsigned int _ptx, unsigned int _pty)
    : name(n)
    , loc(l)
    , minx(_minx)
    , maxx(_maxx)
    , miny(_miny)
    , maxy(_maxy)
    , ptx(_ptx)
    , pty(_pty)
    {
    }
    template < class Vertex >
    void operator()(ostream& out, const Vertex& v) const
    {
        float px = 1 - (loc[v].x - minx) / (maxx - minx);
        float py = (loc[v].y - miny) / (maxy - miny);
        out << "[City-Name=\"" << name[v] << "\", pos=\""
            << static_cast< unsigned int >(ptx *  px) << ","
            << static_cast< unsigned int >(pty *  py) << "\"]";
    }


private:
    Name name;
    LocMap loc;
    float minx, maxx, miny, maxy;
    unsigned int ptx, pty;
};

template < class WeightMap >
 class time_writer
{
public:
    time_writer(WeightMap w) : wm(w) {}
    template < class Edge > void operator()(ostream& out, const Edge& e) const
    {
        out << "[Weight=\"" << wm[e] << "\"]";
    }

private:
    WeightMap wm;
};

// euclidean distance heuristic
template < class Graph, class CostType, class LocMap >
class distance_heuristic : public astar_heuristic< Graph, CostType >
{
public:
    typedef typename graph_traits< Graph >::vertex_descriptor Vertex;
    distance_heuristic(LocMap l, Vertex goal) : m_location(l), m_goal(goal) {}
    CostType operator()(Vertex u)
    {
        CostType dx = m_location[m_goal].x - m_location[u].x;
        CostType dy = m_location[m_goal].y - m_location[u].y;
        return ::sqrt(dx * dx + dy * dy);
    }

private:
    LocMap m_location;
    Vertex m_goal;
};

struct found_goal
{
}; // exception for termination

// visitor that terminates when we find the goal
template < class Vertex >
class astar_goal_visitor : public boost::default_astar_visitor
{
public:
    astar_goal_visitor(Vertex goal) : m_goal(goal) {}
    template < class Graph > void examine_vertex(Vertex u, Graph& g)
    {
        if (u == m_goal)
            throw found_goal();
    }

private:
    Vertex m_goal;
};

int main(int argc, char** argv)
{

    // specify some types
    typedef adjacency_list< listS, vecS, undirectedS, no_property, 
        property< edge_weight_t, cost > > mygraph_t;  //lists->边、vecs->顶点、undirecteds->无向、无属性、权重
    typedef property_map< mygraph_t, edge_weight_t >::type WeightMap; //权重映射 用于访问边的权重
    typedef mygraph_t::vertex_descriptor vertex; //顶点描述符
    typedef mygraph_t::edge_descriptor edge_descriptor; // 边描述符
    typedef std::pair< int, int > edge; // 一条边

    // specify data
    enum nodes
    {
        One, Two,Three,Four,Five,Six,Seven,  Eight,
        Nine, Ten,Eleven,Twelve,Thirteen,Fourteen,Fifteen,Sixteen,
        Seventeen,Eighteen,Nineteen,Twenty,TwentyOne,TwentyTwo,TwentyThree,TwentyFour,
        TwentyFive,TwentySix,TwentySeven,TwentyEight,TwentyNine,Thirty,ThirtyOne,ThirtyTwo,
    };
    const char* name[] = { "(1,1)", "(1,2)", "(1,3)", "(1,4)","(1,5)","(1,6)","(1,7)","(1,8)",
        "(2,1)", "(2,2)", "(2,3)", "(2,4)","(2,5)","(2,6)","(2,7)","(2,8)",
        "(3,1)", "(3,2)", "(3,3)", "(3,4)","(3,5)","(3,6)","(3,7)","(3,8)",
        "(4,1)", "(4,2)", "(4,3)", "(4,4)","(4,5)","(4,6)","(4,7)","(4,8)",
        };
    location locations[] = { // lat/long
        { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 },{1,5},  {1,6},{1,7},{1,8},
        { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 },{2,5},  {2,6},{2,7},{2,8},
        { 3, 1 }, { 3, 2 }, { 3, 3 }, { 3, 4 },{3,5},  {3,6},{3,7},{3,8},
        { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 },{4,5},  {4,6},{4,7},{4,8},
    };
    edge edge_array[]
        = { edge(One, Two), edge(One, Nine), edge(One, Ten),
            edge(Two, Three), edge(Two,Nine),edge(Two, Ten), edge(Two, Eleven),
            edge(Three, Four), edge(Three, Ten), edge(Three, Eleven), edge(Three, Twelve),
            edge(Four, Eleven), edge(Four, Twelve), edge(Four, Thirteen),
            edge(Nine, Ten), edge(Ten, Eleven), edge(Eleven, Twelve),edge(Twelve, Thirteen),edge(Ten, Nineteen),
            edge(Eleven, Nineteen),edge(Nineteen, TwentySeven),edge(TwentySeven, TwentySix),
            edge(TwentySeven, TwentyEight),edge(TwentyEight, TwentyNine),
            edge(TwentyNine, Thirty),edge(Thirty, ThirtyOne),edge(ThirtyOne, ThirtyTwo),
            edge(Thirty, TwentyTwo),edge(Thirty, TwentyThree),edge(ThirtyOne, TwentyThree),edge(ThirtyOne, TwentyFour),edge(ThirtyTwo, TwentyFour),
         };
    unsigned int num_edges = sizeof(edge_array) / sizeof(edge);//边的数量
    cost weights[] = { // estimated travel time (mins)
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1 ,1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,1
    };

    // create graph
    mygraph_t g(32);
    WeightMap weightmap = get(edge_weight, g); //用weightmap[e]来访问边的权重
    for (std::size_t j = 0; j < num_edges; ++j)
    {
        edge_descriptor e;
        bool inserted;
        boost::tie(e, inserted)
            = add_edge(edge_array[j].first, edge_array[j].second, g);
        weightmap[e] = weights[j];
    }

    // pick random start/goal
    vertex start = vertex(0);   
    vertex goal = vertex(31);

    cout << "Start vertex: " << name[start] << endl;
    cout << "Goal vertex: " << name[goal] << endl;

    ofstream dotfile;
    dotfile.open("test-astar-cities.dot");
    write_graphviz(dotfile, g,
        city_writer< const char**, location* >(name, locations, 73.46, 78.86, 40.67, 44.93, 480, 400),
        time_writer< WeightMap >(weightmap));

    vector< mygraph_t::vertex_descriptor > p(num_vertices(g)); //num_vertices(g)返回图g的顶点数
    vector< cost > d(num_vertices(g));
    try
    {
        // call astar named parameter interface
        astar_search_tree(g, start,
            distance_heuristic< mygraph_t, cost, location* >(locations, goal),      //启发式函数
            predecessor_map(make_iterator_property_map(p.begin(), get(vertex_index, g))) //前驱映射
            .distance_map(make_iterator_property_map(d.begin(), get(vertex_index, g))) //距离映射
                .visitor(astar_goal_visitor< vertex >(goal)));
    }
    catch (found_goal fg)
    { // found a path to the goal
        list< vertex > shortest_path;
        for (vertex v = goal;; v = p[v])
        {
            shortest_path.push_front(v);
            if (p[v] == v)
                break;
        }
        cout << "Shortest path from " << name[start] << " to " << name[goal]
             << ": ";
        list< vertex >::iterator spi = shortest_path.begin();
        cout << name[start];
        for (++spi; spi != shortest_path.end(); ++spi)
            cout << " -> " << name[*spi];
        cout << endl << "Total travel time: " << d[goal] << endl;
        return 0;
    }

    cout << "Didn't find a path from " << name[start] << "to" << name[goal]
         << "!" << endl;
    return 0;
}