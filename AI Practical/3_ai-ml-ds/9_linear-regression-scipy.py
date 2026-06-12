import pandas as pd
from scipy import stats
import random

df = pd.read_csv(
    r"D:\CS_6th\AI Practical\3_ai-ml-ds\dd.csv",
    encoding="utf-8-sig"
)
x = df['area']                                    # x = [random.randint(10, 90) for _ in range(15)]
y = df['price']

m, c, r, p, err = stats.linregress(x, y)          # m, c, _, _, _ = stats.linregress(x, y)
 
# r=1 positive relation :: r=-1 negative relation :: r=0 no relation
# y = mx + c

# prediction = [m * var + c for var in x]       # for every x-values(area) predicting y-values(price) as y=mx+c

prediction = m * 10 + c
print(prediction)
