/*********
https://codeforces.com/contest/1698/problem/D
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
bool ask(int l , int r )
{
    cout<<"? "<<l<<sp<<r<<hmm;
    int milsena = 0 ;
    fr(i,l,r+1)
    {
        int t ; cin >> t;
        if(t>= l && t <= r){}
        else milsena++;
    }
    int len = r-l+1;
    if( len%2 == milsena%2 )return  false;
    return  true;
}
int main ()
{
    ww
    {
        int n ; cin >> n ;
        int l = 1, h = n , m;
        while(l<h)
        {
            m = (l+h)/2;
            if(ask(l,m)==true)h = m ;
            else l = m+1;
        }
        cout<<"! "<<l<<hmm;
    }
}
