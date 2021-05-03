/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream ifWordFileIsOpen(filename);
    string newString;
    if (ifWordFileIsOpen.is_open()) {
        while (getline(ifWordFileIsOpen, newString)) {
            string getSorted(newString);
            std::sort(getSorted.begin(), getSorted.end());
            dict[getSorted].push_back(newString);
        }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for (string word: words) {
        string getSorted(word);
        std::sort(getSorted.begin(), getSorted.end());
        dict[getSorted].push_back(word);
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string getSorted(word);
    std::sort(getSorted.begin(), getSorted.end());
    if (dict.count(getSorted) == 0) {
        return vector<string>();
    }
    return dict.at(getSorted);
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> everything;
    for (std::pair<string, vector<std::string>> valueKey : dict) {
        vector<string> angramWord = valueKey.second;
        if (angramWord.size() < 2) {
            continue;
        }
        everything.push_back(angramWord);
    }
    return everything;
}