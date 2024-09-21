#include <bits/stdc++.h>

using namespace std;


char tmp[205];
int cnt=0;
map<char,char>mp;

int main(){
	mp[')']='(';
	mp['}']='{';
	mp[']']='[';
	mp['>']='<';
	vector<char>vec;
	string s,res;
	while(1){
		getline(cin,s);
		if(s==".")break;
		res=res+s;
	}
	int len=res.size();
	for(int i=0;i<len;i++){
		if(res[i]=='('||res[i]=='['||res[i]=='{'||res[i]==')'||res[i]==']'||res[i]=='}')vec.emplace_back(res[i]);
		else if(res[i]=='/'&&res[i+1]=='*')vec.emplace_back('<'),i++;
		else if(res[i]=='*'&&res[i+1]=='/')vec.emplace_back('>'),i++;
	}
	stack<char>stk;
	for(auto c:vec){
		if(c=='('||c=='['||c=='{'||c=='<')stk.push(c);
		else{
                if(!stk.empty()){//非空  输出左
                    if(stk.top()==mp[c]){//匹配
                    	stk.pop();
                    }
                    else{
                    	cout<<"NO"<<endl;
                    	if(stk.top()!='<'){
                    		cout<<stk.top()<<"-?"<<endl;
                    	}
                    	else{
                    		cout<<"/*-?"<<endl;
                    	}
                    	return 0;
                    }
                }
            else {//空   输出右
            	cout<<"NO"<<endl;
            	if(c=='>'){
                    cout<<"?-*/"<<endl;
            	}
            	else{
            		cout<<"?-"<<c<<endl;
            	}
            	return 0;
            }
        }
    }
    if(stk.empty())cout<<"YES"<<endl;
    else{// 未匹配
    	cout<<"NO"<<endl;
    	if(stk.top()=='<')cout<<"/*-?"<<endl;
    	else cout<<stk.top()<<"-?"<<endl;
    }
}