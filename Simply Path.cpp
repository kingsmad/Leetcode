class Solution {
public:
	string simplifyPath(string path) {
	string ans;
	vector<string> mstack;

	int i = 0;
	while(i < path.size()) {
	while(path[i] == ‘/’ && i < path.size())
		++i;
	if(i == path.size())
		break;
	int start = i;
	
int end = i + 1;
	while(end < path.size() && path[end] != ‘/’)
		++end;
string tmp = path.substr(start, end-start);
if(tmp == “..” ) {
	if(!mstack.empty())
		mstack.pop_back();
}
else if(tmp != “.”)
	mstack.push_back(tmp);

i = end;
}

if(mstack.empty()) {
	return “/”;
}

for(int i=0; i<mstack.size(); ++i) {
	ans += “/” + (mstack[i]);
}

return ans;
}
};