#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "25";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.03";
	
	//Software Status
	static const char STATUS[] =  "Custom";
	static const char STATUS_SHORT[] =  "indev";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 139;
	static const long REVISION  = 754;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 291;
	#define RC_FILEVERSION 1,2,139,754
	#define RC_FILEVERSION_STRING "1, 2, 139, 754\0"
	static const char FULLVERSION_STRING [] = "1.2.139.754";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 39;
	

}
#endif //VERSION_H
