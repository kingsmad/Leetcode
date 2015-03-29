class Solution {
	bool isScramble(string s1, string s2) {
	if(s1.size() != s2.size())
		return false;
	int len = s1.size();
	char ht[26];
	memset(ht, 0, sizeof(char)*26);
	
	for(int i=0; i<len; ++i) {
	ht[s1[i]-’a’] += 1;
}

for(int i=0; i<len; ++i) {
	if(--ht[s2[i]-’a’] < 0)
		return false;
}

return true;
}
	
};