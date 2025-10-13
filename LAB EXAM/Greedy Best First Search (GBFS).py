import heapq

def greedy_best_first_search():
    """
    Combines graph creation and Greedy Best-First Search (GBFS) into one function.
    """
    try:
        # 1. Get the graph and heuristic values from user input
        graph = {}
        heuristics = {}
        
        nodes_str = input("Enter all node names (space-separated): ").split()
        
        for node in nodes_str:
            graph[node] = []
            heuristics[node] = int(input(f"Enter heuristic value for node '{node}': "))
        
        num_edges = int(input("\nEnter the number of edges: "))
        print("For each edge, enter 'node1 node2' (e.g., A B)")
        
        for _ in range(num_edges):
            u, v = input(f"Edge #{_+1}: ").split()
            if u in graph and v in graph:
                graph[u].append(v)
            else:
                print(f"Warning: Node {u} or {v} not defined. Skipping edge.")

        # 2. Get start and goal nodes for GBFS
        start_node = input("Enter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()

        if start_node not in graph or goal_node not in graph:
            print("Error: Start or Goal node not in graph.")
            return

        # 3. Perform Greedy Best-First Search
        # Priority queue stores (heuristic_value, node, path_list)
        pq = [(heuristics[start_node], start_node, [start_node])]
        visited = set()

        while pq:
            # Pop the node with the lowest heuristic value
            h_val, current_node, path = heapq.heappop(pq)

            # If we have reached the goal
            if current_node == goal_node:
                print(f"Path found from {start_node} to {goal_node}:")
                print(f"  -> Path: {' -> '.join(path)}")
                return

            if current_node not in visited:
                visited.add(current_node)

                # Explore neighbors, adding them to the priority queue
                for neighbor in sorted(graph.get(current_node, [])):  # Sort for deterministic output
                    if neighbor not in visited:
                        heapq.heappush(pq, (heuristics[neighbor], neighbor, path + [neighbor]))

        print(f"No path found from {start_node} to {goal_node}.")

    except ValueError:
        print("Invalid input. Please enter a valid number or node name.")

# Call the function to start the process
greedy_best_first_search()
