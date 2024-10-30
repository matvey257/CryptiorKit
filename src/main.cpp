#include <iostream> // Для ввода-вывода
#include <fstream>  // Для работы с файлами
#include <string>   // Для использования строк
#include "../lib/encryptor/encryptor.h" // Подключаем заголовочный файл с объявлениями функций

int main() {
    std::string filePath; // Переменная для хранения пути к файлу, введенного пользователем
    std::cout << "Введите имя файла для шифрования или расшифрования (с расширением, например, example.txt): ";
    std::getline(std::cin, filePath); // Считываем имя файла с возможностью ввода пробелов

    // Проверяем существование исходного файла и зашифрованного файла
    std::ifstream fileCheck(filePath); // Проверяем, существует ли исходный файл
    std::ifstream encryptedFileCheck(filePath + ".cry"); // Проверяем, существует ли зашифрованный файл

    // Если оба файла не найдены, выводим ошибку
    if (!fileCheck && !encryptedFileCheck) {
        std::cerr << "Ошибка: Файл не найден. Пожалуйста, проверьте имя файла и попробуйте снова." << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    std::string key; // Переменная для хранения ключа шифрования
    std::cout << "Введите ключ для шифрования: ";
    std::getline(std::cin, key); // Считываем ключ с возможностью ввода пробелов

    // Проверяем, что ключ не пустой
    if (key.empty()) {
        std::cerr << "Ошибка: Ключ не может быть пустым." << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    // Запрашиваем у пользователя выбор действия
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Шифровать" << std::endl; // Опция шифрования
    std::cout << "2. Дешифровать" << std::endl; // Опция расшифрования
    std::cout << "Введите номер действия (1 или 2): ";
    int choice; 
    std::cin >> choice; // Считываем выбор пользователя

    // Выполняем действие в зависимости от выбора пользователя
    switch (choice) {
        case 1: // Шифрование
            // Проверяем, существует ли уже зашифрованный файл
            if (encryptedFileCheck) {
                std::cerr << "Ошибка: Зашифрованный файл уже существует. Пожалуйста, удалите его или выберите другой файл." << std::endl;
                return 1; // Завершаем программу с кодом ошибки
            }
            encryptFile(filePath, key); // Вызываем функцию шифрования
            break; // Завершаем выполнение блока case
        case 2: // Дешифрование
            // Проверяем, существует ли зашифрованный файл для расшифровки
            if (!encryptedFileCheck) {
                std::cerr << "Ошибка: Зашифрованный файл не найден. Пожалуйста, предоставьте зашифрованный файл." << std::endl;
                return 1; // Завершаем программу с кодом ошибки
            }
            decryptFile(filePath + ".cry", key); // Вызываем функцию расшифрования
            break; // Завершаем выполнение блока case
        default: // Неверный выбор
            std::cerr << "Ошибка: Неверный выбор. Пожалуйста, выберите 1 или 2." << std::endl;
            break; // Завершаем выполнение блока case
    }

    return 0; // Завершаем программу с кодом успешного завершения
}

