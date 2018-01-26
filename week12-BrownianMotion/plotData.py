#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np
import sys

def main():
	if len(sys.argv) > 1:
		fileDir = sys.argv[1]
	else:
		fileDir = 'temp.log'
	data = np.loadtxt(fileDir, skiprows=1)	
	t = data[:, 0] 
	x = data[:, 1]
	y = data[:, 2]
	plt.subplot(2,2,1)
	plt.plot(t,x)
	plt.xlabel('time')
	plt.ylabel('x')
	plt.subplot(2,2,2)
	plt.plot(t,y)
	plt.xlabel('time')
	plt.ylabel('y')
	plt.subplot(2,1,2)
	plt.plot(x,y)
	plt.xlabel('x')
	plt.ylabel('y')
	plt.savefig('trajectory.png')
	plt.show()

if __name__ == '__main__':
	main()