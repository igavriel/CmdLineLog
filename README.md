# CmdLineLog
Simple command line tracer for console applications (with colors)

#### Example of usage
```
int i = 0;
LOG_DEBUG(_T("This a debug test: %d"), i++);
LOG_VERBOSE(_T("This a verbose test: %d"), i++);
LOG_INFO(_T("This an info test: %d"), i++);
LOG_WARN(_T("This a warning test: %d"), i++);
LOG_ERROR(_T("This an error test: %d"), i++);

CCmdLineLog::TraceDebug(_T("This a debug test: %d"), i++);
CCmdLineLog::TraceVerbose(_T("This a verbose test: %d"), i++);
CCmdLineLog::TraceInfo(_T("This an info test: %d"), i++);
CCmdLineLog::TraceWarn(_T("This a warning test: %d"), i++);
CCmdLineLog::TraceError(_T("This an error test: %d"), i++);
```
