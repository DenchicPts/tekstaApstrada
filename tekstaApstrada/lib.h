#pragma once

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

map<string, int> wordCounter(ifstream& file, string& punctuation);
bool hasRepeatingLetters(const string& word);