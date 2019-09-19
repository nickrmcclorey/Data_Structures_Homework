#include <iostream>
#include <string>
#include "WordCount.h"
using namespace std;

WordCount::WordCount(){
    word = "";
    count = 0;
}

WordCount::WordCount(string wrd){
    word = wrd;
    count = 1;
}

void WordCount::addCount(){
    count += 1;
}

int WordCount::getCount(){
    return count;
}

void WordCount::print(){
    cout << word << " - " << count << endl;
}

bool WordCount::operator>(WordCount other) {
    return this->word > other.word;
}

bool WordCount::operator<(WordCount other) {
    return this->word < other.word;
}

bool WordCount::operator==(WordCount other) {
    return this->word == other.word;
}

bool WordCount::operator!=(WordCount other) {
    return this->word != other.word;
}