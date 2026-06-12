import pandas as pd

df = pd.read_csv(r"D:\CS_6th\AI Practical\3_ai-ml-ds\data.csv")

print(df)

"""
pandas can be used to read many types of files such as:
    read_csv:       to read csv file
    read_excel:     to read excel files
    read_json:      to read json files
    read_sql:       to read sql files
    read_spss:      to read a spss file

    and more.
"""
# 2. using python own read files

with open(r"D:\CS_6th\AI Practical\3_ai-ml-ds\data.csv") as f:
    file = f.read()
print(file)