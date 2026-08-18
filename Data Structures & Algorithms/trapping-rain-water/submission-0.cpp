class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        int l = 1;
        int r = height.size() - 2;
        stack<int> lstack;
        stack<int> rstack;
        lstack.push(height[0]);
        rstack.push(height[r+1]);
        int lwater = 0, rwater = 0;
        int lcount = 0, rcount = 0;

        while (l <= r) {
            if (height[l] > lstack.top()) {
                lstack.push(height[l]);
                lcount = 0;
            }
            else {
                lwater += lstack.top() - height[l];
                lcount++;
            }
            if (height[r] > rstack.top()) {
                rstack.push(height[r]);
                rcount = 0;
            }
            else {
                rwater += rstack.top() - height[r];
                rcount++;
            }
            l++;
            r--;
        }

        int diff = lstack.top() - rstack.top();
        int final = 0;
        if (diff > 0) {
            lwater -= diff * lcount;
            final = rstack.top();
        } else {
            rwater += diff * rcount;
            final = lstack.top();
        }

        lwater = l == r? lwater - final : lwater;

        return lwater + rwater;
    }
};
