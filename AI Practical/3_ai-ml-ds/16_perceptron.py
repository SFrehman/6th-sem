import random
import numpy as np
import math

def perceptrol( ):

    #inputs
    inputs = [random.random() for _ in range(2)]

    #weights
    weights = np.array([random.random() for _ in range(2)])

    #biase
    bias = random.random()

    #output
    output = np.dot(inputs,weights.T) + bias

    #final_output after activation
    final_output = 1/(1 + math.exp(-output))

    print(f"Final Output : {final_output}")

if __name__ == "__main__":
    perceptrol()


    