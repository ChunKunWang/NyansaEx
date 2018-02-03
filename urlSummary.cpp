#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <ctime>
#include <map>
#include <vector>
#include <cstdlib>
#include <iterator>
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
  map<long, map<string, int>> dateUrlMap;

  // open input file
  if (inFile.is_open()) {
    string line;

    // parse input data into map table
    while (getline(inFile, line)) {
      dataEntry entry;
      entry.parseLine(line);
      dateUrlMap[stol(entry.getDate())][entry.getUrl()]++; 
    }
    inFile.close();
  }
  else cout << "Open file fail!" << endl;

  // report url summary
  for (auto entry : dateUrlMap) {
    string Date = to_string(entry.first);
    cout << Date.substr(4, 2) << "/" 
         << Date.substr(6, 2) << "/" 
         << Date.substr(0, 4) << " GMT" << endl;

    // sort the urls by hit count
    vector<pair<string, int>> v;
    for (auto url : entry.second) 
      v.push_back(make_pair(url.first, url.second));

    sort(v.begin(), v.end(), [](auto p1, auto p2){return p1.second > p2.second;});

    for (auto p : v)
      cout << p.first << " " << p.second << endl;
  }

  return 0;
}

