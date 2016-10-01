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
		for varName in varNames:
			plt.plot(self.dataDict[varName],label=varName)
		plt.legend()
		plt.show()

def main():
	if len(sys.argv) == 1:
		fileDir = 'test.txt'
	else:
		fileDir = sys.argv[1]
	pData = ParseData(fileDir)
	pData.plot()

if __name__ == '__main__':
	main()