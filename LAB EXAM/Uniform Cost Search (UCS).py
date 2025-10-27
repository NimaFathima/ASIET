import heapq

def ucs_traversal():
    """
    Combines graph creation and Uniform Cost Search (UCS) into one function.
    """
    try:
        # 1. Get the weighted graph from user input
        graph = {}
        num_edges = int(input("Enter the number of edges: "))
        print("For each edge, enter 'node1 node2 cost' (e.g., A B 5)")

        for _ in range(num_edges):
            u, v, cost_str = input(f"Edge #{_+1}: ").split()
            cost = int(cost_str)

            # Add nodes if they don't exist
            if u not in graph: graph[u] = []
            if v not in graph: graph[v] = []

            # Add edge (undirected graph)
            graph[u].append((v, cost))
            graph[v].append((u, cost))  # Assuming undirected graph

        # 2. Get start and goal nodes for UCS
        start_node = input("Enter the start node: ").strip()
        goal_node = input("Enter the goal node: ").strip()

        if start_node not in graph or goal_node not in graph:
            print(f"Error: Start or Goal node not in graph.")
            return

        # 3. Perform UCS
        # Priority queue stores tuples of (cost, node, path_list)
        pq = [(0, start_node, [start_node])]
        visited = set()

        while pq:
            # Pop the node with the smallest cost
            cost, current_node, path = heapq.heappop(pq)

            # If the goal is reached, print the path and cost
            if current_node == goal_node:
                print(f"Path found from {start_node} to {goal_node}:")
                print(f"  -> Path: {' -> '.join(path)}")
                print(f"  -> Cost: {cost}")
                return

            if current_node not in visited:
                visited.add(current_node)

                # Explore neighbors
                for neighbor, edge_cost in graph[current_node]:
                    if neighbor not in visited:
                        new_cost = cost + edge_cost
                        new_path = path + [neighbor]
                        heapq.heappush(pq, (new_cost, neighbor, new_path))

        print(f"No path found from {start_node} to {goal_node}.")

    except (ValueError, IndexError):
        print("Invalid input format. Please try again.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to start the process
ucs_traversal()
