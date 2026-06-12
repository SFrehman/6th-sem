from collections import defaultdict
import pandas as pd
import math

df = pd.read_csv(r"D:\CS_6th\AI Practical\3_ai-ml-ds\naive_data.csv")             # read data file


bag_of_words = defaultdict(int)                   # create Empty bag-of-words dictionary to store word counts

for index in df['text']:
    for word in index.split(' '):          # Count each word in text column and store in bag_of_words
        bag_of_words[word] += 1

print(bag_of_words)
