#include "TinkerMotionSystem.h"

#include "CameraDevice.h"

#include <opencv2/videoio.hpp>

#include <iostream>
#include <vector>

namespace TMLib
{

class TinkerMotionSystem::Internal
{
	public:
		std::vector<CameraDevice*> cameraDevices;
		
		SystemState systemState;
		bool personTrackingEnabled; 
		
}; 

TinkerMotionSystem::TinkerMotionSystem()
{
	internal = new Internal();
	internal->validFrame = false;
	
	internal->systemState = TinkerMotionSystem::Idle;
	
	internal->personTrackingEnabled = false; 
}

TinkerMotionSystem::~TinkerMotionSystem()
{
	delete internal; 
}	

SystemState TinkerMotionSystem::GetCurrentSystemState()
{
	return internal->systemState;
}

void TinkerMotionSystem::AddCamera(int id)
{
	CameraDevice* newCamera = new CameraDevice();
	internal->cameraDevices.push_back(newCamera);
	
}

bool TinkerMotionSystem::RemoveCamera(int inx)
{
	if(inx >= internal->cameraDevices.size())
		return false; 
	
}

int TinkerMotionSystem::GetCameraCount()
{
	return internal->cameraDevices.size(); 
}

void TinkerMotionSystem::RunProcesses()
{
	
}

}