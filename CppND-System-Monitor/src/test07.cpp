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


// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  return LinuxParser::UpTime() * sysconf(_SC_CLK_TCK); 
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {
    vector<string> split_str;
    string line;
    string file_path = "/proc/" + std::to_string(pid) + "/stat";
    long utime, stime, cutime, cstime, active_jiffies;
    std::ifstream filestream(file_path);

    if (filestream.is_open()){
        while(std::getline(filestream, line)){
            split_str = split(line, ' ');

            if (split_str.size() >= 17 ){
                utime  = std::stol(split_str[13]);
                stime  = std::stol(split_str[14]);
                cutime = std::stol(split_str[15]);
                cstime = std::stol(split_str[16]);
                active_jiffies = utime + stime + cutime + cstime;

                return active_jiffies;
            }
        }
    }

    return 0; 
}

vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime(){ 
  string line, uptime, idletime;
  long output;
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
        output   = (long)std::stoi(uptime);
        return output;
      }
    }
  }
  
  return 0; 
}

int main(){
    vector<int> PIDs = LinuxParser::Pids();
    for (int pid : PIDs){
        float active = (float)LinuxParser::ActiveJiffies(pid);
        float total  = (float)LinuxParser::Jiffies();
        cout << "[active, total, %] = [" << active << ", " << total << ", " << active/total << "\n";
    }
}
*/