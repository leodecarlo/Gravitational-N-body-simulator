import pandas as pd
import matplotlib.pyplot as plt

# Load your CSV file
df = pd.read_csv('twoparticles.csv', header=None)  

# Create a 3D scatter plot
fig_3d = plt.figure(figsize=(10, 8))
ax_3d = fig_3d.add_subplot(111, projection='3d')
ax_3d.scatter(df[0], df[1], df[2], c='b', marker='o')
ax_3d.set_xlabel('X Coordinate')
ax_3d.set_ylabel('Y Coordinate')
ax_3d.set_zlabel('Z Coordinate')
ax_3d.set_title('3D Scatter Plot of Particle Positions')
plt.savefig('3Dscatterplot.png')
plt.show()

# XY projection
fig_xy = plt.figure(figsize=(8, 6))
ax_xy = fig_xy.add_subplot(111)
ax_xy.scatter(df[0], df[1], c='r', marker='o')
ax_xy.set_xlabel('X Coordinate')
ax_xy.set_ylabel('Y Coordinate')
ax_xy.set_title('XY Projection of Particle Positions')
plt.savefig('XYscatterplot.png')
plt.show()

# XZ projection
fig_xz = plt.figure(figsize=(8, 6))
ax_xz = fig_xz.add_subplot(111)
ax_xz.scatter(df[0], df[2], c='g', marker='o')
ax_xz.set_xlabel('X Coordinate')
ax_xz.set_ylabel('Z Coordinate')
ax_xz.set_title('XZ Projection of Particle Positions')
plt.savefig('XZscatterplot.png')
plt.show()

# YZ projection
fig_yz = plt.figure(figsize=(8, 6))
ax_yz = fig_yz.add_subplot(111)
ax_yz.scatter(df[1], df[2], c='b', marker='o')
ax_yz.set_xlabel('Y Coordinate')
ax_yz.set_ylabel('Z Coordinate')
ax_yz.set_title('YZ Projection of Particle Positions')
plt.savefig('YZscatterplot.png')
plt.show()
