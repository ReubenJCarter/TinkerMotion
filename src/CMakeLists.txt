#library

set(LIBSRCFILES
	TinkerMotionLib/CameraDevice.cpp
)

add_library(${CMAKE_PROJECT_NAME}Lib SHARED ${LIBSRCFILES})

generate_export_header(${CMAKE_PROJECT_NAME}Lib EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Lib_export.h)

target_link_libraries(${CMAKE_PROJECT_NAME}Lib debug opencv_world452d optimized opencv_world452) 

install(TARGETS ${CMAKE_PROJECT_NAME}Lib
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin
		COMPONENT MainLibrary  
)


#gui
set(GUISRCFILES

	${Q_DARK_STYLE_SHEET_QRC_FILE}
	
	TinkerMotionGUI/CameraPanel.cpp
	TinkerMotionGUI/Main.cpp
	TinkerMotionGUI/MainWindow.cpp
	TinkerMotionGUI/ProcessPanel.cpp
	TinkerMotionGUI/ProjectPanel.cpp
	TinkerMotionGUI/View3DPanel.cpp
)

add_executable(${CMAKE_PROJECT_NAME}GUI ${GUISRCFILES})

target_link_libraries(${CMAKE_PROJECT_NAME}GUI 
	Qt6::Core 
	Qt6::Widgets 
	Qt6::Gui 
	Qt6::Concurrent
	Qt6::Network
	Qt6::OpenGL
	Qt6::3DAnimation
	Qt6::3DCore
    Qt6::3DExtras
    Qt6::3DRender
    Qt6::3DInput
	Qt6::3DLogic)
target_link_libraries(${CMAKE_PROJECT_NAME}GUI ${CMAKE_PROJECT_NAME}Lib)

install(TARGETS ${CMAKE_PROJECT_NAME}GUI 
		RUNTIME DESTINATION bin
)