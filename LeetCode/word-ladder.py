def judge(w1, w2):
    length = len(w1)
    n = 0
    for i in range(0, length):
        if w1[i] != w2[i]:
            n = n + 1
    if n > 1:
        return False
    return True

def ladderLength(beginWord, endWord, wordDict):
    from collections import deque
    vis = []
    length = len(beginWord)
    queue = deque()
    queue.appendleft([beginWord, 1])
    while len(queue) != 0:
        front = queue.pop()
        print(front)
        if judge(front[0], endWord):
            return front[1]+1 
        for word in wordDict:
            if judge(word, front[0]):
                queue.appendleft([word, front[1]+1])
                vis.append(word)
        for word in vis:
            wordDict.remove(word)
        vis = []
    return 0

            
        
