import heapq
from collections import deque

def get_possible_moves(state):
    moves = []
    zero_index = state.index(0)
    row, col = zero_index // 3, zero_index % 3
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    for dr, dc in directions:
        new_row, new_col = row + dr, col + dc
        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_index = new_row * 3 + new_col
            new_state = list(state)
            new_state[zero_index], new_state[new_index] = new_state[new_index], new_state[zero_index]
            moves.append(tuple(new_state))
    
    return moves

def is_goal(state):
    return state == (1, 2, 3, 4, 5, 6, 7, 8, 0)

# 1. Depth-First Search (DFS)
def dfs(start):
    stack = [(start, [])]
    visited = set()
    while stack:
        state, path = stack.pop()
        if state in visited:
            continue
        visited.add(state)
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            stack.append((move, path + [move]))
    return None

# 2. Breadth-First Search (BFS)
def bfs(start):
    queue = deque([(start, [])])
    visited = set()
    while queue:
        state, path = queue.popleft()
        if state in visited:
            continue
        visited.add(state)
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            queue.append((move, path + [move]))
    return None

# 3. Iterative Deepening Search (IDS)
def ids(start, depth_limit=20):
    def dls(state, path, depth):
        if depth == 0:
            return None
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            if move not in path:
                result = dls(move, path + [move], depth - 1)
                if result:
                    return result
        return None
    
    for depth in range(depth_limit):
        result = dls(start, [], depth)
        if result:
            return result
    return None

# 4. Greedy Best-First Search
def heuristic(state):
    goal = (1, 2, 3, 4, 5, 6, 7, 8, 0)
    return sum(abs((val-1) % 3 - i % 3) + abs((val-1) // 3 - i // 3) for i, val in enumerate(state) if val)

def greedy(start):
    pq = [(heuristic(start), start, [])]
    visited = set()
    while pq:
        _, state, path = heapq.heappop(pq)
        if state in visited:
            continue
        visited.add(state)
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            heapq.heappush(pq, (heuristic(move), move, path + [move]))
    return None

# 5. Uniform Cost Search (UCS)
def ucs(start):
    pq = [(0, start, [])]
    visited = set()
    while pq:
        cost, state, path = heapq.heappop(pq)
        if state in visited:
            continue
        visited.add(state)
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            heapq.heappush(pq, (cost + 1, move, path + [move]))
    return None

# 6. A* Search
def a_star(start):
    pq = [(heuristic(start), 0, start, [])]
    visited = set()
    while pq:
        _, cost, state, path = heapq.heappop(pq)
        if state in visited:
            continue
        visited.add(state)
        if is_goal(state):
            return path
        for move in get_possible_moves(state):
            new_cost = cost + 1
            heapq.heappush(pq, (new_cost + heuristic(move), new_cost, move, path + [move]))
    return None

# Example usage
start_state = (1, 2, 3, 4, 5, 6, 0, 7, 8)  # Example unsolved puzzle

print("DFS Solution:", dfs(start_state))
print("BFS Solution:", bfs(start_state))
print("IDS Solution:", ids(start_state))
print("Greedy Solution:", greedy(start_state))
print("UCS Solution:", ucs(start_state))
print("A* Solution:", a_star(start_state))