import pandas as pd
from sklearn import linear_model

df = pd.read_csv(
    r"C:\Users\matiq\OneDrive\Desktop\AI Practical\ai-ml-ds\dd.csv",
    encoding="utf-8-sig"
)

x = df[['area']]                                       
y = df['price']                                         

lin_model = linear_model.LinearRegression()     # create empty linear regression model tree        
lin_model.fit(x, y)                                      
print(lin_model.predict([[10]]))                        