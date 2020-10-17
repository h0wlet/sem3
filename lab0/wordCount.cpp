#include "wordCount.h"
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>

wordCount::wordCount() {
    }

bool digitOrLetter(char a) {
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) return true;
    else return false;
}

void wordCount::readAndCount(std::string inputFile) {
    std::ifstream fin;
    fin.open(inputFile, std::ios::in);
    if (!fin.is_open()) {
        throw std::invalid_argument("input file not found");
    }
    std::string array, newWord;
    bool beginningOfWord = true;
    while (getline(fin, array)) {
        for (int i = 0; i < array.size(); i++) {
            char variable = array[i];
            if (digitOrLetter(variable)) {
                newWord += variable;
                beginningOfWord = false;
            }
            else {
                if (beginningOfWord == false) {
                    wordMap[newWord]++;
                    newWord = "";
                }
                beginningOfWord = true;
            }
            if ((digitOrLetter(variable)) && (i == array.size() - 1)) {
                wordMap[newWord]++;
            }
        }
    }
    fin.close();
}

static bool compare(const std::pair<std::string, int>& arg1, const std::pair<std::string, int>& arg2) {
    return (arg1.second > arg2.second) ? true : false;
}

void wordCount::sortAndWrite(std::string outputFile) {
    std::list<std::pair<std::string, int>> wordList;
    std::map<std::string, int>::iterator it;
    count = 0;
    for (it = wordMap.begin(); it != wordMap.end(); it++) {
        std::pair<std::string, int> addToList;
        addToList.first = it->first;
        addToList.second = it->second;
        count += addToList.second;
        wordList.push_back(addToList);
    }
    wordList.sort(compare);
    writeToCSV(wordList, outputFile);
}

void wordCount::writeToCSV(std::list<std::pair<std::string, int>> wordList, std::string outputFile) {
    std::ofstream fout;
    fout.open(outputFile, std::ios::out);
    if (!fout.is_open()) {
        throw std::invalid_argument("output file not open");
    }
    std::list<std::pair<std::string, int>>::iterator it;
   for (it = wordList.begin(); it != wordList.end(); it++) {
        fout << it->first << "," << it->second << "," << (double)it->second / (double)count * 100  << std::endl;
        //fout << it->first << ";" << it->second << ";" << (double)it->second / (double)count * 100 << std::endl;
    }
    fout.close();
}
