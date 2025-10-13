def subset_sum():
    """
    Combines input handling and the subset sum problem with backtracking.
    """
    global solution_found
    solution_found = False

    try:
        # 1. Get the set of numbers from the user
        numbers_str = input("Enter a set of numbers (space-separated): ").strip()
        numbers = [int(num) for num in numbers_str.split()]

        # 2. Get the target sum from the user
        target_sum = int(input("Enter the target sum: "))

        # 3. Backtracking DFS to find a valid subset
        def find_subset(index, current_subset):
            nonlocal solution_found
            if solution_found:
                return

            if sum(current_subset) == target_sum:
                print(f"Solution Found: {current_subset}")
                solution_found = True
                return

            if sum(current_subset) > target_sum or index >= len(numbers):
                return

            # Include the number at the current index
            current_subset.append(numbers[index])
            find_subset(index + 1, current_subset)

            # Backtrack: Exclude the number and try next possibility
            current_subset.pop()

            # Exclude the number at the current index
            find_subset(index + 1, current_subset)

        # Start searching for a solution
        print("\nSearching for a subset that sums to", target_sum, "...")
        find_subset(0, [])

        if not solution_found:
            print("No solution found.")

    except ValueError:
        print("Invalid input. Please enter integers only.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to start the process
subset_sum()
