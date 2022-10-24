/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_2.cpp
 * Abstract: Write a C++ program (or Java program) for hw2_1 that reads a set of events and displays the maximum number of events that take place concurrently.
 * ID: 0621
 * Name: Zihao Xu
 * Date: 9/3/2022
 */

#include <iostream>
using namespace std;

int main()
{
  int num;

  cin >> num;
  
  int event[num][2];

  for(int i=0;i<num;i++){
    cin >> event[i][0];
    cin >> event[i][1];
  }

  int max=1;

  for(int i=0;i<num;i++){
    bool add=false;
    int count=1;
    int temp[2] = {0,0};
    temp[0]=event[i][0];
    temp[1]=event[i][1];
    
    for(int j=0;j<num;j++){
      if(temp[0] < event[j][0] && event[j][0] < temp[1] && i!=j){
        temp[0] = event[j][0];
        add=true;
      }
      if(temp[1] > event[j][1] && event[j][1] > temp[0] && i!=j){
        temp[1] = event[j][1];
        add=true;
      }

      if(add==true){
        count++;
      }

      add=false;
    }

    if(count > max){
      max = count;
    }
  }

  cout << "Max events: ";
  cout << max << "\n";

  return 0;
}

