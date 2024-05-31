#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Conta {

private:

	//Declaração de variáveis
	float saldo;
	int codigo_conta;
	string nome;

public:
	//Construtores
	Conta() {
		/*
		 * Construtor padrão sem parâmetros
		 */

		this->nome = "INDEFINIDO";
		this->codigo_conta = 0000;
		this->saldo = 0.0;
	}

	Conta(string nome, int codigo_conta) {
		/*
		 * Construtor sobrecarregado sem saldo
		 * parâmetros: Nome e código da conta
		 */

		this->nome = nome;
		this->codigo_conta = codigo_conta;
		this->saldo = 0.0;
	}

	Conta(string nome, int codigo_conta, float saldo) {
		/*
		 * Construtor sobrecarregado com todos os parâmetros:
		 * Nome, código de conta e saldo do cliente
		 */

		this->nome = nome;
		this->codigo_conta = codigo_conta;
		this->saldo = saldo;
	}

	//Funções
	void showData() {
		/*
		 * Exibe as informações da conta na tela
		 * Retorna void
		 */

		cout << endl << "Nome: " << nome << endl << "Codigo da Conta: "
				<< codigo_conta << endl << "Saldo: " << saldo << endl;
	}

	bool updateData(int codigo_acesso) {
		/*
		 * Altera os dados da conta
		 * Retorna um valor booleano
		 * Recebe um código de acesso inserido pelo usuário
		 */

		if (this->codigo_conta != codigo_acesso) {
			return false;
		}

		float valor;
		int operacao;

		cout << endl << "Digite 1 para vizualizar os Dados da sua conta" << endl
				<< "Digite 2 para Depositar na sua conta" << endl
				<< "Digite 3 para Sacar da sua conta" << endl;
		cin >> operacao;

		if (operacao == 1) {
			showData();

		} else if (operacao == 2) {

			cout << "Seu Saldo eh de R$" << this->saldo << endl
					<< "Deseja depositar qual valor? ";
			cin >> valor;
			this->saldo += valor;
			cout << endl << "Seu saldo agora eh de R$" << this->saldo << endl;

		} else if (operacao == 3) {

			cout << "Seu Saldo eh de R$" << this->saldo << endl
					<< "Deseja sacar qual valor? ";
			cin >> valor;
			this->saldo -= valor;
			cout << endl << "Seu saldo agora eh de R$" << this->saldo << endl;

		} else {
			cout << "A operação escolhida eh invalida!" << endl;
		}

		return true;
	}

	bool removeAccount(int codigo_excluir) {
		/*
		 * Define se o objeto será removido ou não
		 * Retorna um valor booleano
		 * Recebe um código inteiro de parâmetro
		 */

		if (this->codigo_conta == codigo_excluir) {
			return true;
		} else {
			return false;
		}
	}
};

void excluir(vector<Conta> &contas) {
	/*
	 * Retorna void
	 * Recebe um vector de parâmetro
	 * É responsável por varrer o vector para excluir
	 * uma conta do sistema
	 */

	int codigo_excluir, i;
	bool controle = false;

	cout << "Digite o codigo da conta que deseja excluir: ";
	cin >> codigo_excluir;

	for (i = 0; i < static_cast<int>(contas.size()); i++) {

		controle = contas[i].removeAccount(codigo_excluir);

		if (controle == true) { //se achar o codigo

			contas.erase(contas.begin() + i); //apaga objeto
			cout << endl << "Conta numero " << codigo_excluir
					<< " excluida com sucesso!" << endl;
			break;

		}
	}
	if (controle == false) {
		cout << endl << "Codigo nao encontrado no sistema!" << endl;
	}
}

void criarConta(vector<Conta> &contas) {
	/*
	 * Retorna void
	 * Recebe um vector de parâmetro
	 * É responsável por criar um objeto no vector
	 */

	string nome = " ";
	int codigo = 0;
	float saldo = 0.0;

	cout << "Digite o nome do proprietario da conta: ";
	cin >> nome;
	cout << "Digite o codigo da conta: ";
	cin >> codigo;
	cout << "Digite o saldo da conta: ";
	cin >> saldo;

	contas.emplace_back(nome, codigo, saldo);
	contas.back().showData();
	cout << endl << "Conta criada com Sucesso!" << endl;
}

void acessarConta(vector<Conta> &contas) {
	/*
	 * Retorna void
	 * Recebe um vector de parâmetro
	 * É responsável por varrer o vector para entrar
	 * em uma conta do sistema
	 */

	int codigo_acesso, i;
	bool controle = false;

	cout << "Digite o codigo da conta que deseja acessar: ";
	cin >> codigo_acesso;

	for (i = 0; i < static_cast<int>(contas.size()); i++) {

		controle = contas[i].updateData(codigo_acesso);
		if (controle == true){
			break;
		}

	}
	if (controle == false) {
		cout << endl << "Codigo nao encontrado no sistema!" << endl;
	}

}

void sistema() {
	/*
	 * Retorna void
	 * É responsável por dar as opções de acesso do
	 * sistema ao usuário
	 */

	//Declaração de variáveis
	bool controle = true;
	vector<Conta> contas;

	while (controle) {

		int opcaoEntrada = 0;

		cout << endl << "Digite 1 para criar sua conta" << endl
				<< "Digite 2 para entrar sua conta" << endl
				<< "Digite 3 para exluir sua conta" << endl
				<< "Digite outro numero para encerrar o programa!" << endl;
		cin >> opcaoEntrada;

		switch (opcaoEntrada) {
		case 1:
			cout << endl;
			criarConta(contas);
			break;
		case 2:
			cout << endl;
			acessarConta(contas);
			break;
		case 3:
			cout << endl;
			excluir(contas);
			break;
		default:
			cout << endl;
			cout << endl << "Obrigado por acessar nosso sistema de banco!"
					<< endl;
			controle = true;

		} //switch

	} //while
}

int main() {

	cout << "Bem Vindo ao Sistema Bancario!" << endl;

	sistema();

	return 0;
}
