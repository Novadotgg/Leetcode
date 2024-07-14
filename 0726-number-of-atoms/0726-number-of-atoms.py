from collections import Counter
import re

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Split the formula into components: elements, numbers, and parentheses
        exp = re.findall('([A-Z][a-z]*|[0-9]+|[()])', formula)
        stack = []
        n = len(exp)
        ct = Counter()
        ml = 1
        
        for i in range(n-1, -1, -1):
            if 'A' <= exp[i][0] <= 'Z':
                # Calculate the count of the current element
                count = int(exp[i + 1]) if i + 1 < n and exp[i + 1].isdigit() else 1
                ct[exp[i]] += count * ml
            elif exp[i] == ')':
                # Push the multiplier to the stack and update the total multiplier
                m = int(exp[i + 1]) if i + 1 < n and exp[i + 1].isdigit() else 1
                stack.append(m)
                ml *= m
            elif exp[i] == '(':
                # Pop the last multiplier from the stack and update the total multiplier
                ml //= stack.pop()
        
        # Create the result string in alphabetical order
        result = ''.join([key + (str(ct[key]) if ct[key] > 1 else '') for key in sorted(ct.keys())])
        return result