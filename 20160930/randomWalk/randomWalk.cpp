#ifdef RANDOM_WALK_H

/*
const double RandomWalk::sqrt2 = 1.4142135623730951;
const double RandomWalk::pi = 3.14159265358979323846;
*/

RandomWalk::RandomWalk(int stepN, double stepLength, std::string fileName, int avgN, double pWalk){
	std::srand(std::time(0));
	this->fo.open(fileName);
	char title[200] = {0};
	char firstLine[200] = {0};
	std::sprintf(title,
		"%7s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s",
		"index", "x", "x_err", "y", "y_err", "dist", "dist_err");
	std::sprintf(firstLine,
		"%7i\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f",
		0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	fo << title << std::endl << firstLine << std::endl;
	this->stepN = stepN;
	this->stepLength = stepLength;
	this->avgN = avgN;
	this->pWalk = pWalk;
} // 

void RandomWalk::run(char mode) {
	double* xs = new double[this->avgN];
	double* ys = new double[this->avgN];
	double* ds = new double[this->avgN];
	double* avgData; // {avgX, errX, avgY, errY, avgD, errD}
	for( int i=1; i != this->stepN+1; ++i ) {
		for( int j=0; j != this->avgN; ++j ) {
			// One output every avgN data
			this->move(mode);
			this->appendMove(j, xs, ys, ds);
		}
		avgData = calculateData(xs, ys, ds);
		this->writeData(i, avgData);
		if( i%10 == 0 ) {
			std::cout << "Now executing loop: "  << std::setw(8)
				<< i << '/' << this->stepN << " [ "
				<< std::setprecision(6) << ((double)i)/((double)this->stepN) *100 << "% ] " << std::endl;
		}
	}
	delete[] xs;
	delete[] ys;
	delete[] ds;
	delete[] avgData;
}

void RandomWalk::end() {
	this->fo.close();
} // Done

/* private */
void RandomWalk::move(char mode){
	double indicator = 0;
	double deg = 0;
	double &x = this->xPos;
	double &y = this->yPos;
	double componentLength = this->stepLength;
	switch (mode) {
		case 'p': // probably walk half length
			indicator = ((double) std::rand())/(double)RAND_MAX;
			componentLength = this->stepLength;
			if( indicator > this->pWalk ) {
				componentLength *= 0.5;
			}
			deg = 2*this->pi* std::rand()/(double)RAND_MAX;
			x += componentLength * std::cos(deg);
			y += componentLength * std::sin(deg);
			break;
		case 'u':
			deg = 2*pi* std::rand()/(double)RAND_MAX;
			x += componentLength * std::cos(deg);
			y += componentLength * std::sin(deg);
			break;
		default :
			componentLength = this->stepLength / this->sqrt2;
			if( indicator > this->pWalk ) {
				componentLength *= 0.5;
			}
			break;
	}
	x += componentLength * (( 2*(double) std::rand() ) / RAND_MAX - 1);
	y += componentLength * (( 2*(double) std::rand() ) / RAND_MAX - 1);
} // Done

void RandomWalk::appendMove(int j, double* xs, double* ys, double* ds) {
	xs[j] = this->xPos;
	ys[j] = this->yPos;
	ds[j] = this->getDistance();
} // Done

double* RandomWalk::calculateData(double* xs, double* ys, double* ds) {
	double* avgData = new double[6];
	avgData[0] = this->average(xs);
	avgData[1] = this->stdDiv(xs);
	avgData[2] = this->average(ys);
	avgData[3] = this->stdDiv(ys);
	avgData[4] = this->average(ds);
	avgData[5] = this->stdDiv(ds);
	return avgData;
} // Done

double RandomWalk::average(double* vs) {
	double sum = 0;
	for (int i=0; i != this->avgN; ++i) {
		sum += vs[i];
	}
	return ( sum / this->avgN );
} // Done

double RandomWalk::stdDiv(double* vs) {
	double average = this->average(vs);
	double sqSum = 0;
	for (int i=0; i != this->avgN; ++i) {
		sqSum += (vs[i]-average)*(vs[i]-average);
	}
	return std::sqrt(sqSum/this->avgN);
} // Done

double RandomWalk::getDistance(){
	double x = this->xPos;
	double y = this->yPos;
	return std::sqrt( x*x + y*y );
} // Done

void RandomWalk::writeData(int index, double *avgData){
	char iCharPtr[200]={0};
	std::sprintf(iCharPtr,"%7i\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f",
		index, avgData[0], avgData[1], avgData[2], avgData[3], avgData[4], avgData[5]);
	this->fo << iCharPtr << std::endl;
	//this->fo << index << std::setw(16) << xCharPtr << std::setw(16) << yCharPtr << std::setw(16) << dCharPtr << std::endl;
} // Done

#endif