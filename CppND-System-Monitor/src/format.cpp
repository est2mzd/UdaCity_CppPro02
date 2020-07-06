#include <string>
#include "format.h"
using std::string;
#include <iomanip>

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    std::stringstream ss;

    int h = seconds/3600;
    int m = (seconds - h*3600)/60;
    int s = seconds - h*3600 - m*60;
    ss << std::setw(2) << std::setfill('0') << h << ":";
    ss << std::setw(2) << std::setfill('0') << m << ":";
    ss << std::setw(2) << std::setfill('0') << s;

    return ss.str(); 
}