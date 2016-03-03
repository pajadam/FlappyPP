#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.03";
	
	//Software Status
	static const char STATUS[] =  "Custom";
	static const char STATUS_SHORT[] =  "indev";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 124;
	static const long REVISION  = 671;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 260;
	#define RC_FILEVERSION 1,2,124,671
	#define RC_FILEVERSION_STRING "1, 2, 124, 671\0"
	static const char FULLVERSION_STRING [] = "1.2.124.671";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 24;
	

}
#endif //VERSION_H
