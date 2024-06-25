/*

$$\      $$\                 $$\               $$\           
$$ | $\  $$ |                $$ |              $$ |          
$$ |$$$\ $$ | $$$$$$\  $$\ $$$$$$\   $$\   $$\ $$ | $$$$$$\  
$$ $$ $$\$$ |$$  __$$\ \__|\_$$  _|  $$ |  $$ |$$ | \____$$\ 
$$$$  _$$$$ |$$ /  $$ |$$\   $$ |    $$ |  $$ |$$ | $$$$$$$ |
$$$  / \$$$ |$$ |  $$ |$$ |  $$ |$$\ $$ |  $$ |$$ |$$  __$$ |
$$  /   \$$ |\$$$$$$  |$$ |  \$$$$  |\$$$$$$$ |$$ |\$$$$$$$ |
\__/     \__| \______/ $$ |   \____/  \____$$ |\__| \_______|
                 $$\   $$ |          $$\   $$ |              
                 \$$$$$$  |          \$$$$$$  |              
                  \______/            \______/               
*/


#include <bits/stdc++.h>
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define FOREQ(a, b, c) for(int a = b; a <= c; ++a)
#define mFOR(a, b, c) for(int a = b; a > c; --a)
#define mFOREQ(a, b, c) for(int a = b; a >= c; --a)
#define FOREACH(a, b) for (auto &a : b)
#define CIN(arr, c) FOR(i, 0, c) cin >> arr[i] 
#define CIN2D(arr, r, c) FOR(i, 0, r) FOR(j, 0, c) cin >> arr[i][j]
#define all(x) x.begin(), x.end()
#define pb push_back
#define MOD 1000000007
typedef long long ll;
using namespace std;

static const auto __optimize__ = []() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	return 0;
}();

ll expo(ll base, ll e) // recursively
{
    if (e == 0) return 1;
    if (e == 1) return base;

    ll tmp = expo(base, e / 2);
    ll res = (tmp * tmp) % MOD;
    if (e % 2) res = (res * base) % MOD;

    return res;
}

ll expo2(ll base, ll e)
{
    ll res = 1;

    while (e)
    {
        if (e & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        e /= 2;
    }

    return res;
}


int main()
{
    ll tes = expo(2, 31);
    ll tes2 = expo2(2, 31);
    
    cout << tes << '\n';
    cout << tes2 << '\n';

    return 0;
}