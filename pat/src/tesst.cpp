#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={1,2,3};
    auto it=a.begin();
    a.erase(it);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}