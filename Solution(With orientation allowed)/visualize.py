import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3

#5 different colors for 5 different switches (RGBA)
colors = [(1, 0.1, 0.1, 1), (0.1, 1, 0.1, 1), (0.1, 181/255., 204/255., 1), (1, 0.5, 0.1, 1), (0.23, 0.23, 0.23, 1)]

#Opening "output.txt" which have info about switches position and their orientation
with open("output.txt",'r') as f:
    data = f.readlines()


rz, ry, rx = [int(x) for x in data[0].split()]
data.pop(0)
fig = plt.figure()
ax = fig.gca(projection='3d')
#Making Boundary to fill smooth orientations
ax.bar3d(0, 0, 0, max(ry,rz,rx), max(ry,rz,rx), max(ry,rz,rx), color = (0, 0, 0, 0), shade = False)
#Making legend
type_0 = plt.Rectangle((0, 0), 1, 1, fc = colors[0])
type_1 = plt.Rectangle((0, 0), 1, 1, fc = colors[1])
type_2 = plt.Rectangle((0, 0), 1, 1, fc = colors[2])
type_3 = plt.Rectangle((0, 0), 1, 1, fc = colors[3])
type_4 = plt.Rectangle((0, 0), 1, 1, fc = colors[4])
ax.legend([type_0, type_1, type_2, type_3, type_4],['Type 0', 'Type 1', 'Type 2', 'Type 3', 'Type 4'])
#Creating transparant rack  
ax.bar3d(0, 0, 0, rx, ry, rz, color = (0, 0, 0, 0.1), shade = False)
for line in data:
    #Creating switch with appropiate colors
    t, dz, dy, dx, x, y, z = [int(x) for x in line.split()]
    ax.bar3d(x, y, z, dx, dy, dz, color = colors[t], edgecolor = (0, 0, 0, 1), shade = False) 
    
ax.set_title('Visualization of placed switches')
plt.show()