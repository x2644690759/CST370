/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_1.cpp
 * Abstract: Write a C++ (or Java) program for hw8_1 that conducts the topological sorting using the Kahn algorithm covered in the class. 
 * ID: 0621
 * Name: Zihao Xu
 * Date: 10/26/2022
 */

#include <bits/stdc++.h>
using namespace std;
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing
    // adjacency listsList
    list<int>* adj;
 
public:
    // Constructor
    Graph(int V);
 
    // Function to add an edge to graph
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
}
 
// The function to do
// Topological Sort.
void Graph::topologicalSort()
{
    // Create a vector to store
    // indegrees of all
    // vertices. Initialize all
    // indegrees as 0.
    vector<int> in_degree(V, 0);
    vector<int> in_degree2(V, 0);
 
    // Traverse adjacency lists
    // to fill indegrees of
    // vertices.  This step
    // takes O(V+E) time
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }

    in_degree2 = in_degree;
 
    // Create an queue and enqueue
    // all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
 
    // Initialize count of visited vertices
    int cnt = 0;
 
    // Create a vector to store
    // result (A topological
    // ordering of the vertices)
    vector<int> top_order;
 
    // One by one dequeue vertices
    // from queue and enqueue
    // adjacents if indegree of
    // adjacent becomes 0
    while (!q.empty()) {
        // Extract front of queue
        // (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        // Iterate through all its
        // neighbouring nodes
        // of dequeued node u and
        // decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
 
            // If in-degree becomes zero,
            // add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);
 
        cnt++;
    }
 
    // Check if there was a cycle
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }
    //print in-degrees of all vertices
    for(int i=0;i<in_degree2.size();i++){
      cout << "In-degree[" << i << "]:" << in_degree2[i] << endl;
    }
    cout << "Order:";
    // Print topological order
    for (int i = 0; i < top_order.size(); i++){
      cout << top_order[i];
      if(i != top_order.size()-1){
        cout << "->";
      }
    }
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the
    // above diagram
    int vert;
    int edg;
    cin >> vert;
    cin >> edg;
  
    Graph g(vert);
    for(int i=0;i<edg;i++){
      g.addEdge();
    }
 
    
    g.topologicalSort();
 
    return 0;
}

