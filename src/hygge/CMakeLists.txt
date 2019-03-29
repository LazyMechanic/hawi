set(HYGGE_LIBS_DIR ${PROJECT_DIR}/lib/${SYSTEM_BIT_POSTFIX})
set(HYGGE_OUTPUT_DIR ${PROJECT_DIR}/bin/${SYSTEM_BIT_POSTFIX})

set(HYGGE_INC_DIR ${PROJECT_DIR}/include/hygge)
set(HYGGE_SRC_DIR ${PROJECT_DIR}/src/hygge)

set(HYGGE_LIBS
    ${HYGGE_LIBS_DIR}/icudt.lib
    ${HYGGE_LIBS_DIR}/icuin.lib
    ${HYGGE_LIBS_DIR}/icuio.lib
    ${HYGGE_LIBS_DIR}/icutest.lib
    ${HYGGE_LIBS_DIR}/icutu.lib
    ${HYGGE_LIBS_DIR}/icuuc.lib
)

file(GLOB HYGGE_SRCS
    ${HYGGE_SRC_DIR}/*.cpp
    ${HYGGE_INC_DIR}/*.h
)

#set(HYGGE_SRCS
#    ${HYGGE_INC_DIR}/Lexer.h
#    ${HYGGE_SRC_DIR}/Lexer.cpp
#)

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