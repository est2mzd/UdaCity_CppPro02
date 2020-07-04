#ifndef MY_UTILITY_H
#define MY_UTILITY_H

#include <string>
#include <vector>
using std::string;
using std::vector;

vector<string> split(const string&, char);
string del_space(string);
string trim_rear(string, int);

#endif// MY_UTILITY_H