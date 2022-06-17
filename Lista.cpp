#include "Lista.h"

Lista::Lista(): _primer(NULL) , _ultimo(NULL)
{

}



void Lista::Agregar(Elemento* elemento)
{
    if (_primer == NULL) // Si la lista está vacía
    {
        _primer = elemento;
        _ultimo = elemento;
    }
    else // Si la lista no está vacía
    {
        _ultimo->SetSiguiente(elemento);
        _ultimo = elemento;
    }

}

bool Lista::Eliminar(int indice)
{
	
	int contador = -1;
    Elemento* i = _primer;

    while(i != NULL)
    {	
	    Elemento* siguiente = i->GetSiguiente();
		contador++;
		
		if(contador == indice){

				Elemento* auxiliar = i;

			if (_primer == i)
			{
				_primer = siguiente;
			} else{
				_ultimo->SetSiguiente(siguiente);
			}

			delete auxiliar;

			return true;
		}

		_ultimo = i;		
        i = siguiente;


    }

	if(contador <= indice || contador >= indice ){
		return false;
	}
}

