//data source:https://datahub.io/core/s-and-p-500-companies-financials#resource-constituents-financials
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace std;

void ParseCSV(fstream &infile);

int main(){
	string sector;
	fstream input;
	input.open("/home/pi/Desktop/Data/constituents-financials.csv", ios::out);
	if(!input.is_open()){
		throw runtime_error("File could not be opened.");
		exit(1);
	}
	ParseCSV(input);
	input.close();
	//delete[] input;
	return 0;
}

void ParseCSV(fstream &infile){
	cout<<"Map.\n";
	int i =0;
	string line;
	string  sector;
	infile.ignore(1, '\n');
	vector<vector<string>> parsedCSV;
	while(getline(infile, line)){
		stringstream lineStream(line);
		string cell;
		vector<string> parsedRow;
		while(getline(lineStream, cell, ',')){
			parsedRow.push_back(cell);
		}
		parsedCSV.push_back(parsedRow);
	}
	//for (int i = 0; i < parsedCSV.size(); i++) { // printing the 2D vector.
      	//	for (int j = 0; j < parsedCSV[i].size(); j++){
      	//	cout << parsedCSV[i][j] << " ";
      	//	cout << endl;
   	//	}
	//}
	if(parsedCSV.empty()){cout<<"Empty"<<endl;}
	else{cout<<"Not Empty"<<endl;}
}
/*notes for larger values
 * Market cap values are long long int
 * EBITDA values are long long int
 */



