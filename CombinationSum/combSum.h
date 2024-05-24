#ifndef COMBSUM_H
#define COMBSUM_H
#include <vector>

using namespace std;

void Backtrack(const vector<int>& data, int m, int targetSum, int start, vector<int>& path, vector<vector<int>>& combinations);
vector<vector<int>> FindCombinationSum(const vector<int>& dataArray, int m, int targetSum);
void PrintCombinations(vector<vector<int>>& results);

#endif