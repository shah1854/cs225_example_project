/**
 * @file main.cpp
 * A fake 'run-script' to get time estimates for implemented algorithms
 * For other approaches to time your code (for benchmarking) see:
 * https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

#include "blackbox.h"
/**
 * Main routine.
 * Reads in a specified dataset and outputs the time to do 'algorithm' on it
 */
int main()
{
    // This method of timing rounds to the nearest second
    // It doesnt have precision for very fast operations -- keep that in mind!
    time_t begin, end;
    begin = time(NULL);

    std::string infile = "../../data/smallset.csv";
    std::string search = "CACATCTA";
    bool out = blackbox_exists(infile, search);
    if (out){
        std::cout << "Match found " << std::endl;
    }
    else{
        std::cout << "Match not found " << std::endl;
    }
    

    end = time(NULL);
    std::cout << "Total time to run: " << double(end-begin) << std::endl;;
    return 0;
}
