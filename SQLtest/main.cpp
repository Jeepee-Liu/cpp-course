#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // std::rand()
#include <ctime> // std::time() for seeding
#include <testPrint.h> // Run the code with testprint Debug
#include <formatOutput.h>
#include <SQLAPI.h>
#include <pgAPI.h>
#include <libsqlapiu.a>

using namespace std;

int main(int argc, char *argv[]) {
	TestPrint tp; // Run with test print
/* original main program
	FormatOutput fo;
	if( !fo.setFileDir("test.txt") ) {
		std::cout << "Unable to open or create file!" << std::endl;
		return 1;
	}
	double buffer;
	vector<double> doubleVec;

	cout << "Please input some integers and end with CTRL+D:" << endl;
	while(std::cin >> buffer) {
		doubleVec.push_back(buffer);
	}
	cout << doubleVec.size() << " element(s) are input in total." << endl;
	fo.appendData("var_1", doubleVec);
	std::reverse(doubleVec.begin(), doubleVec.end());
	fo.appendData("var_rev_2", doubleVec);
	fo.printData();
	if( !fo.writeData() ) {
		cout << "cannot write data!" << endl;
		return 1;
	}
*/
	SAConnection con; // create connection object
	try {
		// connect to database
		// in this example it is Oracle,
		// but can also be Sybase, Informix, DB2
		// SQLServer, InterBase, SQLBase and ODBC
		con.Connect(
			"data",     // database name
			"datactrl",   // user name
			"05141995000",   // password
			SA_PostgreSQL_Client);
		cout << "We are connected!\n";
		// Disconnect is optional
		// autodisconnect will ocur in destructor if needed
		con.Disconnect();
		cout << "We are disconnected!\n";
	}
	catch (SAException &x) {
		// SAConnection::Rollback()
		// can also throw an exception
		// (if a network error for example),
		// we will be ready
		try {
			// on error rollback changes
			con.Rollback();
		}
		catch(SAException &y) {
		}
		// print error message
		cout << (const char *) x.ErrText() << endl;
	}
	tp.promptBlock("Finished!");
	return 0;
}