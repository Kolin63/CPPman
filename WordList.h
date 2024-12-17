#ifndef WORDLIST_H
#define WORDLIST_H

#include <vector>
#include <string>
#include <string_view>
#include "Random.h"

namespace WordList
{
   inline static std::vector<std::string_view> words{ "mystery", "broccoli" , "account", "almost", "spaghetti", 
       "opinion", "beautiful", "distance", "luggage", "highseas", "hackclub", "github", "higgledypiggledy" };

   inline static std::string_view getRandomWord() 
   {
       return words[Random::get<std::size_t>(0, words.size() - 1)];
   }
}

#endif