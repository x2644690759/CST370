/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: Write a C++ (or Java) program for hw5_1 that reads an input graph data from a user. Then, it should present a path for the travelling salesman problem (TSP). 
 * ID: 0621
 * Name: Zihao Xu
 * Date: 9/27/2022
 */

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

class finalPermutation{
  public:
   vector<int> path;
   int cost = 0;
   int count = 0;
};

int MIN_cost = INT_MAX;
finalPermutation finalAns;


finalPermutation calculation(int a[], int n, int route[][3], int edge, int startPoint) 
{ 
  int newArr[n+1];
  for(int i=0;i<n+1;i++){
    newArr[i] = a[i];
  }
  newArr[n] = startPoint;
  
  finalPermutation tempObject;
  
	for(int i=0;i<n;i++){
    int first = newArr[i];
    int second = newArr[i+1];
    
    for(int k=0;k<edge;k++){
      if(first == route[k][0] && second == route[k][1]){
        tempObject.path.push_back(second);

        tempObject.cost += route[k][2];
      }
    }
  }

  return tempObject;
}

void find_permutations(int a[], int n, int route[][3], int edge, int startPoint, int realOne) 
{ 
	// Sort the given array first.
	sort(a, a + n); 

	// Find all possible permutations 
	do 
	{ 
    if(a[0] == startPoint){
      finalPermutation temp = calculation(a, n, route, edge, startPoint);

      if(temp.path.size() == n &&  temp.cost < MIN_cost){
        finalAns = temp;

        MIN_cost = temp.cost;
      }
    }
    
	} while (next_permutation(a, a + n)); 
}

int main() 
{ 
  //Get user's input
  int vertice;
  int edge;
  int startPoint;
  
  cin >> vertice;
  cin >> edge;

  int route[edge][3];
  for(int i=0;i<edge;i++){
    cin >> route[i][0];
    cin >> route[i][1];
    cin >> route[i][2];
  }

  cin >> startPoint;

  //calculte all the permutations
  int allVertice[vertice];

  for(int i=0;i<vertice;i++){
    allVertice[i] = i;
  }

  int realOne = allVertice[1];
  
  find_permutations(allVertice, vertice, route, edge, startPoint, realOne);

  if(finalAns.cost == 0){
    cout << "Path:" << endl;
    cout << "Cost:-1" << endl;
  }else{

  cout << "Path:" << startPoint;
  for(auto it=finalAns.path.begin(); it != finalAns.path.end();it++)  {
    cout << "->" << *it;
  }

  cout << "\nCost:" << finalAns.cost << endl;
    }
	return 0;
} 




