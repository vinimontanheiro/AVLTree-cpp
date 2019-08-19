//
// Created by Vinícius Montanheiro on 27/05/15.
//
#include <sstream>
#include <fstream>

#ifndef AVLTREE_FILE_H
#define AVLTREE_FILE_H

class Utility {
public:
    bool isClosed = false;
    vector<string> lines;
    vector<string> read(string filename);
    vector<string> split(string strParam, char delimiter);
    void showExecTime(double start, double end);
    time_t strToTimestamp(string str);
    string timeStampToStr(long  timestamp);
};

/**
 * Método responsável por fazer a leitura do arquivo
 * @param String
 */
vector<string> Utility::read(string filename) {
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file,line)) {
           lines.push_back(line);
        }
        file.close();
    }else{
        cerr<<"Não foi possível abrir o arquivo " << filename << endl;
    }
    return (vector<string>)lines;
}

/**
 * Faz o corte de uma string, baseando no seu delimitador
 * @param String
 * @param Char
 */
vector<string> Utility::split(string strParam, char delimiter){
    vector<string> vet;
    stringstream ss(strParam);
    string str;

    while(getline(ss, str, delimiter)) {
        vet.push_back(str);
    }
    return vet;
}

/**
 * Exibe o tempo de execução de um tempo inicial à um tempo final
 * @param double
 * @param double
 */
void Utility::showExecTime(double start, double end){
    double execTime = ((end - start) * 1000.0) / CLOCKS_PER_SEC;
    cout<<endl<<"Tempo de execução: " << execTime << " ms" << endl << endl;
}

/**
 * Converte uma string para timestamp
 * @param String
 * @return time_t
 */
time_t Utility::strToTimestamp(string str) {
    vector<string> vec = (vector<string>)this->split(str,'/');
    tm  date = {0};
    date.tm_year = atoi(vec[2].c_str()) - 1900;
    date.tm_mon = atoi(vec[1].c_str()) - 1;
    date.tm_mday = atoi(vec[0].c_str());
    time_t timestamp = mktime(&date);
    return timestamp;
}

/**
 * Converte um timestamp para string
 * @param long
 * @return buffer
 */
string Utility::timeStampToStr(long  timestamp) {
    const time_t tm = (const time_t)timestamp;

    struct tm * date;
    char strDate[11];
    char buffer [11];

    date = localtime(&tm);
    strftime(strDate, sizeof(strDate), "%d/%m/%G", date);
    sprintf(buffer,"%s", strDate);
    std::string stdBuffer(buffer);
    return stdBuffer;
}

#endif //AVLTREE_FILE_H
