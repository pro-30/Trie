#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int cnt=0;
struct trie{
	bool isend;
	unordered_map<char,trie*> mp;
   
	trie()
	{
		isend=false;
	}

};


struct trie* root;



void insert(string str)
{
	struct trie* cur=root;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))cur->mp[ch]=new trie;
		cur=cur->mp[ch];
	}
	cur->isend=true;
	cnt++;
}

bool search(string str)
{
	struct trie* cur=root;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			return false;
		cur=cur->mp[ch];
	}
	return cur->isend;
}

void removeWord(trie* parent, string word){
	 if(word.length()==0){
	 	if(parent->isend){
	 		parent->isend=false;
	    cnt--;
	 	}
	 	
	 	return;
	 }
	 char ch=word[0];
	 string res= word.substr(1);
	 trie* child= parent->mp[ch];
	 if(child==NULL){
	 	return;
	 }
	 else{
	 	removeWord(child,res);
	 }
	 if(child->isend==false and  child->mp.size()==0){
	 	parent->mp.erase(ch);
	 }
}
void remove(string word){
	   removeWord(root,word);	   
}
int main()
{

	root=new trie;
      string s;
      cin>>s;
      
     insert(s);
     if(search(s))cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
     cout<<"number of words  in trie "<<cnt<<endl;
     remove(s);
     if(search(s))cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
     cout<<"number of words  in trie "<<cnt<<endl;
     
}