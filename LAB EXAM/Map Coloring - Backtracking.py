def map_coloring():
    """
    Solves the map coloring problem using backtracking.
    User inputs the graph (regions and borders) and the number of colors.
    """

    def get_undirected_graph():
        """
        Builds an undirected graph from user input.
        If user enters A-B, it automatically adds B-A.
        """
        graph = {}
        print("--- Create Your Map (Undirected Graph) ---")
        try:
            nodes_str = input("Enter all region names (space-separated, e.g., WA NT SA): ").split()
            for node in nodes_str:
                graph[node] = []  # Initialize each node with an empty neighbor list

            num_edges = int(input("\nEnter the number of borders (edges): "))
            print("For each border, enter 'region1 region2' (e.g., WA NT)")
            for _ in range(num_edges):
                u, v = input(f"Border #{_+1}: ").split()
                if u in graph and v in graph:
                    graph[u].append(v)
                    graph[v].append(u)  # Add edge in both directions for undirected graph
                else:
                    print(f"Warning: Region {u} or {v} not defined. Skipping border.")
        except (ValueError, IndexError):
            print("Invalid input format. Please try again.")
            return None
        print("Graph created successfully.\n")
        return graph

    def is_safe(node, color, graph, assignment):
        """
        Checks if it's safe to assign a color to a node by checking its neighbors.
        """
        for neighbor in graph.get(node, []):
            if assignment.get(neighbor) == color:
                return False
        return True

    def graph_coloring_solver(nodes, graph, num_colors, assignment, node_index):
        """
        Recursive backtracking function to solve the map coloring problem.
        """
        # Base case: If all nodes are assigned a color, we are done
        if node_index == len(nodes):
            return True

        current_node = nodes[node_index]

        # Try assigning each color to the current node
        for color in range(1, num_colors + 1):
            if is_safe(current_node, color, graph, assignment):
                # Assign the color
                assignment[current_node] = color

                # Recur for the next node
                if graph_coloring_solver(nodes, graph, num_colors, assignment, node_index + 1):
                    return True

                # If recursion didn't lead to a solution, backtrack
                assignment[current_node] = 0

        return False  # No color could be assigned to this node

    # Main map coloring function logic
    user_graph = get_undirected_graph()

    if user_graph:
        try:
            m = int(input("Enter the number of available colors: "))
            if m <= 0:
                print("Number of colors must be positive.")
            else:
                node_list = list(user_graph.keys())
                # Initialize assignment: 0 means no color
                color_assignment = {node: 0 for node in node_list}

                if graph_coloring_solver(node_list, user_graph, m, color_assignment, 0):
                    print(f"\nSolution exists with {m} colors!")
                    print("Coloring of regions is:")
                    for node, color in sorted(color_assignment.items()):
                        print(f"  - Region {node} --> Color {color}")
                else:
                    print(f"\nNo solution exists with {m} colors.")

        except ValueError:
            print("Invalid input. Please enter an integer for the number of colors.")

# Run the map coloring function
map_coloring()
