

//#include "includes.h"

//This is the original entry point from NanoVFC 1.0 and is replaced with wWinMain in Source.cpp
//
//int NOT_main(int argc, char *argv[])
//{
//	//std::string newfilename = "outFile.txt";
//	mstrClass *p_mstrClass = new mstrClass();
//
//	std::string argv_filename1;
//	std::string argv_filename2;
//
//	int mode = 0;
//	if (argc > 1)
//	{
//		if (std::string(argv[1]) == "/D")
//		{
//			//std::cout << "delete mode?" << std::endl;
//			mode = DELETE;
//			argv_filename1.append(argv[2]);
//		}
//		else if (std::string(argv[1]) == "/M")
//		{
//			mode = MERGE;
//			argv_filename1.append(argv[2]);
//			argv_filename2.append(argv[3]);
//		}
//		else 
//		{
//			std::cout << "Incorrect arguments. '/D <filename>' for RXA-21 Delete Operation, '/M <outgoingfilename> <responsefilename>' to merge." << std::endl;
//			//system("pause");
//		}
//	}
//	else
//	{
//		std::cout << "Incorrect arguments. '/D <filename>' for RXA-21 Delete Operation, '/M <outgoingfilename> <responsefilename>' to merge." << std::endl;
//		//system("pause");
//	}
//	
//		
//
//	if (mode == DELETE)
//	{
//		std::cout << "DELETE MODE." << std::endl << "====================" << std::endl << std::endl;
//		std::string *p_filename1 = new std::string(argv_filename1);
//		//p_filename1->erase(p_filename1->find("."), p_filename1->length() - p_filename1->find("."));
//
//		std::string *p_delFileName = new std::string("DEL_");
//		p_delFileName->append(*p_filename1);
//		std::string *p_keepFileName = new std::string("OUT_");
//		p_keepFileName->append(*p_filename1);
//
//
//		
//
//		int h1 = p_mstrClass->newHLFile(&argv_filename1);
//		int h2 = p_mstrClass->newHLFile(p_keepFileName);
//		int h3 = p_mstrClass->newHLFile(p_delFileName);
//		p_mstrClass->openFileStream(h1, ENUM_IN);
//		p_mstrClass->openFileStream(h2, ENUM_OUT);
//		p_mstrClass->openFileStream(h3, ENUM_OUT);
//		//std::cout << "step 1" << std::endl;
//		p_mstrClass->parseFile(h1);
//		//std::cout << "step 2" << std::endl;
//		p_mstrClass->removeRXA21Deletes(h1, h2, h3);
//		//std::cout << "step 3" << std::endl;
//		p_mstrClass->writeFile(h2);
//		//std::cout << "step 4" << std::endl;
//		p_mstrClass->writeFile(h3);
//
//		system("pause");	
//		return 1;
//	}
//	else if (mode == MERGE)
//	{
//		std::cout << "MERGE MODE." << std::endl << "====================" << std::endl << std::endl;
//		//std::string *p_outputFileName = new std::string("merged.txt");
//		int h1 = p_mstrClass->newHLFile(&argv_filename1);
//		int h2 = p_mstrClass->newHLFile(&argv_filename2);
//		p_mstrClass->openFileStream(h1, ENUM_IN);
//		p_mstrClass->openFileStream(h2, ENUM_IN);
//		p_mstrClass->parseFile(h1);
//		p_mstrClass->parseFile(h2);
//		int newHandle = p_mstrClass->mergeFiles(h2, h1);
//		p_mstrClass->openFileStream(newHandle, ENUM_OUT);
//		p_mstrClass->writeFile(newHandle);
//
//		system("pause");
//		return 1;
//	}
//
//
//	return 0;
//}

