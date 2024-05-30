# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/arthur/esp32/esp-idf/components/bootloader/subproject"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/tmp"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/src/bootloader-stamp"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/src"
  "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/arthur/esp32/esp-idf/projects/controle-robo-esp32/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
