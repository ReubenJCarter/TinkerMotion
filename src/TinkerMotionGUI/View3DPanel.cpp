#include "View3DPanel.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>

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
		
	//Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();
	//QWidget* container3D = QWidget::createWindowContainer(view);
	
	//setWidget(container3D);
}

}