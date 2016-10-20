#!/usr/bin/python

import matplotlib.pyplot as plt 
import sys, time, itertools, getopt

def usage( argv0='parseData.py' ):
	print \
	"""usage: ./parseData.py ... [-f fdir | -m mod| -] [arg] ...
	
	Options and Arguments:
	
	-f fdir : set file directory (also --filedir)
	          default value: 'tmp.log'
	
	-m mod  : choose mode of data parse (also --mode)
	          default value: 'plot'
	          avaliable options: 'plot', 'stat'
	
	-h      : show this help page (also --help)
	"""

def parseArg(argv):
	kwdDict =\
	{'fileDir':'tmp.log',
	'mode':'plot'}
	try:
		opts, args = getopt.getopt(argv[1:],
			'f:m:h',
			['filedir=', 'mode=', 'help'])
	except getopt.GetoptError:
		usage(argv[0])
		sys.exit(2)
	for opt, arg in opts:
		if opt in ('-h', '--help'):
			usage(argv[0])
			sys.exit(2)
		elif opt in ('-f', '--filedir'):
			kwdDict['fileDir'] = arg
		elif opt in ('-m', '--mode'):
			kwdDict['mode'] = arg
		else:
			usage()
			sys.exit(2)
	return kwdDict

class ParseData():
	def __init__(self,kwdDict):
		with open(kwdDict['fileDir'],'r') as dataFile:
			rawDataList = dataFile.readlines()
			# First line
			varNames = rawDataList[0].strip().split()
			# Other lines
			data = [ [float(elem) for elem in line.strip().split() ] for line in rawDataList[1:]  ]
			dataList = map( list, itertools.izip( *data ))
			self.dataDict = dict(zip(varNames,dataList))

	def run(self, mode='plot'):
		if mode == 'plot':
			self.plot(['x', 'dx'])
		elif mode == 'stat':
			self.statistics()
		else:
			print "[ ERROR ]"
			print "Unknown mode: ", mode
			sys.exit(2)

	def plot( self, varNames=[] ):
		if len(varNames) == 0:
			varNames = self.dataDict.keys()
		plt.figure()
		for varName in varNames:
			plt.plot(self.dataDict[varName],label=varName)
		plt.legend()
		plt.show()

	def statistics(self):
		bound1 = 0.698252
		count = [0, 0]
		for val in self.dataDict['x']:
			if val < bound1:
				count[0] += 1
			else:
				count[1] += 1
		probability = [eachCount/float(len(self.dataDict['x'])) for eachCount in count]
		print '{0}\t{1}'.format(*probability)
		return probability

	def xyplot(self, xVarName, yVarName):
		xs = self.dataDict[xVarName]
		ys = self.dataDict[yVarName]
		plt.plot(xs,ys,'o-')
		plt.show()

def main():
	kwdDict = parseArg(sys.argv)
	pData = ParseData(kwdDict)
	pData.run(kwdDict['mode'])
	
if __name__ == '__main__':
	main()