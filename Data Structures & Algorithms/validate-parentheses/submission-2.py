class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {
            ")" : "(", 
            "]" : "[", 
            "}" : "{", 
        }

        stack = []

        for c in s:
            if c in pairs.keys():
                if not stack or pairs[c] != stack[-1]:
                    return False
                else:
                    stack.pop()
            else:
                stack.append(c)

        return True if not stack else False