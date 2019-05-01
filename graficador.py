import numpy as np 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.axes3d import Axes3D

Z = np.loadtxt('datos.txt')
X = np.array(range(101))/101
Y = X
X,Y = np.meshgrid(X,Y)
fig = plt.figure()
ax = Axes3D(fig)
ax.plot_wireframe(X,Y,Z,color = 'r')
plt.savefig('Resultado.png')