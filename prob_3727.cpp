class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        vector<long long> squares;

        for (int x : nums)
        {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;
        int n = squares.size();

        for (int i = 0; i < n / 2; i++)
        {
            ans += squares[n - 1 - i] - squares[i];
        }

        if (n % 2 != 0)
        {
            ans += squares[n / 2];
        }

        return ans;
    }
};
