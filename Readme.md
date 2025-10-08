---
date made: 2025-10-07
time made: 18:27
year: 2025
tags:  
- CS315
- Fall2025
description: "Readme file for part 1 of project 3 for cs315 class"

## Categorizations.
isWork: true
isLearn: true
isCoursework: true
---

> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/Project3_P1_HuffmanTree)


## **Collaboration & Sources**
Most of the code and logic used in this project is mine. Some external sources were used learn some things like how to look at the next character in an input stream but the logic itself is mine. I only used ChatGPT to try and debug my code when i was getting the curly apostrophe issue and wasn't aware of it. Through that I learned about static casting chars to be unsigned.

The code for the overloaded tokenize used the logic from `utils.cpp` which was provided by professor in the project file.

I did keep the inline suggestions on for this project mainly due to the quality of life changes it brings. It did suggest me to use static cast and to use `std::move` instead of copy in my constructer.

I did have some discussions with classmates regarding the project but the discussion was mostly centered around the curly apostrophe problem and what was required to be done in this project as I was a bit overwhelmed in the beginning. **No code was shared**

## **Implementation Details**
### `main`
Not a lot was changed in `main` as besides a prompt that stated if the code had begun running and if had ended. Another change was made to the file being used to create the scanner. The input file was the output file and I swapped that.
Changed the second call to be the overloaded `tokenize` function instead of the `utils - writeVectorToFile` function.

### `Scanner Construter`
Initially i used just`inputPath_ = inputPath` and it worked but i was informed by Clion that it would be better to use `std::move` instead.

### `tokenize(std::vector<std::string>& words)`
This function uses `readWord` to read the words from an input file and store the tokens returned by readWord into memory i.e. the vector of strings. The logic used is pretty simple. We continue reading until we reach the end of the file and store the returned tokens into the vector. Before doing so we check whether the file can be opened and if not then we return an appropriate error message. If everything goes through successfully `error_type` `NO_ERROR` is returned.

### `readWord(std::istream& in)`
`readWord` is a private helper function that finds a single token that starts with an alphabet and ends with one, it might also contain an apostrophe but only in the middle.

The logic for `readWord` was pretty straightforward. While we can get characters continue looping, if the character is an alphabet push it to the word after making it lowercase. If the character is an apostrophe and the word is not empty meaning we already have a valid character in word and if the character after the apostrophe is an alphabet push the character to the word. We only stop looping if none of these conditions are satisfied and the word is not empty meaning we have reached a delimiter/character that cannot be accepted into the token.

While the logic mentioned before was mine I did have to pass it through chatGPT a couple of times as I wasn't aware of the curly apostrophe and thought my logic was flawed. During that process I learned that I needed to `static cast` my character to be an `unsigned char` if I wanted to process them through `isLower` and `isAlpha`. some changes were weird and i did not understand them so i removed them from my final code like the `eof` logic. My code still worked.

### `tokenize(std::vector<std::string> &words, const std::filesystem::path &outputFile)`
This overloaded function tokenizes and then writes the tokens to an output file. For the tokenization part i used the previous tokenization function but I forgot that i had called it earlier and that gave me an error so I decided to tokenize only when `words` was an empty vector. The logic after this was basically the code copied over from `utils.hpp` and I understand what it does. we are clearing the file if it existed using the `std::turnc` and `std::out` means we are writing. after that we pass out tokens to out just like we would to `cout` but instead of displaying the tokens they are being written down in the provided file.

## **Testing & Status**
**The program, to the best of my knowledge, is working perfectly**. For testing I used the scripts provided by the professor. Initially when I wasn't aware of the scripts I did use the default files to check if my code was working. I would push the code from pc and ssh into linux to pull the code and run it through those scripts and everything worked perfectly by the end I did have some issues where I would get and extra blank space at the end but i figured it out.