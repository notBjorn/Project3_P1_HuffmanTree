> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/Project3_P1_HuffmanTree)


## **Collaboration & Sources**
Most of the code and logic used in this project is mine. Some external sources were used learn some things like how to look at the next character in an input stream but the logic itself is mine. I only used ChatGPT to try and debug my code when i was getting the curly apostrophe issue and wasn't aware of it. Through that I learned about static casting chars to be unsigned.

The code for the overloaded tokenize used the logic from `utils.cpp` which was provided by professor in the project file.

I did keep the inline suggestions on for this project mainly due to the quality of life changes it brings. It did suggest me to use static cast and to use `std::move` instead of copy in my constructer.

I did have some discussions with classmates regarding the project but the discussion was mostly centered around the curly apostrophe problem and what was required to be done in this project as I was a bit overwhelmed in the beginning. **No code was shared**

## **Implementation Details**
### `main`
Not a lot was changed in main as besides a prompt that stated if the code had begun running and if had ended. Another change was made to the file being used to create the scanner. The input file was the output file and I swapped that.
Changed the second call to be the overloaded `tokenize` function instead of the `utils - writeVectorToFile` function.

`Scanner Construter`
Initially i used just`{cpp}inputPath_ = inputPath` and it worked but i was informed by clion that it would be better to use `std::move` instead.

## **Testing & Status**
**The program, to the best of my knowledge, is working perfectly**.
