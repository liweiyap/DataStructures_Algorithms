include_directories("${PROJECT_SOURCE_DIR}/headers")

set(GRAPHALGOLIBS
    breadth-first-search
)

foreach(GRAPHALGOLIB ${GRAPHALGOLIBS})
    add_library(${GRAPHALGOLIB} ${GRAPHALGOLIB}.cpp)
endforeach()