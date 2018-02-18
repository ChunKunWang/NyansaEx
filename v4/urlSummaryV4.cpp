#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class dataEntry
{
  public:
    dataEntry() 
    {
      date = "";
      url = "";
    }

    bool parseLine(const string line) 
    {
      size_t pos = line.find_first_of("|");
      date = getTimeStamp(stol(line.substr(0, pos)));
      url  = line.substr(pos+1);
    }

    string getTimeStamp(time_t epochTime, const char* format = "%Y%m%d")
    {
      char timestamp[64] = {0};
      strftime(timestamp, sizeof(timestamp), format, localtime(&epochTime));
      return timestamp;
    }

    string getDate() {return date;}
    string getUrl()  {return url;}

    ~dataEntry() {}

  private:
    string date;
    string url;
};

int main(int argc, char *argv[])
{
  string inFileName = "./input.txt";

  // parse command line
  if (argc == 1)
    cout << "Default file: " << inFileName << endl;
  else if (argc == 2) 
    inFileName = argv[1];
  else 
    return -1;

  ifstream inFile (inFileName.c_str());
  unordered_map<string, unordered_map<string, int>> dateUrlMap;

  // open input file
  if (inFile.is_open()) {
    string line;

    // parse input data into map table
    // All lines: O(N)
    while (getline(inFile, line)) {
      dataEntry entry;
      entry.parseLine(line);
      dateUrlMap[entry.getDate()][entry.getUrl()]++; // Insert: O(1)
    }
    inFile.close();
  }
  else cout << "Open file fail!" << endl;

  // report url summary
  // sort by dates: O(K*log K) where K is the number of days
  map<string, unordered_map<string, int>> ordered(dateUrlMap.begin(), dateUrlMap.end());

  // sort by the hit coun valuet
  for (auto entry: ordered) {
    string Date = entry.first;
    cout << Date.substr(4, 2) << "/"
      << Date.substr(6, 2) << "/"
      << Date.substr(0, 4) << " GMT" << endl;

    // Bucketsort: O(N)
    int num = 0;
    for (auto url : entry.second)
      num = max(num, url.second);
    if (num < 1) continue;

    vector<vector<string>> bucket(num + 1);
    for (auto url : entry.second)
      bucket[url.second].push_back(url.first); 
    
    for (int i = num; i > 0; i--) {
      if (bucket[i].empty()) continue;
      for (auto p : bucket[i])
        cout << p << " " << i << endl;
    }
  }

  return 0;
}

