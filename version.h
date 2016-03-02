#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "02";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.03";
	
	//Software Status
	static const char STATUS[] =  "Custom";
	static const char STATUS_SHORT[] =  "indev";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 1;
	static const long BUILD  = 68;
	static const long REVISION  = 385;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 133;
	#define RC_FILEVERSION 1,1,68,385
	#define RC_FILEVERSION_STRING "1, 1, 68, 385\0"
	static const char FULLVERSION_STRING [] = "1.1.68.385";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 18;
	

}
#endif //VERSION_H
