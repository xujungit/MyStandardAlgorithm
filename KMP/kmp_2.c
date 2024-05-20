#include<iostream>
#include<vector>
using namespace std;

/*
	s: 子串;
	t: 模式串;
*/
bool kmp(string s, string t) {
	int n = s.size(), m = t.size(), i = 0, j = -1;
	vector<int> next(m, -1); //模式表

	for (int i = 1; i < m; ++i) {
		int j = next[i - 1];
		while (j != -1 && t[j + 1] != t[i]) {
			j = next[j];
		}

		if (s[j + 1] == s[i]) {
			next[i] = j + 1;
		}
	}

	i = -1, j = -1;
	while (i<n && j<m) {
		if (j == -1 || s[i] == t[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}

	if(j==m) return true;
	return false;
}


int main(){
	string s{ "ABCDABBACABCDABD" }, t{"ABCDABD"};

	cout << kmp(s, t) << endl;
	return 0;
}