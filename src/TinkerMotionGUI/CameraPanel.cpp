#include "CameraPanel.h"

#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

#include <QGridLayout>
#include <QLabel>
#include <QColor>

namespace TMGUI
{
	
	
CameraPanel::CameraPanel()
{
	QGridLayout* layoutBase = new QGridLayout();
	setLayout(layoutBase); 
	
	QPixmap defaultPixmap(600, 400);
	defaultPixmap.fill( QColor(128, 128, 128, 255) );
	
	int cameraCount = 5;
	
	int C = cameraCount < 2 ? 1 : 
			cameraCount < 5 ? 2 : 
			cameraCount < 10 ? 3 : 
			cameraCount < 17 ? 4 : 5; 
	
	for(int i = 0; i < cameraCount; i++)
	{		
		QWidget* baseElement = new QWidget();
		layoutBase->addWidget(baseElement, i / C, i % C); 
		
		QVBoxLayout* baseElementLayout = new QVBoxLayout(); 
		baseElementLayout->setAlignment(Qt::AlignTop);
		baseElement->setLayout(baseElementLayout);
		
		QWidget* cameraDisplayTopBar = new QWidget();
		cameraDisplayTopBar->setFixedHeight(20); 
		cameraDisplayTopBar->setStyleSheet("background-color: #FF0909");
		baseElementLayout->addWidget(cameraDisplayTopBar);
		
		QLabel* cameraDisplay = new QLabel(); 
		cameraDisplay->setBackgroundRole(QPalette::Base);
		cameraDisplay->setScaledContents(true);
		cameraDisplay->setMinimumSize(1, 1);
		cameraDisplay->setPixmap(defaultPixmap);
		baseElementLayout->addWidget(cameraDisplay);
	}
}

void CameraPanel::SetFrame(int cameraInx, cv::Mat img)
{
	QImage qimage( img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); 
	QPixmap pixmap( img.cols, img.rows ); 
	pixmap.convertFromImage(qimage.rgbSwapped().mirrored(false, true)); 
	cameraDisplays[cameraInx]->setPixmap(pixmap);
}


}