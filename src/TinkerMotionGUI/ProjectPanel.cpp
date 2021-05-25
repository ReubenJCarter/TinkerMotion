#include "ProjectPanel.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QListView> 

namespace TMGUI
{

ProjectPanel::ProjectPanel()
{
	//
	//Set up panel
	//
	
    setWindowTitle("Project Panel"); 
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
	//Set up take manager
	//
	
    //List
	QListView* hierarchyList = new QListView(); 

	hierarchyList->setSelectionMode(QAbstractItemView::SingleSelection); //SingleSelection
	//hierarchyList->setSelectionBehavior(QAbstractItemView::SelectRows); 
	//hierarchyList->setDefaultDropAction(Qt::TargetMoveAction);


	hierarchyList->setDragEnabled(true);
	hierarchyList->setAcceptDrops(true);
	hierarchyList->setDropIndicatorShown(true);
	//hierarchyList->setMovement(QListView::Free);

	//hierarchyListModel = new HierarchyListModel(); 
	//hierarchyList->setModel(hierarchyListModel);
	layoutBase->addWidget(hierarchyList); 
}

}