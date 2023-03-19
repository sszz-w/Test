#include <bits/stdc++.h>
using namespace std;

vector<int> line;

int main(){
    int n,k;
    cin>>n>>k;
    line.resize(n);
    for(int i=0;i<n;i++) cin>>line[i];

    for(int i=0;i<k;i++){
        vector<int> check(n);
        for(int j=0;j<n;j++) cin>>check[j];
        deque<int> st;
        int j=0,k=0;
        while(j<n&&k<n){
            if(!st.empty()){
                if(st.back()==check[j]){
                    st.pop_back();
                    j++;
                }else if(st.front()==check[j]){
                    st.pop_front();
                    j++;
                }
            }
            if(check[j]==line[k]){
                j++;k++;
            }
            else{
                st.push_back(line[k++]);
            }
        }

        bool flag=true;
        while(j<n){
            if(st.front()==check[j]){
                st.pop_front();
                j++;
            }else if(st.back()==check[j]){
                st.pop_back();
                j++;
            }else{
                flag=false;
                break;
            }
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}