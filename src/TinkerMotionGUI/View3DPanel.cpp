#include "View3DPanel.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>

namespace TMGUI
{

View3DPanel::View3DPanel()
{
	//
	//Set up panel
	//
	
    setWindowTitle("3D Panel"); 
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