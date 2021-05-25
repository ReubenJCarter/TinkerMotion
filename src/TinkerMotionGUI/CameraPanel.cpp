#include "CameraPanel.h"

#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QSpinBox>


namespace TMGUI
{
	
	
CameraPanel::CameraPanel()
{
	
	QVBoxLayout* layoutBase = new QVBoxLayout();
	setLayout(layoutBase); 
	
	
	//
	//Camera panels
	//
	
	QGridLayout* cameraGridLayout = new QGridLayout();
	cameraGridLayout->setContentsMargins(0, 0, 0, 0);
	cameraGridLayout->setSpacing(0);
	layoutBase->addLayout(cameraGridLayout); 
	
	int cameraCount = 5;
	
	int C = cameraCount < 2 ? 1 : 
			cameraCount < 5 ? 2 : 
			cameraCount < 10 ? 3 : 
			cameraCount < 17 ? 4 : 5; 
	
	QPixmap defaultPixmap(600, 400);
	defaultPixmap.fill( QColor(128, 128, 128, 255) );
	
	for(int i = 0; i < cameraCount; i++)
	{		
		QWidget* baseElement = new QWidget();
		cameraGridLayout->addWidget(baseElement, i / C, i % C); 
		
		QVBoxLayout* baseElementLayout = new QVBoxLayout(); 
		baseElementLayout->setContentsMargins(0, 0, 0, 0);
		baseElementLayout->setSpacing(0);
		baseElementLayout->setAlignment(Qt::AlignTop);
		baseElement->setLayout(baseElementLayout);
		
		QWidget* cameraDisplayTopBar = new QWidget();
		cameraDisplayTopBar->setFixedHeight(20); 
		cameraDisplayTopBar->setStyleSheet("background-color: #1e824c; border: 0px;");
		baseElementLayout->addWidget(cameraDisplayTopBar);
		
		QHBoxLayout* topBarLayout = new QHBoxLayout(); 
		topBarLayout->setContentsMargins(0, 0, 0, 0);
		topBarLayout->setSpacing(0);
		cameraDisplayTopBar->setLayout(topBarLayout);
		
		QLabel* nameLabel = new QLabel("Camera Name");
		nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); 
		topBarLayout->addWidget(nameLabel); 
		
		QPushButton* removeButton = new QPushButton("X");
		removeButton->setFixedHeight(18); 
		removeButton->setStyleSheet("QPushButton:hover { background-color: white } QPushButton{ border: 0px;}");
		removeButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum); 
		topBarLayout->addWidget(removeButton); 
		
		QLabel* cameraDisplay = new QLabel(); 
		cameraDisplay->setStyleSheet("border: 1px solid black;");
		cameraDisplay->setContentsMargins(0, 0, 0, 0);
		cameraDisplay->setMargin(0); 
		cameraDisplay->setBackgroundRole(QPalette::Base);
		cameraDisplay->setScaledContents(true);
		cameraDisplay->setMinimumSize(1, 1);
		cameraDisplay->setPixmap(defaultPixmap);
		baseElementLayout->addWidget(cameraDisplay);
		
		connect(removeButton, &QPushButton::clicked, [this, i]()
		{
			QDialog* dialog = new QDialog();
			QVBoxLayout* vL = new QVBoxLayout(); 
			dialog->setLayout(vL);
			
			vL->addWidget(new QLabel("Are you sure you want to remove this camera?"));
			
			QHBoxLayout* hL = new QHBoxLayout(); 
			vL->addLayout(hL);
			
			QPushButton* okBut = new QPushButton("OK"); 
			QPushButton* cancelBut = new QPushButton("Cancel"); 
			hL->addWidget(cancelBut); 
			hL->addWidget(okBut);
			
			connect(okBut, &QPushButton::clicked, dialog, &QDialog::accept);
			connect(cancelBut, &QPushButton::clicked, dialog, &QDialog::reject);
			
			int result = dialog->exec();
			
			if(result == QDialog::Accepted)
			{
				std::cout << "CameraPanel:CameraRemoved:" << i << "\n"; 
				emit CameraRemoved(i);
			}
		});
	}
	
	
	//
	//Controls
	//
	
	QVBoxLayout* controlPanelLayout = new QVBoxLayout();
	layoutBase->addLayout(controlPanelLayout);
	
	QHBoxLayout* sliderLayout = new QHBoxLayout(); 
	controlPanelLayout->addLayout(sliderLayout); 
	
	QSlider* slider = new QSlider(Qt::Horizontal); 
	sliderLayout->addWidget(slider); 
	QLabel* timeStamp = new QLabel("frame:0"); 
	timeStamp->setFixedWidth(100); 
	sliderLayout->addWidget(timeStamp); 
	
	QHBoxLayout* buttonLayout = new QHBoxLayout(); 
	controlPanelLayout->addLayout(buttonLayout);

	QPushButton* armButton = new QPushButton("Arm");
	QPushButton* recordButton = new QPushButton("record");
	QPushButton* stopRecordButton = new QPushButton("stop");
	QPushButton* playButton = new QPushButton("Play");
	QPushButton* pauseButton = new QPushButton("Pause");
	
	buttonLayout->addWidget(armButton); 
	buttonLayout->addWidget(playButton); 
	
	
	QPushButton* addCameraButton = new QPushButton("Add Camera");
	
	connect(addCameraButton, &QPushButton::clicked, [this]()
	{
		QDialog* dialog = new QDialog();
		QVBoxLayout* vL = new QVBoxLayout(); 
		dialog->setLayout(vL);
		
		vL->addWidget(new QLabel("Choose a Camera id"));
		
		QSpinBox* idPicker = new QSpinBox();
		idPicker->setRange(0, 2000);
		idPicker->setSingleStep(1);
		vL->addWidget(idPicker);
		int id = 0;
		connect(idPicker, QOverload<int>::of(&QSpinBox::valueChanged), [&id](int i){id = i;});  
			
		QHBoxLayout* hL = new QHBoxLayout(); 
		vL->addLayout(hL);
		
		QPushButton* okBut = new QPushButton("OK"); 
		QPushButton* cancelBut = new QPushButton("Cancel"); 
		hL->addWidget(cancelBut); 
		hL->addWidget(okBut);
		
		connect(okBut, &QPushButton::clicked, dialog, &QDialog::accept);
		connect(cancelBut, &QPushButton::clicked, dialog, &QDialog::reject);
		
		int result = dialog->exec();
		
		if(result == QDialog::Accepted)
		{
			std::cout << "CameraPanel:CameraAdded:" << id << "\n"; 
			emit CameraAdded(id);
		}
	});
	
	buttonLayout->addWidget(addCameraButton); 
}

void CameraPanel::SetFrame(int cameraInx, cv::Mat img)
{
	if(cameraInx < 0 || cameraInx >= cameraDisplays.size())
		return; 
	
	QImage qimage( img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); 
	QPixmap pixmap( img.cols, img.rows ); 
	pixmap.convertFromImage(qimage.rgbSwapped().mirrored(false, true)); 
	cameraDisplays[cameraInx]->setPixmap(pixmap);
}


}