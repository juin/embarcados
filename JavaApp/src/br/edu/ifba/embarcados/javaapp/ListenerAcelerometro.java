package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro implements IListenerAcelerometro{

	public void notificarAltitude(float altitude){
		System.out.println("Altitude = "+ altitude);
	}
	
	//Se houver queda, retorna verdadeiro
	public boolean notificarQueda(char queda){
		
		boolean resultado = false;
		
		if(queda == 'Q'){
			resultado = true;
		}
		
		return resultado;
	}

}
