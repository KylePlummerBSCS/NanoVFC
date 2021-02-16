#ifndef _EXTERNALS_
#define _EXTERNALS_
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <map>
#endif

#ifndef _MSAPI_
#define _MSAPI_
#include <windows.h>      // For common windows data types and function headers
#define STRICT_TYPED_ITEMIDS
#include <shlobj.h>
#include <objbase.h>      // For COM headers
#include <shobjidl.h>     // for IFileDialogEvents and IFileDialogControlEvents
#include <shlwapi.h>
#include <knownfolders.h> // for KnownFolder APIs/datatypes/function headers
#include <propvarutil.h>  // for PROPVAR-related functions
#include <propkey.h>      // for the Property key APIs/datatypes
#include <propidl.h>      // for the Property System APIs
#include <strsafe.h>      // for StringCchPrintfW
#include <shtypes.h>      // for COMDLG_FILTERSPEC
#include <new>

#include <atlstr.h>
#endif


#ifndef _INTERNALS_
#define _INTERNALS_
#include "enum.h"
#include "HLFile.h"
#include "mstrClass.h"
#endif