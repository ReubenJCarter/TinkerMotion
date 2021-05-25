#pragma once

#include <vector>

#include <QWidget>

#include <opencv2/core/mat.hpp>

class QLabel; 

namespace TMGUI
{

class CameraPanel: public QWidget
{
	Q_OBJECT
	private:
		std::vector<QLabel*> cameraDisplays;
		
	public:
		CameraPanel();
		void SetFrame(int cameraInx, cv::Mat img);
};

}