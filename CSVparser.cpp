#include <iostream>
#include "CSVParser.h"

using namespace std;

int main()
{
    //string file_location = "C:\\Users\\jw051\\Downloads\\constituents-financials_csv.csv";
    string file_location = "constituents-financials_csv.csv";
    fstream data(file_location);
    if (data.is_open()) {
        CSVParser fileParser;
        fileParser.read_col_names(data);
        fileParser.detect_col_datatypes(data);
    }
    else {
        cout << "Unable to open file." << endl;
        exit(2);
    }
    data.close();
    return 0;
}

