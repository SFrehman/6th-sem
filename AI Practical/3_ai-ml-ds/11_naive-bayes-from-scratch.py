import pandas as pd
from collections import defaultdict
import math

df = pd.read_csv(r"D:\CS_6th\AI Practical\3_ai-ml-ds\naive_data.csv")             # read data file

vocab = defaultdict(int)                   # create Empty vocab dictionary to store word counts
spam_bag = defaultdict(int)                # create Empty spam_bag dictionary to store word counts in spam rows
ham_bag = defaultdict(int)                 # create Empty ham_bag dictionary to store word counts in ham rows
cond_spam = defaultdict(int)               # create Empty cond_spam dictionary to store conditional probabilities
cond_ham = defaultdict(int)                # create Empty cond_ham dictionary to store conditional probabilities

spam_rows = df[df['tag'] == 'spam']        # get spam rows and ham rows
ham_rows = df[df['tag'] == 'ham']

spam_train_index = int(len(spam_rows) * 0.8)         # Set spam_index at 80% of length of spam_rows
ham_train_index  = int(len(ham_rows)  * 0.8)         # Set ham_index at 80% of length of ham_rows

test_spam  = spam_rows[spam_train_index:]            # Extract from that spam_index to end for testing
test_ham   = ham_rows[ham_train_index:]              # Extract from that ham_index to end for testing

train_spam  = spam_rows[:spam_train_index]            # Extract from start to that spam_index for training
train_ham   = ham_rows[:ham_train_index]              # Extract from start to that ham_index for training


for index in train_spam['text']:
    for word in index.split(' '):          # Count each word in spam rows and store in spam_bag and vocab
        vocab[word] += 1
        spam_bag[word] += 1

for index in train_ham['text']:
    for word in index.split(' '):          # Count each word in ham rows and store in ham_bag and vocab
        vocab[word] += 1
        ham_bag[word] += 1

prior_spam = len(train_spam) / (len(train_spam) + len(train_ham))  # Prior Probability 
prior_ham = len(train_ham) / (len(train_spam) + len(train_ham))    # total (spam_OR_ham) rows/total rows(spam+ham)


total_words_spam = len(spam_bag) # Total words in spam rows
total_words_ham = len(ham_bag) # Total words in ham rows
total_words_vocab = len(vocab) # Total unique words across entire dataset

for word in vocab:

    # Using Laplace formula :: P(word|spam) = (count(word in spam) + 1) / (total words in spam + total unique words in vocab)
    cond_spam[word] = (spam_bag[word] + 1) / (total_words_spam + total_words_vocab)
    
    # Using Laplace formula :: P(word|ham) = (count(word in ham) + 1) / (total words in ham + total unique words in vocab)
    cond_ham[word] = (ham_bag[word] + 1) / (total_words_ham + total_words_vocab)
    
    

#-----------------------------------------------------

tp=fp=fn=tn=0                                           # True Positive, False Positive, False Negative, True Negative 

for row in test_spam['text']:                           # Testing Spam rows
    prob_spam = math.log(prior_spam)
    prob_ham = math.log(prior_ham)
    for word in row.split(' '):
        if word in spam_bag:                             # if word in spam_bag then += conditional probability
            prob_spam += math.log(cond_spam[word])
        if word in ham_bag:                              # if word in ham_bag then += conditional probability
            prob_ham += math.log(cond_ham[word])
    
    if prob_spam >= prob_ham:
        tp += 1
    else:
        fn +=1


for row in test_ham['text']:                            # Testing Ham rows
    prob_spam = math.log(prior_spam)
    prob_ham = math.log(prior_ham)
    for word in row.split(' '):
        if word in spam_bag:                             # if word in spam_bag then += conditional probability
            prob_spam += math.log(cond_spam[word])
        if word in ham_bag:                              # if word in ham_bag then += conditional probability
            prob_ham += math.log(cond_ham[word])
    
    if prob_spam <= prob_ham:
        tn += 1
    else:
        fp +=1


print(tp, tn, fp, fn)


acc = (tp + tn) / (tp+tn+fp+fn)
pre = tp / (tp + fp)
rec = tp / (tp + fn)
f1 =  2 * ((pre*rec)/(pre+rec))


print(f'Accuracy: {acc}')
print(f'Precision: {pre}')
print(f'Recall: {rec}')
print(f'F1-Score: {f1}')


#---------------------------------------- prediction by taking input ::

def predict(text):
    prob_spam = math.log(prior_spam)
    prob_ham  = math.log(prior_ham)

    for word in text.lower().split(' '):
        if word in vocab:
            prob_spam += math.log(cond_spam[word])
            prob_ham  += math.log(cond_ham[word])

    if prob_spam >= prob_ham:
        return 'spam'
    else:
        return 'ham'

while True:
    user_input = input("\nEnter email text (or 'quit' to exit): ")
    if user_input.lower() == 'quit':
        break
    result = predict(user_input)
    print(f"Prediction: {result}")

# Spam :: win free money now click prize
# Hame :: meeting at 10am tomorrow, please confirm your attendance