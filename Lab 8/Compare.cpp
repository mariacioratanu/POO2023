#include "Compare.h"
#include <utility>
#include <string>

using std::pair;
using std::string;

//a comparison function that compares two pairs of strings and integers
bool Compare::operator()(const pair<string, int>& pairOne, const pair<string, int>& pairTwo)
{
    int i;
    if (pairOne.second != pairTwo.second) //checks if values of the two pairs are different
        return pairOne.second < pairTwo.second; //the pair with the smaller integer is considered "less than" the other pair
    //in the case of a tie, it compares the two strings character by character
    for(i=0; i<pairOne.first.size() && pairTwo.first.size(); i++)
    {
        if(pairOne.first[i]>pairTwo.first[i])
            return true; //the character in the first string is greater than the character in the second string
        else if (pairOne.first[i]<pairTwo.first[i])
            return false;
    }
    //returns whether the first parameter is "less than" the second parameter according to the sorting criteria
    return pairOne.first.size() > pairTwo.first.size();
}
