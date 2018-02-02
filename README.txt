Auteurs :
	FLECKINGER Julien
	BRETON Cassandra

Archive :
	cmake : module cmake
	data : les images de base et généré
	doc : rapport

Dependances : 
	cmake
	QT5
	OpenGL
	GLEW
	SDL2
	SDL2_image

Compilation :
	cmake CMakeLists.txt
	make

Execution :
	Affichage 3D (sans les routes)
		./Modelisation
	Affichage QT (sans la 3D)
		./QTModelisation

La touche espace permet de simuler 1 année (uniquement veget).

Les images généré (Wetness.ppm, Slope.ppm, PowerStream.ppm, Drainage.ppm
Veget.ppm et Route.ppm) sont dans le dossier data/


