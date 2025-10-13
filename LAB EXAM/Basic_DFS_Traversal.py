def dfs_traversal():
    """
    Combines graph creation and DFS traversal into one function.
    User will input the graph and the starting node for DFS traversal.
    """
    try:
        # Get number of nodes and graph input
        num_nodes = int(input("Enter the number of nodes: "))
        if num_nodes <= 0:
            print("Number of nodes must be positive.")
            return

        # Create graph
        graph = {}
        for i in range(num_nodes):
            node = input(f"Enter name for node #{i+1}: ").strip()
            neighbors_str = input(f"Enter neighbors for node '{node}' (space-separated): ").strip()
            graph[node] = neighbors_str.split() if neighbors_str else []

        # Get starting node for DFS
        start_node = input("Enter the starting node for DFS: ").strip()
        if start_node not in graph:
            print(f"Error: Start node '{start_node}' not in the graph.")
            return

        # DFS implementation
        def dfs(node, visited):
            if node not in visited:
                print(node, end=" ")
                visited.add(node)
                for neighbor in graph.get(node, []):
                    dfs(neighbor, visited)

        # Perform DFS traversal
        print("Depth First Traversal (starting from node", start_node, "):")
        dfs(start_node, set())
        print()

    except ValueError:
        print("Invalid input. Please enter numbers where required.")

# Call the function to start the process
dfs_traversal()
