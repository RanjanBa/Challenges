// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<string> &,int,int);

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m;
		cin>>m;
		vector<string> arr;
		for(int i=0;i<n;i++){
			string S;
			cin>>S;
			arr.push_back(S);
		}
		cout<< Shape(arr,n,m)<<endl;
	}
}// } Driver Code Ends


//User function template for C++

int di[4] = {1,0,-1,0}, dj[4] = {0,1,0,-1};

int vis[50][50], n, m;
vector<string> arr;

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 'X' && vis[i][j] == 0;
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    
    for(int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        
        if(check(ni, nj)) {
            dfs(ni, nj);
        }
    }
}

// A : vector of given strings
int Shape(vector<string> &_arr,int _n,int _m) {
    memset(vis, 0, sizeof(vis));
    arr = _arr, n = _n, m = _m;
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'O' || vis[i][j]) continue;
            
            dfs(i, j);
            res++;
        }
    }
    
    return res;
}