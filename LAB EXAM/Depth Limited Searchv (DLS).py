def dls_traversal():
    """
    Combines graph creation and Depth Limited Search (DLS) into one function.
    """
    try:
        # 1. Get the graph from user input
        graph = {}
        num_nodes = int(input("Enter the number of nodes: "))
        
        for i in range(num_nodes):
            node = input(f"Enter name for node #{i+1}: ").strip()
            neighbors_str = input(f"Enter neighbors for node '{node}' (space-separated): ").strip()
            graph[node] = neighbors_str.split() if neighbors_str else []

        # 2. Get start, goal node, and depth limit for DLS
        start_node = input("Enter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()
        depth_limit = int(input("Enter the depth limit: "))

        if start_node not in graph or goal_node not in graph:
            print("Error: Start or Goal node not in the graph.")
            return

        # 3. Perform Depth Limited Search (DLS)
        def dls(current_node, goal, limit, path):
            """
            Recursive Depth Limited Search function.
            """
            path.append(current_node)
            print(f"Visiting: {' -> '.join(path)}")

            if current_node == goal:
                return path  # Goal found

            if limit <= 0:
                path.pop()  # Backtrack
                return None  # Depth limit reached

            for neighbor in graph.get(current_node, []):
                result = dls(neighbor, goal, limit - 1, path)
                if result is not None:
                    return result  # Propagate found path up

            path.pop()  # Backtrack
            return None  # Goal not found within this path

        # Start the DLS
        print("\n--- Starting DLS ---")
        found_path = dls(start_node, goal_node, depth_limit, [])

        # 4. Print result
        print("\n--- Result ---")
        if found_path:
            print(f"Goal '{goal_node}' found within depth {depth_limit}.")
            print(f"Path: {' -> '.join(found_path)}")
        else:
            print(f"Goal '{goal_node}' not found within depth limit {depth_limit}.")

    except ValueError:
        print("Invalid input. Please enter a valid number.")

# Call the function to start the process
dls_traversal()
