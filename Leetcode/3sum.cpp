#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> output;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
	if (i != 0 && nums[i] == nums[i - 1]) continue;
	unordered_set<int> seen;
	for (int j = i + 1; j < nums.size(); ++j) {
	  if (seen.count(-nums[i] - nums[j])) {
		output.push_back({nums[i], nums[j], -nums[i] - nums[j]});
		// Skip duplicates
		while (j + 1 < nums.size() && nums[j+1] == nums[j]) ++j;
	  }
	  seen.insert(nums[j]);
	}
	}
	return output;
	//sort(A.begin(), A.end());
	
	//int n = A.size();
	//vector<vector<int>> ans;
	
	//for(int i = 0; i < n; i++) {
		//if(i != 0 && A[i] == A[i - 1]) continue;
		
		//unordered_set<int> un_map;
		
		//for(int j = i + 1; j < n; j++) {
			//if(j != 0 && A[j] == A[j - 1]) {
				//continue;
			//}
			//if(un_map.count(-A[i] - A[j])) {
				//ans.push_back({A[i], - A[i] - A[j], A[j]});
				//while(j + 1 < n && A[j+1] == A[j]) j++;
			//}
			
			//un_map.insert(A[j]);
		//}
	//}
	
	//return ans;
}

int main(int argc, const char* argv[]) {
	vector<int> A = { 0, 0, 0};
	vector<vector<int>> ans = threeSum(A);
	
	for(int i = 0; i < (int)ans.size(); i++) {
		for(int j = 0; j < (int)ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		
		cout << endl;
	}
	
	return 0;
}
