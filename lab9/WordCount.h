#pragma once
#include <string>
using namespace std;

class WordCount {
    private:
        int count;
    public:
        string word;
        WordCount();
        WordCount(string wrd);
        void addCount();
        int getCount();
        void print();
        bool operator>(WordCount other);
        bool operator<(WordCount other);
        bool operator==(WordCount other);
        bool operator!=(WordCount other);
};

