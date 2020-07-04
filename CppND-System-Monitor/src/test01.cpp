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

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  string line;
  vector<string> split_str;
  float mem_total, mem_available, mem_used;
  float mem_utilization;

  // std::ifstream filestream(kMeminfoFilename); // open file
  std::ifstream filestream("/proc/meminfo"); // open file
  
  if (filestream.is_open()) {
    // if file open is ok, do while.
    while(std::getline(filestream, line)){
      int pos = line.find(":");

      if (pos != string::npos){
          // delete space from line
          line = del_space(line);

          // split line with ":"
          split_str = split(line, ':');

          // get key & value
          if (split_str.size() == 2){
            if (split_str[0]=="MemTotal"){
              mem_total = std::stof(trim_rear(split_str[1],2));
            }
            if (split_str[0]=="MemAvailable"){
              mem_available = std::stof(trim_rear(split_str[1],2));
              mem_used      = mem_total - mem_available;
              mem_utilization = (float)(mem_used/mem_available);
              // cout << "mem_available = " << mem_available << "\n";
              // cout << "mem_used = " << mem_used << "\n";
              // cout << "mem_utilization = " << mem_utilization << "\n";
              return mem_utilization;
            }
          }
      }
    }
  }
  return 0.0; 
}

int main(){
    float out = LinuxParser::MemoryUtilization();
    cout << "out = " << out << "\n";
    return 0;
}