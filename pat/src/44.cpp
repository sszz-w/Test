#include <bits/stdc++.h>
using namespace std;
int maxl=0;
vector<int> path;
vector<vector<int>> ans;
int ct[1000];
bool cmp(int a,int b){
    return a<b;
}

void dfs(int s){
    auto it=path.rbegin();
    path.pop_back();

    int a=s/3,b=s/2;
    while(a<=b){
        if((a*2<=s-a)||((path.size()!=0)&&(a*2<=path[path.size()-1]))){
            a++;
            continue;
        };
        int i=a,j=s-a;
        path.push_back(i);
        path.push_back(j);

        sort(path.begin(),path.end(),cmp);

        ct[path.size()]++;

        if(maxl<path.size()){
            maxl=path.size();
            ans.clear();
            ans.push_back(path);
        }else if(maxl==path.size()){
            ans.push_back(path);
        }
        dfs(path[path.size()-1]);

        for(auto it=path.begin();it!=path.end();it++){
            if(*it==i){
                path.erase(it);
                break;
            }
        }
        a++;
    }
}
int main(){
    int s;
    cin>>s;
    path.push_back(s);
    dfs(s);
    cout<<ct[maxl]<<" "<<maxl<<endl;
}