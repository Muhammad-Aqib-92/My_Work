from collections import deque
import heapq

def bfs_solve(capacities, target):
    start = (capacities[0], 0, 0)
    queue = deque([(start, [])])
    visited = set()
    while queue:
        state, path = queue.popleft()
        if target in state:
            return path + [state]
        if state in visited:
            continue
        visited.add(state)
        for next_state in get_next_states(state, capacities):
            if next_state not in visited:
                queue.append((next_state, path + [state]))
    return None

def ids_solve(capacities, target):
    def dls(state, path, depth):
        if target in state:
            return path + [state]
        if depth == 0:
            return None
        visited.add(state)
        for next_state in get_next_states(state, capacities):
            if next_state not in visited:
                result = dls(next_state, path + [state], depth - 1)
                if result:
                    return result
        return None
    for depth in range(100):
        visited = set()
        result = dls((capacities[0], 0, 0), [], depth)
        if result:
            return result
    return None

def heuristic(state, target):
    return min(abs(target - s) for s in state)

def greedy_solve(capacities, target):
    start = (capacities[0], 0, 0)
    pq = [(heuristic(start, target), start, [])]
    visited = set()
    while pq:
        _, state, path = heapq.heappop(pq)
        if target in state:
            return path + [state]
        if state in visited:
            continue
        visited.add(state)
        for next_state in get_next_states(state, capacities):
            if next_state not in visited:
                heapq.heappush(pq, (heuristic(next_state, target), next_state, path + [state]))
    return None

def ucs_solve(capacities, target):
    start = (capacities[0], 0, 0)
    pq = [(0, start, [])]
    visited = {}
    while pq:
        cost, state, path = heapq.heappop(pq)
        if target in state:
            return path + [state]
        if state in visited and visited[state] <= cost:
            continue
        visited[state] = cost
        for next_state in get_next_states(state, capacities):
            if next_state not in visited or visited[next_state] > cost + 1:
                heapq.heappush(pq, (cost + 1, next_state, path + [state]))
    return None

def a_star_solve(capacities, target):
    start = (capacities[0], 0, 0)
    pq = [(heuristic(start, target), 0, start, [])]
    visited = {}
    while pq:
        _, cost, state, path = heapq.heappop(pq)
        if target in state:
            return path + [state]
        if state in visited and visited[state] <= cost:
            continue
        visited[state] = cost
        for next_state in get_next_states(state, capacities):
            new_cost = cost + 1
            if next_state not in visited or visited[next_state] > new_cost:
                heapq.heappush(pq, (new_cost + heuristic(next_state, target), new_cost, next_state, path + [state]))
    return None

def dfs_solve(capacities, target):
    start = (capacities[0], 0, 0)
    stack = [(start, [])]
    visited = set()
    while stack:
        state, path = stack.pop()
        if target in state:
            return path + [state]
        if state in visited:
            continue
        visited.add(state)
        for next_state in get_next_states(state, capacities):
            if next_state not in visited:
                stack.append((next_state, path + [state]))
    return None

def get_next_states(state, capacities):
    next_states = []
    jugs = list(state)
    total_water = sum(jugs)

    for i in range(3):
        fill = jugs[:]
        fill[i] = capacities[i]
        next_states.append(tuple(fill))

        empty = jugs[:]
        empty[i] = 0
        next_states.append(tuple(empty))

    for i in range(3):
        for j in range(3):
            if i != j:
                pour = jugs[:]
                transfer = min(jugs[i], capacities[j] - jugs[j])
                pour[i] -= transfer
                pour[j] += transfer
                next_states.append(tuple(pour))

    return [state for state in next_states if sum(state) == total_water]

def test_solvers():
    capacities = (8, 5, 3)
    target = 4
    algorithms = {"BFS": bfs_solve, "DFS": dfs_solve, "IDS": ids_solve, "UCS": ucs_solve, "Greedy": greedy_solve, "A*": a_star_solve}
    for name, solver in algorithms.items():
        print(f"Testing {name}...")
        solution = solver(capacities, target)
        if solution:
            for step in solution:
                print(step)
        else:
            print("No solution found.")
        print("=" * 40)

test_solvers()