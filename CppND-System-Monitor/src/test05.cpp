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

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
    vector<string> split_str;
    string line;
    std::ifstream filestream("/proc/stat");

    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            int pos = line.find("processes ");
            if (pos != string::npos){
                split_str = split(line, ' ');
                return std::stoi(split_str[1]);
            }
        }
    }
    return 0; 
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
    vector<string> split_str;
    string line;
    std::ifstream filestream("/proc/stat");

    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            int pos = line.find("procs_running ");
            if (pos != string::npos){
                split_str = split(line, ' ');
                return std::stoi(split_str[1]);
            }
        }
    }
    return 0; 
}


int main(){
    cout << "Total_Processes = " << LinuxParser::TotalProcesses() << "\n";
    // RunningProcesses
    cout << "RunningProcesses = " << LinuxParser::RunningProcesses() << "\n";
}