set(HYGGE_LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(HYGGE_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(HYGGE_INC_DIR ${PROJECT_DIR}/include/HYGGE)
set(HYGGE_SRC_DIR ${PROJECT_DIR}/src/HYGGE)

set(HYGGE_SRCS
    
)

set(HYGGE_LIBS
)

add_library(hygge STATIC 
    ${HYGGE_SRCS}
)

# Set output path
set_target_properties(hygge PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${HYGGE_OUTPUT_DIR}
)

# Set extension libs
target_link_libraries(hygge ${HYGGE_LIBS})

# Set include paths
target_include_directories(hygge 
    PRIVATE ${PROJECT_SRC_DIR}
    PUBLIC ${PROJECT_INC_DIR}
)