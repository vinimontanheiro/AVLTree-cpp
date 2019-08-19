/**
 * Implementação de uma árvore AVL
 * @author Vinícius Montanheiro
 */

#include <queue>
#include <utility>
#include "Node.h"
#include "Person.h"
#include "Comparator.h"
#include "CPFValidator.h"
#include "NAMEValidator.h"
#include "DATEValidator.h"

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

template<class D, class K>
class AVLTree {
private:
    Node<D> *root;
    Person person;
    NAMEValidator scompare;
    CPFValidator lcompare;
    DATEValidator dcompare;
    vector<Person> persons;

public:

    AVLTree<D, K>();

    Node<D> *leftLeftRotation(Node<D> *pto);

    Node<D> *rightRightRotation(Node<D> *pto);

    Node<D> *leftRightRotation(Node<D> *pto);

    Node<D> *rightLeftRotation(Node<D> *pto);

    Node<D> *lessThanLeft(Node<D> **pto);

    Node<D> *moreThanRight(Node<D> **pto);

    bool find(K key);

    void find(Node<D> *root, K key);

    int height(Node<D> *root);

    void addl(D item);

    Node<D> *addl(Node<D> *root, D item);

    void adds(D item);

    Node<D> *adds(Node<D> *root, D item);

    int getBF(Node<D> *pto);

    Node<D> *balance(Node<D> *pto);

    void setRoot(Node<D> *root);

    Node<D> *getRoot();

    void setPerson(Person person);

    Person getPerson();

    bool findByName(K key);

    void findByName(Node<D> *root, K key);

    bool findByDate(K iniKey, K finalKey);

    void findByDate(Node<D> *root, K iniKey, K finalKey);

    void setPersons(Person person);

    vector<Person> getPersons();

    void addD(D item);

    Node<D> *addD(Node<D>*root, D item);

    void levelByLevel(Node<D> *root);

    void remove(Node<D> **root, K key);
};

/**
 * Construtor
 * @param Node<D>*
 */
template<class D, class K>
AVLTree<D, K>::AVLTree() : root(NULL) { }

/**
 * Determina a raíz
 * @param Node<D>*
 */
template<class D, class K>
void AVLTree<D, K>::setRoot(Node<D> *root) {
    this->root = root;
}

/**
 * Recupera a raíz
 * @return Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::getRoot() {
    return this->root;
}

/**
 * Determina a pessoa
 * @param Person
 */
template<class D, class K>
void AVLTree<D, K>::setPerson(Person person) {
    this->person = person;
}

/**
 * Recupera a pessoa
 * @return Person
 */
template<class D, class K>
Person AVLTree<D, K>::getPerson() {
    return this->person;
}

/**
 * Determina uma lista de pessoas
 * @param Person
 */
template<class D, class K>
void AVLTree<D, K>::setPersons(Person person) {
    this->persons.push_back(person);
}

/**
 * Recupera uma lista de pessoas
 */
template<class D, class K>
vector<Person> AVLTree<D, K>::getPersons() {
    return this->persons;
}

/**
 * Verifica á altura da árvore
 * @param  Node<D>*
 */
template<class D, class K>
int AVLTree<D, K>::height(Node<D> *root) {
    int leftHeight, rightHeight;

    if (!root) {
        return 0;
    }
    leftHeight = this->height(root->left);
    rightHeight = this->height(root->right);
    return leftHeight > rightHeight ? (1 + leftHeight) : (1 + rightHeight);
}

/**
 * Rotação à esquerda
 * @param  Node<D>*
 * @return  Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::leftLeftRotation(Node<D> *pto) {
    Node<D> *left = pto->left;
    pto->left = left->right;
    left->right = pto;
    return left;
}

/**
 * Rotação à direita
 * @param  Node<D>*
 * @return  Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::rightRightRotation(Node<D> *pto) {
    Node<D> *right = pto->right;
    pto->right = right->left;
    right->left = pto;
    return right;
}

/**
 * Rotação esquerda -> direita
 * @param  Node<D>*
 * @return  Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::leftRightRotation(Node<D> *pto) {
    pto->left = this->rightRightRotation(pto->left);
    return this->leftLeftRotation(pto);
}

/**
 * Rotação direita -> esquerda
 * @param  Node<D>*
 * @return  Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::rightLeftRotation(Node<D> *pto) {
    pto->right = leftLeftRotation(pto->right);
    return this->rightRightRotation(pto);
}

/**
 * Recupera a diferença entre ambos os lados.(Fator de balanceamento)
 * @param Node<D>*
 * @return int
 */
template<class D, class K>
int AVLTree<D, K>::getBF(Node<D> *pto) {
    int leftHeight = this->height(pto->left);
    int rightHeight = this->height(pto->right);
    return (leftHeight - rightHeight);
}

/**
 * Verifica se á necessidade de balancear a árvore, se sim, faz o balanceamento.
 * @param Node<D>*
 * @return Node<D>*
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::balance(Node<D> *pto) {
    int bf = getBF(pto);
    if (bf > 1) {
        if (getBF(pto->left) > 0) {
            pto = this->leftLeftRotation(pto);
        } else {
            pto = this->leftRightRotation(pto);
        }
    } else if (bf < -1) {
        if (getBF(pto->right) > 0) {
            pto = this->rightLeftRotation(pto);
        } else {
            pto = this->rightRightRotation(pto);
        }
    }
    return pto;
}

/**
 * Adiciona um item númerico (com tratamento para o cpf)
 * @param D
 */
template<class D, class K>
void AVLTree<D, K>::addl(D item) {
    root = this->addl(root, item);
}

/**
 * Complemento do método adicionar
 * @param Node<D>
 * @param D
 * @return Node<D>
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::addl(Node<D> *root, D item) {
    if (!root) {
        root = new Node<D>(item);
        root->left = NULL;
        root->right = NULL;
        return root;
    } else {
        if (lcompare.lessThan(item, root->item.getCpf())) {
            root->left = this->addl(root->left, item);
            root = this->balance(root);
        } else {
            if (lcompare.moreThanEqual(item, root->item.getCpf())) {
                root->right = this->addl(root->right, item);
                root = this->balance(root);
            }
        }

    }
    this->setRoot(root);
    return root;
}

/**
 * Adiciona um item alfanúmerico (com tratamento para nome)
 * @param D
 */
template<class D, class K>
void AVLTree<D, K>::adds(D item) {
    root = this->adds(root, item);
}

/**
 * Complemento do método adicionar
 * @param Node<D>
 * @param D
 * @return Node<D>
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::adds(Node<D> *root, D item) {
    if (!root) {
        root = new Node<D>(item);
        root->left = NULL;
        root->right = NULL;
        return root;
    } else {
        if (scompare.lessThan(item, root->item.getName())) {
            root->left = this->adds(root->left, item);
            root = this->balance(root);
        } else {
            if (scompare.moreThanEqual(item, root->item.getName())) {
                root->right = this->adds(root->right, item);
                root = this->balance(root);
            }
        }
    }
    this->setRoot(root);
    return root;
}

/**
 * Adiciona um item númerico (com tratamento para datas)
 * @param D
 */
template<class D, class K>
void AVLTree<D, K>::addD(D item) {
    root = this->addD(root, item);
}

/**
 * Complemento do método adicionar
 * @param Node<D>
 * @param D
 * @return Node<D>
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::addD(Node<D> *root, D item) {
    if (!root) {
        root = new Node<D>(item);
        root->left = NULL;
        root->right = NULL;
        return root;
    } else {
        if (dcompare.lessThan(item, root->item.getBirthDate())) {
            root->left = this->addD(root->left, item);
            root = this->balance(root);
        } else {
            if (dcompare.moreThanEqual(item, root->item.getBirthDate())) {
                root->right = this->addD(root->right, item);
                root = this->balance(root);
            }
        }
    }
    this->setRoot(root);
    return root;
}

/**
 * Busca pessoa pelo CPF
 * @param K
 * @return bool
 */
template<class D, class K>
bool AVLTree<D, K>::find(K key) {
    this->find(root, key);
    return this->getPerson().getCpf() > 0;
}

/**
 * Complemento do método buscar pelo cpf;
 * @param Node<D>*
 * @param K
 */
template<class D, class K>
void AVLTree<D, K>::find(Node<D> *root, K key) {
    if (root) {
        if (this->lcompare.equal(root->item, key)) {
            this->setPerson(root->item);
        } else {
            if (this->lcompare.lessThan(root->item, key)) {
                this->find(root->right, key);
            } else {
                if (this->lcompare.moreThan(root->item, key)) {
                    this->find(root->left, key);
                }
            }
        }
    } else {
        Person p;
        p.setCpf(0);
        this->setPerson(p);
    }
}

/**
 * Recupera pessoa pelo nome
 * @param K
 * @return bool
 */
template<class D, class K>
bool AVLTree<D, K>::findByName(K key) {
    this->findByName(root, key);
    return this->getPersons().size() >= 1;
}

/**
 * Complemento do método buscar pelo nome;
 * @param Node<D>*
 * @param K
 */
template<class D, class K>
void AVLTree<D, K>::findByName(Node<D> *root, K key) {
    if (root) {
        if (this->scompare.with(root->item, key)) {

            this->setPersons(root->item);

            if(root->left){
                this->findByName(root->left,key);
                if(root->right){
                    this->findByName(root->right,key);
                }
            }else{
                this->findByName(root->right,key);
                if(root->left){
                    this->findByName(root->left,key);
                }
            }

        } else {
            if (this->scompare.lessThan(root->item, key)) {
                this->findByName(root->right, key);
            } else {
                if (this->scompare.moreThan(root->item, key)) {
                    this->findByName(root->left, key);
                }
            }
        }
    }

}

/**
 * Busca pessoa por periodo
 * @param K
 * @param K
 * @return bool
 */
template<class D, class K>
bool AVLTree<D, K>::findByDate(K iniKey ,K finalKey) {
    AVLTree<D, K>::findByDate(root,iniKey,finalKey);
    return this->getPersons().size() >= 1;
}

/**
 * Complemento do método buscar por periodo
 * @param Node<D>*
 * @param K
 * @param K
 */
template<class D, class K>
void AVLTree<D, K>::findByDate(Node<D> *root, K iniKey,K finalKey) {
    if (root) {
        if (root->item.getBirthDate() >= iniKey && root->item.getBirthDate() <= finalKey) {

            this->setPersons(root->item);

            if(root->left){
                this->findByDate(root->left,iniKey,finalKey);
                if(root->right){
                    this->findByDate(root->right,iniKey,finalKey);
                }
            }else{
                this->findByDate(root->right,iniKey,finalKey);
                if(root->left){
                    this->findByDate(root->left,iniKey,finalKey);
                }
            }

        } else {
            if (this->dcompare.lessThan(root->item, iniKey)) {
                this->findByDate(root->right, iniKey, finalKey);
            } else {
                if (this->dcompare.moreThan(root->item, iniKey)) {
                    this->findByDate(root->left, iniKey, finalKey);
                }
            }
        }
    }
}

/**
 * Recupera o menor a esquerda
 * @param Node<D>**
 * @return Node<D>
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::lessThanLeft(Node<D> **pto) {
    if ((*pto)->left) {
        return this->lessThanLeft(&(*pto)->left);
    } else {
        Node<D> *aux = *pto;
        if ((*pto)->right) {
            *pto = (*pto)->right;
        } else {
            *pto = NULL;
        }
        return aux;
    }
}

/**
 * Recupera o maior a direita
 * @param Node<D>**
 * @return Node<D>
 */
template<class D, class K>
Node<D> *AVLTree<D, K>::moreThanRight(Node<D> **pto) {
    if ((*pto)->right) {
        return this->moreThanRight(&(*pto)->right);
    } else {
        Node<D> *aux = *pto;
        if ((*pto)->left) {
            *pto = (*pto)->left;
        } else {
            *pto = NULL;
        }
        return aux;
    }
}

/**
 * Remove um item pela chave (Apenas para chaves númericas)
 * @param Node<D>**
 * @param K
 */
template<class D,class K>
void AVLTree<D, K>::remove(Node<D> **root, K key) {

    if (!(*root)) {
        cout << " Árvore vazia..." << endl;
        exit(0);
    }

    //Verifica se o item informado é menor que o item da raíz
    if (this->lcompare.lessThan((*root)->item, key)) {
        this->remove(&(*root)->right, key); // Se for menor, recursivamente chamamos o remover passando por referência o endereço do item à esquerda da árvore.
        *root = this->balance(*root);
    } else {
        //Verifica se o item item informado é maior que o item da raíz.
        if (this->lcompare.moreThan((*root)->item, key)) {
            this->remove(&(*root)->left, key);// Se for maior, recursivamente chamamos o remover passando por referência o endereço do item à direita da árvore.
            *root = this->balance(*root);
        } else {
            Node<D> *pto = *root;
            if (!(*root)->left && !(*root)->right) {
                (*root) = NULL;
            } else {
                // Possui apenas filhos a direita
                if (!(*root)->left) {
                    (*root) = (*root)->right;
                    pto->right = NULL;
                } else {
                    // Possui apenas filhos a esquerda
                    if (!(*root)->right) {
                        (*root) = (*root)->left;
                        pto->left = NULL;
                    }
                    else {
                        //Buscamos o menor da sub árvore a direita
                        pto = lessThanLeft(&(*root)->right);
                        pto->left = (*root)->left;
                        pto->right = (*root)->right;
                        (*root)->left = (*root)->right = NULL;
                        *root = this->balance(pto);
                    }
                }
            }

        }
    }

}

/**
 * Exibe a árvore por level
 * @param Node<D>
 * @author http://articles.leetcode.com/2010/09/printing-binary-tree-in-level-order.html
 */
template<class D, class K>
void AVLTree<D, K>::levelByLevel(Node<D> *root) {
    if (!root) {
        cerr << "Árvore vazia! ";
    }
    queue<Node<D>*> queue;
    int currentLevel = 1;
    int nextLevel = 0;
    queue.push(root);
    while (!queue.empty()) {
        Node<D> *pto = queue.front();
        queue.pop();
        currentLevel--;
        if (pto) {
            cout << pto->item.getCpf() << " ";
            queue.push(pto->left);
            queue.push(pto->right);
            nextLevel += 2;
        }
        if (currentLevel == 0) {
            cout << endl;
            currentLevel = nextLevel;
            nextLevel = 0;
        }
    }
    std::cout << std::endl;
}

#endif //AVLTREE_AVLTREE_H
