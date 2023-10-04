#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

// Function to store a word from the user to check against a block of text.
std::string getWordFromUser()
{
    std::string chosenWord {};
    std::cin >>  chosenWord;

    return chosenWord;
}

// Function to get the block of text from the user.
std::string storeBlockOfText()
{
    std::string textBlock {};
    std::cin.ignore();
    std::getline(std::cin, textBlock);

    return textBlock;
}

// Function to count words in text.
std::unordered_map<std::string, int> countWordsInText(const std::string & text)
{
    std::unordered_map<std::string, int> wordCount;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word)
    {
        // Convert word to lowercase for case-insensitive comparison.
        for (char & c : word) c = std::tolower(c);
        wordCount[word]++;
    }
    return wordCount;
}

int main()
{
    std::cout << "Enter a word to check how many times it appears in a block of text" << '\n';

    std::string chosenWord = getWordFromUser();
    std::cout << "You entered: " <<  chosenWord << std::endl;

    std::cout << "Paste your block of text" << '\n';
    std::string textBlock = storeBlockOfText();

    std::cout << "You entered:\n\"" << textBlock << "\"\nIf this is correct,";

    std::unordered_map < std::string, int > wordCount = countWordsInText(textBlock);

    std::cout << "\"" << chosenWord << "\" appears " << wordCount[chosenWord] << " times" << std::endl;
    std::cout << "Here is a frequency list of all the words. \n";

      for (const auto & pair : wordCount)
    {

        std::cout << pair.first << ": " << pair.second << " times" << std::endl;
    }


    std::cin.get();
    // Wait for the user to press Enter before exiting

    return 0;
}
