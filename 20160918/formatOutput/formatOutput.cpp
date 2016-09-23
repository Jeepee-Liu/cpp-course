#ifdef _FORMAT_OUTPUT_H

FormatOutput::FormatOutput() {
	this->isFileDirSet = false;
	this->dataSizeN = {0, 0};
} // Done

bool FormatOutput::setFileDir(std::string dir) {
	this->fileDir = dir;
	std::ofstream fOut(dir);
	if (!fOut) {
		return false;
	}
	this->isFileDirSet = true;
	return true;
} // Done



bool FormatOutput::appendData(std::string name, std::vector<dataType> dataColumn) {
	int columnSize = dataColumn.size();
	if (dataSizeN[1]==0 || this->dataSizeN[0]==columnSize ) {
		// If this is the first column OR of matched size 
		// Allocate certain memory for the column
		new dataColPtr = int[columnSize];
		// Change vector into 1-D array
		for(int i=1; i!=columnSize; ++i) {
			dataColPtr[i] = dataColumn[i];
		}
		int curCol = this->dataSizeN[1];
		// append a row to data column
		this->data[curCol] = dataColPtr;
		this->dataSizeN[0] = columnSize;
		this->dataSizeN[1] += 1;
		return true;
	}
	else { // Not the first column
		if (columnSize != this->dataSizeN[0]) {
			// Array size not matched
			return false;
		}
	}
	this->data[name] = data;
	this->dataColN++;
}

bool FormatOutput::appendData(std::string name, dataType *dataColumn, int len) {
	std::vector<dataType> tmpDataVec;
	for(int i=0; i!=len; ++i) {
		tmpDataVec.push_back(dataColumn[i]);
	}
	this->data[name] = tmpDataVec;
	this->dataColN++;
}

bool FormatOutput::writeData() {
	if (!isFileDirSet) {
		return false;
	}
	std::ofstream fOut(this->fileDir);
	for (auto dataCol : this->data) {

	}
}

void formatOutput::clearData(){
	
}

void formatOutput::printData() {
	int maxCol = this->dataSizeN[1];
	int maxRow = this->dataSizeN[0];
	std::cout << "data table of " << maxRow
	<< '*' << maxCol << std::endl << std::endl;
	for (auto name : this->namesVec) {
		std::cout << name << '\t';
	}
	std::string eqns(80,'=');
	std::cout << '\n' << eqns << std::endl;
	for (int col=0; col!=maxCol; ++col ) {
		// print each row of different col;
		for (int row=0; row!=maxRow-1; ++row) {
			std::cout << this->data[row][col] << '\t';
		}
		std::cout
	}
}

#endif