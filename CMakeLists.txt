cmake_minimum_required(VERSION 3.10) # Указываем минимальную версию CMake 

project(CryptiorKit) # Задаем имя проекта и версию

set(CMAKE_CXX_STANDARD 11) # Указываем стандарт C++

# Укажите, где находиться код библиотеки
set(ENCRYPTOR_SOURCE_FILES lib/encryptor/encryptor.cpp)
set(ENCRYPTOR_HEADER_FILES lib/encryptor/encryptor.h)

#Создайте библиотеку
add_library(encryptor STATIC ${ENCRYPTOR_SOURCE_FILES} ${ENCRYPTOR_HEADER_FILES})

# указание дериктории encryptor
target_include_directories(encryptor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/encryptor)

# Указываем исполняемый файл и источники
add_executable(CryptiorKit src/main.cpp) # Создаем исполняемый файл из указанных исходников

# Свяжите исполняемый файл с библиотекой
target_link_libraries(CryptiorKit PRIVATE encryptor)
