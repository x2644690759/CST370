/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw6_1.cpp
 * Abstract: Write a C++ (or Java) program for hw6_1 that conducts the BFS in a social networking service (= SNS) such as LinkedIn or Faceboo
 * ID: 0621
 * Name: Zihao Xu
 * Date: 10/6/2022
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void read_graph(vector<vector<int>> & g, unordered_map<string, int> Name_Number, int vertex)
{
    g.resize(vertex);
    
    int connections;
    cin >> connections;

    string from;
    string to;
    
    for (int i = 0; i < connections; i++) 
    {
        cin >> from;
        cin >> to;
        g[Name_Number[from]].push_back(Name_Number[to]);
    }

    for (int i = 0; i < g.size(); i++) 
    {
        sort(g[i].begin(), g[i].end());
    }
}

int main()
{
  int vertex;
  string start;
  int degree;

  unordered_map<string, int> Name_Number;
  unordered_map<int, string> Number_Name;

  cin >> vertex;
  for(int i=0;i<vertex;i++){
    string name;
    cin >> name;

    Name_Number[name] = i;
    Number_Name[i] = name;
  }

  vector<vector<int>> graph;

  read_graph(graph, Name_Number, vertex);

  cin >> start;
  cin >> degree;

  //initial mark array
  int arr[vertex];

  for(int i=0;i<vertex;i++){
    arr[i] = -1;
  }
  arr[Name_Number[start]] = 0;

  //initial queue
  queue<int> q;
  q.push(Name_Number[start]);
  int temp = 0;

  //BFS
  do{
    int size = q.size();
    temp++;
    
    for(int i=0;i<size;i++){
      int size2 = graph[q.front()].size();
      
      for(int j=0;j<size2;j++){
        if(arr[graph[q.front()][j]] == -1){
          q.push(graph[q.front()][j]);

          arr[graph[q.front()][j]] = temp;
        }
      }

      q.pop();
    }
  }while(temp < degree);

  //output
  int a = q.size()-1;
  if(q.empty()){
    cout << "NONE" << endl;
  }else{
  while (!q.empty()) {
        cout << Number_Name[q.front()];

        if(a != 0){
          cout << ",";
          a--;
        }
        q.pop();
    }
  }
  cout << endl;
  
  return 0;
}
