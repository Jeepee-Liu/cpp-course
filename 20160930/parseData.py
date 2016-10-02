#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt 
import sys, time

class ParseData():
	def __init__(self,fileDir):
		with open(fileDir,'r') as dataFile:
			dataDict = {}
			rawDataList = dataFile.readlines()
			dataArray = np.array(
				[ [ float(elem) for elem in eachRow.split() ]
				for eachRow in rawDataList[1:] ], dtype='f8' ).transpose()
			varNames = [ i for i in rawDataList[0].strip().split() if len(i)>0]
			# print varNames
			for ind in xrange(len(varNames)):
				dataDict[varNames[ind]] = dataArray[ind]
			self.dataDict = dataDict
			self.dataArray = dataArray

	def plot( self, varNames=[] ):
		if len(varNames) == 0:
			varNames = self.dataDict.keys()
		plt.figure()
		index = 1
		for varName in varNames:
			plt.subplot(len(varNames),2,index)
			plt.plot(self.dataDict[varName],label=varName)
			index += 2
		plt.subplot(1,2,2)
		for varName in varNames:
			plt.plot(self.dataDict[varName],label=varName)
			plt.
		plt.show()

	def xyplot(self, xVarName, yVarName):
		xs = self.dataDict[xVarName]
		ys = self.dataDict[yVarName]
		plt.plot(xs,ys,'o-')
		plt.show()

def main():
	if len(sys.argv) == 1:
		# default file dir: './test.txt'
		fileDir = 'tmplog.txt'
	else:
		fileDir = sys.argv[1]
	pData = ParseData(fileDir)
	pData.plot(['x','x_err','y','y_err','dist','dist_err'])

if __name__ == '__main__':
	main()