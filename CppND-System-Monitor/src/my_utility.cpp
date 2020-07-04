#include "my_utility.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using std::cout;
using std::string;
using std::vector;
using std::stringstream;

//-------------------------------------------
// Split Strings by delimiter
vector<string> split(const string &s, char delimiter)
{
    vector<string> elements;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delimiter))
    {
        if (!item.empty())
        {
            elements.push_back(item);
        }
    }
    return elements;
}

//-------------------------------------------
string del_space(string input){
  int pos = 1;

  while(pos != string::npos){
    pos = input.find(" ");

    if (pos != string::npos){
        input = input.erase(pos,1);
        }
    else{
        break;
    }
  }
  //
  return input;
}
//-------------------------------------------
string trim_rear(string str, int trim_num){
  int pos_trim_rear = str.size() - trim_num;

  if (pos_trim_rear > 0){
    return str.erase( pos_trim_rear );
  }
  else{
    return str;
  }
}