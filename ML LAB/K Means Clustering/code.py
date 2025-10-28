import pandas as pd 
import matplotlib.pyplot as plt 
from sklearn.cluster import KMeans

df = pd.read_csv("california_housing_train.csv")
 
X = df[['longitude', 'latitude']].values 

kmeans = KMeans(n_clusters=10, random_state=32) 
kmeans.fit(X) 

y_kmeans = kmeans.predict(X) 
centers = kmeans.cluster_centers_ 
 
plt.figure(figsize=(8, 6)) 
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, s=50, cmap='viridis') 
plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.75, 
marker='X', label='Centroids') 
plt.xlabel('longitude') 
plt.ylabel('latitude') 
plt.title('K-Means Clustering on California Housing Dataset') 
plt.legend() 
plt.show()
