# 1. Import Necessery Libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# 2. Load the Boston dataset
try:
    boston_df = pd.read_csv('Boston.csv')
except FileNotFoundError:
    print("Error: 'Boston.csv' not found. Please ensure the dataset file is in the correct directory.")
    exit()

# 3. Display data info
print("---------------- DATASET HEAD ----------------")
print(boston_df.head())
print("\n---------------- DATASET INFO ----------------")
boston_df.info()

# 4. Define Predictor (X) and Target (y)
# Use capital 'X' as per convention
X = boston_df[['RM']]
y = boston_df['MEDV']

print(f"\nShape of features (X): {X.shape}")
print(f"Shape of target (y): {y.shape}")

# 5. Exploratory Data Analysis (EDA)
print("\nDisplaying EDA scatter plot...")
plt.figure(figsize=(10, 6))
sns.scatterplot(x='RM', y='MEDV', data=boston_df, alpha=0.7)
plt.title('Relationship between Average Rooms (RM) and House Value (MEDV)')
plt.xlabel('Average number of rooms per dwelling (RM)')
plt.ylabel('Median value of owner-occupied homes in $1000s (MEDV)')
plt.grid(True)
plt.show()

# 6. Split Data into Training and Testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=4)

print("\n---------------- DATA SPLIT ----------------")
print(f"Training set size: {len(X_train)} samples")
print(f"Test set size:     {len(X_test)} samples")

# 7. Train the Linear Regression Model
model = LinearRegression()
model.fit(X_train, y_train)
print("\nLinear regression model has been trained successfully.")

# 8. Print Model Parameters
intercept = model.intercept_
coefficient = model.coef_[0]

print("\n--- MODEL PARAMETERS ---")
print(f"Intercept (c): {intercept:.4f}")
print(f"Coefficient for RM (m): {coefficient:.4f}")
print(f"The model equation is: MEDV = {intercept:.4f} + {coefficient:.4f} * RM")

# 9. Make Predictions
y_train_pred = model.predict(X_train)
y_test_pred = model.predict(X_test)

# 10. Evaluate the Model
print("\n--- MODEL EVALUATION ---")
# Calculate metrics for train and test sets
mse_train = mean_squared_error(y_train, y_train_pred)
rmse_train = np.sqrt(mse_train)
r2_train = r2_score(y_train, y_train_pred)

mse_test = mean_squared_error(y_test, y_test_pred)
rmse_test = np.sqrt(mse_test)
r2_test = r2_score(y_test, y_test_pred)

# Print in a clean table
print(f"                  |  Training Set  |  Testing Set")
print(f"------------------|----------------|---------------")
print(f"R-Squared (R²)    |    {r2_train:8.4f}    |   {r2_test:8.4f}")
print(f"Mean Sq. Error    |    {mse_train:8.2f}    |   {mse_test:8.2f}")
print(f"Root Mean Sq. Error |    {rmse_train:8.2f}    |   {rmse_test:8.2f}")
print("-" * 46)

# 11. Visualize the Model Fit on TEST Data
print("\nDisplaying regression line plot on Test Data...")
plt.figure(figsize=(10, 6))

# Plot the actual test data points
plt.scatter(X_test, y_test, color='blue', label='Actual Test Values', alpha=0.6)

# 1. Create a new, sorted array of X-values
# We use .values.reshape(-1, 1) to make it a 2D array for the model
X_fit = np.linspace(X.min(), X.max(), 100).values.reshape(-1, 1)

# 2. Predict the Y-values for this new sorted X-range
y_fit = model.predict(X_fit)

# 3. Plot the smooth, straight regression line
plt.plot(X_fit, y_fit, color='red', linewidth=2, label='Regression Line (Prediction)')

# Labels and Title
plt.title('Linear Regression Fit on Test Data')
plt.xlabel('Average No Of Rooms Per Dwelling (RM)')
plt.ylabel('Median Value Of Home ($1000s)')
plt.legend()
plt.grid(True)
plt.show()

print("\nLab analysis complete.")
