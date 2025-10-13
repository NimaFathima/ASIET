import heapq

def a_star():
    """
    Combines graph creation and A* search into one function.
    """
    try:
        # 1. Get the weighted graph and heuristic values from user input
        graph = {}
        heuristics = {}
        
        nodes_str = input("Enter all node names (space-separated): ").split()
        
        for node in nodes_str:
            graph[node] = []
            heuristics[node] = int(input(f"Enter heuristic (h) value for node '{node}': "))
        
        num_edges = int(input("\nEnter the number of edges: "))
        print("For each edge, enter 'node1 node2 cost' (e.g., A B 5)")
        
        for _ in range(num_edges):
            u, v, cost_str = input(f"Edge #{_+1}: ").split()
            cost = int(cost_str)
            if u in graph and v in graph:
                graph[u].append((v, cost))
            else:
                print(f"Warning: Node {u} or {v} not defined. Skipping edge.")

        # 2. Get start and goal nodes for A*
        start_node = input("Enter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()

        if start_node not in graph or goal_node not in graph:
            print("Error: Start or Goal node not in graph.")
            return

        # 3. Perform A* search
        # Priority queue stores (f_cost, g_cost, node, path_list)
        # f_cost = g_cost + h_cost
        # g_cost = actual cost from start
        pq = [(heuristics[start_node], 0, start_node, [start_node])]
        visited = set()

        while pq:
            f_cost, g_cost, current_node, path = heapq.heappop(pq)

            # If we have reached the goal
            if current_node == goal_node:
                print(f"Path found from {start_node} to {goal_node}:")
                print(f"  -> Path: {' -> '.join(path)}")
                print(f"  -> Total Cost: {g_cost}")
                return
            
            if current_node not in visited:
                visited.add(current_node)

                # Explore neighbors, adding them to the priority queue
                for neighbor, edge_cost in graph.get(current_node, []):
                    if neighbor not in visited:
                        new_g_cost = g_cost + edge_cost
                        new_f_cost = new_g_cost + heuristics[neighbor]
                        new_path = path + [neighbor]
                        heapq.heappush(pq, (new_f_cost, new_g_cost, neighbor, new_path))

        print(f"No path found from {start_node} to {goal_node}.")

    except ValueError:
        print("Invalid input. Please enter a valid number or node name.")

# Call the function to start the process
a_star()
