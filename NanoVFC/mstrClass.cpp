#include "includes.h"

///////////////////////////////
// mstr Class Implementation //
///////////////////////////////

mstrClass::mstrClass()
{
	//std::cout << "begin mstrClass constructor" << std::endl;
	mp_fileMap = new filemap();
	m_fileHandleCount = 0;
	//std::cout << "finished mstrClass constructor" << std::endl;
}

int mstrClass::newHLFile(std::string *fn)
{
	hlfile *mp_newHLFile = new hlfile(fn);
	++m_fileHandleCount;
	mp_fileMap->insert(std::pair<int, hlfile*>(m_fileHandleCount, mp_newHLFile));
	std::cout << "HL7 File instantiated. Handle: " << m_fileHandleCount << "  Filename: " << *fn << std::endl << std::endl;
	return m_fileHandleCount;
	
}


int mstrClass::parseFile(int h)
{
	mp_fileMap->at(h)->parseFile();
	return 1;
}

int mstrClass::openFileStream(int h, fileMode fm)
{
	if (mp_fileMap->at(h)->openFileStream(fm))
	{
		return 1;
	}
	else 
	{
		std::cout << "file didn't open. Handle: " << h << std::endl;
		return 0;
	}
}

int mstrClass::closeFileStream(int h)
{
	mp_fileMap->at(h)->closeFileStream();
	return 1;
}

int mstrClass::removeRXA21Deletes(int h, int j, int k)
{
	mp_fileMap->at(h)->removeRXA21Deletes(mp_fileMap->at(j), mp_fileMap->at(k));
	return 1;
}

int mstrClass::writeFile(int h)
{
	mp_fileMap->at(h)->writeFile();
	return 1;
}



/*
int mstrClass::testSearch(int h)
{
	std::string *mp_teststring = new std::string("1051306771");
	linevector *mp_linevectortest = mp_fileMap->at(h)->findMSH9(mp_teststring);
	mp_teststring->append(".txt");
	int handle = this->newHLFile(mp_teststring);
	mp_fileMap->at(handle)->writeFile(mp_teststring);
	return 1;
}
*/
