# Experiment 26: Depth Limited Search (DLS)

def get_graph_from_user():
    """Builds an unweighted graph from user input."""
    graph = {}
    print("--- Create Your Graph ---")
    try:
        num_nodes = int(input("Enter the number of nodes: "))
        for i in range(num_nodes):
            node = input(f"Enter name for node #{i+1}: ").strip()
            neighbors_str = input(f"Enter neighbors for node '{node}' (space-separated): ").strip()
            graph[node] = neighbors_str.split() if neighbors_str else []
    except ValueError:
        print("Invalid input.")
        return None
    print("Graph created successfully.\n")
    return graph

def dls(graph, current_node, goal, limit, path):
    """
    Recursive Depth Limited Search function.
    Returns the path if found, otherwise None.
    """
    path.append(current_node)
    print(f"Visiting: {' -> '.join(path)}")
    
    if current_node == goal:
        return path  # Goal found

    if limit <= 0:
        path.pop() # Backtrack
        return None  # Depth limit reached

    for neighbor in graph.get(current_node, []):
        result = dls(graph, neighbor, goal, limit - 1, path)
        if result is not None:
            return result # Propagate found path up

    path.pop() # Backtrack
    return None # Goal not found within this path

# --- Main Execution ---
if __name__ == "__main__":
    user_graph = get_graph_from_user()
    if user_graph:
        start_node = input("Enter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()
        try:
            depth_limit = int(input("Enter the depth limit: "))
            
            if start_node not in user_graph or goal_node not in user_graph:
                print("Error: Start or Goal node not in the graph.")
            else:
                print("\n--- Starting DLS ---")
                found_path = dls(user_graph, start_node, goal_node, depth_limit, [])
                
                print("\n--- Result ---")
                if found_path:
                    print(f"Goal '{goal_node}' found within depth {depth_limit}.")
                    print(f"Path: {' -> '.join(found_path)}")
                else:
                    print(f"Goal '{goal_node}' not found within depth limit {depth_limit}.")
        except ValueError:
            print("Invalid depth limit. Please enter an integer.")
