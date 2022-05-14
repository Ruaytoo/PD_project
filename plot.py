import matplotlib.pyplot as plt
import subprocess

subprocess.call('./run')

data = open('result.txt', 'r')

Lines = data.readlines()

N, E = map(int, Lines[0].split())

y = []
x = []
p = 0

Lines = Lines[1:]

for i in range(0, 100):
	s = 0
	for j in range(E*N):
		t = tuple(map(int, Lines[i*E*N+j].split()))
		s += sum(t)
	y += [s/(E*N*20)]
	x += [p]
	p += 0.01

plt.plot(x, y)
plt.show()