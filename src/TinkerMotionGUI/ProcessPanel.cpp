#include "ProcessPanel.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QProgressBar>

namespace TMGUI
{

ProcessPanel::ProcessPanel()
{
	//
	//Set up panel
	//
	
    setWindowTitle("Process Panel"); 
    setMinimumHeight(100);
    setFeatures(QDockWidget::DockWidgetMovable); 
    QScrollArea* scrollAreaBase = new QScrollArea();
	QWidget* widgetBase = new QWidget();
	QVBoxLayout* layoutBase = new QVBoxLayout();
	widgetBase->setLayout(layoutBase);
	scrollAreaBase->setWidget(widgetBase);
	scrollAreaBase->setWidgetResizable(true);
	setWidget(scrollAreaBase);
	layoutBase->setAlignment(Qt::AlignTop);
	
	
	//
	//Person Tracking
	//
	
	QGroupBox* personTrackGroupBox = new QGroupBox("Person Tracking");
	layoutBase->addWidget(personTrackGroupBox);
	
	QVBoxLayout* personTrackLayout = new QVBoxLayout();
	personTrackGroupBox->setLayout(personTrackLayout); 
	
	QCheckBox* personTrackEnabled = new QCheckBox("enabled"); 
	personTrackLayout->addWidget(personTrackEnabled);
	
	
	//
	//ARUCO Marker Tracking
	//
	
	QGroupBox* arucoTrackGroupBox = new QGroupBox("ARUCO Tracking");
	layoutBase->addWidget(arucoTrackGroupBox);
	
	QVBoxLayout* arucoTrackLayout = new QVBoxLayout();
	arucoTrackGroupBox->setLayout(arucoTrackLayout); 
	
	QCheckBox* arucoTrackEnabled = new QCheckBox("enabled"); 
	arucoTrackLayout->addWidget(arucoTrackEnabled);
	
	
	//
	//Sphere Marker Tracking
	//
	
	QGroupBox* sphereTrackGroupBox = new QGroupBox("Sphere marker Tracking");
	layoutBase->addWidget(sphereTrackGroupBox);
	
	QVBoxLayout* sphereTrackLayout = new QVBoxLayout();
	sphereTrackGroupBox->setLayout(sphereTrackLayout); 
	
	QCheckBox* sphereTrackEnabled = new QCheckBox("enabled"); 
	sphereTrackLayout->addWidget(sphereTrackEnabled);
	
	
	//
	//Running
	//
	
	QCheckBox* runLive = new QCheckBox("Run Processes Live"); 
	layoutBase->addWidget(runLive);
	
	QPushButton* processButton = new QPushButton("Process"); 
	layoutBase->addWidget(processButton); 
	
	QProgressBar* progressBar = new QProgressBar();
	layoutBase->addWidget(progressBar); 
}

}