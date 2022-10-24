/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_2.cpp
 * Abstract: Write a C++ (or Java) program for hw4_2 to solve the Knapsack problem.
 * ID: 0621
 * Name:Zihao Xu
 * Date: 9/22/2022
 */

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main()
{
  int num;
  int capacity;
  int items[num][2];
  int MAX = 0;
  int final_capacity = 0;
  int num_result = 1;
  set<int>result_set;

  cin >> num;
  cin >> capacity;
  
  for(int i=0;i<num;i++){
    cin >> items[i][0];
    cin >> items[i][1];
  }

  int all_sub = pow(2,num);
  int result[all_sub][2];

  for(int i=1;i<all_sub;i++){
    int binary[num];
    int temp=i;
    int pos=num-1;
    int temp_value = 0;
    int temp_capacity = 0;
    set<int>temp_set;

    while(temp>0){
      binary[pos] = temp%2;
      temp = temp/2;
      pos--;
    }

    for(int k=0;k<num;k++){
      
      if(binary[k] == 1){
        temp_capacity += items[k][0];

        if(temp_capacity <= capacity){
          temp_value += items[k][1];
          temp_set.insert(k+1);
        }
      }
    }

    if(temp_capacity > capacity){
      temp_value = -1;
    }

    if(temp_value == MAX){
      num_result++;
    }else if(temp_value > MAX){
      MAX = temp_value;
      final_capacity = temp_capacity;
      result_set = temp_set;

      num_result = 1;
    }
  }

  if(num_result == 1){
    cout << "Item:";
    int count = result_set.size();

    for(auto it=result_set.begin();it != result_set.end();it++){
      cout << *it;

      if(count != 1){
        cout << " ";

        count--;
      }
    }

    cout << "\nCapacity:" << final_capacity << endl;
    cout << "Value:" << MAX << endl;
  }else{
    cout << "Item:Multiple solutions" << endl;
    cout << "Capacity:" << final_capacity << endl;
    cout << "Value:" << MAX << endl;
  }

  return 0;
}

