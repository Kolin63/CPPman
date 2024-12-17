#include <iostream>
#include "Session.h"
#include "WordList.h"

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n\n";

    Session s{ 6 };

    while (true)
    {
        if (s.display() != 'n')
            break;
        s.getLetter();
    }
    return 0;
}
