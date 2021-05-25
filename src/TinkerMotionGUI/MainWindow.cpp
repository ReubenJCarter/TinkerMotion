#include "MainWindow.h"

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QScreen>
#include <QFileDialog>
#include <QStandardPaths>

#include <iostream>
#include <string>

#include "CameraPanel.h"
#include "ProjectPanel.h"
#include "ProcessPanel.h"
#include "View3DPanel.h"

namespace TMGUI
{
	
MainWindow::MainWindow()
{
	//
	//Window settings
	//
	
	setWindowTitle("Tinker Motion");
	
	
	//
	//Set the Top bar 
	//
	
	QMenu* fileMenu = menuBar()->addMenu("File");
	QAction* saveAction = fileMenu->addAction("Save Project");
	QAction* loadAction = fileMenu->addAction("Load Project");
	
	
	//
	//Setup children
	//
	
	//central
	CameraPanel* cameraPanel = new CameraPanel(); 
	setCentralWidget(cameraPanel);

	//dockables
	ProjectPanel* projectPanel = new ProjectPanel(); 
	addDockWidget(Qt::LeftDockWidgetArea, projectPanel);
	
	ProcessPanel* processPanel = new ProcessPanel(); 
	addDockWidget(Qt::RightDockWidgetArea, processPanel);
	
	View3DPanel* view3DPanel = new View3DPanel(); 
	addDockWidget(Qt::BottomDockWidgetArea, view3DPanel);

	//
	//Connect Actions
	//
	
	//Save and load actions
	connect(saveAction, &QAction::triggered, [this]()
	{
		QString folderLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation); 
		QString qstr = QFileDialog::getSaveFileName(this, tr("Open Project"), folderLocation, tr("Project File (*.tmproj)"));
		std::string str = qstr.toStdString(); 
		if(str.length() > 0)
		{
			std::cout << "MainWindow:SaveProject called" << str << "\n";
			emit SaveProject(str);
		}
	});
	
	connect(loadAction, &QAction::triggered, [this]()
	{
		QString folderLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation); 
		QString qstr = QFileDialog::getOpenFileName(this, tr("Open Project"), folderLocation, tr("Project File (*.tmproj)"));
		std::string str = qstr.toStdString();
		if(str.length() > 0)
		{
			std::cout << "MainWindow:LoadProject called" << str << "\n";
			emit LoadProject(str); 
		}
	});


	//
	//Show 
	//
	
	//show command
	showNormal();
	
	//Expand the window to fill the avalible screen space
	QScreen *screen = QGuiApplication::primaryScreen();
	QRect  rec = screen->geometry();
	int differenceH = frameGeometry().height() - geometry().height();
	int differenceW = frameGeometry().width() - geometry().width();
	int height = rec.height() - differenceH;
	int width = rec.width() - differenceW;
	resize(width *  0.75, height * 0.75);
	move(rec.topLeft().x(), rec.topLeft().y());	
}


}