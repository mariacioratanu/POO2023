//reads a text file, stores each word in a map and then prints the words and their frequency in decreasing order.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <vector>
#include "Compare.h" //defines the comparison function

#define FILE_NAME "text.txt" //the name of the input file that the code will read
#define DELIMITER  " ,!?.\n" //all the delimiters that are used to separate words in the text file
//(space, comma, question and exclamation mark, point)

//to use them without the std:: prefix:
using std::string;
using std::map;
using std::priority_queue;
using std::pair;
using std::vector;

inline void handle_error(const char* msg) //a function that handles errors
{
    perror(msg); //perror() function, used to print an error message
    exit(EXIT_FAILURE);
}

void toLowerCase(string& str) //modifies the string by converting all the uppercase characters in it to lowercase
{
    int i;
    for(i=0; i<str.size(); i++)
    {
        if (str[i]>='A' && str[i]<='Z') //check if character is uppercase
            str[i]=str[i]-'A'+'a'; //convert to lowercase using ASCII values
        //the lowercase character is assigned back to the original position in the string
    }
}

//a custom search function which searches for a delimiter character in a string starting from a given index
size_t custom_find(const string str, size_t index, bool reverse=false) //reverse=flag indicating whether the search should be done in reverse order
{
    for (index; index < str.size(); index++)
    {
        //checks if the current character at the current index is a delimiter character
        const char* result=strchr(DELIMITER, str[index]);
        if (!reverse && result!=nullptr || reverse && result==nullptr)
            return index; //if the delimiter character is found, the function returns the current index
    }
    return string::npos; //if the delimiter character is not found, the function returns a special value used to indicate that no match was found
}

int main()
{
    FILE* fp;
    if(nullptr==(fp=fopen(FILE_NAME, "r"))) //"r" specifies that the file is to be opened in read-only mode
        handle_error("Error opening the file."); //the file could not be opened
    string str; //holds the content of the file
    struct stat sb; //holds information about the file, such as its size
    stat(FILE_NAME, &sb); //populates sb with information about the file
    str.resize(sb.st_size); //resizes str to the size of the file

    if (-1 == fread(const_cast<char*>(str.text()), 1, sb.st_size, fp))
        handle_error("Error reading the file.");

    fclose(fp); //closes the file
    map<string, int> words; //holds the unique words and their frequency
    //start and end are declared to hold the start and end positions of each word
    size_t start=0;
    size_t end=custom_find(str, 0); //returns the position of the delimiter that separates the first word from the rest of the text
    while(end!=string::npos) //until no more words can be found
    {
        string sub=str.substr(start, end-start); //extracts the word from str
        toLowerCase(sub); //converts the word to lowercase
        words[sub]++; //increments its frequency in the words map
        start=custom_find(str, end+1, true); //finds the position of the next delimiter
        end=custom_find(str, start); //sets start and end to the new positions
    }

    priority_queue < pair<string, int>, vector<pair<string, int>>, Compare> priority; //holds the words in descending order of their frequency
    for(auto it = words.begin(); it != words.end(); it++)
    {
        //pushes each word and its frequency onto the priority queue
        priority.push(pair<string, int>{ it->first, it->second });
    }

    while (!priority.empty())
    {
        //prints the word and its frequency
        std::cout<<priority.top().first<<" => "<<priority.top().second<<"\n";
        priority.pop(); //removes the top element from the priority queue
    }
    return 0;
}
