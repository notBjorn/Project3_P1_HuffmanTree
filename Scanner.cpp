//
// Created by Ali Kooshesh on 9/27/25.
//

#include "Scanner.hpp"

#include <utility>
#include <iostream>
#include <fstream>

#include "utils.hpp"

Scanner::Scanner(std::filesystem::path inputPath) {
    inputPath_ = std::move(inputPath);// clion told me to use move instead of copy
}
error_type Scanner::tokenize(std::vector<std::string>& words) {
    std::ifstream inputFile(inputPath_);// input file from which i read
    if (!inputFile.is_open()) {
        return UNABLE_TO_OPEN_FILE;
    }

    std::string token;
    while (!inputFile.eof()) {
        token = readWord(inputFile);
        words.push_back(token);
    }

    return NO_ERROR;
}


std::string Scanner::readWord(std::istream& in) {
    std::string word;
    char c;
    while (in.get(c)) {
        // read while we have something to read
        if (std::isalpha(c))
            word.push_back(std::tolower(c)); //forgot to lower the char here
        else if (c == '\'' && !word.empty() && std::isalpha(in.peek())) {
            word.push_back(c);
        } else {
            if (!word.empty()) break; //there is something in the word that means we have reached the end
        }
    }
    return word;
}