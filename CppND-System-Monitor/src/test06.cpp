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

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
    string line;
    string file_path = "/proc/" + std::to_string(pid) + "/cmdline";
    std::ifstream filestream(file_path);
    if (std::getline(filestream, line)){
        return line;
    }
    return " ";
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
float LinuxParser::Ram(int pid) {
    string line;
    vector<string> split_str;
    float sum_rss = 0.0;
    string file_path = "/proc/" + std::to_string(pid) + "/smaps";
    std::ifstream filestream(file_path);

    if (filestream.is_open()) {
        while(std::getline(filestream, line)){
            line = del_space(line);
            split_str = split(line, ':');
            if (split_str[0] == "Rss"){
                sum_rss += std::stof( trim_rear(split_str[1], 2) );
            }
        }
        return sum_rss;
    }
    return 0.0; 
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
int LinuxParser::Uid(int pid) {
    vector<string> split_str;
    string line;
    string file_path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream filestream(file_path);
    int count = 0;
    if(filestream.is_open()){
        while(std::getline(filestream, line)){
         // split_str = split(line, ' ');
            char str_tab = '\t';
            split_str = split(line, str_tab);

            if(split_str.size() >= 2){
                if (split_str[0] == "Uid:"){                   
                    return std::stoi(split_str[1]);
                }
            }
        }
    }

    return 0;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) { return 0; }


int main(){
    int pid = 4919;
    // cout << "command = " << LinuxParser::Command(pid) << "\n";
    // cout << "ram     = " << LinuxParser::Ram(pid)<< "\n";
    // cout << "uid     = " << LinuxParser::Uid(pid)<< "\n";
    int out = LinuxParser::Uid(pid);
    // string line = "Uid:  1000    1000    1000    1000";
    // vector<string> split_str = split(line, ' ');
    // cout << "SIZE=" << split_str.size() << "\n";
    // for (int i=0; i < split_str.size(); i++){
    //     cout << split_str[i] <<"\n";
    // }

    cout << "out = " << out << "\n";
}
