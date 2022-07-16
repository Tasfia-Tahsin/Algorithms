/***********https://vjudge.net/problem/Gym-369360B*************/

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
//#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll base = 29 ;
ll mod = 1e9+7 ;
ll inverseModPreCalc[ 1000006 ];
ll prefHash[ 1000006 ];
string s;

void generateHash()
{
    ll currPower = 1 ;
    ll strLen = s.size();
    fr(i,0,strLen)
    {
        ll ch = s[i]-'a'+1;
        ll tem = ( ch * currPower ) % mod ;
        if(i!=0) tem += prefHash[i-1];
        tem %= mod ;
        prefHash[i] = tem ;
        currPower *= base ;
        currPower %= mod ;
    }
}

ll modInverse(ll  val , ll Mod)
{
	ll result = 1;
	while(Mod)
	{
		if(Mod & 1) result = (result * val) % mod;
		Mod >>= 1;
		val = (val * val) % mod;
	}
	return result;
}

ll substrHash(int i , int j )
{
    if(i==0) return prefHash[j];
    return ( (prefHash[j] - prefHash[i-1] + mod ) * inverseModPreCalc[i] )% mod;
}

int getAns(int iniL , int iniR )
{
    if(iniR < iniL)return 0;
    if(iniR == iniL)return 1;

    for(int currL = iniL, currR = iniR ; currL <currR ; currL++ , currR--  ){

        if(substrHash(iniL , currL)==substrHash(currR, iniR) )
            return (ll)2+getAns(currL+1,currR-1);
    }

    return 1 ;
}
void getInverseModPreCalc()
{
    inverseModPreCalc[0]=1 ;
    ll currPower = 1 ;
    fr(i,1,1000006){
        currPower = (currPower * base) % mod;
		inverseModPreCalc[i] = modInverse(currPower , mod - 2);
    }
}
int main()
{
    faaast;
    getInverseModPreCalc();
    ww
    {
        cin >> s ;
        generateHash();
        cout<<getAns(0,s.size()-1)<<hmm;
    }
}

/*
ll suf[ 1000006 ];
void suffixHash()
{
    int n = s.size();
    suf[0]=prifixHash[n-1];
    suf[0] *= inverseModPreCalc[1];
 
    fr(i,0,n)
    {
        suf[i+1] = ( prifixHash[n-1] - prifixHash[i] + mod ) * inverseModPreCalc[i+1] ;
        suf[i+1] %= mod ;
    }
}
*/
