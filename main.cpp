#include "main.h"

using namespace std;

int main() {

  unordered_map<string, int32_t> wordCount;

  cout << "Starting processing" << endl;

  mapFileToWords(wordCount, "greatexpectations.txt");

  // Convert from map to vector to enable sort
  vector<pair<string, uint32_t>> wordCountEnumerable;
  for(auto const pair : wordCount) {
    wordCountEnumerable.push_back(pair);
  }

  auto t_start = std::chrono::high_resolution_clock::now();
  quickSort(wordCountEnumerable, 0, wordCountEnumerable.size() - 1);
  auto t_end = std::chrono::high_resolution_clock::now();
  cout << std::chrono::duration<double, std::milli>(t_end-t_start).count() << endl;

  /*
  t_start = std::chrono::high_resolution_clock::now();
  sort(wordCountEnumerable.begin(), wordCountEnumerable.end(), [](auto const &a, auto const &b){
      return a.second < b.second;
  });
  t_end = std::chrono::high_resolution_clock::now();
  cout << std::chrono::duration<double, std::milli>(t_end-t_start).count() << endl;
*/

  for(auto const pair : wordCountEnumerable) {
      cout << pair.first << " - " << pair.second << endl;
  };

  return 0;

}

void mapFileToWords(unordered_map<string, int32_t>& wordCount, string fileName) {

  ifstream inputFile (fileName);

  std::string line;
  while (std::getline(inputFile, line)) {

    vector<string> words;

    boost::split(words, line, boost::is_space());

    for (auto word : words) {

      boost::algorithm::trim_all(word);
      boost::algorithm::to_lower(word);

      string result;

      // remove punctuation
      std::remove_copy_if(word.begin(), word.end(), std::back_inserter(result), std::ptr_fun<int, int>(&std::ispunct));

      if (result.size() > 0) {
        wordCount[result]++;
      }

    }
  }
}

int32_t partition(vector<pair<string, uint32_t>>& wordCount, int32_t low, int32_t high) {

  auto pivot = wordCount[high].second;
  auto index = low;

  for (auto j = low; j < high; j++) {

    if (wordCount[j].second < pivot) {

      auto swap = wordCount[index];
      wordCount[index] = wordCount[j];
      wordCount[j] = swap;

      index++;
    }

  }

  auto swap = wordCount[index];
  wordCount[index] = wordCount[high];
  wordCount[high] = swap;

  return index;

}

void quickSort(vector<pair<string, uint32_t>>& wordCount, int32_t low, int32_t high) {

  if (low < high) {

    auto pivotIndex = partition(wordCount, low, high);
    quickSort(wordCount, low, pivotIndex - 1);
    quickSort(wordCount, pivotIndex + 1, high);

  }

}