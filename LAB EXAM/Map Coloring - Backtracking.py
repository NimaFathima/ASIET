# Check if it's safe to color a node with the given color
def is_safe(node, color, assignment, graph):
    for neighbor in graph[node]:
        if neighbor in assignment and assignment[neighbor] == color:
            return False
    # Also check reverse neighbors (for directed graphs)
    for other in graph:
        if node in graph[other] and assignment[other] == color:
            return False
    return True

# Backtracking function for graph coloring
def graph_coloring(nodes, graph, m, assignment, index=0):
    if index == len(nodes):  # All nodes processed
        return True
    node = nodes[index]
    for color in range(1, m + 1):
        if is_safe(node, color, assignment, graph):
            assignment[node] = color
            if graph_coloring(nodes, graph, m, assignment, index + 1):
                return True
            assignment[node] = 0  # Backtrack
    return False

# Solve the map coloring problem
def solve_map_coloring(graph, m):
    nodes = list(graph.keys())
    assignment = {node: 0 for node in nodes}  # 0 = uncolored
    if not graph_coloring(nodes, graph, m, assignment):
        print(f"No solution exists with {m} colors.")
        return None
    print("Solution exists: Coloring of vertices is")
    for node in nodes:
        print(f"Vertex {node} --> Color {assignment[node]}")
    return assignment

# Take graph input from user
def graph():
    try:
        num_nodes = int(input("Enter the number of nodes: "))
        if num_nodes <= 0:
            print("Number of nodes must be positive.")
            return None

        graph = {}
        for i in range(num_nodes):
            node = input(f"Enter name for node #{i+1}: ").strip()
            neighbors_str = input(f"Enter neighbors for node '{node}' (space-separated): ").strip()
            graph[node] = neighbors_str.split() if neighbors_str else []

        return graph
    except ValueError:
        print("Invalid input. Please enter a valid number of nodes.")
        return None

# Run the program directly
graph_data = graph()
m = int(input("Number of colors: "))
solve_map_coloring(graph_data, m)
