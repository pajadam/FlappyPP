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
	static const long MINOR  = 1;
	static const long BUILD  = 78;
	static const long REVISION  = 444;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 153;
	#define RC_FILEVERSION 1,1,78,444
	#define RC_FILEVERSION_STRING "1, 1, 78, 444\0"
	static const char FULLVERSION_STRING [] = "1.1.78.444";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 28;
	

}
#endif //VERSION_H
