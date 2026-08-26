class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if not s[l].isalnum():
                while l < r and not s[l].isalnum():
                    l += 1

            if not s[r].isalnum():
                while l < r and not s[r].isalnum():
                    r -= 1

            if s[l].lower() != s[r].lower():
                return False
            l, r = l + 1, r - 1

        return True