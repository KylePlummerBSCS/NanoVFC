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

//DEPRECIATED
//int mstrClass::mergeFiles(int h, int j)
//{
//	std::cout << "begin merging files" << std::endl;
//	
//	std::string *fn = new std::string("merged_files.txt");
//	int k = this->newHLFile(fn);
//	int cursor = -1;
//
//	msgvector::iterator msgIter1, msgIter2;
//	linevector::iterator lineIter1, lineIter2, lineIter3;
//	std::map<int, std::string*>::iterator mapIter1, mapIter2;
//
//	for (msgIter1 = mp_fileMap->at(h)->mp_msgVector->begin(); msgIter1 != mp_fileMap->at(h)->mp_msgVector->end(); ++msgIter1)
//	{
//		for (lineIter1 = (*msgIter1)->begin(); lineIter1 != (*msgIter1)->end(); ++lineIter1)
//		{
//			if (!(*lineIter1)->begin()->second->compare(0, 3, "MSH"))
//			{
//				++cursor;
//				mp_fileMap->at(k)->mp_msgVector->push_back(*msgIter1);
//				std::string *id = new std::string(*(*lineIter1)->at(9));
//				for (msgIter2 = mp_fileMap->at(j)->mp_msgVector->begin(); msgIter2 != mp_fileMap->at(j)->mp_msgVector->end(); ++msgIter2)
//				{
//					for (lineIter2 = (*msgIter2)->begin(); lineIter2 != (*msgIter2)->end(); ++lineIter2)
//					{
//						if (!(*lineIter2)->begin()->second->compare(0, 3, "MSH"))
//						{
//							if (!(*lineIter2)->at(9)->compare(*id))
//							{
//								/*
//								//ORIGINAL BEFORE CHANGE DUE TO VECTOR ITERATION ASSERTION ERROR
//								std::cout << "found match!" << std::endl;
//								for (lineIter3 = (*msgIter2)->begin(); lineIter3 != (*msgIter2)->end(); ++lineIter3)
//								{
//									std::cout << "pushing back line" << std::endl;
//									mp_fileMap->at(k)->mp_msgVector->at(cursor)->push_back(*lineIter3);         //it's this line that breaks it...
//									
//								}
//								*/
//
//								//std::cout << "pushing back line" << std::endl;
//								mp_fileMap->at(k)->insertMSG(*msgIter2);
//							}
//						}
//					}
//				}
//			delete(id);
//			}
//		}
//	}
//	std::cout << "Merge Complete." << std::endl;
//	return k;
//}

/*
	//std::cout << "begin delete operation" << std::endl;

	for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
	{
		for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
		{
			if (!(*lineIter)->begin()->second->compare(0, 3, "MSH"))
			{
				if (!(*lineIter)->at(9)->compare(0, 1, *id))
				{
					return *msgIter;
					break;
				}
			}
		}
	}
*/



