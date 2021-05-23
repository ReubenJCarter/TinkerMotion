#include "MainWindow.h"

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

#include <iostream>

namespace TMGUI
{
	
MainWindow::MainWindow()
{
	setWindowTitle("Tinker Motion");
	
	//Set the Top bar 
	fileMenu = menuBar()->addMenu("File");
	saveAction = fileMenu->addAction("Save Project");
	loadAction = fileMenu->addAction("Load Project");
	connect(saveAction, &QAction::triggered, this, &MainWindow::Save);
	connect(loadAction, &QAction::triggered, this, &MainWindow::Load);
	
	//central
	//nodeEditorWidegt = new NodeEditor::NodeEditorWidget(); 
	//setCentralWidget(nodeEditorWidegt);

	//dockables
	//projectHierarchyWidget = new ProjectHierarchy::ProjectHierarchyWidget(); 
	//addDockWidget(Qt::LeftDockWidgetArea, projectHierarchyWidget);

	//Show
	showNormal();
	ExpandToFitScreen();
}

void MainWindow::ExpandToFitScreen()
{
	
}

void MainWindow::Save()
{
	std::cout << "Save" << std::endl;
}

void MainWindow::Load()
{
	std::cout << "Load" << std::endl;
}

}