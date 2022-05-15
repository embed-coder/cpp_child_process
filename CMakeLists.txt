cmake_minimum_required (VERSION 2.8.10)

project(child_process)

include_directories(
    .
)

set(
    SOURCE_FILES
    main.cpp
)

#add_definitions( -DIGX_APP=2 )

add_executable(
    child_process

    ${SOURCE_FILES}
)

#target_link_libraries(
    #-lpthread
    #-levent
    #-lhiredis
    #-lssl
    #-lcrypto
    #-luuid
    #-lrt
    
    #-lpaho-mqttpp3
#)

INSTALL(TARGETS child_process
    RUNTIME DESTINATION /opt/embedcoder/child_process/
)
