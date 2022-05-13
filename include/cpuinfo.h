#ifndef CPUINFO_H
#define CPUINFO_H

#include <vector>
#include <string>

#include "systemcommand.h"

#ifndef _WIN32
    #error This library heavily uses wmic.exe, which is only available on Win32 platforms
#endif

class CPUInfo
{
public:
	CPUInfo::CPUInfo(const std::vector<std::string> &rawData, int cpuNumber);
    std::string name() const;
    std::string manufacturer() const;
	std::string numberOfCores() const;
    std::string architecture() const;
    std::string L2CacheSize() const;
    std::string L3CacheSize() const;
	std::string currentClockSpeed() const;
	int cpuNumber() const;

private:
    std::string _name;
    std::string _manufacturer;
    std::string _numberOfCores;
    std::string _architecture;
    std::string _L2CacheSize;
    std::string _L3CacheSize;
	int _cpuNumber;

    
    std::string getArchitecture(std::string &dataWidth) const;
	
    

	
    static const std::string NAME_IDENTIFIER_STRING;
    static const std::string NUMBER_OF_CORES_IDENTIFIER_STRING;
    static const std::string MANUFACTURER_IDENTIFIER_STRING;
	static const std::string CLOCK_SPEED_QUERY_STRING;
    static const std::string CURRENT_CLOCK_SPEED_IDENTIFIER_STRING;
    static const std::string ARCHITECTURE_IDENTIFIER_STRING;
    static const std::string L2_CACHE_SIZE_IDENTIFIER_STRING;
    static const std::string L3_CACHE_SIZE_IDENTIFIER_STRING;
};

#endif