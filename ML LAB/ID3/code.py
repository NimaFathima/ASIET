import pandas as pd
from sklearn.tree import DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt

df = pd.read_csv("xyz.csv") 

X_raw = df[['Age', 'Competition', 'Type']]
y_raw = df['Profit']

X = pd.get_dummies(X_raw)

y = y_raw.map({'Down': 0, 'Up': 1})

encoded_feature_names = X.columns.tolist()
class_names = ['Down', 'Up']

model = DecisionTreeClassifier(criterion="entropy", random_state=42)
model.fit(X, y)

print("Model trained successfully.")
print("\n")

plt.figure(figsize=(12, 8))
plot_tree(model, 
          feature_names=encoded_feature_names, 
          class_names=class_names, 
          filled=True,
          rounded=True)
plt.title("Decision Tree (ID3)")
plt.show()

# --- 5. Test Model with Manual Input ---
print("--- Test Model with Manual Input ---")

# Define input
age_input = 'Mild'
comp_input = 'Yes'
type_input = 'Hardware'

print(f"Predicting for: [Age: {age_input}, Competition: {comp_input}, Type: {type_input}]")

# 1. Create a single-row DataFrame from the input
test_data_raw = pd.DataFrame({
    'Age': [age_input],
    'Competition': [comp_input],
    'Type': [type_input]
})

# 2. Encode and Align the new data to match the model's training columns
# This is the most crucial step for manual prediction.
# It converts strings (e.g., 'Mild') to columns (e.g., 'Age_Mild')
# and ensures all columns from training (encoded_feature_names) are present.
test_data_processed = pd.get_dummies(test_data_raw).reindex(columns=encoded_feature_names, fill_value=0)

# 3. Make the prediction
prediction_encoded = model.predict(test_data_processed)

# 4. Convert the numeric prediction (0 or 1) back to a string
prediction_label = class_names[prediction_encoded[0]]

print(f"\n---> Predicted Profit: {prediction_label}")
