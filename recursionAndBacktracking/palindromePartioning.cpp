#include<iostream>
#include<vector>

using namespace std;
void printVector(vector<vector<string>> &v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout<< v[i][j] << " ";		
		}
	cout<< endl;
	}
cout << endl;
}

bool checkPalindrome(string str, int left, int right){
	if(str.length() == 1) return true;
	while(left < right){
	if(str[left] != str[right]) return false;
	left ++, right --;
	}
	return true;
}

void solve(vector<vector<string>> &ans, string &s, vector<string> &curr, int start){
	// base case
	if(start == s.length()){
		ans.push_back(curr);
		return;
	}
	for(int end=start; end < s.length(); end++){
		if(checkPalindrome(s, start, end)){
			// choose
			curr.push_back(s.substr(start, end-start + 1));
			solve(ans, s, curr, end+1);
			curr.pop_back();
		}

	}

}

vector<vector<string>> partition(string s){
	vector<vector<string>> ans; 
	vector<string> curr;
	solve(ans, s, curr, 0);
	return ans;
}

int main(){
	string s = "aab";
	vector<vector<string>> res = partition(s);
	printVector(res);
    return 0;
}
