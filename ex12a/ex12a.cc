// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// This program reads a text file whose filename is given as a single
// command-line argument, and then read and count the individual words
// in the file, and, after reading the entire file,
// it prints a sorted list of the words and
// the number of times each word appears in the file.
// Each word will  be written on a separate output line with the word first
// followed by a single space and their number of occurrences.

// for std::cin std::cout std::string
// and std::map etc.
#include <iostream>
// for EXIT_FAILURE and EXIT_SUCCESS
#include <cstdlib>
// for uint64_t type
#include <cinttypes>
 // for map
#include <map>
// for ifstream
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        // should input only one filename argument
        // print out error message
        cerr << "Please enter a valid txt file name" << endl;
        // exit the program
        return EXIT_FAILURE;
    }
    // for storing words read from the file and
    // associated times that word appears in the file
    map<string, uint64_t> data;
    // for openning the file
    ifstream file;
    file.open(argv[1]);
    // for storing each word
    string word;
    // get each word and
    // add to map along with its count
    while (file >> word) {
        // check if the map already contains the word as key
        if (data.count(word) == 0) {
            data[word] = 0;
        }
        // update the count
        data[word] = data[word] + 1;
    }
    // iterate through each key/value pair and
    // print out the result
    for (const auto& kv : data) {
        cout << kv.first << " " << kv.second << endl;
    }

    return EXIT_SUCCESS;
}
