cmake_minimum_required(VERSION 3.15)


project(ImGuiCommandMenu LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(IMGUI_DIR "C:/libs/imgui-docking" CACHE PATH "Path to ImGui source directory")
if(NOT EXISTS "${IMGUI_DIR}/imgui.h")
    message(FATAL_ERROR "ImGui directory not found or invalid: ${IMGUI_DIR}. Please set IMGUI_DIR correctly.")
endif()
if(NOT EXISTS "${IMGUI_DIR}/imconfig.h")

endif()

set(PROJECT_SOURCES
    main.cpp
    dx_setup.cpp
    ui_style.cpp
    command_menu.cpp
    window_setup.cpp
)


set(IMGUI_BACKEND_SOURCES
    ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
    ${IMGUI_DIR}/backends/imgui_impl_dx11.cpp
)


set(IMGUI_CORE_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp

)


add_library(imgui_lib STATIC
    ${IMGUI_CORE_SOURCES}
    ${IMGUI_BACKEND_SOURCES}
)
target_include_directories(imgui_lib PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)
set_target_properties(imgui_lib PROPERTIES CXX_STANDARD ${CMAKE_CXX_STANDARD})

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE
    imgui_lib
    d3d11
    d3dcompiler
    dxgi
)


target_include_directories(${PROJECT_NAME} PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${CMAKE_CURRENT_SOURCE_DIR}
)


if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-mwindows")
endif()




