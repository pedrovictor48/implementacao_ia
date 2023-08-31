#include <bits/stdc++.h>

using namespace std;

#include "./basic.h"

set<Proposicao> verdades;
vector<Regra> regras;



void ler_regras() {
	cout << "Insira a quantidade de regras: ";
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		Regra regra;
		cout << "Para a regra " << i + 1 << " insira a quantidade de proposicoes: ";
		int m; cin >> m;
		for(int j = 0; j < m; j++) {
			string campo, valor;
			cout << "Insira campo: ";
			cin >> campo;
			cout << " = ";
			cin >> valor;
			if(j < m - 1) cout << "e\n";
			Proposicao nova_p(campo, valor);
			regra.inserir_proposicao(nova_p);
		}
		cout << " entao ";
		{
			string campo, valor;
			cout << "Insira campo: ";
			cin >> campo;
			cout << " = ";
			cin >> valor;
			Proposicao nova_p(campo, valor);
			regra.conclusao = nova_p;
		}
		regras.push_back(regra);
	}
}

bool analisar_regra(Regra &r) {
	for(Proposicao p : r.proposicoes) {
		if(verdades.count(p) == 0) return false;
	}
	verdades.insert(r.conclusao);
	r.used = true;
	return true;
}

void pra_frente() {
	while(true) {
		bool flag = false;
		for(Regra &r : regras) {
			if(!r.used) flag |= analisar_regra(r);
		}
		if(!flag) break;
	}
}

void ler_instancia() {
	cout << "Insira o numero de proposicoes verdadeiras sobre a instancia: ";
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string campo, valor;
		cout << "Insira campo: ";
		cin >> campo;
		cout << " = ";
		cin >> valor;
		if(n < n - 1) cout << "e\n";
		Proposicao nova_p(campo, valor);
		verdades.insert(nova_p);
	}
}

int main() {
	ler_regras();
	for(Regra r : regras) {
		cout << r.get_string() << endl;
	}
	ler_instancia();
	pra_frente();
	cout << "Insira o valor do campo target: ";
	string campo; cin >> campo;
	for(Proposicao p : verdades) {
		if(p.campo == campo) {
			cout << p.get_string() << endl;
		}
	}
}
