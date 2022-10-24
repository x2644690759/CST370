/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_3.cpp
 * Abstract:  Write a C++ (or Java) program for hw7_3 that reads a number of input values and the values themselves. Then, your program should put all negative numbers in front of all positive num
 * ID: 0621
 * Name: Zihao Xu
 * Date: 10/19/2022
 */

#include <iostream>
using namespace std;

int main() {
	int n=0;
  cin >> n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int arr2[n];
  for(int i=0;i<n;i++){
    arr2[i] = arr[i];
  }

  //first approach
  int pointer = n-1;
  for(int i=0;i<n;i++){
    if(i == pointer){
      break;
    }
    
    if(arr[i] < 0){
      continue;
    }
    
    for(int j=pointer;j>=0;j--){
      
      if(arr[j] <0){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        break;
      }

      pointer--;
    }
  }

  for(int i=0; i<n;i++){
    cout << arr[i];

    if(i != n-1){
      cout << " ";
    }
  }
  cout << endl;
  
  //second approach
  int pointer2 = n-1;
  bool stop = false;
  
  for(int i=n-1;i>=0;i--){
    if(stop){
      break;
    }
    
    if(arr2[i]>0){
      if(i == pointer2){
        pointer2--;
      }
      
      continue;
    }
    
    for(int j=pointer2;j>=0;j--){
      if(arr2[j] > 0){
        int temp;
        temp = arr2[i];
        arr2[i] = arr2[j];
        arr2[j] = temp;

        pointer2 = j;
        break;
      }

      if(j == 0){
        stop = true;
      }
    }
  }

  for(int i=0; i<n;i++){
    cout << arr2[i];

    if(i != n-1){
      cout << " ";
    }
  }

  cout << endl;

	return 0;
}

