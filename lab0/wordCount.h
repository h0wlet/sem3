#pragma once
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>

class wordCount {
    int count;
    std::map <std::string, int> wordMap;

public:
    wordCount();
    void readAndCount(std::string inputFile);
    void sortAndWrite(std::string OutputFile);

private:
    void writeToCSV(std::list<std::pair<std::string, int>> wordList, std::string outputFile);
};
