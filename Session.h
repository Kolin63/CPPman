#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <iostream>
#include <bitset>
#include "WordList.h"

class Session
{
private:
    std::string word{};
    std::bitset<26> lettersGuessed{};
    std::string wrongGuesses{};
    int pluses{};

    std::string underscorify(std::string f_word) const;

public:
    Session(int f_pluses)
        : word{ WordList::getRandomWord() }
        , pluses{ f_pluses }
    {

    }

    char display();

    char getLetter();

    std::string getWord() { return word; }
};

#endif