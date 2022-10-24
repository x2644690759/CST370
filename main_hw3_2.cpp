/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_2.cpp
 * Abstract: Write a C++ (or Java) program for hw3_2 that converts a directed weighted graph data from a user into 
a corresponding adjacency list form
 * ID: 0621
 * Name: Zihao Xu
 * Date: 9/14/2022
 */

#include <iostream>
#include <map>
using namespace std;

int main()
{
  //Get user's input
  int vertex;
  int edge;
  cin >> vertex;
  cin >> edge;

  int startPoint[edge];
  int endPoint[edge];
  int cost[edge];

  for(int i=0;i<edge;i++){
    cin >> startPoint[i];
    cin >> endPoint[i];
    cin >> cost[i];
  }

  //display
  for(int i=0;i<vertex;i++){
    cout << i;
    map<int,int>temp;
    
    for(int k=0;k<edge;k++){
      if(startPoint[k] == i){
        temp.insert(pair<int,int>(endPoint[k],cost[k]));
      }
    }

    for(auto it=temp.begin(); it != temp.end(); it++){
      cout << "->" << it->first << "," << it->second;
    }

    cout << "\n";
  }

    return 0;
}

