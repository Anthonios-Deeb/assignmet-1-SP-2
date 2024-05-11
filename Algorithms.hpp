#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <string>
#include "Graph.hpp" // Assuming Graph.hpp contains the definition of Graph
using namespace std;

namespace ariel
{
  class Algorithms
  {
  public:
    Algorithms() = default;
    ~Algorithms() = default;
    Algorithms(const Algorithms &) = delete;
    Algorithms &operator=(const Algorithms &) = delete;
    static int isConnected(Graph &g);
    static string shortestPath(Graph &g, int start, int end);
    static string isContainsCycle(Graph &g);
    static string isBipartite(Graph &g);
    static string negativeCycle(Graph &g);
  };
}

#endif // ALGORITHMS_HPP
