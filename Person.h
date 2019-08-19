//
// Created by Vinícius Montanheiro.
//

#ifndef AVLTREE_PERSON_H
#define AVLTREE_PERSON_H

class Person {
private:
    long cpf;
    int rg;
    string name;
    time_t birthDate;
    string birthCity;

public:

    long getCpf() const {
        return cpf;
    }

    void setCpf(long cpf) {
        this->cpf = cpf;
    }

    int getRg() const {
        return rg;
    }

    void setRg(int rg) {
        this->rg = rg;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    time_t getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(time_t birthDate) {
        this->birthDate = birthDate;
    }

    string getBirthCity() const {
        return birthCity;
    }

    void setBirthCity(string birthCity) {
        this->birthCity = birthCity;
    }
};

#endif //AVLTREE_PERSON_H
