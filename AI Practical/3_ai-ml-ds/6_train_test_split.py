import pandas as pd
from sklearn.model_selection import train_test_split

df = pd.read_csv(r"D:\CS_6th\AI Practical\3_ai-ml-ds\data.csv")

X = df[['study', 'attendance']]
y = df['result']

# split by test_size=0.3 means 30% of data will be in test set and 70% in training set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

print(f'records of training set {len(X_train)}')
print(f'records of test set {len(X_test)}')