#include <QApplication>

#include "MainWindow.h"

int main(int argc, char* argv[])
{
	//create app
	QApplication app(argc, argv);
	
	//create main window
	TMGUI::MainWindow mainWindow;
	
	return app.exec();
}