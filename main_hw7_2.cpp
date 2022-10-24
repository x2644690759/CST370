/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_2.cpp
 * Abstract:  Write a C++ program (or Java program) for hw7_2 that reads the number of input values from a user. Then, read the input values from the user. After that, your program should display them in 
the ascending order.
 * ID: 0621
 * Name: Zihao Xu
 * Date: 10/19/2022
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  sort(arr, arr+n);
  vector <int>result;
  set <int>mark;
  result.push_back(arr[0]);

  if(arr[0]+1 == arr[1]){
    mark.insert(arr[0]);
  }
  
  for(int i=1;i<n;i++){
    
      if(arr[i]-1 == arr[i-1] && arr[i+1] == arr[i]+1){
        continue;
      }else{
        result.push_back(arr[i]);
      }

      if(arr[i+1] == arr[i]+1 && arr[i]-1 != arr[i-1]){
        if(i == n-1){
          break;
        }
        
        mark.insert(result.back());
      }
    
  }

  for(int i=0;i<result.size();i++){
    cout << result[i];

    if(mark.find(result[i]) != mark.end()){
      cout << "-";
    }else{
      if(i != result.size()-1){
        cout << " ";
      }
    }
  }

  cout << endl;
  return 0;
}

