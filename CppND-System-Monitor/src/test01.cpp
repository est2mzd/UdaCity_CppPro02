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

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}




// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  string line, key, value;
  vector<string> split_str;

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
            key   = split_str[0];
            value = trim_rear(split_str[1],2);

            if (key=="MemTotal"){
              return std::stof(value);
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