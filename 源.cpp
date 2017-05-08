#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

struct word{
	string w;
	string suf;
};

struct suffix {
	string w;
	int num=1;
}

Bool find(vector<suffix>& suflist,string s) {
	for (vector<suffix>::iterator iter = suflist.begin(); iter != suflist.end(); ++iter)
	{
		if (&iter.w == s) { &iter.num++; return true; }
	}
	return false;
}

int main(){
	vector<word> wordlist;
	vector<suffix> suflist;
	ifstream in("C:\\Users\\Jay Zhou\\Documents\\Visual Studio 2015\\Projects\\EnglishWords.txt");
	int n=3;
	cin >> n;
	string buff;
	while (!in.eof())
	{
		getline(in, buff);
		string suf=buff.substr(buff.length() - n, buff.length());
		word w = {buff,suf};
		wordlist.push_back(w);
		suffix s = { suf,1 };
		if (!find(suflist, suf)) { suflist.push_back(s); }
	}

	return 0;
}
