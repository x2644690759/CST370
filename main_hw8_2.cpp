/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_2.cpp
 * Abstract: Write a C++ (or Java) program for hw8_2 that implements the topological sorting algorithm based on the DFS algorithm.
 * ID: 0621
 * Name: Zihao Xu
 * Date: 10/26/2022
 */

#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int> arr;
set<int> cylic;
bool acylic = true;
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack, int& cnt);
 
public:
    // Constructor
    Graph(int V);
 
    // function to add an edge to graph
    void addEdge();
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge()
{
    int u,v;
    cin >>u;
    cin >>v;
  
    adj[u].push_back(v);
    arr.insert(v);
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack, int& cnt)
{
    // Mark the current node as visited.
    visited[v] = true;
    cylic.insert(v);
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){
            topologicalSortUtil(*i, visited, Stack, cnt);
          }else{
            if(cylic.find(*i) != cylic.end()){
              acylic = false;
            }
          }
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
    cylic.clear();
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
    int cnt=0;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack,cnt);

    if(acylic){
      int count = Stack.size();
      
      vector<int> result;
      for(int i=0;i<V;i++){
        if(arr.find(i) == arr.end()){
          result.push_back(i);
        }
      }
      
      cout << "This is a DAG." << endl;
      cout << "Start node(s):";
      for(int i=0;i<result.size();i++){
        cout << result[i];

        if(i != result.size()-1){
          cout << " ";
        }
      }
      cout << "\nTopological sort:";
      while (Stack.empty() == false) {
        cout << Stack.top();
        if(count != 1){
          cout << "->";
          count--;
        }
        Stack.pop();
      }
      cout << endl;
    }else{
      cout << "This is not a DAG." << endl;
    }

}
 
// Driver Code
int main()
{
    // Create a graph given in the above diagram
    int vert;
    int edg;
    cin >> vert;
    cin >> edg;
  
    Graph g(vert);
    for(int i=0;i<edg;i++){
      g.addEdge();
    }

 
    // Function Call
    g.topologicalSort();
 
    return 0;
}

