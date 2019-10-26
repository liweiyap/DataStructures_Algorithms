include_directories("${PROJECT_SOURCE_DIR}/headers")

set(LIBS
    std-input-parser
)

foreach(LIB ${LIBS})
    add_library(${LIB} ${LIB}.cpp)
endforeach()