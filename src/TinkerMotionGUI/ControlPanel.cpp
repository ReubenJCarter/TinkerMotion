#include "ControlPanel.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>

namespace TMGUI
{

ControlPanel::ControlPanel()
{
	//
	//Set up panel
	//
	
    setWindowTitle("Control Panel"); 
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
}

}