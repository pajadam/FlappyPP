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
	static const long BUILD  = 142;
	static const long REVISION  = 767;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 296;
	#define RC_FILEVERSION 1,2,142,767
	#define RC_FILEVERSION_STRING "1, 2, 142, 767\0"
	static const char FULLVERSION_STRING [] = "1.2.142.767";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 42;
	

}
#endif //VERSION_H
