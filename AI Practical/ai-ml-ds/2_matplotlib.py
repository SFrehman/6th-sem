
# --------------"""matplotlip"""----------------
import matplotlib.pyplot as plt
import random

x = [random.randint(10,20) for _ in range(20)]
y = [random.randint(15,200) for _ in range(20)]

plt.scatter(x, y)       #   draw scatter plot

plt.plot(x, y)          #   draw line plot

plt.bar(x, y)           #   draw bar chart

plt.pie(x, labels=y)    #   draw pie chart

plt.boxplot(x)          #   draw box plot

plt.xlabel = 'x-axis'   #   label x-axis
plt.ylabel = 'y-axis'   #   label y-axis

plt.show()              #   display the plot