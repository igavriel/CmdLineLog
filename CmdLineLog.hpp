#ifndef __CMDLINELOG_H__
#define __CMDLINELOG_H__

#include <time.h>
#include <sys/timeb.h>

#ifndef NO_CMDLINE_LOG
	#define LOG_DEBUG	CCmdLineLog::TraceDebug
	#define LOG_VERBOSE CCmdLineLog::TraceVerbose
	#define LOG_INFO	CCmdLineLog::TraceInfo
	#define LOG_WARN	CCmdLineLog::TraceWarn
	#define LOG_ERROR	CCmdLineLog::TraceError
#endif //NO_CMDLINE_LOG

class CCmdLineLog
{
private:
	CCmdLineLog();
	CCmdLineLog(CCmdLineLog&);
	CCmdLineLog& operator= (CCmdLineLog&);

private:
	typedef enum LogColors
	{
		COLOR_DEBUG   = 0x0F, // WHITE
		COLOR_VERBOSE = 0x07, // GRAY
		COLOR_INFO    = 0x0A, // GREEN
		COLOR_WARN    = 0x0D, // PURPLE 
		COLOR_ERROR   = 0x0C, // RED
	} LogColors;

	static void CurrentTime(FILE* pOutFile)
	{	//build the time stamp
		static const UINT TIME_LENGTH = 24;
		struct _timeb tNow;
		_ftime64_s( &tNow );
		struct tm xTmNow = {0};
		localtime_s( &xTmNow, &tNow.time );
		TCHAR cTimeBuffer[TIME_LENGTH];
		size_t nSize = _tcsftime(cTimeBuffer, TIME_LENGTH, "%d/%m/%Y %H:%M:%S", &xTmNow);
		_stprintf_s (&cTimeBuffer[nSize], TIME_LENGTH-nSize, ".%03d", tNow.millitm);
		_ftprintf(pOutFile, cTimeBuffer);
	}

	static void LogHeader(FILE* pOutFile, LogColors eColor, TCHAR* szSeverity)
	{
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), eColor);
		CurrentTime(pOutFile);
		//			TIME    | PID | TID | SEVERITTY | Event Message
		_ftprintf(pOutFile, " | %4d | %4d | %-7s| ",
					GetCurrentProcessId(),
					GetCurrentThreadId(),
					szSeverity);
	}

public:
	static void TraceDebug(TCHAR* szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);

		LogHeader(stdout, COLOR_DEBUG, "DEBUG"); 
		_vftprintf(stdout, szFormat, args);
		va_end(args);
		std::cout << "\n";
	}
	static void TraceVerbose(TCHAR* szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);

		LogHeader(stdout, COLOR_VERBOSE, "VERBOSE"); 
		_vftprintf(stdout, szFormat, args);
		va_end(args);
		std::cout << "\n";
	}
	static void TraceInfo(TCHAR* szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);

		LogHeader(stdout, COLOR_INFO, "INFO"); 
		_vftprintf(stdout, szFormat, args);
		va_end(args);
		std::cout << "\n";
	}
	static void TraceWarn(TCHAR* szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);

		LogHeader(stdout, COLOR_WARN, "WARNING"); 
		_vftprintf(stdout, szFormat, args);
		va_end(args);
		std::cout << "\n";
	}
	static void TraceError(TCHAR* szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);

		LogHeader(stdout, COLOR_ERROR, "ERROR"); 
		_vftprintf(stdout, szFormat, args);
		va_end(args);
		std::cout << "\n";
	}
};

#endif //__CMDLINELOG_H__