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

// TODO: Read and return CPU utilization
float LinuxParser::CpuUtilization() { 
  string line;
  vector<string> split_str;
  float user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  float sum_idle, sum_non_idle, total;
  float cpu_util;

  std::ifstream filestream("/proc/stat");

  if (filestream.is_open()){
    while(std::getline(filestream, line)){
      split_str = split(line, ' ');
      if (split_str[0] == "cpu"){
        user   = std::stof(split_str[1]);
        nice   = std::stof(split_str[2]);
        system = std::stof(split_str[3]);
        idle   = std::stof(split_str[4]);
        iowait = std::stof(split_str[5]);
        irq    = std::stof(split_str[6]);
        softirq= std::stof(split_str[7]);
        steal  = std::stof(split_str[8]);
        guest  = std::stof(split_str[9]);
        guest_nice= std::stof(split_str[10]);
        //
        sum_idle = idle + iowait;
        sum_non_idle = user + nice + system + irq + softirq + steal;
        total = sum_idle + sum_non_idle;
        cpu_util = (total - sum_idle) / total;
        //cout << "cpu_utile = " << cpu_util << "\n";
        return cpu_util;
      }
    }
  }
  return 0.0; 
}

int main(){
    vector<string> out = LinuxParser::CpuUtilization();
    // cout << "out = " << out << "\n";
    return 0;
}
*/