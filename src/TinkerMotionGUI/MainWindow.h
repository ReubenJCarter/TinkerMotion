#pragma once

#include <QMainWindow>

namespace TMGUI
{
	
class MainWindow: public QMainWindow
{
	Q_OBJECT
	public:
		MainWindow();
		
	signals:
		void SaveProject(std::string fileName);
		void LoadProject(std::string fileName);
};

}