PROJECT(ColorMapVTKCode CXX)

cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(make_images generate_samples.cxx make_images.cxx)
TARGET_LINK_LIBRARIES(make_images
  vtkCommonCore
  vtkFiltersGeneral
  vtkIOCore
  vtkIOImage
  vtkImagingCore
  vtkRenderingCore
  vtkRenderingOpenGL2
  vtkRenderingFreeType
  vtkImagingHybrid
  vtkInteractionStyle
  )

GET_TARGET_PROPERTY(MAKE_IMAGES_EXE make_images LOCATION)
ADD_CUSTOM_TARGET(create_images
  ${CMAKE_COMMAND} -E chdir "${CMAKE_SOURCE_DIR}/images" "${MAKE_IMAGES_EXE}"
  COMMAND ${CMAKE_COMMAND} -E chdir "${CMAKE_BINARY_DIR}" ${CMAKE_COMMAND} .
  COMMENT "Creating images"
  )
ADD_DEPENDENCIES(create_images make_images)

ADD_EXECUTABLE(make_palette generate_samples.cxx make_palette.cxx)
TARGET_LINK_LIBRARIES(make_palette
  vtkCommonCore
  vtkIOImage
  vtkImagingCore
  vtkRenderingOpenGL2
  vtkRenderingFreeType
  vtkImagingHybrid
  vtkInteractionStyle
  )
