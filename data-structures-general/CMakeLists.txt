include_directories("${PROJECT_SOURCE_DIR}/headers")

set(DSGENLIBS
    stack
    queue
    graph
    binary-search-tree
)

foreach(DSGENLIB ${DSGENLIBS})
    add_library(${DSGENLIB} ${DSGENLIB}.cpp)
endforeach()