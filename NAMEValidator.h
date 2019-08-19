//
// Created by Vinícius Montanheiro.

#ifndef AVLTREE_NAMEVALIDATOR_H
#define AVLTREE_NAMEVALIDATOR_H

class NAMEValidator : public Comparator<Person,string> {
public:

    NAMEValidator();

    bool with(Person p, string key);

    bool equal(Person p, string key);

    bool lessThan(Person p, string key);

    bool moreThan(Person p, string key);

    bool moreThanEqual(Person p, string key);
};

NAMEValidator::NAMEValidator() { }

bool NAMEValidator::with(Person p, string key) {
    return p.getName().find(key) == 0;
}

bool NAMEValidator::equal(Person p, string key) {
    return p.getName() ==  key;
}

bool NAMEValidator::lessThan(Person p, string key) {
    return p.getName() < key;
}

bool NAMEValidator::moreThan(Person p, string key) {
    return p.getName()  > key;
}

bool NAMEValidator::moreThanEqual(Person p, string key) {
    return p.getName()  >= key;
}

#endif //AVLTREE_NAMEVALIDATOR_H
