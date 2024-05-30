cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(controle_robo_esp32)

# Configurar SPIFFS
set(EXTRA_COMPONENT_DIRS $ENV{IDF_PATH}/components/spiffs)

# Incluir arquivo de partições

spiffs_create_partition_image(storage spiffs_image FLASH_IN_PROJECT)
