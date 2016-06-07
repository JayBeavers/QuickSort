#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#include <list>
#include <array>
#include <functional>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim_all.hpp>

using namespace std;

void mapFileToWords(unordered_map<string, int32_t>& wordCount, string fileName);

void quickSort(vector<pair<string, uint32_t>>& wordCount, int32_t low, int32_t high);