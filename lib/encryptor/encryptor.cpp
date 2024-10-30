#include "encryptor.h" // Подключаем заголовочный файл с объявлениями функций
#include <iostream>    // Для вывода сообщений в консоль
#include <fstream>     // Для работы с файлами

// Функция для шифрования файла
void encryptFile(const std::string& filePath, const std::string& key) {
    // Открываем исходный файл для чтения в бинарном режиме
    std::ifstream inputFile(filePath, std::ios::binary);
    if (!inputFile) { // Проверяем, успешно ли открыт файл
        std::cerr << "Ошибка: Не удалось открыть файл " << filePath << std::endl;
        return; // Если файл не открыт, выходим из функции
    }

    // Создаем имя выходного файла, добавляя расширение .cry
    std::string outputFilePath = filePath + ".cry"; 
    // Открываем выходной файл для записи в бинарном режиме
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile) { // Проверяем, удалось ли создать выходной файл
        std::cerr << "Ошибка: Не удалось создать файл " << outputFilePath << std::endl;
        return; // Если файл не открыт, выходим из функции
    }

    char ch; // Переменная для хранения текущего символа, который будем шифровать
    size_t keyLength = key.length(); // Длина ключа для циклического шифрования
    size_t index = 0; // Индекс для перебора символов ключа

    // Читаем символы из входного файла по одному и шифруем их
    while (inputFile.get(ch)) {
        // Применяем операцию XOR для шифрования символа
        ch ^= key[index % keyLength]; // Используем остаток от деления индекса на длину ключа для циклического перебора
        outputFile.put(ch); // Записываем зашифрованный символ в выходной файл
        index++; // Увеличиваем индекс для следующего символа ключа
    }

    // Закрываем открытые файлы, чтобы освободить ресурсы
    inputFile.close(); 
    outputFile.close(); 
    // Подтверждаем успешное завершение операции шифрования
    std::cout << "Файл зашифрован и сохранён как " << outputFilePath << std::endl; 
}

// Функция для расшифрования файла
void decryptFile(const std::string& encryptedFilePath, const std::string& key) {
    // Открываем зашифрованный файл для чтения в бинарном режиме
    std::ifstream inputFile(encryptedFilePath, std::ios::binary);
    if (!inputFile) { // Проверяем, успешно ли открыт файл
        std::cerr << "Ошибка: Не удалось открыть файл " << encryptedFilePath << std::endl;
        return; // Если файл не открыт, выходим из функции
    }

    // Создаем имя выходного файла, убирая расширение .cry
    std::string outputFilePath = encryptedFilePath.substr(0, encryptedFilePath.length() - 4); 
    // Открываем выходной файл для записи в бинарном режиме
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile) { // Проверяем, удалось ли создать выходной файл
        std::cerr << "Ошибка: Не удалось создать файл " << outputFilePath << std::endl;
        return; // Если файл не открыт, выходим из функции
    }

    char ch; // Переменная для хранения текущего символа, который будем расшифровывать
    size_t keyLength = key.length(); // Длина ключа для использования в расшифровании
    size_t index = 0; // Индекс для перебора символов ключа

    // Читаем символы из зашифрованного файла по одному и расшифровываем их
    while (inputFile.get(ch)) {
        // Применяем операцию XOR для расшифровки символа
        ch ^= key[index % keyLength]; // Используем остаток от деления индекса на длину ключа для циклического перебора
        outputFile.put(ch); // Записываем расшифрованный символ в выходной файл
        index++; // Увеличиваем индекс для следующего символа ключа
    }

    // Закрываем открытые файлы, чтобы освободить ресурсы
    inputFile.close(); 
    outputFile.close(); 
    // Подтверждаем успешное завершение операции расшифрования
    std::cout << "Файл расшифрован и сохранён как " << outputFilePath << std::endl; 
}

