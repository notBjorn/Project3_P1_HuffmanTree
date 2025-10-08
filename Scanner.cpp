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
    std::ifstream inputFile(inputPath_);
    if (!inputFile.is_open()) {
        return UNABLE_TO_OPEN_FILE;
    }

    std::string token;
    while (true) {
        token = readWord(inputFile);
        if (token.empty()) break;
        words.push_back(token);
    }

    return NO_ERROR;
}



//Copied over from utils not sure what is there to change here
error_type Scanner::tokenize(std::vector<std::string> &words, const std::filesystem::path &outputFile) {
    std::ofstream out(outputFile, std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        return UNABLE_TO_OPEN_FILE_FOR_WRITING;
    }

    tokenize(words); //tokenize the data to memory

    for (const auto& item : words) {
        out << item << '\n';
        if (!out) {
            std::cerr << "Error: failed while writing to " << outputFile << "\n";
            return FAILED_TO_WRITE_FILE;
        }
    }

    return NO_ERROR;
}



std::string Scanner::readWord(std::istream& in) {
    std::string word;
    char c;

    while (in.get(c)) {

        if (std::isalpha(static_cast<unsigned char>(c))) {
            word.push_back(std::tolower(static_cast<unsigned char>(c)));
        }
        else if (c == '\''&& !word.empty()) {
            int nextChar = in.peek();
            if (nextChar != EOF && std::isalpha(static_cast<unsigned char>(nextChar))) {
                word.push_back(c);  // keep apostrophe
            } else {
                break;
            }
        }
        else if (!word.empty()) {
            break;
        }
    }
    return word;
}