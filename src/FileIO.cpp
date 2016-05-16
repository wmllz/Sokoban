#include "FileIO.h"


FileIO::FileIO(const string &fileName, FileFormat format){
	init(fileName, format);
}


/*
**���ܣ����ڳ�ʼ��
*/
void FileIO::init(const string &fileName, FileFormat format){
	m_fileName = fileName;
	m_fileFormat = format;
	m_position = 0;
}

/*
**���ܣ����ڴ��ļ��ļ��������Ҷ�ȡ���е�����
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
**���ܣ����ڴ��ļ��ļ��������ҽ����ݱ��浽�ļ���
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
**���ܣ���txt�ļ��ж�ȡ���ݣ�����ȡ��ÿһ�����ݴ���m_content��
**@param	fs	�򿪵�txt�ļ���
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
**���ܣ���csv�ļ��ж�ȡ���ݣ�����ȡ��ÿһ�����ݴ���m_table��
**@param	fs	�򿪵�csv�ļ���
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
**���ܣ���txt�ļ��ж�ȥһ��
**@param	fs	�򿪵�txt�ļ���
**@return	row	һ������
*/
TXTRow FileIO::getRowFromTXT(ifstream &fs){

	TXTRow row;
	getline(fs, row);
	m_position = fs.tellg();
	return row;
}

/*
**���ܣ��Ӵ򿪵�csv�ļ����ж�ȡһ�����ݣ��������ݵ�ÿ������������
**@param	fs	�򿪵��ļ���
**@return	һ������
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
**���ܣ���m_table�е����ݱ��浽csv�ļ���
**@param	fs	�򿪵�����ļ���
*/
void FileIO::writeCSVfile(ofstream &fs){
	CSVTable::iterator it;
	for (it = m_table.begin(); it != m_table.end(); it++){
		writeRowToCSV(fs, *it);
	}
}

/*
**���ܣ���һ����������csv�ļ���
**@param	fs	�򿪵�����ļ����ļ�
**@param	row	�������һ������
*/
void FileIO::writeRowToTXT(ofstream &fs, TXTRow &row){
	fs << row << endl;
}

/*
**���ܣ���һ����������csv�ļ���
**@param	fs	�򿪵�����ļ����ļ�
**@param	row	�������һ������
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
