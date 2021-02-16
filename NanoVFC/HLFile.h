#include "includes.h"
///////////////////////////////
// HL7 File Class Definition //
///////////////////////////////

class hlfile
{
	friend class mstrClass;

public:
	//construction/destruction
	//hlfile(std::fstream *a);
	hlfile(std::string *fn);
	~hlfile();


	//public members


	//public functions
	int openFile(std::string *s);
	int openFileStream();
	int openFileStream(fileMode fm);
	//int closeFile(int h);
	int parseFile();
	int textDump();
	int removeRXA21Deletes();
	int removeRXA21Deletes(hlfile *output, hlfile *deletes);
	int writeFile();
	int writeTrimFile(std::string *filename);
	int insertMSG(linevector *msg);
	linevector* findMSH9(std::string *id);
	int closeFileStream();
	


private:
	//private members
	std::fstream *mp_hlFile;
	msgvector *mp_msgVector;
	msgvector *mp_trimmedMessages;
	linevector *mp_lineVector;
	segmap *mp_segMap;
	std::string *mp_str1;
	std::string *mp_str2;
	std::string *mp_filename;

	//private functions



};