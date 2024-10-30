#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <string>

// Объявление функций для шифрования и расшифрования файлов
// Эти функции будут определены в encryptor.cpp
void encryptFile(const std::string& filePath, const std::string& key);
void decryptFile(const std::string& encryptedFilePath, const std::string& key);

#endif // ENCRYPTOR_H

