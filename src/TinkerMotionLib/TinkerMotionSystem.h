#pragma once

#include "TinkerMotionLib_export.h"

#include <opencv2/core/mat.hpp>

namespace TMLib
{
	
class TINKERMOTIONLIB_EXPORT TinkerMotionSystem
{
    private: 
		class Internal;
		Internal* internal;
		
	public:
		enum SystemState {Idle, Armed, Recording, Processing, Playback, Calibrate};
	
		TinkerMotionSystem(); 
        ~TinkerMotionSystem(); 
		
		SystemState GetCurrentSystemState(); 
		
		void AddCamera();
		bool RemoveCamera(int inx);
		int GetCameraCount();
		
		void SetPersonTrackingEnabled(); 
		
		void SaveProject(std::string path);
		void OpenProject(std::string path);
		
		//system control functions 
		void Play();
		void Pause();
		void Arm();
		void Record(); 
		void StopRecord(); 
		void StartProcessing(); //starts the tracking process
		void CancelProcessing(); 
		void StartExtrinsicCalib(); //starts camera calib on current recorded footage
		void CancelExtrinsicCalib(); 
		
		
};
	
}