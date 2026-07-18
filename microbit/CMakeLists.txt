set(NRF5_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/nrf51sdk1000dc26b5e)

set(SDK_SOURCES
    ${NRF5_SDK_PATH}/components/toolchain/system_nrf51.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/delay/nrf_delay.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/gpiote/nrf_drv_gpiote.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/common/nrf_drv_common.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/timer/nrf_drv_timer.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/rtc/nrf_drv_rtc.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/clock/nrf_drv_clock.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/twi_master/nrf_drv_twi.c
    ${NRF5_SDK_PATH}/components/drivers_nrf/uart/nrf_drv_uart.c
    ${NRF5_SDK_PATH}/components/libraries/util/app_error.c
    ${NRF5_SDK_PATH}/components/libraries/util/app_util_platform.c
    ${NRF5_SDK_PATH}/components/libraries/scheduler/app_scheduler.c
    ${NRF5_SDK_PATH}/components/libraries/timer/app_timer.c
    ${NRF5_SDK_PATH}/components/libraries/button/app_button.c
)

add_library(microbit STATIC
    internal/microbit_startup.s
    internal/board.c
    internal/display.c
    internal/buttons.c
    internal/syscalls.c
    ${SDK_SOURCES}
)

set_source_files_properties(${SDK_SOURCES} PROPERTIES COMPILE_OPTIONS "-w")

target_include_directories(microbit PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/internal
    ${NRF5_SDK_PATH}/components/toolchain/gcc
    ${NRF5_SDK_PATH}/components/toolchain
    ${NRF5_SDK_PATH}/components/device
    ${NRF5_SDK_PATH}/components/drivers_nrf/hal
    ${NRF5_SDK_PATH}/components/drivers_nrf/delay
    ${NRF5_SDK_PATH}/components/drivers_nrf/config
    ${NRF5_SDK_PATH}/components/drivers_nrf/common
    ${NRF5_SDK_PATH}/components/drivers_nrf/gpiote
    ${NRF5_SDK_PATH}/components/drivers_nrf/timer
    ${NRF5_SDK_PATH}/components/drivers_nrf/rtc
    ${NRF5_SDK_PATH}/components/drivers_nrf/clock
    ${NRF5_SDK_PATH}/components/drivers_nrf/twi_master
    ${NRF5_SDK_PATH}/components/drivers_nrf/uart
    ${NRF5_SDK_PATH}/components/libraries/util
    ${NRF5_SDK_PATH}/components/libraries/scheduler
    ${NRF5_SDK_PATH}/components/libraries/timer
    ${NRF5_SDK_PATH}/components/libraries/button
    ${NRF5_SDK_PATH}/components/softdevice/s110/headers
)

target_compile_definitions(microbit PUBLIC
    NRF51 S110 SOFTDEVICE_PRESENT BLE_STACK_SUPPORT_REQD
    BOARD_CUSTOM BSP_DEFINES_ONLY
)

target_compile_options(microbit PRIVATE
    -mcpu=cortex-m0 -mthumb -mabi=aapcs -mfloat-abi=soft
    -Wall -Werror
    -O3 -ffunction-sections -fdata-sections
    -fno-strict-aliasing -fno-builtin --short-enums
)

target_link_options(microbit PUBLIC
    -mcpu=cortex-m0 -mthumb -mabi=aapcs -mfloat-abi=soft
    -T${CMAKE_CURRENT_SOURCE_DIR}/linker/microbit_s110.ld
    -L${NRF5_SDK_PATH}/components/toolchain/gcc
    -L${NRF5_SDK_PATH}/components/softdevice/s110/toolchain/armgcc
    -Wl,--gc-sections --specs=nano.specs -lc
)
