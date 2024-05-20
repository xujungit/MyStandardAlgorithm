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

	while (i<m-1)
	{
		if (j == -1 || t[i] == t[j]) {
			++i;
			++j;
			next[i] = j;
			/*
			优化代码:
			*/
			// if (t[i] != t[j]) next[i] = j;
			// else next[i] = next[j];
		}
		else {
			j = next[j];
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