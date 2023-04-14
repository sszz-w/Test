#include <bits/stdc++.h>
using namespace std;

class Solution1{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> hashtable;
        for(int i=0;i<nums.size();i++){
            auto it=hashtable.find(target-nums[i]);
            if(it!=hashtable.end()) return {it->second,i};
            hashtable[nums[i]]=i;
        }
        return {};
    }
};
class Solution4{
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k){
        int m=nums1.size();
        int n=nums2.size();
        int index1=0,index2=0;
        while(true){
            if(index1==m) return nums2[index2+k-1];
            if(index2==n) return nums1[index1+k-1];
            if(k==1) return min(nums1[index1],nums2[index2]);
            int newIndex1=min(index1+k/2-1,m-1);
            int newIndex2=min(index2+k/2-1,n-1);
            int pivot1=nums1[newIndex1];
            int pivot2=nums2[newIndex2];
            if(pivot1<=pivot2){
                k-=newIndex1-index1+1;
                index1=newIndex1+1;
            }else{
                k-=newIndex2-index2+1;
                index2=newIndex2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int totalLength=nums1.size()+nums2.size();
        if(totalLength%2) return getKthElement(nums1,nums2,(totalLength+1)/2);
        else return (getKthElement(nums1,nums2,totalLength/2)+ getKthElement(nums1,nums2,totalLength/2+1))/2.0;
    }
};
class Solution10{
public:
    bool isMatch(string s, string p){
        int m=s.size();
        int n=s.size();
        auto matches=[&](int i, int j){
            if(i==0) return false;
            if(p[j-1]=='.') return true;
            return s[i-1]==p[j-1];
        };
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    dp[i][j] |= dp[i][j-2];
                    if(matches(i,j-1)){
                        dp[i][j]|=dp[i-1][j];
                    }
                }else{
                    if(matches(i,j)){
                        dp[i][j]|=dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
class Solution11{
public:
    int maxArea(vector<int>& height){
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            int area=min(height[l],height[r])*(r-l);
            ans=max(ans,area);
            if(height[l]<height[r]) ++l;
            else r--;
        }
        return ans;
    }
};
class Solution13{
public:
    unordered_map<char,int> symbolValues={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
    };
    int romanToInt(string s){
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i<n-1&&symbolValues[s[i]]<symbolValues[s[i+1]]){
                ans-=symbolValues[s[i]];
            }else ans+=symbolValues[s[i]];
        }
        return ans;
    }
};
class Solution15{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int first=0;first<n;first++){
            if(first!=0&&nums[first]==nums[first-1]) continue;
            int third=n-1;
            int target=-nums[first];
            for(int second=first+1;second<n;second++){
                if(second!=first+1&&nums[second]==nums[second-1]) continue;
                while(second<third&&nums[second]+nums[third]>target) third--;
                if(second==third) break;
                if(nums[second]+nums[third]==target) ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
        return ans;
    }
};
class Solution16{
public:
    int threeSumClosest(vector<int>& nums,int target){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int best=1e7;
        auto update=[&](int cur){
            if(abs(cur-target)<abs(target-best)) best=cur;
        };
        for(int i=0;i<n;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return target;
                update(sum);
                if(sum>target){
                    k--;
                    while(j<k&&nums[k]==nums[k+1]) k--;
                }else{
                    j++;
                    while(j<k&&nums[j]==nums[j-1]) j++;
                }
            }
        }
        return best;
    }
};
class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int first=0;first<n;first++){
            if(first!=0&&nums[first]==nums[first-1]) continue;
            int tar1=target-nums[first];
            for(int second=first+1;second<n;second++){
                if(second!=first+1&&nums[second]==nums[second-1]) continue;
                int tar2=tar1-nums[second];
                int fourth=n-1;
                for(int third=second+1;third<n;third++){
                    if(third!=second+1&&nums[third]==nums[third-1]) continue;
                    while(third<fourth&&nums[third]+nums[fourth]>tar2) fourth--;
                    if(third==fourth) break;
                    if(nums[third]+nums[fourth]==tar2) ans.push_back({nums[first],nums[second],nums[third],nums[fourth]});
                }
            }
        }
        return ans;
    }
};
class Solution23{
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode():val(0),next(nullptr){}
        explicit ListNode(int x):val(x),next(nullptr){}
        ListNode(int x, ListNode *next):val(x),next(next){}
    };
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if(!a||!b) return a?a:b;
        ListNode head,*tail=&head,*aPtr=a,*bPtr=b;
        while(aPtr&&bPtr){
            if(aPtr->val<bPtr->val){
                tail->next=aPtr;
                aPtr=aPtr->next;
            }else{
                tail->next=bPtr;
                bPtr=bPtr->next;
            }
            tail=tail->next;
        }
        tail->next=aPtr?aPtr:bPtr;
        return head.next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l==r) return lists[l];
        if(l>r) return nullptr;
        int mid=(l+r)>>1;
        return mergeTwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        return merge(lists,0,lists.size()-1);
    }
};