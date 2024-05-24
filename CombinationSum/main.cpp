#include <iostream>
#include <fstream>
#include <vector>
#include "combSum.h"

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    
    // Open file to read
    ifstream file(argv[1]);
    if(!file){
        cerr << "Error opening file." << endl;
        return 1;
    }

    int n, m, s;

    // Read data from file
    file >> n >> m >> s;
    vector<int> dataVector(n);
    for(int i = 0; i < n; ++i){
        file >> dataVector[i];
    }
    file.close();

    // Show data
    cout << n << " " << m << " " << s << endl;
    for (int i = 0; i < n; ++i) {
        cout << dataVector[i] << " ";
    }
    cout << endl;

    // Begin calculations
    vector<vector<int>> results = FindCombinationSum(dataVector, m, s);

    // Print results
    PrintCombinations(results);

    return 0;
}