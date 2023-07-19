#include "Sha1.h"
#include "Chat.h"

#include <iomanip>

int main()
{
    std::string _login{};
    std::string _pass{};

    Chat chat;

    bool exit = false;
    int answ;

    chat.reg("Anna", "qwerty");
    chat.reg("Dima", "123456");
    chat.reg("Pavel", "654123");
    chat.reg("Fedor", "aaaaaa");
    chat.reg("Semen", "ytrewq");
    chat.reg("Stas", "zxcvbn");

    chat.print();

    chat.delUser("Pavel");
    chat.delUser("Anna");
    chat.delUser("Stas");
    chat.delUser("Fedor");

    chat.print();

    std::cout << "\n********** WELCOME **********\n\n";

    while (!exit)
    {
        std::cout << "1 - Registration\n2 - Authorization\n3 - Exit\n";
        std::cin >> answ;
        if (answ == 1)
        {
            std::cout << "REG Enter login:\n";
            std::cin >> _login;
            std::cout << "REG Enter password:\n";
            std::cin >> _pass;
            chat.reg(_login, _pass);
        }
        if (answ == 2)
        {
            std::cout << "\nAUTH Enter login:\n";
            std::cin >> _login;
            std::cout << "AUTH Enter password:\n";
            std::cin >> _pass;

            if (chat.login(_login, _pass))
                std::cout << "\nAuthorization was successful\n";
            else
                std::cout << "\nAuthorization failed\n";
        }
        if (answ == 3)
            exit = true;
    }

    return 0;
}