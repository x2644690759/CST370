/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: Write a C++ (or Java) program for hw4_1 which checks if two strings are anagram or not. In the problem, an anagram is a word formed by rearranging the letters of a different word. 
 * ID: 0621
 * Name: Zihao Xu
 * Date: 9/22/2022
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
	string first;
  string second;
  bool anagram = false;

  cin >>first;
  cin >>second;

  map<char, int>first_map;
  map<char, int>second_map;

  for(int i=0;i<first.length();i++){
    bool found=false;
    
    for(auto it=first_map.begin();it != first_map.end();it++){
      if(it->first == first.at(i)){
        it->second++;
        found = true;
      }
    }

    if(!found){
      first_map.insert(pair<char,int>(first.at(i),1));
    }
  }

  for(int i=0;i<second.length();i++){
    bool found=false;
    
    for(auto it=second_map.begin();it != second_map.end();it++){
      if(it->first == second.at(i)){
        it->second++;
        found = true;
      }
    }

    if(!found){
      second_map.insert(pair<char,int>(second.at(i),1));
    }
  }

  if(first_map == second_map){
    cout << "ANAGRAM" << endl;

    for(auto it=first_map.begin();it != first_map.end();it++){
      cout << it->first << ":" << it->second << endl;
    }
  }else{
    cout << "NO ANAGRAM" << endl;
  }

	return 0;
}
