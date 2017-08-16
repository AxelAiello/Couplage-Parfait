#include "grapheBipartie.hpp"
#include "grapheGeneral.hpp"
#include <time.h>

int 	main(int argc, char** argv) {
        srand(time(NULL));
        int find = 0;
	int NBR = 100;

	if(argc == 2) {	
		int choice = atoi(argv[1]);
		double probability = 0.0;
		
		if(choice == 1) {
			for(probability = 0.00; probability <= 0.01; probability = probability + 0.0005) {
		        	cout << endl << "Pourcentage = " << probability << endl;
        			for(int i = 0; i < NBR; i++) {
                			// If there is a perfect couplage
					GrapheGeneral g(probability);
					g.init();
					g.edmonds();
                			if(g.checkPerfect()) {find++;}
                			g.clearGraph();
        			}
        			cout << "Couplage parfait trouvé : " << find << " / " << NBR << endl;
				find = 0;
			}
		} 

		else if (choice == 2) {
			for(probability = 0.00; probability <= 1.00; probability = probability + 0.01) {
		        	cout << endl << "Pourcentage = " << probability << endl;
        			for(int i = 0; i < NBR; i++) {
                			// If there is a perfect couplage
					GrapheBipartie g(probability);
                			if(g.algoBiPartie()) {find++;}
        			}
        			cout << "Couplage parfait trouvé : " << find << " / " << NBR << endl;
				find = 0;
			}
		} 

		else {cout << "Error, need 1 argument !\n\tfor type of graphe :\n\t\t- 1 for general,\n\t\t- 2 for bipartie.\n" << endl;} 

	} else {cout << "Error, need 1 argument !\n\tfor type of graphe :\n\t\t- 1 for general,\n\t\t- 2 for bipartie.\n" << endl;}


	return 0;
}
