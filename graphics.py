import matplotlib.pyplot as plt
import numpy as np

def out(path):
    x, y, z = np.loadtxt(path, unpack=True)
    

    plt.plot(x, y, marker='o', linestyle='-')
    plt.plot(x, z, marker='o', linestyle='-')

    plt.title('Scatter Plot of Points')

    plt.xlabel('X')
    plt.ylabel('Y')

    plt.show()

out('graphics_data_bubble_sort.txt')
out('graphics_data_shaker_sort.txt')
out('graphics_data_naturale_two_way_sort.txt')