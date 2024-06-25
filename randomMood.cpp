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

struct Matrix
{
    double matrix[2][2] = {{0, 0}, {0, 0}};

    Matrix operator* (Matrix other)
    {
        Matrix res;
        FOR(i, 0, 2) 
        {
            FOR(j, 0, 2)
            {
                FOR(k, 0, 2)
                    res.matrix[i][k] += matrix[i][j] * other.matrix[j][k]; 
            }
        }

        return res;
    }
};

Matrix expo(Matrix base, int e)
{
    Matrix res;
    FOR(i, 0, 2) res.matrix[i][i] = 1;

    while (e)
    {
        if (e & 1) res = res * base;
        base = base * base;
        e /= 2;
    }

    return res;
}

int main()
{
    int n;
    double p;
    cin >> n >> p;

    Matrix prob;
    prob.matrix[0][0] = 1 - p;
    prob.matrix[0][1] = p;
    prob.matrix[1][0] = p;
    prob.matrix[1][1] = 1 - p;

    Matrix ans = expo(prob, n);

    cout << fixed << setprecision(10) << ans.matrix[0][0] << '\n';

    return 0;
}