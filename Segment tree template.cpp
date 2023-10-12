#include <iostream>
#include <bits/stdc++.h>
#define ll long long int


using namespace std;
class SGTree{
    
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
void build(int idx, int low, int high, int arr[]){
    
    if(low == high){
        seg[idx] = arr[low];
        return;
    }
    
    int mid = (low+high)/2;
    build(2*idx+1,low,mid,arr,seg);
    build(2*idx+2,mid+1,high,arr,seg);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    
}

int query(int idx,int low, int high, int l, int r){
    //no overlap
    // l r low high or low high l return
    if(r < low || high < l) return INT_MAX;
    
    //complete overlap
    // [l low high r]
    if(low>= l && high <= r) return seg[idx];
    
    int mid = (low+high)>>1;
    int left = query(2*idx+1,low,mid,l,r,seg);
    int right = query(2*idx+2,mid+1,high,l,r,seg);
    return min(left , right);
    }
    
    void update(int idx,int low,int high, int i,int val,int seg[]){
        if(low==high){
            seg[idx]= val;
            return;
        }
        int mid = (low+high)>>1;
        if(i<=mid) update(2*idx+1,low,mid,i,val,seg);
        else update(2*idx+2,mid+1,high,i,val,seg);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
    
    void solve(){
        int n1;
        cin>>n1;
        int arr1[n1];
        for(int i=0;i<n1;i++){
            cin>>arr[i];
        }
        SGTree sg1(n1);
        sg1.build(0,0,n1-1,arr1);
       int n2;
       cin>>n2;
       int arr2[n2];
       for(int i=0;i<n2;i++){
           cin>>arr[n2];
       }
       SGTree sg2(n2);
       sg2.build(0,0,n2-1,arr2);
       
        int q;
        cin>>q;
        while(q--){
            int type;
            cin>>type; 
            if(type == 1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = sg1.query(0,0,n1-1,l1,r1);
            int min2 = sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<endl;
            }
            else{
                int arrNo,i,val;
                cin>>arrNo>>i>>val;
                if(arrNo == 1){
                    sg1.update(0,0,n1-1,i,val);
                    arr1[i] = val;
                }
                else{
                    sg2.update(0,0,n2-1,i,val);
                    arr2[i] = val;
                }
            }
            }
        
        
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--){
       solve();

    }
    return 0;
}
