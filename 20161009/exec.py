#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np
import os, subprocess
import itertools
import time

def setup():
	# Basic parameters to run C++ program
	argv = {'avgN':500,
	'stepN':100000,
	'stepL':0.02,
	'end':0.3,
	'start':0.1,
	'num':100
	}
	
	# regenerate data by
	regenData = False
	
	# file name
	fileDir = "./stat2.txt"

	figName = 'prob_plot2.png'

	return argv, regenData, fileDir, figName

def simuLoop(argv, fileDir):
	bgnTime = time.time()
	fo = open(fileDir, "w")
	kTList = list(np.exp(np.linspace(np.log(argv['start']), np.log(argv['end']), argv['num'])))
	for index, kT in enumerate( kTList ):
		argv['kT'] = kT
		print '[', index, '/', argv['num'], '] kT = ', kT
		os.system("./example -l {stepL} -a {avgN} -n {stepN} -k {kT} -f tmp.log".format(**argv) )
		# output = subprocess.Popen("./parseData.py -m stat -f log/{}.log".format(str(index)), shell = True).communicate()[0]
		output = os.popen("./parseData.py -m stat -f tmp.log").read()
		line = str(kT) + '\t' + output
		fo.write(line)
		fo.flush()
		timeElapsed = time.time() - bgnTime
		print 'Time elapsed = ' + str(timeElapsed)
	fo.close()
	os.system("rm tmp.log")

def analyzeData(fileDir, figName):
	with open(fileDir, 'r') as dataFile:
		rawDataList = dataFile.readlines()
		# First line
		varNames = ['kT', 'prob1', 'prob2']
		# Other lines
		data = [ [float(elem) for elem in line.strip().split() ] for line in rawDataList  ]
		dataList = map( list, itertools.izip( *data ))
		dataDict = dict(zip(varNames,dataList))
	plt.figure('prob_plot.png')
	for varName in ('prob1', 'prob2'):
		plt.plot( dataDict['kT'], dataDict[varName], '-o', label=varName)
	plt.xlabel(r'${\itk_B \times T} / E_0$', fontsize=14)
	plt.ylabel('Probability', fontsize=14)
	plt.title('Probability of particle in each state', fontsize=16)
	# plt.text(0.5, 0.05, 
	# 	'Note:\nState 2 is the ground state\nwhile state 1 and 3 are two\nequivalent excited states.',
	# 	fontsize=12)
	plt.text(.3, 0.4,
		'potential:\n\n$V(x) = E_0 [-0.5 cos(0.5 \pi x) - cos(1.5 \pi x) ]$',
		fontsize = 16, bbox=dict(facecolor='none', edgecolor='black', pad=10.0) )
	plt.legend(['state 1', 'state 2'])
	plt.savefig(figName)
	plt.show()

def main():
	argv, regenData, fileDir, figName = setup()
	if regenData:
		simuLoop(argv, fileDir)
	analyzeData(fileDir, figName)

if __name__ == '__main__':
	main()