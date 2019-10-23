include_directories("${PROJECT_SOURCE_DIR}/headers")

set(DSGENLIBS
    stack
)

foreach(DSGENLIB ${DSGENLIBS})
    add_library(${DSGENLIB} ${DSGENLIB}.cpp)
endforeach()