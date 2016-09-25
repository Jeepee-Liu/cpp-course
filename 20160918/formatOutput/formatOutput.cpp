#ifdef _FORMAT_OUTPUT_H

FormatOutput::FormatOutput() {
	this->isFileDirSet = false;
	this->dataSizeN[0] = 0;
	this->dataSizeN[1] = 0;
} // Done & I don't know how to test it

bool FormatOutput::setFileDir(std::string dir) {
	this->fileDir = dir;
	std::ofstream fOut(dir);
	if (!fOut) {
		return false;
	}
	this->isFileDirSet = true;
	/***** For test: *****
	 * std::cout << "File directory set!" << std::endl; 
	 */
	return true;
} // Done & tested

// Append a VECTOR to data array
bool FormatOutput::appendData(std::string name, std::vector<double> dataColumn) {
	int columnSize = dataColumn.size();
	int &curCol = this->dataSizeN[1];
	int &RowN = this->dataSizeN[0];
	if( curCol==0 || RowN==columnSize ) {
		// If this is the first column OR of matched size 
		// Allocate certain memory for the column
		RowN = columnSize;
		double* dataColPtr = new double[RowN];
		this->namesVec.push_back(name);
		// Change vector into 1-D array
		for(int i=0; i!=columnSize; ++i) {
			dataColPtr[i] = dataColumn[i];
			// For test:
			// std::cout << dataColPtr[i] << std::endl;
		}
		// append a row to data column
		this->data[curCol] = dataColPtr;
		curCol++;
		// *** For test:
		// std::cout << " column # : " <<this->dataSizeN[1] <<std::endl;
		// std::cout << " row number : " << this->dataSizeN[0] << std::endl;
		return true;
	}
	else {
		// Not the first column
		if (columnSize != this->dataSizeN[0]) {
			// Array size not matched
			return false;
		}
	}
	return false;
} // Done & tested

// Append a LIST to data array
bool FormatOutput::appendData(std::string name, double* dataColumn, int len) {
	int columnSize = len;
	int &curCol = this->dataSizeN[1];
	int &RowN = this->dataSizeN[0];
	if ( curCol==0 || RowN==columnSize ) {
		// If this is the first column OR of matched size 
		// Allocate certain memory for the column
		RowN = columnSize;
		double* dataColPtr = new double[RowN];
		// Change vector into 1-D array
		for(int i=0; i!=columnSize; ++i) {
			dataColPtr[i] = dataColumn[i];
		}
		int curCol = this->dataSizeN[1];
		this->data[curCol] = dataColPtr; // append a row to data column
		this->namesVec.push_back(name); // append name of this data column to the name vector
		this->dataSizeN[0] = columnSize; // define column size under both circumstances
		this->dataSizeN[1]++; // add a column in size
		return true;
	}
	else {
		// Not the first column AND array size not matched
		return false;
	}
} // Done

int* FormatOutput::getDataSize(){
	// prevent direct call at private pointer
	int* dataSizePtr = new int[2]; 
	dataSizePtr[0] = dataSizeN[0];
	dataSizePtr[1] = dataSizeN[1];
	return this->dataSizeN;
} // Done

bool FormatOutput::writeData() {
	if (!isFileDirSet) {
		return false;
	}
	this->data2str(1); // mode: concise
	std::ofstream fOut(this->fileDir);
	fOut << this->dataStr;
	fOut.close();
	return true;
} // Done

void FormatOutput::clearData(){
	for(int i=1; i!=this->dataSizeN[1]; ++i) {
		delete[] data[i];
	}
} // Done

void FormatOutput::printData() {
	int maxCol = this->dataSizeN[1];
	int maxRow = this->dataSizeN[0];
	// print header
	std::cout << "data table of " << maxRow
	<< '*' << maxCol << std::endl << std::endl;
	// refesh the string buffering the output
	this->data2str(0); // mode: decorated
	/* **** For test:
	 * std::cout << "****** Break Point 2." << std::endl;
	 */
	// print data
	std::cout << this->dataStr;
} // Done & tested

std::string FormatOutput::num2str(double num) {
	char* tmpCharPtr = new char[20];
	std::sprintf(tmpCharPtr,"%.6f",num);
	std::string str(tmpCharPtr);
	delete[] tmpCharPtr;
	return str;
} // Done & tested

void FormatOutput::data2str(){
	this->clearDataStr();
	int maxCol = this->dataSizeN[1];
	int maxRow = this->dataSizeN[0];
	std::string &bufferStr = this->dataStr;
	std::string boldLine(16*maxCol,'=');
	std::string thinLine(16*maxCol,'-');
	// print correspondent names in the first line
	bufferStr += boldLine + '\n';
	for(auto name : this->namesVec) {
		this->dataStr = this->dataStr + name + "\t\t";
	}
	bufferStr += '\n' + thinLine + '\n';
	// append data to the buffer string
	for(int row=0; row<maxRow; ++row) {
		// append each row of data
		for(int col=0; col<maxCol; ++col) {
			// append each column of data in the row
			/***** For test: *****
			 *  std::cout << "[converting to string...] Row: " << row << ", column: " << col << ". Value: " << num2str(data[row][col]) << std::endl;
			 */
			// ATTENTION!!!
			// Data element for correspondent position (row, col) is data[col][row]
			bufferStr += num2str(data[col][row]) + "\t";
		}
		bufferStr += '\n';
	}
	bufferStr += boldLine + '\n';
} // Done & debugged & tested

void FormatOutput::data2str(int mode) {
	if( mode == 1 ) {
		this->clearDataStr();
		int maxCol = this->dataSizeN[1];
		int maxRow = this->dataSizeN[0];
		std::string &bufferStr = this->dataStr;
		std::string boldLine(16*maxCol,'=');
		std::string thinLine(16*maxCol,'-');
		// print correspondent names in the first line
		for(auto name : this->namesVec) {
			this->dataStr = this->dataStr + name + "\t\t";
		}
		bufferStr += '\n';
		// append data to the buffer string
		for(int row=0; row<maxRow; ++row) {
			// append each row of data
			for(int col=0; col<maxCol; ++col) {
				// append each column of data in the row
				/***** For test: *****
				 *  std::cout << "[converting to string...] Row: " << row << ", column: " << col << ". Value: " << num2str(data[row][col]) << std::endl;
				 */
				// ATTENTION!!!
				// Data element for correspondent position (row, col) is data[col][row]
				bufferStr += num2str(data[col][row]) + "\t";
			}
			bufferStr += '\n';
		}
	}
	else if( mode == 0 ) {
		this->data2str();
	}
}

void FormatOutput::clearDataStr(){
	// clear the data buffered in "dataStr"
	this->dataStr = "";
} // Done

#endif