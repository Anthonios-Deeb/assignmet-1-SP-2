#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
using namespace std;

namespace ariel
{
  class Graph
  {
  public:
    Graph() = default;
    ~Graph() = default;
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    void loadGraph(vector<vector<int> > graph);
    void printGraph();
    vector<vector<int>> getAdjMatrix();

  private:
    vector<vector<int> > graph;
  }; 
}
#endif