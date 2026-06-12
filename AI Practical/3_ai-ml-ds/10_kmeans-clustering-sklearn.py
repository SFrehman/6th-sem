from sklearn.cluster import KMeans      # Import K-Means clustering algorithm
import pandas as pd                     # Import pandas for data handling


df = pd.read_csv(
    r"D:\CS_6th\AI Practical\3_ai-ml-ds\dd.csv",
    encoding="utf-8-sig"
)

kmeans_model = KMeans(n_clusters=2)                          # Create a K-Means model with 2 clusters

kmeans_model.fit(df[['area', 'price']])                      # Train model and get cluster number for each row
clusters = kmeans_model.predict(df[['area', 'price']])

df['cluster'] = clusters                                      # Add cluster numbers as a new column

cluster_0 = df[df['cluster'] == 0]                            # Get all rows belonging to cluster 0

cluster_1 = df[df['cluster'] == 1]                            # Get all rows belonging to cluster 1

print(cluster_0)                                              # Print rows in cluster 0

print(cluster_1)                                               # Print rows in cluster 1