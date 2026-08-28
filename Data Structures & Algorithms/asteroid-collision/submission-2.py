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

        for a in asteroids:
            # Perform collision
            while stack and a < 0 and stack[-1] > 0:
                diff = stack[-1] + a
                if diff < 0:
                    stack.pop()
                elif diff > 0:
                    a = 0
                else:
                    a = 0
                    stack.pop()

            if a:
                stack.append(a) 
   
        return stack
                
