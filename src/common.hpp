#pragma once

// shared AMX/SA:MP stuff
extern void** ppPluginData;
extern void* pAMXFunctions;
typedef void (*logprint_f)(const char* szFormat, ...);
extern logprint_f logprint;