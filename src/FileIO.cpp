#include "FileIO.h"


FileIO::FileIO(const string &fileName, FileFormat format){
	init(fileName, format);
}


/*
**功能：用于初始化
*/
void FileIO::init(const string &fileName, FileFormat format){
	m_fileName = fileName;
	m_fileFormat = format;
	m_position = 0;
}

/*
**功能：用于打开文件文件流，并且读取流中的数据
*/
void FileIO::open(int position){
	ifstream input(m_fileName.c_str(), ios::in);

	if (!input.is_open()){
		cout << "can't open the file!" << endl;
		return;
	}

	input.seekg(position, input.beg);
	switch (m_fileFormat){
	case FORMAT_TXT:
		readTXTfile(input);
		break;
	case FORMAT_CSV:
		readCSVfile(input);
		break;
	default:
		break;
	}
	input.close();
}

/*
**功能：用于打开文件文件流，并且将数据保存到文件中
*/
void FileIO::save(){
	ofstream output(m_fileName.c_str(), ios::out);

	if (!output.is_open()){
		cout << "can't open the file!" << endl;
		return;
	}

	switch (m_fileFormat){
	case FORMAT_CSV:
		writeCSVfile(output);
		break;
	case FORMAT_TXT:
		writeTXTfile(output);
		break;
	default:
		break;
	}
	output.close();
}

/*
**功能：从txt文件中读取数据，将读取的每一行数据存入m_content中
**@param	fs	打开的txt文件流
*/
void FileIO::readTXTfile(ifstream &fs){

	TXTRow row;
	while (true){
		if (fs.eof()){
			return;
		}
		row = getRowFromTXT(fs);

		if (!row.empty()){
			m_content.push_back(row);
		}
	}
}

/*
**功能：从csv文件中读取数据，将读取的每一行数据存入m_table中
**@param	fs	打开的csv文件流
*/
void FileIO::readCSVfile(ifstream &fs){

	CSVRow row;

	m_table.erase(m_table.begin(), m_table.end());
	while (true){
		if (fs.eof()){
			return;
		}
		row = getRowFromCSV(fs);

		if (!row.empty()){
			if (row.size() == 1){
				return;
			}
			m_table.push_back(row);
		}

	}
}

/*
**功能：从txt文件中都去一行
**@param	fs	打开的txt文件流
**@return	row	一行数据
*/
TXTRow FileIO::getRowFromTXT(ifstream &fs){

	TXTRow row;
	getline(fs, row);
	m_position = fs.tellg();
	return row;
}

/*
**功能：从打开的csv文件流中读取一行数据，并将数据的每个域进入队列里
**@param	fs	打开的文件流
**@return	一行数据
*/
CSVRow FileIO::getRowFromCSV(ifstream &fs){

	string line;
	CSVRow row;
	size_t pos = 0;
	size_t prePos = 0;

	getline(fs, line);

	m_position = fs.tellg();
	while (line.size() > 0 && pos != line.npos){
		if (pos > 0){
			prePos = pos + 1;
		}

		pos = line.find(',', prePos);
		row.push_back(line.substr(prePos, pos - prePos));
	}

	return row;
}

void FileIO::writeTXTfile(ofstream &fs){
	TXTContent::iterator it;
	for (it = m_content.begin(); it != m_content.end(); it++){
		writeRowToTXT(fs, *it);
	}
}

/*
**功能：将m_table中的数据保存到csv文件中
**@param	fs	打开的输出文件流
*/
void FileIO::writeCSVfile(ofstream &fs){
	CSVTable::iterator it;
	for (it = m_table.begin(); it != m_table.end(); it++){
		writeRowToCSV(fs, *it);
	}
}

/*
**功能：将一行数据输入csv文件中
**@param	fs	打开的输出文件流文件
**@param	row	待保存的一行数据
*/
void FileIO::writeRowToTXT(ofstream &fs, TXTRow &row){
	fs << row << endl;
}

/*
**功能：将一行数据输入csv文件中
**@param	fs	打开的输出文件流文件
**@param	row	待保存的一行数据
*/
void FileIO::writeRowToCSV(ofstream &fs, CSVRow &row){
	CSVRow::iterator it, temp;

	for (it = row.begin(); it != row.end(); it++){
		fs << *it;
		temp = it;
		temp++;
		if (temp != row.end()){
			fs << ',';
		}
	}
	fs << endl;
}
