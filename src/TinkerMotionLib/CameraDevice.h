#pragma once

#include "TinkerMotionLib_export.h"

#include <opencv2/core/mat.hpp>

namespace TMLib
{
	
class TINKERMOTIONLIB_EXPORT CameraDevice
{
    private: 
		class Internal;
		Internal* internal;
		
	public:
		CameraDevice(); 
        ~CameraDevice(); 
		bool Open(int deviceID);
		bool Close(); 
		bool CaptureFrame(); 
		bool DecodeFrame(); 
		bool IsOpen(); 
		cv::Mat GetLatestFrame(); 
};
	
}