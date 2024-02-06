#include <iostream>
#include <string>

std::string getMessage();

int main() {
                                                // indexes 0 to 51
    std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    std::string key     { "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

    std::string rawMessage{ getMessage() };

    //build encryptedMessage
    std::string encryptedMessage;
    for (size_t i{ 0 }; i < rawMessage.length(); ++i) { // loop rawMessage chars
        if (alphabet.find(rawMessage.at(i)) == alphabet.npos) { // ignore char if not in alphabet
            encryptedMessage += rawMessage.at(i); // append char to encrypted message using +=
            continue; // continue looping
        }
        else
            encryptedMessage += key.at(alphabet.find(rawMessage.at(i))); // append key char to encyptedMessage
    }

    std::cout << "Encrypted message: " << encryptedMessage << '\n';

    //decrypt encryptedMessage
    std::string decryptedMessage;
    for (size_t i{ 0 }; i < encryptedMessage.length(); ++i) { // loop encryptedMessage chars
        if (key.find(encryptedMessage.at(i)) == key.npos) { // ignore char if not in key
            decryptedMessage += encryptedMessage.at(i); // append char to decryptedMessage using +=
            continue; // continue looping
        }
        else
            decryptedMessage += alphabet.at(key.find(encryptedMessage.at(i))); // append alphabet char to decyptedMessage
    }

    std::cout << "Decrypted message: " << decryptedMessage << '\n';


    std::cout << std::endl;
    return 0;
}

std::string getMessage() {
    std::cout << "Enter a secret message: ";
    std::string message;
    getline(std::cin, message);
    return message;
}