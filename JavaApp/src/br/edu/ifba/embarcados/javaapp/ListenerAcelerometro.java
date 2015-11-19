package br.edu.ifba.embarcados.javaapp;

import br.edu.ifba.embarcados.javaapp.asincexec.IListenerAcelerometro;

public class ListenerAcelerometro implements IListenerAcelerometro{

	public void notificarDados(float altitude, char queda){
		System.out.println("Altitude: "+altitude);
		System.out.println("Queda: "+queda);
	}
	
	public void notificarAltitude(float altitude){
		System.out.println("Altitude = "+ altitude);
	}
	
	//Se houver queda, retorna verdadeiro
	public void notificarQueda(char queda){
		if(queda == 'Q'){
			System.out.println("Queda = "+ queda);
			
		}
	}

	@Override
	public void guardarLog(float inicio, float fim) {
		System.out.println("Inicial: "+inicio);
		System.out.println("Final: "+fim);
		
	}

}
