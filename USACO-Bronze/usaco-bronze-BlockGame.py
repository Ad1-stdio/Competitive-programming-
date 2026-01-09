import sys

# Standard USACO I/O setup
def solve():
    # Read N from the first line
    try:
        line = sys.stdin.readline()
        if not line: return
        n = int(line.strip())
    except EOFError:
        return

    # Total blocks needed for each of the 26 letters
    total_blocks = [0] * 26

    for _ in range(n):
        word1, word2 = sys.stdin.readline().split()
        
        # Count letters for word 1
        count1 = [0] * 26
        for char in word1:
            count1[ord(char) - ord('a')] += 1
            
        # Count letters for word 2
        count2 = [0] * 26
        for char in word2:
            count2[ord(char) - ord('a')] += 1
            
        # For each board, we need the MAX of each letter's count
        for i in range(26):
            total_blocks[i] += max(count1[i], count2[i])

    # Output the result (one line per letter)
    for count in total_blocks:
        print(count)

if __name__ == "__main__":
    solve()