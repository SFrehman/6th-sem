import random
import numpy as np
import math

"""
Architecture:
Input Layer  →  Hidden Layer  →  Output Layer

x1
    ->  h1
x2          ->  o
    ->  h2
x3

"""
def ann_one_hidden_layer():
    #================ Input Layer =================

    # 3 input nodes
    input1 = [random.random() for _ in range(3)]

    """
    input1 = [x1, x2, x3]
    """

    #================ Input → Hidden Layer =================

    # 3 inputs → 2 hidden neurons (6 weights total)
    weights1 = np.array([[random.random() for _ in range(3)],
                        [random.random() for _ in range(3)]])

    """
    weights1 = [[w11, w12, w13],
                [w21, w22, w23]]

    """

    # 2 biases (one per hidden neuron)
    bias1 = [random.random() for _ in range(2)]

    """
    bias1 = [b1, b2]
    """

    # Hidden layer output
    hidden_output = np.dot(input1, weights1.T) + bias1

    """
    h1 = x1*w11 + x2*w12 + x3*w13 + b1
    h2 = x1*w21 + x2*w22 + x3*w23 + b2
    hidden_output = [h1, h2]
    """

    #================ Hidden → Output Layer =================

    # 2 hidden neurons → 1 output neuron
    weights2 = np.array([random.random() for _ in range(2)])

    """
    weights2 = [w1, w2]

    """

    # single bias for output neuron
    bias2 = random.random()

    """
    bias2 = b1
    """

    # final output
    output = np.dot(hidden_output, weights2) + bias2

    """
    o1 = h1*w1 + h2*w2 + b1
    output = final result (o1)
    """
    # print("Input Layer   :", input1)
    # print("Hidden Layer  :", hidden_output)
    # print("Output Layer  :", output)

    #======== activation function using sigmoid formula ===========
    # 1/(1 + e^(-x))
    final_output = 1/(1 + math.exp(-output))

    print(f"final_output : \n{final_output}")

if __name__ == "__main__":
    ann_one_hidden_layer()