# --------------"""Pandas"""----------------

import pandas as pd

df=pd.read_csv("data.csv")  

# """ read_csv:       to read csv file
#     read_excel:     to read excel files
#     read_json:      to read json files
#     read_sql:       to read sql files
#     read_spss:      to read a spss file
# """

#   3. Display records 
print(df.head())    #   first 5 rows

print(df.tail())    #   last 5 rows

print(df['name'])   #   Whole column


