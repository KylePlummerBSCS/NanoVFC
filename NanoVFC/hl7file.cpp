#include "includes.h"


///////////////////////////////////
// HL7 File Class Implementation //
///////////////////////////////////

//Construction/destruction
hlfile::hlfile(std::string *fn)
{
	mp_filename = fn;
	mp_msgVector = new msgvector();
	mp_trimmedMessages = new msgvector();
	
	//moved to open() function.
	//mp_hlFile = new std::fstream();
	//mp_hlFile->open(*fn, std::ios::in | std::ios::out);
	//this->parseFile();
	

	
	//this->removeRXA21Deletes();
	//this->textDump();
	//std::string newFilename("Out.txt");
	//this->writeFile(&newFilename);
	//std::string newTrimFilename("deletes.txt");
	//this->writeTrimFile(&newTrimFilename);
	//std::cout << "Finished: Instance new HL File" << std::endl;

}

hlfile::~hlfile()
{

}




//public functions
/* //DEPRECIATING
int hlfile::openFile(std::string *s)
{
	std::fstream *mp_newFileStream = new std::fstream();
	mp_newFileStream->open(*s, std::ios::in | std::ios::out);

	if (mp_newFileStream->is_open())
	{
		++m_fileHandleCount;
		mp_fileMap->insert(std::pair<int, std::fstream*>(m_fileHandleCount, mp_newFileStream));
		return m_fileHandleCount;
	}
	else
	{
		return -1;
	}

}


int hlfile::closeFile(int h)
{
	mp_fileMap->at(h)->close();
	return 1;
}
*/

int hlfile::openFileStream()
{
	std::cout << *mp_filename << std::endl;//remove later

	mp_hlFile = new std::fstream();
	mp_hlFile->open(*mp_filename, std::ios::in | std::ios::out | std::ios::trunc);
	//this->parseFile();
	if (mp_hlFile->is_open())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int hlfile::openFileStream(fileMode fm)
{
	switch (fm)
	{
	case ENUM_IN:
		mp_hlFile = new std::fstream();
		mp_hlFile->open(*mp_filename, std::ios::in);
		break;
	case ENUM_OUT:
		mp_hlFile = new std::fstream();
		mp_hlFile->open(*mp_filename, std::ios::out | std::ios::trunc);
		break;
	case INOUT:
		mp_hlFile = new std::fstream();
		mp_hlFile->open(*mp_filename, std::ios::out | std::ios::out);
		break;
	}
	
	if (mp_hlFile->is_open())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int hlfile::parseFile()
{
	//std::cout << "begin parse operation" << std::endl;
	mp_lineVector = new linevector();
	mp_str1 = new std::string();
	mp_str2 = new std::string();

	//std::cout << "parse step 2" << std::endl;
	int countmsg = 0; //remove later
	int countline = 0; //remove later
	int countseg = 0; //remove later

	/////////////////////////////
	// Begin parsing each line //
	/////////////////////////////
	while (std::getline(*mp_hlFile, *mp_str1))
	{
		if (!mp_str1->compare(0, 3, "MSH")) //0 returned on equal compare, so use ! to look for 0.
		{
			//std::cout << "push_back() messgae" << std::endl;
			++countmsg; //remove later
			mp_msgVector->push_back(mp_lineVector);
			mp_lineVector = new linevector();
			//std::cout << "finished push_back()" << std::endl;
		}

		mp_segMap = new segmap();
		int i = 0; //iterator for string
		int j = 0; //iterator for segments


		for (i; i < mp_str1->length(); ++i)
		{
			if (!mp_str1->compare(i, 1, ("|")))//0 returned on equal compare, so use ! to look for 0.
			{
				++countseg;//remove later
				mp_segMap->insert(std::pair<int, std::string*>(j, mp_str2));
				mp_str2 = new std::string();
				++j;

			}
			else
			{
				mp_str2->append(*mp_str1, i, 1);
			}

		}
		++countseg;//remove later
		mp_segMap->insert(std::pair<int, std::string*>(j, mp_str2));
		mp_str2 = new std::string();
		++countline;
		mp_lineVector->push_back(mp_segMap);


		mp_str1->clear();

	}
	++countmsg; //remove later
	mp_msgVector->push_back(mp_lineVector);
	mp_lineVector = new linevector();

	std::cout << "parsing complete: " << "Messages: " << countmsg << "  Lines: " << countline << "  segments: " << countseg << std::endl;
	return 1;
}

int hlfile::textDump()
{
	//output all
	//std::cout << "begin text dump:" << std::endl << std::endl << std::endl;

	msgvector::iterator msgIter;
	linevector::iterator lineIter;
	std::map<int, std::string*>::iterator mapIter;
	for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
	{
		for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
		{
			for (mapIter = (*lineIter)->begin(); mapIter != (*lineIter)->end(); ++mapIter)
			{
				if (mapIter != (*lineIter)->begin())
				{
					std::cout << "|";
				}
				std::cout << *(mapIter->second);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl;

	//std::cout << std::endl << std::endl << "Finished text dump" << std::endl;


return 1;
}

int hlfile::removeRXA21Deletes()
{
	//std::cout << "begin delete operation" << std::endl;
	msgvector::iterator msgIter;
	linevector::iterator lineIter;
	std::map<int, std::string*>::iterator mapIter;
	for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
	{
		for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
		{
			if (!(*lineIter)->begin()->second->compare(0, 3, "RXA"))
			{
				if (!(*lineIter)->at(21)->compare(0, 1, "D"))
				{
					msgvector::iterator deleteIter = msgIter;
					--msgIter;
					mp_trimmedMessages->push_back(*deleteIter);
					mp_msgVector->erase(deleteIter);
					break;
				}
			}
		}
	}
	//std::cout << "delete operation finished" << std::endl;
	return 1;
}
int hlfile::removeRXA21Deletes(hlfile *output, hlfile *deletes)
{
	//std::cout << "begin: hl7 file class removerxa21deletes function overloaded with 2 hFile parameters." << std::endl;
	hlfile *mp_deletes = deletes;
	hlfile *mp_keeps = output;
	msgvector::iterator msgIter;
	linevector::iterator lineIter;
	std::map<int, std::string*>::iterator mapIter;
	//std::cout << "step 1" << std::endl;
	for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
	{
		//std::cout << "step 2" << std::endl;
		for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
		{
			//std::cout << "step 3" << std::endl;
			if (!(*lineIter)->begin()->second->compare(0, 3, "RXA"))
			{
				//std::cout << "step 4" << std::endl;
				//std::cout << (*lineIter)->size() << std::endl;
				//std::cout << *(*lineIter)->at(20) << std::endl;
				if((*lineIter)->size() > 21)
				{
					if (!(*lineIter)->at(21)->compare(0, 1, "D")) //bugs out when RXA21 not included...
					{
						//std::cout << "step 5" << std::endl;
						msgvector::iterator deleteIter = msgIter;
						--msgIter;
						//mp_trimmedMessages->push_back(*deleteIter);
						mp_deletes->insertMSG(*deleteIter);
						mp_msgVector->erase(deleteIter);
						break;
					}				
				}
			}
		}
	}
	//std::cout << "step 6" << std::endl;
	for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
	{
		mp_keeps->insertMSG(*msgIter);
	}
	//std::cout << "delete operation finished" << std::endl;
	//std::cout << "end: hl7 file class removerxa21deletes function overloaded with 2 hFile parameters." << std::endl;
	return 1;
}

int hlfile::writeFile()
{
	//std::ofstream outFile;
	//outFile.open(*filename, std::ios::out);
	if (mp_hlFile->is_open())
	{

		msgvector::iterator msgIter;
		linevector::iterator lineIter;
		std::map<int, std::string*>::iterator mapIter;
		for (msgIter = mp_msgVector->begin(); msgIter != mp_msgVector->end(); ++msgIter)
		{
			for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
			{
				for (mapIter = (*lineIter)->begin(); mapIter != (*lineIter)->end(); ++mapIter)
				{
					if (mapIter != (*lineIter)->begin())
					{
						*mp_hlFile << "|";
					}
					*mp_hlFile << *(mapIter->second);
				}
				*mp_hlFile << std::endl;
			}
		}
	return 1;
	}
	else
	{
		std::cout << "unable to write to file. not open." << std::endl;
		return 0;
	}
	
	//outFile.close();
	
}

int hlfile::writeTrimFile(std::string *filename)
{
	std::ofstream outFile;
	outFile.open(*filename, std::ios::out);
	if (outFile.is_open())
	{

		msgvector::iterator msgIter;
		linevector::iterator lineIter;
		std::map<int, std::string*>::iterator mapIter;
		for (msgIter = mp_trimmedMessages->begin(); msgIter != mp_trimmedMessages->end(); ++msgIter)
		{
			for (lineIter = (*msgIter)->begin(); lineIter != (*msgIter)->end(); ++lineIter)
			{
				for (mapIter = (*lineIter)->begin(); mapIter != (*lineIter)->end(); ++mapIter)
				{
					if (mapIter != (*lineIter)->begin())
					{
						outFile << "|";
					}
					outFile << *(mapIter->second);
				}
				outFile << std::endl;
			}
		}
	return 1;
	}
	else
	{
		std::cout << "unable to write to file. not open." << std::endl;
		return 0;
	}
	
	outFile.close();
	
}

int hlfile::insertMSG(linevector *msg)
{
	mp_msgVector->push_back(msg);
	return 1;
}

linevector* hlfile::findMSH9(std::string *id)
{
	//std::cout << "begin delete operation" << std::endl;
	msgvector::iterator msgIter;
	linevector::iterator lineIter;
	std::map<int, std::string*>::iterator mapIter;
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
}

int hlfile::closeFileStream()
{
	if (mp_hlFile->is_open())
	{
		mp_hlFile->close();
	}
	if (mp_hlFile->is_open())
	{
		return 0;
	}
	else
	{
		return 1;
	}
	return -1;
}

