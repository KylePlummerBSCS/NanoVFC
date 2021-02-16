#include "includes.h"
///////////////////////////
// mstr Class Definition //
///////////////////////////

class mstrClass
{
public:
	//construction/destruction
	mstrClass();
	~mstrClass();

	//piublic functions
	int newHLFile(std::string *fn);
	int testSearch(int h); //remove later
	int mergeFiles(int h, int j);
	int parseFile(int h);
	int openFileStream(int h, fileMode fm);
	int closeFileStream(int h);
	int removeRXA21Deletes(int h, int j, int k);
	int writeFile(int h);

	//public members


private:
	//private functions


	//private members
	int m_fileHandleCount;
	filemap *mp_fileMap;

};