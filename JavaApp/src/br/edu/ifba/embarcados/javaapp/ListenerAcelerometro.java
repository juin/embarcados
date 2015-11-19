package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro implements IListenerAcelerometro{

	public void notificarAltitude(float altitude){
		System.out.println("Altitude = "+ altitude);
	}
	
	//Se houver queda, retorna verdadeiro
	public int notificarQueda(int queda){
		
		int resultado = 0;
		
		if(queda == 1){
			resultado = 1;
			System.out.println("Queda = "+ queda);
			
		}
		
		return resultado;
	}

}
