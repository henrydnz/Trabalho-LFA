#include "../Headers/automato.h"
#include "../utils/utils.h"

/** 
 * @brief cria e adiciona manualmente dois estados com transições para testes
 * @pre o vetor 'automata' deve estar disponivel e ser passado por referência
 * @post o automato conterá dois estados com transições deterministicas
 * @param word palavra a ser testada
 * @param step passo atual da leitura da palavra
 * @authors @mattheusMSL
 */

//função helper recursiva pra mostrar cada letra da palavra individualmente de acordo com o passo
void show_word(const string &word, int step){
    if(step < word.size()){
        cout << word[step];
        show_word(word, step + 1);
    }
}

/** 
 * @brief mostra o passo atual da leitura da palavra
 * @pre o 'state_id' deve ser um valor válido dentro do intervalo de estados
 * @post exibe o estado atual e a palavra a partir do passo dado
 * @param state_id ID do estado atual
 * @param word palavra a ser testada
 * @param step passo atual da leitura da palavra
 * @authors @mattheusMSL
 */

//mostra o passo atual da leitura da palavra
void print_step(int state_id, const string &word, int step){
    //mostra estado atual
    cout << "[q" << state_id << "] ";
    //chama recursiva pra mostrar palavra a partir do passo dado
    show_word(word, step);
    cout << endl;
}

/** 
 * @brief retorna o ID do estado de destino de uma transição
 * @pre o estado deve conter transições válidas
 * @post retorna o ID do estado de destino se a transição existir, ou -1 se não existir
 * @param state estado do automato onde a transição será verificada
 * @param symbol símbolo lido pela transição
 * @authors @henrydnz @mattheusMSL
 */

int get_target_id(State state, char symbol){
    //analisa todas as transicoes do estado
    for(Transition transition : state.transition)
        //se o simbolo esta numa transicao, retorna o destino. valor 0 ou mais
        if(transition.read == symbol)
            return transition.target_id;
    //passou por tudo e não encontrou uma transição correspondente, retorna -1
    return -1;
}

/** 
 * @brief lê um arquivo de automato e preenche o vetor de estados 
 * @pre o arquivo deve estar no formato correto e acessível
 * @post o vetor de estados 'automata' é preenchido com os estados e transições do automato
 * @param file caminho do arquivo a ser lido
 * @authors  @mattheusMSL
 */

void read_afd_file(string &file, Automata &automata){
    string file_path = "../Files/" + file;
    ifstream read_file(file_path);
    
    if(!read_file.is_open()){
        cout << "Erro em abrir o arquivo: " << file << endl;
        exit(1);
    }
    
    string line; // linha que lê o arquivo por linha 
    vector<string> estados_nomeados; // vetor de string 
    set<string> finals; // guarda todos os estados que são identificados como finais 
    map<string, int> nameForId; // mapeia nome do estado pra id

    while(getline(read_file, line)){
        if(line.find("alfabeto") == 0){
            continue;
        }
        else if(line.find("estados") == 0){
            size_t initial = line.find("{"), final = line.find("}"); // acha os { } dentro dos estados para diferenciar quais do que são conteudos dos estados
            string state_content = line.substr(initial + 1, final - initial - 1); // coloca em uma sub string os conteudos dos estados, avançando uma casa no inicial e pegando o final menos o estados inicial e menos um para pegar o conteudo do estado 
            stringstream string_content(state_content);
            string state;
            for (int id = 0; getline(string_content, state, ','); id++) {
                nameForId[state] = id;
                estados_nomeados.push_back(state);
                automata.push_back(State());
            }
        }
        else if(line.find("finais") == 0){
            size_t inicial = line.find("{"), final = line.find("}"); // acha os { } dentro dos estados finais 
            string state_final_content = line.substr(inicial + 1, final - inicial - 1); 
            stringstream string_content(state_final_content);
            string state;
            while (getline(string_content, state, ',')) {
                finals.insert(state);
            }
        }
        else if (!line.empty()) {
            // padrão: (q0,a)= q1
            regex r(R"(\((q\d+),([a-z0-9@])\)= (q\d+))");
            smatch match;
            if (regex_match(line, match, r)) {
                string origin = match[1];
                char symbol = match[2].str()[0];
                string destiny = match[3];
                
                int origin_id = nameForId[origin];
                int destiny_id = nameForId[destiny];
                
                automata[origin_id].transition.push_back({symbol,destiny_id});
            }
        }
    } 

    for (const string &state : finals) {
        int id = nameForId[state];
        automata[id].is_final = true;
    }
    
    read_file.close();
}
   
/** 
 * @brief verifica se uma palavra é válida no automato
 * @pre o automata deve estar inicializado e conter estados válidos
 * @post retorna true se a palavra é aceita pelo automato, false caso contrário
 * @param automata vetor de estados que representa o automato
 * @param word palavra a ser testada
 * @returns retorna verdadeiro se a palavra for aceite ou falso se não for aceita 
 * @authors @henrydnz @mattheusMSL
 */

//ve se uma palavra é valida no automato
bool valid(Automata automata, string word){
    //quando a palavra é vazia, se o estado inicial é final retorna true, senão false
    if(word[0] == '@') {
        return automata[0].is_final;
    }

    State current_state = automata[0];
    int i, target_id = 0;

    //vê simbolo por simbolo da palavra, anda pelo automato
    for(i = 0; i < word.size(); i++) {
        print_step(target_id, word, i); //mostra passo
        target_id = get_target_id(current_state, word[i]);  //pega estado da transicao
        //nao tem transicao pro simbolo, é invalida
        if(target_id == -1) {   
            return false;
        }
        current_state = automata[target_id];    
    }

    cout << "[q" << target_id << "]\n";

    //se quando a palavra acaba, o estado é final, retorna true, senão false
    return current_state.is_final;

}

/** 
 * @brief pede a palavra e mostra o resultado da validação
 * @pre o 'automata' deve estar inicializado e conter estados válidos
 * @post exibe a palavra lida, e mostra se ela é aceita ou rejeitada pelo automato
 * @param automata vetor de estados que representa o automato
 * @authors @henrydnz @mattheusMSL
 */

//pede a palavra, mostra result
void test_word(Automata automata){
    string word;
    cout << "Escreva a palavra a ser testada:\n";
    cin >> word;
    clear_buffer();
    cout << "\nLendo \'" << word << "\'\n\n";
    cout << (valid(automata, word) ? "ACEITO\n" : "REJEITADO\n");
}