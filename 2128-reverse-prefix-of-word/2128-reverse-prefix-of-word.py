class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        reverse=""
        for i in range (len(word)):
            if word[i]==ch:
                prefix=word[:i+1]
                reverse=prefix[::-1]
                break
        return reverse+word[len(reverse):]
                
