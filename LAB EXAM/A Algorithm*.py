import heapq

def a_star():
    try:
        # 1. Get the weighted graph from user input
        graph = {}
        heuristics = {}

        num_edges = int(input("Enter the number of edges: "))
        print("For each edge, enter 'node1 node2 cost' (e.g., A B 5)")
        
        for i in range(num_edges):
            u, v, cost_str = input(f"Edge #{i+1}: ").split()
            cost = int(cost_str)
            
            # Ensure both nodes exist as keys in the graph
            if u not in graph:
                graph[u] = []
            if v not in graph:
                graph[v] = []
            
            # Add the directed edge
            graph[u].append((v, cost))

        # 2. Get start and goal nodes
        start_node = input("\nEnter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()

        # Ensure start/goal nodes are in the graph, even if they have no edges
        if start_node not in graph:
            graph[start_node] = []
        if goal_node not in graph:
            graph[goal_node] = []

        # 3. Get heuristics for all discovered nodes (now from graph.keys())
        print("\nEnter heuristic (h) values for each node:")
        # Sort the keys for a consistent, alphabetical input order
        for node in sorted(graph.keys()): 
            heuristics[node] = int(input(f"  -> Enter h value for node '{node}': "))

        # 4. Perform A* search
        # Priority queue stores (f_cost, g_cost, node, path_list)
        pq = [(heuristics[start_node], 0, start_node, [start_node])]
        visited = set()

        while pq:
            f_cost, g_cost, current_node, path = heapq.heappop(pq)

            if current_node == goal_node:
                print(f"\nPath found from {start_node} to {goal_node}:")
                print(f"  -> Path: {' -> '.join(path)}")
                print(f"  -> Total Cost: {g_cost}")
                return
            
            if current_node not in visited:
                visited.add(current_node)

                # We know current_node is in graph, so graph[current_node] is safe
                for neighbor, edge_cost in graph[current_node]:
                    if neighbor not in visited:
                        new_g_cost = g_cost + edge_cost
                        new_f_cost = new_g_cost + heuristics[neighbor]
                        new_path = path + [neighbor]
                        heapq.heappush(pq, (new_f_cost, new_g_cost, neighbor, new_path))

        print(f"No path found from {start_node} to {goal_node}.")

    except ValueError:
        print("Invalid input. Please enter a valid number or node name.")
    except KeyError as e:
        print(f"Error: Missing heuristic data for node {e}. Please check inputs.")

# Call the function to start the process
a_star()
