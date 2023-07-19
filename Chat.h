#pragma once

#include "Sha1.h"
#include "string.h"

//constexpr auto SIZE = 10;
//constexpr auto LOGINLENGTH = 10;

class Chat {
public:
    Chat();
    void reg(const std::string& login, const std::string& pass);
    bool login(const std::string& login, const std::string& pass);
    void delUser(const std::string& login);
    void print();

private:
    enum enUserStatus {
        free,
        engaged,
        deleted
    };

    struct UserAuthData {
        UserAuthData() :
            _login(),
            _pass_sha1_hash(0),
            _status(enUserStatus::free) {}

        ~UserAuthData() {
            if (_pass_sha1_hash != 0)
                delete[] _pass_sha1_hash;
        }

        UserAuthData(std::string& login, uint* sh1) {
            _login = login;
            _pass_sha1_hash = sh1;
            _status = enUserStatus::engaged;
        }

        UserAuthData& operator = (const UserAuthData& other) {
            _login = other._login;

            if (_pass_sha1_hash != 0)
                delete[] _pass_sha1_hash;
            _pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];

            memcpy(_pass_sha1_hash, other._pass_sha1_hash, SHA1HASHLENGTHBYTES);
            _status = other._status;

            return *this;
        }

        enUserStatus _status;
        std::string _login;
        uint* _pass_sha1_hash;
    };

    UserAuthData* _data;
    int _data_count;
    int _del_data_count;
    int _mem_size;

    int hash_func(const std::string& login, int offset);
    int hf_multiply(int val);
    void addUser(std::string login, uint* password);
    void resize();
    void sizeReduction();
};
