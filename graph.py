import matplotlib.pyplot as plt
n = [5000, 10000, 15000, 20000, 25000]
t = [0.04, 0.15, 0.35, 0.62, 0.98] 

plt.plot(n, t, marker='o', color='b', linestyle='-')
plt.title('Time Complexity Analysis')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.show()
