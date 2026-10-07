class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int l = 0, r = m;

        while (l <= r)
        {
            int x = (l + r) / 2;
            int y = (m + n + 1) / 2 - x;

            int a1 = (x == 0) ? INT_MIN : a[x - 1];
            int a2 = (x == m) ? INT_MAX : a[x];

            int b1 = (y == 0) ? INT_MIN : b[y - 1];
            int b2 = (y == n) ? INT_MAX : b[y];

            if (a1 <= b2 && b1 <= a2)
            {
                if ((m + n) % 2)
                    return max(a1, b1);

                return (max(a1, b1) + min(a2, b2)) / 2.0;
            }

            if (a1 > b2)
                r = x - 1;
            else
                l = x + 1;
        }

        return 0;
    }
};