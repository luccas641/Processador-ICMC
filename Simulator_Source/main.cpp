#include "Model.h"
#include "Controller.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{	
//*
  // init threads
  gdk_threads_init();
//*/

	gtk_init(&argc, &argv);

	if(argc != 2)
	{	cout << "ERRO: numero de argumentos invalido" << endl << "Uso: sim arq.mif" << endl;
		return 1;
	}
	else
	{	int i = 0;
		while(argv[1][i] != '.' && argv[1][i] != '\0')
			i++;
		if(argv[1][i+1] != 'm' || argv[1][i+2] != 'i' || argv[1][i+3] != 'f')
		{	cout << "nao eh mif" << endl;
			return 1;
		}
	}

	Model *m = new Model(argv[1]);
	Controller *c = new Controller(m);

//*
  // enter the GTK main loop
  gdk_threads_enter();
  gtk_main();
  gdk_threads_leave();
//*/

//	delete m;
//	delete c;

	return 0;
}

