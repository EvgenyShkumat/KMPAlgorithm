#include <iostream>
#include <vector>
using namespace std;

int KMP(string base, string s);

int main() {

	cout << KMP("fabcabceabdabcabcdfklabc", "abcd");

	return 0;
}

int KMP(string base, string s) {
	int* p = new int[s.length()];
	*p = 0;
	int i = 1, j = 0;

	for (; i < s.length();)
	{
		if (s[i] == s[j]) {
			*(p + i) = j + 1;
			j++;
			i++;
		} 
		else if (j == 0) {
			*(p + i) = 0;
			i++;
		}
		else {
			j = p[j - 1];	
		}
	}

	i = 0, j = 0;

	while(i < base.length()) {
		if (base[i] == s[j]) {
			i++;
			j++;	
		}
		if (j == s.length()) {
			cout << "j: " << j << " i: " << i << endl;
			return i - j;
		}
		else if (i < base.length() && s[j] != base[i]) {
			if (j != 0) {
				j = p[j - 1];
			}
			else {
				i++;
			}
		}
	}

	

	return -1;	
}