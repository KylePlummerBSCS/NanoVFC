#include "includes.h"

//forward dec of hlfile class necessary?
class hlfile;

///////////
// Enums //
///////////
enum mode
{
	INVALID = 0,	// 0
	ENUM_DELETE,			// 1
	MERGE,			// 2
	TEST
};

enum fileMode
{
	ENUM_IN = 1,			//1
	ENUM_OUT,			//2
	INOUT			//3
};









//////////////
// typedefs //
//////////////

typedef std::vector<std::vector<std::map<int, std::string*>*>*> msgvector;
typedef std::vector<std::map<int, std::string*>*> linevector;
typedef std::map<int, std::string*> segmap;
typedef std::map<int, hlfile*> filemap;