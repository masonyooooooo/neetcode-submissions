class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() < 2) {
            return false;
        }
        int i = 0;

        while (i < flowerbed.size() - 1) {
            if (flowerbed[i + 1] == 1) {
                // next pos is occupied
                i += 3;
            } else {
                if (flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
                i += 2;

            }
        }

        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2])
            n--;

        if (n <= 0)
            return true;

        return false;
    }
};