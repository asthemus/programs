#include<iostream>
#include<vector>
using namespace std;

void getsubstrings(string input, string output, vector<string> &res){
	if(input.empty()){
		res.push_back(output);
		return;
	}
	getsubstrings(input.substr(1), output + input[0], res);
	getsubstrings(input.substr(1), output, res);
}

int main(){
	string input;
	string output = "";
	cin>>input;
	vector<string> res;
	getsubstrings(input, output, res);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	return 0;
}