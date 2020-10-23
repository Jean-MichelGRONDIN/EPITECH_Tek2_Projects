# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)
PROJECT(bomberMan)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmakeModule")

set (OpenGL_GL_PREFERENCE LEGACY)
IF (MSVC)     # Windows
   SET(CMAKE_FIND_LIBRARY_PREFIXES "")
   SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
   FIND_LIBRARY(SFML_DEPENDENCIES
      openal32
      flac
      vorbisenc
      vorbisfile
      vorbis
      ogg
      PATHS
         ${CMAKE_CURRENT_SOURCE_DIR}/cmakeModule
   )
   FIND_LIBRARY(SFML_LIBRARIES
      NAMES
         sfml-audio
         sfml_system
      PATHS
         ${CMAKE_CURRENT_SOURCE_DIR}/cmakeModule
   )
ELSE (MSVC)   # Linux
ENDIF(MSVC)
find_package(Irrlicht REQUIRED)
find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(
   ${Irrlicht_INCLUDE_DIRS}
   ${PROJECT_SOURCE_DIR}/include
   )

FILE(GLOB SRCS src/*.cpp)
FILE(GLOB HDRS include/*.h)

ADD_EXECUTABLE(bomberman
   ${SRCS}
   ${HDRS}
 "src/EndGame.cpp" "src/MySound.cpp"  "src/SpeedUp.cpp" "src/SpeedDown.cpp" "src/RangeBombe.cpp")



TARGET_LINK_LIBRARIES(bomberman
   ${Irrlicht_LIBRARIES}
   ${OPENGL_gl_LIBRARY}
)

IF (MSVC)     # Windows
   TARGET_LINK_LIBRARIES(bomberman
      ${SFML_LIBRARIES}
      ${SFML_DEPENDENCIES}
   )
ELSE (MSVC)   # Linux
   TARGET_LINK_LIBRARIES(bomberman
      sfml-audio
      sfml-system
   )
ENDIF(MSVC)