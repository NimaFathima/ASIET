from collections import deque

def bfs_traversal():
    """
    Combines graph creation and BFS traversal into one function.
    """
    try:
        # 1. Get the set of nodes and neighbors from the user
        graph = {}
        num_nodes = int(input("Enter the number of nodes: "))
        if num_nodes <= 0:
            print("Number of nodes must be positive.")
            return

        for i in range(num_nodes):
            node = input(f"Enter name for node #{i+1}: ").strip()
            neighbors_str = input(f"Enter neighbors for node '{node}' (space-separated): ").strip()
            graph[node] = neighbors_str.split() if neighbors_str else []

        # 2. Get the starting node for BFS
        start_node = input("Enter the starting node for BFS: ").strip()
        if start_node not in graph:
            print(f"Error: Start node '{start_node}' not in the graph.")
            return

        # 3. BFS Traversal Implementation
        visited = set()
        queue = deque([start_node])
        visited.add(start_node)

        print("Breadth First Traversal (starting from node", start_node, "):")
        while queue:
            current_node = queue.popleft()
            print(current_node, end=" ")

            # Enqueue all unvisited neighbors
            for neighbor in graph.get(current_node, []):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

        print()

    except ValueError:
        print("Invalid input. Please enter valid numbers and data.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to start the process
bfs_traversal()
