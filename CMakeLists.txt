cmake_minimum_required(VERSION 3.16.0)

set(SoftwareVersion 0.1)

project(TinkerMotion VERSION ${SoftwareVersion})
set(PROJECT_BRIEF ${CMAKE_PROJECT_NAME})


include (GenerateExportHeader)


add_definitions(-DSOFTWAREVERSION=${SoftwareVersion})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#compiler options
set(CMAKE_BUILD_TYPE RELEASE)
set(GCC_COMPILE_FLAGS "-std=c++11 -Wall -O3 -g -static")
set(GCC_LINK_FLAGS "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_LINK_FLAGS}")

#doxygen custom target 
add_custom_target(doc doxygen ${CMAKE_SOURCE_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} 
				  COMMENT "Generating documentation with Doxygen" VERBATIM
)

#QT
set (CMAKE_PREFIX_PATH "C:\\Qt\\6.1.0\\msvc2019_64\\" CACHE PATH "cmake prefix path")
find_package(Qt6 COMPONENTS Core Widgets Gui Concurrent Network OpenGL 3DAnimation 3DCore 3DExtras 3DRender 3DInput 3DLogic REQUIRED)

set(QT_BIN_DIR ${Qt6_DIR}/../../../bin CACHE PATH "Path to QT binary files ")
install(FILES ${QT_BIN_DIR}/Qt6Core.dll
			  ${QT_BIN_DIR}/Qt6Gui.dll
			  ${QT_BIN_DIR}/Qt6Widgets.dll
			  ${QT_BIN_DIR}/Qt6Network.dll
			  ${QT_BIN_DIR}/Qt6OpenGL.dll
			  ${QT_BIN_DIR}/Qt63DAnimation.dll
			  ${QT_BIN_DIR}/Qt63DCore.dll
			  ${QT_BIN_DIR}/Qt6Concurrent.dll
			  ${QT_BIN_DIR}/Qt63DExtras.dll
			  ${QT_BIN_DIR}/Qt63DRender.dll
			  ${QT_BIN_DIR}/Qt63DInput.dll
			  ${QT_BIN_DIR}/Qt63DLogic.dll

			  ${QT_BIN_DIR}/Qt6Cored.dll
			  ${QT_BIN_DIR}/Qt6Guid.dll
			  ${QT_BIN_DIR}/Qt6Widgetsd.dll
			  ${QT_BIN_DIR}/Qt6Networkd.dll
			   ${QT_BIN_DIR}/Qt6OpenGLd.dll
			  ${QT_BIN_DIR}/Qt63DAnimationd.dll
			  ${QT_BIN_DIR}/Qt63DCored.dll
			  ${QT_BIN_DIR}/Qt6Concurrentd.dll
			  ${QT_BIN_DIR}/Qt63DExtrasd.dll
			  ${QT_BIN_DIR}/Qt63DRenderd.dll
			  ${QT_BIN_DIR}/Qt63DInputd.dll
			  ${QT_BIN_DIR}/Qt63DLogicd.dll

		DESTINATION bin
		COMPONENT gui
)

install(DIRECTORY ${QT_BIN_DIR}/../plugins/platforms
		DESTINATION bin
		COMPONENT gui
)

install(DIRECTORY ${QT_BIN_DIR}/../plugins/renderers
		DESTINATION bin
		COMPONENT gui
)

install(DIRECTORY ${QT_BIN_DIR}/../plugins/sceneparsers
		DESTINATION bin
		COMPONENT gui
)

#Opencv
set(OPENCV_ROOT_DIR C:/opencv/build CACHE PATH "Path to opencv")
set(OPENCV_INC_DIR ${OPENCV_ROOT_DIR}/include)
set(OPENCV_LIB_DIR ${OPENCV_ROOT_DIR}/x64/vc15/lib)
set(OPENCV_BIN_DIR ${OPENCV_ROOT_DIR}/x64/vc15/bin)
include_directories(${OPENCV_INC_DIR})
link_directories(${OPENCV_LIB_DIR})

install(FILES 
			${OPENCV_BIN_DIR}/opencv_world452.dll
			${OPENCV_BIN_DIR}/opencv_world452d.dll
			${OPENCV_BIN_DIR}/opencv_videoio_ffmpeg452_64.dll
		DESTINATION bin
		COMPONENT MainLibrary
)

#qtdarkmode
set(Q_DARK_STYLE_SHEET_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext/QDarkStyleSheet-3.0.2 CACHE PATH "Path to QDarkStyleSheet")
set(Q_DARK_STYLE_SHEET_QRC_FILE ${Q_DARK_STYLE_SHEET_DIR}/qdarkstyle/dark/style.qrc)	

#cmake dirs
include_directories(${CMAKE_BINARY_DIR})
include_directories(src)
add_subdirectory(src)

install(FILES ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Lib_export.h
		DESTINATION include
)

#copy header files to include install path
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/ DESTINATION include/${CMAKE_PROJECT_NAME}
		FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)