# 참고 영상 : https://www.youtube.com/watch?v=N3nRFE58yDc&feature=youtu.be <이산수학 : 파이썬으로 BFS 구현하기 - 국민대학교 박하명 교수님>
import queue


# using for dfs
class Stack:
    def __init__(self):
        self.user_stack = []

    def __len__(self):
        return len(self.user_stack)

    def empty(self):
        if len(self.user_stack) == 0: return True
        else: return False

    def push(self, data):
        self.user_stack.append(data)

    def pop(self):
        popped_data = self.user_stack.pop()
        return popped_data


# adj : 입력 그래프, start : 탐색을 시작할 정점
def bfs(adj, start):
    visited = set()
    to_visit = queue.Queue()
    to_visit.put(start)

    while not to_visit.empty():
        u = to_visit.get()
        if u in visited: continue

        visited.add(u)
        print("visit ", u)

        for v in adj[u]:
            if v not in visited:
                to_visit.put(v)

# same logic as bfs
def dfs(adj, start):
    visited = set()
    to_visit = Stack()
    to_visit.push(start)

    while not to_visit.empty():
        u = to_visit.pop()
        if u in visited: continue

        visited.add(u)
        print("visit ", u)

        for v in adj[u]:
            if v not in visited:
                to_visit.push(v)
# main
'''
adj :
           a
          /  \
         b    c
        / \  / 
       d   e    h
          /    /
         f ---g
                 
'''

adjacency_graph = {'a': ['b', 'c'],
       'b': ['a', 'd', 'e'],
       'c': ['a', 'e'],
       'd': ['b'],
       'e': ['c', 'f'],
       'f': ['g'],
       'g': ['f', 'h'],
       'h': ['g']}
print("BFS")
bfs(adjacency_graph, 'a')
print("\nDFS")
dfs(adjacency_graph, 'a')