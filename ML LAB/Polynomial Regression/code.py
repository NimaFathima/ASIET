import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import PolynomialFeatures

# --- Load Dataset ---
try:
    boston_df = pd.read_csv('Boston.csv')
except FileNotFoundError:
    print("Error: 'Boston.csv' not found. Please ensure the dataset file is in the same directory.")
    exit()

print("----------------DATASET HEAD----------------")
print(boston_df.head())
print("\n----------------DATASET INFO----------------")
boston_df.info()

# --- Prepare Data ---
x = boston_df[['RM']]  
y = boston_df['MEDV']  
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

# --- Model Training ---
poly = PolynomialFeatures(degree=2)
X_train_poly = poly.fit_transform(X_train)
X_test_poly = poly.transform(X_test)

model = LinearRegression()
model.fit(X_train_poly, y_train)

# --- Model Evaluation ---
y_test_pred = model.predict(X_test_poly)
mse_test = mean_squared_error(y_test, y_test_pred)
r2_test = r2_score(y_test, y_test_pred)

print("\n---MODEL EVALUATION---")
print(f"Test MSE: {mse_test:.4f}")
print(f"Test R-Squared: {r2_test:.4f}")
print("-" * 20)

# --- Visualization ---
plt.figure(figsize=(10, 6))
plt.scatter(X_train, y_train, color='blue', label='Actual Training Values', alpha=0.6)

# Generate a smooth range of RM values for plotting
rm_min = X_train['RM'].min()
rm_max = X_train['RM'].max()
X_range = np.linspace(rm_min, rm_max, 100).reshape(-1, 1)

X_range_poly = poly.transform(X_range)
y_range_pred = model.predict(X_range_poly)

plt.plot(X_range, y_range_pred, color='red', linewidth=2, label='Polynomial Regression Fit')
plt.scatter(X_test, y_test, color='green', label='Actual Testing Values', alpha=0.6)

plt.title('Polynomial Regression Fit (Degree 2)')
plt.xlabel('Average Number of Rooms per Dwelling (RM)')
plt.ylabel('Median Value of Homes (MEDV in $1000s)')
plt.legend()
plt.grid(True)

print("\nDisplaying plot... Close the plot window to start interactive predictions.")
plt.show()

# --- Interactive Prediction Loop ---
print("\n--- PREDICT NEW VALUES ---")
print("Enter the average number of rooms (RM) to predict the median home value (MEDV).")
print("MEDV is in $1000s.")

while True:
    try:
        user_input = input("Enter RM value (or 'q' to quit): ")
        if user_input.lower() == 'q':
            print("Exiting prediction loop. Goodbye!")
            break

        rm_value = float(user_input)
        if rm_value <= 0:
            print("Please enter a positive number of rooms.")
            continue

        rm_input = np.array([[rm_value]])
        rm_input_poly = poly.transform(rm_input)
        predicted_medv = model.predict(rm_input_poly)

        print(f"  -> Predicted MEDV for {rm_value:.1f} rooms: ${predicted_medv[0] * 1000:,.2f}")

    except ValueError:
        print("Invalid input. Please enter a valid number (e.g., 6.5) or 'q'.")
    except Exception as e:
        print(f"An error occurred: {e}")
