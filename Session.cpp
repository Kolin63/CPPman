#include "Session.h"

std::string Session::underscorify(std::string f_word) const
{
    for (size_t i{}; i < f_word.size(); ++i)
    {
        if (lettersGuessed[f_word[i] - 97] == 1)
            continue;
        f_word[i] = '_';
    }
    return f_word;
}

char Session::display()
{
    std::cout << "The word: " << underscorify(word) << '\t';

    std::cout << "    Wrong guesses: ";
    for (int i{}; i < pluses; ++i)
    {
        std::cout << '+';
    }
    std::cout << wrongGuesses << '\n';

    if (word == underscorify(word))
    {
        std::cout << "Congratulations, You Win!\n";
        return 'w';
    }
    else if (pluses == 0)
    {
        std::cout << "You lose! The word was: " << word << '\n';
        return 'l';
    }

    return 'n';
}

char Session::getLetter()
{
    while (true)
    {
        std::cout << "Enter your next letter: ";

        char c{};
        std::cin >> c;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (c >= 65 && c <= 90)
            c += 32;

        if (lettersGuessed[c - 97] == 1)
        {
            std::cout << "You already guessed that. Try again.\n";
            continue;
        }

        if (c >= 97 && c <= 122)
        {
            lettersGuessed[c - 97] = 1;

            for (char i : word)
            {
                if (i == c)
                {
                    std::cout << "Yes, '" << c << "' is in the word!\n\n";
                    return c;
                }
            }
            
            std::cout << "No, '" << c << "' is not in the word!\n\n";
            wrongGuesses.append(1, c);
            --pluses;

            return c;
        }

        std::cout << "That wasn't a valid input. Try again.\n";
    }
}

