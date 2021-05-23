#pragma once

#include <QMainWindow>

class QMenu;
class QAction; 

namespace TMGUI
{
	
class MainWindow: public QMainWindow
{
	Q_OBJECT
	public:
		QMenu* fileMenu;
		QAction* saveAction;
		QAction* loadAction;
		
		MainWindow();
		void ExpandToFitScreen();
		
	public slots:
		void Save();
		void Load();
};

}