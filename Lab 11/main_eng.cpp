// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of
// {"a.jpg", "b.jpg"} no global(or statics!) variables allowed

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "CommandManager.h"
#include <algorithm>
#define PAGE_SIZE 4096
#include <stdexcept>

class AutoCloseFile {
    FILE* file;
  public:
    AutoCloseFile(FILE* file) : file(file) {
    }
    ~AutoCloseFile() {
        fclose(file);
    }
};

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) {
        printf("counted %d args\n", static_cast<int>(args.size()));
    };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) {
        if (args.size() == 0) {
            throw MyException("Invalid number of parameters");
        }
        ofstream ofs(args[0], std::ios_base::app);
        if(ofs.is_open() == false) {
            throw OpenFileException(args[0]);
        }
        for (int i=1;i<args.size();i++) {
            if (!(ofs << args[i] << " ")) {
                throw WriteFileException(args[0]);
            }
        }

    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [x = 0](vector<string> args) mutable {
        x++;
        printf("Functia times a fost apelata de %d ori.\n", x);
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [&number_of_errors](vector<string> args) {
        if (args.size() < 2) {
            throw MyException("Invalid number of parameters");
        }
        FILE *fileOne, *fileTwo;
        if (nullptr == (fileOne = fopen(args[0].c_str(), "rb"))) {
            throw OpenFileException(args[0]);
        }
        AutoCloseFile fileOneAuto = fileOne;
        if (nullptr == (fileTwo = fopen(args[1].c_str(), "wb"))) {
            throw OpenFileException(args[0]);
        }
        AutoCloseFile fileTwoAuto = fileTwo;
        char buffer[PAGE_SIZE];

        while (true) {
            size_t data_read  = fread(buffer, 1, PAGE_SIZE, fileOne);
            if (data_read == 0)
                break;
            if (ferror(fileOne)) {
                throw ReadFileException(args[0]);
            }
            size_t data_write = fwrite(buffer, 1, data_read, fileTwo);
            if (data_read != data_write) {
                throw WriteFileException(args[1]);
            }
        }
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards

    auto sort_size = [](vector<string> args) {
        std::sort(args.begin(), args.end(), [](string strOne, string strTwo) { return strOne.size() < strTwo.size(); });
        std::for_each(args.begin(), args.end(), [](string str) { std::cout << str << " "; });
        std::cout << "\n";
    };
    manager.add("sort_size", sort_size);


    //create a new command that if called with certain parameters will allocate a huge amount (or negative)
    //of memory, in order for the allocator to throw std::bad_alloc
    auto allocate_mem = [](vector<string> args) {
        int size = -1;
        int* x = new int[size];
    };
    manager.add("allocate_mem", allocate_mem);

    // add one more command of anything you'd like

    manager.run();
}
