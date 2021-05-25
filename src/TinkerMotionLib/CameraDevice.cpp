#include "CameraDevice.h"

#include <opencv2/videoio.hpp>
#include <iostream>

namespace TMLib
{
	class CameraDevice::Internal
	{
		public:
			cv::VideoCapture cap;
			cv::Mat frame;
			bool validFrame; 
	}; 
	
	CameraDevice::CameraDevice()
	{
		internal = new Internal();
		internal->validFrame = false;
	}
	
    CameraDevice::~CameraDevice()
	{
		delete internal; 
	}	

	bool CameraDevice::Open(int deviceID)
	{
		int apiID = cv::CAP_ANY;      // 0 = autodetect default API		
		internal->cap.open(deviceID, apiID);
		
		if (!internal->cap.isOpened()) 
		{
			std::cerr << "CameraDevice:Unable to open camera FAIL \n";
			return false;
		}
		return true; 
	}

	bool CameraDevice::Close()
	{
		if (!internal->cap.isOpened()) 
		{
			std::cerr << "CameraDevice:Unable to close camera because it was never open FAIL \n";
			return false;
		}
		internal->cap.release(); 
		return true; 
	}
	
	bool CameraDevice::CaptureFrame()
	{
		if( !internal->cap.isOpened() )
		{
			std::cerr << "CameraDevice:isOpened FAIL\n";
			internal->validFrame = false; 
			return false; 
		}
		if ( !internal->cap.grab() ) 
		{
			std::cerr << "CameraDevice:frame grabbed FAIL\n";
			internal->validFrame = false; 
			return false; 
		}
		internal->validFrame = true; 
		return true; 
	}

	bool CameraDevice::DecodeFrame()
	{
		if( !internal->validFrame )
		{
			std::cerr << "CameraDevice:validFrame FAIL\n";
			return false; 
		}
		if ( !internal->cap.retrieve(internal->frame) )
		{
			std::cerr << "CameraDevice:DecodeFrame FAIL\n";
			return false; 
		}
		return true; 
	}
	
	bool CameraDevice::IsOpen()
	{
		return internal->cap.isOpened(); 
	}

	cv::Mat CameraDevice::GetLatestFrame()
	{
		if(!internal->cap.isOpened())
			return cv::Mat(); 
		
		if(!internal->validFrame)
			return cv::Mat();
		
		if(internal->frame.cols == 0 || internal->frame.rows == 0)
			return cv::Mat(); 
		
		return internal->frame; 
	}
}