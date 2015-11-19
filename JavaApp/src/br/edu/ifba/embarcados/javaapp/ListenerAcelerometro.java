package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro implements IListenerAcelerometro{

	public void notificarDados(float altitude, int queda){
		System.out.println("Altitude: "+altitude);
		System.out.println("Queda: "+queda);
	}
	
	public void notificarAltitude(float altitude){
		System.out.println("Altitude = "+ altitude);
	}
	
	//Se houver queda, retorna verdadeiro
	public void notificarQueda(int queda){
		if(queda == 1){
			System.out.println("Queda = "+ queda);
			
		}
	}

}
