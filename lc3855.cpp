class Solution {
public:
    using ll = long long;

    const ll MOD = 1e9 + 7;

    ll power(ll a, ll b) {
        ll ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int sumOfNumbers(int l, int r, int k) {
        ll n = r - l + 1;

        ll digitSum = (l + r) * n / 2;
        ll ways = power(n, k - 1);

        ll inv9 = power(9, MOD - 2);
        ll placeSum = (power(10, k) - 1 + MOD) % MOD;
        placeSum = placeSum * inv9 % MOD;

        return digitSum % MOD * ways % MOD * placeSum % MOD;
    }
};