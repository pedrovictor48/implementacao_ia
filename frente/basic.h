#include <bits/stdc++.h>

using namespace std;

struct Proposicao {
	string campo, valor;
	Proposicao() {
		this->campo = string();
		this-> valor = string();
	}
	Proposicao(string campo, string valor) {
		// fazendo ambos os campos em lower case, para padronizar
		for(char c : campo) this->campo += tolower(c);
		for(char c : valor) this->valor += tolower(c);
	}
	bool operator==(Proposicao& p) {
		return this->campo == p.campo && this->valor == valor;
	}
	bool operator<(const Proposicao& p) const {
		if(p.campo == this->campo) return this->valor < p.valor;
		return this->campo < p.campo;
	}
	bool operator==(const Proposicao& p) {
		return this->campo == p.campo && this->valor == valor;
	}
	public:
	string get_string() {
		string s;
		s = this->campo + " = " + this->valor;
		return s;
	}

};

struct Regra {
	set<Proposicao> proposicoes;
	Proposicao conclusao;
	bool used;
	Regra() {
		proposicoes = set<Proposicao>();
		conclusao = Proposicao();
		used = false;
	}
	void inserir_proposicao(Proposicao p) {
		proposicoes.insert(p);
	}
	public:
	string get_string() {
		string s = "Se ";
		int rule_idx = 0;
		for(Proposicao p : proposicoes) {
			s += p.get_string();
			rule_idx++;
			if(rule_idx != proposicoes.size()) s += " e ";
		}
		s += " entao " + this->conclusao.get_string();
		return s;
	}
};
