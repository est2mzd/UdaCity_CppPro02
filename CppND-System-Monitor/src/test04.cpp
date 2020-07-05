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
        return std::stod(uptime);
      }
    }
  }
  
  return 0; 
}



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

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
    vector<string> split_str;
    string line;
    long active_jiffies = 0;
    std::ifstream filestream("/proc/stat");

    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            split_str = split(line, ' ');
            if (split_str.size() == 11){

                if (split_str[0] == "cpu"){
                    for(int i=1; i<=10; i++ ){
                        if ( (i!=4) && (i!=5)){
                            active_jiffies += std::stol(split_str[i]);
                        }
                    }
                    return active_jiffies;
                }
            }
        }
    }
    return 0; 
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
    vector<string> split_str;
    string line;
    long active_jiffies = 0;
    std::ifstream filestream("/proc/stat");

    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            split_str = split(line, ' ');
            if (split_str.size() == 11){

                if (split_str[0] == "cpu"){
                    for(int i=1; i<=10; i++ ){
                        if ( (i==4) || (i==5)){
                            active_jiffies += std::stol(split_str[i]);
                        }
                    }
                    return active_jiffies;
                }
            }
        }
    }
    return 0; 
}


int main(){
    cout << "UpTime = " << LinuxParser::UpTime() << "\n";
    cout << "Jiffies = " << LinuxParser::Jiffies() << "\n";
    cout << "sysconf(_SC_CLK_TCK) = " << sysconf(_SC_CLK_TCK) << "\n";
    cout << "Active Jiffies pid = " << LinuxParser::ActiveJiffies(120)  << "\n";
    cout << "Active Jiffies sys = " << LinuxParser::ActiveJiffies()     << "\n";
    cout << "Idle   Jiffies sys = " << LinuxParser::IdleJiffies()     << "\n";
}
*/