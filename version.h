#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "07";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2017";
	static const char UBUNTU_VERSION_STYLE[] =  "17.06";
	
	//Software Status
	static const char STATUS[] =  "Custom";
	static const char STATUS_SHORT[] =  "indev";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 2;
	static const long BUILD  = 146;
	static const long REVISION  = 778;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 304;
	#define RC_FILEVERSION 1,2,146,778
	#define RC_FILEVERSION_STRING "1, 2, 146, 778\0"
	static const char FULLVERSION_STRING [] = "1.2.146.778";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 46;
	

}
#endif //VERSION_H
