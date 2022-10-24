/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_1.cpp
 * Abstract:program for hw7_1 which displays the smallest number in an array with n integer numbers using a divide-and-conquer technique. 
 * ID: 0622
 * Name: Zihao Xu
 * Date: 10/19/2022
 */

#include <iostream>
#include <climits>
using namespace std;

int smallest =INT_MAX;

int DisplaySmall(int arr[], int start, int end){
  
  if (abs(start-end) == 1) 
    {
        if(arr[start] >= arr[end]){
          if(arr[end] <= smallest){
            smallest = arr[end];
          }
        }else{
          if(arr[start] <= smallest){
            smallest = arr[start];
          }
        }
    }else if(start == end){
      if(arr[end] <= smallest){
        smallest = arr[end];
      }
    }
    else 
    {
        int small_1 = DisplaySmall(arr, start, (start+end)/2);
        int small_2 = DisplaySmall(arr, (start+end)/2+1, end);
    }

  return smallest;
}

int main() {
	int n;
  cin >> n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int small = DisplaySmall(arr, 0, n-1);

  cout << small << endl;

	return 0;
}

