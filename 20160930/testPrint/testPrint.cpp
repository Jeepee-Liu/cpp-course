#ifdef _TEST_PRINT_H

TestPrint::TestPrint(){
	// Make Notification that
	this->newLine();
	this->promptBlock("This code is run with test prints.");
	this->newLine();
	this->startClock = std::clock();
}

void TestPrint::anyLine(int len, char anyChar) {
	std::string anyCharStr(len,anyChar);
	std::cout << anyCharStr << std::endl;
}

void TestPrint::starLine(int len){
	this->anyLine(len,'*');
}

void TestPrint::barLine(int len){
	this->anyLine(len,'-');
}

void TestPrint::slashLine(int len) {
	this->anyLine(len,'/');
}

void TestPrint::sharpLine(int len) {
	this->anyLine(len,'#');
}

void TestPrint::newLine(void){
	// a substitute to "std::endl"
	std::cout << std::endl;
}

void TestPrint::promptBlock(const char* promptStr){
	this->newLine();
	this->starLine(40);
	std::cout << "**\n**  " << promptStr << "\n**" << std::endl;
	this->starLine(40);
	this->newLine();
}

void TestPrint::promptBlock(void) {
	this->promptBlock("ATTENTION !!!");
}

void TestPrint::printTimeElapsed(void){
	std::cout << "**  Time elapsed : " << std::fixed
	<< this->timeElapsed() << " sec" << std::endl;
}

double TestPrint::timeElapsed(void){
	auto curClock = std::clock();
	return (1.0 * (curClock - this->startClock)) / CLOCKS_PER_SEC;
}

#endif