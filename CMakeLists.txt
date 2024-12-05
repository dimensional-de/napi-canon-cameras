cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0042 NEW)
set (CMAKE_CXX_STANDARD 17)
set(EDSDK_VERSION 131840)
set(EDSDK_DIRECTORY EDSDKv${EDSDK_VERSION}W)

project(napi-canon-cameras)
include_directories(${CMAKE_JS_INC})
include_directories(third_party/${EDSDK_DIRECTORY}/Windows/EDSDK/Header)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "src/library/*.cc" "src/library/*.h")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    PREFIX ""
    SUFFIX ".node"
)
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})

# Include N-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

if(WIN32)
    include_directories(third_party/Node/node-v17.0.0/include/node)

    if(NOT "${CMAKE_GENERATOR}" MATCHES "(Win64|IA64)")
        target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${EDSDK_DIRECTORY}/Windows/EDSDK/Library/EDSDK.lib)
    else()
        target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/third_party/${EDSDK_DIRECTORY}/Windows/EDSDK_64/Library/EDSDK.lib)
    endif()
endif()

# define NAPI_VERSION
add_definitions(-DNAPI_EXPERIMENTAL)
