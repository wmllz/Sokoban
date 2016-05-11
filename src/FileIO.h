#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

//自定义类型
enum FileFormat{
	FORMAT_TXT,
	FORMAT_CSV
};

typedef deque<string> CSVRow;
typedef deque<CSVRow> CSVTable;
typedef	string	TXTRow;
typedef deque<TXTRow> TXTContent;

class FileIO{
public:

	FileIO(const string &fileName, FileFormat format);
	~FileIO(){};

	void open();
	void save();

	void readTXTfile(ifstream &fs);
	void readCSVfile(ifstream &fs);

	TXTRow getRowFromTXT(ifstream &fs);
	CSVRow getRowFromCSV(ifstream &fs);

	void writeTXTfile(ofstream &fs);
	void writeCSVfile(ofstream &fs);

	void writeRowToTXT(ofstream &fs, TXTRow &row);
	void writeRowToCSV(ofstream &fs, CSVRow &row);

	CSVTable getTable(){ return m_table; }


private:
	string m_fileName;
	FileFormat m_fileFormat;
	CSVTable m_table;
	TXTContent m_content;
};

#endif