// C++ Program to implement the
// above approach
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Function to print all the
// numbers up to n in
// lexicographical order
void lexNumbers(int n)
{
	vector<string> s;

	for (int i = 1; i <= n; i++) {
		s.push_back(to_string(i));
	}

	sort(s.begin(), s.end());
	vector<int> ans;
	for (int i = 0; i < n; i++)
		ans.push_back(stoi(s[i]));

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}
// Driver Program
int main()
{

	int n = 11;
	lexNumbers(n);
	return 0;
}
