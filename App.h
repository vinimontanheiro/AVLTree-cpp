//
// Created by Vinícius Montanheiro.
//

#ifndef AVLTREE_APP_H
#define AVLTREE_APP_H
class App{
public:
    AVLTree<Person,long> ltree, dtree;
    AVLTree<Person, string> stree;
    Person *person;
    string err[2];
    void load();
    void init(int choice);
    void show(Person person);
    void showList(vector<Person> list);
    int choice = 0;
    void removeL(long key);


};

/**
 * Método responsável por carregar e popular os dados vindos de um arquivo.txt, na classe pessoa.
 */
void App::load(){
    vector<string> lines = vector<string>(util.read("file.txt"));
    int len = lines.size();
    person = new Person[len];
    vector<string> words;
    clock_t time[2];
    err[0] = "[ Registro não encontrado! ]";
    err[1] = "[ Entrada inválida! ]";

    time[0] = clock();

    for (int i = 0; i < 1000; i++) {
        words = vector<string>(util.split(lines[i], ';'));
        if(words.size() > 0){
            cout<< "[" << words[2] << " - " << words[0] << "] - OK!" << endl;
            person[i].setCpf(atol(words[0].c_str()));
            person[i].setRg(atoi(words[1].c_str()));
            person[i].setName(words[2]);
            person[i].setBirthDate(util.strToTimestamp(words[3]));
            person[i].setBirthCity(words[4]);

            if(choice == 1){
                ltree.addl(person[i]);
            }else{
                if(choice == 2){
                    stree.adds(person[i]);
                }else{
                    if(choice == 3){
                        dtree.addD(person[i]);
                    }
                }
            }
        }
    }
    time[1] = clock();
    util.showExecTime(time[0],time[1]);
}

/**
 * Método que inicia á aplicação
 * @param int opção
 */
void App::init(int op) {
    long cpf = 0;
    choice = op;
    string name = "", initial = "",final = "";

    this->load();

    if(choice == 1){
        clock_t timeCpf[2];
        cout<<"Informe o CPF: ";
        cin>>cpf;
        if(cpf >= 1){
            timeCpf[0] = clock();
            if(ltree.find(cpf)){
                timeCpf[1] = clock();
                Person p = ltree.getPerson();
                show(p);
                util.showExecTime(timeCpf[0],timeCpf[1]);
            }else {
                cout << endl << err[0] << endl;
            }
        }else{
            cout << endl << err[1] << endl;
        }
    }else{
        if(choice == 2){
            clock_t timeStr[2];
            cout<<"Informe o nome: ";
            cin.ignore();
            getline(std::cin,name);
            if(name.size() >= 1){
                timeStr[0] = clock();
                if(stree.findByName(name)){
                    timeStr[1] = clock();
                    vector<Person> list = stree.getPersons();
                    showList(list);
                    util.showExecTime(timeStr[0],timeStr[1]);
                }else {
                    cout << endl << err[0] << endl;
                }
            }else{
                cout << endl << err[1] << endl;
            }
        }else{
            if(choice == 3) {
                clock_t timeDt[2];
                cout << "Data inicial: ";
                cin.ignore();
                getline(cin, initial);
                cout << endl;
                cout << "Data final: ";
                cin.ignore();
                getline(cin, final);

                if (initial.size() >= 1 && final.size() >= 1) {
                    timeDt[0] = clock();
                    long i = util.strToTimestamp(initial);
                    long f = util.strToTimestamp(final);

                    if (dtree.findByDate(i, f)) {
                        timeDt[1] = clock();
                        vector<Person> list = dtree.getPersons();
                        showList(list);
                        util.showExecTime(timeDt[0], timeDt[1]);
                    } else {
                        cout << endl << err[0] << endl;
                    }
                } else {
                    cout << endl << err[1] << endl;
                }
            }
        }
    }

}

/**
 * Método que exibe os dados dá pessoa
 * @param Person
 */
void App::show(Person person){
    cout<<endl;
    cout<<"\t\t [REGISTRO]" << endl << endl;
    cout<<"NOME:" << person.getName() <<"\t CPF:"<<person.getCpf()<<endl;
    cout<<"NASCIMENTO:" << util.timeStampToStr(person.getBirthDate()) <<"\t\t RG:"<<person.getRg()<<endl;
    cout<<"CIDADE:"<<person.getBirthCity() << endl;
    cout<<endl;

//    long cpf;
//
//    cout<<"Excluir: " << endl;
//    cin>>cpf;
//    if(cpf > 0){
//        this->removeL(cpf);
//    }
//    cout<<endl;
//    ltree.levelByLevel(ltree.getRoot());
}

/**
 * Método que varre uma lista de pessoas e exibe seus dados
 * @param vector<Person>
 */
void App::showList(vector<Person> list){
    for(int i = 0;i < list.size(); i++){
        cout << endl;
        this->show(list[i]);
        cout<< endl;
    }
}

/**
 * Remove um item da árvore
 * @param long chave
 */
void App::removeL(long key){
    Node<Person> *root = ltree.getRoot();
    ltree.remove(&root,key);
}

#endif //AVLTREE_APP_H
