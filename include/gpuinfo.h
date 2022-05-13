#ifndef GPUINFO_H
#define GPUINFO_h

#include <vector>
#include <string>

#include "systemcommand.h"

#ifndef _WIN32
#error This library heavily uses wmic.exe, which is only available on Win32 platforms
#endif

class GPUInfo
{
public:
	GPUInfo::GPUInfo(const std::vector<std::string> &rawData, int cpuNumber);
    std::string name() const;
    std::string manufacturer() const;
    
   
    std::string driverVersion() const;
    std::string videoArchitecture() const;
   
    std::string videoProcessor() const;
	int gpuNumber() const;

private:
    std::string _name;
    std::string _manufacturer;
   
    
    
    std::string _driverVersion;
    std::string _videoArchitecture;
   
    
    std::string _videoProcessor;
	int _gpuNumber;

    std::string getVideoArchitecture(const std::string &videoArchitectureString) const;
    std::string getVideoMemoryType(const std::string &videoMemoryTypeString) const;

    

    static const std::string NVIDIA_IDENTIFIER_STRING;
    static const std::string INTEL_IDENTIFIER_STRING;
    static const std::string AMD_IDENTIFIER_STRING;
    static const std::string NAME_IDENTIFIER_STRING;
    static const std::string MANUFACTURER_IDENTIFIER_STRING;
    static const std::string ADAPTER_RAM_IDENTIFIER_STRING;
    static const std::string REFRESH_RATE_IDENTIFIER_STRING;
    static const std::string DRIVER_VERSION_IDENTIFIER_STRING;
    static const std::string VIDEO_ARCHITECTURE_IDENTIFIER_STRING;
    static const std::string VIDEO_MEMORY_TYPE_IDENTIFIER_STRING;
    static const std::string VIDEO_MODE_DESCRIPTION_IDENTIFIER_STRING;
    static const std::string VIDEO_PROCESSOR_IDENTIFIER_STRING;
    static const std::string CAPTION_IDENTIFIER_STRING;
};

#endif
