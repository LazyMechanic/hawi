set(HAWI_LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(HAWI_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(HAWI_INC_DIR ${PROJECT_DIR}/include/HAWI)
set(HAWI_SRC_DIR ${PROJECT_DIR}/src/HAWI)

set(HAWI_SRCS
    
)

set(HAWI_LIBS
)

add_library(hawi STATIC 
    ${HAWI_SRCS}
)

# Set output path
set_target_properties(hawi PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${HAWI_OUTPUT_DIR}
)

# Set extension libs
target_link_libraries(hawi ${HAWI_LIBS})

# Set include paths
target_include_directories(hawi 
    PRIVATE ${PROJECT_SRC_DIR}
    PUBLIC ${PROJECT_INC_DIR}
)