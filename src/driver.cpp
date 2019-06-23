#include "../include/dict.h"

#include <cassert>  //assert

class MyKeyComparator
{
	public:

		bool operator()(const int &lhs, const int &rhs) const
		{
			return lhs < rhs;
		}
};

int main()
{
	// Teste DAL.
	{
		DAL <int, std::string, MyKeyComparator> myList(50);

		// Insert //

		std::cout << ">>> Inserindo alguns elementos no Dicionário. <<<\n";

		myList.insert(2012003129, "Jack" );
		myList.insert(2014065190, "John" );
		myList.insert(2016042023, "Erick");
		myList.insert(2017129821, "James");
		myList.insert(2014871811, "Charles");
		myList.insert(2016042762, "Luis E.");

		std::cout << ">>> Conteúdo do Dicionário após inserções <<<\n";
		std::cout << myList << std::endl;

		// Fim dos testes do Insert //

		// Remove //

		std::string nome1 = "James";
		std::string nome2 = "Mário";

		std::cout << "\n>>> Removendo 'James' <<<\n";
		assert( myList.remove( 2017129821, nome1 ) == true );

		std::cout << ">>> Tentando remover quem não está no Dicionário : " << nome2 << " <<<\n";
		assert( myList.remove( 10, nome2) == false );

		std::cout << ">>> Conteúdo do Dicionário após remoções <<<\n";
		std::cout << myList << std::endl;


		//Fim dos testes do Remove //

		// Search //

		std::cout << "\n\n>>> Conteúdo do Dicionário <<<\n";
		std::cout << myList << std::endl;

		std::cout << "\n>>> Procurando 'Erick' <<<\n";
		assert( myList.search( 2016042023, nome1 ) == true );
		std::cout << nome1 << " foi encontrado no Dicionário!!!\n\n";

		std::cout << ">>> Tentando procurar quem não está no Dicionário : " << nome2 << " <<<\n";
		assert( myList.search( 10, nome2 ) == false );
		std::cout << nome2 << " não foi encontrado no Dicionário!!!\n";

		// Fim dos testes do Search //

		// Min e Max //

		std::cout << "\n\n>>> Conteúdo do Dicionário <<<\n";
		std::cout << myList << std::endl;

		// MIN //
		std::cout << "Matricula do Min : " << myList.min(); // Jack
		// FIM MIN //

		// MAX //
		std::cout << ", Matricula do Max : " <<  myList.max(); // Luis E.
		std::cout << "\n";
		// FIM MAX //

		// Fim dos testes de Min e Max //

		// Sucessor

		myList.insert( 2019121212, "Max" );

		int sucessor;

		std::cout << "\n\n>>> Conteúdo do Dicionário <<<\n";
		std::cout << myList << std::endl;

		myList.sucessor( 2014065190, sucessor ); // Sucessor de John == Erick

		std::cout << "ID do sucessor de John: " << sucessor;

		std::cout << "\n>>> Tentando buscar sucessor do maior elemento <<<\n";

		assert( myList.sucessor( 2019121212, sucessor ) == false ); // Sucessor de Luis E. == Não existe
		std::cout << "OK, não existe!\n";

		// Fim do Sucessor //

		// Predecessor

		int antecessor;

		myList.insert( 1, "Min");

		std::cout << "\n\n>>> Conteúdo do Dicionário <<<\n";
		std::cout << myList << std::endl;

		myList.predecessor( 2016042023, antecessor ); // Sucessor de Erick == John

		std::cout << "ID do sucessor de Min: " << antecessor;

		std::cout << "\n>>> Tentando buscar antecessor do menor elemento <<<\n";

		assert( myList.predecessor( 1, antecessor ) == false ); // Sucessor do menor : John Não existe
		std::cout << "OK, não existe!\n";
		
		// Fim do Predecessor //


	}


	// Teste DSAL.
	{
		DSAL <int, std::string, MyKeyComparator> myList(50);

		// Insert //

		std::cout << ">>> Inserindo alguns elementos no Dicionário Ordenado. <<<\n";

		myList.insert( 2012003129, "Jack"   );
		myList.insert( 2014065190, "John"   );
		myList.insert( 2016042023, "Erick"  );
		myList.insert( 2017129821, "James"  );
		myList.insert( 2014871811, "Charles");
		myList.insert( 2016042762, "Luis E.");
		myList.insert( 2019999999, "Max"    );
		myList.insert(          1, "Min"    );

		std::cout << ">>> Conteúdo do Dicionário Ordenado após inserções <<<\n";
		std::cout << myList << std::endl;

		// Fim dos testes do Insert //

		// Remove //

		std::string nome1 = "James";
		std::string nome2 = "Mário";

		std::cout << "\n>>> Removendo 'James' <<<\n";
		assert( myList.remove( 2017129821, nome1 ) == true );

		std::cout << ">>> Tentando remover quem não está no Dicionário : " << nome2 << " <<<\n";
		assert( myList.remove( 10, nome2) == false );

		std::cout << ">>> Conteúdo do Dicionário após remoções <<<\n";
		std::cout << myList << std::endl;


		//Fim dos testes do Remove //

		// Search //

		std::cout << "\n\n>>> Conteúdo do Dicionário Ordenado <<<\n";
		std::cout << myList << std::endl;

		std::cout << "\n>>> Procurando 'Erick' <<<\n";
		assert( myList.search( 2016042023, nome1 ) == true );
		std::cout << nome1 << " foi encontrado no Dicionário!!!\n\n";

		std::cout << ">>> Tentando procurar quem não está no Dicionário : " << nome2 << " <<<\n";
		assert( myList.search( 10, nome2 ) == false );
		std::cout << nome2 << " não foi encontrado no Dicionário!!!\n";

		// Fim dos testes do Search //

		// Min e Max //

		std::cout << "\n\n>>> Conteúdo do Dicionário Ordenado <<<\n";
		std::cout << myList << std::endl;

		// MIN //
		std::cout << "Matricula do Min : " << myList.min(); // Jack
		// FIM MIN //

		// MAX //
		std::cout << ", Matricula do Max : " <<  myList.max(); // Luis E.
		std::cout << "\n";
		// FIM MAX //

		// Fim dos testes de Min e Max //

		// Sucessor

		int sucessor;

		std::cout << "\n\n>>> Conteúdo do Dicionário Ordenado <<<\n";
		std::cout << myList << std::endl;

		myList.sucessor( 2014065190, sucessor ); // Sucessor de John == Erick

		std::cout << "ID do sucessor de John: " << sucessor;

		std::cout << "\n>>> Tentando buscar sucessor do maior elemento <<<\n";

		assert( myList.sucessor( 2019999999, sucessor ) == false ); // Sucessor de Max == Não existe
		std::cout << "OK, não existe!\n";

		// Fim do Sucessor //

		// Predecessor //

		int antecessor;

		std::cout << "\n\n>>> Conteúdo do Dicionário Ordenado <<<\n";
		std::cout << myList << std::endl;

		myList.predecessor( 2016042023, antecessor ); // Antecessor de John == Min.

		std::cout << "ID do sucessor de Min: " << antecessor;

		std::cout << "\n>>> Tentando buscar antecessor do menor elemento <<<\n";

		assert( myList.predecessor( 1, antecessor ) == false ); // Antecessor do Min. Não existe
		std::cout << "OK, não existe!\n";
		
		// Fim do Predecessor //

		
	}
}