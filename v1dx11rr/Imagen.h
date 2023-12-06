#pragma once
#include "GUI.h"

class Imagen {

private:
	GUI* imagen = NULL;
	GUI* incorrecta = NULL;
	int id_imagen = 0;

public:

	Imagen() {
	}

	void Set_Imagen(GUI& imagen, int id_imagen) {
		this->imagen = &imagen;
		this->id_imagen = id_imagen;
	}

	void Draw() { //draw the note in the GUI 
		if (this->imagen != NULL) {
			this->imagen->Draw(0.9, 0.8, 1, 3, 1);
		}
	}

	bool validar_pinturas(int id_pintura) {

		if (this->id_imagen == id_pintura) {
			return true;
		}
		else
		{
			return false;
		}
	}

	void Free_Gui() {
		this->imagen = NULL;
		this->id_imagen = 0;
	}

	void Draw_Supreme() { //Draw the note when called
		if (this->imagen != NULL) {
			this->imagen->Draw(0, 0, 8, 12, 12);
		}
	}

	void Set_Imagen_Incorrecta(GUI& imagen_incorrecta) {
		this->incorrecta = &imagen_incorrecta;
	}

	void Draw_Incorrect_Image() {
		if (this->incorrecta != NULL) {
			this->incorrecta->Draw(0, 0, 8, 12, 12);
		}
	}

	bool check_if_i_have_a_note() {
		if (this->imagen == NULL) {
			return false;
		}
		else
		{
			return true;
		}
	}

	void Ganar() { //Perder
		this->imagen->Draw(0, 0, 8, 22, 22) ;
	}
};