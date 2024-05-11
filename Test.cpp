#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;
using namespace ariel;

TEST_CASE("Test isConnected undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected undircted Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 1, 2, 0, 0},
        {1, 0, 6, 0, 0},
        {2, 6, 0, 9, 0},
        {0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
        {0, 3, 6, 0, 0, -5},
        {3, 0, 3, 7, 0, 0},
        {6, 3, 0, 0, 8, 0},
        {0, 7, 0, 0, -3, -2},
        {0, 0, 8, -3, 0, 1},
        {-5, 0, 0, -2, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 7, 0, 0},
        {0, 3, 0, 0, 8, 0},
        {0, 7, 0, 0, -3, -2},
        {0, 0, 8, -3, 0, 1},
        {0, 0, 0, -2, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0, 2, 4, 0, 0, 0, 0, 1},
        {2, 0, 5, 3, 0, 0, 0, 0},
        {4, 5, 0, 7, 0, 0, 0, 0},
        {0, 3, 7, 0, -5, 0, 0, 0},
        {0, 0, 0, -5, 0, 6, 7, 0},
        {0, 0, 0, 0, 6, 0, 4, 2},
        {0, 0, 0, 0, 7, 4, 0, 5},
        {1, 0, 0, 0, 0, 2, 5, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected dircted unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, 1, 0, 0, 1, 0, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected dircted Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 0, 2, 9, 0, 0},
        {6, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 4},
        {0, -6, 0, 3, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 0, 8, 1, 0, 0},
        {2, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, -1, 0, 0, 6, 0, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 3, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 9, 0, 0},  // 2
        {0, 0, 0, 0, 12, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 5, 0, 0, 0},  // 4
        {0, 0, 0, 6, 0, 0, 0, 7, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 10, 0, 0, 0, 0, 0, 3}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 1, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 1, 5) == "1->3->5");
}

TEST_CASE("Test shortestPath undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {0, 0, 4},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(Algorithms::shortestPath(g, 2, 1) == "-1");

    vector<vector<int>> graph2 = {
        {0, 2, 7, 0, 0},
        {2, 0, 3, 0, 0},
        {7, 3, 0, 2, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(Algorithms::shortestPath(g, 3, 0) == "3->2->1->0");

    vector<vector<int>> graph4 = {
        {0, 1, 5, 0, 0, 1},
        {1, 0, 6, 1, 0, 0},
        {5, 6, 0, 0, 4, 0},
        {0, 1, 0, 0, 3, 2},
        {0, 0, 4, 3, 0, 1},
        {1, 0, 0, 2, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 1, 5) == "1->0->5");
}

TEST_CASE("Test shortestPath directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 2, 0) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 4, 0) == "4->3->2->0");

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 2, 5) == "-1");

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, 1, 0, 0, 1, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(Algorithms::shortestPath(g, 3, 6) == "3->4->5->7->2->6");
}

TEST_CASE("Test shortestPath directed Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 2, 0) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0},
        {3, 1, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, -2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 4, 0) == "4->3->2->0");

    vector<vector<int>> graph3 = {
        {0, -1, 0, 0, 0, 0},
        {0, 0, -4, 0, 0, 0},
        {12, 11, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {-9, 0, 0, 6, 0, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 2, 5) == "-1");

    vector<vector<int>> graph4 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, 2, 0, 0, 1, 0, 0},    // 0
        {0, 0, 0, 0, 0, 0, 1, 0},    // 1
        {0, 0, 0, 0, 0, 0, 1, 0},    // 2
        {0, 0, 0, 0, 1, 0, 0, 0},    // 3
        {0, 0, 0, 0, 0, 1, 0, 0},    // 4
        {7, 0, 0, 1, 0, 0, 0, 5},    // 5
        {0, 0, 0, 0, 0, 0, 0, 0},    // 6
        {0, 0, -10, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 7, 1) == "-1");
    CHECK(Algorithms::shortestPath(g, 5, 2) == "5->7->2");

    vector<vector<int>> graph5 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, -2, 0, 0, 1, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 1, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0},  // 4
        {2, 0, 0, 1, 0, 0, 3, 1},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 2, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph5);
    CHECK(Algorithms::shortestPath(g, 5, 2) == "5->0->2");
}

TEST_CASE("Test isContainsCycle undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph3 = {
        //   0  1  2  3  4  5
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 0, 0, 1, 0}};

    g.loadGraph(graph3);
    CHECK(Algorithms::isContainsCycle(g) == "1->2->3->4->5->1");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 4},
        {2, 0, 7},
        {4, 7, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 6, 0},
        {6, 0, 8},
        {0, 8, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph3 = {
        {0, 2, 1, 0, 0, 0},
        {2, 0, 3, 5, 0, 0},
        {1, 3, 0, 0, 1, 0},
        {0, 5, 0, 0, 7, 1},
        {0, 0, 1, 7, 0, 2},
        {0, 0, 0, 1, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 8, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {8, -6, 1, 0, -2, 0},
        {0, 0, 0, -2, 0, 10},
        {0, 0, 0, 0, 10, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "1->3->4->1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle directed Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 2},
        {4, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 8, 1, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, -4},
        {0, 3, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "1->3->4->1");

    vector<vector<int>> graph2 = {
        {0, 10, 8, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isBipartite undirected unWeighted")
{
    ariel::Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}.");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,1,2,4}, B={3,5}.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, -2, -2},
        {-2, 0, 5},
        {-2, 5, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 5, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, -1, 0, 0},
        {5, 2, -1, 0, 4, 0},
        {0, 0, 0, 4, 0, 2},
        {0, 0, 0, 0, 2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,1,2,4}, B={3,5}.");

    vector<vector<int>> graph2 = {
        {0, 2, 8, 0, 0, 0, 0, 4},
        {1, 0, 1, 3, 0, 0, 0, 0},
        {2, 8, 0, 2, 0, 0, 0, 0},
        {0, 3, 2, 0, -1, 0, 0, 5},
        {0, 0, 0, -1, 0, -5, 6, 0},
        {0, 0, 0, 0, -5, 0, 1, 7},
        {0, 0, 0, 0, 6, 1, 0, 1},
        {4, 0, 0, 5, 0, 7, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={1,2,3,5}, B={0,4}.");

    vector<vector<int>> graph1 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, 1, 0, 0, 1, 0, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite directed weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 2, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, -1, 0, -5, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6, 0, 0, 0},
        {4, 0, 0, 0, 0, 7, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 3, 20, 0, 0},
        {2, 0, 0, 0, 13, 0},
        {0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={1,2,3,5}, B={0,4}.");
}

TEST_CASE("Test negativeCycle Exists")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::negativeCycle(g) == "1->2->0->1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0},
        {1, 0, -1, 0},
        {0, 0, 0, 1},
        {0, -1, 0, 0}};

    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == "2->3->1->2");
}

TEST_CASE("Test negativeCycle Does not Exist")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::negativeCycle(g) == "-1");

     vector<vector<int>> graph1 = {
        {0, 2, 1, 0, 0, 0},
        {2, 0, 3, 5, 0, 0},
        {1, 3, 0, 0, 1, 0},
        {0, 5, 0, 0, 7, 1},
        {0, 0, 1, 7, 0, 2},
        {0, 0, 0, 1, 2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == "-1");
}

TEST_CASE("Test invalid graph Coluomn missing")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph0));
}

TEST_CASE("Test invalid graph Row missing")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 2},
        {1, 0, 3}};
    CHECK_THROWS(g.loadGraph(graph0));
}
