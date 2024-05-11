#include "Graph.hpp"
#include <iostream>

using namespace ariel;

//check if the graph is valid or not
void Graph::loadGraph(vector<vector<int> > graph)
{
  if(graph.size() == 0)
  {
    throw invalid_argument("Graph is empty");
  }

  if (graph.size() != graph[0].size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  this->graph = graph;
}

void Graph::printGraph(){
  int edges = 0;
  for(auto & i : graph)
  {
    for(int j : i)
    {
        if (j!=0)
        {
            edges++;
        }
    }
  }
  cout << "Graph with " << graph.size() << " vertices and " << edges << " edges." << endl;
}

vector<vector<int>> Graph::getAdjMatrix() {
    return graph;
}