/**
 * @file blackbox.cpp
 * Implements a 'blackbox' algorithm

 */

#include "blackbox.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool blackbox_exists(std::string infile, std::string pattern){
    fstream fin;
    fin.open(infile);

    vector<string> kmer_list;
    string line, kmer, temp;
  
    while (fin >> temp) {  
        // read an entire row and store it in a string variable 'line'
        getline(fin, line);
  
        // used for breaking words
        stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'kmer'
        unsigned row = 0;
        while (getline(s, kmer, ',')) {
            if(row == 1){
                // The actual text content is on column index 1
                kmer_list.push_back(kmer);
            }
            row++;            
        }
    }
    for(string kmer : kmer_list){
        if(kmer.find(pattern)){
            return true;
        }
    }
    return false;

}

bool blackbox_count(std::string infile, std::string pattern, unsigned count){
    return false;
}