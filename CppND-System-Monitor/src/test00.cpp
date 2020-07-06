/*
#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "../include/linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

#include "my_utility.h"
#include <iostream>
using std::cout;


// TODO: Read and return the system uptime
long LinuxParser::UpTime(){ 
  string line, uptime, idletime;
  vector<string> split_str;

  // std::ifstream filestream(kMeminfoFilename); // open file
  std::ifstream filestream("/proc/uptime"); // open file
  
  if (filestream.is_open()) {
    // if file open is ok, do while.
    while(std::getline(filestream, line)){
      split_str = split(line, ' ');

      // get key & value
      if (split_str.size() == 2){
        uptime   = split_str[0];
        idletime = split_str[1];
        return (long)std::stoi(uptime);
      }
    }
  }
  
  return 0; 
} 

#include <iomanip>

int main(){
    long out = LinuxParser::UpTime();
    cout << "out = " << out << "\n";

    std::stringstream ss;
    int total_s = 8133;
    int h = total_s/3600;
    int m = (total_s - h*3600)/60;
    int s = total_s - h*3600 - m*60;
    ss << std::setw(2) << std::setfill('0') << h << ":";
    ss << std::setw(2) << std::setfill('0') << m << ":";
    ss << std::setw(2) << std::setfill('0') << s;
    cout << h << ":" << m << ":" << s << "\n";
    cout << ss.str() << "\n";

    return 0;
}
*/