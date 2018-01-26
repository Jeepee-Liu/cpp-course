#ifndef FORMAT_H
#define FORMAT_H

class Format {

public:

		// Type definitions
	typedef int AtomNumT;
	typedef int ResNumT;
	

/** DATA OF FIRST TWO RESIDUES (INPUT)

0         1  2   3   4  5        6       7       8      9    10             11

ATOM      1  N   MET I  20     -10.466  35.714   7.911  0.50 34.27           N  
ATOM      2  CA  MET I  20     -10.571  34.318   8.221  0.50 33.85           C  
ATOM      3  C   MET I  20      -9.332  33.656   7.891  0.50 32.74           C  
ATOM      4  O   MET I  20      -8.795  33.708   6.772  0.50 31.26           O  
ATOM      5  CB  MET I  20     -11.706  33.708   7.388  0.50 35.75           C  
ATOM      6  CG  MET I  20     -12.198  32.375   7.874  0.50 38.31           C  
ATOM      7  SD  MET I  20     -13.086  31.484   6.642  0.50 42.53           S  
ATOM      8  CE  MET I  20     -13.638  29.964   7.361  0.50 41.01           C
ATOM      9  N   LYS I  21      -8.810  32.995   8.643  1.00 32.12           N  
ATOM     10  CA  LYS I  21      -7.582  32.421   8.271  1.00 31.45           C  
ATOM     11  C   LYS I  21      -7.920  30.950   7.852  1.00 29.96           C  
ATOM     12  O   LYS I  21      -8.935  30.409   8.245  1.00 31.83           O  
ATOM     13  CB  LYS I  21      -6.889  32.675   9.574  1.00 30.12           C  
ATOM     14  CG  LYS I  21      -5.512  32.231   9.676  1.00 27.08           C  
ATOM     15  CD  LYS I  21      -4.894  32.641  10.980  1.00 25.13           C  
ATOM     16  CE  LYS I  21      -3.448  32.232  11.041  1.00 23.21           C  
ATOM     17  NZ  LYS I  21      -2.866  32.403  12.366  1.00 24.87           N 
...

*/

	struct InputT {
		const int idCol = 0;
		const int atomNoCol = 1;
		const int atomTypeCol = 2;
		const int resNameCol = 3;
		const int resIdxCol = 5;
		const int atomXPosCol = 6;
		const int atomYPosCol = 7;
		const int atomZPosCol = 8;
		const int atomNameCol = 11;
	} input;

/**OUTPUT

***********
* Residue *
***********

0    1    2   3     4     5

ATOM MET 33.0 2.334 3.544 2.455
...

***************
* Interaction *
***************

0   1 2   3     4

HAR 0 1 100.0   1.2
REP 0 2   1.0   2.3
LJ  1 3   1.0  44.5
...

 */

	struct OutputT {
		const int idCol = 0;
		const int resNameCol = 1;
		const int resMassCol = 2;
		const int resXPosCol = 3;
		const int resYPosCol = 4;
		const int resZPosCol = 5;
		const int interNo1Col = 1;
		const int interNo2Col = 2;
		const int interMagnCol = 3;
		const int interDistCol = 4;
	} outputDir;

};

#endif