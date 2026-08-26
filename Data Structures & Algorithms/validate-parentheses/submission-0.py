class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {
            ")" : "(", 
            "]" : "[", 
            "}" : "{", 
        }

        stack = []

        for c in s:
            if c in ["(", "[", "{"]:
                stack.append(c)
            if c in pairs.keys():
                if pairs[c] != stack[-1]:
                    return False
                else:
                    stack.pop()
        
        if len(stack):
            return False

        return True