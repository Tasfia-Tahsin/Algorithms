/*********
https://toph.co/p/a-unique-array
*********/

#include<bits/stdc++.h>
#define fr(i,j,n)   for(int i=j;i<n;i++)
#define pb          push_back
#define rf(i,j,p)   for(int i=p-1;i>=j;i--)
#define vi          vector<int>
#define vll         vector<long long>
#define ll          long long
#define hmm         "\n"
#define sp          " "
#define srt(v)      sort(v.begin(), v.end());
#define ww           int tc ; cin >> tc ; while(tc--)
#define down        cout<<hmm;
#define faaast      ios_base::sync_with_stdio(0);cin.tie(nullptr);
#include <iostream>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


///*(st.find_by_order(i))
//  returns the element which is currently at index i
//  i : [0, n-1]
//  returns the data type of the set

///st.erase(val)
// return type void
// erases the element x
// all the values are distinct in the set

int main()
{
    int kk = 1;
    ww
    {
        int n,q; cin >> n >> q;
        int arr[n+5];
        ordered_set st;
        fr(i,0,n)cin >> arr[i], st.insert(i) ;

        cout<<"Case "<<kk++<<":"<<hmm;
        fr(j,0,q)
        {
            int idx , val, cnt=0,ans;
            cin >> idx >> val;
            if(j==0){
                arr[idx]=val;
                fr(i,1,n)
                {
                    if(arr[i]==arr[i-1]){
                            st.erase(i-1);
                    }
                }
                ans = st.size();
                cout<<ans<<hmm;
            }
            else{
                int x,y,z;
                n = st.size();
                if(n==1){
                    arr[0]=val;
                    cout<<1<<hmm;
                    continue;
                }
                if(idx==0){
                    y = arr[*(st.find_by_order(idx+1))];
                    if(y==val)st.erase(*(st.find_by_order(idx))), ans--;
                    else arr[*(st.find_by_order(idx))]=val;
                }
                else if(idx == n-1){
                    y = arr[*(st.find_by_order(idx-1))];
                    if(y==val)st.erase(*(st.find_by_order(idx))),ans--;
                    else arr[*(st.find_by_order(idx))]=val;
                }
                else{
                    x = arr[*(st.find_by_order(idx-1))];
                    z = arr[*(st.find_by_order(idx+1))];
                    if(x==val && z == val){
                        st.erase(*(st.find_by_order(idx-1)));
                        st.erase(*(st.find_by_order(idx)));
                        ans-=2;
                    }
                    else if (x==val || z == val)st.erase(*(st.find_by_order(idx))), ans--;
                    else arr[*(st.find_by_order(idx))]=val;
                }
                cout<<ans<<hmm;
            }
        }
    }
}
