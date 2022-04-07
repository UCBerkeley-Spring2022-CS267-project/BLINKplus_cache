file(GLOB_RECURSE HEADER_LIST CONFIGURE_DEPENDS "${BLINKPlus_SOURCE_DIR}/include/*.h" "${BLINKPlus_SOURCE_DIR}/include/*.cuh")
file(GLOB_RECURSE SRC_LIST CONFIGURE_DEPENDS "${BLINKPlus_SOURCE_DIR}/src/*.cpp" "${BLINKPlus_SOURCE_DIR}/src/*.cu")

add_library(blinkplus SHARED ${SRC_LIST} ${HEADER_LIST})

target_include_directories(blinkplus PUBLIC ../include)

# We do not link nccl here, we link it manually using dlopen
target_link_libraries(blinkplus PRIVATE dl)

target_compile_features(blinkplus PUBLIC cxx_std_11)



