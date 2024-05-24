#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Backtrack(const vector<int>& data, int m, int targetSum, int start, vector<int>& path, vector<vector<int>>& combinations){
    // Check for complete combination (Base case check)
    if (path.size() == m){
        int sum = 0;
        for(int num : path){
            sum += num;
        }
        // Validate if sum is our targetSum
        if(sum == targetSum){
            combinations.push_back(path);
        }
        return;
    }
    
    // Explore all possible combinations
    for(int i = start; i < data.size(); ++i){
        if(path.size() < m && targetSum - data[i] >= 0){
            path.push_back(data[i]);
            Backtrack(data, m, targetSum, i + 1, path, combinations);
            path.pop_back();
        } 
    }
}

vector<vector<int>> FindCombinationSum(const vector<int>& dataArray, int m, int targetSum){
    vector<vector<int>> combinations;
    vector<int> path;
    Backtrack(dataArray, m, targetSum, 0, path, combinations);

    return combinations;
}

void PrintCombinations(vector<vector<int>>& results){
    cout << "Combinations found: " << endl;

    if(results.size() == 0){
        cout << "None" << endl;
    } else {
        for(const auto& result : results){
            cout << "[ ";
            for(int num : result){
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }
}