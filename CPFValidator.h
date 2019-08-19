//
// Created by Vinícius Montanheiro.
//

#ifndef AVLTREE_CPFVALIDATOR_H
#define AVLTREE_CPFVALIDATOR_H

class CPFValidator : public Comparator<Person,long> {
public:
    CPFValidator();

    bool with(Person p, long key);

    bool equal(Person p, long key);

    bool lessThan(Person p, long key);

    bool moreThan(Person p, long key);

    bool moreThanEqual(Person p, long key);
};

CPFValidator::CPFValidator() { }

bool CPFValidator::with(Person p, long key) {
    return false;
}

bool CPFValidator::equal(Person p, long key) {
    return p.getCpf() ==  key;
}

bool CPFValidator::lessThan(Person p, long key) {
    return p.getCpf() < key;
}

bool CPFValidator::moreThan(Person p, long key) {
    return  p.getCpf() > key;
}

bool CPFValidator::moreThanEqual(Person p, long key) {
    return p.getCpf() >= key;
}

#endif //AVLTREE_CPFVALIDATOR_H
