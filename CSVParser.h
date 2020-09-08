#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

class CSVParser
{
public: 
	vector<string> read_col_names(fstream& infile);
	void detect_col_datatypes(fstream& infile);
private:
	vector<string> colnames;
	vector<string> col_vals;
};

//Reads column names into vector
vector<string> CSVParser::read_col_names(fstream& infile) {
	ofstream outfile;
	
	string field;
	getline(infile, field);
	stringstream sstream(field);

	while (sstream.good()) {
		getline(sstream, field, ',');
		colnames.push_back(field);
	}

	return colnames;
}
	
void CSVParser::detect_col_datatypes(fstream& infile) {
	infile.ignore(100000, '\n');
	string col_val;
	int uncasted=0, casted = 0;
	getline(infile, col_val);
	stringstream sstream(col_val);
	try{	
	while (infile.good()) {
		getline(sstream, col_val, ',');
		col_vals.push_back(col_val);
		}
	}
	catch(const std::bad_alloc&){
		cout<<"badd_alloc exception. Aborted."<<endl;
		exit(3);
	}

	for (auto it = col_vals.begin(); it != col_vals.end(); it++) {
		try {
			double converted = stod(*it);
			++casted;
			//printf("Sucessfully casted %f to double\n", casted);
		}
		catch (...) {
			//cout << "Unable to cast to double." << endl;
			++uncasted;
		}
	}
	printf("Successfully casted: %d values.\nUnable to cast: %d values.", casted, uncasted);
}

