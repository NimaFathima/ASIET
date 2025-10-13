from itertools import permutations

def solve_tsp_brute_force():
    """
    Solves the Travelling Salesman Problem using brute force (checking all permutations)
    with user input for cities and distances.
    """
    # Input cities and distances
    cities_str = input("Enter the city names (space-separated): ").strip()
    cities = cities_str.split()
    
    if len(cities) < 2:
        print("Error: Please enter at least two cities.")
        return
    
    dist_matrix = {}
    print("\nEnter the distances between each pair of cities:")
    for i in range(len(cities)):
        for j in range(i + 1, len(cities)):
            city1 = cities[i]
            city2 = cities[j]
            while True:
                try:
                    dist = int(input(f"  Distance from {city1} to {city2}: "))
                    dist_matrix[(city1, city2)] = dist
                    dist_matrix[(city2, city1)] = dist  # Assume symmetric travel
                    break
                except ValueError:
                    print("Invalid distance. Please enter an integer.")

    # Ask for starting city
    start_city = input(f"\nEnter the starting city from {cities}: ").strip()
    if start_city not in cities:
        print(f"Error: '{start_city}' is not a valid city.")
        return
    
    # Generate all permutations of the cities except the start city
    other_cities = [city for city in cities if city != start_city]
    
    min_cost = float('inf')
    best_path = []

    # Check all possible permutations of the cities
    for perm in permutations(other_cities):
        current_cost = 0
        current_city = start_city
        
        # Calculate the cost for this permutation
        for next_city in perm:
            current_cost += dist_matrix[(current_city, next_city)]
            current_city = next_city
        
        # Add the cost to return to the start city
        current_cost += dist_matrix[(current_city, start_city)]
        
        # Update if we find a better (lower cost) path
        if current_cost < min_cost:
            min_cost = current_cost
            best_path = [start_city] + list(perm) + [start_city]
    
    # Output the solution
    print("\n--- TSP Solution ---")
    if best_path:
        print(f"Best Path Found: {' -> '.join(best_path)}")
        print(f"Minimum Cost: {min_cost}")
    else:
        print("Could not find a solution.")

# Execute the function directly
solve_tsp_brute_force()
