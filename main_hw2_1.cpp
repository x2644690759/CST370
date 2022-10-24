/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: Write a C++ (or Java) program for hw2_1 which checks if an input string is a palindrome or not.
 * ID:0621
 * Name: Zihao Xu
 * Date: 9/3/2022
 */

#include <iostream>
using namespace std;

int main() {
    bool result = true;
    string word;
    int count=0;
  
    cin >> word;

    char new_string[word.length()+1];

    for(int i=0;i<word.length();i++){
      char temp = word[i];

      if(temp > 47 && temp < 58){
        new_string[count] = temp;
        count++;
      }else if(temp > 64 && temp < 91){
        new_string[count] = tolower(temp);
        count++;
      }else if(temp > 96 && temp < 123){
        new_string[count] = temp;
        count++;
      }
    }

    int j=count-1;
    
    for(int i=0;i<count/2;i++){
      if(new_string[i] != new_string[j]){
        result=false;
        break;
      }

      j--;
    }

    if(result){
      cout << "TRUE";
    }else{
      cout << "FALSE";
    }

    cout << "\n\n";
}
