/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: Write a C++ (or Java) program for hw3_1 that reads a number of elements in a set first. Then, your program should read the elements of the set. After that, your program should display all possible decimal 
numbers, corresponding binary numbers, and subsets one by on
 * ID: 0621
 * Name: Zihao Xu
 * Date: 9/14/2022
 */

#include <iostream>
#include <cmath>
#include <list>
using namespace std;

int main() {
	// Your code should be here.
	// The following is a just sample statement.
	int n;
  cin >> n;

  if(n==0){
    cout << "0:0:EMPTY"<<"\n";

    exit(0);
  }
  
  string arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int numberOfbinary = pow(2,n);

  for(int i=0;i<numberOfbinary;i++){
    cout << i << ":";

    int binaryNum[10];
    for(int k=0;k<10;k++){
      binaryNum[k] = 0;
    }

    //decimal to binary
    int j=0;
    int temp=i;
    
    while(temp>0){
      binaryNum[j] = temp%2;
      temp = temp/ 2;
      j++;
    }

    for (int k = n-1; k >= 0; k--){
      cout << binaryNum[k];
    }

    cout << ":";

    //display string
    bool empty = true;
    int count=0;
    int count2=0;
    for(int k = n-1; k >= 0; k--){

      if(binaryNum[k] == 1){
        if(count2 != 0){
          cout << " ";
        }
        
        cout << arr[count];
        count2++;
        
        empty = false;
      }

      

      count++;
    }

    if(empty){
        cout << "EMPTY";
      }

    cout << "\n";
  }

	return 0;
}

