# CmdLineLog
Simple command line tracer for console applications (with colors)

#### Example of usage
''' 
	LOG_DEBUG(_T("This a debug test"));
	LOG_VERBOSE(_T("This a verbose test"));
	LOG_INFO(_T("This an info test"));
	LOG_WARN(_T("This a warning test"));
	LOG_ERROR(_T("This an error test"));
'''

'''
	CCmdLineLog::TraceDebug(_T("This a debug test"));
	CCmdLineLog::TraceVerbose(_T("This a verbose test"));
	CCmdLineLog::TraceInfo(_T("This an info test"));
	CCmdLineLog::TraceWarn(_T("This a warning test"));
	CCmdLineLog::TraceError(_T("This an error test"));
	'''
