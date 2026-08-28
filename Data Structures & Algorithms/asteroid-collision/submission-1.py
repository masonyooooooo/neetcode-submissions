class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        """
        First element: if it goes to left (negative), never collide with others
        [IDEA] Use stack to track one direction?
        [DRY] [2, 4, -4, -1]
        stack = [2]
        [DRY] [7, -3, 9]
        stack = [7, 9]
        [DRY] [-1, 2, 4, -4, -1]
        stack = [-1, 2]

        [Solution] 
        Stack:
            Push all starting neg elements into stack
            Traverse asteroids:
                if num > 0:
                    push
                else:
                    compare with top: 
                        same direction: push
                        different direction:
                            current is less: continue
                            current is large: 
                                pop and push
                                compare the top, until no less different direction
        """
        stack = []

        for i in range(len(asteroids)):
            if asteroids[i] > 0 or len(stack) == 0 or stack[-1] < 0:
                stack.append(asteroids[i])
            elif -asteroids[i] <= stack[-1]:
                if -asteroids[i] == stack[-1]:
                    stack.pop()
                continue
            else:
                while len(stack) != 0 or -asteroids[i] >= stack[-1]:
                    stack.pop()
                    if len(stack) != 0 or -asteroids[i] == stack[-1]:
                        break
            
        return stack
                
