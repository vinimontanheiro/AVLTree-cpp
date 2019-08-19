//
// Created by Vinícius Montanheiro.
//

#ifndef AVLTREE_DATEVALIDATOR_H
#define AVLTREE_DATEVALIDATOR_H
class DATEValidator :public Comparator<Person,long> {
public:
    DATEValidator();

    bool with(Person p, long key);

    bool equal(Person p, long key);

    bool lessThan(Person p, long key);

    bool moreThan(Person p, long key);

    bool moreThanEqual(Person p, long key);
};

DATEValidator::DATEValidator() { }

bool DATEValidator::with(Person p, long key) {
    return false;
}

bool DATEValidator::equal(Person p, long key) {
    return p.getBirthDate() ==  key;
}

bool DATEValidator::lessThan(Person p, long key) {
    return p.getBirthDate() < key;
}

bool DATEValidator::moreThan(Person p, long key) {
    return  p.getBirthDate() > key;
}

bool DATEValidator::moreThanEqual(Person p, long key) {
    return p.getBirthDate() >= key;
}


#endif //AVLTREE_DATEVALIDATOR_H
