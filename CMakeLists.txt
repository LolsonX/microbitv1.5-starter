cmake_minimum_required(VERSION 3.20)
project(microbit C CXX ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src CACHE PATH "Source directory")
set(TARGET_NAME app)

add_subdirectory(microbit)
add_executable(${TARGET_NAME} ${SOURCE_DIR}/main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE -Wl,--whole-archive microbit -Wl,--no-whole-archive)

set(APP_HEX ${CMAKE_BINARY_DIR}/${TARGET_NAME}.app.hex)
set(HEX_FILE ${CMAKE_SOURCE_DIR}/bin/${TARGET_NAME}.hex)
set(SOFTDEVICE_HEX ${CMAKE_SOURCE_DIR}/microbit/nrf51sdk1000dc26b5e/components/softdevice/s110/hex/s110_nrf51_8.0.0_softdevice.hex)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${TARGET_NAME}> ${APP_HEX}
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${TARGET_NAME}>
)

add_custom_command(OUTPUT ${HEX_FILE}
    COMMAND srec_cat ${SOFTDEVICE_HEX} -intel ${APP_HEX} -intel -o ${HEX_FILE} -intel
    DEPENDS ${TARGET_NAME}
)

add_custom_target(merge ALL DEPENDS ${HEX_FILE})
